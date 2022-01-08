

/* includes */

#include "hw_config.h"

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

    printf("RCC->CFGR : 0x%0X\r\n", RCC->CFGR);

    RCC_GetClocksFreq(&rcc_clocks);
    printf("SYSCLK_Frequency = %d\r\n",rcc_clocks.SYSCLK_Frequency );
    printf("HCLK_Frequency = %d\r\n",rcc_clocks.HCLK_Frequency );
    printf("PCLK1_Frequency = %d\r\n",rcc_clocks.PCLK1_Frequency );
    printf("PCLK2_Frequency = %d\r\n",rcc_clocks.PCLK2_Frequency );
    printf("ADCCLK_Frequency = %d\r\n",rcc_clocks.ADCCLK_Frequency );
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

    /* Configure the GPIO ports */
    GPIO_Configuration();

    /* UART initialization */
    USART1_Init();

    delay_1_second();

    LED_Off_All();

    printf("Mango Z1 test start...\r\n\r\n");

    while(1)
    {
        printf("\r\n---------------------\r\n");
        printf("Press menu key\r\n");
        printf("---------------------\r\n");
        printf("0> System Information\r\n");
        printf("---------------------\r\n");
        printf("1> LED Test\r\n");
        printf("2> KEY Test\r\n");
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
        }

        if('x' == (char)ch)
        {
            break;
        }
    }

    return 0;
}
