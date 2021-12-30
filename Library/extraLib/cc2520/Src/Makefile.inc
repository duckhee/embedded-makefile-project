###########################################################
# GCC template makefile
###########################################################

CC2520_SOURCES = 
CC2520_SOURCES += basic_rf.c
CC2520_SOURCES += basic_rf_security.c
CC2520_SOURCES += hal_cc2520.c
CC2520_SOURCES += hal_int.c
CC2520_SOURCES += hal_rf.c
CC2520_SOURCES += hal_rf_security.c
CC2520_SOURCES += util.c


EXTRAINCDIRS += $(TOP)/Library/extraLib/cc2520/Inc

C_SOURCES += $(CC2520_SOURCES)

