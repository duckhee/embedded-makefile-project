/*
 * (C) COPYRIGHT 2009 CRZ
 *
 * File Name : main.c
 * Author    : POOH
 * Version   : V1.0
 * Date      : 08/12/2009
 */

/* includes */

#include "hw_config.h"

/* Private define ------------------------------------------------------------*/
#define SP_PROCESS_SIZE             0x200  /* Process stack size */
#define SP_PROCESS                  0x02   /* Process stack */
#define SP_MAIN                     0x00   /* Main stack */
#define THREAD_MODE_PRIVILEGED      0x00   /* Thread mode has privileged access */
#define THREAD_MODE_UNPRIVILEGED    0x01   /* Thread mode has unprivileged access */

/* Private macro -------------------------------------------------------------*/ 
#if defined ( __CC_ARM   )
__ASM void __SVC(void) 
{ 
  SVC 0x01 
  BX R14
}
#elif defined ( __ICCARM__ )
static __INLINE  void __SVC()                     { __ASM ("svc 0x01");}
#elif defined   (  __GNUC__  )
static __INLINE void __SVC()                      { __ASM volatile ("svc 0x01");}
#endif

/* Private variables ---------------------------------------------------------*/
__IO uint8_t PSPMemAlloc[SP_PROCESS_SIZE];

uint32_t  Get_Current_ThreadMode(void)
{
    /* Check Thread mode privilege status */
    if((__get_CONTROL() & 0x01) == THREAD_MODE_PRIVILEGED)
    {
        /* Thread mode has privileged access  */
        return THREAD_MODE_PRIVILEGED;
    }
    else
    {
        /* Thread mode has unprivileged access*/
        return THREAD_MODE_UNPRIVILEGED;
    }
}

uint32_t  Get_Current_Stack(void)
{
    if((__get_CONTROL() & 0x02) == SP_MAIN)
    {
        /* Main stack is used as the current stack */
        return SP_MAIN;
    }
    else
    {
        /* Process stack is used as the current stack */
        return SP_PROCESS;
    }
}

void Mode_Privilege_Test(void)
{
    __IO uint32_t Index;

    DEBUG_MSG_FUNC_START;

    /* Switch Thread mode Stack from Main to Process */
    /* Initialize memory reserved for Process Stack */
    for(Index = 0; Index < SP_PROCESS_SIZE; Index++)
    {
        PSPMemAlloc[Index] = 0x00;
    }
    printf("PSPMemAlloc address = 0x%0X\n", PSPMemAlloc);

    printf("(1) CurrentStack = %d, ThreadMode = %d\n",
           Get_Current_Stack(), Get_Current_ThreadMode());

    /* Set Process stack value */ 
    __set_PSP((uint32_t)PSPMemAlloc + SP_PROCESS_SIZE);
    printf("(2) CurrentStack = %d, ThreadMode = %d\n",
           Get_Current_Stack(), Get_Current_ThreadMode());

    /* Select Process Stack as Thread mode Stack */
    __set_CONTROL(SP_PROCESS);
    printf("(3) CurrentStack = %d, ThreadMode = %d\n",
           Get_Current_Stack(), Get_Current_ThreadMode());

    /* Get the Thread mode stack used */
    if(Get_Current_Stack() == SP_MAIN)
    {
        printf("CurrentStack is Main Stack\n");
    }
    else
    {
        printf("CurrentStack is Process Stack\n");

        /* Get process stack pointer value */
        printf("PSPValue = 0x%0X\n", __get_PSP());
    }
  
    /* Switch Thread mode from privileged to unprivileged */
    /* Thread mode has unprivileged access */
    __set_CONTROL(THREAD_MODE_UNPRIVILEGED | SP_PROCESS);
    /* Unprivileged access mainly affect ability to:
    - Use or not use certain instructions such as MSR fields
    - Access System Control Space (SCS) registers such as NVIC and SysTick */
    printf("(4) CurrentStack = %d, ThreadMode = %d\n",
           Get_Current_Stack(), Get_Current_ThreadMode());

    /* Switch back Thread mode from unprivileged to privileged */
    /* Try to switch back Thread mode to privileged (Not possible, this can be
    done only in Handler mode) */
    __set_CONTROL(THREAD_MODE_PRIVILEGED | SP_PROCESS);
    printf("(5) CurrentStack = %d, ThreadMode = %d\n",
           Get_Current_Stack(), Get_Current_ThreadMode());

    /* Generate a system call exception, and in the ISR switch back Thread mode
    to privileged */
    __SVC();
    printf("(6) CurrentStack = %d, ThreadMode = %d\n",
           Get_Current_Stack(), Get_Current_ThreadMode());

    /* Select Main Stack */
    __set_CONTROL(SP_MAIN);
    printf("(7) CurrentStack = %d, ThreadMode = %d\n",
           Get_Current_Stack(), Get_Current_ThreadMode());
}

/* global variables */

RCC_ClocksTypeDef  rcc_clocks;

bool g_TestProcessState = FALSE;

/* functions */

void System_Information()
{
    printf("SYSCLK_Frequency = %d\n",rcc_clocks.SYSCLK_Frequency );
    printf("HCLK_Frequency = %d\n",rcc_clocks.HCLK_Frequency );
    printf("PCLK1_Frequency = %d\n",rcc_clocks.PCLK1_Frequency );
    printf("PCLK2_Frequency = %d\n",rcc_clocks.PCLK2_Frequency );
    printf("ADCCLK_Frequency = %d\n",rcc_clocks.ADCCLK_Frequency );
}

void USB_Test_Start (void)
{
    USB_Interrupts_Config();
    Set_USBClock();
    USB_Init();
}

/*
 * Name   : main
 * Input  : None
 * Output : None
 * Return : None
 */
int main(void)
{
    uint8_t ch;

    /* System Clocks Configuration */
    RCC_Configuration();

    RCC_GetClocksFreq(&rcc_clocks);

    /* NVIC configuration */
    NVIC_Configuration();

    /* Configure the GPIO ports */
    GPIO_Configuration();

    /* EXTI configuration */
    EXTI_Configuration();

    /* UART initialization */
    USART1_Init();

    /* Setup SysTick Timer for 1 msec interrupts  */
    if (SysTick_Config(rcc_clocks.SYSCLK_Frequency / 1000))
    { 
        /* Capture error */ 
        while (1);
    }

    USB_Cable_Config(DISABLE);

    Delay(500);

#if defined ( __CC_ARM   )
    printf("__CC_ARM\n");
#elif defined ( __ICCARM__ )
    printf("__ICCARM__\n");
#elif defined   (  __GNUC__  )
    printf("__GNUC__\n");
#endif

    while(1)
    {
        printf("\n---------------------\n");
#ifdef BOARD_DEF_MANGO_M32
        printf("Mango M32 test start...\n");
#elif  BOARD_DEF_MANGO_Z1
        printf("Mango Z1 test start...\n");
#endif
        printf("Press menu key\n");
        printf("---------------------\n");
        printf("0> System Information\n");
        printf("---------------------\n");
        printf("1> LED Test\n");
        printf("2> KEY Test\n");
#ifdef BOARD_DEF_MANGO_M32
        printf("3> 7-Segment Test\n");
#elif  BOARD_DEF_MANGO_Z1
        printf("3> ZigBee Test\n");
#endif
        printf("4> USB HID Test\n");
        printf("5> Mode_Privilege_Test\n");
        printf("---------------------\n");
        printf("x> quit\n\n");

        ch = USART_GetCharacter(USART1);
        printf(" is selected\n\n");

        switch((char)ch)
        {
        case '0':
            System_Information();
            break;

        case '1':
            LED_Test();
            break;

        case '2':
            KEY_Test();
            break;

        case '3':
#ifdef BOARD_DEF_MANGO_M32
            Seven_Segment_Test();
#elif  BOARD_DEF_MANGO_Z1
            ZigBee_Test();
#endif
            break;

        case '4':
            g_TestProcessState = TRUE;

            /* USB initialization */
            USB_Test_Start();
            Delay(500);
            USB_Cable_Config(ENABLE);
            break;

        case '5':
            Mode_Privilege_Test();
            break;
        }

        if('x' == (char)ch)
        {
            break;
        }
    }

    return 0;
}
