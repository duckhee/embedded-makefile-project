###########################################################
# GCC template makefile
###########################################################


CMSIS_SAMPLE_SOURCES = 
CMSIS_SAMPLE_SOURCES += main.c
CMSIS_SAMPLE_SOURCES += hw_config.c
CMSIS_SAMPLE_SOURCES += syscalls.c

EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-Z1/01.Z1.Src001.HelloWorld/Inc


C_SOURCES += $(CMSIS_SAMPLE_SOURCES)