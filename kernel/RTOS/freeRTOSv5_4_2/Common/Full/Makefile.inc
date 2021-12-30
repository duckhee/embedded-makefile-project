###########################################################
# GCC template makefile
###########################################################


FREE_RTOS_FULL_SOURCES = 
FREE_RTOS_FULL_SOURCES += BlockQ.c
FREE_RTOS_FULL_SOURCES += comtest.c
FREE_RTOS_FULL_SOURCES += death.c
FREE_RTOS_FULL_SOURCES += dynamic.c
FREE_RTOS_FULL_SOURCES += events.c
FREE_RTOS_FULL_SOURCES += flash.c
FREE_RTOS_FULL_SOURCES += flop.c
FREE_RTOS_FULL_SOURCES += integer.c
FREE_RTOS_FULL_SOURCES += PollQ.c
FREE_RTOS_FULL_SOURCES += print.c
FREE_RTOS_FULL_SOURCES += semtest.c


C_SOURCES += $(FREE_RTOS_FULL_SOURCES)