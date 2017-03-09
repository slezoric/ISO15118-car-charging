/*
 * EXITypes.h
 *
 *  Created on: 03.01.2016
 *      Author: melanie
 */

#ifndef ISO_COMM_CODEC_EXITYPES_H_
#define ISO_COMM_CODEC_EXITYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#if EXI_STREAM == FILE_STREAM
#include <stdio.h>
#include "EXIConfig.h"
#endif

/** Number of bits for each byte */
#define BITS_IN_BYTE 8


/**
 * \brief 	Bit stream container
 *
 *	Structure for byteArray/file stream.
 *
 *	# General
 *	.size defines the maximum size of the byte array (see .data)
 *
 *	.data points to the input/output array of bytes (unsigned char*).
 *
 *	.pos has to be set to an pointer to an 32 bit long unsigned integer (uint32_t *)
 *	 as this variable is read/write.
 *	 Therefore it is best practice to declare the variable itself and use the &-operator
 *	 to assign the address. The value of that variable points to the position inside the
 *	 buffer where the stream begins. Which is usually the first (0th) byte but can also be
 *	 another value if there more information transferred in that stream.
 *	 After processing .pos points to the next "available" byte (if any left).
 *
 *	.buffer has to be set to 0 for internal use only (single byte buffer)
 *
 *	# Receiving data (input)
 *	.capacity is used for addressing single bits in the actual byte (see .buffer)
 *	 and has to be set to 0, which means there are 0 bits read so far and a new
 *	 byte needs to be read from the input stream/data-array to the current byte buffer.
 *
 *	# Sending data (output)
 *	.capacity is used for addressing single bits in the actual byte (see .buffer)
 *	 and has to be set to 8, which means there are still 8 bits left to fill up
 *	 the current byte buffer before writing the final byte to the output stream/data-array.
 *
 */
typedef struct {
#if EXI_STREAM == BYTE_ARRAY
	/**	byte array size */
	uint16_t size;
	/**	byte array data */
	uint8_t* data;
	/**	byte array next position in array */
	uint16_t* pos;
#endif
#if EXI_STREAM == FILE_STREAM
	/** file pointer */
	FILE *file;
#endif
	/** Current byte buffer*/
	uint8_t buffer;
	/** Remaining bit capacity in current byte buffer*/
	uint8_t capacity;
} bitstream_t;

/** \brief EXI string character */
/* Note: define whether you wan't to support ASCII only or UCS */
#if STRING_REPRESENTATION == STRING_REPRESENTATION_ASCII
typedef char exi_string_character_t;
#endif /* STRING_REPRESENTATION_ASCII */
#if STRING_REPRESENTATION == STRING_REPRESENTATION_UCS
typedef uint32_t exi_string_character_t;
#endif /* STRING_REPRESENTATION_UCS */





#endif /* ISO_COMM_CODEC_EXITYPES_H_ */
