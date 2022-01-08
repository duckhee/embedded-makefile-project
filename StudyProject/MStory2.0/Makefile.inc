###########################################################
# GCC template makefile
###########################################################

SUB_ARCH := 
SUB_ARCH += MANGO-M3
SUB_ARCH += MANGO-Z1

SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/, $(SUB_ARCH))

vpath %.c $(SUB_ARCH)
vpath %.s $(SUB_ARCH)

sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))
