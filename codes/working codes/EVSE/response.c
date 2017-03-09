/*
 * response.c
 *
 *  Created on: 16.02.2016
 *      Author: melanie
 */

# include "response.h"
# include <stdio.h>
# include <stdint.h>
# include "Convert.h"

int sessionSetup(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut) {

	printf("EVSE side: sessionSetup called\n"  );
	printf("\tReceived data:\n");
	printf("\tHeader SessionID=");
	printBinaryArray(exiIn->V2G_Message.Header.SessionID.bytes, exiIn->V2G_Message.Header.SessionID.bytesLen);
	printf("\t\t EVCCID=%d\n", exiIn->V2G_Message.Body.SessionSetupReq.EVCCID.bytes[0]);

	exiOut->V2G_Message_isUsed = 1u;

	/* generate an unique sessionID */
	exiOut->V2G_Message.Header.Notification_isUsed = 0u;
	exiOut->V2G_Message.Header.Signature_isUsed = 0u;

	exiOut->V2G_Message.Header.SessionID.bytes[0] = 1;
	exiOut->V2G_Message.Header.SessionID.bytes[1] = 2;
	exiOut->V2G_Message.Header.SessionID.bytes[2] = 3;
	exiOut->V2G_Message.Header.SessionID.bytes[3] = 4;
	exiOut->V2G_Message.Header.SessionID.bytes[4] = 5;
	exiOut->V2G_Message.Header.SessionID.bytes[5] = 6;
	exiOut->V2G_Message.Header.SessionID.bytes[6] = 7;
	exiOut->V2G_Message.Header.SessionID.bytes[7] = 8;
	exiOut->V2G_Message.Header.SessionID.bytesLen = 8;

	/* Prepare data for EV */
	init_v2gBodyType(&exiOut->V2G_Message.Body);
	exiOut->V2G_Message.Body.SessionSetupRes_isUsed = 1u;
	exiOut->V2G_Message.Body.SessionSetupRes.EVSETimeStamp_isUsed = 0u;

	exiOut->V2G_Message.Body.SessionSetupRes.ResponseCode = v2gresponseCodeType_OK;
	exiOut->V2G_Message.Body.SessionSetupRes.EVSEID.characters[0] = 0;
	exiOut->V2G_Message.Body.SessionSetupRes.EVSEID.characters[1] = 20;
	exiOut->V2G_Message.Body.SessionSetupRes.EVSEID.charactersLen = 2;
	exiOut->V2G_Message.Body.SessionSetupRes.EVSETimeStamp_isUsed = 1u;
	exiOut->V2G_Message.Body.SessionSetupRes.EVSETimeStamp = 123456789;

	return 0;
}

int serviceDiscovery(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut) {

	printf("EVSE side: serviceDiscovery called\n"  );
	printf("\tReceived data:\n");
	printf("\tHeader SessionID=");
	printBinaryArray(exiIn->V2G_Message.Header.SessionID.bytes, exiIn->V2G_Message.Header.SessionID.bytesLen);
	printf("\t\t ServiceCategory=%d\n", exiIn->V2G_Message.Body.ServiceDiscoveryReq.ServiceCategory);

	/* Prepare data for EV */
	exiOut->V2G_Message_isUsed = 1u;
	init_v2gBodyType(&exiOut->V2G_Message.Body);
	exiOut->V2G_Message.Body.ServiceDiscoveryRes_isUsed = 1u;

	exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList_isUsed = 0u; /* we do not provide VAS */
	exiOut->V2G_Message.Body.ServiceDiscoveryRes.ResponseCode = v2gresponseCodeType_OK;


	/* result->ChargeService.SupportedEnergyTransferMode = AC_single_phase_core_EnergyTransferModeType; */
	exiOut->V2G_Message.Body.ServiceDiscoveryRes.ChargeService.ServiceID = 1; /* ID of the charge service */
	exiOut->V2G_Message.Body.ServiceDiscoveryRes.ChargeService.ServiceName_isUsed = 1u;
	exiOut->V2G_Message.Body.ServiceDiscoveryRes.ChargeService.ServiceName.characters[0] = 'A';
	exiOut->V2G_Message.Body.ServiceDiscoveryRes.ChargeService.ServiceName.characters[1] = 'C';
	exiOut->V2G_Message.Body.ServiceDiscoveryRes.ChargeService.ServiceName.characters[2] = '_';
	exiOut->V2G_Message.Body.ServiceDiscoveryRes.ChargeService.ServiceName.characters[3] = 'D';
	exiOut->V2G_Message.Body.ServiceDiscoveryRes.ChargeService.ServiceName.characters[4] = 'C';
	exiOut->V2G_Message.Body.ServiceDiscoveryRes.ChargeService.ServiceName.characters[5] = '\0';
	exiOut->V2G_Message.Body.ServiceDiscoveryRes.ChargeService.ServiceName.charactersLen = 5;
	exiOut->V2G_Message.Body.ServiceDiscoveryRes.ChargeService.ServiceScope_isUsed = 1u;
	exiOut->V2G_Message.Body.ServiceDiscoveryRes.ChargeService.FreeService = 1;
	exiOut->V2G_Message.Body.ServiceDiscoveryRes.ChargeService.ServiceCategory = v2gserviceCategoryType_EVCharging;
	exiOut->V2G_Message.Body.ServiceDiscoveryRes.ChargeService.ServiceScope_isUsed = 1u;
	exiOut->V2G_Message.Body.ServiceDiscoveryRes.ChargeService.ServiceScope.characters[0] = 100;
	exiOut->V2G_Message.Body.ServiceDiscoveryRes.ChargeService.ServiceScope.characters[1] = '\0';
	exiOut->V2G_Message.Body.ServiceDiscoveryRes.ChargeService.ServiceScope.charactersLen = 1;

	exiOut->V2G_Message.Body.ServiceDiscoveryRes.ChargeService.SupportedEnergyTransferMode.EnergyTransferMode.array[0] = v2gEnergyTransferModeType_DC_combo_core;
	exiOut->V2G_Message.Body.ServiceDiscoveryRes.ChargeService.SupportedEnergyTransferMode.EnergyTransferMode.array[1] = v2gEnergyTransferModeType_AC_single_phase_core;
	exiOut->V2G_Message.Body.ServiceDiscoveryRes.ChargeService.SupportedEnergyTransferMode.EnergyTransferMode.arrayLen = 2;

	exiOut->V2G_Message.Body.ServiceDiscoveryRes.PaymentOptionList.PaymentOption.array[0] = v2gpaymentOptionType_ExternalPayment; /* EVSE handles the payment */
	exiOut->V2G_Message.Body.ServiceDiscoveryRes.PaymentOptionList.PaymentOption.array[1] = v2gpaymentOptionType_Contract;
	exiOut->V2G_Message.Body.ServiceDiscoveryRes.PaymentOptionList.PaymentOption.arrayLen = 2;

	if(exiIn->V2G_Message.Body.ServiceDiscoveryReq.ServiceCategory==v2gserviceCategoryType_Internet || exiIn->V2G_Message.Body.ServiceDiscoveryReq.ServiceCategory==v2gserviceCategoryType_OtherCustom || exiIn->V2G_Message.Body.ServiceDiscoveryReq.ServiceCategory_isUsed == 0u) {

		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.arrayLen = 2;
		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.array[0].FreeService=1;
		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.array[0].ServiceID=22; /* ID of the charge service */
		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.array[0].ServiceName_isUsed = 1u;
		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.array[0].ServiceName.characters[0]='W';
		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.array[0].ServiceName.characters[1]='W';
		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.array[0].ServiceName.characters[2]='W';
		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.array[0].ServiceName.charactersLen = 3;
		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.array[0].ServiceCategory= v2gserviceCategoryType_Internet;
		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.array[0].ServiceScope_isUsed = 0u;

		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.array[1].FreeService=0;
		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.array[1].ServiceID=33; /* ID of the charge service */
		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.array[1].ServiceName_isUsed = 1u;
		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.array[1].ServiceName.characters[0]='H';
		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.array[1].ServiceName.characters[1]='T';
		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.array[1].ServiceName.characters[2]='T';
		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.array[1].ServiceName.characters[3]='P';
		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.array[1].ServiceName.characters[4]='S';
		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.array[1].ServiceName.charactersLen = 5;
		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.array[1].ServiceCategory=v2gserviceCategoryType_Internet;
		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList.Service.array[1].ServiceScope_isUsed = 0u;

		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList_isUsed = 1u;

	} else {
		exiOut->V2G_Message.Body.ServiceDiscoveryRes.ServiceList_isUsed = 0u; /* no value added service requested */
	}

	return 0;
}

int serviceDetail(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut) {

	printf("EVSE side: serviceDetail called\n"  );
	printf("\tReceived data:\n");
	printf("\tHeader SessionID=");
	printBinaryArray(exiIn->V2G_Message.Header.SessionID.bytes, exiIn->V2G_Message.Header.SessionID.bytesLen);
	printf("\t\t ServiceDetailID=%d\n",exiIn->V2G_Message.Body.ServiceDetailReq.ServiceID);


	/* Prepare data for EV */
	exiOut->V2G_Message_isUsed = 1u;
	init_v2gBodyType(&exiOut->V2G_Message.Body);
	exiOut->V2G_Message.Body.ServiceDetailRes_isUsed= 1u;
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList_isUsed = 0u;

	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceID = 1234;

	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList_isUsed = 1u;
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.arrayLen = 2;

	/* Parameter Set 1*/
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].ParameterSetID = 1;
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.arrayLen = 2;
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.array[0].Name.charactersLen = 8;
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.array[0].Name.characters[0] = 'P';
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.array[0].Name.characters[1] = 'r';
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.array[0].Name.characters[2] = 'o';
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.array[0].Name.characters[3] = 't';
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.array[0].Name.characters[4]= 'o';
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.array[0].Name.characters[5] = 'c';
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.array[0].Name.characters[6] = 'o';
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.array[0].Name.characters[7] = 'l';
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.array[0].intValue = 15119;
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.array[0].intValue_isUsed = 1u;

	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.array[1].Name.charactersLen = 4;
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.array[1].Name.characters[0] = 'N';
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.array[1].Name.characters[1] = 'a';
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.array[1].Name.characters[2] = 'm';
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.array[1].Name.characters[3] = 'e';

	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.array[1].stringValue_isUsed = 1u;
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.array[1].stringValue.charactersLen = 3;
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.array[1].stringValue.characters[0] = 'V';
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.array[1].stringValue.characters[1] = '2';
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[0].Parameter.array[1].stringValue.characters[2] = 'G';

	/* Parameter Set 2 */
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[1].ParameterSetID = 2;
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[1].Parameter.arrayLen = 1;
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[1].Parameter.array[0].Name.charactersLen = 7;
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[1].Parameter.array[0].Name.characters[0] = 'C';
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[1].Parameter.array[0].Name.characters[1] = 'h';
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[1].Parameter.array[0].Name.characters[2] = 'a';
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[1].Parameter.array[0].Name.characters[3] = 'n';
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[1].Parameter.array[0].Name.characters[4] = 'n';
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[1].Parameter.array[0].Name.characters[5] = 'e';
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[1].Parameter.array[0].Name.characters[6] = 'l';
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[1].Parameter.array[0].physicalValue_isUsed = 1u;
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[1].Parameter.array[0].physicalValue.Value = 1234;
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[1].Parameter.array[0].physicalValue.Unit = v2gunitSymbolType_m;
	exiOut->V2G_Message.Body.ServiceDetailRes.ServiceParameterList.ParameterSet.array[1].Parameter.array[0].physicalValue.Multiplier = 0;

	exiOut->V2G_Message.Body.ServiceDetailRes.ResponseCode = v2gresponseCodeType_OK;

	return 0;
}

int paymentServiceSelection(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut) {
	int i;

	printf("EVSE side: paymentServiceSelection called\n"  );
	printf("\tReceived data:\n");
	printf("\tHeader SessionID=");
	printBinaryArray(exiIn->V2G_Message.Header.SessionID.bytes, exiIn->V2G_Message.Header.SessionID.bytesLen);

	if(exiIn->V2G_Message.Body.PaymentServiceSelectionReq.SelectedPaymentOption == v2gpaymentOptionType_ExternalPayment)  {
		printf("\t\t SelectedPaymentOption=ExternalPayment\n");
	}

	for(i=0; i<exiIn->V2G_Message.Body.PaymentServiceSelectionReq.SelectedServiceList.SelectedService.arrayLen;i++)
	{
		printf("\t\t ServiceID=%d\n", exiIn->V2G_Message.Body.PaymentServiceSelectionReq.SelectedServiceList.SelectedService.array[i].ServiceID);
		if(exiIn->V2G_Message.Body.PaymentServiceSelectionReq.SelectedServiceList.SelectedService.array[i].ParameterSetID_isUsed) {
				printf("\t\t ParameterSetID=%d\n", exiIn->V2G_Message.Body.PaymentServiceSelectionReq.SelectedServiceList.SelectedService.array[i].ParameterSetID);
		}
	}

	/* Prepare data for EV */
	exiOut->V2G_Message_isUsed = 1u;
	init_v2gBodyType(&exiOut->V2G_Message.Body);
	exiOut->V2G_Message.Body.PaymentServiceSelectionRes_isUsed= 1u;
	exiOut->V2G_Message.Body.ServiceDetailRes.ResponseCode = v2gresponseCodeType_OK;

	return 0;
}

int paymentDetails(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut) {

	printf("EVSE side: paymentDetails called\n"  );
	printf("\tReceived data:\n");

	printf("\t\t eMAID=%d\n", exiIn->V2G_Message.Body.PaymentDetailsReq.eMAID.characters[0]);
	printf("\t\t ID=%c%c\n", exiIn->V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.Id.characters[0], exiIn->V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.Id.characters[1]);
	printf("\t\t Certificate=%c%c\n", exiIn->V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.Certificate.bytes[0],  exiIn->V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.Certificate.bytes[1]);
	printf("\t\t SubCertificate 1=%c%c\n", exiIn->V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.SubCertificates.Certificate.array[0].bytes[0], exiIn->V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.SubCertificates.Certificate.array[0].bytes[1]);
	printf("\t\t SubCertificate 2=%c%c\n", exiIn->V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.SubCertificates.Certificate.array[1].bytes[0], exiIn->V2G_Message.Body.PaymentDetailsReq.ContractSignatureCertChain.SubCertificates.Certificate.array[1].bytes[1]);

	/* Prepare data for EV */
	exiOut->V2G_Message_isUsed = 1u;
	init_v2gBodyType(&exiOut->V2G_Message.Body);
	exiOut->V2G_Message.Body.PaymentDetailsRes_isUsed = 1u;

	exiOut->V2G_Message.Body.PaymentDetailsRes.ResponseCode = v2gresponseCodeType_OK;
	exiOut->V2G_Message.Body.PaymentDetailsRes.GenChallenge.bytesLen = 1;
	exiOut->V2G_Message.Body.PaymentDetailsRes.GenChallenge.bytes[0] = 1;
	exiOut->V2G_Message.Body.PaymentDetailsRes.EVSETimeStamp = 123456;

	return 0;
}

int authorization(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut) {

	printf("EVSE: Authorization called\n"  );
	printf("\tReceived data:\n");

	if(exiIn->V2G_Message.Body.AuthorizationReq.GenChallenge_isUsed) {
		printf("\t\t\t GenChallenge=%d\n", exiIn->V2G_Message.Body.AuthorizationReq.GenChallenge.bytes[0]);
	}
	if(exiIn->V2G_Message.Body.AuthorizationReq.Id_isUsed ) {
		printf("\t\t\t ID=%c%c%c\n", exiIn->V2G_Message.Body.AuthorizationReq.Id.characters[0], exiIn->V2G_Message.Body.AuthorizationReq.Id.characters[1], exiIn->V2G_Message.Body.AuthorizationReq.Id.characters[2]);
	}


	/* Prepare data for EV */
	exiOut->V2G_Message_isUsed = 1u;
	init_v2gBodyType(&exiOut->V2G_Message.Body);
	exiOut->V2G_Message.Body.AuthorizationRes_isUsed = 1u;

	exiOut->V2G_Message.Body.AuthorizationRes.ResponseCode = v2gresponseCodeType_OK;
	exiOut->V2G_Message.Body.AuthorizationRes.EVSEProcessing = v2gEVSEProcessingType_Finished;

	return 0;
}

int chargeParameterDiscovery(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut) {

	printf("EVSE side: chargeParameterDiscovery called\n"  );
	printf("\tReceived data:\n");
	printf("\t\t EVRequestedEnergyTransferType=%d\n", exiIn->V2G_Message.Body.ChargeParameterDiscoveryReq.RequestedEnergyTransferMode);

	/* check,if DC or AC is requested */
	if(exiIn->V2G_Message.Body.ChargeParameterDiscoveryReq.RequestedEnergyTransferMode == v2gEnergyTransferModeType_DC_core || exiIn->V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter_isUsed == 1) {
		printf("\t\t MaxEntriesSAScheduleTuple=%d\n", exiIn->V2G_Message.Body.ChargeParameterDiscoveryReq.MaxEntriesSAScheduleTuple);
		printf("\t\t EVStatus:\n");
		printf("\t\t\t EVReady=%d\n", exiIn->V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.DC_EVStatus.EVReady);
		printf("\t\t\t EVRESSSOC=%d\n", exiIn->V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.DC_EVStatus.EVRESSSOC);
		printf("\t\t\t EVErrorCode=%d\n", exiIn->V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.DC_EVStatus.EVErrorCode);

		printf("\t\t DepartureTime=%d\n", exiIn->V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.DepartureTime);
		printf("\t\t EVMaximumCurrentLimit=%d\n", exiIn->V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVMaximumCurrentLimit.Value);
		printf("\t\t EVMaximumPowerLimit=%d\n", exiIn->V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVMaximumPowerLimit.Value);
		printf("\t\t EVMaximumVoltageLimit=%d\n", exiIn->V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVMaximumVoltageLimit.Value);
		printf("\t\t EVEnergyCapacity=%d\n", exiIn->V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVEnergyCapacity.Value);
		printf("\t\t EVEnergyRequest=%d\n", exiIn->V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.EVEnergyRequest.Value);
		printf("\t\t FullSOC=%d\n", exiIn->V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.FullSOC);
		printf("\t\t BulkSOC=%d\n", exiIn->V2G_Message.Body.ChargeParameterDiscoveryReq.DC_EVChargeParameter.BulkSOC);


		/* Prepare data for EV */
		exiOut->V2G_Message_isUsed = 1u;
		init_v2gBodyType(&exiOut->V2G_Message.Body);
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes_isUsed = 1u;


		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.ResponseCode = v2gresponseCodeType_OK;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.EVSEProcessing = v2gEVSEProcessingType_Finished;

		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter_isUsed = 1u;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.AC_EVSEChargeParameter_isUsed = 0u;

		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.DC_EVSEStatus.EVSEStatusCode = v2gDC_EVSEStatusCodeType_EVSE_Ready;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.DC_EVSEStatus.EVSEIsolationStatus = v2gisolationLevelType_Valid;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.DC_EVSEStatus.EVSEIsolationStatus_isUsed = 1;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.DC_EVSEStatus.EVSENotification = v2gEVSENotificationType_None;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.DC_EVSEStatus.NotificationMaxDelay = 10;


		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEMinimumCurrentLimit.Multiplier = 0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEMinimumCurrentLimit.Unit = v2gunitSymbolType_A;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEMinimumCurrentLimit.Value = 50;

		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEMaximumPowerLimit.Multiplier = 0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEMaximumPowerLimit.Unit = v2gunitSymbolType_W;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEMaximumPowerLimit.Value = 20000;

		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEMaximumVoltageLimit.Multiplier = 0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEMaximumVoltageLimit.Unit = v2gunitSymbolType_V;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEMaximumVoltageLimit.Value = 400;

		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEMinimumCurrentLimit.Multiplier = 0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEMinimumCurrentLimit.Unit = v2gunitSymbolType_A;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEMinimumCurrentLimit.Value = 5;

		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEMinimumVoltageLimit.Multiplier = 0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEMinimumVoltageLimit.Unit = v2gunitSymbolType_V;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEMinimumVoltageLimit.Value = 200;

		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSECurrentRegulationTolerance.Multiplier = 0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSECurrentRegulationTolerance.Unit = v2gunitSymbolType_A;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSECurrentRegulationTolerance.Value = 2;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSECurrentRegulationTolerance_isUsed = 1u;

		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEPeakCurrentRipple.Multiplier = 0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEPeakCurrentRipple.Unit = v2gunitSymbolType_A;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEPeakCurrentRipple.Value = 1;

		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEEnergyToBeDelivered.Multiplier = 0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEEnergyToBeDelivered.Unit = v2gunitSymbolType_W;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEEnergyToBeDelivered.Value = 5000;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter.EVSEEnergyToBeDelivered_isUsed = 1u;


		/* set up a PMax schedule */
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList_isUsed = 1u;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].SAScheduleTupleID = 10;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].SalesTariff_isUsed = 0; /* no tariffs */

		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.arrayLen = 2;
		/* set up two PMax entries: #1 */
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[0].PMax.Value=20000;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[0].PMax.Unit = v2gunitSymbolType_W;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[0].PMax.Multiplier =0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[0].RelativeTimeInterval_isUsed = 1u;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[0].RelativeTimeInterval.start=0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[0].RelativeTimeInterval.duration_isUsed = 0;

		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[1].PMax.Value=0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[1].PMax.Unit = v2gunitSymbolType_W;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[1].PMax.Multiplier =0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[1].RelativeTimeInterval_isUsed = 1u;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[1].RelativeTimeInterval.start=1200; /* 20 min */
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[1].RelativeTimeInterval.duration_isUsed =0;

		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.arrayLen =2; /* we set up two time entries */


		/* #2 */
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].SAScheduleTupleID = 15;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].PMaxSchedule.PMaxScheduleEntry.array[0].PMax.Value = 10000;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].PMaxSchedule.PMaxScheduleEntry.array[0].PMax.Unit = v2gunitSymbolType_W;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].PMaxSchedule.PMaxScheduleEntry.array[0].PMax.Multiplier =0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].PMaxSchedule.PMaxScheduleEntry.array[0].RelativeTimeInterval.start=0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].PMaxSchedule.PMaxScheduleEntry.array[0].RelativeTimeInterval_isUsed = 1;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].PMaxSchedule.PMaxScheduleEntry.array[0].RelativeTimeInterval.duration_isUsed = 0u;

		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].PMaxSchedule.PMaxScheduleEntry.array[1].PMax.Value=0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].PMaxSchedule.PMaxScheduleEntry.array[1].PMax.Unit = v2gunitSymbolType_W;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].PMaxSchedule.PMaxScheduleEntry.array[1].PMax.Multiplier =1;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].PMaxSchedule.PMaxScheduleEntry.array[1].RelativeTimeInterval.start=1800; /* 30 min */
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].PMaxSchedule.PMaxScheduleEntry.array[1].RelativeTimeInterval_isUsed = 1u;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].PMaxSchedule.PMaxScheduleEntry.array[1].RelativeTimeInterval.duration=3600;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].PMaxSchedule.PMaxScheduleEntry.array[1].RelativeTimeInterval.duration_isUsed = 1u;

		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].PMaxSchedule.PMaxScheduleEntry.arrayLen =2; /* we set up two time entries */




	} else { /* AC related */

		printf("\t\t DepartureTime=%d\n", exiIn->V2G_Message.Body.ChargeParameterDiscoveryReq.AC_EVChargeParameter.DepartureTime);
		printf("\t\t EAmount=%d\n", exiIn->V2G_Message.Body.ChargeParameterDiscoveryReq.AC_EVChargeParameter.EAmount.Value);
		printf("\t\t EVMaxCurrent=%d\n", exiIn->V2G_Message.Body.ChargeParameterDiscoveryReq.AC_EVChargeParameter.EVMaxCurrent.Value);
		printf("\t\t EVMaxVoltage=%d\n", exiIn->V2G_Message.Body.ChargeParameterDiscoveryReq.AC_EVChargeParameter.EVMaxVoltage.Value);
		printf("\t\t EVMinCurrent=%d\n", exiIn->V2G_Message.Body.ChargeParameterDiscoveryReq.AC_EVChargeParameter.EVMinCurrent.Value);


		/* Prepare data for EV */
		exiOut->V2G_Message_isUsed = 1u;
		init_v2gBodyType(&exiOut->V2G_Message.Body);
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes_isUsed = 1u;


		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.ResponseCode = v2gresponseCodeType_OK;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.EVSEProcessing = v2gEVSEProcessingType_Finished;


		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.AC_EVSEChargeParameter_isUsed = 1u;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.DC_EVSEChargeParameter_isUsed = 0u;


		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.AC_EVSEChargeParameter.AC_EVSEStatus.RCD =1;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.AC_EVSEChargeParameter.AC_EVSEStatus.EVSENotification = v2gEVSENotificationType_None;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.AC_EVSEChargeParameter.AC_EVSEStatus.NotificationMaxDelay=123;

		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.AC_EVSEChargeParameter.EVSEMaxCurrent.Multiplier = 0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.AC_EVSEChargeParameter.EVSEMaxCurrent.Unit = v2gunitSymbolType_A;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.AC_EVSEChargeParameter.EVSEMaxCurrent.Value = 100;

		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.AC_EVSEChargeParameter.EVSENominalVoltage.Multiplier = 0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.AC_EVSEChargeParameter.EVSENominalVoltage.Unit = v2gunitSymbolType_V;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.AC_EVSEChargeParameter.EVSENominalVoltage.Value = 300;

		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.EVSEProcessing = 1;

		/* set up a PMax schedule */
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList_isUsed = 1u;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].SAScheduleTupleID = 10;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].SalesTariff_isUsed = 0; /* no tariffs */


		/* set up two PMax entries: #1 */
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[0].PMax.Value=20000;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[0].PMax.Unit = v2gunitSymbolType_W;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[0].PMax.Multiplier =0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[0].RelativeTimeInterval.start=0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[0].RelativeTimeInterval_isUsed = 1u;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[0].RelativeTimeInterval.duration_isUsed =0;

		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[1].PMax.Value=0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[1].PMax.Unit = v2gunitSymbolType_W;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[1].PMax.Multiplier =0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[1].RelativeTimeInterval.start=1200; /* 20 min */
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[1].RelativeTimeInterval_isUsed = 1u;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[1].RelativeTimeInterval.duration_isUsed =0;

		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.arrayLen =2; /* we set up two time entries */

		/* set up sale entries */
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].SalesTariff.NumEPriceLevels=2;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].SalesTariff.NumEPriceLevels_isUsed = 1u;

		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].SalesTariff.SalesTariffID=20;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].SalesTariff.Id.characters[0]=100;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].SalesTariff.Id.charactersLen=1;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].SalesTariff.Id_isUsed =1;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].SalesTariff.SalesTariffEntry.array[0].EPriceLevel=2;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].SalesTariff.SalesTariffEntry.array[0].EPriceLevel_isUsed =1;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].SalesTariff.SalesTariffEntry.array[0].ConsumptionCost.arrayLen =0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].SalesTariff.SalesTariffEntry.array[0].RelativeTimeInterval.start=0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].SalesTariff.SalesTariffEntry.array[0].RelativeTimeInterval_isUsed = 1;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].SalesTariff.SalesTariffEntry.array[0].RelativeTimeInterval.duration=10;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[0].SalesTariff.SalesTariffEntry.array[0].RelativeTimeInterval.duration_isUsed =1;


		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].SalesTariff.SalesTariffEntry.array[1].EPriceLevel=3;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].SalesTariff.SalesTariffEntry.array[1].RelativeTimeInterval.start=11;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].SalesTariff.SalesTariffEntry.array[1].RelativeTimeInterval.duration=10;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].SalesTariff.SalesTariffEntry.array[1].RelativeTimeInterval_isUsed = 1;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].SalesTariff.SalesTariffEntry.array[1].RelativeTimeInterval.duration_isUsed =1;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].SalesTariff.SalesTariffEntry.array[1].ConsumptionCost.array[0].Cost.array[0].amount=10;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].SalesTariff.SalesTariffEntry.array[1].ConsumptionCost.array[0].Cost.array[0].amountMultiplier=1;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].SalesTariff.SalesTariffEntry.array[1].ConsumptionCost.array[0].Cost.array[0].amountMultiplier_isUsed =1;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].SalesTariff.SalesTariffEntry.array[1].ConsumptionCost.array[0].Cost.array[0].costKind= v2gcostKindType_RenewableGenerationPercentage;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].SalesTariff.SalesTariffEntry.array[1].ConsumptionCost.array[0].startValue.Value=123;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].SalesTariff.SalesTariffEntry.array[1].ConsumptionCost.array[0].Cost.arrayLen = 1;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].SalesTariff.SalesTariffEntry.array[1].EPriceLevel_isUsed =1;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].SalesTariff.SalesTariffEntry.array[1].ConsumptionCost.arrayLen = 1;



		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].PMaxSchedule.PMaxScheduleEntry.arrayLen = 1;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].PMaxSchedule.PMaxScheduleEntry.array[0].TimeInterval_isUsed = 1u;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].PMaxSchedule.PMaxScheduleEntry.array[0].PMax.Value=0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].PMaxSchedule.PMaxScheduleEntry.array[0].PMax.Multiplier = 0;
		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.array[1].PMaxSchedule.PMaxScheduleEntry.array[0].PMax.Value = 0;

		exiOut->V2G_Message.Body.ChargeParameterDiscoveryRes.SAScheduleList.SAScheduleTuple.arrayLen = 2;
	}

	return 0;
}

int powerDelivery(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut) {
	int i;

	printf("EVSE side: powerDelivery called\n"  );
	printf("\tReceived data:\n");

	printf("\t\t  ChargeProgress=%d\n", exiIn->V2G_Message.Body.PowerDeliveryReq.ChargeProgress);
	printf("\t\t  SAScheduleTupleID=%d\n", exiIn->V2G_Message.Body.PowerDeliveryReq.SAScheduleTupleID);

	/* Prepare data for EV */
	exiOut->V2G_Message_isUsed = 1u;
	init_v2gBodyType(&exiOut->V2G_Message.Body);
	exiOut->V2G_Message.Body.PowerDeliveryRes_isUsed = 1u;


	if(exiIn->V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter_isUsed) {

		printf("\t\t EVStatus:\n");
		printf("\t\t\t EVReady=%d\n", exiIn->V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter.DC_EVStatus.EVReady);
		printf("\t\t\t EVRESSSOC=%d\n",exiIn->V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter.DC_EVStatus.EVRESSSOC);
		printf("\t\t\t EVErrorCode=%d\n", exiIn->V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter.DC_EVStatus.EVErrorCode);

		printf("\t\t BulkChargingComplete=%d\n", exiIn->V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter.BulkChargingComplete);
		printf("\t\t ChargingComplete=%d\n", exiIn->V2G_Message.Body.PowerDeliveryReq.DC_EVPowerDeliveryParameter.ChargingComplete);

		if(exiIn->V2G_Message.Body.PowerDeliveryReq.ChargingProfile_isUsed) {
			printf("\t\t\tChargingProfile:\n");
			printf("\t\t\t SAScheduleTupleID=%d\n",exiIn->V2G_Message.Body.PowerDeliveryReq.SAScheduleTupleID );
			for(i=0;i<exiIn->V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.arrayLen;i++) {
				printf("\t\t\t Entry#%d\n",i);
				printf("\t\t\t\t ChargingProfileEntryMaxPower=%d (%d %d) \n", exiIn->V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[i].ChargingProfileEntryMaxPower.Value, exiIn->V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[i].ChargingProfileEntryMaxPower.Unit, exiIn->V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[i].ChargingProfileEntryMaxPower.Multiplier);
				printf("\t\t\t\t ChargingProfileEntryStart=%d\n",exiIn->V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[i].ChargingProfileEntryStart);
				printf("\t\t\t\t ChargingProfileEntryMaxNumberOfPhasesInUse=%d\n", exiIn->V2G_Message.Body.PowerDeliveryReq.ChargingProfile.ProfileEntry.array[i].ChargingProfileEntryMaxNumberOfPhasesInUse);

			}
		}

		exiOut->V2G_Message.Body.PowerDeliveryRes.ResponseCode = v2gresponseCodeType_OK;
		exiOut->V2G_Message.Body.PowerDeliveryRes.DC_EVSEStatus.EVSEIsolationStatus =0;
		exiOut->V2G_Message.Body.PowerDeliveryRes.DC_EVSEStatus.EVSEIsolationStatus_isUsed = 1;
		exiOut->V2G_Message.Body.PowerDeliveryRes.DC_EVSEStatus.EVSEStatusCode = v2gDC_EVSEStatusCodeType_EVSE_Ready;
		exiOut->V2G_Message.Body.PowerDeliveryRes.DC_EVSEStatus.EVSENotification = v2gEVSENotificationType_None;
		exiOut->V2G_Message.Body.PowerDeliveryRes.DC_EVSEStatus.NotificationMaxDelay = 123;

		exiOut->V2G_Message.Body.PowerDeliveryRes.DC_EVSEStatus_isUsed = 1;
		exiOut->V2G_Message.Body.PowerDeliveryRes.AC_EVSEStatus_isUsed = 0;


	} else {
		exiOut->V2G_Message.Body.PowerDeliveryRes.ResponseCode = v2gresponseCodeType_OK;
		exiOut->V2G_Message.Body.PowerDeliveryRes.AC_EVSEStatus.RCD=0;
		exiOut->V2G_Message.Body.PowerDeliveryRes.AC_EVSEStatus.EVSENotification=3;
		exiOut->V2G_Message.Body.PowerDeliveryRes.AC_EVSEStatus.NotificationMaxDelay=12;

		exiOut->V2G_Message.Body.PowerDeliveryRes.AC_EVSEStatus_isUsed = 1;
		exiOut->V2G_Message.Body.PowerDeliveryRes.DC_EVSEStatus_isUsed = 0;
	}

	return 0;
}

int chargingStatus(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut) {

	printf("EVSE side: chargingStatus called\n"  );

	/* Prepare data for EV */
	exiOut->V2G_Message_isUsed = 1u;
	init_v2gBodyType(&exiOut->V2G_Message.Body);
	exiOut->V2G_Message.Body.ChargingStatusRes_isUsed = 1u;

	exiOut->V2G_Message.Body.ChargingStatusRes.ResponseCode = v2gresponseCodeType_OK;
	exiOut->V2G_Message.Body.ChargingStatusRes.EVSEID.characters[0]=12;
	exiOut->V2G_Message.Body.ChargingStatusRes.EVSEID.charactersLen =1;

	exiOut->V2G_Message.Body.ChargingStatusRes.AC_EVSEStatus.RCD=1;
	exiOut->V2G_Message.Body.ChargingStatusRes.AC_EVSEStatus.EVSENotification = v2gEVSENotificationType_None;
	exiOut->V2G_Message.Body.ChargingStatusRes.AC_EVSEStatus.NotificationMaxDelay=123;
	exiOut->V2G_Message.Body.ChargingStatusRes.ReceiptRequired=1;
	exiOut->V2G_Message.Body.ChargingStatusRes.ReceiptRequired_isUsed =1;
	exiOut->V2G_Message.Body.ChargingStatusRes.EVSEMaxCurrent.Multiplier = 2;
	exiOut->V2G_Message.Body.ChargingStatusRes.EVSEMaxCurrent.Unit = v2gunitSymbolType_A;

	exiOut->V2G_Message.Body.ChargingStatusRes.EVSEMaxCurrent.Value = 400;
	exiOut->V2G_Message.Body.ChargingStatusRes.EVSEMaxCurrent_isUsed =1;
	exiOut->V2G_Message.Body.ChargingStatusRes.SAScheduleTupleID=10;

	exiOut->V2G_Message.Body.ChargingStatusRes.MeterInfo_isUsed =1;
	exiOut->V2G_Message.Body.ChargingStatusRes.MeterInfo.MeterID.charactersLen =1;
	exiOut->V2G_Message.Body.ChargingStatusRes.MeterInfo.MeterID.characters[0]=2;

	exiOut->V2G_Message.Body.ChargingStatusRes.MeterInfo.MeterReading = 5000;
	exiOut->V2G_Message.Body.ChargingStatusRes.MeterInfo.MeterStatus = 4321;
	exiOut->V2G_Message.Body.ChargingStatusRes.MeterInfo.TMeter =123456789;
	exiOut->V2G_Message.Body.ChargingStatusRes.MeterInfo.SigMeterReading.bytes[0]=123;
	exiOut->V2G_Message.Body.ChargingStatusRes.MeterInfo.SigMeterReading.bytesLen=1;
	exiOut->V2G_Message.Body.ChargingStatusRes.MeterInfo.MeterReading_isUsed = 1;
	exiOut->V2G_Message.Body.ChargingStatusRes.MeterInfo.MeterStatus_isUsed =1;
	exiOut->V2G_Message.Body.ChargingStatusRes.MeterInfo.TMeter_isUsed=1;
	exiOut->V2G_Message.Body.ChargingStatusRes.MeterInfo.SigMeterReading_isUsed =1;

	return 0;
}

int meteringReceipt(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut) {

	printf("EVSE side: meteringReceipt called\n"  );
	printf("\tReceived data:\n");

	printf("\t\t ID=%c%c%c\n", exiIn->V2G_Message.Body.MeteringReceiptReq.Id.characters[0], exiIn->V2G_Message.Body.MeteringReceiptReq.Id.characters[1], exiIn->V2G_Message.Body.MeteringReceiptReq.Id.characters[2]);
	printf("\t\t SAScheduleTupleID=%d\n", exiIn->V2G_Message.Body.MeteringReceiptReq.SAScheduleTupleID);
	printf("\t\t SessionID=%d\n", exiIn->V2G_Message.Body.MeteringReceiptReq.SessionID.bytes[1]);
	printf("\t\t MeterInfo.MeterStatus=%d\n", exiIn->V2G_Message.Body.MeteringReceiptReq.MeterInfo.MeterStatus);
	printf("\t\t MeterInfo.MeterID=%d\n",		exiIn->V2G_Message.Body.MeteringReceiptReq.MeterInfo.MeterID.characters[0]);
	printf("\t\t MeterInfo.isused.MeterReading=%d\n", exiIn->V2G_Message.Body.MeteringReceiptReq.MeterInfo.MeterReading_isUsed);
	printf("\t\t MeterReading.Value=%lu\n",		(long unsigned int)exiIn->V2G_Message.Body.MeteringReceiptReq.MeterInfo.MeterReading);
	printf("\t\t MeterInfo.TMeter=%li\n",		(long int)exiIn->V2G_Message.Body.MeteringReceiptReq.MeterInfo.TMeter);

	/* Prepare data for EV */
	exiOut->V2G_Message_isUsed = 1u;
	init_v2gBodyType(&exiOut->V2G_Message.Body);
	exiOut->V2G_Message.Body.MeteringReceiptRes_isUsed = 1u;

	exiOut->V2G_Message.Body.MeteringReceiptRes.ResponseCode = v2gresponseCodeType_OK;

	exiOut->V2G_Message.Body.MeteringReceiptRes.AC_EVSEStatus.RCD=1;
	exiOut->V2G_Message.Body.MeteringReceiptRes.AC_EVSEStatus.EVSENotification= v2gEVSENotificationType_None;
	exiOut->V2G_Message.Body.MeteringReceiptRes.AC_EVSEStatus.NotificationMaxDelay=123;

	return 0;
}

int cableCheck(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut) {

	printf("EVSE side: cableCheck called\n"  );
	printf("\tReceived data:\n");

	printf("\t\t EVStatus:\n");
	printf("\t\t\t EVReady=%d\n", exiIn->V2G_Message.Body.CableCheckReq.DC_EVStatus.EVReady);
	printf("\t\t\t EVRESSSOC=%d\n", exiIn->V2G_Message.Body.CableCheckReq.DC_EVStatus.EVRESSSOC);
	printf("\t\t\t EVErrorCode=%d\n", exiIn->V2G_Message.Body.CableCheckReq.DC_EVStatus.EVErrorCode);

	/* Prepare data for EV */
	exiOut->V2G_Message_isUsed = 1u;
	init_v2gBodyType(&exiOut->V2G_Message.Body);
	exiOut->V2G_Message.Body.CableCheckRes_isUsed = 1u;

	exiOut->V2G_Message.Body.CableCheckRes.ResponseCode = v2gresponseCodeType_OK;

	exiOut->V2G_Message.Body.CableCheckRes.EVSEProcessing = v2gEVSEProcessingType_Finished;
	exiOut->V2G_Message.Body.CableCheckRes.DC_EVSEStatus.EVSEIsolationStatus= v2gisolationLevelType_Valid;
	exiOut->V2G_Message.Body.CableCheckRes.DC_EVSEStatus.EVSEIsolationStatus_isUsed = 1u;
	exiOut->V2G_Message.Body.CableCheckRes.DC_EVSEStatus.EVSEStatusCode = v2gDC_EVSEStatusCodeType_EVSE_Ready;
	exiOut->V2G_Message.Body.CableCheckRes.DC_EVSEStatus.EVSENotification= v2gEVSENotificationType_None;
	exiOut->V2G_Message.Body.CableCheckRes.DC_EVSEStatus.NotificationMaxDelay = 1234;

	return 0;
}

int preCharge(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut) {

	printf("EVSE side: preCharge called\n"  );
	printf("\tReceived data:\n");

	printf("\t\t EVStatus:\n");
	printf("\t\t\t EVReady=%d\n", exiIn->V2G_Message.Body.PreChargeReq.DC_EVStatus.EVReady);
	printf("\t\t\t EVRESSSOC=%d\n", exiIn->V2G_Message.Body.PreChargeReq.DC_EVStatus.EVRESSSOC);
	printf("\t\t\t EVErrorCode=%d\n", exiIn->V2G_Message.Body.PreChargeReq.DC_EVStatus.EVErrorCode);

	printf("\t\t EVTargetCurrent=%d (%d %d)\n", exiIn->V2G_Message.Body.PreChargeReq.EVTargetCurrent.Value, exiIn->V2G_Message.Body.PreChargeReq.EVTargetCurrent.Unit, exiIn->V2G_Message.Body.PreChargeReq.EVTargetCurrent.Multiplier);
	printf("\t\t EVTargetVoltage=%d (%d %d)\n", exiIn->V2G_Message.Body.PreChargeReq.EVTargetVoltage.Value, exiIn->V2G_Message.Body.PreChargeReq.EVTargetVoltage.Unit, exiIn->V2G_Message.Body.PreChargeReq.EVTargetVoltage.Multiplier);

	/* Prepare data for EV */
	exiOut->V2G_Message_isUsed = 1u;
	init_v2gBodyType(&exiOut->V2G_Message.Body);
	exiOut->V2G_Message.Body.PreChargeRes_isUsed = 1u;

	exiOut->V2G_Message.Body.PreChargeRes.ResponseCode = v2gresponseCodeType_OK;


	exiOut->V2G_Message.Body.PreChargeRes.DC_EVSEStatus.EVSEIsolationStatus= v2gisolationLevelType_Valid;
	exiOut->V2G_Message.Body.PreChargeRes.DC_EVSEStatus.EVSEIsolationStatus_isUsed = 1u;
	exiOut->V2G_Message.Body.PreChargeRes.DC_EVSEStatus.EVSEStatusCode = v2gDC_EVSEStatusCodeType_EVSE_Ready;
	exiOut->V2G_Message.Body.PreChargeRes.DC_EVSEStatus.EVSENotification = v2gEVSENotificationType_None;
	exiOut->V2G_Message.Body.PreChargeRes.DC_EVSEStatus.NotificationMaxDelay= 1234;

	exiOut->V2G_Message.Body.PreChargeRes.EVSEPresentVoltage.Multiplier = 0;
	exiOut->V2G_Message.Body.PreChargeRes.EVSEPresentVoltage.Unit = v2gunitSymbolType_V;
	exiOut->V2G_Message.Body.PreChargeRes.EVSEPresentVoltage.Value= 100;

	return 0;
}

int currentDemand(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut) {

	printf("EVSE side: currentDemand called\n"  );
	printf("\tReceived data:\n");
	printf("\t\t EVStatus:\n");
	printf("\t\t\t EVReady=%d\n", exiIn->V2G_Message.Body.CurrentDemandReq.DC_EVStatus.EVReady);
	printf("\t\t\t EVRESSSOC=%d\n", exiIn->V2G_Message.Body.CurrentDemandReq.DC_EVStatus.EVRESSSOC);
	printf("\t\t\t EVErrorCode=%d\n", exiIn->V2G_Message.Body.CurrentDemandReq.DC_EVStatus.EVErrorCode);


	printf("\t\t EVTargetCurrent=%d\n", exiIn->V2G_Message.Body.CurrentDemandReq.EVTargetCurrent.Value);
	printf("\t\t EVMaximumVoltageLimit=%d\n", exiIn->V2G_Message.Body.CurrentDemandReq.EVMaximumVoltageLimit.Value);
	printf("\t\t EVMaximumPowerLimit=%d\n", exiIn->V2G_Message.Body.CurrentDemandReq.EVMaximumPowerLimit.Value);
	printf("\t\t EVMaximumCurrentLimit=%d\n", exiIn->V2G_Message.Body.CurrentDemandReq.EVMaximumCurrentLimit.Value);
	printf("\t\t BulkChargingComplete=%d\n", exiIn->V2G_Message.Body.CurrentDemandReq.BulkChargingComplete);
	printf("\t\t ChargingComplete=%d\n", exiIn->V2G_Message.Body.CurrentDemandReq.ChargingComplete);
	printf("\t\t RemainingTimeToFullSoC=%d\n", exiIn->V2G_Message.Body.CurrentDemandReq.RemainingTimeToFullSoC.Value);
	printf("\t\t RemainingTimeToBulkSoC=%d\n", exiIn->V2G_Message.Body.CurrentDemandReq.RemainingTimeToBulkSoC.Value);

	printf("\t\t EVTargetVoltage=%d\n", exiIn->V2G_Message.Body.CurrentDemandReq.EVTargetVoltage.Value);

	/* Prepare data for EV */
	exiOut->V2G_Message_isUsed = 1u;
	init_v2gBodyType(&exiOut->V2G_Message.Body);
	exiOut->V2G_Message.Body.CurrentDemandRes_isUsed = 1u;

	exiOut->V2G_Message.Body.CurrentDemandRes.ResponseCode = v2gresponseCodeType_OK;

	exiOut->V2G_Message.Body.CurrentDemandRes.DC_EVSEStatus.EVSEIsolationStatus= v2gisolationLevelType_Valid;
	exiOut->V2G_Message.Body.CurrentDemandRes.DC_EVSEStatus.EVSEIsolationStatus_isUsed = 1;
	exiOut->V2G_Message.Body.CurrentDemandRes.DC_EVSEStatus.EVSEStatusCode = v2gDC_EVSEStatusCodeType_EVSE_Ready;
	exiOut->V2G_Message.Body.CurrentDemandRes.DC_EVSEStatus.EVSENotification= v2gEVSENotificationType_None;
	exiOut->V2G_Message.Body.CurrentDemandRes.DC_EVSEStatus.NotificationMaxDelay=1234;

	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEPresentVoltage.Multiplier = 0;
	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEPresentVoltage.Unit = v2gunitSymbolType_V;
	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEPresentVoltage.Value = 400;


	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEPresentCurrent.Multiplier = 0;
	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEPresentCurrent.Unit = v2gunitSymbolType_A;
	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEPresentCurrent.Value = 45;

	exiOut->V2G_Message.Body.CurrentDemandRes.EVSECurrentLimitAchieved=0;
	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEVoltageLimitAchieved=1;
	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEPowerLimitAchieved=0;

	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEMaximumVoltageLimit.Multiplier = 0;
	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEMaximumVoltageLimit.Unit = v2gunitSymbolType_V;
	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEMaximumVoltageLimit.Value = 400;
	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEMaximumVoltageLimit_isUsed = 1u;

	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEMaximumCurrentLimit.Multiplier = 0;
	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEMaximumCurrentLimit.Unit = v2gunitSymbolType_A;
	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEMaximumCurrentLimit.Value = 50;
	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEMaximumCurrentLimit_isUsed = 1u;

	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEMaximumPowerLimit.Multiplier = 0;
	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEMaximumPowerLimit.Unit = v2gunitSymbolType_W;
	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEMaximumPowerLimit.Value = 20000;
	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEMaximumPowerLimit_isUsed = 1u;


	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEID.characters[0]=12;
	exiOut->V2G_Message.Body.CurrentDemandRes.EVSEID.charactersLen = 1;

	exiOut->V2G_Message.Body.CurrentDemandRes.SAScheduleTupleID = 123;


	exiOut->V2G_Message.Body.CurrentDemandRes.MeterInfo_isUsed = 1u;
	exiOut->V2G_Message.Body.CurrentDemandRes.MeterInfo.MeterID.charactersLen =1;
	exiOut->V2G_Message.Body.CurrentDemandRes.MeterInfo.MeterID.characters[0]=2;

	exiOut->V2G_Message.Body.CurrentDemandRes.MeterInfo.MeterReading = 500;
	exiOut->V2G_Message.Body.CurrentDemandRes.MeterInfo.MeterStatus = 4321;
	exiOut->V2G_Message.Body.CurrentDemandRes.MeterInfo.TMeter =123456789;
	exiOut->V2G_Message.Body.CurrentDemandRes.MeterInfo.MeterReading_isUsed = 1;
	exiOut->V2G_Message.Body.CurrentDemandRes.MeterInfo.MeterStatus_isUsed =1;
	exiOut->V2G_Message.Body.CurrentDemandRes.MeterInfo.TMeter_isUsed =1;
	exiOut->V2G_Message.Body.CurrentDemandRes.MeterInfo.SigMeterReading_isUsed =0;

	exiOut->V2G_Message.Body.CurrentDemandRes.ReceiptRequired = 1;
	exiOut->V2G_Message.Body.CurrentDemandRes.ReceiptRequired_isUsed =1;

	return 0;
}

int weldingDetection(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut) {

	printf("EVSE side: weldingDetection called\n"  );
	printf("\tReceived data:\n");
	printf("\t\t EVStatus:\n");
	printf("\t\t\t EVReady=%d\n", exiIn->V2G_Message.Body.WeldingDetectionReq.DC_EVStatus.EVReady);
	printf("\t\t\t EVRESSSOC=%d\n", exiIn->V2G_Message.Body.WeldingDetectionReq.DC_EVStatus.EVRESSSOC);
	printf("\t\t\t EVErrorCode=%d\n", exiIn->V2G_Message.Body.WeldingDetectionReq.DC_EVStatus.EVErrorCode);

	/* Prepare data for EV */
	exiOut->V2G_Message_isUsed = 1u;
	init_v2gBodyType(&exiOut->V2G_Message.Body);
	exiOut->V2G_Message.Body.WeldingDetectionRes_isUsed = 1u;

	exiOut->V2G_Message.Body.WeldingDetectionRes.ResponseCode = v2gresponseCodeType_OK;

	exiOut->V2G_Message.Body.WeldingDetectionRes.DC_EVSEStatus.EVSEIsolationStatus= v2gisolationLevelType_Valid;
	exiOut->V2G_Message.Body.WeldingDetectionRes.DC_EVSEStatus.EVSEIsolationStatus_isUsed = 1;
	exiOut->V2G_Message.Body.WeldingDetectionRes.DC_EVSEStatus.EVSEStatusCode = v2gDC_EVSEStatusCodeType_EVSE_Ready;
	exiOut->V2G_Message.Body.WeldingDetectionRes.DC_EVSEStatus.EVSENotification= v2gEVSENotificationType_None;
	exiOut->V2G_Message.Body.WeldingDetectionRes.DC_EVSEStatus.NotificationMaxDelay=123;
	exiOut->V2G_Message.Body.WeldingDetectionRes.EVSEPresentVoltage.Value = 1234;
	exiOut->V2G_Message.Body.WeldingDetectionRes.EVSEPresentVoltage.Unit = v2gunitSymbolType_V;
	exiOut->V2G_Message.Body.WeldingDetectionRes.EVSEPresentVoltage.Multiplier = 0;

	return 0;
}

int sessionStop(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut) {

	printf("EVSE side: sessionStop called\n"  );
	printf("\tReceived data:\n");
	printf("\tHeader SessionID=");
	printBinaryArray(exiIn->V2G_Message.Header.SessionID.bytes, exiIn->V2G_Message.Header.SessionID.bytesLen);
	printf("\t\t ChargingSession=%d\n", exiIn->V2G_Message.Body.SessionStopReq.ChargingSession);

	/* Prepare data for EV */
	exiOut->V2G_Message_isUsed = 1u;
	init_v2gBodyType(&exiOut->V2G_Message.Body);
	exiOut->V2G_Message.Body.SessionStopRes_isUsed = 1u;

	exiOut->V2G_Message.Body.SessionStopRes.ResponseCode = v2gresponseCodeType_OK;

	return 0;
}
