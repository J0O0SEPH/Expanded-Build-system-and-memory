#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../include/common/memory.h"
#define SIZE (10)


uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base);
void pop_arr(uint8_t *whereabouts, size_t length);
void print_arr(uint8_t *whereabouts, size_t length );
int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base);


int main(){
	uint8_t *newLoc=malloc(32*sizeof(*newLoc));
//	uint8_t *oldLoc=malloc(SIZE*sizeof(*oldLoc));
//	pop_arr(oldLoc, SIZE);
//	printf("%p\n", oldLoc);
//	print_arr(oldLoc, SIZE);
//
//	newLoc= my_reverse(oldLoc, SIZE);
//	printf("%p\n", newLoc);
//	print_arr(newLoc, SIZE);
//	
//	free(oldLoc);
//	free(newLoc);
	uint8_t length=my_itoa(-524,newLoc,10);
	printf("length: %d,%s\n",length ,newLoc);
	uint32_t nomber= my_atoi(newLoc,length,10);
	printf("%d\n",nomber);
}



int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base){
	int32_t sgnd=0, rslt=0;
	for(int i=0; i<digits; i++){
		if(*(ptr)=='-'){*ptr='0';sgnd=1;}
		else if(*(ptr+i)>'9'){rslt+=(*(ptr+i)-'7');}
		else{rslt+=(*(ptr+i)-'0');}
		if(!*(ptr+i+1)){break;}
		rslt*=base;
	}
	if(sgnd){rslt=-rslt;}
	return rslt;
}


uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base){
	uint8_t cnt=0,sgnd=0;
	uint8_t *tmp=calloc(32,sizeof(*tmp));
	if(!tmp){exit(1);}
	else{
	    for(int i=0;i<32;i++){
		if(data<0){data=-data;sgnd=1;}
		if(data!=0){
		   if(data%base<10){
			*(tmp+i)=(data%base)+'0';
			data/=base;
		   }
		   else{
			*(tmp+i)=(data%base)+'7';
			data/=base;
		   }
		cnt++;	   
		}
	    }
	if(sgnd){*(tmp+cnt)=45;++cnt;}
	}
	my_reverse(tmp, cnt);
	my_memcopy(tmp,ptr,cnt);
	return ++cnt;
}


int32_t* reserve_words(size_t length){
	int32_t *tmp=malloc(length*sizeof(*tmp));
	return tmp;
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


uint8_t* my_memzero(uint8_t *src, size_t length){
	for(int i=0;i<length;i++){
		*(src+i)=0;
	}
	return src;
}


uint8_t* my_memset(uint8_t *src, size_t length, uint8_t value){
	for(int i=0;i<length;i++){
		*(src+i)=value;
	}
	return src;
}


uint8_t* my_memmove(uint8_t *src, uint8_t *dst, size_t length){
	uint8_t *tmp;
	tmp= realloc(src, length*sizeof(*src));
	if(tmp==NULL){exit(1);}
	else{dst=tmp;}
	return dst;
}

uint8_t* my_memcopy(uint8_t *src, uint8_t *dst, size_t length){
		for(int i=0;i<length;i++){
			*(dst+i)=*(src+i);
		}
	return dst;
}

void print_arr(uint8_t *whereabouts, size_t length ){
	for(int i=0; i< length; i++){
		printf("%d..",*(whereabouts+i));
	}
	printf("\n");
}


void pop_arr(uint8_t *whereabouts, size_t length){
	for(int i=0; i< length; i++){
		whereabouts[i]=i*4;
	}
}

