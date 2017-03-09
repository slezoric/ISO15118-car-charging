/*
 * Convert.h
 *
 *  Created on: 06.01.2016
 *      Author: melanie
 */

#ifndef ISO_COMM_CODEC_CONVERT_H_
#define ISO_COMM_CODEC_CONVERT_H_

# include "EXITypes.h"
# include "v2gEXIDatatypes.h"

int writeStringToEXIString(char* string, exi_string_character_t* exiString);

int serializeEXI2Stream(struct v2gEXIDocument* exiIn, bitstream_t* stream, int socket_nummer);

int deserializeStream2EXI(bitstream_t* streamIn, struct v2gEXIDocument* exi);


#endif /* ISO_COMM_CODEC_CONVERT_H_ */
