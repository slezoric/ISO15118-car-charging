/*
 * AC_Charge.c
 *
 *  Created on: 03.01.2016
 *      Author: melanie
 */

#include "ISO_EV_main.h"
# include <netinet/in.h>

# include "EXITypes.h"
# include "ErrorCodes.h"
# include "Convert.h"
# include "clientsockets.h"
# include "PWMSignal.h"



void copyBytes(uint8_t* from, uint16_t len, uint8_t* to) {
	int i;
	for(i=0; i<len; i++) {
		to[i] = from[i];
	}
}

int ac_charging(int socket_number, int fd)
{
	bitstream_t stream1;
	bitstream_t stream2;
	uint16_t pos1 = V2GTP_HEADER_LENGTH; /* v2gtp header */
	uint16_t pos2 = 0;


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
	int j;

	struct v2gEXIDocument exi_stream;

	struct v2gServiceDiscoveryResType serviceDiscoveryRes;
	struct v2gServiceDetailResType serviceDetailRes;
	struct v2gPaymentServiceSelectionResType paymentServiceSelectionRes;
	struct v2gPaymentDetailsResType paymentDetailsRes;

	/* setup header information */
	init_v2gEXIDocument(&exi_stream);
	exi_stream.V2G_Message_isUsed = 1u;
	exi_stream.V2G_Message.Header.Notification_isUsed = 0u;
	exi_stream.V2G_Message.Header.Signature_isUsed = 0u;
	exi_stream.V2G_Message.Header.SessionID.bytes[0] = 0; /* sessionID is always '0' at the beginning (the response contains the valid sessionID)*/
	exi_stream.V2G_Message.Header.SessionID.bytes[1] = 0;
	exi_stream.V2G_Message.Header.SessionID.bytes[2] = 0;
	exi_stream.V2G_Message.Header.SessionID.bytes[3] = 0;
	exi_stream.V2G_Message.Header.SessionID.bytes[4] = 0;
	exi_stream.V2G_Message.Header.SessionID.bytes[5] = 0;
	exi_stream.V2G_Message.Header.SessionID.bytes[6] = 0;
	exi_stream.V2G_Message.Header.SessionID.bytes[7] = 0;
	exi_stream.V2G_Message.Header.SessionID.bytesLen = 8; /* length of the byte session array is always 8*/
	exi_stream.V2G_Message.Header.Notification_isUsed = 0u; /* no notification */
	exi_stream.V2G_Message.Header.Signature_isUsed = 0u;

	/************************
	 * sessionSetup *
	 ************************/
	init_v2gBodyType(&exi_stream.V2G_Message.Body);
	exi_stream.V2G_Message.Body.SessionSetupReq_isUsed = 1u;
	exi_stream.V2G_Message.Body.SessionSetupReq.EVCCID.bytesLen = 1;
	exi_stream.V2G_Message.Body.SessionSetupReq.EVCCID.bytes[0] = 10;

	printf("EV side: call EVSE sessionSetup\n");

	errn = serializeEXI2Stream(&exi_stream, &stream1, socket_number);

	errn = transmit_message(socket_number, &stream1);
		/**************EVSE**************
		deserialize, create response, serialize response
		************************************/
	errn = receive_message(socket_number ,&stream2);
	if (errn == 0){
	errn = deserializeStream2EXI(&stream2, &exi_stream);
	}

	if(errn == 0) {
		/* check, if this is the right response message */
		if(exi_stream.V2G_Message.Body.SessionSetupRes_isUsed) {
			/* show results of EVSEs answer message */
			printf("EV side: received response message from EVSE\n");
			printf("\tHeader SessionID=");
			printBinaryArray(exi_stream.V2G_Message.Header.SessionID.bytes, exi_stream.V2G_Message.Header.SessionID.bytesLen);
			printf("\tResponseCode=%d\n", exi_stream.V2G_Message.Body.SessionSetupRes.ResponseCode);
			printf("\tEVSEID=%d\n",	exi_stream.V2G_Message.Body.SessionSetupRes.EVSEID.characters[1]);
			printf("\tEVSETimeStamp=%li\n", (long int)exi_stream.V2G_Message.Body.SessionSetupRes.EVSETimeStamp);
		} else {
			errn = ERROR_UNEXPECTED_SESSION_SETUP_RESP_MESSAGE;
			return errn;
		}
	}


	/*******************************************
	 * serviceDiscovery *
	 *******************************************/
	init_v2gBodyType(&exi_stream.V2G_Message.Body);
	exi_stream.V2G_Message.Body.ServiceDiscoveryReq_isUsed = 1u;

	exi_stream.V2G_Message.Body.ServiceDiscoveryReq.ServiceScope_isUsed = 0U;
	exi_stream.V2G_Message.Body.ServiceDiscoveryReq.ServiceCategory_isUsed = 0U;

	exi_stream.V2G_Message.Body.ServiceDiscoveryReq.ServiceCategory_isUsed = 1u;
	exi_stream.V2G_Message.Body.ServiceDiscoveryReq.ServiceCategory = v2gserviceCategoryType_Internet;
	exi_stream.V2G_Message.Body.ServiceDiscoveryReq.ServiceScope_isUsed = 0u;

	printf("EV side: call EVSE serviceDiscovery\n");

	errn = serializeEXI2Stream(&exi_stream, &stream1, socket_number);
	errn = transmit_message(socket_number, &stream1);
		/**************EVSE**************
		deserialize, create response, serialize response
		 ************************************/
	errn = receive_message(socket_number ,&stream2);
	if (errn == 0){
	errn = deserializeStream2EXI(&stream2, &exi_stream);
	}
	if(errn == 0) {
		/* check, if this is the right response message */
		if(exi_stream.V2G_Message.Body.ServiceDiscoveryRes_isUsed) {
			serviceDiscoveryRes = exi_stream.V2G_Message.Body.ServiceDiscoveryRes;
			/* show results of EVSEs answer message */
			printf("EV side: received response message from EVSE\n");
			printf("\tHeader SessionID=");
			printBinaryArray(exi_stream.V2G_Message.Header.SessionID.bytes, exi_stream.V2G_Message.Header.SessionID.bytesLen);
			printf("\t ResponseCode=%d\n",  exi_stream.V2G_Message.Body.ServiceDiscoveryRes.ResponseCode);
			printf("\t ServiceID=%d\n",	exi_stream.V2G_Message.Body.ServiceDiscoveryRes.ChargeService.ServiceID);
			printf("\t ServiceName=");
			printASCIIString(serviceDiscoveryRes.ChargeService.ServiceName.characters, serviceDiscoveryRes.ChargeService.ServiceName.charactersLen);
			if(serviceDiscoveryRes.PaymentOptionList.PaymentOption.array[1] == v2gpaymentOptionType_Contract) {
				printf("\t PaymentOption=Contract_paymentOptionType\n");
			}
			if(serviceDiscoveryRes.ChargeService.FreeService==1) {
				printf("\t ChargeService.FreeService=True\n");
			}
			if(serviceDiscoveryRes.ChargeService.SupportedEnergyTransferMode.EnergyTransferMode.array[0] == v2gEnergyTransferModeType_DC_combo_core) {
				printf("\t EnergyTransferMode=AC_single_DC_core\n");
			}
			if(serviceDiscoveryRes.ChargeService.SupportedEnergyTransferMode.EnergyTransferMode.array[1] == v2gEnergyTransferModeType_AC_single_phase_core) {
				printf("\t EnergyTransferMode=AC_single_phase_core_EnergyTransferModeType\n");
			}
			printf("\t Value added service list:\n");
			for(i=0;i<serviceDiscoveryRes.ServiceList.Service.arrayLen;i++)
			{
				printf("\n\t\t ServiceID=%d\n",	serviceDiscoveryRes.ServiceList.Service.array[i].ServiceID);
				printf("\t\t ServiceName=");
				printASCIIString(serviceDiscoveryRes.ServiceList.Service.array[i].ServiceName.characters, exi_stream.V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.array[i].ServiceName.charactersLen );
				if(serviceDiscoveryRes.ServiceList.Service.array[i].ServiceCategory == v2gserviceCategoryType_Internet) {
					printf("\t\t ServiceCategory=Internet\n");
				}
				if(serviceDiscoveryRes.ServiceList.Service.array[i].FreeService==1) {
					printf("\t\t FreeService=True\n");
				}
			}

		} else {
			errn = ERROR_UNEXPECTED_SERVICE_DISCOVERY_RESP_MESSAGE;
			return errn;
		}
	}


	/*********************************
	 * ServiceDetails *
	 *********************************/
	init_v2gBodyType(&exi_stream.V2G_Message.Body);
	exi_stream.V2G_Message.Body.ServiceDetailReq_isUsed = 1u;

	exi_stream.V2G_Message.Body.ServiceDetailReq.ServiceID = 22; /* Value Added Server ID */

	printf("EV side: call EVSE ServiceDetail \n");

	errn = serializeEXI2Stream(&exi_stream, &stream1, socket_number);
	errn = transmit_message(socket_number ,&stream1);
		/**************EVSE**************
		deserialize, create response, serialize response
		 ************************************/
	errn = receive_message(socket_number ,&stream2);
	errn = deserializeStream2EXI(&stream2, &exi_stream);

	if(errn == 0) {
		/* check, if this is the right response message */
		if(exi_stream.V2G_Message.Body.ServiceDetailRes_isUsed) {
			serviceDetailRes = exi_stream.V2G_Message.Body.ServiceDetailRes;
			/* show results of EVSEs answer message */
			printf("EV side: received response message from EVSE\n");
			printf("\tHeader SessionID=");
			printBinaryArray(exi_stream.V2G_Message.Header.SessionID.bytes, exi_stream.V2G_Message.Header.SessionID.bytesLen);
			printf("\t ResponseCode=%d\n",  exi_stream.V2G_Message.Body.ServiceDiscoveryRes.ResponseCode);
			printf("\t ServiceID=%d\n",	exi_stream.V2G_Message.Body.ServiceDetailRes.ServiceID);

			if(serviceDetailRes.ServiceParameterList_isUsed) {
				printf("\t\tLength=%d\n", serviceDetailRes.ServiceParameterList.ParameterSet.arrayLen );/*TEST*/

				for(i=0; i<serviceDetailRes.ServiceParameterList.ParameterSet.arrayLen; i++)
				{
					printf("\t\tServiceSetID=%d\n", serviceDetailRes.ServiceParameterList.ParameterSet.array[i].ParameterSetID);
					printf("\t\tParameters=%d\n", serviceDetailRes.ServiceParameterList.ParameterSet.array[i].Parameter.arrayLen);

					for(j=0; j<serviceDetailRes.ServiceParameterList.ParameterSet.array[i].Parameter.arrayLen; j++)
					{
						printf("\t\t\t %d: ParameterName=", j+1);
						printASCIIString(serviceDetailRes.ServiceParameterList.ParameterSet.array[i].Parameter.array[j].Name.characters, exi_stream.V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[i].Parameter.array[j].Name.charactersLen);

						if(serviceDetailRes.ServiceParameterList.ParameterSet.array[i].Parameter.array[j].shortValue_isUsed == 1u) {
							printf("\t\t\t %d: StringValue=", j+1);
							printASCIIString(serviceDetailRes.ServiceParameterList.ParameterSet.array[i].Parameter.array[j].stringValue.characters, serviceDetailRes.ServiceParameterList.ParameterSet.array[i].Parameter.array[j].stringValue.charactersLen);
						} else if(serviceDetailRes.ServiceParameterList.ParameterSet.array[i].Parameter.array[j].intValue_isUsed == 1u) {
							printf("\t\t\t %d: IntValue=%d\n", j+1, serviceDetailRes.ServiceParameterList.ParameterSet.array[i].Parameter.array[j].intValue);
						} else if(serviceDetailRes.ServiceParameterList.ParameterSet.array[i].Parameter.array[j].physicalValue_isUsed == 1u) {
							printf("\t\t\t %d: PhysicalValue=%d (%d)\n",  j+1, serviceDetailRes.ServiceParameterList.ParameterSet.array[i].Parameter.array[j].physicalValue.Value, serviceDetailRes.ServiceParameterList.ParameterSet.array[i].Parameter.array[j].physicalValue.Multiplier);
						}
					}
				}
			}
		} else {
			errn = ERROR_UNEXPECTED_SERVICE_DETAILS_RESP_MESSAGE;
			return errn;
		}
	}

	/*******************************************
	 * ServicePaymentSelection *
	 *******************************************/
	init_v2gBodyType(&exi_stream.V2G_Message.Body);
	exi_stream.V2G_Message.Body.PaymentServiceSelectionReq_isUsed = 1u;

	exi_stream.V2G_Message.Body.PaymentServiceSelectionReq.SelectedPaymentOption = v2gpaymentOptionType_ExternalPayment;
	exi_stream.V2G_Message.Body.PaymentServiceSelectionReq.SelectedServiceList.SelectedService.arrayLen = 2;
	exi_stream.V2G_Message.Body.PaymentServiceSelectionReq.SelectedServiceList.SelectedService.array[0].ServiceID = serviceDiscoveryRes.ChargeService.ServiceID; /* charge server ID */
	exi_stream.V2G_Message.Body.PaymentServiceSelectionReq.SelectedServiceList.SelectedService.array[0].ParameterSetID_isUsed = 0u; /* is not used */
	exi_stream.V2G_Message.Body.PaymentServiceSelectionReq.SelectedServiceList.SelectedService.array[1].ServiceID = serviceDiscoveryRes.ServiceList.Service.array[0].ServiceID;
	exi_stream.V2G_Message.Body.PaymentServiceSelectionReq.SelectedServiceList.SelectedService.array[1].ParameterSetID= serviceDetailRes.ServiceParameterList.ParameterSet.array[0].ParameterSetID;
	exi_stream.V2G_Message.Body.PaymentServiceSelectionReq.SelectedServiceList.SelectedService.array[1].ParameterSetID_isUsed = 1u;

	printf("EV side: call EVSE ServicePaymentSelection \n");

	errn = serializeEXI2Stream(&exi_stream, &stream1, socket_number);
	errn = transmit_message(socket_number ,&stream1);
		/**************EVSE**************
		deserialize, create response, serialize response
		 ************************************/
	errn = receive_message(socket_number ,&stream2);
	if (errn == 0){
	errn = deserializeStream2EXI(&stream2, &exi_stream);
	}
	if(errn == 0) {
		/* check, if this is the right response message */
		if(exi_stream.V2G_Message.Body.PaymentServiceSelectionRes_isUsed) {
			paymentServiceSelectionRes = exi_stream.V2G_Message.Body.PaymentServiceSelectionRes;
			/* show results of EVSEs answer message */
			printf("EV side: received response message from EVSE\n");
			printf("\tHeader SessionID=");
			printBinaryArray(exi_stream.V2G_Message.Header.SessionID.bytes, exi_stream.V2G_Message.Header.SessionID.bytesLen);
			printf("\t ResponseCode=%d\n",  paymentServiceSelectionRes.ResponseCode);
		} else {
			errn = ERROR_UNEXPECTED_PAYMENT_SERVICE_SELECTION_RESP_MESSAGE;
			return errn;
		}
	}

	/**********************************
	 * PaymentDetails *
	 **********************************/
	init_v2gBodyType(&exi_stream.V2G_Message.Body);
	exi_stream.V2G_Message.Body.PaymentDetailsReq_isUsed = 1u;

	exi_stream.V2G_Message.Body.PaymentDetailsReq.eMAID.characters[0] = 1;
	exi_stream.V2G_Message.Body.PaymentDetailsReq.eMAID.characters[1] = 123;
	exi_stream.V2G_Message.Body.PaymentDetailsReq.eMAID.charactersLen =2;

	exi_stream.V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.Certificate.bytes[0] = 'C';
	exi_stream.V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.Certificate.bytes[1] = 'e';
	exi_stream.V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.Certificate.bytesLen = 2;
	exi_stream.V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.SubCertificates_isUsed = 1u;
	exi_stream.V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.SubCertificates.Certificate.array[0].bytes[0] = 'S';
	exi_stream.V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.SubCertificates.Certificate.array[0].bytes[1] = 'u';
	exi_stream.V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.SubCertificates.Certificate.array[0].bytesLen = 2;
	exi_stream.V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.SubCertificates.Certificate.array[1].bytes[0] = 'S';
	exi_stream.V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.SubCertificates.Certificate.array[1].bytes[1] = 'u';
	exi_stream.V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.SubCertificates.Certificate.array[1].bytes[2] = '2';
	exi_stream.V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.SubCertificates.Certificate.array[1].bytesLen = 3;
	exi_stream.V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.SubCertificates.Certificate.arrayLen =2;
	exi_stream.V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.Id_isUsed = 1u;
	exi_stream.V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.Id.charactersLen = 2;
	exi_stream.V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.Id.characters[0] = 'I';
	exi_stream.V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.Id.characters[0] = 'd';

	printf("EV side: call EVSE PaymentDetails \n");

	errn = serializeEXI2Stream(&exi_stream, &stream1, socket_number);
	errn = transmit_message(socket_number ,&stream1);
		/**************EVSE**************
		deserialize, create response, serialize response
		 ************************************/
	errn = receive_message(socket_number ,&stream2);
	if (errn == 0){
	errn = deserializeStream2EXI(&stream2, &exi_stream);
	}
	if(errn == 0) {
		/* check, if this is the right response message */
		if(exi_stream.V2G_Message.Body.PaymentDetailsRes_isUsed) {

			paymentDetailsRes = exi_stream.V2G_Message.Body.PaymentDetailsRes;

			/* show results of EVSEs answer message */
			printf("EV side: received response message from EVSE\n");
			printf("\tHeader SessionID=");
			printBinaryArray(exi_stream.V2G_Message.Header.SessionID.bytes, exi_stream.V2G_Message.Header.SessionID.bytesLen);
			printf("\t ResponseCode=%d\n",  paymentDetailsRes.ResponseCode);
			printf("\tEVSETimeStamp=%li\n",  (long int) paymentDetailsRes.EVSETimeStamp);
			printf("\tGenChallenge=%d\n",   paymentDetailsRes.GenChallenge.bytes[0]);

		} else {
			errn = ERROR_UNEXPECTED_PAYMENT_DETAILS_RESP_MESSAGE;
			return errn;
		}
	}


	/*******************************************
	 * Authorization *
	 *******************************************/
	init_v2gBodyType(&exi_stream.V2G_Message.Body);
	exi_stream.V2G_Message.Body.AuthorizationReq_isUsed = 1u;

	exi_stream.V2G_Message.Body.AuthorizationReq.Id_isUsed = 0U;
	exi_stream.V2G_Message.Body.AuthorizationReq.GenChallenge_isUsed = 0U;

	copyBytes(paymentDetailsRes.GenChallenge.bytes, paymentDetailsRes.GenChallenge.bytesLen, exi_stream.V2G_Message.Body.AuthorizationReq.GenChallenge.bytes);
	exi_stream.V2G_Message.Body.AuthorizationReq.GenChallenge.bytesLen = paymentDetailsRes.GenChallenge.bytesLen;
	exi_stream.V2G_Message.Body.AuthorizationReq.GenChallenge_isUsed = 1u; /* no challenge needed here*/
	exi_stream.V2G_Message.Body.AuthorizationReq.Id_isUsed = 1u; /* no signature needed here */
	exi_stream.V2G_Message.Body.AuthorizationReq.Id.charactersLen = 3;
	exi_stream.V2G_Message.Body.AuthorizationReq.Id.characters[0] = 'I';
	exi_stream.V2G_Message.Body.AuthorizationReq.Id.characters[1] = 'd';
	exi_stream.V2G_Message.Body.AuthorizationReq.Id.characters[2] = '2';

	printf("EV side: call EVSE Authorization \n");

	errn = serializeEXI2Stream(&exi_stream, &stream1, socket_number);
	errn = transmit_message(socket_number ,&stream1);
		/**************EVSE**************
		deserialize, create response, serialize response
		 ************************************/
	errn = receive_message(socket_number ,&stream2);
	if (errn == 0){
	errn = deserializeStream2EXI(&stream2, &exi_stream);
	}
	if(errn == 0) {
		/* check, if this is the right response message */
		if(exi_stream.V2G_Message.Body.AuthorizationRes_isUsed) {

			/* show results of EVSEs answer message */
			printf("EV side: received response message from EVSE\n");
			printf("\tHeader SessionID=");
			printBinaryArray(exi_stream.V2G_Message.Header.SessionID.bytes, exi_stream.V2G_Message.Header.SessionID.bytesLen);
			printf("\t ResponseCode=%d\n",  exi_stream.V2G_Message.Body.AuthorizationRes.ResponseCode);

			if(exi_stream.V2G_Message.Body.AuthorizationRes.EVSEProcessing == v2gEVSEProcessingType_Finished) {
				printf("\t EVSEProcessing=Finished\n");
			}
		} else {
			errn = ERROR_UNEXPECTED_AUTHORIZATION_RESP_MESSAGE;
			return errn;
		}
	}

# if CODE_EXAMPLE == CODE_EXAMPLE_HARDWARE
	double UCP;
	set_Ucp(fd, 2); // 150 Ohm --> 6V --> Status C: EV connected, ready
	UCP = get_Ucp(fd);
	printf("+++ change level on CP for state C: EV connected, ready, %f +++\n\n", UCP);
# endif

	/*******************************************
	 * chargeParameterDiscovery *
	 *******************************************/
	init_v2gBodyType(&exi_stream.V2G_Message.Body);
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq_isUsed = 1u;

	init_v2gChargeParameterDiscoveryReqType(&exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq);

	/* we use here AC based charging parameters */
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.RequestedEnergyTransferMode = v2gEnergyTransferModeType_AC_single_phase_core;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.MaxEntriesSAScheduleTuple = 1234;

	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.AC_EVChargeParameter_isUsed = 1u;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.AC_EVChargeParameter.DepartureTime = 12345;

	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.AC_EVChargeParameter.EAmount.Multiplier = 0;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.AC_EVChargeParameter.EAmount.Unit = v2gunitSymbolType_W;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.AC_EVChargeParameter.EAmount.Value = 100;

	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.AC_EVChargeParameter.EVMaxCurrent.Multiplier = 0;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.AC_EVChargeParameter.EVMaxCurrent.Unit = v2gunitSymbolType_A;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.AC_EVChargeParameter.EVMaxCurrent.Value = 200;

	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.AC_EVChargeParameter.EVMaxVoltage.Multiplier = 0;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.AC_EVChargeParameter.EVMaxVoltage.Unit = v2gunitSymbolType_V;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.AC_EVChargeParameter.EVMaxVoltage.Value = 400;

	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.AC_EVChargeParameter.EVMinCurrent.Multiplier = 0;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.AC_EVChargeParameter.EVMinCurrent.Unit = v2gunitSymbolType_A;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.AC_EVChargeParameter.EVMinCurrent.Value = 500;

	printf("EV side: call EVSE chargeParameterDiscovery\n");


	errn = serializeEXI2Stream(&exi_stream, &stream1, socket_number);
	errn = transmit_message(socket_number ,&stream1);
		/**************EVSE**************
		deserialize, create response, serialize response
		 ************************************/
	errn = receive_message(socket_number ,&stream2);
	if (errn == 0){
	errn = deserializeStream2EXI(&stream2, &exi_stream);
	}
	if(errn == 0) {
		/* check, if this is the right response message */
		if(exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes_isUsed) {

			/* show results of EVSEs answer message */
			printf("EV side: received response message from EVSE\n");
			printf("\tHeader SessionID=");
			printBinaryArray(exi_stream.V2G_Message.Header.SessionID.bytes, exi_stream.V2G_Message.Header.SessionID.bytesLen);
			printf("\t ResponseCode=%d\n", exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.ResponseCode);

			printACEVSEStatus(&(exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.AC_EVSEChargeParameter.AC_EVSEStatus));
			printf("\t EVSEProcessing=%d\n", exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.EVSEProcessing);
			printf("\t EVSEMaxCurrent=%d\n", exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.AC_EVSEChargeParameter.EVSEMaxCurrent.Value);
			printf("\t EVSENominalVoltage=%d\n", exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.AC_EVSEChargeParameter.EVSENominalVoltage.Value);
		} else {
			errn = ERROR_UNEXPECTED_CHARGE_PARAMETER_DISCOVERY_RESP_MESSAGE;
			return errn;
		}
	}

	/*********************************
	 * PowerDelivery *
	 *********************************/

	init_v2gBodyType(&exi_stream.V2G_Message.Body);
	exi_stream.V2G_Message.Body.PowerDeliveryReq_isUsed = 1u;

	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile_isUsed = 0U;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.EVPowerDeliveryParameter_isUsed = 0U;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter_isUsed = 0U;

	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile_isUsed = 0;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter_isUsed = 0; /* only used for DC charging */

	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargeProgress = v2gchargeProgressType_Start;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.SAScheduleTupleID = exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].SAScheduleTupleID;

	printf("EV side: call EVSE powerDelivery \n");

	errn = serializeEXI2Stream(&exi_stream, &stream1, socket_number);
	errn = transmit_message(socket_number ,&stream1);
		/**************EVSE**************
		deserialize, create response, serialize response
		************************************/
	errn = receive_message(socket_number ,&stream2);
	if (errn == 0){
	errn = deserializeStream2EXI(&stream2, &exi_stream);
	}
	if(errn == 0) {
		/* check, if this is the right response message */
		if(exi_stream.V2G_Message.Body.PowerDeliveryRes_isUsed) {

			/* show results of EVSEs answer message */
			printf("EV side: received response message from EVSE\n");
			printf("\tHeader SessionID=");
			printBinaryArray(exi_stream.V2G_Message.Header.SessionID.bytes, exi_stream.V2G_Message.Header.SessionID.bytesLen);
			printf("\t ResponseCode=%d\n", exi_stream.V2G_Message.Body.PowerDeliveryRes.ResponseCode);
			printf("\tEVSEStatus:\n");
			printf("\t\tRCD=%d\n", exi_stream.V2G_Message.Body.PowerDeliveryRes.AC_EVSEStatus.RCD);
			printf("\t\tEVSENotification=%d\n", exi_stream.V2G_Message.Body.PowerDeliveryRes.AC_EVSEStatus.EVSENotification);
			printf("\t\tNotificationMaxDelay=%d\n", exi_stream.V2G_Message.Body.PowerDeliveryRes.AC_EVSEStatus.NotificationMaxDelay);
		} else {
			errn = ERROR_UNEXPECTED_POWER_DELIVERY_RESP_MESSAGE;
			return errn;
		}
	}


	/*********************************
	 * Setup data for chargingStatus *
	 *********************************/

	init_v2gBodyType(&exi_stream.V2G_Message.Body);
	exi_stream.V2G_Message.Body.ChargingStatusReq_isUsed = 1u;

	printf("EV side: call EVSE chargingStatus \n");

	errn = serializeEXI2Stream(&exi_stream, &stream1, socket_number);
	errn = transmit_message(socket_number ,&stream1);
		/**************EVSE**************
		deserialize, create response, serialize response
		 ************************************/
	errn = receive_message(socket_number ,&stream2);
	if (errn == 0){
	errn = deserializeStream2EXI(&stream2, &exi_stream);
	}
	if(errn == 0) {
		/* check, if this is the right response message */
		if(exi_stream.V2G_Message.Body.ChargingStatusRes_isUsed)
		{
			/* show results of EVSEs answer message */
			printf("EV side: received response message from EVSE\n");
			printf("\tHeader SessionID=");
			printBinaryArray(exi_stream.V2G_Message.Header.SessionID.bytes, exi_stream.V2G_Message.Header.SessionID.bytesLen);
			printf("\t ResponseCode=%d\n", exi_stream.V2G_Message.Body.ChargingStatusRes.ResponseCode);

			printf("\tEVSEStatus:\n");
			printf("\t\tRCD=%d\n", exi_stream.V2G_Message.Body.ChargingStatusRes.AC_EVSEStatus.RCD);
			printf("\t\tEVSENotification=%d\n", exi_stream.V2G_Message.Body.ChargingStatusRes.AC_EVSEStatus.EVSENotification);
			printf("\t\tNotificationMaxDelay=%d\n", exi_stream.V2G_Message.Body.ChargingStatusRes.AC_EVSEStatus.NotificationMaxDelay);

			printf("\tReceiptRequired=%d\n", exi_stream.V2G_Message.Body.ChargingStatusRes.ReceiptRequired);
			printf("\tEVSEID=%d\n", exi_stream.V2G_Message.Body.ChargingStatusRes.EVSEID.characters[0]);
			printf("\tSAScheduleTupleID=%d\n", exi_stream.V2G_Message.Body.ChargingStatusRes.SAScheduleTupleID);
			printf("\tEVSEMaxCurrent=%d (%d %d)\n", exi_stream.V2G_Message.Body.ChargingStatusRes.EVSEMaxCurrent.Value, exi_stream.V2G_Message.Body.ChargingStatusRes.EVSEMaxCurrent.Unit, exi_stream.V2G_Message.Body.ChargingStatusRes.EVSEMaxCurrent.Multiplier);
			printf("\tisused.MeterInfo=%d\n",		exi_stream.V2G_Message.Body.ChargingStatusRes.MeterInfo_isUsed);
			printf("\t\tMeterInfo.MeterID=%d\n",		exi_stream.V2G_Message.Body.ChargingStatusRes.MeterInfo.MeterID.characters[0]);
			printf("\t\tMeterInfo.MeterReading.Value=%li\n",		(long int)exi_stream.V2G_Message.Body.ChargingStatusRes.MeterInfo.MeterReading);
			printf("\t\tMeterInfo.MeterStatus=%d\n",		exi_stream.V2G_Message.Body.ChargingStatusRes.MeterInfo.MeterStatus);
			printf("\t\tMeterInfo.TMeter=%li\n",		(long int)exi_stream.V2G_Message.Body.ChargingStatusRes.MeterInfo.TMeter);
			printf("\t\tMeterInfo.SigMeterReading.data=%d\n",		exi_stream.V2G_Message.Body.ChargingStatusRes.MeterInfo.SigMeterReading.bytes[0]);
		} else {
			errn = ERROR_UNEXPECTED_CHARGING_STATUS_RESP_MESSAGE;
			return errn;
		}
	}

	/***********************************
	 * MeteringReceipt *
	 ***********************************/

	init_v2gBodyType(&exi_stream.V2G_Message.Body);
	exi_stream.V2G_Message.Body.MeteringReceiptReq_isUsed = 1u;

	exi_stream.V2G_Message.Body.MeteringReceiptReq.Id_isUsed = 0U;
	exi_stream.V2G_Message.Body.MeteringReceiptReq.SAScheduleTupleID_isUsed = 0U;

	exi_stream.V2G_Message.Body.MeteringReceiptReq.SessionID.bytes[0] = 22;
	exi_stream.V2G_Message.Body.MeteringReceiptReq.SAScheduleTupleID = 12;
	exi_stream.V2G_Message.Body.MeteringReceiptReq.SAScheduleTupleID_isUsed =1;
	exi_stream.V2G_Message.Body.MeteringReceiptReq.MeterInfo.MeterStatus = 2;
	exi_stream.V2G_Message.Body.MeteringReceiptReq.MeterInfo.MeterStatus_isUsed = 1;
	exi_stream.V2G_Message.Body.MeteringReceiptReq.MeterInfo.MeterID.charactersLen =1;
	exi_stream.V2G_Message.Body.MeteringReceiptReq.MeterInfo.MeterID.characters[0]=3;

	exi_stream.V2G_Message.Body.MeteringReceiptReq.MeterInfo.MeterReading = 100;
	exi_stream.V2G_Message.Body.MeteringReceiptReq.MeterInfo.MeterReading_isUsed = 1;
	exi_stream.V2G_Message.Body.MeteringReceiptReq.MeterInfo.SigMeterReading_isUsed = 0;

	exi_stream.V2G_Message.Body.MeteringReceiptReq.MeterInfo.TMeter =123456789;
	exi_stream.V2G_Message.Body.MeteringReceiptReq.MeterInfo.TMeter_isUsed = 1;

	exi_stream.V2G_Message.Body.MeteringReceiptReq.Id.characters[0]='I';
	exi_stream.V2G_Message.Body.MeteringReceiptReq.Id.characters[1]='d';
	exi_stream.V2G_Message.Body.MeteringReceiptReq.Id.characters[2]='3';
	exi_stream.V2G_Message.Body.MeteringReceiptReq.Id.charactersLen =3;
	exi_stream.V2G_Message.Body.MeteringReceiptReq.Id_isUsed =1; /* message is signed */

	printf("EV side: call EVSE meteringReceipt \n");

	errn = serializeEXI2Stream(&exi_stream, &stream1, socket_number);
	errn = transmit_message(socket_number ,&stream1);
		/**************EVSE**************
		deserialize, create response, serialize response
		************************************/
	errn = receive_message(socket_number ,&stream2);
	if (errn == 0){
	errn = deserializeStream2EXI(&stream2, &exi_stream);
	}

	if(errn == 0) {
		/* check, if this is the right response message */
		if(exi_stream.V2G_Message.Body.MeteringReceiptRes_isUsed) {

			/* show results of EVSEs answer message */
			printf("EV side: received response message from EVSE\n");
			printf("\tHeader SessionID=");
			printBinaryArray(exi_stream.V2G_Message.Header.SessionID.bytes, exi_stream.V2G_Message.Header.SessionID.bytesLen);
			printf("\t ResponseCode=%d\n", exi_stream.V2G_Message.Body.MeteringReceiptRes.ResponseCode);

		} else {
			errn = ERROR_UNEXPECTED_METERING_RECEIPT_RESP_MESSAGE;
			return errn;
		}
	}

	/*********************************
	 * PowerDelivery *
	 *********************************/

	init_v2gBodyType(&exi_stream.V2G_Message.Body);
	exi_stream.V2G_Message.Body.PowerDeliveryReq_isUsed = 1u;

	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile_isUsed = 0U;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.EVPowerDeliveryParameter_isUsed = 0U;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter_isUsed = 0U;

	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile_isUsed = 0;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter_isUsed = 0; /* only used for DC charging */

	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargeProgress = v2gchargeProgressType_Start;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.SAScheduleTupleID = exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].SAScheduleTupleID;

	printf("EV side: call EVSE powerDelivery \n");

	errn = serializeEXI2Stream(&exi_stream, &stream1, socket_number);
	errn = transmit_message(socket_number ,&stream1);
		/**************EVSE**************
		deserialize, create response, serialize response
		************************************/
	errn = receive_message(socket_number ,&stream2);
	if (errn == 0){
	errn = deserializeStream2EXI(&stream2, &exi_stream);
	}
	if(errn == 0) {
		/* check, if this is the right response message */
		if(exi_stream.V2G_Message.Body.PowerDeliveryRes_isUsed) {

			/* show results of EVSEs answer message */
			printf("EV side: received response message from EVSE\n");
			printf("\tHeader SessionID=");
			printBinaryArray(exi_stream.V2G_Message.Header.SessionID.bytes, exi_stream.V2G_Message.Header.SessionID.bytesLen);
			printf("\t ResponseCode=%d\n", exi_stream.V2G_Message.Body.PowerDeliveryRes.ResponseCode);
			printf("\tEVSEStatus:\n");
			printf("\t\tRCD=%d\n", exi_stream.V2G_Message.Body.PowerDeliveryRes.AC_EVSEStatus.RCD);
			printf("\t\tEVSENotification=%d\n", exi_stream.V2G_Message.Body.PowerDeliveryRes.AC_EVSEStatus.EVSENotification);
			printf("\t\tNotificationMaxDelay=%d\n", exi_stream.V2G_Message.Body.PowerDeliveryRes.AC_EVSEStatus.NotificationMaxDelay);
		} else {
			errn = ERROR_UNEXPECTED_POWER_DELIVERY_RESP_MESSAGE;
			return errn;
		}
	}

# if CODE_EXAMPLE == CODE_EXAMPLE_HARDWARE
	set_Ucp(fd, 1); //  2,7k --> Status B: vehicle detected
	UCP = get_Ucp(fd);
	printf("+++ change level on CP for state B: EV detected, %f +++\n\n", UCP);
# endif

	/***********************************
	 * SessionStop *
	 ***********************************/

	init_v2gBodyType(&exi_stream.V2G_Message.Body);
	exi_stream.V2G_Message.Body.SessionStopReq_isUsed = 1u;

	exi_stream.V2G_Message.Body.SessionStopReq.ChargingSession = 1;

	printf("EV side: call EVSE stopSession \n");

	errn = serializeEXI2Stream(&exi_stream, &stream1, socket_number);
	errn = transmit_message(socket_number ,&stream1);
		/**************EVSE**************
		deserialize, create response, serialize response
		************************************/
	errn = receive_message(socket_number ,&stream2);
	if (errn == 0){
	errn = deserializeStream2EXI(&stream2, &exi_stream);
	}
	if(errn == 0) {
		/* check, if this is the right response message */
		if(exi_stream.V2G_Message.Body.SessionStopRes_isUsed) {
			/* show results of EVSEs answer message */
			printf("EV side: received response message from EVSE\n");
			printf("\tHeader SessionID=");
			printBinaryArray(exi_stream.V2G_Message.Header.SessionID.bytes, exi_stream.V2G_Message.Header.SessionID.bytesLen);
			printf("\t ResponseCode=%d\n", exi_stream.V2G_Message.Body.SessionStopRes.ResponseCode);
		} else {
			errn = ERROR_UNEXPECTED_SESSION_STOP_RESP_MESSAGE;
			return errn;
		}
	}
	return errn;
}

