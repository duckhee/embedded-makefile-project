/**
 * 
 * 
 * Author   : doukhee
 * Version  : V1.0
 * Date:    : 25/05/2020
 * 
 */

/**
 * Set시 해당되는 핀의 LED가 꺼진다.
 * Reset시 해당되는 핀의 LED가 켜진다.
 * 
 */

void delay_int_count(volatile unsigned int nTime){
    for(; nTime > 0; nTime--);
}

int main(){

    /** APB2 Peripheral clock enable register(RCC_APB2ENR) */
    /** RCC I/O PortB Enable */
    /** RCC_APB2ENR */
    (*(volatile unsigned *)0x40021018) |= 0x8;
    /** Pin9 General purpose output push-pull Mode Output mode, Max speed 10MHz */
    (*(volatile unsigned *)0x40010C04) |= 0x10;
    /** GPIO RESET Bit */
    /** Port bit reset register GPIOx_BRR */
    /** 
     * Address Offset : 0x14
     * Reset Value 0x0000 0000
     */
    /** 9Pin Reset */
    (*(volatile unsigned *)0x40010C14) |= 0x200; /** 0x200 9Pin 1 */

#if 1
    delay_int_count(806596);
    delay_int_count(806596);
    delay_int_count(806596);
    delay_int_count(806596);
    delay_int_count(806596);
    delay_int_count(806596);
    delay_int_count(806596);
    delay_int_count(806596);
    delay_int_count(806596);
    delay_int_count(806596);
#else
    for(i = 0; i < 0x400; i++)
    {
        delay_int_count(10240);
    }
#endif

    /** GPIO SET Bit */
    /** Port bit set register GPIOx_BSRR */
    /** 
     * Address Offset : 0x10
     * Reset Value : 0x0000 0000
     */
    /** 9Pin Set */
    (*(volatile unsigned *)0x40010C10) |= 0x200;
    while(1){
        ;
    }
    return 0;
}