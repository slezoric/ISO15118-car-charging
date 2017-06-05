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

int serializeEXI2Stream(struct v2gEXIDocument* exiIn, int socket_nummer);

int deserializeStream2EXI(struct v2gEXIDocument* exi, int socket_nummer);

void printASCIIString(exi_string_character_t* string, uint16_t len);

void printBinaryArray(uint8_t* byte, uint16_t len);


#endif /* ISO_COMM_CODEC_CONVERT_H_ */
