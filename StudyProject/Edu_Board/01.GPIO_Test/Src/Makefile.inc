###########################################################
# GCC template makefile
###########################################################

GPIO_TEST_SOURCES = 
GPIO_TEST_SOURCES += main.c
GPIO_TEST_SOURCES += gpio.c
GPIO_TEST_SOURCES += stm32f4xx_hal_msp.c
GPIO_TEST_SOURCES += stm32f4xx_it.c
GPIO_TEST_SOURCES += system_stm32f4xx.c

EXTRAINCDIRS += $(TOP)/StudyProject/Edu_Board/01.GPIO_Test/Inc

C_SOURCES += $(GPIO_TEST_SOURCES)