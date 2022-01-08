###########################################################
# GCC template makefile
###########################################################

ifeq ($(CONFIG_CMSIS_SAMPLE_HELLO_WORLD_Z1), y)

    SUB_ARCH := 
    SUB_ARCH += 01.Z1.Src001.HelloWorld/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-Z1/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_CMSIS_LED_KEY_CONTROL), y)

    SUB_ARCH :=
    SUB_ARCH += 02.Z1.Src002.LedKeyControl/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-Z1/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_CMSIS_CLOCK_CONTROL), y)

    SUB_ARCH :=
    SUB_ARCH += 03.Z1.Src003.ClockControl/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-Z1/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_CMSIS_KEY_INTERRUPT), y)
    SUB_ARCH := 
    SUB_ARCH += 04.Z1.Src004.KeyInterrupt/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-Z1/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_CMSIS_IAP_BOOTLOADER), y)
    SUB_ARCH :=
    SUB_ARCH += 05.Z1.Src005.AN2557.IAP.BootLoader/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-Z1/, $(SUB_ARCH))

    vpath %.s $(SUB_ARCH)
    vpath %.c $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_CMSIS_SPI_TEST), y)
    SUB_ARCH := 
    SUB_ARCH += 06.Z1.Src006.SPI.CC2520.ID/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-Z1/, $(SUB_ARCH))

    vpath %.s $(SUB_ARCH)
    vpath %.c $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))
    
else ifeq ($(CONFIG_CMSIS_ZIGBEE_RX_TX_ONE_TEST), y)
    SUB_ARCH := 
    SUB_ARCH += 07.Z1.Src007.1ByteTxRx/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-Z1/, $(SUB_ARCH))

    vpath %.s $(SUB_ARCH)
    vpath %.c $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_CMSIS_ONE_BYTE_RX_TX_TEST), y)
    SUB_ARCH :=
    SUB_ARCH += 08.Z1.Src008.MultiPacketTransmit/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-Z1/, $(SUB_ARCH))

    vpath %.s $(SUB_ARCH)
    vpath %.c $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_CMSIS_USB_HID_TEST), y)
    SUB_ARCH :=
    SUB_ARCH += 09.Z1.Src009.USB.HID/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-Z1/, $(SUB_ARCH))

    vpath %.s $(SUB_ARCH)
    vpath %.c $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

endif