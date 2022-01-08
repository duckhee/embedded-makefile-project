###########################################################
# GCC template makefile
###########################################################

CMSIS_KEY_INTERRUPT_SOURCES = 
CMSIS_KEY_INTERRUPT_SOURCES += debug.c
CMSIS_KEY_INTERRUPT_SOURCES += hw_config.c
CMSIS_KEY_INTERRUPT_SOURCES += stm32f10x_it.c
CMSIS_KEY_INTERRUPT_SOURCES += led.c
CMSIS_KEY_INTERRUPT_SOURCES += key.c
CMSIS_KEY_INTERRUPT_SOURCES += syscalls.c
CMSIS_KEY_INTERRUPT_SOURCES += main.c

EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-Z1/04.Z1.Src004.KeyInterrupt/Inc

C_SOURCES += $(CMSIS_KEY_INTERRUPT_SOURCES)