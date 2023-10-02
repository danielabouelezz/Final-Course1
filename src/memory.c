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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
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


uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
  //allocated memory temp array
    uint8_t * temp  = (uint8_t *)malloc(sizeof(uint8_t ) * length);
if(NULL == temp)
    {
return NULL;
    }
else
    {
      unsigned int i;
      //copy src in temp array
for (i=0; i<length ; i++)
      {
        *(temp + i) = *(src + i);
      }
      //copy tmp to dest
for (i=0 ;i<length;i++)
      {
        *(dst+i) = *(temp+i);
      }

      free(temp); //free allocated memory
    }

return dst;
}

uint8_t * my_memcopy (uint8_t * src, uint8_t * dst, size_t length)
{
unsigned int i;

for (i=0; i<length ; i++)
  {
    *(dst + i) = *(src + i);
  }
return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
unsigned int i;

for (i=0 ; i<length ; i++)
  {
    *(src + i) = value;
  }

return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length)
{
unsigned int i;

for (i=0 ; i<length ; i++)
  {
	  *(src + i) = 0;
  }

return src;

}

uint8_t * my_reverse(uint8_t * src, size_t length)
{

uint8_t vec_inv[length];

int i = length-1 , j=0;

while(i>=0)
 {

	vec_inv[j] = *(src + i);
	i--;
 	j++;
 }

for(i=0 ; i<length ; i++)
{
	*(src + i) = vec_inv[i];
}

return src;
}

int32_t * reserve_words(size_t length)
{
int32_t * is_allocated = (int32_t *)malloc(sizeof(int32_t)*length);
if (NULL == is_allocated)
  {
 return NULL;
  }
else
  {
return is_allocated;
  }
}

void free_words(uint32_t * src)
{
return free(src);
}
