###########################################################
# GCC template makefile
###########################################################



LIB_DEBUG_SOURCES = 
LIB_DEBUG_SOURCES += hw_config.c
LIB_DEBUG_SOURCES += syscalls.c
LIB_DEBUG_SOURCES += main.c
LIB_DEBUG_SOURCES += debug.c
LIB_DEBUG_SOURCES += lib_dbg.c
LIB_DEBUG_SOURCES += cc2520_mango_porting.c
LIB_DEBUG_SOURCES += stm32f10x_it.c
LIB_DEBUG_SOURCES += led.c
LIB_DEBUG_SOURCES += key.c
LIB_DEBUG_SOURCES += seven_segment.c


EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory3.0/01.Lib_DEBUG/Inc

C_SOURCES += $(LIB_DEBUG_SOURCES)