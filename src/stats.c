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
/**
 * @file "stats.c" 
 * @brief "impelementation file for statistical funstions (calculations, and print)"
 *	
 *  functions included are "look header file(stats.h), for more details": 
 *
 *	print_statistics() 
 *	print_array()
 *	find_median()
 *	find_mean()
 *	find_maximum()
 *	find_minimum()
 *	sort_array()
 *
 * @author "Joseph Soliman"
 * @date "12/09/2019"
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)
/**
 *void main() {
 *
 *  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
 *                              114, 89,   45,  76, 123,  87,  25,  23,
 *                              200, 122, 150, 90,   92,  87, 177, 244,
 *                              201,   6,  12,  60,   8,   2,   5,  67,
 *                                7,  87, 250, 230,  99,   3, 100,  90};
 *
 *  Other Variable Declarations Go Here
 *   Statistics and Printing Functions Go Here 
 *unsigned char max, min, mean, median;
 *#ifdef VERBOSE
 *print_array((unsigned char*)&test, SIZE);
 *#endif
 *max=find_maximum((unsigned char*)&test, SIZE);
 *min=find_minimum((unsigned char*)&test, SIZE);
 *mean=find_mean((unsigned char*)&test, SIZE);
 *median=find_median((unsigned char*)&test, SIZE);
 *print_statistics(max, min, mean,median);
 *}
 *
*/
/* Add other Implementation File Code Here */


	void print_statistics (unsigned char max, unsigned char min, unsigned char mean,unsigned char median){
		printf("maximum: %d\nminimum: %d\nmean: %d\nmedian: %d\n\n", max, min, mean, median);
	}
	void print_array(unsigned char *array, int length){
		for(int i=0;i<length;i++){
			printf("%-*d ",3, array[i]);
			if(i==0){continue;}
			if((i+1)%8==0){printf("\n");}

		}printf("\n");
	}

	unsigned char find_maximum(unsigned char *array, int length){
		int max=0;
		for(int i=0; i<length;i++){
			if(array[i]>max){
				max=array[i];
			}
		}
		return max;
	}
	unsigned char find_minimum(unsigned char *array, int length){
			int min=255;
		for(int i=0; i<length;i++){
			if(array[i]<min){
				min=array[i];
			}
		}
		return min;	
	}
	unsigned char find_mean(unsigned char *array, int length){
		int mean=0;
		for(int i=0;i<length;i++){
			mean+=array[i];
		}
		return mean/length;
	}
	unsigned char find_median(unsigned char *array, int length){
		unsigned char median;
		sort_array(array, length);
		median=array[length/2];
		if(length%2==0){
			median=(array[((length-1)/2)]+median)/2;
		}
		return median;
	}

	void sort_array(unsigned char *array, int length){
		unsigned char sorted[length];
		for(int i=0;i<length;i++){
			unsigned char index=0;
			for(int j=0;j<length;j++){
				if(array[j]>array[index]){
					index=j;
				}
			}
			sorted[i]=array[index];
			array[index]=0;
		}
		for(int i=0;i<length;i++){
		array[i]=sorted[i];
		}
	}

