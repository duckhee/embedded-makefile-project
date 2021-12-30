#ifndef __GPIO_H__
#define __GPIO_H__


/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "main.h"


#define LED1_PORT               GPIOD
#define LED1_RED                GPIO_PIN_12
#define LED1_BLUE               GPIO_PIN_14
#define LED1_GREEN              GPIO_PIN_13

#define LED2_PORT               GPIOB
#define LED2_PORT2              GPIOC
/** RED is Port GPIOC */
#define LED2_RED                GPIO_PIN_6
#define LED2_BLUE               GPIO_PIN_5
#define LED2_GREEN              GPIO_PIN_0

#ifdef __cplusplus
    extern "C" {
#endif


void MX_GPIO_Init();

void LED_One_RGB_Set(uint16_t red, uint16_t blue, uint16_t green);
void LED_One_Red_On();
void LED_One_Blue_On();
void LED_One_Green_On();

void LED_One_Red_Off();
void LED_One_Blue_Off();
void LED_One_Green_Off();

void LED_Two_RGB_Set(uint16_t red, uint16_t blue, uint16_t green);
void LED_Two_Red_On();
void LED_Two_Blue_On();
void LED_Two_Green_On();

void LED_Two_Red_Off();
void LED_Two_Blue_Off();
void LED_Two_Green_Off();

void MX_Switch_Init();

void Sw1_check();
void Sw2_check();
void Sw3_check();
void Sw4_check();

/** Test LED */
void LED_Test();
/** Test Switch */
void Sw_Test();

#ifdef __cplusplus
    }
#endif
#endif