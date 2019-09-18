INCLUDE=-I../include/common \
	-I../include/msp432 \
	-I../include/CMSIS



SRC_Linux=main.c course1.c data.c memory.c stats.c	

SRC_MSP=$(shell ls *.c)


