###########################################################
# GCC template makefile
###########################################################

KEY_PRESS_SOURCES = 
KEY_PRESS_SOURCES += key.c
KEY_PRESS_SOURCES += led.c
KEY_PRESS_SOURCES += main.c



EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/07.M32.Src008.KeyPress/Inc

C_SOURCES += $(KEY_PRESS_SOURCES)