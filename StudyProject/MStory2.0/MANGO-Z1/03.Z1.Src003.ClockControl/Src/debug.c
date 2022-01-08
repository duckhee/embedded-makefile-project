/* Includes ------------------------------------------------------------------*/
#include "debug.h"

void DebugMsg_FunctionStart(char const * fName_p)
{
#ifdef  DEBUG_MSG_LEVEL0
    printf("%s() S\r\n", fName_p);
#endif
}

void DebugMsg_FunctionEnd(char const * fName_p)
{
#ifdef  DEBUG_MSG_LEVEL0
    printf("%s() E\r\n", fName_p);
#endif
}

void DebugMsg_FunctionNotify(char const * fName_p, int lineNum)
{
#ifdef  DEBUG_MSG_LEVEL0
    printf("%s() %d\r\n", fName_p, lineNum);
#endif
}

void DebugMsg_FunctionError(char const * fName_p, int lineNum)
{
#ifdef  DEBUG_MSG_LEVEL0
    printf("[ERROR] %s() %d\r\n", fName_p, lineNum);
#endif
}

#ifdef  USE_FULL_ASSERT
void DebugMsg_Assert(char const * fName_p, int lineNum)
{
    printf("!!! ASSERT FAILED !!! %s() %d\r\n", fName_p, lineNum);
}

/*******************************************************************************
* Function Name  : assert_failed
* Description    : Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
* Input          : - file: pointer to the source file name
*                  - line: assert_param error line source number
* Output         : None
* Return         : None
*******************************************************************************/
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\r\n", file, line) */
    printf("Wrong parameters value: file %s on line %d\r\r\n", file, line);

  /* Infinite loop */
  while (1)
  {}
}
#endif

