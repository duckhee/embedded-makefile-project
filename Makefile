# Top Folder Setting
TOP = .

# make project Version Setting
VERSION = 2021
PATCHVERSION = 0
SUBVERSION = 
EXTRAVERSION = 
NAME = 

# Build Target Name
TARGET = buildProject

# Include inc.mk
-include $(TOP)/inc.mk

# Custom Make Project Version
CUSTOMVERSION = v$(VERSION)$(if $(PATCHVERSION),.$(PATCHVERSION)$(if $(SUBVERSION),.$(SUBVERSION))) $(EXTRAVERSION)

#Get HOST OS Make lower
HOSTOS := $(shell uname -s | tr '[:upper:]' '[:lower:]' | \
	    sed -e 's/\(cygwin\).*/cygwin/')

export HOSTOS


# BUILD arm-none-eabi-gcc

# FOLDERS  := $(shell ls -R sampleSource kernel | grep : | sed 's/://')

# Source File %.c
SRCS += $(C_SOURCES)
# Source File %.cpp
CPPSRCS += $(CPP_SOURCES)
# List Assmbler sources files here.
ASM_SOURCES = 


# Get Folder 
# SUB_DIRS  := $(shell ls -R sampleSource kernel Project | grep : | sed 's/://')
SUB_DIRS :=
SUB_DIRS += driver
SUB_DIRS += CMSIS
SUB_DIRS += Library
SUB_DIRS += kernel
SUB_DIRS += StudyProject
SUB_DIRS += moduleTestCode

# SUB_DIR addprefix Setting
SUB_DIRS := $(addprefix $(TOP)/, $(SUB_DIRS))

# Source File add compling
vpath %.c $(SUB_DIRS)
vpath %.s $(SUB_DIRS)
vpath %.cpp $(SUB_DIRS)

sinclude $(addsuffix /Makefile.inc, $(SUB_DIRS))


# LIBC_LIB = -L $(shell dirname `$(CC) $(ALL_CFLAGS) -print-file-name=libc.a`) -lc
# MATH_LIB = -L $(shell dirname `$(CC) $(ALL_CFLAGS) -print-file-name=libm.a`) -lm
# LIBGCC_LIB += -L $(shell dirname `$(CC) $(ALL_CFLAGS) -print-libgcc-file-name`) -lgcc
# CPLUSPLUS_LIB = -lstdc++

# Linker flags.
#  -Wl,...:     tell GCC to pass this to linker.
#    -Map:      create map file
#    --cref:    add cross reference to  map file
# LDFLAGS = -Map=$(TARGET).map --cref
# Linker script flash
ifeq ($(CONFIG_MANGO_M3), y)
# Flash LinkerScript setting
FLASH_LDSCRIPT = LinkerScripts/stm32f10x/STM32F103RBTx_FLASH.ld

else ifeq ($(CONFIG_MANGO_Z1), y)
# Flash LinkerScript setting
FLASH_LDSCRIPT = LinkerScripts/stm32f10x/STM32F103RBTx_FLASH.ld

else ifeq ($(CONFIG_MANGO_M4), y)
# Flash LinkerScript setting
FLASH_LDSCRIPT = LinkerScripts/stm32f407/STM32F407ZETx_FLASH.ld

else ifeq ($(CONFIG_MANGO_M32F2), y)
FLASH_LDSCRIPT =
else ifeq ($(CONFIG_EDU_BOARD), y)
# Flash LinkerScript setting
FLASH_LDSCRIPT = LinkerScripts/stm32f407/STM32F407VE_FLASH.ld

else ifeq ($(CONFIG_ARCH_M3), y)
FLASH_LDSCRIPT = LinkerScripts/stm32f10x/STM32F103RBTx_FLASH.ld

else ifeq ($(CONFIG_ARCH_M4), y)
FLASH_LDSCRIPT = LinkerScripts/stm32f407/STM32F407VE_FLASH.ld

endif

# float printf add libs nano.spec
# linker lib add float library add -spec=nano.spec -u_printf_float not use system file syscall file _write _read _getpid _close
LD_LIBS = -lc -lm -lnosys -specs=nano.specs -u _printf_float -u _scanf_float -static
# Linker script add setting
LDFLAGS = $(MCU) $(LD_LIBS) -Wl,-Map=$(OUT_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

LDFLAGS += $(patsubst %,-L%, $(EXTRA_LIBDIRS))
LDFLAGS += $(patsubst %,-L%, $(EXTRA_LIBS))
# Flash Linker Script add Setting
LDFLAGS += -T$(FLASH_LDSCRIPT)

# make Command Setting
all: projectversion gccversion build sizeinfo

# include Rule makefile
include $(TOP)/rule.mk

# Kconfig Test
# echo folder and file
file:
	@echo "Include Folder - $(SUB_DIRS)"
	@echo "Include Source File - $(SRCS)"
	@echo "Assemble Source FIle - $(ASM_SOURCES)"
	@echo "Include Header File - $(EXTRAINCDIRS)"

# Build Command Do
build: clean createdirs elf bin lss sym sizeinfo

# download Command do
download: clean createdirs elf bin lss sym sizeinfo flashLoader

flashLoader:
	./download.sh $(BUILD_DIR) $(TARGET)

# version Command Do
version:
	@echo "Make Project Version : $(CUSTOMVERSION)"

# config using ncurses
menuconfig: version
	@$(MAKE) -f scripts/Makefile $@

# All Delete
distclean:
	$(REMOVE) $(OUT_DIR)
	$(REMOVE) $(BUILD_DIR)
	$(REMOVE) $(LIB_DIR)
	$(REMOVE) build $(TOP)/include .config .config.old
	@$(MAKE) -f scripts/Makefile clean

# Help Command explain
help:
	@echo "----Sample Embedded Study Project $(CUSTOMVERSION)--- "
	@echo menuconfig - "GUI Config Sample Code, Select Board "
	@echo distclean - "All Object File, Folder Delete"
	@echo clean - "Folder Delete"
	@echo version - "Show this project Version"
	@echo file - "Get Inlclude Folder and Source File"
	@echo sizeinfo - "Get Binaray File Size"
	@echo gccversion - "Get arm-none-eabi-gcc version Check"
	@echo createdirs - "Make Object, Binary, hex file In Folder Name"	
	@$(MAKE) -f scripts/Makefile help


lss: $(BUILD_DIR)/$(TARGET).lss
bin: $(BUILD_DIR)/$(TARGET).bin
sym: $(BUILD_DIR)/$(TARGET).sym

