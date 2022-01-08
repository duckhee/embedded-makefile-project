
#include "hw_config.h"
#include "lib_dbg.h"

RCC_ClocksTypeDef rcc_clocks;

void SystemInformation(){
    printf("SYSCLK_Frequency = %d\r\n",rcc_clocks.SYSCLK_Frequency );
    printf("HCLK_Frequency = %d\r\n",rcc_clocks.HCLK_Frequency );
    printf("PCLK1_Frequency = %d\r\n",rcc_clocks.PCLK1_Frequency );
    printf("PCLK2_Frequency = %d\r\n",rcc_clocks.PCLK2_Frequency );
    printf("ADCCLK_Frequency = %d\r\n",rcc_clocks.ADCCLK_Frequency );
}

int main(void){
    RCC_Configuration();
    RCC_GetClocksFreq(&rcc_clocks);
    /* NVIC configuration */
    NVIC_Configuration();
    USART1_Init();
    GPIO_Configuration();
    debug();
    /* Setup SysTick Timer for 1 msec interrupts  */
    if (SysTick_Config(rcc_clocks.SYSCLK_Frequency / 1000))
    { 
        /* Capture error */ 
        while (1);
    }
    SystemInformation();
    LED_Off_All();
    PowerOff_7_SEG();
    LED_Test();
    LED_Off_All();
    //RCC_APB1PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
    while(1){
        ;
    }

    return 0;
}