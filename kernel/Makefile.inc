###########################################################
# GCC template makefile
###########################################################

#Kernel Select

ifeq ($(CONFIG_FREE_RTOS), y)

#FreeRTOS Version Folder
SUB_ARCH := 
SUB_ARCH += RTOS

SUB_ARCH := $(addprefix $(TOP)/kernel/, $(SUB_ARCH))

vpath %.c $(SUB_ARCH)
vpath %.s $(SUB_ARCH)

#Select Config FreeRTOS
sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

endif