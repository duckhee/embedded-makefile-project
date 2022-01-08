###########################################################
# GCC template makefile
###########################################################


HELLO_WORD_SOURCES = 
HELLO_WORD_SOURCES += main.c
HELLO_WORD_SOURCES += key.c
HELLO_WORD_SOURCES += led.c

EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory2.0/08.M32.Src009.HelloWorld1/Inc

C_SOURCES += $(HELLO_WORD_SOURCES)