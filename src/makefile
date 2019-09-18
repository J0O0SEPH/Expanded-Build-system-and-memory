include sources.mk


PLATFORM=$(shell uname)
COURSE=-DCOURSE1

ifeq ($(PLATFORM), Linux)
SRC:=SRC_Linux
CC=gcc
CFLAGS=-g -v -D$(PLATFORM)
CPPFALGS=
ASFLAGS=
LDFLAGS=
LDLIBS=
endif
ifeq ($(PLATFORM), MSP432)
SRC:=SRC_MSP
CC=arm-none-eabi-gcc
CFLAGS=-g -v -D$(PLATFORM)
ARCH= -mcpu=cortex-m4 -mthumb -specs=nosys.specs
CPPFALGS=
ASFLAGS=
LDFLAGS=
LDLIBS=-T msp432p401r.lds
endif

%.o:%.c
	$(CC) $(ARCH) $(INCLUDE) $(CFLAGS) $(CPPFLAGS) $(ASFLAGS)\
	    	$(LDFLAGS) $(LDLIBS) $^ -o $@


.phony:all
all:main	
main:main.c course1.c data.c memory.c stats.c#$(SRC)
	$(CC) $(ARCH) $(INCLUDE) $(CFLAGS) $(CPPFLAGS) $(ASFLAGS)\
	     	$(LDFLAGS) $(LDLIBS) $(COURSE) $^ -o $@


.phony:clean
clean:
	rm -f *.o *.s *.i *.out main 
