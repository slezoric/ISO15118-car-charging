/*
 * AbstractDecoderChannel.c
 *
 *  Created on: 04.01.2016
 *      Author: melanie
 */


#include "ErrorCodes.h"
#include "DecoderChannel.h"


/**
 * Decode an arbitrary precision integer using a sign bit followed by a
 * sequence of octets. The most significant bit of the last octet is set to
 * zero to indicate sequence termination. Only seven bits per octet are used
 * to store the integer's value.
 */
int decodeInteger16(bitstream_t* stream, int16_t* int16) {
	int b;
	uint16_t uint16;
	int errn = decodeBoolean(stream, &b);

	if (errn == 0) {
		if (b) {
			/* For negative values, the Unsigned Integer holds the
			 * magnitude of the value minus 1 */
			errn = decodeUnsignedInteger16(stream, &uint16);
			*int16 = (int16_t)(-(uint16 + 1));
		} else {
			/* positive */
			errn = decodeUnsignedInteger16(stream, &uint16);
			*int16 = (int16_t)(uint16);
		}
	}

	return errn;
}

int decodeInteger32(bitstream_t* stream, int32_t* int32) {
	int b;
	uint32_t uint32;
	int errn = decodeBoolean(stream, &b);

	if (errn == 0) {
		if (b) {
			/* For negative values, the Unsigned Integer holds the
			 * magnitude of the value minus 1 */
			errn = decodeUnsignedInteger32(stream, &uint32);
			*int32 = (-(int32_t)(uint32 + 1));
		} else {
			/* positive */
			errn = decodeUnsignedInteger32(stream, &uint32);
			*int32 = (int32_t)(uint32);
		}
	}

	return errn;
}

/**
 * Decode an arbitrary precision integer using a sign bit followed by a
 * sequence of octets. The most significant bit of the last octet is set to
 * zero to indicate sequence termination. Only seven bits per octet are used
 * to store the integer's value.
 */
int decodeInteger64(bitstream_t* stream, int64_t* int64) {
	int b;
	uint64_t uint64;
	int errn = decodeBoolean(stream, &b);

	if (errn == 0) {
		if (b) {
			/* For negative values, the Unsigned Integer holds the
			 * magnitude of the value minus 1 */
			errn = decodeUnsignedInteger64(stream, &uint64);
			*int64 = (-(int64_t)(uint64 + 1));
		} else {
			/* positive */
			errn = decodeUnsignedInteger64(stream, &uint64);
			*int64 = (int64_t)(uint64);
		}
	}

	return errn;
}

int decodeUnsignedInteger16(bitstream_t* stream, uint16_t* uint16) {
	unsigned int mShift = 0;
	int errn = 0;
	uint8_t b;
	*uint16 = 0;

	do {
		/* 1. Read the next octet */
		errn = decode(stream, &b);
		/* 2. Multiply the value of the unsigned number represented by the 7
		 * least significant
		 * bits of the octet by the current multiplier and add the result to
		 * the current value */
		*uint16 = (uint16_t)(*uint16 + ((b & 127) << mShift));
		/* 3. Multiply the multiplier by 128 */
		mShift += 7;
		/* 4. If the most significant bit of the octet was 1, go back to step 1 */
	} while (errn == 0 && (b >> 7) == 1);

	return errn;
}

int decodeUnsignedInteger32(bitstream_t* stream, uint32_t* uint32) {
	/* 0XXXXXXX ... 1XXXXXXX 1XXXXXXX */
	unsigned int mShift = 0;
	int errn = 0;
	uint8_t b;
	*uint32 = 0;

	do {
		/* 1. Read the next octet */
		errn = decode(stream, &b);
		/* 2. Multiply the value of the unsigned number represented by the 7
		 * least significant
		 * bits of the octet by the current multiplier and add the result to
		 * the current value */
		*uint32 += (uint32_t)((b & 127) << mShift);
		/* 3. Multiply the multiplier by 128 */
		mShift += 7;
		/* 4. If the most significant bit of the octet was 1, go back to step 1 */
	} while (errn == 0 && (b >> 7) == 1);

	return errn;
}

/**
 * Decode an arbitrary precision non negative integer using a sequence of
 * octets. The most significant bit of the last octet is set to zero to
 * indicate sequence termination. Only seven bits per octet are used to
 * store the integer's value.
 */
int decodeUnsignedInteger64(bitstream_t* stream, uint64_t* uint64) {
	unsigned int mShift = 0;
	int errn = 0;
	uint8_t b;
	*uint64 = 0L;

	do {
		errn = decode(stream, &b);
		*uint64 += ((uint64_t) (b & 127)) << mShift;
		mShift += 7;
	} while (errn == 0 && (b >> 7) == 1);

	return errn;
}


/**
 * Decode a sequence of characters according to a given length.
 * Each character is represented by its UCS [ISO/IEC 10646]
 * code point encoded as an Unsigned Integer
 */
int decodeCharacters(bitstream_t* stream, uint16_t len, exi_string_character_t* chars) {
	unsigned int i;
	int errn = 0;

#if STRING_REPRESENTATION == STRING_REPRESENTATION_ASCII
	uint8_t b;
	for (i = 0; i < len && errn == 0; i++) {
		errn = decode(stream, &b);
		if(b < 128) {
			chars[i] = (exi_string_character_t)b;
		} else {
			errn = EXI_ERROR_STRINGVALUES_CHARACTER;
		}
	}
	/* null terminator \0 */
	chars[i] = '\0';

#endif /* STRING_REPRESENTATION_ASCII */
#if STRING_REPRESENTATION == STRING_REPRESENTATION_UCS
	for (i = 0; i < len && errn == 0; i++) {
		errn = decodeUnsignedInteger32(stream, &chars[i]);
	}
#endif /* STRING_REPRESENTATION_UCS */




	return errn;
}

int decodeBytes(bitstream_t* stream, uint16_t len, uint8_t* data) {
	unsigned int i;
	int errn = 0;
	uint8_t b;

	for (i = 0; i < len && errn == 0; i++) {
		errn = decode(stream, &b);
		data[i] = (uint8_t)b;
	}

	return errn;
}
