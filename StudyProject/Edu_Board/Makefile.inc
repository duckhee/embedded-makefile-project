###########################################################
# GCC template makefile
###########################################################


ifeq ($(CONFIG_GPIO_TEST_EDU), y)

    SUB_ARCH := 
    SUB_ARCH += 01.GPIO_Test/Src

    SUB_ARCH := $(addprefix $(TOP)/StudyProject/Edu_Board/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_UART_POLLING_EDU), y)

    SUB_ARCH :=
    SUB_ARCH += 02.UART_polling/Src

    SUB_ARCH := $(addprefix $(TOP)/StudyProject/Edu_Board/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_UART_PRINTF_EDU), y)

    SUB_ARCH :=
    SUB_ARCH += 03.UART_Printf/Src

    SUB_ARCH := $(addprefix $(TOP)/StudyProject/Edu_Board/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_UART_INTERRUPT_EDU), y)

    SUB_ARCH :=
    SUB_ARCH += 04.UART_Interrupt/Src

    SUB_ARCH := $(addprefix $(TOP)/StudyProject/Edu_Board/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.S $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc , $(SUB_ARCH))

else ifeq ($(CONFIG_LCD_PRINT_EDU), y)

    SUB_ARCH :=
    SUB_ARCH += 05.Character_LCD/Src

    SUB_ARCH := $(addprefix $(TOP)/StudyProject/Edu_Board/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

endif