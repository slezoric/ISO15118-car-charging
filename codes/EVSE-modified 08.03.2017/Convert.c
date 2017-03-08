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
# include "serversockets.h"
#include "v2gEXIDatatypes.h"
# include <netinet/in.h>


#define BUFFER_SIZE 256
uint8_t buffer[BUFFER_SIZE];

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
int serializeEXI2Stream(struct v2gEXIDocument* exiIn, int socket_nummer) {
	int errn;

	bitstream_t streamOut;
	uint16_t pos;
	streamOut.size = BUFFER_SIZE;
	streamOut.data = buffer;
	streamOut.pos = &pos;

	*streamOut.pos = V2GTP_HEADER_LENGTH;  /* v2gtp header */
	if( (errn = encode_v2gExiDocument(&streamOut, exiIn)) == 0) {
		errn = write_v2gtpHeader(streamOut.data, (*streamOut.pos)-V2GTP_HEADER_LENGTH, V2GTP_EXI_TYPE);
	}
	errn = transmit_message(socket_nummer, &streamOut);
	return errn;
}


/* deserializes V2G TP header and decodes right away EXI stream */
int deserializeStream2EXI(struct v2gEXIDocument* exi, int socket_nummer) {
	int errn;
	uint16_t payloadLength;

	bitstream_t streamIn;
	uint16_t pos;
	streamIn.size = BUFFER_SIZE;
	streamIn.data = buffer;
	streamIn.pos = &pos;

	errn = receive_message(socket_nummer, &streamIn);

	*streamIn.pos = 0;
	if ( (errn = read_v2gtpHeader(streamIn.data, &payloadLength)) == 0) {
		*streamIn.pos += V2GTP_HEADER_LENGTH;

		errn = decode_v2gExiDocument(&streamIn, exi);
	}

	return errn;
}

void printASCIIString(exi_string_character_t* string, uint16_t len) {
	unsigned int i;
	for(i=0; i<len; i++) {
		printf("%c",(char)string[i]);
	}
	printf("\n");
}

void printBinaryArray(uint8_t* byte, uint16_t len) {
	unsigned int i;
	for(i=0; i<len; i++) {
		printf("%d ",byte[i]);
	}
	printf("\n");
}
