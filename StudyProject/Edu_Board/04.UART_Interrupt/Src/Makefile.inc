###########################################################
# GCC template makefile
###########################################################

UART_INTERRUPT_SOURCES = 
UART_INTERRUPT_SOURCES += main.c
UART_INTERRUPT_SOURCES += gpio.c
UART_INTERRUPT_SOURCES += stm32f4xx_hal_msp.c
UART_INTERRUPT_SOURCES += stm32f4xx_it.c
UART_INTERRUPT_SOURCES += system_stm32f4xx.c
UART_INTERRUPT_SOURCES += uart.c

EXTRAINCDIRS += $(TOP)/StudyProject/Edu_Board/04.UART_Interrupt/Inc

C_SOURCES += $(UART_INTERRUPT_SOURCES)