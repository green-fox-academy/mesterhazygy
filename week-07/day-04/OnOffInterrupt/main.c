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

void init_user_button (void)
{

	__HAL_RCC_GPIOI_CLK_ENABLE();
	user_button_handle.Pin = GPIO_PIN_11;
	user_button_handle.Pull = GPIO_NOPULL;
	user_button_handle.Speed = GPIO_SPEED_FAST;
	user_button_handle.Mode = GPIO_MODE_IT_RISING;
	HAL_GPIO_Init(GPIOI, &user_button_handle);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

int main(void)
{
	HAL_Init();
	BSP_LED_Init(LED_GREEN);
	init_user_button();

	while(1){

	}
}

void EXTI15_10_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    /* this is the place for the user code */
    BSP_LED_Toggle(LED_GREEN);
}
