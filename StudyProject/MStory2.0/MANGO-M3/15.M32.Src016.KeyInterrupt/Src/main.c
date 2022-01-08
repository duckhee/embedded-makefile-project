
/* includes */

#include "hw_config.h"

/* functions */

extern __IO uint32_t StartUpCounter;

RCC_ClocksTypeDef  rcc_clocks;

void System_Information()
{

    printf("StartUpCounter : %d\r\n", StartUpCounter);

    printf("SYSCLK_Frequency = %d\r\n",rcc_clocks.SYSCLK_Frequency );
    printf("HCLK_Frequency = %d\r\n",rcc_clocks.HCLK_Frequency );
    printf("PCLK1_Frequency = %d\r\n",rcc_clocks.PCLK1_Frequency );
    printf("PCLK2_Frequency = %d\r\n",rcc_clocks.PCLK2_Frequency );
    printf("ADCCLK_Frequency = %d\r\n",rcc_clocks.ADCCLK_Frequency );
}

void DELAY_Test(void)
{
    uint32_t i;

    for(i=0; i<50; i++)
    {
        delay_1_second();
    }

    printf("DELAY_Test done !!\r\n");
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

    RCC->APB2ENR |= RCC_APB2Periph_GPIOA;
    RCC->APB2ENR |= RCC_APB2Periph_GPIOB;
    RCC->APB2ENR |= RCC_APB2Periph_USART1;

    RCC_GetClocksFreq(&rcc_clocks);

    /* NVIC configuration */
    NVIC_Configuration();

    /* Configure the GPIO ports */
    GPIO_Configuration();

    EXTI_Configuration();

    /* UART initialization */
    USART1_Init();

    /* Setup SysTick Timer for 1 msec interrupts  */
    if (SysTick_Config(rcc_clocks.SYSCLK_Frequency / 1000))
    { 
        /* Capture error */ 
        while (1);
    }
    System_Information();
    LED_Off_All();
    printf("KEY INTERRUPT TEST \r\n");
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
        printf("4> 1 sec Delay Test\r\n");
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

        case '4':
            DELAY_Test();
            break;
        }

        if('x' == (char)ch)
        {
            break;
        }
    }
}
