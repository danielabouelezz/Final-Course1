#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Using this Makefile we will be generating several kind of files>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <In this Makefile we are using hedears and source files to generate several 
#      file type like .d, .asm, .i, .o and .map which are dependency files, assembly files,
#      preprocessed files, object files and map files respectively using flags and makefile
#      rules that we will be building in this Makefile.
#
# Platform Overrides:
#      <Using the gcc compiler and the arm-none-eabi-gcc cross compiler we will be 
#      building these files for the HOST and the MSP432 platform respectively with 
#      the given specs in the quiz2.
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = Host
COURSE1 = COURSE1
VERBOSE = VERBOSE
# General Flags(Both Platforms)
FLAGS = -Wall\
	-Werror\
	-g\
	-O0\
	-std=c99

TARGET = final_assesment

ifeq ($(PLATFORM),HOST)
	CC = gcc
	CFLAGS = $(FLAGS)
	CPPFLAGS = -DHOST 
	LDFLAGS = -Wl,-Map=$(TARGET).map
	SIZE = size
endif

ifeq ($(PLATFORM),MSP432)
	LINKER_FILE = -T msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	OTHER_SPECS = -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
	#Source Files necessary for the platform
	SOURCES = ./src/main.c\
		  ./src/memory.c\
		  ./src/interrupts_msp432p401r_gcc.c\
		  ./src/startup_msp432p401r_gcc.c\
		  ./src/system_msp432p401r.c

	CC = arm-none-eabi-gcc
	LINKER_PATH = -L ../
	CPPFLAGS = -DMSP432 $(INCLUDES)
	CFLAGS = $(FLAGS) $(OTHER_SPECS) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS)
	LDFLAGS = -Wl,-Map=$(TARGET).map, $(LINKER_PATH) $(LINKER_FILE)
	SIZE = arm-none-eabi-size

endif

ifeq ($(COURSE1),COURSE1)
	CPPFLAGS += -DCOURSE1
endif

ifeq ($(VERBOSE),VERBOSE)
	CPPFLAGS += -DVERBOSE
endif


OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
ASMS = $(SOURCES:.c=.asm)
PRES = $(SOURCES:.c=.i)


# Comiling without linking using -c
%.o : %.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -o $@

#Generating assembly file using -S
%.asm : %.c
	$(CC) -S $< $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -o $@

#Generating preprocessed file using -E
%.i : %.c
	$(CC) -E $< $(CPPFLAGS) $(INCLUDES) -o $@

#Generating dependency files using -E -M
%.d : %.c
	$(CC) -E -M $< $(CPPFLAGS) $(INCLUDES) -o $@

.PHONY: compile-all
compile-all:$(OBJS)

.PHONY: build
build: $(DEPS)
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) $(INCLUDES) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(ARMS) $(PRES) $(TARGET).out $(TARGET).map
