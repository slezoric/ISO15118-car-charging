/*
 * appHandEXIDatatypesDecoder.h
 *
 *  Created on: 03.01.2016
 *      Author: melanie
 */

#ifndef ISO_COMM_APPHANDSHAKE_APPHANDEXIDATATYPESDECODER_H_
#define ISO_COMM_APPHANDSHAKE_APPHANDEXIDATATYPESDECODER_H_


#include <stdint.h>

#include "EXITypes.h"
#include "appHandEXIDatatypes.h"

int decode_appHandExiDocument(bitstream_t* stream, struct appHandEXIDocument* exiDoc);

#ifdef __cplusplus
}
#endif



#endif /* ISO_COMM_APPHANDSHAKE_APPHANDEXIDATATYPESDECODER_H_ */
