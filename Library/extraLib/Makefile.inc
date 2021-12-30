###########################################################
# GCC template makefile
###########################################################


ifeq ($(CONFIG_USB_FS_DEVICE_DRIVER), y)

    SUB_ARCH :=
    SUB_ARCH += STM32_USB-FS-Device_Driver/Src

    SUB_ARCH := $(addprefix $(TOP)/Library/extraLib/ , $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath $.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_CC2520), y)

    SUB_ARCH :=
    SUB_ARCH += cc2520/Src

    SUB_ARCH := $(addprefix $(TOP)/Library/extraLib/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_EDU_CLCD), y)

    SUB_ARCH :=
    SUB_ARCH += edu_LCD/Src

    SUB_ARCH := $(addprefix $(TOP)/Library/extraLib/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

endif
