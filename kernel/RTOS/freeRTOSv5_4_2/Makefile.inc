###########################################################
# GCC template makefile
###########################################################

#FreeRTOS v5_4_2 Version Folder Include

SUB_ARCH := 
SUB_ARCH += \
Common/Minimal \
Inc \
MemMang \
Common/portable/GCC/ARM_CM3 \
Src 

SUB_ARCH :=$(addprefix $(TOP)/kernel/RTOS/freeRTOSv5_4_2/, $(SUB_ARCH))

vpath %.c $(SUB_ARCH)
vpath %.s $(SUB_ARCH)

#include source Makefile
sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

EXTRAINCDIRS += $(TOP)/kernel/RTOS/freeRTOSv5_4_2/Common/portable/GCC/ARM_CM3

EXTRAINCDIRS += $(TOP)/kernel/RTOS/freeRTOSv5_4_2/Inc
EXTRAINCDIRS += $(TOP)/kernel/RTOS/freeRTOSv5_4_2/Common/include


#$(TOP)/kernel/freeRTOSv5_4_2/Common/portable/GCC/ARM_CM3 \
#$(TOP)/kernel/freeRTOSv5_4_2/Inc \
#$(TOP)/kernel/freeRTOSv5_4_2/Common/Minimal \
#$(TOP)/kernel/freeRTOSv5_4_2/Common/include \