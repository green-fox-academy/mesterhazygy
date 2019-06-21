#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "ft5336.h"
#include <string.h>

#define UART_PUTCHAR int __io_putchar(int ch)

static void SystemClock_Config(void);
static void Error_Handler(void);
int calculate_rpm(int);

TIM_HandleTypeDef timer_handle;
TIM_HandleTypeDef timer_handle_2;
TIM_OC_InitTypeDef pwm_config;
GPIO_InitTypeDef PB4_PIN_config;
GPIO_InitTypeDef PA15_PIN_config;
GPIO_InitTypeDef gpio_adc_pin;
GPIO_InitTypeDef gpio_ic_pin;
ADC_HandleTypeDef adc_handle;
ADC_ChannelConfTypeDef adc_channel_config;
UART_HandleTypeDef uart_handle;

volatile uint8_t pwm_val = 0;
volatile uint8_t blade_counter = 0;
volatile uint16_t fan_rpm;
volatile uint32_t fan_round_counter = 0;
volatile uint8_t buffer = 0;
volatile uint8_t *text;
volatile int flag = 0;
volatile uint16_t period_counter = 0;


int _write(int file, char *ptr, int len)
{
	int DataIdx;
	for (DataIdx = 0; DataIdx < len; DataIdx++)
	{
		HAL_UART_Transmit(&uart_handle, (uint8_t *)&*ptr++, 1, 100);
	}
	return len;
}

void init_input_capture_pin()
{
	__HAL_RCC_TIM2_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    gpio_ic_pin.Pin = GPIO_PIN_15;
    gpio_ic_pin.Mode = GPIO_MODE_AF_PP;
    gpio_ic_pin.Pull = GPIO_NOPULL;
    gpio_ic_pin.Speed = GPIO_SPEED_FREQ_LOW;
    gpio_ic_pin.Alternate = GPIO_AF1_TIM2;
    HAL_GPIO_Init(GPIOA, &gpio_ic_pin);
}

void init_uart()
{
    /* enable the clock of the used peripherial instance */
    __HAL_RCC_USART1_CLK_ENABLE();

        /* defining the UART configuration structure */
    uart_handle.Instance = USART1;
    uart_handle.Init.BaudRate = 115200;
    uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
    uart_handle.Init.StopBits = UART_STOPBITS_1;
    uart_handle.Init.Parity = UART_PARITY_NONE;
    uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    uart_handle.Init.Mode = UART_MODE_TX_RX;

    BSP_COM_Init(COM1, &uart_handle);
	HAL_NVIC_EnableIRQ(USART1_IRQn);
	HAL_NVIC_SetPriority(USART1_IRQn, 8, 0);
}

void init_adc()
{
    /* configuring A0 pin as analog input */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /* there is no need for setting the Alternate datafield like other peripherals*/
    gpio_adc_pin.Mode = GPIO_MODE_ANALOG;
    gpio_adc_pin.Pin = GPIO_PIN_0;
    gpio_adc_pin.Speed = GPIO_SPEED_FAST;
    gpio_adc_pin.Pull = GPIO_NOPULL;

    HAL_GPIO_Init(GPIOA, &gpio_adc_pin);

    /* configuring ADC3, as it is the only ADC wired out to the headers */
    __HAL_RCC_ADC3_CLK_ENABLE();
    adc_handle.Instance = ADC3;
    adc_handle.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
    adc_handle.Init.Resolution = ADC_RESOLUTION_12B;

    /* these 5 settings are closely related */
    adc_handle.Init.ScanConvMode = DISABLE;
    adc_handle.Init.ContinuousConvMode = DISABLE;
    adc_handle.Init.DiscontinuousConvMode = DISABLE;
    adc_handle.Init.EOCSelection = ADC_EOC_SEQ_CONV;
    adc_handle.Init.NbrOfDiscConversion = 1;

    HAL_ADC_Init(&adc_handle);

    /* configuring a channel belonging to ADC3 */
    adc_channel_config.Channel = ADC_CHANNEL_0;
    adc_channel_config.SamplingTime = ADC_SAMPLETIME_56CYCLES;

    HAL_ADC_ConfigChannel(&adc_handle, &adc_channel_config);
}

void init_FAN() {
	__HAL_RCC_GPIOB_CLK_ENABLE();

	PB4_PIN_config.Pin = GPIO_PIN_4;
	PB4_PIN_config.Mode = GPIO_MODE_AF_PP; /* configure as output, in PUSH-PULL mode */
	PB4_PIN_config.Pull = GPIO_NOPULL;
	PB4_PIN_config.Speed = GPIO_SPEED_HIGH;
	PB4_PIN_config.Alternate = GPIO_AF2_TIM3; /* we need this alternate function to use TIM2 in OC mode */

	HAL_GPIO_Init(GPIOB, &PB4_PIN_config);
}

void init_timer() {
	__HAL_RCC_TIM3_CLK_ENABLE();

	timer_handle.Instance = TIM3;
	timer_handle.Init.Prescaler = 108 - 1; // 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.1 ms
	timer_handle.Init.Period = 100 - 1; // 10000 x 0.1 ms = 1 second period
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_PWM_Init(&timer_handle);
}

void init_timer_2() {
	__HAL_RCC_TIM2_CLK_ENABLE();
	TIM_MasterConfigTypeDef sMasterConfig = { 0 };
	TIM_IC_InitTypeDef sConfigIC = { 0 };

	timer_handle_2.Instance = TIM2;
	timer_handle_2.Init.Prescaler = 0; // 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.1 ms
	timer_handle_2.Init.Period = 65535 - 1; // 10000 x 0.1 ms = 1 second period
	timer_handle_2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle_2.Init.CounterMode = TIM_COUNTERMODE_UP;

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;

	sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
	sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
	sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
	sConfigIC.ICFilter = 0;

	HAL_TIM_IC_Init(&timer_handle_2);
    HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(TIM2_IRQn);
	HAL_TIM_IC_ConfigChannel(&timer_handle_2, &sConfigIC, TIM_CHANNEL_1);
}

void init_PWM() {
	pwm_config.Pulse = 50;
	pwm_config.OCMode = TIM_OCMODE_PWM1;
	pwm_config.OCPolarity = TIM_OCPOLARITY_HIGH;
	pwm_config.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&timer_handle, &pwm_config, TIM_CHANNEL_1);
}

int main(void) {
	HAL_Init();
	SystemClock_Config();

	init_timer();
	init_timer_2();
	init_input_capture_pin();
	init_FAN();
	init_PWM();
	init_uart();
    init_adc();

	HAL_TIM_PWM_Start(&timer_handle, TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&timer_handle_2, TIM_CHANNEL_1);
	HAL_TIM_Base_Start_IT(&timer_handle_2);
	HAL_UART_Receive_IT(&uart_handle, &buffer, 1);

    int adc_value;
	while (1) {
        HAL_Delay(10);
        HAL_ADC_Start(&adc_handle);
        if(HAL_ADC_PollForConversion(&adc_handle, 10) == HAL_OK){
            adc_value = HAL_ADC_GetValue(&adc_handle);
			int fan_speed = ((float)adc_value / 4060) * 100;
			__HAL_TIM_SET_COMPARE(&timer_handle, TIM_CHANNEL_1, fan_speed);

	        printf("PWM: %d | RPM: %d\n", fan_speed, fan_rpm);
	        __HAL_TIM_SET_COMPARE(&timer_handle, TIM_CHANNEL_1, fan_speed);
	        HAL_Delay(500);
        }
    }
}

int calculate_rpm(int time)
{
    float round_time = time / 108000000.0;
    int rpm = 60 / round_time;
    return rpm;
}

void USART1_IRQHandler()
{
	HAL_UART_IRQHandler(&uart_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	uint32_t length = strlen(text);
	text = realloc(text, length + 2);
	text[length] = buffer;
	text[length + 1] = '\0';
	HAL_UART_Receive_IT(&uart_handle, &buffer, 1);
	flag = 1;
}

void TIM2_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&timer_handle_2);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * htim)
{
	if(htim->Instance == TIM2){
		period_counter++;
	}
}

void HAL_TIM_IC_CaptureCallback (TIM_HandleTypeDef * htim)
{
    blade_counter++;
    if (blade_counter == 8){
	    if(htim->Instance == TIM2) {
		    fan_rpm = calculate_rpm(HAL_TIM_ReadCapturedValue(&timer_handle_2, TIM_CHANNEL_1) + (period_counter * (65535 - 1)));
            fan_round_counter++;
	    }
        blade_counter = 0;
        period_counter = 0;
    }
}

void Error_Handler(void) {
}

void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE();
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
