/*
 *
 * File Name : main.c
 * Author    : Doukhee
 * Version   : V1.0
 * Date      : 24/05/2020
 */



int main(void)
{
    /** APB2 Peripheral clock enable register(RCC_APB2ENR) */
    /** RCC I/O PortB Enable */
    /** RCC_APB2ENR */
    (*(volatile unsigned *)0x40021018) |= 0x8;

#if 0
    /** GPIO_CRH */
    /** Pin9 General purpose output push-pull Mode Output mode, Max speed 10MHz */
    (*(volatile unsigned *)0x40010C04) |= 0x10;
#else
    /** GPIO_CRH RESET */
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
#endif

    while(1)
    {
        ;
    }
}
