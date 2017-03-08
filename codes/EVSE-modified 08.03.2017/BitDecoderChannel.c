/*
 * BitDecoderChannel.c
 *
 *  Created on: 04.01.2016
 *      Author: melanie
 */


#include "DecoderChannel.h"
#include "BitInputStream.h"
#include "EXITypes.h"
#include "ErrorCodes.h"

#ifndef BIT_DECODER_CHANNEL_C
#define BIT_DECODER_CHANNEL_C


#if EXI_OPTION_ALIGNMENT == BIT_PACKED

int decode(bitstream_t* stream, uint8_t* b) {
	uint32_t bb;
	int errn =  readBits(stream, 8, &bb);
	if (errn == 0) {
		if (bb > 256) {
			errn = EXI_ERROR_UNEXPECTED_BYTE_VALUE;
		} else {
			*b = (uint8_t)bb;
		}
	}

	return errn;
}

int decodeNBitUnsignedInteger(bitstream_t* stream, uint16_t nbits, uint32_t* uint32) {
	int errn = 0;
	if (nbits == 0) {
		*uint32 = 0;
	} else {
		errn= readBits(stream, nbits, uint32);
	}
	return errn;
}

int decodeBoolean(bitstream_t* stream, int* b) {
	uint32_t ub;
	int errn = readBits(stream, 1, &ub);
	*b = (ub == 0) ? 0 : 1;
	return errn;
}

#endif

#endif


