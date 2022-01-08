/**
 * 
 * Author   :   doukhee
 * Version  :   V1.0
 * Date     :   25/05/2020
 * 
 */

/**
 * Clock Configuration register (RCC_CFGR)
 * Address offset : 0x04
 * Reset Value : 0x0000 0000
 * 이 register의 경우 외부 오실레이터, 내부 오실래이터 PLL등을 설정하는 register 기본적으로 HSI(내부 오실레이터)사용한다.
 * 
 */

void delay_int_count(volatile unsigned nTime){
    for(; nTime > 0; nTime--);
}

void delay_1_second(){
    delay_int_count(806596);
}

int main(){

    /** APB2 Peripheral clock enable register(RCC_APB2ENR) */
    /** RCC I/O PortB Enable */
    /** RCC_APB2ENR */
    (*(volatile unsigned *)0x40021018) |= 0x8;
    /** GPIO_CRL RESET */
    /** 5Pin RESET 0 */
    (*(volatile unsigned *)0x40010C00) &= 0xFF0FFFFF;
    /** Pin5 General purpose output push-pull Mode Output mode, Max speed 10MHz */
    (*(volatile unsigned *)0x40010C00) |= 0x100000;
    /** GPIO_CRH RESET */
    /** 9Pin, 8Pin RESET 0 */
    (*(volatile unsigned *)0x40010C04) &= 0xFFFFFF00;
    /** Pin9 General purpose output push-pull Mode Output mode, Max speed 10MHz */
    (*(volatile unsigned *)0x40010C04) |= 0x10;
    /** Pin8 General purpose output push-pull Mode Output mode, Max speed 10MHz */
    (*(volatile unsigned *)0x40010C04) |= 0x1;
    /** GPIO RESET Bit */
    /** Port bit reset register GPIOx_BRR */
    /** 
     * Address Offset : 0x14
     * Reset Value 0x0000 0000
     */
    (*(volatile unsigned *)0x40010C14) |= 0x200; /** 0x200 9Pin 1 */
    delay_1_second();
    /** GPIO SET Bit */
    /** Port bit set register GPIOx_BSRR */
    /** 
     * Address Offset : 0x10
     * Reset Value : 0x0000 0000
     */
    (*(volatile unsigned *)0x40010C10) |= 0x200; /** 0x200 9Pin 1 */
    delay_1_second();
    /** GPIO RESET Bit */
    /** Port bit reset register GPIOx_BRR */
    /** 
     * Address Offset : 0x14
     * Reset Value 0x0000 0000
     */
    (*(volatile unsigned *)0x40010C14) |= 0x100; /** 0x100 8Pin 1 */
    delay_1_second();
    /** GPIO SET Bit */
    /** Port bit set register GPIOx_BSRR */
    /** 
     * Address Offset : 0x10
     * Reset Value : 0x0000 0000
     */
    (*(volatile unsigned *)0x40010C10) |= 0x100; /** 0x100 8Pin 1 */
    delay_1_second();
    /** GPIO RESET Bit */
    /** Port bit reset register GPIOx_BRR */
    /** 
     * Address Offset : 0x14
     * Reset Value 0x0000 0000
     */
    (*(volatile unsigned *)0x40010C14) |= 0x20; /** 0x20 5Pin 1 */
    delay_1_second();
    /** GPIO SET Bit */
    /** Port bit set register GPIOx_BSRR */
    /** 
     * Address Offset : 0x10
     * Reset Value : 0x0000 0000
     */
    (*(volatile unsigned *)0x40010C10) |= 0x20; /** 0x20 5Pin 1 */
    delay_1_second();

    while(1){
        ;
    }

    return 0;
}