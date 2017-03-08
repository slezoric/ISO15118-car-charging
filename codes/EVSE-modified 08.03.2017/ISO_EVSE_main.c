/*
 * ISO_main.c
 *
 *  Created on	: 03.01.2016
 *      Author	: melanie
 *  Modified by :Jiztom Francis K 
 * 	Modified on : 07.03.2017
 * 
 */

# include <stdio.h>
# include <netinet/in.h>
#include "ISO_EVSE_main.h"
# include "appHandEXIDatatypes.h"

# include "v2gtp.h"
# include "Convert.h"
# include "appHandEXIDatatypesDecoder.h"
#include "appHandEXIDatatypesEncoder.h"
#include "serversockets.h"
# include "response.h"
# include "hardware.h"

# include <sys/types.h>
# include <sys/socket.h>

#include "transfer.h"

#define BUFFER_SIZE 256

static int next_state;
static int charging_state;
static 	int basic_state;



int appHandshake(int socket_number) {

	bitstream_t iStream;
	bitstream_t oStream;

	uint16_t payloadLengthDec;
	uint16_t pos1 = V2GTP_HEADER_LENGTH; /* v2gtp header */
	uint16_t pos2 = 0;

	int errn, i;
	uint8_t buffer1[BUFFER_SIZE];
	uint8_t buffer2[BUFFER_SIZE];

	iStream.size = BUFFER_SIZE;
	iStream.data = buffer1;
	iStream.pos = &pos1;


	oStream.size = BUFFER_SIZE;
	oStream.data = buffer2;
	oStream.pos = &pos2;


	struct appHandEXIDocument appHandResp;
	struct appHandEXIDocument exiDoc;

	errn = receive_message(socket_number, &iStream);
	if ( (errn = read_v2gtpHeader(iStream.data, &payloadLengthDec)) == 0) {
	*iStream.pos = V2GTP_HEADER_LENGTH;
		if( (errn = decode_appHandExiDocument(&iStream, &exiDoc)) ) {
			/* an error occured */
			return errn;
		}


	}
	printf("EVSE side: List of application handshake protocols of the EV\n");

	for(i=0;i<exiDoc.supportedAppProtocolReq.AppProtocol.arrayLen;i++) {
		printf("\tProtocol entry #=%d\n",(i+1));
		printf("\t\tProtocolNamespace=");
		printASCIIString(exiDoc.supportedAppProtocolReq.AppProtocol.array[i].ProtocolNamespace.characters, exiDoc.supportedAppProtocolReq.AppProtocol.array[i].ProtocolNamespace.charactersLen);
		printf("\t\tVersion=%d.%d\n", exiDoc.supportedAppProtocolReq.AppProtocol.array[i].VersionNumberMajor, exiDoc.supportedAppProtocolReq.AppProtocol.array[i].VersionNumberMinor);
		printf("\t\tSchemaID=%d\n", exiDoc.supportedAppProtocolReq.AppProtocol.array[i].SchemaID);
		printf("\t\tPriority=%d\n", exiDoc.supportedAppProtocolReq.AppProtocol.array[i].Priority);
	}

	/* prepare response handshake response:
	 * it is assumed, we support the 15118 1.0 version :-) */
	 
	sendd( sockfd, PROTOCOL_DETECT);
	///////--------->>>>> event PROTOCOL_DETECTED
	 
	appHandResp.supportedAppProtocolReq_isUsed = 0u;
	appHandResp.supportedAppProtocolRes_isUsed = 1u;
	appHandResp.supportedAppProtocolRes.ResponseCode = appHandresponseCodeType_OK_SuccessfulNegotiation;
	appHandResp.supportedAppProtocolRes.SchemaID = exiDoc.supportedAppProtocolReq.AppProtocol.array[0].SchemaID; /* signal the protocol by the provided schema id*/
	appHandResp.supportedAppProtocolRes.SchemaID_isUsed = 1u;


	*oStream.pos = V2GTP_HEADER_LENGTH;
	if( (errn = encode_appHandExiDocument(&oStream, &appHandResp)) == 0) {
		errn = write_v2gtpHeader(oStream.data, (*oStream.pos)-V2GTP_HEADER_LENGTH, V2GTP_EXI_TYPE);
		printf("EVSE side: send response to the EV\n");
		errn = transmit_message(socket_number, &oStream);
	}

	/*init static state machine params*/
	next_state = STATE_B1_SESSION_SETUP;
	charging_state = 0;

	return errn;
}


int Communication_State_B1(int socket_number,struct v2gEXIDocument* Input, struct v2gEXIDocument* Output){
	int errn = 0;
	char parameter[100] ;
	
	errn = deserializeStream2EXI(Input, socket_number);

	if((errn == 0) && (Input->V2G_Message_isUsed)) {
		init_v2gEXIDocument(Output);
		switch (next_state){
		case  STATE_B1_SESSION_SETUP:
			if (Input->V2G_Message.Body.SessionSetupReq_isUsed) {
				errn = sessionSetup(Input, Output);
				next_state = STATE_B1_SERVICE_DICOVERY;
				basic_state = STATE_B1;
			}
			break;

		case  STATE_B1_SERVICE_DICOVERY:
			if (Input->V2G_Message.Body.ServiceDiscoveryReq_isUsed) {
				errn = serviceDiscovery(Input, Output);
				next_state = STATE_B1_SERVICE_AND_PAYMENT_SELECTION;
				basic_state = STATE_B1;
			}
			break;

		case  STATE_B1_SERVICE_AND_PAYMENT_SELECTION:
			if (Input->V2G_Message.Body.ServiceDetailReq_isUsed) {
				errn = serviceDetail(Input, Output);
				basic_state = STATE_B1;
			} else if (Input->V2G_Message.Body.PaymentServiceSelectionReq_isUsed) {
				errn = paymentServiceSelection(Input, Output);
				next_state = STATE_B1_PAYMENT_DETAILS;
				basic_state = STATE_B1;
				sendd(sockfd , REGISTER);
			/////------>>>>> event REGISTER
			}
			break;

		case  STATE_B1_PAYMENT_DETAILS:
			if (Input->V2G_Message.Body.CertificateInstallationReq_isUsed){
				basic_state = STATE_B1;
				//missing request
			}else if (Input->V2G_Message.Body.CertificateUpdateReq_isUsed){
				basic_state = STATE_B1;
				//missing request
			} else if (Input->V2G_Message.Body.PaymentDetailsReq_isUsed) {
				errn = paymentDetails(Input, Output);
				next_state = STATE_B1_CONTRACT_AUTHENTICATION;
				basic_state = STATE_B1;
			} break;

		case  STATE_B1_CONTRACT_AUTHENTICATION:
			if (Input->V2G_Message.Body.AuthorizationReq_isUsed) {
				errn = authorization(Input, Output);
				next_state = STATE_B1_CHARGE_PARAMETER_DISCOVERY;
				basic_state = STATE_B1;
				do
				{
					parameter = receivee(sockfd , &code , &value)
				}while(strcmp(parameter,AUTHORIZATION) != 1); 
			/////----->>>>> event AUTHORIZATION
			}
			break;

		case  STATE_B1_CHARGE_PARAMETER_DISCOVERY:
			if (Input->V2G_Message.Body.ChargeParameterDiscoveryReq_isUsed) {
				errn = chargeParameterDiscovery(Input, Output);
				if(Input->V2G_Message.Body.ChargeParameterDiscoveryReq.AC_EVChargeParameter_isUsed){
					next_state = STATE_C_BEGIN_POWER_DELIVERY;
					charging_state = AC_CHARGING;
					basic_state = STATE_C;
				} else {
					next_state = STATE_C_DC_CABLE_CHECK;
					charging_state = DC_CHARGING;
					basic_state = STATE_C;
				}
			do
			{
				parameter = receivee(sockfd , &code ,&value);
			}while(strcmp(parameter,START_CHARGE) != 1) ;
			/////----->>>>> event START_CHARGE
			}
			break;
		}
	}
	if (errn == 0){
		errn = serializeEXI2Stream(Output, socket_number);
	}
	if (errn == 0){
	return basic_state;
	} else return STATE_ERROR;
}

int Communication_State_C(int fd, int socket_number,struct v2gEXIDocument* Input, struct v2gEXIDocument* Output){

	int errn;
	errn = deserializeStream2EXI(Input, socket_number);

	switch (next_state){
	case STATE_C_BEGIN_POWER_DELIVERY:
		if (charging_state == AC_CHARGING){
			do{
				errn = Close_Contractors(fd);
			} while (errn !=0);

			errn = powerDelivery(Input, Output);
			next_state = STATE_C_AC_CHARGING_STATUS;
			basic_state = STATE_C;
		} else if (charging_state == DC_CHARGING){
			if (Input->V2G_Message.Body.PowerDeliveryReq_isUsed){
				do{
					errn = Close_Contractors(fd);
				} while (errn !=0);
				errn = powerDelivery(Input, Output);
				next_state = STATE_C_DC_CURRENT_DEMAND;
				basic_state = STATE_C;
			} else if (Input->V2G_Message.Body.PreChargeReq_isUsed){
				errn = preCharge(Input, Output);
			}
		}
		break;

	case STATE_C_AC_CHARGING_STATUS:
		if (Input->V2G_Message.Body.ChargingStatusReq_isUsed) {
			errn = chargingStatus(Input, Output);
			sendd(sockfd , CHARGING_STATUS);
			/////----->>>>> event CHARGING_STATUS
			next_state = STATE_C_END_POWER_DELIVERY;
			basic_state = STATE_C;
		}
		break;
	case STATE_C_DC_CABLE_CHECK:
		if (Input->V2G_Message.Body.CableCheckReq_isUsed){
			errn = cableCheck(Input, Output);
			next_state = STATE_C_DC_PRE_CHARGE;
			basic_state = STATE_C;
		}
		break;

	case STATE_C_DC_PRE_CHARGE:
		if (Input->V2G_Message.Body.CableCheckReq_isUsed){
			errn = cableCheck(Input, Output);
		} else if (Input->V2G_Message.Body.PreChargeReq_isUsed){
			errn = preCharge(Input, Output);
			next_state = STATE_C_BEGIN_POWER_DELIVERY;
			basic_state = STATE_C;
		}
		break;

	case STATE_C_DC_CURRENT_DEMAND:
		if(Input->V2G_Message.Body.CurrentDemandReq_isUsed){
			errn = currentDemand(Input, Output);
			next_state = STATE_C_END_POWER_DELIVERY;
			basic_state = STATE_C;
		}
		break;
	case STATE_C_END_POWER_DELIVERY:
		if (charging_state == AC_CHARGING){
			parameter = 0;
			if (Input->V2G_Message.Body.ChargingStatusReq_isUsed) {
				errn = chargingStatus(Input, Output);
			} else if (Input->V2G_Message.Body.MeteringReceiptReq_isUsed) {
				errn = meteringReceipt(Input, Output);
				sendd(sockfd , METER_RECEIPT);
				/////----->>>>> event METERING RECEIPT
			} else if (Input->V2G_Message.Body.PowerDeliveryReq_isUsed){
				do{
					errn = Open_Contractors(fd);
					
						
				} while (errn !=0);
				do
				{
						parameter = receivee(sockfd, &code, &value);
						////////full cahrge condition//////////
				}while(strcmp(parameter, MANUAL_STOP)!=1);
				errn = powerDelivery(Input, Output);
				next_state = STATE_B2_SESSION_STOP;
				basic_state = STATE_B2;
			}
		} else if (charging_state == DC_CHARGING){
			if(Input->V2G_Message.Body.CurrentDemandReq_isUsed){
				errn = currentDemand(Input, Output);
			} else if (Input->V2G_Message.Body.PowerDeliveryReq_isUsed){
				do{
					errn = Open_Contractors(fd);
				} while (errn !=0);

				errn = powerDelivery(Input, Output);
				next_state = STATE_B2_DC_WELDING_DETECTION;
				basic_state = STATE_B2;
			}
		}
		break;

	default: errn = STATE_ERROR; break;
	}
	if (errn ==0){
		errn = serializeEXI2Stream(Output, socket_number);
	}
	if (errn ==0){
		return basic_state;
	} else return errn;
}


int Communication_State_B2(int socket_number,struct v2gEXIDocument* Input, struct v2gEXIDocument* Output){
	int errn;
	errn = deserializeStream2EXI(Input, socket_number);

	switch (next_state){
	case STATE_B2_SESSION_STOP:
		if (Input->V2G_Message.Body.SessionStopReq_isUsed) {
			errn = sessionStop(Input, Output);
			sendd(sockfd , INITIATE_PAYMENT);/////----->>>>> event INTIATE_PAYMENT
			/////----->>>>> event PAYMENT_SUCCESSFUL
			/////----->>>>> event PAYMENT_UNSUCCESSFUL
			do
			{
				parameter = receivee(sockfd , &value , &code );
			} while (strcmp(parameter,PAYMENT_SUCESSFUL)!=1);
			next_state = 0;
			basic_state = STATE_A;
		}
		break;
		
	case STATE_B2_DC_WELDING_DETECTION:
		if (Input->V2G_Message.Body.WeldingDetectionReq_isUsed) {
			errn = weldingDetection(Input, Output);
			next_state = STATE_B2_SESSION_STOP;
			basic_state = STATE_B2;
		}
		break;
	}

	if (errn ==0){
		errn = serializeEXI2Stream(Output, socket_number);
	}
	if (errn ==0){
		return basic_state;
	} else return errn;
}
