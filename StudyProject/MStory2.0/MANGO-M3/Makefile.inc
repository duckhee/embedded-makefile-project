###########################################################
# GCC template makefile
###########################################################


ifeq ($(CONFIG_MSTORY_V2_0_SRC_LED_1), y)

    SUB_ARCH := 
    SUB_ARCH += 01.M32.Src001.LedOn/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_MSTORY_V2_0_SRC_LED_2), y)

    SUB_ARCH := 
    SUB_ARCH += 02.M32.Src001.LedOn.2009.1022.1419/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))


else ifeq ($(CONFIG_MSTORY_V2_0_SRC_LED_3), y)

    SUB_ARCH :=
    SUB_ARCH += 03.M32.Src003.LedOff/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_MSTORY_V2_0_SRC_LED_4), y)

    SUB_ARCH :=
    SUB_ARCH += 04.M32.Src005.LedAllOnOff/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_MSTORY_V2_0_SRC_LED_5), y)

    SUB_ARCH :=
    SUB_ARCH += 05.M32.Src006.LedAllOnOff.New1/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_MSTORY_V2_0_SRC_LED_6), y)
    SUB_ARCH :=
    SUB_ARCH += 06.M32.Src007.LedAllOnOff.New2/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_MSTORY_V2_0_SRC_KEY_PRESS), y)

    SUB_ARCH :=
    SUB_ARCH += 07.M32.Src008.KeyPress/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_MSTORY_V2_0_SRC_HELLO_WORLD), y)
    SUB_ARCH :=
    SUB_ARCH += 08.M32.Src009.HelloWorld1/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_MSTORY_V2_0_SRC_HELLO_WORLD_TWO), y)
    SUB_ARCH :=
    SUB_ARCH += 09.M32.Src010.HelloWorld2_printf/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_MSTORY_V2_0_SRC_GETCHAR), y)

    SUB_ARCH :=
    SUB_ARCH += 10.M32.Src011.getchar/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_MSTORY_V2_0_SRC_SEVEN_SEGMENT), y)

    SUB_ARCH :=
    SUB_ARCH += 11.M32.Src012.7_Segment/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_MSTORY_V2_0_SRC_CLOCK_SYSTEM), y)
    SUB_ARCH :=
    SUB_ARCH += 12.M32.Src013.ClockControl/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_MSTORY_V2_0_SRC_CLOCK_SYSTEM2), y)
    SUB_ARCH := 
    SUB_ARCH += 13.M32.Src014.ClockControl2/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_MSTORY_V2_0_SRC_SYSCLOCK), y)

    SUB_ARCH := 
    SUB_ARCH += 14.M32.Src015.SysTick/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_MSTORY_V2_0_SRC_EXTI), y)

    SUB_ARCH :=
    SUB_ARCH += 15.M32.Src016.KeyInterrupt/Src
    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/MANGO-M3/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else

endif

