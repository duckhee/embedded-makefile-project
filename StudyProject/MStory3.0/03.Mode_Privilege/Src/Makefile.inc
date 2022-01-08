###########################################################
# GCC template makefile
###########################################################

MODE_PRIVILEGE_SOURCES = 
MODE_PRIVILEGE_SOURCES += cc2520_mango_porting.c
MODE_PRIVILEGE_SOURCES += debug.c
MODE_PRIVILEGE_SOURCES += hw_config.c
MODE_PRIVILEGE_SOURCES += key.c
MODE_PRIVILEGE_SOURCES += led.c
MODE_PRIVILEGE_SOURCES += main.c
MODE_PRIVILEGE_SOURCES += seven_segment.c
MODE_PRIVILEGE_SOURCES += stm32f10x_it.c
MODE_PRIVILEGE_SOURCES += syscalls.c
MODE_PRIVILEGE_SOURCES += zigbee_test.c

EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MStory3.0/03.Mode_Privilege/Inc

C_SOURCES += $(MODE_PRIVILEGE_SOURCES)