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
 * @file <AbouElEzz_Coursera> 
 * @brief <the 'stats.h' header file contains declarations for seven functions designed to operate on arrays of unsigned characters>
 *
 * <These functions include calculating the median and mean, findind the maximum values, as well as sorting the array in descending order>
 *
 * @author <Daniel Abou ElEzz>
 * @date <22/9/2023 >
 *
 */

#ifndef __STATS_H__
#define __STATS_H__



/*this function takes an array of unsigned char values in addition to the length of the array and four declared pointers where we can store the median, mean, smallest number, and biggest number , all after being calculated using this function*/
void print_statistics(unsigned char arr[], int length, float *mean, float *median,
                unsigned char *max, unsigned char *min);


/*this function takes an array of unsigned char values in addition to the length of the array and print it to the screen in addition to the length of the array*/
int print_array(unsigned char arr[], int length);

/*This function takes an array of unsighned char values and its length as argument, and returns the median of the elements in the array*/
int find_median(unsigned char arr[], int length);

/*This function takes an array of unsighned char values and its length as argument, and returns the mean of the elements in the array*/
int find_mean(unsigned char arr[],int length);

/*This function takes an array of unsighned char values and its length as argument, and returns the biggest number of the elements in the array*/
int find_maximum(unsigned char arr[], int length);

/*This function takes an array of unsighned char values and its length as argument, and returns the smallest number of the elements in the array*/
int find_minimum(unsigned char arr[], int length);

/*This function takes an array of unsighned char values and its length as argument, and sorts the array in a descending manner*/
void sort_array(unsigned char arr[], int length);


#endif
