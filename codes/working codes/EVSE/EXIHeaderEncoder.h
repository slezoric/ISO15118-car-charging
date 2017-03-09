/*
 * EXIHeaderEncoder.h
 *
 *  Created on: 03.01.2016
 *      Author: melanie
 */


#ifndef ISO_COMM_CODEC_EXIHEADERENCODER_H_
#define ISO_COMM_CODEC_EXIHEADERENCODER_H_

#include "EXITypes.h"


#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief 		Writes EXI header
 *
 * \param       stream   		Output Stream
 * \return                  	Error-Code <> 0
 *
 */
int writeEXIHeader(bitstream_t* stream);




#endif /* ISO_COMM_CODEC_EXIHEADERENCODER_H_ */
