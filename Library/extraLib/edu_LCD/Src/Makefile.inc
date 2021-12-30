###########################################################
# GCC template makefile
###########################################################


EDU_LCD_SOURCES = 
EDU_LCD_SOURCES += CLCD.c

EXTRAINCDIRS += $(TOP)/Library/extraLib/edu_LCD/Inc

C_SOURCES += $(EDU_LCD_SOURCES)