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

void init_pins() {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN; /* GPIOI clock enable */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN; /* GPIOI clock enable */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	// Init user led (I 1)
	GPIOF->MODER |= (GPIO_MODER_MODER10_0); /* configure PI1 in output mode */
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_10); /* ensure push pull mode selected default */
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR10); /* ensure maximum speed setting (even though it is unnecessary) */
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR10); /* ensure all pull up pull down resistors are disabled */

	GPIOF->MODER |= (GPIO_MODER_MODER9_0);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_9);
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR9);
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR9);

	GPIOF->MODER |= (GPIO_MODER_MODER8_0);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_8);
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR8);
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR8);

	GPIOA->MODER |= (GPIO_MODER_MODER0_0);
	GPIOA->OTYPER &= ~(GPIO_OTYPER_OT_0);
	GPIOA->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR0);
	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR0);

	// Init user button (I 11)
	GPIOI->MODER |= 0b0000100000000000; /* configure PI11 in input mode */
}

int main(void) {
	HAL_Init();
	init_pins();

	uint32_t first_led = (1 << 10);
	uint32_t user_button = (1 << 11);
	//  uint32_t user_led = (1 << 10) | (1 << 9) | (1 << 8) | (1 << 7);

	while (1) {
		/* when button is pushed LED turns on, when released, then LED turns off */
		if (GPIOI->IDR & (user_button)) {
			/* set PI1 */
			for (int i = 0; i < 4; i++) {
				if (i != 3) {
					GPIOF->BSRR = first_led >> i;
					HAL_Delay(50);
					GPIOF->BSRR = first_led >> i << 16;
				} else {
					GPIOA->BSRR |= 1;
					HAL_Delay(50);
					GPIOA->BSRR |= 1 << 16;
				}
			}
			for (int i = 0; i < 4; i++) {
				if (i != 3) {
					GPIOF->BSRR = first_led >> (3 - i);
					HAL_Delay(50);
					GPIOF->BSRR = first_led >> (3 - i) << 16;
				} else {
					GPIOA->BSRR |= 1;
					HAL_Delay(50);
					GPIOA->BSRR |= 1 << 16;
				}
			}
		} else {
			/* reset PI1 */

			GPIOA->BSRR |= 1 << 16;
			GPIOF->BSRR = first_led << 16;
			//  GPIOF->BSRR = user_led << 16;
			/* we could use the ODR register also
			 reset PI1, leave the other bits as they are
			 GPIOI->ODR ^= green_led;
			 */
		}
	}
}
