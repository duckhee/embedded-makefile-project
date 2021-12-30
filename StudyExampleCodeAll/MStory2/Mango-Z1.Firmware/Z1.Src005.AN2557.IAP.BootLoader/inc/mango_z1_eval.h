  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MANGO_Z1_EVAL_H
#define __MANGO_Z1_EVAL_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/**
 * @brief LED
 */
#define LEDn                        3

#define LED1_GPIO_PORT              GPIOB
#define LED1_GPIO_CLK               RCC_APB2Periph_GPIOB
#define LED1_GPIO_PIN               GPIO_Pin_9

#define LED2_GPIO_PORT              GPIOB
#define LED2_GPIO_CLK               RCC_APB2Periph_GPIOB
#define LED2_GPIO_PIN               GPIO_Pin_5

#define LED3_GPIO_PORT              GPIOB
#define LED3_GPIO_CLK               RCC_APB2Periph_GPIOB
#define LED3_GPIO_PIN               GPIO_Pin_8

#define BUTTONn                     2

/**
 * @brief Wakeup push-button
 */
#define WAKEUP_BUTTON_PORT          GPIOA
#define WAKEUP_BUTTON_CLK           RCC_APB2Periph_GPIOA
#define WAKEUP_BUTTON_PIN           GPIO_Pin_0
#define WAKEUP_BUTTON_EXTI_LINE     EXTI_Line0
#define WAKEUP_BUTTON_PORT_SOURCE   GPIO_PortSourceGPIOA
#define WAKEUP_BUTTON_PIN_SOURCE    GPIO_PinSource0
#define WAKEUP_BUTTON_IRQn          EXTI0_IRQn 

/**
 * @brief Key push-button
 */
#define KEY_BUTTON_PORT             GPIOA
#define KEY_BUTTON_CLK              RCC_APB2Periph_GPIOA
#define KEY_BUTTON_PIN              GPIO_Pin_1
#define KEY_BUTTON_EXTI_LINE        EXTI_Line1
#define KEY_BUTTON_PORT_SOURCE      GPIO_PortSourceGPIOA
#define KEY_BUTTON_PIN_SOURCE       GPIO_PinSource1
#define KEY_BUTTON_IRQn             EXTI9_5_IRQn

#define COMn                        1

/**
 * @brief Definition for COM port1
 */ 
#define EVAL_COM1                   USART1
#define EVAL_COM1_GPIO              GPIOA
#define EVAL_COM1_CLK               RCC_APB2Periph_USART1
#define EVAL_COM1_GPIO_CLK          RCC_APB2Periph_GPIOA
#define EVAL_COM1_RxPin             GPIO_Pin_10
#define EVAL_COM1_TxPin             GPIO_Pin_9

#ifdef __cplusplus
}
#endif

#endif /* __MANGO_Z1_EVAL_H */

