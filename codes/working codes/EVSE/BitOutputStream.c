/*
 * BitOutputStream.c
 *
 *  Created on: 03.01.2016
 *      Author: melanie
 */


#include "BitOutputStream.h"


#ifndef BIT_OUTPUT_STREAM_C
#define BIT_OUTPUT_STREAM_C

int writeBits(bitstream_t* stream, uint16_t nbits, uint32_t val) {
	int errn = 0;
	/*  is there enough space in the buffer */
	if (nbits <= stream->capacity) {
		/* all bits fit into the current buffer */
		stream->buffer = (uint8_t)(stream->buffer << (nbits)) | (uint8_t)(val & (uint32_t)(0xff >> (uint32_t)(BITS_IN_BYTE - nbits)));
		stream->capacity = (uint8_t)(stream->capacity - nbits);
		/* if the buffer is full write byte */
		if (stream->capacity == 0) {
#if EXI_STREAM == BYTE_ARRAY
			if ((*stream->pos) >= stream->size) {
				errn = EXI_ERROR_OUTPUT_STREAM_EOF;
			} else {
				stream->data[(*stream->pos)++] = stream->buffer;
			}
#endif
#if EXI_STREAM == FILE_STREAM
			if ( putc(stream->buffer, stream->file) == EOF ) {
				errn = EXI_ERROR_OUTPUT_STREAM_EOF;
			}
#endif
			stream->capacity = BITS_IN_BYTE;
			stream->buffer = 0;
		}
	} else {
		/* the buffer is not enough
		 * fill the buffer */
		stream->buffer = (uint8_t)(stream->buffer << stream->capacity) |
				( (uint8_t)(val >> (nbits - stream->capacity)) & (uint8_t)(0xff >> (BITS_IN_BYTE - stream->capacity)) );

		nbits = (uint16_t)(nbits - stream->capacity);
#if EXI_STREAM == BYTE_ARRAY
		if ((*stream->pos) >= stream->size) {
			errn = EXI_ERROR_OUTPUT_STREAM_EOF;
		} else {
			stream->data[(*stream->pos)++] = stream->buffer;
		}
#endif
#if EXI_STREAM == FILE_STREAM
		if ( putc(stream->buffer, stream->file) == EOF ) {
			errn = EXI_ERROR_OUTPUT_STREAM_EOF;
		}
#endif
		stream->buffer = 0;

		/* write whole bytes */
		while (errn == 0 && nbits >= BITS_IN_BYTE) {
			nbits = (uint16_t)(nbits - BITS_IN_BYTE);
#if EXI_STREAM == BYTE_ARRAY
			if ((*stream->pos) >= stream->size) {
				errn = EXI_ERROR_OUTPUT_STREAM_EOF;
			} else {
				stream->data[(*stream->pos)++] = (uint8_t)(val >> (nbits));
			}
#endif
#if EXI_STREAM == FILE_STREAM
			if ( putc((int)(val >> (nbits)), stream->file) == EOF ) {
				errn = EXI_ERROR_OUTPUT_STREAM_EOF;
			}
#endif
		}

		/* spared bits are kept in the buffer */
		stream->buffer = (uint8_t)val; /* Note: the high bits will be shifted out during further filling */
		stream->capacity = (uint8_t)(BITS_IN_BYTE - (nbits));
	}

	return errn;
}

/**
 * Flush output
 */
int flush(bitstream_t* stream) {
	int errn = 0;
	if (stream->capacity == BITS_IN_BYTE) {
		/* nothing to do, no bits in buffer */
	} else {
		errn = writeBits(stream, stream->capacity, 0);
	}
	return errn;
}

#endif
