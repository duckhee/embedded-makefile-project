###########################################################
# GCC template makefile
###########################################################

MANGO_Z1_USB_HD_SOURCES = 
MANGO_Z1_USB_HD_SOURCES += cc2520_mango_porting.c
MANGO_Z1_USB_HD_SOURCES += syscalls.c
MANGO_Z1_USB_HD_SOURCES += key.c
MANGO_Z1_USB_HD_SOURCES += led.c
MANGO_Z1_USB_HD_SOURCES += hw_config.c
MANGO_Z1_USB_HD_SOURCES += main.c
MANGO_Z1_USB_HD_SOURCES += stm32f10x_it.c
MANGO_Z1_USB_HD_SOURCES += debug.c
MANGO_Z1_USB_HD_SOURCES += zigbee_test.c




EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-Z1/09.Z1.Src009.USB.HID/Inc


C_SOURCES += $(MANGO_Z1_USB_HD_SOURCES)