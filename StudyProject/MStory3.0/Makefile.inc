###########################################################
# GCC template makefile
###########################################################


ifeq ($(CONFIG_MSTORY_V3_0_SRC_LIB_DEBUG), y)

    SUB_ARCH := 
    SUB_ARCH += 01.Lib_DEBUG/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory3.0/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_MSTORY_V3_0_SRC_BIT_BAND), y)
    
    SUB_ARCH :=
    SUB_ARCH += 02.Bit_Band/Src
   
    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory3.0/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_MSTORY_V3_0_SRC_MODE_PRIVILEGE), y)

    SUB_ARCH :=
    SUB_ARCH += 03.Mode_Privilege/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory3.0/, $(SUB_ARCH))

    vpath %.s $(SUB_ARCH)
    vpath %.c $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_MSTORY_V3_0_SRC_BASEPROGRAM_FORDFU), y)

    SUB_ARCH :=
    SUB_ARCH += 04.BaseProgram_forDFU/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory3.0/, $(SUB_ARCH))

    vpath %.s $(SUB_ARCH)
    vpath %.c $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else 



endif