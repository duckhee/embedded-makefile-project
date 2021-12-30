/*
 * (C) COPYRIGHT 2009 CRZ
 *
 * File Name : platform_config.h
 * Author    : POOH
 * Version   : V1.0
 * Date      : 08/12/2009
 */

#ifndef __PLATFORM_CONFIG_H
#define __PLATFORM_CONFIG_H

/* includes */

#include "stm32f10x.h"

/* defines */

#define RCC_APB2Periph_GPIO_USART           RCC_APB2Periph_GPIOA

#define GPIO_USART                 GPIOA

#define GPIO_USART_Rx_Pin          GPIO_Pin_10
#define GPIO_USART_Tx_Pin          GPIO_Pin_9

#endif /* __PLATFORM_CONFIG_H */

