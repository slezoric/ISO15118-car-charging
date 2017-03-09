/*
 * DC_Charge.c
 *
 *  Created on: 03.01.2016
 *      Author: melanie
 */


# include "ISO_EV_main.h"
# include "ErrorCodes.h"
# include "v2gEXIDatatypes.h"
# include "PWMSignal.h"


int dc_charging(int socket_number, int fd)
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

	int i, j;
	for (i=0;i<BUFFER_SIZE; i++) {
		stream1.data[i] = 0;
		stream2.data[i] = 0;
	}

	int errn = 0;

	struct v2gEXIDocument exi_stream;

	struct v2gServiceDiscoveryResType serviceDiscoveryRes;
	struct v2gChargeParameterDiscoveryResType chargeParameterDiscoveryRes;
	/* struct v2gServiceDetailResType serviceDetailRes;
	struct v2gPaymentServiceSelectionResType paymentServiceSelectionRes;*/
	struct v2gPaymentDetailsResType paymentDetailsRes;

	/* setup header information */
	init_v2gEXIDocument(&exi_stream);
	exi_stream.V2G_Message_isUsed = 1u;
	exi_stream.V2G_Message.Header.SessionID.bytes[0] = 0; /* sessionID is always '0' at the beginning (the response contains the valid sessionID)*/
	exi_stream.V2G_Message.Header.SessionID.bytes[1] = 0;
	exi_stream.V2G_Message.Header.SessionID.bytes[2] = 0;
	exi_stream.V2G_Message.Header.SessionID.bytes[3] = 0;
	exi_stream.V2G_Message.Header.SessionID.bytes[4] = 0;
	exi_stream.V2G_Message.Header.SessionID.bytes[5] = 0;
	exi_stream.V2G_Message.Header.SessionID.bytes[6] = 0;
	exi_stream.V2G_Message.Header.SessionID.bytes[7] = 0;
	exi_stream.V2G_Message.Header.SessionID.bytesLen = 8; /* length of the byte session array is always 8 */
	exi_stream.V2G_Message.Header.Notification_isUsed = 0u; /* no notification */
	exi_stream.V2G_Message.Header.Signature_isUsed = 0u;




	/************************
	 * sessionSetup *
	 ************************/
	init_v2gBodyType(&exi_stream.V2G_Message.Body);
	exi_stream.V2G_Message.Body.SessionSetupReq_isUsed = 1u;

	exi_stream.V2G_Message.Body.SessionSetupReq.EVCCID.bytesLen = 1;
	exi_stream.V2G_Message.Body.SessionSetupReq.EVCCID.bytes[0] = 20;

	printf("EV side: call EVSE sessionSetup");

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

	exi_stream.V2G_Message.Body.ServiceDiscoveryReq.ServiceScope_isUsed = 0u;

	exi_stream.V2G_Message.Body.ServiceDiscoveryReq.ServiceCategory_isUsed = 1u;
	exi_stream.V2G_Message.Body.ServiceDiscoveryReq.ServiceCategory = v2gserviceCategoryType_EVCharging;


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

			printf("\t PaymentOption=%d\n",	serviceDiscoveryRes.PaymentOptionList.PaymentOption.array[1]);
			printf("\t EnergyTransferType=%d\n",	serviceDiscoveryRes.ChargeService.SupportedEnergyTransferMode.EnergyTransferMode.array[1]);
			printf("\t FreeService=%d\n", serviceDiscoveryRes.ChargeService.FreeService);
			printf("\t ServiceCategory=%d\n",	serviceDiscoveryRes.ChargeService.ServiceCategory);
			printf("\t ServiceScope=%d\n",	serviceDiscoveryRes.ChargeService.ServiceScope.characters[0]);
		} else {
			errn = ERROR_UNEXPECTED_SERVICE_DISCOVERY_RESP_MESSAGE;
			return errn;
		}
	}



	/*******************************************
	 * ServicePaymentSelection *
	 *******************************************/
	init_v2gBodyType(&exi_stream.V2G_Message.Body);
	exi_stream.V2G_Message.Body.PaymentServiceSelectionReq_isUsed = 1u;

	exi_stream.V2G_Message.Body.PaymentServiceSelectionReq.SelectedPaymentOption = v2gpaymentOptionType_ExternalPayment;
	exi_stream.V2G_Message.Body.PaymentServiceSelectionReq.SelectedServiceList.SelectedService.arrayLen = 1; /* only one service was selected */
	exi_stream.V2G_Message.Body.PaymentServiceSelectionReq.SelectedServiceList.SelectedService.array[0].ServiceID = serviceDiscoveryRes.ChargeService.ServiceID; /* charge server ID */
	exi_stream.V2G_Message.Body.PaymentServiceSelectionReq.SelectedServiceList.SelectedService.array[0].ParameterSetID_isUsed = 0u; /* is not used */

	printf("EV side: call EVSE ServicePaymentSelection \n");

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
		if(exi_stream.V2G_Message.Body.PaymentServiceSelectionRes_isUsed) {
			/* show results of EVSEs answer message */
			printf("EV side: received response message from EVSE\n");
			printf("\tHeader SessionID=");
			printBinaryArray(exi_stream.V2G_Message.Header.SessionID.bytes, exi_stream.V2G_Message.Header.SessionID.bytesLen);
			printf("\t ResponseCode=%d\n",  exi_stream.V2G_Message.Body.PaymentServiceSelectionRes.ResponseCode);

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

	exi_stream.V2G_Message.Body.AuthorizationReq.GenChallenge_isUsed =0; /* no challenge needed here*/
	exi_stream.V2G_Message.Body.AuthorizationReq.Id_isUsed =0 ; /* no signature needed here */

	printf("EV side: call EVSE Authorization \n");

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




	/*******************************************
	 * chargeParameterDiscovery *
	 *******************************************/
	init_v2gBodyType(&exi_stream.V2G_Message.Body);
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq_isUsed = 1u;

	init_v2gChargeParameterDiscoveryReqType(&exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq);


	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter_isUsed = 1u;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.DC_EVStatus.EVRESSSOC = 89;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.DC_EVStatus.EVReady = 1;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.DC_EVStatus.EVErrorCode = v2gDC_EVErrorCodeType_NO_ERROR;

	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.DepartureTime_isUsed = 1u;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.DepartureTime = 123456789;

	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVMaximumCurrentLimit.Multiplier = 0;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVMaximumCurrentLimit.Unit = v2gunitSymbolType_A;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVMaximumCurrentLimit.Value = 60;

	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVMaximumPowerLimit_isUsed = 1u;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVMaximumPowerLimit.Multiplier = 0;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVMaximumPowerLimit.Unit = v2gunitSymbolType_W;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVMaximumPowerLimit.Value = 20000;

	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVMaximumVoltageLimit.Multiplier = 0;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVMaximumVoltageLimit.Unit = v2gunitSymbolType_V;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVMaximumVoltageLimit.Value = 420;

	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVEnergyCapacity_isUsed = 1u;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVEnergyCapacity.Multiplier = 0;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVEnergyCapacity.Unit = v2gunitSymbolType_W;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVEnergyCapacity.Value = 15000;

	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVEnergyRequest_isUsed = 1u;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVEnergyRequest.Multiplier = 0;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVEnergyRequest.Unit = v2gunitSymbolType_W;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVEnergyRequest.Value = 5000;


	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.FullSOC_isUsed = 1u;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.FullSOC = 99;

	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.BulkSOC_isUsed = 1u;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.BulkSOC = 80;


	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.RequestedEnergyTransferMode = v2gEnergyTransferModeType_DC_core;
	exi_stream.V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter_isUsed = 1u;


	printf("EV side: call EVSE chargeParameterDiscovery \n");

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
		if(exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes_isUsed) {
			chargeParameterDiscoveryRes = exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes;

			/* show results of EVSEs answer message */
			printf("EV side: received response message from EVSE\n");
			printf("\tHeader SessionID=");
			printBinaryArray(exi_stream.V2G_Message.Header.SessionID.bytes, exi_stream.V2G_Message.Header.SessionID.bytesLen);
			printf("\t ResponseCode=%d\n", exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.ResponseCode);

			printACEVSEStatus(&(exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.AC_EVSEChargeParameter.AC_EVSEStatus));

			printf("\tEVSEMaximumCurrentLimit=%d\n", exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEMaximumCurrentLimit.Value);
			printf("\tEVSEMaximumPowerLimit=%d\n", exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEMaximumPowerLimit.Value);
			printf("\tEVSEMaximumVoltageLimit=%d\n", exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEMaximumVoltageLimit.Value);
			printf("\tEVSEMinimumCurrentLimit=%d\n", exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEMinimumCurrentLimit.Value);

			printf("\tEVSEMinimumVoltageLimit=%d\n", exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEMinimumVoltageLimit.Value);
			printf("\tEVSECurrentRegulationTolerance=%d\n", exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSECurrentRegulationTolerance.Value);
			printf("\tEVSEPeakCurrentRipple=%d\n", exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEPeakCurrentRipple.Value);
			printf("\tEVSEEnergyToBeDelivered=%d\n", exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEEnergyToBeDelivered.Value);

			printf("\tSAScheduleList: \n");

			for(i=0; i< exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.arrayLen;i++)
			{
				printf("\t\t Tuple#%d: \n",(i+1));
				printf("\t\t SAScheduleTupleID=%d: \n", exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[i].SAScheduleTupleID);

				for(j=0; j< exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[i].PMaxSchedule.PMaxScheduleEntry.arrayLen;j++)
				{
					printf("\t\t\t Entry#%d: \n",(j+1));
					printf("\t\t\t\t PMax=%d (%d %d) \n", exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[i].PMaxSchedule.PMaxScheduleEntry.array[j].PMax.Value, exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[i].PMaxSchedule.PMaxScheduleEntry.array[j].PMax.Unit, exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[i].PMaxSchedule.PMaxScheduleEntry.array[j].PMax.Multiplier);
					printf("\t\t\t\t Start=%d \n", exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[i].PMaxSchedule.PMaxScheduleEntry.array[j].RelativeTimeInterval.start);
					if(exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[i].PMaxSchedule.PMaxScheduleEntry.array[j].RelativeTimeInterval.duration_isUsed) {
						printf("\t\t\t\t Duration=%d \n", exi_stream.V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[i].PMaxSchedule.PMaxScheduleEntry.array[j].RelativeTimeInterval.duration);
					}
				}
			}
		} else {
			errn = ERROR_UNEXPECTED_CHARGE_PARAMETER_DISCOVERY_RESP_MESSAGE;
			return errn;
		}
	}

# if CODE_EXAMPLE == CODE_EXAMPLE_HARDWARE
	double UCP;
	set_Ucp(fd, 2); // 150 Ohm --> 6V --> Status C: EV connected, ready
	UCP = get_Ucp(fd);
	printf("+++ change level on CP for state C: EV connected, ready, %f +++\n\n", UCP);
# endif

	/*****************************
	 * cableCheck *
	 *****************************/
	init_v2gBodyType(&exi_stream.V2G_Message.Body);
	exi_stream.V2G_Message.Body.CableCheckReq_isUsed = 1u;

	exi_stream.V2G_Message.Body.CableCheckReq.DC_EVStatus.EVErrorCode = 1;
	exi_stream.V2G_Message.Body.CableCheckReq.DC_EVStatus.EVReady = 1;
	exi_stream.V2G_Message.Body.CableCheckReq.DC_EVStatus.EVRESSSOC = 12;

	printf("EV side: call EVSE cableCheck \n");

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
		if(exi_stream.V2G_Message.Body.CableCheckRes_isUsed) {

			/* show results of EVSEs answer message */
			printf("EV side: received response message from EVSE\n");
			printf("\tHeader SessionID=");
			printBinaryArray(exi_stream.V2G_Message.Header.SessionID.bytes, exi_stream.V2G_Message.Header.SessionID.bytesLen);
			printf("\t ResponseCode=%d\n", exi_stream.V2G_Message.Body.CableCheckRes.ResponseCode);

			if(exi_stream.V2G_Message.Body.CableCheckRes.EVSEProcessing==v2gEVSEProcessingType_Finished) {
				printf("\tEVSEProcessing=Finished\n");
			}

			printDCEVSEStatus(&(exi_stream.V2G_Message.Body.CableCheckRes.DC_EVSEStatus));

		} else {
			errn = ERROR_UNEXPECTED_CABLE_CHECK_RESP_MESSAGE;
			return errn;
		}
	}



	/*****************************
	 * preCharge *
	 *****************************/
	init_v2gBodyType(&exi_stream.V2G_Message.Body);
	exi_stream.V2G_Message.Body.PreChargeReq_isUsed = 1u;

	exi_stream.V2G_Message.Body.PreChargeReq.DC_EVStatus.EVErrorCode = 1;
	exi_stream.V2G_Message.Body.PreChargeReq.DC_EVStatus.EVReady = 1;
	exi_stream.V2G_Message.Body.PreChargeReq.DC_EVStatus.EVRESSSOC = 12;

	exi_stream.V2G_Message.Body.PreChargeReq.EVTargetCurrent.Multiplier = 0;
	exi_stream.V2G_Message.Body.PreChargeReq.EVTargetCurrent.Unit = v2gunitSymbolType_A;
	exi_stream.V2G_Message.Body.PreChargeReq.EVTargetCurrent.Value = 100;

	exi_stream.V2G_Message.Body.PreChargeReq.EVTargetVoltage.Multiplier = 0;
	exi_stream.V2G_Message.Body.PreChargeReq.EVTargetVoltage.Unit = v2gunitSymbolType_V;
	exi_stream.V2G_Message.Body.PreChargeReq.EVTargetVoltage.Value = 200;

	printf("EV side: call EVSE preCharge \n");

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
		if(exi_stream.V2G_Message.Body.PreChargeRes_isUsed) {

			/* show results of EVSEs answer message */
			printf("EV side: received response message from EVSE\n");
			printf("\tHeader SessionID=");
			printBinaryArray(exi_stream.V2G_Message.Header.SessionID.bytes, exi_stream.V2G_Message.Header.SessionID.bytesLen);
			printf("\t ResponseCode=%d\n", exi_stream.V2G_Message.Body.PreChargeRes.ResponseCode);

			printDCEVSEStatus(&exi_stream.V2G_Message.Body.PreChargeRes.DC_EVSEStatus);
			printf("\tEVSEPresentVoltage=%d (%d %d)\n", exi_stream.V2G_Message.Body.PreChargeRes.EVSEPresentVoltage.Value, exi_stream.V2G_Message.Body.PreChargeRes.EVSEPresentVoltage.Unit, exi_stream.V2G_Message.Body.PreChargeRes.EVSEPresentVoltage.Multiplier);

		} else {
			errn = ERROR_UNEXPECTED_PRE_CHARGE_RESP_MESSAGE;
			return errn;
		}
	}


	/*****************************
	 * powerDelivery *
	 *****************************/
	init_v2gBodyType(&exi_stream.V2G_Message.Body);
	exi_stream.V2G_Message.Body.PowerDeliveryReq_isUsed = 1u;


	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile_isUsed = 0u;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.EVPowerDeliveryParameter_isUsed = 0u;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter_isUsed = 0u;

	exi_stream.V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter.DC_EVStatus = exi_stream.V2G_Message.Body.PreChargeReq.DC_EVStatus;

	exi_stream.V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter.BulkChargingComplete = 0;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter.BulkChargingComplete_isUsed = 1u;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter.ChargingComplete = 1;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter_isUsed = 1u; /* DC parameters are send */

	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargeProgress = v2gchargeProgressType_Start;


	/* we are using a charging profile */
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile_isUsed = 1u;

	exi_stream.V2G_Message.Body.PowerDeliveryReq.SAScheduleTupleID  = chargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].SAScheduleTupleID;

	/* set up 3 entries */
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.arrayLen=3;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[0].ChargingProfileEntryMaxPower.Value=0;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[0].ChargingProfileEntryMaxPower.Unit = v2gunitSymbolType_W;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[0].ChargingProfileEntryMaxPower.Multiplier=2;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[0].ChargingProfileEntryStart=0;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[0].ChargingProfileEntryMaxNumberOfPhasesInUse=1;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[0].ChargingProfileEntryMaxNumberOfPhasesInUse_isUsed=1;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[1].ChargingProfileEntryMaxPower.Value=20000;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[1].ChargingProfileEntryMaxPower.Unit = v2gunitSymbolType_W;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[1].ChargingProfileEntryMaxPower.Multiplier = 1;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[1].ChargingProfileEntryMaxNumberOfPhasesInUse=3;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[1].ChargingProfileEntryMaxNumberOfPhasesInUse_isUsed=1;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[1].ChargingProfileEntryStart=300; /* 5min */
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[2].ChargingProfileEntryMaxPower.Value=0;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[2].ChargingProfileEntryStart=1200; /* 20min */
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[2].ChargingProfileEntryMaxNumberOfPhasesInUse=3;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[2].ChargingProfileEntryMaxNumberOfPhasesInUse_isUsed=1;


	printf("EV side: call EVSE powerDelivery \n");

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
		if(exi_stream.V2G_Message.Body.PowerDeliveryRes_isUsed) {

			/* show results of EVSEs answer message */
			printf("EV side: received response message from EVSE\n");
			printf("\tHeader SessionID=");
			printBinaryArray(exi_stream.V2G_Message.Header.SessionID.bytes, exi_stream.V2G_Message.Header.SessionID.bytesLen);
			printf("\t ResponseCode=%d\n", exi_stream.V2G_Message.Body.PowerDeliveryRes.ResponseCode);

			printDCEVSEStatus(&exi_stream.V2G_Message.Body.PowerDeliveryRes.DC_EVSEStatus);
		} else {
			errn = ERROR_UNEXPECTED_PRE_CHARGE_RESP_MESSAGE;
			return errn;
		}
	}




	/*****************************
	 * currentDemand *
	 *****************************/
	init_v2gBodyType(&exi_stream.V2G_Message.Body);
	exi_stream.V2G_Message.Body.CurrentDemandReq_isUsed = 1u;

	init_v2gCurrentDemandReqType(&exi_stream.V2G_Message.Body.CurrentDemandReq);

	exi_stream.V2G_Message.Body.CurrentDemandReq.DC_EVStatus.EVRESSSOC = 12;
	exi_stream.V2G_Message.Body.CurrentDemandReq.DC_EVStatus.EVReady = 1;
	exi_stream.V2G_Message.Body.CurrentDemandReq.DC_EVStatus.EVErrorCode = 1;

	exi_stream.V2G_Message.Body.CurrentDemandReq.EVTargetVoltage.Multiplier = 0;
	exi_stream.V2G_Message.Body.CurrentDemandReq.EVTargetVoltage.Unit = v2gunitSymbolType_A;
	exi_stream.V2G_Message.Body.CurrentDemandReq.EVTargetVoltage.Value = 100;

	exi_stream.V2G_Message.Body.CurrentDemandReq.EVMaximumVoltageLimit.Multiplier = 0;
	exi_stream.V2G_Message.Body.CurrentDemandReq.EVMaximumVoltageLimit.Unit = v2gunitSymbolType_V;
	exi_stream.V2G_Message.Body.CurrentDemandReq.EVMaximumVoltageLimit.Value = 420;
	exi_stream.V2G_Message.Body.CurrentDemandReq.EVMaximumVoltageLimit_isUsed = 1u;

	exi_stream.V2G_Message.Body.CurrentDemandReq.EVMaximumPowerLimit.Multiplier = 0;
	exi_stream.V2G_Message.Body.CurrentDemandReq.EVMaximumPowerLimit.Unit = v2gunitSymbolType_W;
	exi_stream.V2G_Message.Body.CurrentDemandReq.EVMaximumPowerLimit.Value = 20000;
	exi_stream.V2G_Message.Body.CurrentDemandReq.EVMaximumPowerLimit_isUsed = 1u;

	exi_stream.V2G_Message.Body.CurrentDemandReq.EVMaximumCurrentLimit.Multiplier = 0;
	exi_stream.V2G_Message.Body.CurrentDemandReq.EVMaximumCurrentLimit.Unit = v2gunitSymbolType_A;
	exi_stream.V2G_Message.Body.CurrentDemandReq.EVMaximumCurrentLimit.Value = 60;
	exi_stream.V2G_Message.Body.CurrentDemandReq.EVMaximumCurrentLimit_isUsed = 1u;

	exi_stream.V2G_Message.Body.CurrentDemandReq.BulkChargingComplete_isUsed = 1u;
	exi_stream.V2G_Message.Body.CurrentDemandReq.BulkChargingComplete = 0;

	exi_stream.V2G_Message.Body.CurrentDemandReq.ChargingComplete = 1;

	exi_stream.V2G_Message.Body.CurrentDemandReq.RemainingTimeToFullSoC.Multiplier = 0;
	exi_stream.V2G_Message.Body.CurrentDemandReq.RemainingTimeToFullSoC.Unit = v2gunitSymbolType_s;
	exi_stream.V2G_Message.Body.CurrentDemandReq.RemainingTimeToFullSoC.Value = 300; /* 5 min*/
	exi_stream.V2G_Message.Body.CurrentDemandReq.RemainingTimeToFullSoC_isUsed = 1u;

	exi_stream.V2G_Message.Body.CurrentDemandReq.RemainingTimeToBulkSoC.Multiplier = 0;
	exi_stream.V2G_Message.Body.CurrentDemandReq.RemainingTimeToBulkSoC.Unit = v2gunitSymbolType_s;
	exi_stream.V2G_Message.Body.CurrentDemandReq.RemainingTimeToBulkSoC.Value = 120; /* 3 min */
	exi_stream.V2G_Message.Body.CurrentDemandReq.RemainingTimeToBulkSoC_isUsed = 1u;


	exi_stream.V2G_Message.Body.CurrentDemandReq.EVTargetVoltage.Multiplier = 0;
	exi_stream.V2G_Message.Body.CurrentDemandReq.EVTargetVoltage.Unit = v2gunitSymbolType_V;
	exi_stream.V2G_Message.Body.CurrentDemandReq.EVTargetVoltage.Value = 400;


	printf("EV side: call EVSE currentDemand \n");

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
		if(exi_stream.V2G_Message.Body.CurrentDemandRes_isUsed) {

			/* show results of EVSEs answer message */
			printf("EV side: received response message from EVSE\n");
			printf("\tHeader SessionID=");
			printBinaryArray(exi_stream.V2G_Message.Header.SessionID.bytes, exi_stream.V2G_Message.Header.SessionID.bytesLen);
			printf("\t ResponseCode=%d\n", exi_stream.V2G_Message.Body.CurrentDemandRes.ResponseCode);

			printDCEVSEStatus(&exi_stream.V2G_Message.Body.CurrentDemandRes.DC_EVSEStatus);
			printf("\t EVSEPresentVoltage=%d\n", exi_stream.V2G_Message.Body.CurrentDemandRes.EVSEPresentVoltage.Value);
			printf("\t EVSEPresentCurrent=%d\n", exi_stream.V2G_Message.Body.CurrentDemandRes.EVSEPresentCurrent.Value);
			printf("\t EVSECurrentLimitAchieved=%d\n", exi_stream.V2G_Message.Body.CurrentDemandRes.EVSECurrentLimitAchieved);
			printf("\t EVSEVoltageLimitAchieved=%d\n", exi_stream.V2G_Message.Body.CurrentDemandRes.EVSEVoltageLimitAchieved);

			printf("\t EVSEPowerLimitAchieved=%d\n" ,exi_stream.V2G_Message.Body.CurrentDemandRes.EVSEPowerLimitAchieved);
			printf("\t EVSEMaximumVoltageLimit=%d\n", exi_stream.V2G_Message.Body.CurrentDemandRes.EVSEMaximumVoltageLimit.Value);
			printf("\t EVSEMaximumCurrentLimit=%d (%d %d) \n", exi_stream.V2G_Message.Body.CurrentDemandRes.EVSEMaximumCurrentLimit.Value, exi_stream.V2G_Message.Body.CurrentDemandRes.EVSEMaximumCurrentLimit.Unit, exi_stream.V2G_Message.Body.CurrentDemandRes.EVSEMaximumCurrentLimit.Multiplier);
			printf("\t EVSEMaximumPowerLimit=%d\n", exi_stream.V2G_Message.Body.CurrentDemandRes.EVSEMaximumPowerLimit.Value);

			printf("\tReceiptRequired=%d\n", exi_stream.V2G_Message.Body.CurrentDemandRes.ReceiptRequired);
			printf("\tEVSEID=%d\n", exi_stream.V2G_Message.Body.CurrentDemandRes.EVSEID.characters[0]);
			printf("\tisused.MeterInfo=%d\n",		exi_stream.V2G_Message.Body.CurrentDemandRes.MeterInfo_isUsed);
			printf("\t\tMeterInfo.MeterID=%d\n",		exi_stream.V2G_Message.Body.CurrentDemandRes.MeterInfo.MeterID.characters[0]);
			printf("\t\tMeterInfo.MeterReading.Value=%lu\n",		(long unsigned int)exi_stream.V2G_Message.Body.CurrentDemandRes.MeterInfo.MeterReading);
			printf("\t\tMeterInfo.MeterStatus=%d\n",		exi_stream.V2G_Message.Body.CurrentDemandRes.MeterInfo.MeterStatus);
			printf("\t\tMeterInfo.TMeter=%li\n",		(long int)exi_stream.V2G_Message.Body.CurrentDemandRes.MeterInfo.TMeter);
		} else {
			errn = ERROR_UNEXPECTED_CURRENT_DEMAND_RESP_MESSAGE;
			return errn;
		}
	}
	/*****************************
	 * powerDelivery *
	 *****************************/
	init_v2gBodyType(&exi_stream.V2G_Message.Body);
	exi_stream.V2G_Message.Body.PowerDeliveryReq_isUsed = 1u;


	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile_isUsed = 0u;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.EVPowerDeliveryParameter_isUsed = 0u;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter_isUsed = 0u;

	exi_stream.V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter.DC_EVStatus = exi_stream.V2G_Message.Body.PreChargeReq.DC_EVStatus;

	exi_stream.V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter.BulkChargingComplete = 0;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter.BulkChargingComplete_isUsed = 1u;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter.ChargingComplete = 1;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter_isUsed = 1u; /* DC parameters are send */

	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargeProgress = v2gchargeProgressType_Start;


	/* we are using a charging profile */
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile_isUsed = 1u;

	exi_stream.V2G_Message.Body.PowerDeliveryReq.SAScheduleTupleID  = chargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].SAScheduleTupleID;

	/* set up 3 entries */
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.arrayLen=3;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[0].ChargingProfileEntryMaxPower.Value=0;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[0].ChargingProfileEntryMaxPower.Unit = v2gunitSymbolType_W;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[0].ChargingProfileEntryMaxPower.Multiplier=2;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[0].ChargingProfileEntryStart=0;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[0].ChargingProfileEntryMaxNumberOfPhasesInUse=1;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[0].ChargingProfileEntryMaxNumberOfPhasesInUse_isUsed=1;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[1].ChargingProfileEntryMaxPower.Value=20000;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[1].ChargingProfileEntryMaxPower.Unit = v2gunitSymbolType_W;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[1].ChargingProfileEntryMaxPower.Multiplier = 1;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[1].ChargingProfileEntryMaxNumberOfPhasesInUse=3;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[1].ChargingProfileEntryMaxNumberOfPhasesInUse_isUsed=1;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[1].ChargingProfileEntryStart=300; /* 5min */
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[2].ChargingProfileEntryMaxPower.Value=0;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[2].ChargingProfileEntryStart=1200; /* 20min */
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[2].ChargingProfileEntryMaxNumberOfPhasesInUse=3;
	exi_stream.V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[2].ChargingProfileEntryMaxNumberOfPhasesInUse_isUsed=1;


	printf("EV side: call EVSE powerDelivery \n");

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
		if(exi_stream.V2G_Message.Body.PowerDeliveryRes_isUsed) {

			/* show results of EVSEs answer message */
			printf("EV side: received response message from EVSE\n");
			printf("\tHeader SessionID=");
			printBinaryArray(exi_stream.V2G_Message.Header.SessionID.bytes, exi_stream.V2G_Message.Header.SessionID.bytesLen);
			printf("\t ResponseCode=%d\n", exi_stream.V2G_Message.Body.PowerDeliveryRes.ResponseCode);

			printDCEVSEStatus(&exi_stream.V2G_Message.Body.PowerDeliveryRes.DC_EVSEStatus);
		} else {
			errn = ERROR_UNEXPECTED_PRE_CHARGE_RESP_MESSAGE;
			return errn;
		}
	}

# if CODE_EXAMPLE == CODE_EXAMPLE_HARDWARE
	set_Ucp(fd, 1); // 9V --> Status C: EV connected, ready
	UCP = get_Ucp(fd);
	printf("+++ change level on CP for state B: EV detected, %f +++\n\n", UCP);
# endif
	/*****************************
	 * weldingDetection *
	 *****************************/
	init_v2gBodyType(&exi_stream.V2G_Message.Body);
	exi_stream.V2G_Message.Body.WeldingDetectionReq_isUsed = 1u;

	exi_stream.V2G_Message.Body.WeldingDetectionReq.DC_EVStatus.EVRESSSOC = 100;

	printf("EV side: call EVSE weldingDetection \n");

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
		if(exi_stream.V2G_Message.Body.WeldingDetectionRes_isUsed) {

			/* show results of EVSEs answer message */
			printf("EV side: received response message from EVSE\n");
			printf("\tHeader SessionID=");
			printBinaryArray(exi_stream.V2G_Message.Header.SessionID.bytes, exi_stream.V2G_Message.Header.SessionID.bytesLen);
			printf("\t ResponseCode=%d\n", exi_stream.V2G_Message.Body.WeldingDetectionRes.ResponseCode);

			printDCEVSEStatus(&exi_stream.V2G_Message.Body.WeldingDetectionRes.DC_EVSEStatus);
			printf("\tEVSEPresentVoltage=%d (%d %d)\n", exi_stream.V2G_Message.Body.WeldingDetectionRes.EVSEPresentVoltage.Value, exi_stream.V2G_Message.Body.WeldingDetectionRes.EVSEPresentVoltage.Unit, exi_stream.V2G_Message.Body.WeldingDetectionRes.EVSEPresentVoltage.Multiplier);

		} else {
			errn = ERROR_UNEXPECTED_CURRENT_DEMAND_RESP_MESSAGE;
			return errn;
		}
	}
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

void printACEVSEStatus(struct v2gAC_EVSEStatusType* status)
{
	printf("\tEVSEStatus:\n");
	printf("\t\tRCD=%d\n", status->RCD);
	printf("\t\tEVSENotification=%d\n", status->EVSENotification);
	printf("\t\tNotificationMaxDelay=%d\n", status->NotificationMaxDelay);
}

void printDCEVSEStatus(struct v2gDC_EVSEStatusType* status)
{
	if(status->EVSEIsolationStatus_isUsed) {
		printf("\tEVSEStatus:\n\t\tEVSEIsolationStatus=%d\n", status->EVSEIsolationStatus);
	}
	printf("\t\tEVSEStatusCode=%d\n", status->EVSEStatusCode);

	if(status->EVSENotification==v2gEVSENotificationType_None) {
		printf("\t\tEVSENotification=None_EVSENotificationType\n");
	}
	printf("\t\tNotificationMaxDelay=%d\n",status->NotificationMaxDelay);

}
