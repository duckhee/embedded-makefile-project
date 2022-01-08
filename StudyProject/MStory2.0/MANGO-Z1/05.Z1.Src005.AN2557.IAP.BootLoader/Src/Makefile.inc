###########################################################
# GCC template makefile
###########################################################

IAR_BOOT_LOADER_SOURCES = 
IAR_BOOT_LOADER_SOURCES += common.c
IAR_BOOT_LOADER_SOURCES += download.c
IAR_BOOT_LOADER_SOURCES += stm32_eval.c
IAR_BOOT_LOADER_SOURCES += stm32f10x_it.c
IAR_BOOT_LOADER_SOURCES += ymodem.c
IAR_BOOT_LOADER_SOURCES += main.c
IAR_BOOT_LOADER_SOURCES += syscalls.c

EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-Z1/05.Z1.Src005.AN2557.IAP.BootLoader/Inc

C_SOURCES += $(IAR_BOOT_LOADER_SOURCES)