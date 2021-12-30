###########################################################
# GCC template makefile
###########################################################


ifeq ($(CONFIG_STANDARD_DRIVER), y)

    # if board mango-m3 board Select Add SUB_DIRS
    ifeq ($(CONFIG_MANGO_M3), y)

        SUB_ARCH := 
        #Standard Driver
        SUB_ARCH += STM32F10x_StdPeriph_Driver/Src

        SUB_ARCH := $(addprefix $(TOP)/driver/, $(SUB_ARCH))

        vpath %.c $(SUB_ARCH)
        vpath %.s $(SUB_ARCH)

    else ifeq ($(CONFIG_MANGO_Z1), y)

        SUB_ARCH := 
        #Standard Driver
        SUB_ARCH += STM32F10x_StdPeriph_Driver/Src

        SUB_ARCH := $(addprefix $(TOP)/driver/, $(SUB_ARCH))

        vpath %.c $(SUB_ARCH)
        vpath %.s $(SUB_ARCH)

    else ifeq ($(CONFIG_MANGO_M32F2) y)

    else ifeq ($(CONFIG_MANGO_M4), y)

        SUB_ARCH := 
        SUB_ARCH += STM32F4xx_StdPeriph_Driver/Src

        SUB_ARCH := $(addprefix $(TOP)/driver/, $(SUB_ARCH))

        vpath %.c $(SUB_ARCH)
        vpath %.s $(SUB_ARCH)

    else ifeq ($(CONFIG_EDU_BOARD), y)

        SUB_ARCH := 
        SUB_ARCH += STM32F4xx_StdPeriph_Driver/Src

        SUB_ARCH := $(addprefix $(TOP)/driver/, $(SUB_ARCH))

        vpath %.c $(SUB_ARCH)
        vpath %.s $(SUB_ARCH)

    else ifeq ($(CONFIG_ARCH_M3), y)

        SUB_ARCH := 
        #Standard Driver
        SUB_ARCH += STM32F10x_StdPeriph_Driver/Src

        SUB_ARCH := $(addprefix $(TOP)/driver/, $(SUB_ARCH))

        vpath %.c $(SUB_ARCH)
        vpath %.s $(SUB_ARCH)

    else ifeq ($(CONFIG_ARCH_M4), y)

        SUB_ARCH := 
        SUB_ARCH += STM32F4xx_StdPeriph_Driver/Src

        SUB_ARCH := $(addprefix $(TOP)/driver/, $(SUB_ARCH))

        vpath %.c $(SUB_ARCH)
        vpath %.s $(SUB_ARCH)

    endif

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

# HAL Driver Setting Flag

else ifeq ($(CONFIG_HAL_DRIVER), y)

    # if board mango-m3 board Select Add SUB_DIRS
    ifeq ($(CONFIG_MANGO_M3), y)

        SUB_ARCH := 
        #HAL Driver
        SUB_ARCH += STM32F1xx_HAL_Driver/Src

        SUB_ARCH := $(addprefix $(TOP)/driver/, $(SUB_ARCH))

        vpath %.c $(SUB_ARCH)
        vpath %.s $(SUB_ARCH)


    else ifeq ($(CONFIG_MANGO_Z1), y)

        SUB_ARCH := 
        #HAL Driver
        SUB_ARCH += STM32F1xx_HAL_Driver/Src

        SUB_ARCH := $(addprefix $(TOP)/driver/, $(SUB_ARCH))

        vpath %.c $(SUB_ARCH)
        vpath %.s $(SUB_ARCH)


    else ifeq ($(CONFIG_MANGO_M32F2), y)

    else ifeq ($(CONFIG_MANGO_M4), y)

        SUB_ARCH := 
        SUB_ARCH += STM32F4xx_HAL_Driver/Src

        SUB_ARCH := $(addprefix $(TOP)/driver/, $(SUB_ARCH))

        vpath %.c $(SUB_ARCH)
        vpath %.s $(SUB_ARCH)


    else ifeq ($(CONFIG_EDU_BOARD), y)

        SUB_ARCH := 
        SUB_ARCH += STM32F4xx_HAL_Driver/Src

        SUB_ARCH := $(addprefix $(TOP)/driver/, $(SUB_ARCH))

        vpath %.c $(SUB_ARCH)
        vpath %.s $(SUB_ARCH)

    else ifeq ($(CONFIG_ARCH_M3), y)

        SUB_ARCH := 
        #HAL Driver
        SUB_ARCH += STM32F1xx_HAL_Driver/Src

        SUB_ARCH := $(addprefix $(TOP)/driver/, $(SUB_ARCH))

        vpath %.c $(SUB_ARCH)
        vpath %.s $(SUB_ARCH)

    else ifeq ($(CONFIG_ARCH_M4), y)

        SUB_ARCH := 
        SUB_ARCH += STM32F4xx_HAL_Driver/Src

        SUB_ARCH := $(addprefix $(TOP)/driver/, $(SUB_ARCH))

        vpath %.c $(SUB_ARCH)
        vpath %.s $(SUB_ARCH)

    endif

    # Include Folder
    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

endif

