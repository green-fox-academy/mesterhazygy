#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

UART_HandleTypeDef uart_handle;

volatile uint8_t buffer = 0;
volatile uint8_t *string;

void init_uart()
{
	__HAL_RCC_USART1_CLK_ENABLE();

	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;

	BSP_COM_Init(COM1, &uart_handle);

	HAL_NVIC_EnableIRQ(USART1_IRQn);
	HAL_NVIC_SetPriority(USART1_IRQn, 8, 0);
}

int main(void)
{
	HAL_Init();
	init_uart();

	string = calloc(1, 1);

	HAL_UART_Receive_IT(&uart_handle, &buffer, 1);

	while (1) {
		printf("\r\nYour message was: %s\r\n", string);
		HAL_Delay(500);
	}

	free(string);
}

void USART1_IRQHandler()
{
	HAL_UART_IRQHandler(&uart_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	uint32_t length = strlen(string);
	string = realloc(string, length + 2);
	string[length] = buffer;
	string[length + 1] = '\0';

	HAL_UART_Receive_IT(&uart_handle, &buffer, 1);
}

// Copied from syscalls.c, needed for printf()
int _write(int file, char *ptr, int len)
{
	int DataIdx;

	for (DataIdx = 0; DataIdx < len; DataIdx++) {
		HAL_UART_Transmit(&uart_handle, &ptr[DataIdx], 1, HAL_MAX_DELAY);
	}
	return len;
}
