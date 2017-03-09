/*
 * BitOutputStream.h
 *
 *  Created on: 03.01.2016
 *      Author: melanie
 */

#ifndef ISO_COMM_CODEC_BITOUTPUTSTREAM_H_
#define ISO_COMM_CODEC_BITOUTPUTSTREAM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

# include "EXITypes.h"
# include "ErrorCodes.h"

/**
 * \brief 		Write bits
 *
 * 				Write the n least significant bits of parameter b starting
 * 				with the most significant, i.e. from left to right.
 *
 * \param       stream   		Output Stream
 * \param       nbits			Number of bits
 * \param       bits		   	value
 * \return                  	Error-Code <> 0
 *
 */
int writeBits(bitstream_t* stream, uint16_t nbits, uint32_t bits);

/**
 * \brief 		Flush output
 *
 * 				If there are some unwritten bits, pad them if necessary and
 * 				write them out. Note that this method does flush the
 * 				underlying stream.
 *
 * \param       stream   		Output Stream
 * \return                  	Error-Code <> 0
 *
 */
int flush(bitstream_t* stream);


#ifdef __cplusplus
}
#endif

#endif /* ISO_COMM_CODEC_BITOUTPUTSTREAM_H_ */
