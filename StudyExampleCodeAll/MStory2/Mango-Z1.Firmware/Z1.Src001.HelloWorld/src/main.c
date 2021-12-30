/*
 * (C) COPYRIGHT 2009 CRZ
 *
 * File Name : main.c
 * Author    : POOH
 * Version   : V1.0
 * Date      : 08/12/2009
 */

/* Includes */

#include "stm32f10x.h"
#include "hw_config.h"
#include "platform_config.h"

/*
 * Name   : main
 * Input  : None
 * Output : None
 * Return : None
 */
int main(void)
{
    /* Enable GPIOA clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIO_USART, ENABLE);

    /* Enable USART1 clocks */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    /* Configure the GPIO ports */
    GPIO_Configuration();

    /* UART initialization */
    USART1_Init();

    printf("Hello World! - Mango Story 2.0\n");
    return 0;
}
