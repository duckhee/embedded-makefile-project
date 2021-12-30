###########################################################
# GCC template makefile
###########################################################


SUB_ARCH :=
SUB_ARCH += Edu_Board
SUB_ARCH += Mstory2.0
SUB_ARCH += Mstory3.0
SUB_ARCH += moduleTest

SUB_ARCH := $(addprefix $(TOP)/StudyProject/, $(SUB_ARCH))

vpath %.c $(SUB_ARCH)
vpath %.s $(SUB_ARCH)

sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

