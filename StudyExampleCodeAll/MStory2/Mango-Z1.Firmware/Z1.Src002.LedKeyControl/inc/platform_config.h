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
#include "debug.h"

/* defines */

#define RCC_APB2Periph_GPIO_USART           RCC_APB2Periph_GPIOA
#define RCC_APB2Periph_GPIO_KEY             RCC_APB2Periph_GPIOA
#define RCC_APB2Periph_GPIO_LED             RCC_APB2Periph_GPIOB

#define GPIO_LED             GPIOB
#define GPIO_KEY             GPIOA
#define GPIO_USART           GPIOA

#define GPIO_LED1_PIN        GPIO_Pin_9 /* RED */
#define GPIO_LED2_PIN        GPIO_Pin_5 /* YELLOW */ 
#define GPIO_LED3_PIN        GPIO_Pin_8 /* BLUE */

#define GPIO_KEY1_PIN        GPIO_Pin_0 /* LEFT_WKUP */
#define GPIO_KEY2_PIN        GPIO_Pin_1 /* RIGHT_USER */

#define GPIO_USART_Rx_Pin    GPIO_Pin_10
#define GPIO_USART_Tx_Pin    GPIO_Pin_9

/* functions */

void LED_On_Red (void);
void LED_Off_Red (void);
void LED_On_Yellow (void);
void LED_Off_Yellow (void);
void LED_On_Blue (void);
void LED_Off_Blue (void);
void LED_On_All (void);
void LED_Off_All (void);

void LED_Test (void);
void KEY_Test (void);

void delay_1_second(void);
void delay_100_milli_second(void);

#endif /* __PLATFORM_CONFIG_H */

