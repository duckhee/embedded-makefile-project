#include "stm32f10x.h"
#include "hw_config.h"
#include "platform_config.h"

int main(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIO_USART, ENABLE);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    GPIO_Configuration();

    USART1_Init();

    printf("Hello World ! - Mango Story 2.0 \r\n");

    return 0;
}
