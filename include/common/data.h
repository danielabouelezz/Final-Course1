
// ********************************************************************************
/**
 * @file   data.h
 * @brief  Abstraction of data manipulation functions
 *
 * This header file provides an abstraction for data manipulation functions
 * integer-to-ASCII and ASCII-to-integer
 *
 * @Author Daniel Abou ElEzz
 * @date   November 2/10/2023
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief Converts an integer into an ASCII string
 *
 * Converts data from a standard integer type into an ASCII string
 *
 * @param  ptr Pointer to string location
 * @param  data Integer to convert to string
 * @param  base Base of data integer
 *
 * @return Char Length of converted data
 */
uint8_t my_itoa(int32_t * ptr, int32_t data, uint32_t base);

/**
 * @brief Converts an ASCII string to an integer
 *
 * Converts an ASCII string to an integer
 *
 * @param ptr Pointer to an ASCII string
 * @param digits Char Number of digits in string
 * @param base Integer base of digits data
 *
 * @return Integer 32 Bit signed integer result
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);


#endif /* __DATA_H__ */
