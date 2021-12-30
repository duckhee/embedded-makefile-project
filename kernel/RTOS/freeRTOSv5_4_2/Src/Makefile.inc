###########################################################
# GCC template makefile
###########################################################


FREERTOS_SOURCES = 
FREERTOS_SOURCES += list.c
FREERTOS_SOURCES += croutine.c
FREERTOS_SOURCES += queue.c
FREERTOS_SOURCES += tasks.c

C_SOURCES += $(FREERTOS_SOURCES)