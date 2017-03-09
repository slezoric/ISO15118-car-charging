/*
 * Convert.c
 *
 *  Created on: 06.01.2016
 *      Author: melanie
 */

# include "Convert.h"
# include "EncoderChannel.h"
# include "DecoderChannel.h"
# include "v2gtp.h"
# include "v2gEXIDatatypesDecoder.h"
# include "v2gEXIDatatypesEncoder.h"
# include "clientsockets.h"

int writeStringToEXIString(char* string, exi_string_character_t* exiString) {
	int pos = 0;
	while(string[pos]!='\0')
	{
		exiString[pos] = string[pos];
		pos++;
	}

	return pos;
}

/* serializes EXI stream and adds V2G TP header */
int serializeEXI2Stream(struct v2gEXIDocument* exiIn, bitstream_t* stream, int socket_number) {
	int errn;
	*stream->pos = V2GTP_HEADER_LENGTH;  /* v2gtp header */
	if( (errn = encode_v2gExiDocument(stream, exiIn)) == 0) {
		errn = write_v2gtpHeader(stream->data, (*stream->pos)-V2GTP_HEADER_LENGTH, V2GTP_EXI_TYPE);
	}
	return errn;
}


/* deserializes V2G TP header and decodes right away EXI stream */
int deserializeStream2EXI(bitstream_t* streamIn, struct v2gEXIDocument* exi) {
	int errn;
	uint16_t payloadLength;

	*streamIn->pos = 0;
	if ( (errn = read_v2gtpHeader(streamIn->data, &payloadLength)) == 0) {
		*streamIn->pos += V2GTP_HEADER_LENGTH;

		errn = decode_v2gExiDocument(streamIn, exi);
	}
	return errn;
}
