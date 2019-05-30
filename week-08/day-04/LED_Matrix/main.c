#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "ft5336.h"
#include <string.h>

I2C_HandleTypeDef I2C_handle;
GPIO_InitTypeDef SCL_SDA_config;
UART_HandleTypeDef uart_handle;
TIM_HandleTypeDef read_timer;
TIM_HandleTypeDef display_timer;

#define LED_MATRIX_ADDRESS  (0b1110000 << 1)
/* regiszter címek */
#define SYSTEM_SETUP_REG	0x20
#define ROW_INT_SET_REG		0xA0
#define DISPLAY_SETUP_REG	0x80
#define READ_TEMP_REG		0x00
#define	CONFIG_REG			0x01

/* regiszter értékek */
#define STANDBY_MODE		(0 << 0)
#define NORMAL_MODE			(1 << 0)
#define OUTPUT_MODE			(0 << 0)
#define DISP_ON_BLINK_OFF	(1 << 0)
/* regiszter értékek */
#define	TEMP_STANDBY_MODE	(1 << 7)
#define	TEMP_NORMAL_MODE	(0 << 7)
#define	DATA_READY			(0 << 6)
#define	DATA_NOT_READY		(1 << 6)

static void Error_Handler(void);
static void SystemClock_Config(void);

void i2c_init(){
	__HAL_RCC_GPIOB_CLK_ENABLE();

    SCL_SDA_config.Pin = GPIO_PIN_8 | GPIO_PIN_9; // SCL: PB8 | SDA: PB9
    SCL_SDA_config.Pull = GPIO_PULLUP;
    SCL_SDA_config.Mode = GPIO_MODE_AF_OD;
    SCL_SDA_config.Alternate = GPIO_AF4_I2C1;

    HAL_GPIO_Init(GPIOB, &SCL_SDA_config);

    __HAL_RCC_I2C1_CLK_ENABLE();
	I2C_handle.Instance = I2C1;
    I2C_handle.Init.Timing = 0x40912732;
    I2C_handle.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;

    HAL_I2C_Init(&I2C_handle);
}
uint8_t temperature;
uint8_t temperature2;

uint8_t normal_mode = (SYSTEM_SETUP_REG | NORMAL_MODE);
uint8_t output_mode = (ROW_INT_SET_REG | OUTPUT_MODE);
uint8_t no_blinking = (DISPLAY_SETUP_REG | DISP_ON_BLINK_OFF);
uint8_t max_brightness = (0xE0 | 0x0F);

const uint8_t led_numbers[][8] ={
		{ 0x0e, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e },	//0
		{ 0x04, 0x06, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0e },	//1
		{ 0x0e, 0x11, 0x10, 0x10, 0x08, 0x04, 0x02, 0x1f },	//2
		{ 0x0e, 0x11, 0x10, 0x0c, 0x10, 0x10, 0x11, 0x0e },	//3
		{ 0x10, 0x18, 0x14, 0x12, 0x11, 0x1f, 0x10, 0x10 },	//4
		{ 0x1f, 0x01, 0x01, 0x0f, 0x10, 0x10, 0x11, 0x0e },	//5
		{ 0x0e, 0x11, 0x01, 0x0f, 0x11, 0x11, 0x11, 0x0e },	//6
		{ 0x1f, 0x10, 0x10, 0x08, 0x04, 0x02, 0x02, 0x02 },	//7
		{ 0x0e, 0x11, 0x11, 0x0e, 0x11, 0x11, 0x11, 0x0e },	//8
		{ 0x0e, 0x11, 0x11, 0x11, 0x1e, 0x10, 0x11, 0x0e }	//9
};

const uint8_t clear[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

const uint8_t celsuis[8] = { 0x60, 0x60, 0x1e, 0x33, 0x81, 0x81, 0x33, 0x1e };

uint8_t temp_normal_mode = TEMP_NORMAL_MODE;
uint8_t temp_read_reg = READ_TEMP_REG;

void print_number(int num) {
	int i;
	for (i = 0; i < 8; i++) {
		HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, i * 2,
		I2C_MEMADD_SIZE_8BIT, &led_numbers[num][i], 1, 100);
	}
}
void print_celsius(void) {
	int i;
	for (i = 0; i < 8; i++) {
		HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, i * 2,
		I2C_MEMADD_SIZE_8BIT, &celsuis[i], 1, 100);
	}
}

void dot_matrix_init(void) {
	HAL_I2C_Master_Transmit(&I2C_handle, LED_MATRIX_ADDRESS, &normal_mode, 1, 100);
	HAL_I2C_Master_Transmit(&I2C_handle, LED_MATRIX_ADDRESS, &output_mode, 1, 100);
	HAL_I2C_Master_Transmit(&I2C_handle, LED_MATRIX_ADDRESS, &no_blinking, 1, 100);
	HAL_I2C_Master_Transmit(&I2C_handle, LED_MATRIX_ADDRESS, &max_brightness, 1, 100);
	HAL_Delay(50);
}

int main(void) {
	HAL_Init();
	i2c_init();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_RNG_CLK_ENABLE();
	SystemClock_Config();
	RNG_HandleTypeDef rng_handle;
	rng_handle.Instance = RNG;
	HAL_RNG_Init(&rng_handle);
	temperature = HAL_RNG_GetRandomNumber(&rng_handle) % 10;
	temperature2 = HAL_RNG_GetRandomNumber(&rng_handle) % 10;

	HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, SYSTEM_SETUP_REG,
	I2C_MEMADD_SIZE_8BIT, NORMAL_MODE, 1, 100);
	HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, ROW_INT_SET_REG,
	I2C_MEMADD_SIZE_8BIT, OUTPUT_MODE, 1, 100);
	HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, DISPLAY_SETUP_REG,
	I2C_MEMADD_SIZE_8BIT, DISP_ON_BLINK_OFF, 1, 100);

	dot_matrix_init();
	/*
	uint8_t first_column =  0b11111111;
	uint8_t clear = 0; */
	while(1){
		if (temperature != 255) {
			uint8_t first_digit = temperature;
			uint8_t second_digit = temperature2;
			print_number(first_digit);
			HAL_Delay(500);
			print_number(second_digit);
			HAL_Delay(500);
			print_celsius();
			HAL_Delay(500);
		} else {
			int i;
			for (i = 0; i < 8; i++) {
				HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, i * 2,
				I2C_MEMADD_SIZE_8BIT, &clear[i], 1, 100);
			}
		}
	}
}

static void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE()
	;
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 216;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 2;

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

static void Error_Handler(void) {

}
