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

/* functions */

extern __IO uint32_t StartUpCounter;

void System_Information()
{
    printf("USART1->BRR : 0x%08X\r\n", USART1->BRR);
    printf("StartUpCounter : %d\r\n", StartUpCounter);
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

    RCC_Configuration();

    RCC->APB2ENR |= RCC_APB2Periph_GPIOA;
    RCC->APB2ENR |= RCC_APB2Periph_GPIOB;
    RCC->APB2ENR |= RCC_APB2Periph_USART1;

    GPIO_Configuration();

    USART1_Init();
    LED_Off_All();
    System_Information();
    while(1)
    {
        printf("\r\n---------------------\r\n");
        printf("Press menu key\r\n");
        printf("---------------------\r\n");
        printf("0> System Information\r\n");
        printf("---------------------\r\n");
        printf("1> LED Test\r\n");
        printf("2> KEY Test\r\n");
        printf("3> 7-Segment Test\r\n");
        printf("---------------------\r\n");
        printf("x> quit\r\n\r\n");

        ch = USART_GetCharacter(USART1);
        printf(" is selected\r\n\r\n");

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
            Seven_Segment_Test();
            break;
        }

        if('x' == (char)ch)
        {
            break;
        }
    }
}
