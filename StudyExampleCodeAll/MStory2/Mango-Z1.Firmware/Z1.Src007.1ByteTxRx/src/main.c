/*
 * (C) COPYRIGHT 2009 CRZ
 *
 * File Name : main.c
 * Author    : POOH
 * Version   : V1.0
 * Date      : 08/12/2009
 */

/* includes */

#include "hw_config.h"

/* global variables */

RCC_ClocksTypeDef  rcc_clocks;

/* functions */

void System_Information()
{
    DEBUG_MSG_FUNC_START;

    printf("SYSCLK_Frequency = %d\n",rcc_clocks.SYSCLK_Frequency );
    printf("HCLK_Frequency = %d\n",rcc_clocks.HCLK_Frequency );
    printf("PCLK1_Frequency = %d\n",rcc_clocks.PCLK1_Frequency );
    printf("PCLK2_Frequency = %d\n",rcc_clocks.PCLK2_Frequency );
    printf("ADCCLK_Frequency = %d\n",rcc_clocks.ADCCLK_Frequency );
}

/*
 * Name   : main
 * Input  : None
 * Output : None
 * Return : None
 */
int main(void)
{
    uint8_t ch;

    /* System Clocks Configuration */
    RCC_Configuration();

    RCC_GetClocksFreq(&rcc_clocks);

    /* NVIC configuration */
    NVIC_Configuration();

    /* Configure the GPIO ports */
    GPIO_Configuration();

    /* EXTI configuration */
    EXTI_Configuration();

    /* UART initialization */
    USART1_Init();

    /* Setup SysTick Timer for 1 msec interrupts  */
    if (SysTick_Config(rcc_clocks.SYSCLK_Frequency / 1000))
    { 
        /* Capture error */ 
        while (1);
    }

    printf("Mango Z1 test start...\n\n");

    while(1)
    {
        printf("\n---------------------\n");
        printf("Press menu key\n");
        printf("---------------------\n");
        printf("0> System Information\n");
        printf("---------------------\n");
        printf("1> LED Test\n");
        printf("2> KEY Test\n");
        printf("3> ZigBee Test\n");
        printf("---------------------\n");
        printf("x> quit\n\n");

        ch = USART_GetCharacter(USART1);
        printf(" is selected\n\n");

        switch((char)ch)
        {
        case '0':
            System_Information();
            break;

        case '1':
            LED_Test();
            break;

        case '2':
            KEY_Test();
            break;

        case '3':
            ZigBee_Test();
            break;
        }

        if('x' == (char)ch)
        {
            break;
        }
    }

    return 0;
}
