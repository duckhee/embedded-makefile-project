###########################################################
# GCC template makefile
###########################################################

GET_CHAR_SOURCES = 
GET_CHAR_SOURCES += key.c
GET_CHAR_SOURCES += led.c
GET_CHAR_SOURCES += syscalls.c
GET_CHAR_SOURCES += main.c

EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/10.M32.Src011.getchar/Inc


C_SOURCES += $(GET_CHAR_SOURCES)