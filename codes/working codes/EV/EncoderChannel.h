/*
 * EncoderChannel.h
 *
 *  Created on: 03.01.2016
 *      Author: melanie
 */

#ifndef ISO_COMM_CODEC_ENCODERCHANNEL_H_
#define ISO_COMM_CODEC_ENCODERCHANNEL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "EXITypes.h"

/**
 * \brief 		Encode byte value
 *
 * \param       stream   		Output Stream
 * \param       b		   		byte
 * \return                  	Error-Code <> 0
 *
 */
int encode(bitstream_t* stream, uint8_t b);

/**
 * \brief 		Encode a single boolean value
 *
 * 				A false value is encoded as 0 and true value is encode as 1.
 *
 * \param       stream   		Output Stream
 * \param       b		   		boolean
 * \return                  	Error-Code <> 0
 *
 */
int encodeBoolean(bitstream_t* stream, int b);

/**
 * \brief 		Encode n-bit unsigned integer
 *
 * 				The n least significant bits of parameter b starting with the
 * 				most significant, i.e. from left to right.
 *
 * \param       stream   		Output Stream
 * \param       nbits		   	number of bits
 * \param       val		   		value
 * \return                  	Error-Code <> 0
 *
 */
int encodeNBitUnsignedInteger(bitstream_t* stream, uint16_t nbits, uint32_t val);


/**
 * \brief 		Encode unsigned integer
 *
 * 				Encode an arbitrary precision non negative integer using
 * 				a sequence of octets. The most significant bit of the last
 * 				octet is set to zero to indicate sequence termination.
 * 				Only seven bits per octet are used to store the integer's value.
 *
 * \param       stream   		Output Stream
 * \param       n		   		Unsigned integer value 16 bits
 * \return                  	Error-Code <> 0
 *
 */
int encodeUnsignedInteger16(bitstream_t* stream, uint16_t n);

/**
 * \brief 		Encode unsigned integer
 *
 * 				Encode an arbitrary precision non negative integer using
 * 				a sequence of octets. The most significant bit of the last
 * 				octet is set to zero to indicate sequence termination.
 * 				Only seven bits per octet are used to store the integer's value.
 *
 * \param       stream   		Output Stream
 * \param       n		   		Unsigned integer value 32 bits
 * \return                  	Error-Code <> 0
 *
 */
int encodeUnsignedInteger32(bitstream_t* stream, uint32_t n);

/**
 * \brief 		Encode unsigned integer
 *
 * 				Encode an arbitrary precision non negative integer using
 * 				a sequence of octets. The most significant bit of the last
 * 				octet is set to zero to indicate sequence termination.
 * 				Only seven bits per octet are used to store the integer's value.
 *
 * \param       stream   		Output Stream
 * \param       n		   		Unsigned integer value 64 bits
 * \return                  	Error-Code <> 0
 *
 */
int encodeUnsignedInteger64(bitstream_t* stream, uint64_t n);

/**
 * \brief 		Encode integer
 *
 * 				Encode an arbitrary precision integer using a sign boolean
 * 				followed by a sequence of octets. The most significant bit
 * 				of the last octet is set to zero to indicate sequence termination.
 * 				Only seven bits per octet are used to store the integer's value.
 *
 * \param       stream   		Output Stream
 * \param       n		   		Integer value 16 bits
 * \return                  	Error-Code <> 0
 *
 */
int encodeInteger16(bitstream_t* stream, int16_t n);

/**
 * \brief 		Encode integer
 *
 * 				Encode an arbitrary precision integer using a sign boolean
 * 				followed by a sequence of octets. The most significant bit
 * 				of the last octet is set to zero to indicate sequence termination.
 * 				Only seven bits per octet are used to store the integer's value.
 *
 * \param       stream   		Output Stream
 * \param       n		   		Integer value 32 bits
 * \return                  	Error-Code <> 0
 *
 */
int encodeInteger32(bitstream_t* stream, int32_t n);

/**
 * \brief 		Encode integer
 *
 * 				Encode an arbitrary precision integer using a sign boolean
 * 				followed by a sequence of octets. The most significant bit
 * 				of the last octet is set to zero to indicate sequence termination.
 * 				Only seven bits per octet are used to store the integer's value.
 *
 * \param       stream   		Output Stream
 * \param       n		   		Integer value 64 bits
 * \return                  	Error-Code <> 0
 *
 */
int encodeInteger64(bitstream_t* stream, int64_t n);

/**
 * \brief 		Encode characters
 *
 * 				Encode a sequence of characters according to a given length.
 * 				Each character is represented by its UCS [ISO/IEC 10646]
 * 				code point encoded as an Unsigned Integer.
 *
 * \param       stream   		Output Stream
 * \param       chars   		Characters
 * \param       len				Numbr of characters
 * \return                  	Error-Code <> 0
 *
 */
int encodeCharacters(bitstream_t* stream, exi_string_character_t* chars, uint16_t len);

/**
 * \brief 		Encode binary data
 *
 * 				Encode a sequence of octets.
 *
 * \param       stream   		Output Stream
 * \param       data	   		Byte values
 * \param       len		   		Length
 * \return                  	Error-Code <> 0
 *
 */
int encodeBytes(bitstream_t* stream, uint8_t* data, uint16_t len);

/**
 * \brief 		Flush underlying bit output stream
 *
 * \param       stream   		Output Stream
 * \return                  	Error-Code <> 0
 *
 */
int encodeFinish(bitstream_t* stream);

#endif /* ISO_COMM_CODEC_ENCODERCHANNEL_H_ */
