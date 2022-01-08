###########################################################
# GCC template makefile
###########################################################

BASE_PROGRAM_DFU_SOURCES = 
BASE_PROGRAM_DFU_SOURCES += cc2520_mango_porting.c
BASE_PROGRAM_DFU_SOURCES += debug.c
BASE_PROGRAM_DFU_SOURCES += hw_config.c
BASE_PROGRAM_DFU_SOURCES += key.c
BASE_PROGRAM_DFU_SOURCES += led.c
BASE_PROGRAM_DFU_SOURCES += main.c
BASE_PROGRAM_DFU_SOURCES += seven_segment.c
BASE_PROGRAM_DFU_SOURCES += stm32f10x_it.c
BASE_PROGRAM_DFU_SOURCES += syscalls.c
BASE_PROGRAM_DFU_SOURCES += zigbee_test.c

EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory3.0/04.BaseProgram_forDFU/Inc

C_SOURCES += $(BASE_PROGRAM_DFU_SOURCES)