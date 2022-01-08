###########################################################
# GCC template makefile
###########################################################

LED_SOURCES = 
LED_SOURCES += main.c
LED_SOURCES += led.c

#Include Header file
EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/05.M32.Src006.LedAllOnOff.New1/Inc

#include C source file
C_SOURCES += $(LED_SOURCES)