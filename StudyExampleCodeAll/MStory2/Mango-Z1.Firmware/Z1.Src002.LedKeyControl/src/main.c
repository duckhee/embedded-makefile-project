/*
 * (C) COPYRIGHT 2009 CRZ
 *
 * File Name : main.c
 * Author    : POOH
 * Version   : V1.0
 * Date      : 08/12/2009
 */

/* includes */

#include "stm32f10x.h"
#include "hw_config.h"
#include "platform_config.h"

/* functions */

static void delay_int_count(volatile unsigned int nTime)
{
    for(; nTime > 0; nTime--);
}

void delay_1_second(void)
{
    delay_int_count(806596);
}

void delay_100_milli_second(void)
{
    delay_int_count(80660);
}

void System_Information()
{
    DEBUG_MSG_FUNC_START;

    RCC_ClocksTypeDef  rcc_clocks;

    printf("RCC->CFGR : 0x%0X\n", RCC->CFGR);

    RCC_GetClocksFreq(&rcc_clocks);
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

    /* Enable GPIOA clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIO_USART, ENABLE);

    /* Enable GPIOB clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIO_LED, ENABLE);

    /* Enable USART1 clocks */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    /* Configure the GPIO ports */
    GPIO_Configuration();

    /* UART initialization */
    USART1_Init();

    delay_1_second();

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
        }

        if('x' == (char)ch)
        {
            break;
        }
    }

    return 0;
}
