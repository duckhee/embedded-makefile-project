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

/*
 * Name   : main
 * Input  : None
 * Output : None
 * Return : None
 */
int main(void)
{
    int i;

    (*(volatile unsigned *)0x40021018) |= 0x8;
    (*(volatile unsigned *)0x40010C04) |= 0x10;

    (*(volatile unsigned *)0x40010C14) |= 0x200;

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

    (*(volatile unsigned *)0x40010C10) |= 0x200;

    while(1)
    {
        ;
    }
}
