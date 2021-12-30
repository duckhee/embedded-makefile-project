###########################################################
# GCC template makefile
###########################################################

ifeq ($(CONFIG_LWIP), y)

    SUB_ARCH :=
    SUB_ARCH += lwip-2.1.2
    SUB_ARCH := $(addprefix $(TOP)/Library/middleWare/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

endif