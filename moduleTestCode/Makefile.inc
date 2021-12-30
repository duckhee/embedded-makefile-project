###########################################################
# GCC template makefile
###########################################################

ifeq ($(CONFIG_ESP_12E), y)

    SUB_ARCH := 
    SUB_ARCH += ESP8266_12E/Src

    SUB_ARCH := $(addprefix $(TOP)/moduleTestCode/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else

endif