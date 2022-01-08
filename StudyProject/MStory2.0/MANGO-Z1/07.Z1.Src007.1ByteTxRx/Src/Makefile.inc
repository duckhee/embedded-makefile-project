###########################################################
# GCC template makefile
###########################################################

ZIGBEE_TEST_SOURCES = 
ZIGBEE_TEST_SOURCES += cc2520_mango_porting.c
ZIGBEE_TEST_SOURCES += debug.c
ZIGBEE_TEST_SOURCES += hw_config.c
ZIGBEE_TEST_SOURCES += key.c
ZIGBEE_TEST_SOURCES += led.c
ZIGBEE_TEST_SOURCES += main.c
ZIGBEE_TEST_SOURCES += stm32f10x_it.c
ZIGBEE_TEST_SOURCES += syscalls.c
ZIGBEE_TEST_SOURCES += zigbee_test.c

EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-Z1/07.Z1.Src007.1ByteTxRx/Inc

C_SOURCES += $(ZIGBEE_TEST_SOURCES)
