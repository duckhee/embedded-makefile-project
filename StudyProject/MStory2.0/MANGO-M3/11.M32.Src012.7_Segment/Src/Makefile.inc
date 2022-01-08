###########################################################
# GCC template makefile
###########################################################

SEVEN_SEGMENT_SOURCES = 
SEVEN_SEGMENT_SOURCES += key.c
SEVEN_SEGMENT_SOURCES += led.c
SEVEN_SEGMENT_SOURCES += main.c
SEVEN_SEGMENT_SOURCES += segment.c
SEVEN_SEGMENT_SOURCES += syscalls.c


EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/11.M32.Src012.7_Segment/Inc

C_SOURCES += $(SEVEN_SEGMENT_SOURCES)