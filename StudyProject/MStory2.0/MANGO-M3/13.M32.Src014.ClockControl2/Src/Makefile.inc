###########################################################
# GCC template makefile
###########################################################


CLOCK_SYS_SOURCES = 
CLOCK_SYS_SOURCES += hw_config.c
CLOCK_SYS_SOURCES += key.c
CLOCK_SYS_SOURCES += led.c
CLOCK_SYS_SOURCES += seven_segment.c
CLOCK_SYS_SOURCES += main.c
CLOCK_SYS_SOURCES += stm.c
CLOCK_SYS_SOURCES += syscalls.c

EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/13.M32.Src014.ClockControl2/Inc

C_SOURCES += $(CLOCK_SYS_SOURCES)