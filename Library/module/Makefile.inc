###########################################################
# GCC template makefile
###########################################################

ifeq ($(CONFIG_ESP8266), y)

    SUB_ARCH :=
    SUB_ARCH += esp8266/Src

    SUB_ARCH := $(addprefix $(TOP)/Library/module/, $(SUB_ARCH))

    vpath %.s $(SUB_ARCH)
    vpath %.c $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

endif