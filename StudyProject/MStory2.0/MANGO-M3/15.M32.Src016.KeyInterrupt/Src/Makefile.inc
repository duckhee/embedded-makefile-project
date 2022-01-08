###########################################################
# GCC template makefile
###########################################################

EXTI_SOURCES = 
EXTI_SOURCES += hw_config.c
EXTI_SOURCES += key.c
EXTI_SOURCES += led.c
EXTI_SOURCES += main.c
EXTI_SOURCES += seven_segment.c
EXTI_SOURCES += stm.c
EXTI_SOURCES += syscalls.c


EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/15.M32.Src016.KeyInterrupt/Inc

C_SOURCES += $(EXTI_SOURCES)