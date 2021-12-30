###########################################################
# GCC template makefile
###########################################################


FREERTOS_CORE_SOURCES = 
FREERTOS_CORE_SOURCES += croutine.c
FREERTOS_CORE_SOURCES += event_groups.c
FREERTOS_CORE_SOURCES += list.c
FREERTOS_CORE_SOURCES += queue.c
FREERTOS_CORE_SOURCES += stream_buffer.c
FREERTOS_CORE_SOURCES += tasks.c
FREERTOS_CORE_SOURCES += timers.c

C_SOURCES += $(FREERTOS_CORE_SOURCES)