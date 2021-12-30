###########################################################
# GCC template makefile
###########################################################

USB_FS_DEVICE_SOURCES = 
USB_FS_DEVICE_SOURCES += usb_core.c
USB_FS_DEVICE_SOURCES += usb_init.c
USB_FS_DEVICE_SOURCES += usb_int.c
USB_FS_DEVICE_SOURCES += usb_mem.c
USB_FS_DEVICE_SOURCES += usb_regs.c
USB_FS_DEVICE_SOURCES += usb_sil.c

EXTRAINCDIRS += $(TOP)/Library/extraLib/STM32_USB-FS-Device_Driver/Inc

C_SOURCES += $(USB_FS_DEVICE_SOURCES)