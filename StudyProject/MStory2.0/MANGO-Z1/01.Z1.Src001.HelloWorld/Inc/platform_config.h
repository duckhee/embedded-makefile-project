#ifndef __PLATFORM_CONFIG_H__
#define __PLATFORM_CONFIG_H__

#include "stm32f10x.h"

#define RCC_APB2Periph_GPIO_USART       RCC_APB2Periph_GPIOA

#define GPIO_USART       GPIOA

#define GPIO_USART_Rx_Pin               GPIO_Pin_10
#define GPIO_USART_Tx_Pin               GPIO_Pin_9

#endif