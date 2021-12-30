/*
 * (C) COPYRIGHT 2009 CRZ
 *
 * File Name : hw_config.h
 * Author    : POOH
 * Version   : V1.0
 * Date      : 08/12/2009
 */

#ifndef __HW_CONFIG_H
#define __HW_CONFIG_H

/* includes */

#include "stm32f10x.h"
#include "stdio.h"

/* functions */

void GPIO_Configuration(void);
void USART1_Init(void);
uint8_t USART_GetCharacter(USART_TypeDef *  usart_p);

#endif  /*__HW_CONFIG_H */

