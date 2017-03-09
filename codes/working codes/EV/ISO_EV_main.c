/*
 * ISO_main.c
 *
 *  Created on: 03.01.2016
 *      Author: melanie
 */

# include <stdio.h>
# include <netinet/in.h>
# include <sys/types.h>
# include <sys/socket.h>

# include "ISO_EV_main.h"
# include "PWMSignal.h"


int ISO_start(int socket_nummer, int fd){

	int errn =0;
	int selection = 0;
	/*DIN Test --> optional*/
	/*XMLDSIG Test --> optional*/
# if CODE_EXAMPLE == CODE_EXAMPLE_HARDWARE
	double UCP;
	set_Ucp(fd, 1); // 9V --> Status C: EV detected
	UCP = get_Ucp(fd);
	printf("+++ change level on CP for state B: EV detected, %f +++\n\n", UCP);
# endif

	printf("+++ Start application handshake protocol example +++\n\n");
		errn = appHandshake(socket_nummer);
		printf("+++ Terminate application handshake protocol example +++\n\n");
		errn =0;

		if(errn != 0) {
			printf("\n\nHandshake error %d!\n", errn);
			return errn;
		}

	while ((selection != 1)&&(selection != 2)&&(selection != 3)){
	printf("choose between AC-Charging[1], DC-Chargiung[2] or exit [3]:  ");
	scanf("%d", &selection);
	}
	switch(selection){
		case 1: 	printf("\n+++ Start V2G client / service example for AC charging +++\n\n");
					errn = ac_charging(socket_nummer, fd);
					printf("\n+++Terminate V2G Client / Service example for AC charging +++\n");
					break;
		case 2: 	printf("+++ Start V2G client / service example for DC charging +++\n\n");
					errn = dc_charging(socket_nummer, fd);
					printf("\n+++Terminate V2G client / service example for DC charging +++\n");
					break;
		case 3: printf("3 \n"); break;

	}

	return errn;

}


int appHandshake(int socket) {
	struct appHandEXIDocument handshake;
	struct appHandEXIDocument handshakeResp;
	bitstream_t stream1;
	bitstream_t stream2;
	uint16_t pos1 = V2GTP_HEADER_LENGTH; /* v2gtp header */
	uint16_t pos2 = 0;
	uint16_t payloadLengthDec;


	uint8_t buffer1[BUFFER_SIZE];
	uint8_t buffer2[BUFFER_SIZE];


	stream1.size = BUFFER_SIZE;
	stream1.data = buffer1;
	stream1.pos = &pos1;

	stream2.size = BUFFER_SIZE;
	stream2.data = buffer2;
	stream2.pos = &pos2;

	int i;
	for (i=0;i<BUFFER_SIZE; i++) {
		stream1.data[i] = 0;
		stream2.data[i] = 0;
	}

	int errn = 0;

	char* ns0 = "urn:iso:15118:2:2010:MsgDef";
	char* ns1 = "urn:din:70121:2012:MsgDef";


	printf("EV side: setup data for the supported application handshake request message\n");

	/* set up ISO/IEC 15118 Version 1.0 information */
	handshake.supportedAppProtocolRes_isUsed = 0u;
	handshake.supportedAppProtocolReq_isUsed = 1u;
	handshake.supportedAppProtocolReq.AppProtocol.arrayLen = 2; /* we have only two protocols implemented */

	handshake.supportedAppProtocolReq.AppProtocol.array[0].ProtocolNamespace.charactersLen =
			writeStringToEXIString(ns0, handshake.supportedAppProtocolReq.AppProtocol.array[0].ProtocolNamespace.characters);
	handshake.supportedAppProtocolReq.AppProtocol.array[0].SchemaID = 1;
	handshake.supportedAppProtocolReq.AppProtocol.array[0].VersionNumberMajor = 1;
	handshake.supportedAppProtocolReq.AppProtocol.array[0].VersionNumberMinor = 0;
	handshake.supportedAppProtocolReq.AppProtocol.array[0].Priority = 1;

	handshake.supportedAppProtocolReq.AppProtocol.array[1].ProtocolNamespace.charactersLen =
			writeStringToEXIString(ns1, handshake.supportedAppProtocolReq.AppProtocol.array[1].ProtocolNamespace.characters);
	handshake.supportedAppProtocolReq.AppProtocol.array[1].SchemaID = 2;
	handshake.supportedAppProtocolReq.AppProtocol.array[1].VersionNumberMajor = 1;
	handshake.supportedAppProtocolReq.AppProtocol.array[1].VersionNumberMinor = 0;
	handshake.supportedAppProtocolReq.AppProtocol.array[1].Priority = 2;
	/* send app handshake request */
	if( (errn = encode_appHandExiDocument(&stream1, &handshake)) == 0) {
		if ( write_v2gtpHeader(stream1.data, pos1-V2GTP_HEADER_LENGTH, V2GTP_EXI_TYPE) == 0 ) {
			printf("EV side: send message to the EVSE\n");
			errn = transmit_message(socket,& stream1);
		}
	}
	/* read app handshake request & generate response *///EVSE///////////////////////////

	errn = receive_message(socket,&stream2);
	printf("EV side: received message from the EVSE \n");

	if (errn == 0) {
		/* check response */
		if ( (errn = read_v2gtpHeader(stream2.data, &payloadLengthDec)) == 0) {
			pos2 = V2GTP_HEADER_LENGTH;
			if((errn ==0 ) && (decode_appHandExiDocument(&stream2, &handshakeResp) == 0)) {
				printf("EV side: Response of the EVSE \n");
				if(handshakeResp.supportedAppProtocolRes.ResponseCode == appHandresponseCodeType_OK_SuccessfulNegotiation) {
					printf("\t\tResponseCode=OK_SuccessfulNegotiation\n");
					printf("\t\tSchemaID=%d\n",handshakeResp.supportedAppProtocolRes.SchemaID);
				}
			}
		}
	}

	if (errn != 0) {
		printf("appHandshake error %d \n", errn);
	}
	return errn;
}


void printBinaryArray(uint8_t* byte, uint16_t len) {
	unsigned int i;
	for(i=0; i<len; i++) {
		printf("%d ",byte[i]);
	}
	printf("\n");
}
void printASCIIString(exi_string_character_t* string, uint16_t len) {
	unsigned int i;
	for(i=0; i<len; i++) {
		printf("%c",(char)string[i]);
	}
	printf("\n");
}
