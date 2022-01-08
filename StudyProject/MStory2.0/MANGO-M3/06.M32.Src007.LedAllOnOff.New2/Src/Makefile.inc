###########################################################
# GCC template makefile
###########################################################

LED_ON_OFF_SOURCES = 
LED_ON_OFF_SOURCES += led.c
LED_ON_OFF_SOURCES += main.c

#Include Header file
EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/06.M32.Src007.LedAllOnOff.New2/Inc

#include C source file
C_SOURCES += $(LED_ON_OFF_SOURCES)