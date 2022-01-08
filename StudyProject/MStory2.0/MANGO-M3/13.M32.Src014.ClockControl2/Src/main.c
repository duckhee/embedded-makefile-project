#include "hw_config.h"

extern __IO uint32_t StartUpCounter;

void System_Information(){
    RCC_ClocksTypeDef rcc_clocks;
    printf("StartUpCounter : %d\r\n", StartUpCounter);

    RCC_GetClocksFreq(&rcc_clocks);
    printf("SYSCLK_Frequency = %d\r\n",rcc_clocks.SYSCLK_Frequency );
    printf("HCLK_Frequency = %d\r\n",rcc_clocks.HCLK_Frequency );
    printf("PCLK1_Frequency = %d\r\n",rcc_clocks.PCLK1_Frequency );
    printf("PCLK2_Frequency = %d\r\n",rcc_clocks.PCLK2_Frequency );
    printf("ADCCLK_Frequency = %d\r\n",rcc_clocks.ADCCLK_Frequency );
}

int main(void){
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
