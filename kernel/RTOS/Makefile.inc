###########################################################
# GCC template makefile
###########################################################


SUB_ARCH := 

#use FreeRTOS Kernel Veriosn
ifeq ($(CONFIG_FreeRTOS_V5), y)

SUB_ARCH += freeRTOSv5_4_2

SUB_ARCH  := $(addprefix $(TOP)/kernel/RTOS/, $(SUB_ARCH))

vpath %.c $(SUB_ARCH)
vpath %.s $(SUB_ARCH)

#freeRTOS Version 5_4_2 Include
sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_FreeRTOS_V10), y)

SUB_ARCH += freeRTOSv10_2

SUB_ARCH  := $(addprefix $(TOP)/kernel/RTOS/, $(SUB_ARCH))

vpath %.c $(SUB_ARCH)
vpath %.s $(SUB_ARCH)

#freeRTOS Version 10_2 Include
sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

endif
