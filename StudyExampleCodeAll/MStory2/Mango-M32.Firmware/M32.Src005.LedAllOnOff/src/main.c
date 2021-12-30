/*
 * (C) COPYRIGHT 2009 CRZ
 *
 * File Name : main.c
 * Author    : POOH
 * Version   : V1.0
 * Date      : 08/12/2009
 */

static void delay_int_count(volatile unsigned int nTime)
{
    for(; nTime > 0; nTime--);
}

void delay_1_second(void)
{
    delay_int_count(806596);
}

/*
 * Name   : main
 * Input  : None
 * Output : None
 * Return : None
 */
int main(void)
{
    (*(volatile unsigned *)0x40021018) |= 0x8;

    // PIN #5 setting ...
    (*(volatile unsigned *)0x40010C00) &= 0xFF0FFFFF;
    (*(volatile unsigned *)0x40010C00) |= 0x100000;

    // PIN #9 & #8 setting ...
    (*(volatile unsigned *)0x40010C04) &= 0xFFFFFF00;
    (*(volatile unsigned *)0x40010C04) |= 0x10;
    (*(volatile unsigned *)0x40010C04) |= 0x1;

    (*(volatile unsigned *)0x40010C14) |= 0x200;
    delay_1_second();
    (*(volatile unsigned *)0x40010C10) |= 0x200;
    delay_1_second();
    (*(volatile unsigned *)0x40010C14) |= 0x100;
    delay_1_second();
    (*(volatile unsigned *)0x40010C10) |= 0x100;
    delay_1_second();
    (*(volatile unsigned *)0x40010C14) |= 0x20;
    delay_1_second();
    (*(volatile unsigned *)0x40010C10) |= 0x20;
    delay_1_second();

    while(1)
    {
        ;
    }
}
