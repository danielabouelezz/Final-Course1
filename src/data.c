#include <stdlib.h>
#include <stdbool.h>
#include "memory.h"
//#include "platform.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
	uint8_t digitShift = 48;
	uint8_t charShift = 65;
	if(data == 0){
		*ptr = '0';
		*(ptr + 1) = '\0';
		return 2;
	}
	bool negative = false;
	if(data < 0){
		negative = true;
		data *= -1;
	}
	*ptr = '\0';
	int count = 1;
	do{
		int digit = data % base;
		data /= base;
		if(digit < 10){
			*(ptr + count) = digitShift + digit;
		} else {
			*(ptr + count) = charShift + digit;
		}
		count++;
	} while(data > 0);
	if(negative){
		*(ptr + count) = '-';
		count++;
	}
	my_reverse(ptr, count);
	return count;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
	uint8_t digitShift = 48;
	uint8_t charShift = 65;
	bool negative = false;
	int32_t res = 0;
	for(int i = 0; i < digits; i++){
		uint8_t code = *(ptr + i);
		if(code == '-'){
			negative = true;
			continue;
		}
		if(code == 0){
			break;
		}
		if(code >= charShift){
			code -= charShift;
		} else {
			code -= digitShift;
		}
		res *= base;
		res += code;		
	}
	if(negative){
		res *= -1;
	}
	return res;
}
