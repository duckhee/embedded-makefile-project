###########################################################
# GCC template makefile
###########################################################


HELLO_SOURCES = 
HELLO_SOURCES += key.c
HELLO_SOURCES += led.c
HELLO_SOURCES += syscalls.c
HELLO_SOURCES += main.c


EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/09.M32.Src010.HelloWorld2_printf/Inc



C_SOURCES += $(HELLO_SOURCES)