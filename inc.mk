###########################################################
# GCC template makefile
###########################################################

MODEL = 
SUBMODEL = Study-Project

# prefix GCC (cross compiler)
PREFIX = arm-none-eabi-

# REMOVE Command
REMOVE_CMD = rm 
REMOVE = $(REMOVE_CMD) -rf
# shell script using bash
SHELL = sh

# Cross Compiler setting
CC = $(PREFIX)gcc
CPP = $(PREFIX)g++
AR = $(PREFIX)ar
LD = $(PREFIX)ld
OBJCOPY = $(PREFIX)objcopy
OBJDUMP = $(PREFIX)objdump
SIZE = $(PREFIX)size
NM = $(PREFIX)nm

# Kconfig file add
-include .config

#####################################################################
# CFLAGS
#####################################################################

# default cpu arch is m3
DEFAULT_CPU = -mcpu=cortex-m3
# architecture M3
M3_CPU = -mcpu=cortex-m3
# architecture M4
M4_CPU = -mcpu=cortex-m4

# Setting Default CPU
CPU := $(DEFAULT_CPU)

# Floating point unit Setting
FPU := 

# Floating ABI Setting
FLOAT-ABI := 

# cpu architecture Setting using flag

# if board mango-m3 board Select
ifeq ($(CONFIG_MANGO_M3), y)

CPU = $(M3_CPU)

FPU = 
FLOAT-ABI = 
C_DEFS = \
-D STM32F103xB \
-D BOARD_DEF_MANGO_M32

else ifeq ($(CONFIG_MANGO_Z1), y)

CPU = $(M3_CPU)

FPU = 
FLOAT-ABI = 
C_DEFS = \
-D STM32F103xB \
-D BOARD_DEF_MANGO_Z1

else ifeq ($(CONFIG_MANGO_M32F2), y)

CPU = $(M3_CPU)

FPU = 
FLOAT-ABI = 
C_DEFS = \
-D STM32F103xB \


else ifeq ($(CONFIG_MANGO_M4), y)

CPU = $(M4_CPU)
# fpu
FPU = -mfpu=fpv4-sp-d16
# float-abi
FLOAT-ABI = -mfloat-abi=hard
C_DEFS = \
-D STM32F407xx \
-D STM32F40_41xxx

else ifeq ($(CONFIG_EDU_BOARD), y)

CPU = $(M4_CPU)
# fpu
FPU = -mfpu=fpv4-sp-d16
# float-abi
FLOAT-ABI = -mfloat-abi=hard
C_DEFS = \
-D STM32F407xx

else ifeq ($(CONFIG_ARCH_M3), y)

CPU = $(M3_CPU)

FPU = 
FLOAT-ABI = 

else ifeq ($(CONFIG_ARCH_M4), y)

CPU = $(M4_CPU)
# fpu
FPU = -mfpu=fpv4-sp-d16
# float-abi
FLOAT-ABI = -mfloat-abi=hard

endif

# CPU Flag Setting
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)


## Output format. (can be ihex or binary)
## (binary i.e. for openocd and SAM-BA, hex i.e. for lpc21isp and uVision)
#OUTPUT Format  setting

# HEX FOMART
# FORMAT = ihex
# BINARY FORMAT
FORMAT = binary

# Optimization level, can be [0, 1, 2, 3, s].
# 0 = turn off optimization. s = optimize for size.
# (Note: 3 is not always the best optimization level. See avr-libc FAQ.)
OPT = g

# Debugging format.
# Native formats for GCC's -g are stabs [default], or dwarf-2.
#DEBUG = stabs
DEBUG = dwarf-2


#define Set up
# Place -D or -U options for C here
#CDEFS =  -D$(RUN_MODE)

#Default define flag It is use CMSIS Driver
ifeq ($(CONFIG_STANDARD_DRIVER), y)
# using driver setting
C_DEFS += \
-D USE_STDPERIPH_DRIVER 

else ifeq ($(CONFIG_HAL_DRIVER), y)
# using driver setting
C_DEFS += \
-D USE_HAL_DRIVER

endif


#Place -D or -U options for ASM here
#ADEFS = -D$(RUN_MODE)
#Assembler Define Flag 
ADEFS = 



# Compiler flags.
#  -g*:          generate debugging information
#  -O*:          optimization level
#  -f...:        tuning, see GCC manual and avr-libc documentation
#  -Wall...:     warning level
#  -Wa,...:      tell GCC to pass this to the assembler.
#    -adhlns...: create assembler listing
#

COMFLAGS = -Wall -fdata-sections -ffunction-sections

# Flags for C and C++ (arm-elf-gcc/arm-elf-g++)
CFLAGS = -g$(DEBUG)
CFLAGS += $(C_DEFS) $(C_INCLUDES)
CFLAGS += -O$(OPT)
CFLAGS += -Wcast-align -Wimplicit
CFLAGS += -Wredundant-decls -Wreturn-type -Wshadow -Wunused
CFLAGS += $(COMFLAGS)

# add prefix Header Include
CFLAGS += $(patsubst %,-I%,$(EXTRAINCDIRS))
ASFLAGS = $(COMFLAGS)

# Flags only for C
CONLYFLAGS += -Wnested-externs


# Compiler flag to set the C Standard level.
# c89   - "ANSI" C
# gnu89 - c89 plus GCC extensions
# c99   - ISO C99 standard (not yet fully implemented)
# gnu99 - c99 plus GCC extensions
CONLYFLAGS += -std=gnu99

# Waring with
CFLAGS += -Wcast-qual
CONLYFLAGS += -Wmissing-prototypes
CONLYFLAGS += -Wstrict-prototypes
CONLYFLAGS += -Wmissing-declarations
#CONLYFLAGS += -Wno-traditional

# Output directory
LIB_DIR := $(TOP)/lib.$(SUBMODEL)
OUT_DIR := $(TOP)/obj.$(SUBMODEL)
BUILD_DIR := $(TOP)/bin.$(SUBMODEL)
PRJ_LIBS := 