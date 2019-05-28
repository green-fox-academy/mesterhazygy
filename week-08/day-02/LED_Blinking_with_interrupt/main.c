#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

static void SystemClock_Config(void);

/* the timer's config structure */
TIM_HandleTypeDef timer_handle;
TIM_HandleTypeDef timer_handle_2;

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

void init_timer_int(void) {
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	timer_handle_2.Instance = TIM2;
	timer_handle_2.Init.Prescaler = 108000 - 1; // 108000000/54000=2000 -> speed of 1 count-up: 1/2000 sec = 0.5 ms
	timer_handle_2.Init.Period = 1000 - 1; // 2000 x 0.5 ms = 1 second period
	timer_handle_2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle_2.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&timer_handle_2);

	/* assign the highest priority to our interrupt line */
	HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);

	/* tell the interrupt handling unit to process our interrupts */
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
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

int main(void) {
	HAL_Init();
	/* this function call sets the timers input clock to 108 Mhz (=108000000 Hz) */
	SystemClock_Config();
	BSP_LED_Init(LED_GREEN);
	init_timer();
	init_timer_int();
	init_LED();
	init_PWM();
	/* starting the timer */
	HAL_TIM_Base_Start_IT(&timer_handle_2);
	HAL_TIM_PWM_Start(&timer_handle, TIM_CHANNEL_1);

	while (1) {
		/* blinking the user LED with 0.1 Hz (1 on and 1 off per 100 ms) */
		for (int i = 0; i < 100; i++) {
			__HAL_TIM_SET_COMPARE(&timer_handle, TIM_CHANNEL_1, i);
			HAL_Delay(10);
		}
	}
}

void TIM2_IRQHandler(void) {
	HAL_TIM_IRQHandler(&timer_handle_2);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TIM2) {
		/* toggling the LED once in every second */
		BSP_LED_Toggle(LED_GREEN);
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
