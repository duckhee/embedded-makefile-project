###########################################################
# GCC template makefile
###########################################################

BIT_BAND_SOURCES = 
BIT_BAND_SOURCES += cc2520_mango_porting.c
BIT_BAND_SOURCES += debug.c
BIT_BAND_SOURCES += hw_config.c
BIT_BAND_SOURCES += key.c
BIT_BAND_SOURCES += led.c
BIT_BAND_SOURCES += main.c
BIT_BAND_SOURCES += seven_segment.c
BIT_BAND_SOURCES += stm32f10x_it.c
BIT_BAND_SOURCES += syscalls.c
BIT_BAND_SOURCES += zigbee_test.c

EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory3.0/02.Bit_Band/Inc

C_SOURCES += $(BIT_BAND_SOURCES)