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
 * @file <stats.h> 
 * @brief "header file for stas.c, includes functions declarations and double include guard"
 *
 * @author "Joseph Soliman"
 * @date "12/09/2019"
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief "print results from statical functions" 
 *    "must include "stdio.h""
 *    "print in command line the values: maximum, minimum, mean, median"
 * @param "unsigned char max" <result of find_maximum();>
 * @param "unsigned char min "<result of find_minimum();>
 * @param "unsigned char mean "<result of find_mean();>
 * @param "unsigned char median"<result of find_median();>
 *
 * @return "void" prints results in command line
 */
	void print_statistics(unsigned char max,unsigned  char min,unsigned  char mean,unsigned char median);




/**
 * @brief "prints given array into command line" 
 *
 *	"must include "stdio.h" array values divided into rows of 8 elements"
 *
 * @param   "unsigned char * array", "pointer to the desired array to print"
 * @param   "int length", "number of array's elements"
 *
 * @return  "void", "prints into command line array values in rows of 8 elements" 
 */
	void print_array(unsigned char *array, int length);




/**
 * @brief "calls sort_array() function, then pick value/values in the middle"
 *
 * @param   "unsigned char * array", "pointer to the desired array to calculate median"
 * @param   "int length", "number of array's elements"
 *
 * @return  "unsigned char median" 
 */
	unsigned char find_median(unsigned char *array, int length);





/**
 * @brief   "iterate through elements and update the minimum value" 
 *
 * @param   "unsigned char * array", "pointer to the desired array to calculate maximum"
 * @param   "int length", "number of array's elements"
 *
 * @return  "unsigned char max" 
 */
	unsigned char find_maximum(unsigned char *array, int length);
	
	

	
/**
 * @brief   "iterate through elements and update the minimum value" 
 *
 * @param   "unsigned char * array", "pointer to the desired array to clculate minimum"
 * @param   "int length", "number of array's elements"
 *
 * @return  "unsigned char min" 
 */
	unsigned char find_minimum(unsigned char *array, int length);




/**
 * @brief   "sum/count" 
 *
 * @param   "unsigned char * array", "pointer to the desired array to calculate the mean value"
 * @param   "int length", "number of array's elements"
 *
 * @return  "unsigned char mean" 
 */
	unsigned char find_mean(unsigned char *array, int length);




/**
 * @brief   "descending sort" 
 *
 * @param   "unsigned char * array", "pointer to the desired array to sort in descending order"
 * @param   "int length", "number of array's elements"
 * @return  "void","reorder the indicated array in descending manner" 
 */
	void sort_array(unsigned char *array, int length);




#endif /* __STATS_H__ */
