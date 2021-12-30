###########################################################
# GCC template makefile
###########################################################

#FreeRTOS v10_2 Version Folder Include

SUB_ARCH := 
SUB_ARCH += \
Common/Minimal \
include \
MemMang \
portable/ARM_CM3 \
Src 

SUB_ARCH :=$(addprefix $(TOP)/kernel/RTOS/freeRTOSv10_2/, $(SUB_ARCH))

vpath %.c $(SUB_ARCH)
vpath %.s $(SUB_ARCH)

#include source Makefile
sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

EXTRAINCDIRS += $(TOP)/kernel/RTOS/freeRTOSv10_2/portable/ARM_CM3
EXTRAINCDIRS += $(TOP)/kernel/RTOS/freeRTOSv10_2/include
