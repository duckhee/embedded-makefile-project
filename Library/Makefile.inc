###########################################################
# GCC template makefile
###########################################################


SUB_ARCH :=
SUB_ARCH += extraLib
SUB_ARCH += middleWare
SUB_ARCH += module

SUB_ARCH := $(addprefix $(TOP)/Library/, $(SUB_ARCH))

vpath %.c $(SUB_ARCH)
vpath %.s $(SUB_ARCH)

sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))