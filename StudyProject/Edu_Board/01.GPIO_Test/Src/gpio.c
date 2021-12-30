/**
 * 
 */

#include "gpio.h"

void MX_GPIO_Init();


void LED_One_RGB_Set(uint16_t red, uint16_t blue, uint16_t green);
void LED_One_Red_On();
void LED_One_Blue_On();
void LED_One_Green_On();

void LED_One_Red_Off();
void LED_One_Blue_Off();
void LED_One_Green_Off();

void LED_Two_RGB_Set(uint16_t red, uint16_t blue, uint16_t green);
void LED_Two_Red_On();
void LED_Two_Blue_On();
void LED_Two_Green_On();

void LED_Two_Red_Off();
void LED_Two_Blue_Off();
void LED_Two_Green_Off();

void MX_Switch_Init();

void Sw1_check();
void Sw2_check();
void Sw3_check();
void Sw4_check();

void Sw_Test();

void LED_Test();

/** LED GPIO Init Setting */
void MX_GPIO_Init(){
    /** GPIO Init Type structure Setting */
    GPIO_InitTypeDef GPIO_Initstruct = {0, };
    /** Clock Setting */
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();

    /** LED One Init */
    GPIO_Initstruct.Pin = LED1_RED | LED1_BLUE | LED1_GREEN;
    GPIO_Initstruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_Initstruct.Pull = GPIO_NOPULL;
    GPIO_Initstruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED1_PORT, &GPIO_Initstruct);

    /** LED Two Init */
    GPIO_Initstruct.Pin = LED2_BLUE | LED2_GREEN;
    GPIO_Initstruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_Initstruct.Pull = GPIO_NOPULL;
    GPIO_Initstruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_Initstruct);

    /** LED Two Red Init */
    GPIO_Initstruct.Pin = LED2_RED;
    GPIO_Initstruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_Initstruct.Pull = GPIO_NOPULL;
    GPIO_Initstruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED2_PORT2, &GPIO_Initstruct);
}

void LED_One_RGB_Set(uint16_t red, uint16_t blue, uint16_t green);
void LED_One_Red_On(){
    HAL_GPIO_WritePin(LED1_PORT, LED1_RED, GPIO_PIN_RESET);
}
void LED_One_Blue_On(){
    HAL_GPIO_WritePin(LED1_PORT, LED1_BLUE, GPIO_PIN_RESET);
}
void LED_One_Green_On(){
    HAL_GPIO_WritePin(LED1_PORT, LED1_GREEN, GPIO_PIN_RESET);
}

void LED_One_Red_Off(){
    HAL_GPIO_WritePin(LED1_PORT, LED1_RED, GPIO_PIN_SET);
}
void LED_One_Blue_Off(){
    HAL_GPIO_WritePin(LED1_PORT, LED1_BLUE, GPIO_PIN_SET);
}
void LED_One_Green_Off(){
    HAL_GPIO_WritePin(LED1_PORT, LED1_GREEN, GPIO_PIN_SET);
}

void LED_Two_RGB_Set(uint16_t red, uint16_t blue, uint16_t green);
void LED_Two_Red_On(){
    HAL_GPIO_WritePin(LED2_PORT2, LED2_RED, GPIO_PIN_RESET);
}
void LED_Two_Blue_On(){
    HAL_GPIO_WritePin(LED2_PORT, LED2_BLUE, GPIO_PIN_RESET);
}
void LED_Two_Green_On(){
    HAL_GPIO_WritePin(LED2_PORT, LED2_GREEN, GPIO_PIN_RESET);
}

void LED_Two_Red_Off(){
    HAL_GPIO_WritePin(LED2_PORT2, LED2_RED, GPIO_PIN_SET);
}
void LED_Two_Blue_Off(){
    HAL_GPIO_WritePin(LED2_PORT, LED2_BLUE, GPIO_PIN_SET);
}
void LED_Two_Green_Off(){
    HAL_GPIO_WritePin(LED2_PORT, LED2_GREEN, GPIO_PIN_SET);
}

void LED_Test(){
    LED_One_Red_On();
    HAL_Delay(1000);
    LED_One_Blue_On();
    HAL_Delay(1000);
    LED_One_Green_On(1000);
    HAL_Delay(1000);
    LED_One_Red_Off();
    HAL_Delay(1000);
    LED_One_Blue_Off();
    HAL_Delay(1000);
    LED_One_Green_Off();
    LED_Two_Blue_On();
    HAL_Delay(1000);
    LED_Two_Red_On();
    HAL_Delay(1000);
    LED_Two_Green_On();
    HAL_Delay(1000);
    LED_Two_Green_Off();
    HAL_Delay(1000);
    LED_Two_Blue_Off();
    HAL_Delay(1000);
    LED_Two_Red_Off();
}

void MX_Switch_Init(){
    GPIO_InitTypeDef GPIO_Initstucture = {0, };
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
    /** Sw1 Init */
    GPIO_Initstucture.Pin = GPIO_PIN_4;
    GPIO_Initstucture.Mode = GPIO_MODE_INPUT;
    GPIO_Initstucture.Pin = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOD, &GPIO_Initstucture);
    /** Sw2 Init */
    GPIO_Initstucture.Pin = GPIO_PIN_10;
    GPIO_Initstucture.Mode = GPIO_MODE_INPUT;
    GPIO_Initstucture.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOD, &GPIO_Initstucture);
    /** Sw3 Init */
    GPIO_Initstucture.Pin = GPIO_PIN_3;
    GPIO_Initstucture.Mode = GPIO_MODE_INPUT;
    GPIO_Initstucture.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOE, &GPIO_Initstucture);
    /** Sw4 Init */
    GPIO_Initstucture.Pin = GPIO_PIN_15;
    GPIO_Initstucture.Mode = GPIO_MODE_INPUT;
    GPIO_Initstucture.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOC, &GPIO_Initstucture);

}

void Sw1_check(){
    if(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_4) == SET){
        LED_One_Blue_On();
    }else{
        LED_One_Blue_Off();
    }
}
void Sw2_check(){
    if(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10) == SET){
        LED_One_Red_On();
    }else{
        LED_One_Red_Off();
    }
}
void Sw3_check(){
    if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_3) == SET){
        LED_One_Green_On();
    }else{
        LED_One_Green_Off();
    }
}
void Sw4_check(){
    if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15) == SET){
        LED_One_Green_On();
        LED_One_Blue_On();
    }else{
        LED_One_Green_Off();
        LED_One_Blue_Off();
    }
}

void Sw_Test(){
    Sw1_check();
    Sw2_check();
    Sw3_check();
    Sw4_check();
}