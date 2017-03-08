/*
 * AbstractEncoderChannel.c
 *
 *  Created on: 03.01.2016
 *      Author: melanie
 */


# include "EncoderChannel.h"
# include "MethodsBag.h"


/**
 * Encode an arbitrary precision non negative integer using a sequence of
 * octets. The most significant bit of the last octet is set to zero to
 * indicate sequence termination. Only seven bits per octet are used to
 * store the integer's value.
 */
int encodeUnsignedInteger16(bitstream_t* stream, uint16_t n) {
	int errn = 0;
	if (n < 128) {
		/* write byte as is */
		errn = encode(stream, (uint8_t) n);
	} else {
		uint8_t n7BitBlocks = numberOf7BitBlocksToRepresent(n);

		switch (n7BitBlocks) {
		case 3:
			errn = encode(stream, (uint8_t) (128 | n));
			n = n >> 7;
			if (errn != 0) {
				break;
			}
			/* no break */
		case 2:
			errn = encode(stream, (uint8_t) (128 | n));
			n = n >> 7;
			if (errn != 0) {
				break;
			}
			/* no break */
		case 1:
			/* 0 .. 7 (last byte) */
			errn = encode(stream, (uint8_t) (0 | n));
			/* no break */
		}
	}

	return errn;
}

/**
 * Encode an arbitrary precision non negative integer using a sequence of
 * octets. The most significant bit of the last octet is set to zero to
 * indicate sequence termination. Only seven bits per octet are used to
 * store the integer's value.
 */
int encodeUnsignedInteger32(bitstream_t* stream, uint32_t n) {
	int errn = 0;
	if (n < 128) {
		/* write byte as is */
		errn = encode(stream, (uint8_t) n);
	} else {
		uint8_t n7BitBlocks = numberOf7BitBlocksToRepresent(n);

		switch (n7BitBlocks) {
		case 5:
			errn = encode(stream, (uint8_t) (128 | n));
			n = n >> 7;
			if (errn != 0) {
				break;
			}
			/* no break */
		case 4:
			errn = encode(stream, (uint8_t) (128 | n));
			n = n >> 7;
			if (errn != 0) {
				break;
			}
			/* no break */
		case 3:
			errn = encode(stream, (uint8_t) (128 | n));
			n = n >> 7;
			if (errn != 0) {
				break;
			}
			/* no break */
		case 2:
			errn = encode(stream, (uint8_t) (128 | n));
			n = n >> 7;
			if (errn != 0) {
				break;
			}
			/* no break */
		case 1:
			/* 0 .. 7 (last byte) */
			errn = encode(stream, (uint8_t) (0 | n));
			/* no break */
		}
	}

	return errn;
}

/**
 * Encode an arbitrary precision non negative integer using a sequence of
 * octets. The most significant bit of the last octet is set to zero to
 * indicate sequence termination. Only seven bits per octet are used to
 * store the integer's value.
 */
int encodeUnsignedInteger64(bitstream_t* stream, uint64_t n) {
	int errn = 0;
	uint8_t lastEncode = (uint8_t) n;
	n >>= 7;

	while (n != 0 && errn == 0) {
		errn = encode(stream, lastEncode | 128);
		lastEncode = (uint8_t) n;
		n >>= 7;
	}

	if (errn == 0) {
		errn = encode(stream, lastEncode);
	}

	return errn;
}

int encodeInteger32(bitstream_t* stream, int32_t n) {
	int errn;
	/* signalize sign */
	if (n < 0) {
		errn = encodeBoolean(stream, 1);
		/* For negative values, the Unsigned Integer holds the
		 * magnitude of the value minus 1 */
		n = (-n) - 1;
	} else {
		errn = encodeBoolean(stream, 0);
	}
	if (errn == 0) {
		errn = encodeUnsignedInteger32(stream, (uint32_t)n);
	}
	return errn;
}

/**
 * Encode an arbitrary precision integer using a sign bit followed by a
 * sequence of octets. The most significant bit of the last octet is set to
 * zero to indicate sequence termination. Only seven bits per octet are used
 * to store the integer's value.
 */
int encodeInteger16(bitstream_t* stream, int16_t n) {
	int errn;
	/* signalize sign */
	if (n < 0) {
		errn = encodeBoolean(stream, 1);
		/* For negative values, the Unsigned Integer holds the
		 * magnitude of the value minus 1 */
		n = (int16_t)((-n) - 1);
	} else {
		errn = encodeBoolean(stream, 0);
	}
	if (errn == 0) {
		errn = encodeUnsignedInteger16(stream, (uint16_t)n);
	}
	return errn;
}

/**
 * Encode an arbitrary precision integer using a sign bit followed by a
 * sequence of octets. The most significant bit of the last octet is set to
 * zero to indicate sequence termination. Only seven bits per octet are used
 * to store the integer's value.
 */
int encodeInteger64(bitstream_t* stream, int64_t n) {
	int errn;
	/* signalize sign */
	if (n < 0) {
		errn = encodeBoolean(stream, 1);
		/* For negative values, the Unsigned Integer holds the
		 * magnitude of the value minus 1 */
		n = (-n) - 1;
	} else {
		errn = encodeBoolean(stream, 0);
	}
	if (errn == 0) {
		errn = encodeUnsignedInteger64(stream, (uint64_t)n);
	}
	return errn;
}


/**
 * Encode a sequence of characters according to a given length.
 * Each character is represented by its UCS [ISO/IEC 10646]
 * code point encoded as an Unsigned Integer
 */
int encodeCharacters(bitstream_t* stream, exi_string_character_t* chars, uint16_t len) {
	unsigned int i;
	int errn = 0;
	for (i = 0; i < len && errn == 0; i++) {
#if STRING_REPRESENTATION == STRING_REPRESENTATION_ASCII
		errn = encode(stream, (uint8_t)chars[i]);
#endif /* STRING_REPRESENTATION_ASCII */
#if STRING_REPRESENTATION == STRING_REPRESENTATION_UCS
		errn = encodeUnsignedInteger32(stream, chars[i]);
#endif /* STRING_REPRESENTATION_UCS */
	}
	return errn;
}

int encodeBytes(bitstream_t* stream, uint8_t* data, uint16_t len) {
	unsigned int i;
	int errn = 0;

	for (i = 0; i < len && errn == 0; i++) {
		errn = encode(stream, data[i]);
	}
	return errn;
}
