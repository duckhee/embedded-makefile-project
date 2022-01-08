###########################################################
# GCC template makefile
###########################################################

CMSIS_CLOCK_SOURCES = 
CMSIS_CLOCK_SOURCES += debug.c
CMSIS_CLOCK_SOURCES += hw_config.c
CMSIS_CLOCK_SOURCES += key.c
CMSIS_CLOCK_SOURCES += led.c
CMSIS_CLOCK_SOURCES += main.c
CMSIS_CLOCK_SOURCES += syscalls.c

EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-Z1/03.Z1.Src003.ClockControl/Inc

C_SOURCES += $(CMSIS_CLOCK_SOURCES)