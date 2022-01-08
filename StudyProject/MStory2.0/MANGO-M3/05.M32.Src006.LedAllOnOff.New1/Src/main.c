#include "platform_config.h"



RCC_ClocksTypeDef rcc_clocks;



void System_Information()
{
    printf("SYSCLK_Frequency = %d\n",rcc_clocks.SYSCLK_Frequency );
    printf("HCLK_Frequency = %d\n",rcc_clocks.HCLK_Frequency );
    printf("PCLK1_Frequency = %d\n",rcc_clocks.PCLK1_Frequency );
    printf("PCLK2_Frequency = %d\n",rcc_clocks.PCLK2_Frequency );
    printf("ADCCLK_Frequency = %d\n",rcc_clocks.ADCCLK_Frequency );
}


static void delay_int_count(volatile unsigned int nTime)
{
    for(; nTime > 0; nTime--);
}

void delay_1_second(void)
{
    delay_int_count(806596);
}

void GPIO_B_Output_Init(uint16_t pinNum,
         GPIOSpeed_TypeDef speedValE, GPIOMode_Output_TypeDef modeE)
{
    uint32_t tmpVal = modeE << 2 | speedValE;
    uint32_t pinpos = 0x00;

    // pin #0 ~ #7
    if((pinNum & 0xFF) != 0)
    {
        for (pinpos = 0x00; pinpos < 0x08; pinpos++)
        {
            if (pinNum == ((uint32_t)0x01) << pinpos)
            {
                pinpos = pinpos * 4;
                GPIOB_CRL &= ~(0xF << pinpos);
                GPIOB_CRL |= tmpVal << pinpos;
                break;
            }
        }
    }

    // pin #8 ~ #15
    else
    {
        pinNum = pinNum >> 8;
        for (pinpos = 0x00; pinpos < 0x08; pinpos++)
        {
            if (pinNum == ((uint32_t)0x01) << pinpos)
            {
                pinpos = pinpos * 4;
                GPIOB_CRH &= ~(0xF << pinpos);
                GPIOB_CRH |= tmpVal << pinpos;
                break;
            }
        }
    }
}

/*
 * Name   : main
 * Input  : None
 * Output : None
 * Return : None
 */
int main(void)
{
    RCC_APB2ENR |= RCC_APB2Periph_GPIOB;

    GPIO_B_Output_Init(GPIO_LED1_PIN, GPIO_Speed_10MHz, GPIO_Mode_Out_PP);
    GPIO_B_Output_Init(GPIO_LED2_PIN, GPIO_Speed_10MHz, GPIO_Mode_Out_PP);
    GPIO_B_Output_Init(GPIO_LED3_PIN, GPIO_Speed_10MHz, GPIO_Mode_Out_PP);
    System_Information();
    LED_Test();

    while(1)
    {
        ;
    }
    return 0;
}