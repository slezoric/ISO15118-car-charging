/*
 * BitEncoderChannel.c
 *
 *  Created on: 03.01.2016
 *      Author: melanie
 */

#include "EncoderChannel.h"
#include "BitOutputStream.h"


#ifndef BIT_ENCODER_CHANNEL_C
#define BIT_ENCODER_CHANNEL_C

#if EXI_OPTION_ALIGNMENT == BIT_PACKED


int encode(bitstream_t* stream, uint8_t b) {
	return writeBits(stream, 8, b);
}

int encodeNBitUnsignedInteger(bitstream_t* stream, uint16_t nbits, uint32_t val)  {
	int errn = 0;
	if (nbits > 0) {
		errn = writeBits(stream, nbits, val);
	}
	return errn;
}

/**
 * Encode a single boolean value. A false value is encoded as bit 0 and true
 * value is encode as bit 1.
 */
int encodeBoolean(bitstream_t* stream, int b) {
	uint8_t val = b ? 1 : 0;
	return writeBits(stream, 1, val);
}

/**
 * Flush underlying bit output stream.
 */
int encodeFinish(bitstream_t* stream) {
	return flush(stream);
}


#endif /* alignment */

#endif

