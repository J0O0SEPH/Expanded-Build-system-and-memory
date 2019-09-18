/******************************************************************************
 * Copyright (C) 2019 by Joseph Soliman 
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * Author is  not liable for any misuse of this material. 
 *
 *****************************************************************************/
#include "data.h"
#include "memory.h"



uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base){
	uint8_t cnt=0,sgnd=0;
	uint8_t *tmp=calloc(32,sizeof(*tmp));
	if(!tmp){exit(1);}
	else{
	    for(int i=0;i<32;i++){
		if(data<0){data=-data;sgnd=1;}
		if(data!=0){
		   if(data%base<10){
			*(tmp+i)=(data%base)+48;
			data/=base;
		   }
		   else{
			*(tmp+i)=(data%base)+55;
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
