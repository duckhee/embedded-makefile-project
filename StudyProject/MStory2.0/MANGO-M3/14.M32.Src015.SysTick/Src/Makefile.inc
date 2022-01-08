###########################################################
# GCC template makefile
###########################################################

SYSCLK_SOURCES = 
SYSCLK_SOURCES += hw_config.c
SYSCLK_SOURCES += key.c
SYSCLK_SOURCES += led.c
SYSCLK_SOURCES += main.c
SYSCLK_SOURCES += seven_segment.c
SYSCLK_SOURCES += stm.c
SYSCLK_SOURCES += syscalls.c

EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/14.M32.Src015.SysTick/Inc

C_SOURCES += $(SYSCLK_SOURCES)
