###########################################################
# GCC template makefile
###########################################################


CMSIS_LED_KEY_CONTROL_SOURCES = 
CMSIS_LED_KEY_CONTROL_SOURCES += debug.c
CMSIS_LED_KEY_CONTROL_SOURCES += hw_config.c
CMSIS_LED_KEY_CONTROL_SOURCES += key.c
CMSIS_LED_KEY_CONTROL_SOURCES += led.c
CMSIS_LED_KEY_CONTROL_SOURCES += main.c
CMSIS_LED_KEY_CONTROL_SOURCES += syscalls.c

EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-Z1/02.Z1.Src002.LedKeyControl/Inc

C_SOURCES += $(CMSIS_LED_KEY_CONTROL_SOURCES)