/*
 * DecoderChannel.h
 *
 *  Created on: 04.01.2016
 *      Author: melanie
 */

#ifndef ISO_COMM_CODEC_DECODERCHANNEL_H_
#define ISO_COMM_CODEC_DECODERCHANNEL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "EXITypes.h"


/**
 * \brief 		Decode byte value
 *
 * \param       stream   		Input Stream
 * \param       b		   		byte (out)
 * \return                  	Error-Code <> 0
 *
 */
int decode(bitstream_t* stream, uint8_t* b);

/**
 * \brief 		Decode boolean
 *
 * 				Decode a single boolean value. The value false is
 * 				represented by 0, and the value true is represented by 1.
 *
 * \param       stream   		Input Stream
 * \param       b		   		boolean (out)
 * \return                  	Error-Code <> 0
 *
 */
int decodeBoolean(bitstream_t* stream, int* b);

/**
 * \brief 		Decode unsigned integer
 *
 * 				Decode an arbitrary precision non negative integer using
 * 				a sequence of octets. The most significant bit of the last
 * 				octet is set to zero to indicate sequence termination.
 * 				Only seven bits per octet are used to store the integer's value.
 *
 * \param       stream   		Input Stream
 * \param       uint16		   	Unsigned Integer Value 16 bits (out)
 * \return                  	Error-Code <> 0
 *
 */
int decodeUnsignedInteger16(bitstream_t* stream, uint16_t* uint16);

/**
 * \brief 		Decode unsigned integer
 *
 * 				Decode an arbitrary precision non negative integer using
 * 				a sequence of octets. The most significant bit of the last
 * 				octet is set to zero to indicate sequence termination.
 * 				Only seven bits per octet are used to store the integer's value.
 *
 * \param       stream   		Input Stream
 * \param       uint32		   	Unsigned Integer Value 32 bits (out)
 * \return                  	Error-Code <> 0
 *
 */
int decodeUnsignedInteger32(bitstream_t* stream, uint32_t* uint32);

/**
 * \brief 		Decode unsigned integer
 *
 * 				Decode an arbitrary precision non negative integer using
 * 				a sequence of octets. The most significant bit of the last
 * 				octet is set to zero to indicate sequence termination.
 * 				Only seven bits per octet are used to store the integer's value.
 *
 * \param       stream   		Input Stream
 * \param       uint64		   	Unsigned Integer Value 64 bits (out)
 * \return                  	Error-Code <> 0
 *
 */
int decodeUnsignedInteger64(bitstream_t* stream, uint64_t* uint64);

/**
 * \brief 		Decode n-bit unsigned integer
 *
 * 				Decodes and returns an n-bit unsigned integer.
 *
 * \param       stream   		Input Stream
 * \param       nbits		   	Number of bits
 * \param       uint32		   	Value (out)
 * \return                  	Error-Code <> 0
 *
 */
int decodeNBitUnsignedInteger(bitstream_t* stream, uint16_t nbits, uint32_t* uint32);

/**
 * \brief 		Decode integer
 *
 * 				Decode an arbitrary precision integer using a sign bit
 * 				followed by a sequence of octets. The most significant bit
 * 				of the last octet is set to zero to indicate sequence termination.
 * 				Only seven bits per octet are used to store the integer's value.
 *
 * \param       stream   		Input Stream
 * \param       int16		   	Integer Value 16 bits (out)
 * \return                  	Error-Code <> 0
 *
 */
int decodeInteger16(bitstream_t* stream, int16_t* int16);

/**
 * \brief 		Decode integer
 *
 * 				Decode an arbitrary precision integer using a sign bit
 * 				followed by a sequence of octets. The most significant bit
 * 				of the last octet is set to zero to indicate sequence termination.
 * 				Only seven bits per octet are used to store the integer's value.
 *
 * \param       stream   		Input Stream
 * \param       int32		   	Integer Value 32 bits (out)
 * \return                  	Error-Code <> 0
 *
 */
int decodeInteger32(bitstream_t* stream, int32_t* int32);

/**
 * \brief 		Decode integer
 *
 * 				Decode an arbitrary precision integer using a sign bit
 * 				followed by a sequence of octets. The most significant bit
 * 				of the last octet is set to zero to indicate sequence termination.
 * 				Only seven bits per octet are used to store the integer's value.
 *
 * \param       stream   		Input Stream
 * \param       int64		   	Integer Value 64 bits (out)
 * \return                  	Error-Code <> 0
 *
 */
int decodeInteger64(bitstream_t* stream, int64_t* int64);

/**
 * \brief 		Decode characters
 *
 * 				Decode a sequence of characters according to a given length.
 *
 * \param       stream   		Input Stream
 * \param       len		   		Length
 * \param       chars   		Characters (out)
 * \return                  	Error-Code <> 0
 *
 */
int decodeCharacters(bitstream_t* stream, uint16_t len, exi_string_character_t* chars);

/**
 * \brief 		Decode Binary data
 *
 * 				Decode a sequence of octets.
 *
 * \param       stream   		Input Stream
 * \param       len		   		Length
 * \param       data	   		Bytes (out)
 * \return                  	Error-Code <> 0
 *
 */
int decodeBytes(bitstream_t* stream, uint16_t len, uint8_t* data);

#endif /* ISO_COMM_CODEC_DECODERCHANNEL_H_ */
