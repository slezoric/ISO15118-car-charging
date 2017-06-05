/*
 * BitInputStream.h
 *
 *  Created on: 04.01.2016
 *      Author: melanie
 */

#ifndef ISO_COMM_CODEC_BITINPUTSTREAM_H_
#define ISO_COMM_CODEC_BITINPUTSTREAM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "EXITypes.h"

/**
 * \brief 		Read bits
 *
 * 				Read the next num_bits bits and returns result an integer.
 *
 * \param       stream   		Input Stream
 * \param       num_bits		Number of bits
 * \param       b		   		Integer value (out)
 * \return                  	Error-Code <> 0
 *
 */
int readBits(bitstream_t* stream, uint16_t num_bits, uint32_t* b);


#ifdef __cplusplus
}
#endif




#endif /* ISO_COMM_CODEC_BITINPUTSTREAM_H_ */
