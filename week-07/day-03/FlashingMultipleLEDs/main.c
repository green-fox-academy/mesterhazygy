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

	// Init user led (I 1)
	GPIOF->MODER |= (GPIO_MODER_MODER10_0); /* configure PI1 in output mode */
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_1); /* ensure push pull mode selected default */
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR1); /* ensure maximum speed setting (even though it is unnecessary) */
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR1); /* ensure all pull up pull down resistors are disabled */

	GPIOF->MODER |= (GPIO_MODER_MODER9_0);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_1);
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR1);
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR1);

	GPIOF->MODER |= (GPIO_MODER_MODER8_0);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_1);
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR1);
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR1);

	GPIOF->MODER |= (GPIO_MODER_MODER7_0);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_1);
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR1);
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR1);

	// Init user button (I 11)
	GPIOI->MODER |= 0b0000100000000000; /* configure PI11 in input mode */
}

int main(void) {
	HAL_Init();
	init_pins();
	/*
	uint32_t first_led = (1 << 10);
	uint32_t second_led = (1 << 9);
	uint32_t third_led = (1 << 8);
	uint32_t fourth_led = (1 << 7);*/
	uint32_t user_button = (1 << 11);
	uint32_t user_led = (1 << 10) | (1 << 9) | (1 << 8) | (1 << 7);

	while (1) {
		/* when button is pushed LED turns on, when released, then LED turns off */
		if (GPIOI->IDR & (user_button)) {
			/* set PI1 */
			/*
			GPIOF->BSRR = first_led;
			GPIOF->BSRR = second_led;
			GPIOF->BSRR = third_led;
			GPIOF->BSRR = fourth_led;*/
			GPIOF->BSRR = user_led;
			HAL_Delay(250);
			/*
			GPIOF->BSRR = first_led << 16;
			GPIOF->BSRR = second_led << 16;
			GPIOF->BSRR = third_led << 16;
			GPIOF->BSRR = fourth_led << 16; */
			GPIOF->BSRR = user_led << 16;
			HAL_Delay(250);

			/* we could use the ODR register also
			 set PI1, leave the other bits as they are
			 GPIOI->ODR = GPIOI->ODR ^ green_led;
			 */
		} else {
			/* reset PI1 */
			/*
			GPIOF->BSRR = first_led << 16;
			GPIOF->BSRR = second_led << 16;
			GPIOF->BSRR = third_led << 16;
			GPIOF->BSRR = fourth_led << 16; */
			GPIOF->BSRR = user_led << 16;
			/* we could use the ODR register also
			 reset PI1, leave the other bits as they are
			 GPIOI->ODR ^= green_led;
			 */
		}
	}
}
