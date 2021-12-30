###########################################################
# GCC template makefile
###########################################################

FREERTOS_PORTABLE_SOURCES = 
FREERTOS_PORTABLE_SOURCES += port.c
FREERTOS_PORTABLE_SOURCES += heap_1.c

C_SOURCES += $(FREERTOS_PORTABLE_SOURCES)