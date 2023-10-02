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
 * @brief <he 'stats.c file contains a main function that will be having the unsigned char array in addition to seven functions designed to operate on arrays of unsigned characters >
 *
 * <The user will input the array then these functions will be calculating the median and mean, finding the maximum and the minimum values of the inputed array, as well as sorting the array in descending order. And to do so there's a whole function that will do all these calculations nad if the user chose to get only one valu like the median for example there's other functions that will be doing these tasks separetly>
 *  * @author <Danile Abou ElEzz>
 * @date <22/9/2023>
 *
 */



#include <stdio.h>
#include "stats.h"
#include <string.h>
/* Size of the Data Set */


#define SIZE (40)


int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  int length = strlen(test);
  float median, mean;
  unsigned char max, min;
  /* Statistics and Printing Functions Go Here */
	
	print_statistics(test, length, &mean, &median, &max, &min);
	
	int rounded_median = (int)median;
  	int rounded_mean = (int)mean;

	print_array(test, length);
	
	find_median(test, length);

	find_mean(test, length);

	find_maximum(test,length);

	find_minimum(test,length);

	sort_array(test, length);

	printf("Median: %d\n", rounded_median);
	printf("Mean: %d\n", rounded_mean);
	printf("Maximum: %u\n", max);
	printf("Minimum: %u\n", min);
	

	return 0;

}

/* Add other Implementation File Code Here */

void print_statistics(unsigned char arr[], int length, float *mean, float *median, 
		unsigned char *max, unsigned char *min){

	int sum = 0;
	for (int i = 0; i < length; i++){
		sum += arr[i];
	}
	*mean = (float)sum / length;
	

	*max = *min =arr[0];

	for (int i = 0; i< length; i++){
		if (arr[i] > *max) *max = arr[i];

		if (arr[i] < *min) *min = arr[i];
	
	}



	for (int i = 0; i< length-1; i++){
		for(int j= 0; j< length-1; j++){
		
		if (arr[j] < arr[j+1]){
			int temp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = temp;
				
				}
		}
	
	}
	if (length % 2 ==0){
		*median = (arr[length/2 -1] + arr[length/2]) / 2.0;
	}
	else *median = arr[length/2];

}




int print_array(unsigned char arr[], int length)
{
	printf("The array is :");
	for (int i = 0; i<length; i++) printf(" %d,", arr[i]);
	
	
	printf("\nIts length is: %d\n", length); 
}



int find_median(unsigned char arr[], int length){
	float median;
	if (length % 2 ==0){
                median = (arr[length/2 -1] + arr[length/2]) / 2.0;
        }
        else median = arr[length/2];
	int rounded_down = (int)median;
	printf("The median is: %d\n", rounded_down);
}



int find_mean(unsigned char arr[],int length){
	int sum = 0;
        for (int i = 0; i < length; i++){
                sum += arr[i];
        }
        float mean = (float)sum / length;
	int rounded_down = (int)mean;

	printf("The mean is: %d\n", rounded_down);

}

int find_maximum(unsigned char arr[], int length){
	int max = arr[0];
	for (int i = 0; i<length; i++){
		if (arr[i] > max) {
			max = arr[i];
		}
	}
printf("The biggest number is: %d\n", max);
}


int find_minimum(unsigned char arr[], int length){
        int min = arr[0];
        for (int i = 0; i<length; i++){
                if (arr[i] < min) {
                        min = arr[i];
                }
        }
	printf("The smallest number is: %d\n", min);

}

void sort_array(unsigned char arr[], int length){
	for (int i = 0; i< length-1; i++){
                for(int j= 0; j< length-1; j++){

                if (arr[j] < arr[j+1]){
                        int temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;

                                }
                }

        }


}
