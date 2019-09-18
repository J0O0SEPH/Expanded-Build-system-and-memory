/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
#include "memory.h"

void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}


uint8_t* my_memmove(uint8_t *src, uint8_t *dst, size_t length){
	uint8_t *tmp=malloc(length*sizeof(*src));
	if(!tmp){exit(1);}
	for(int i=0;i<length;i++){*(tmp+i)=*(src+i);}
	for(int j=0;j<length;j++){
		*(dst+j)=*(tmp+j);
	}
	free(tmp);
	return dst;
}


uint8_t* my_memcopy(uint8_t *src, uint8_t *dst, size_t length){
		for(int i=0;i<length;i++){
			*(dst+i)=*(src+i);
		}
	return dst;
}


uint8_t* my_memset(uint8_t *src, size_t length, uint8_t value){
	for(int i=0;i<length;i++){
		*(src+i)=value;
	}
	return src;
}

uint8_t* my_memzero(uint8_t *src, size_t length){
	for(int i=0;i<length;i++){
		*(src+i)=0;
	}
	return src;
}


uint8_t* my_reverse(uint8_t *src, size_t length){
	uint8_t tmp;
	for(int i=0;i<length/2;i++){
		tmp=*(src+i);
		*(src+i)=*(src+(length-i-1));
		*(src+(length-i-1))=tmp;
	}
	return src;	
}

int32_t* reserve_words(size_t length){
	int32_t *tmp=malloc(length*sizeof(*tmp));
	return tmp;
}


void free_words(int32_t *src){
	free(src);
}



