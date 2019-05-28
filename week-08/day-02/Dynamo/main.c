#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

static void SystemClock_Config(void);

/* the timer's config structure */
TIM_HandleTypeDef timer_handle;
GPIO_InitTypeDef user_button_handle;

/* the output compare channel's config structure */
TIM_OC_InitTypeDef pwm_config;

/* pin config: we cannot use the green user LED because it's not connected to an output compare channel so we use PA15 */
GPIO_InitTypeDef PB4_LED_config;

void init_LED() {
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;

	PB4_LED_config.Pin = GPIO_PIN_4;
	PB4_LED_config.Mode = GPIO_MODE_AF_PP; /* configure as output, in PUSH-PULL mode */
	PB4_LED_config.Pull = GPIO_NOPULL;
	PB4_LED_config.Speed = GPIO_SPEED_HIGH;
	PB4_LED_config.Alternate = GPIO_AF2_TIM3; /* we need this alternate function to use TIM2 in OC mode */

	HAL_GPIO_Init(GPIOB, &PB4_LED_config);
}

void init_user_button(void) {

	__HAL_RCC_GPIOI_CLK_ENABLE()
	;
	user_button_handle.Pin = GPIO_PIN_11;
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_FAST;
	user_button_handle.Mode = GPIO_MODE_IT_RISING;
	HAL_GPIO_Init(GPIOI, &user_button_handle);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_timer() {
	__HAL_RCC_TIM3_CLK_ENABLE()
	;

	timer_handle.Instance = TIM3;
	timer_handle.Init.Prescaler = 108 - 1; // 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.1 ms
	timer_handle.Init.Period = 100 - 1; // 10000 x 0.1 ms = 1 second period
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_PWM_Init(&timer_handle);
}

void init_PWM() {
	/*
	 * 50% * 0.01 s = 0.005 s: 0.005 low, then 0.005 s high;
	 * our eyes are not able to notice that it is a vibrating light
	 */
	pwm_config.Pulse = 50;
	pwm_config.OCMode = TIM_OCMODE_PWM1;
	pwm_config.OCPolarity = TIM_OCPOLARITY_HIGH;
	pwm_config.OCFastMode = TIM_OCFAST_ENABLE;
	HAL_TIM_PWM_ConfigChannel(&timer_handle, &pwm_config, TIM_CHANNEL_1);
}

volatile int charge = 0;

int main(void) {
	HAL_Init();
	/* this function call sets the timers input clock to 108 Mhz (=108000000 Hz) */
	SystemClock_Config();
	BSP_LED_Init(LED_GREEN);
	init_timer();
	init_user_button();
	init_LED();
	init_PWM();
	HAL_TIM_PWM_Start(&timer_handle, TIM_CHANNEL_1);

	while (1) {
		/* blinking the user LED with 0.1 Hz (1 on and 1 off per 100 ms) */
		for (int i = 0; i < charge; i++) {
			__HAL_TIM_SET_COMPARE(&timer_handle, TIM_CHANNEL_1, i);
			HAL_Delay(50);
		}
		for(; charge >= 0; charge--){
			__HAL_TIM_SET_COMPARE(&timer_handle, TIM_CHANNEL_1, charge);
			HAL_Delay(10);
		}
	}
}

void EXTI15_10_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	/* this is the place for the user code */
	if(charge <= 95){
		charge += 5;
	}
}

void Error_Handler(void) {
}

void SystemClock_Config(void) {
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
