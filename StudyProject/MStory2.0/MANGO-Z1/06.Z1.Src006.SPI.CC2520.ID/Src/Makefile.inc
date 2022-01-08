###########################################################
# GCC template makefile
###########################################################

CMSIS_SPI_TEST_SOURCES = 
CMSIS_SPI_TEST_SOURCES += cc2520_mango_porting.c
CMSIS_SPI_TEST_SOURCES += key.c
CMSIS_SPI_TEST_SOURCES += led.c
CMSIS_SPI_TEST_SOURCES += zigbee_test.c
CMSIS_SPI_TEST_SOURCES += stm32f10x_it.c
CMSIS_SPI_TEST_SOURCES += hw_config.c
CMSIS_SPI_TEST_SOURCES += debug.c
CMSIS_SPI_TEST_SOURCES += syscalls.c
CMSIS_SPI_TEST_SOURCES += main.c

EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-Z1/06.Z1.Src006.SPI.CC2520.ID/Inc


C_SOURCES += $(CMSIS_SPI_TEST_SOURCES)