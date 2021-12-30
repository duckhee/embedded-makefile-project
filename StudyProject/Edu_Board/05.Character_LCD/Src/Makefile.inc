###########################################################
# GCC template makefile
###########################################################

CHARACTER_LCD_SOURCES = 
CHARACTER_LCD_SOURCES += main.c
CHARACTER_LCD_SOURCES += gpio.c
CHARACTER_LCD_SOURCES += stm32f4xx_hal_msp.c
CHARACTER_LCD_SOURCES += stm32f4xx_it.c
CHARACTER_LCD_SOURCES += system_stm32f4xx.c
CHARACTER_LCD_SOURCES += uart.c


EXTRAINCDIRS += $(TOP)/StudyProject/Edu_Board/05.Character_LCD/Inc

C_SOURCES += $(CHARACTER_LCD_SOURCES)