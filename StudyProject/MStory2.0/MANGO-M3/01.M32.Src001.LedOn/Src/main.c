/**
 * 
 * File Name : main.c
 * Author : Doukhee
 * Version : V1.0
 * Date : 05/23/2020
 */

/**
 * 
 * Push/Pull은 말 그대로 전원 전압으로 밀어 올리거나, 그라운드로 끌어 내린다는 뜻
 * 전원이나 그라운드쪽으로 내부 스위치를 도통 시킨다는 의미. 
 * IO Buffer의 설계에 따라 많게는 수십 mA이상까지도 설계할 수 있으며, 특수한 경우 100mA이상도 가능하다.
 * 다만, slewrate 조절 및 발열 등의 문제로 대개는 4~8mA정도의 버퍼를 쓰고, MCU의 경우는 LED등을 직접 드라이브 할 수 있도록 
 * 30mA정도까지도 가능하게 한다.
 * 
 * Open Drain은 TTL의 Open-Collector와 비슷한 개념으로 P-MOS FET가 항상 OFF로 아래쪽 NMOS FET의 Drain이 Open
 * (즉, 전원 측과 항상 끊어져 있는 상태)라는 것으로, 외부 Pull-up등으로 High값을 만든다.
 * 이때, 외부 저항의 크기에 따라 Low->High, High->Low 전환에 Un-balance가 발생할 수 밖에 없지만, I2c같은 버스 구조에서는 
 * 비교적 널리 사용되는 형태이다.
 * 
 */

void delay_int_count(volatile unsigned int nTime){
    for(; nTime > 0; nTime--);
}

void Delay_1_second(){
    delay_int_count(806596);
}

int main(){
    /** APB2 Peripheral clock enable register(RCC_APB2ENR) */
    /** RCC I/O PortB Enable */
    /** RCC_APB2ENR */
    (*(volatile unsigned *)0x40021018) |= 0x8; /** IOPB EN 0x8 */

#if 0
    (*(volatile unsigned *)0x40010C04) |= 0x10;
#else
    /** PortB RESET(HIGHT) */
    /**  GPIO_CRH */
    /** 9Pin RESET 0 */
    (*(volatile unsigned *)0x40010C04) &= 0xFFFFFF0F;
    /** Pin9 General purpose output push-pull Mode Output mode, Max speed 10MHz */
//    (*(volatile unsigned *)0x40010C04) |= 0x10;
    /** Pin9 General purpose output Open-drain Mode Output mode, Max speed 10MHz */
//    (*(volatile unsigned *)0x40010C04) |= 0x50;
    /** Pin9 Alternate function output Push-pull Mode Output mode, Max speed 10MHz */
//    (*(volatile unsigned *)0x40010C04) |= 0x90;
    /** Pin9 Alternate function output Open-drain Mode Output mode, Max speed 10MHz */
    (*(volatile unsigned *)0x40010C04) |= 0xD0;
    /** PortB RESET(LOW) */
    /**  GPIO_CRL */
    (*(volatile unsigned *)0x40010C00) &= 0xFF0FFFFF;
    /** LED YELLOW PIN5 ON */
    //(*(volatile unsigned *)0x40010C00) |= 0x100000;
    /** LED RED ON */
    /** Pin 9 */
    //(*(volatile unsigned *)0x40010C04) |= 0x10;
    /** GPIO PIN9 RESET */
    //(*(volatile unsigned *)0x40010C14) |= 0x200;
    Delay_1_second();
    /** GPIO PIN9 SET */
    //(*(volatile unsigned *)0x40010C10) |= 0x200;
    /** LED BLUE ON */
    /** GPIO PIN8 SET */
    //(*(volatile unsigned *)0x40010C04) |= 0x1;
//    (*(volatile unsigned *)0x40010C04) |= 0x50;
//    (*(volatile unsigned *)0x40010C04) |= 0x90;
//    (*(volatile unsigned *)0x40010C04) |= 0xD0;
#endif

    while(1)
    {
        ;
    }

    return 0;
}