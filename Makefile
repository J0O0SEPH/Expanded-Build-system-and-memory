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
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

PLATFORM:= $(shell uname)

ifeq ($(PLATFORM), Linux)
	SRC=$(SOURCES)
	CC= gcc
else
	SRC=$(SOURCE)
	CC=arm-none-eabi-gcc
	LINKER_FILE=msp432p401r.lds
	PLATFORMFLAGS:=-mcpu=cortex-m4 -mthumb -specs=nosys.specs
endif

ARCH=-D$(PLATFORM) 
OBJS= $(SRC: .c=.o) 
CPPFLAGS= -E
LDFLAGS= -Wl,-Map=
CFLAGS= -g -v -c
ASFLAGS= -S

%.o: %.c
	$(CC) $(INCLUDES) $(ARCH) $(CFLAGS) $^ -o $@

%.i: %.c
	$(CC) $(INCLUDES) $(ARCH) $(CPPFLAGS) $^ -o $@

%.s: %.c
	$(CC) $(INCLUDES) $(PLATFORMFLAGS) $(ARCH) $(ASFLAGS) $^ -o $@

%.map: $(SRC) 
	$(CC) $^ $(INCLUDES) $(ARCH)  $(LDFLAGS)$@ -o $@

.phony: all
all:main.out
main.out: $(OBJS)
	$(CC) $(ARCH) $(PLATFORMFLAGS) $(INCLUDES) -Wl,-T $(LINKER_FILE) $^ -o $@

.phony: clean
clean:
	 rm -f *.o *.out *.map *.s *.i
