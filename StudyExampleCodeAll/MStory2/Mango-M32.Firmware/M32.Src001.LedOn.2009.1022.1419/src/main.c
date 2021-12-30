/*
 * (C) COPYRIGHT 2009 CRZ
 *
 * File Name : main.c
 * Author    : POOH
 * Version   : V1.0
 * Date      : 08/12/2009
 */

/*
 * Name   : main
 * Input  : None
 * Output : None
 * Return : None
 */
int main(void)
{
    (*(volatile unsigned *)0x40021018) |= 0x8;

#if 0
    (*(volatile unsigned *)0x40010C04) |= 0x10;
#else
    (*(volatile unsigned *)0x40010C04) &= 0xFFFFFF0F;

//    (*(volatile unsigned *)0x40010C04) |= 0x10;
//    (*(volatile unsigned *)0x40010C04) |= 0x50;
//    (*(volatile unsigned *)0x40010C04) |= 0x90;
    (*(volatile unsigned *)0x40010C04) |= 0xD0;
#endif

    while(1)
    {
        ;
    }
}
