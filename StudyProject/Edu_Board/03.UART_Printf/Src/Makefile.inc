###########################################################
# GCC template makefile
###########################################################

UART_PRINTF_SOURCES = 
UART_PRINTF_SOURCES += gpio.c
UART_PRINTF_SOURCES += main.c
UART_PRINTF_SOURCES += stm32f4xx_hal_msp.c
UART_PRINTF_SOURCES += stm32f4xx_it.c
UART_PRINTF_SOURCES += system_stm32f4xx.c
UART_PRINTF_SOURCES += uart.c

EXTRAINCDIRS += $(TOP)/StudyProject/Edu_Board/03.UART_Printf/Inc

C_SOURCES += $(UART_PRINTF_SOURCES)