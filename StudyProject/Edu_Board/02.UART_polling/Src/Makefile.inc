###########################################################
# GCC template makefile
###########################################################

UART_TEST_SOURCES = 
UART_TEST_SOURCES += main.c
UART_TEST_SOURCES += uart.c
UART_TEST_SOURCES += gpio.c
UART_TEST_SOURCES += stm32f4xx_hal_msp.c
UART_TEST_SOURCES += stm32f4xx_it.c
UART_TEST_SOURCES += system_stm32f4xx.c

EXTRAINCDIRS += $(TOP)/StudyProject/Edu_Board/02.UART_polling/Inc

C_SOURCES += $(UART_TEST_SOURCES)