#ifndef __HW_CONFIG_H__
#define __HW_CONFIG_H__

#include "stm32f10x.h"
#include "stdio.h"

void GPIO_Configuration(void);
void USART1_Init(void);
uint8_t USART_GetCharacter(USART_TypeDef *uart_p);

#endif