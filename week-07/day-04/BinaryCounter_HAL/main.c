/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef user_button_handle;

void init_leds() {
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;
	GPIO_InitTypeDef gpio_config;
	gpio_config.Pin = (GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10);
	gpio_config.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOF, &gpio_config);
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

int main(void) {
	HAL_Init();
	init_user_button();
	init_leds();

	while (1) {
		for(int i = 0; i < 16; i++){
			i = i % 16;
			GPIOF->BSRR = i << 7;
			HAL_Delay(500);
			GPIOF->BSRR = i << 23;
		}
	}
}
