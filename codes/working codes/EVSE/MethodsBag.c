/*
 * MethodsBag.c
 *
 *  Created on: 03.01.2016
 *      Author: melanie
 */


#ifndef METHODS_BAG_C
#define METHODS_BAG_C

#include "MethodsBag.h"
#include "ErrorCodes.h"


uint8_t numberOf7BitBlocksToRepresent(uint32_t n) {
	/* assert (n >= 0); */

	/* 7 bits */
	if (n < 128) {
		return 1;
	}
	/* 14 bits */
	else if (n < 16384) {
		return 2;
	}
	/* 21 bits */
	else if (n < 2097152) {
		return 3;
	}
	/* 28 bits */
	else if (n < 268435456) {
		return 4;
	}
	/* 35 bits */
	else {
		/* int, 32 bits */
		return 5;
	}
}



#endif

