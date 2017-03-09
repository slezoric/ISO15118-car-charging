/*
 * EXIHeaderDecoder.h
 *
 *  Created on: 04.01.2016
 *      Author: melanie
 */

#ifndef ISO_COMM_CODEC_EXIHEADERDECODER_H_
#define ISO_COMM_CODEC_EXIHEADERDECODER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "EXITypes.h"

/**
 * \brief 		Reads EXI header
 *
 * \param       stream   		Input Stream
 * \return                  	Error-Code <> 0
 *
 */
int readEXIHeader(bitstream_t* stream);

#ifdef __cplusplus
}
#endif



#endif /* ISO_COMM_CODEC_EXIHEADERDECODER_H_ */
