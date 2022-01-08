###########################################################
# GCC template makefile
###########################################################

ONE_BYTE_TX_RX_SOURCES = 
ONE_BYTE_TX_RX_SOURCES += cc2520_mango_porting.c
ONE_BYTE_TX_RX_SOURCES += debug.c
ONE_BYTE_TX_RX_SOURCES += hw_config.c
ONE_BYTE_TX_RX_SOURCES += key.c
ONE_BYTE_TX_RX_SOURCES += led.c
ONE_BYTE_TX_RX_SOURCES += main.c
ONE_BYTE_TX_RX_SOURCES += stm32f10x_it.c
ONE_BYTE_TX_RX_SOURCES += syscalls.c
ONE_BYTE_TX_RX_SOURCES += zigbee_test.c

EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-Z1/08.Z1.Src008.MultiPacketTransmit/Inc

C_SOURCES += $(ONE_BYTE_TX_RX_SOURCES)