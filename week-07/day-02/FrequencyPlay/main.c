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

int main(void) {
	HAL_Init();

	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

	BSP_LED_Init(LED1);

	while (1) {
		/*
		for (int i = 1; i < 9; i += i) {
			for (int j = 0; j < 3; j++) {
				BSP_LED_On(LED1);
				HAL_Delay(i * 125);
				BSP_LED_Off(LED1);
				HAL_Delay(i * 125);
			}
		}
		for (int i = 4; i > 1; i = i / 2) {
			for (int j = 0; j < 3; j++) {
				BSP_LED_On(LED1);
				HAL_Delay(i * 125);
				BSP_LED_Off(LED1);
				HAL_Delay(i * 125);
			}
		}
		*/

		 int a = 0;
		 for (int i = 0; i < 12; i++) {
		 while (a < 3) {
		 BSP_LED_On(LED1);
		 HAL_Delay(1000);
		 BSP_LED_Off(LED1);
		 HAL_Delay(1000);
		 a++;
		 }
		 if (a == 3) {
		 while (a < 6) {
		 BSP_LED_On(LED1);
		 HAL_Delay(500);
		 BSP_LED_Off(LED1);
		 HAL_Delay(500);
		 a++;
		 }
		 }
		 if (a == 6) {
		 while (a < 9) {
		 BSP_LED_On(LED1);
		 HAL_Delay(250);
		 BSP_LED_Off(LED1);
		 HAL_Delay(250);
		 a++;
		 }
		 }
		 if (a == 9) {
		 while (a < 12) {
		 BSP_LED_On(LED1);
		 HAL_Delay(125);
		 BSP_LED_Off(LED1);
		 HAL_Delay(125);
		 a++;
		 }
		 }
		 if (a == 12) {
		 while (a < 15) {
		 BSP_LED_On(LED1);
		 HAL_Delay(250);
		 BSP_LED_Off(LED1);
		 HAL_Delay(250);
		 a++;
		 }
		 }
		 if (a == 15) {
		 while (a < 18) {
		 BSP_LED_On(LED1);
		 HAL_Delay(500);
		 BSP_LED_Off(LED1);
		 HAL_Delay(500);
		 a++;
		 }
		 }
		 if (a == 18) {
		 a = 0;
		 }
		 }
	}
}
