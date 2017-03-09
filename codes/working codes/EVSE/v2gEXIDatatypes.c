/*
 * v2gEXIDatatypes.c
 *
 *  Created on: 06.01.2016
 *      Author: melanie
 */

#include <stdint.h>

#include "v2gEXIDatatypes.h"
#include "EXITypes.h"


#ifndef ISO_COMM_CODEC_V2GEXIDATATYPES_C_
#define ISO_COMM_CODEC_V2GEXIDATATYPES_C_

#if DEPLOY_ISO_CODEC == SUPPORT_YES


void init_v2gEXIDocument(struct v2gEXIDocument* exiDoc) {
	exiDoc->V2G_Message_isUsed = 0u;
	exiDoc->ServiceDiscoveryReq_isUsed = 0u;
	exiDoc->ServiceDiscoveryRes_isUsed = 0u;
	exiDoc->MeteringReceiptReq_isUsed = 0u;
	exiDoc->PaymentDetailsReq_isUsed = 0u;
	exiDoc->MeteringReceiptRes_isUsed = 0u;
	exiDoc->PaymentDetailsRes_isUsed = 0u;
	exiDoc->SessionSetupReq_isUsed = 0u;
	exiDoc->SessionSetupRes_isUsed = 0u;
	exiDoc->CableCheckReq_isUsed = 0u;
	exiDoc->CableCheckRes_isUsed = 0u;
	exiDoc->CertificateInstallationReq_isUsed = 0u;
	exiDoc->CertificateInstallationRes_isUsed = 0u;
	exiDoc->WeldingDetectionReq_isUsed = 0u;
	exiDoc->WeldingDetectionRes_isUsed = 0u;
	exiDoc->CertificateUpdateReq_isUsed = 0u;
	exiDoc->CertificateUpdateRes_isUsed = 0u;
	exiDoc->PaymentServiceSelectionReq_isUsed = 0u;
	exiDoc->PowerDeliveryReq_isUsed = 0u;
	exiDoc->PaymentServiceSelectionRes_isUsed = 0u;
	exiDoc->PowerDeliveryRes_isUsed = 0u;
	exiDoc->ChargingStatusReq_isUsed = 0u;
	exiDoc->ChargingStatusRes_isUsed = 0u;
	exiDoc->BodyElement_isUsed = 0u;
	exiDoc->CurrentDemandReq_isUsed = 0u;
	exiDoc->PreChargeReq_isUsed = 0u;
	exiDoc->CurrentDemandRes_isUsed = 0u;
	exiDoc->PreChargeRes_isUsed = 0u;
	exiDoc->SessionStopReq_isUsed = 0u;
	exiDoc->AuthorizationReq_isUsed = 0u;
	exiDoc->SessionStopRes_isUsed = 0u;
	exiDoc->AuthorizationRes_isUsed = 0u;
	exiDoc->ChargeParameterDiscoveryReq_isUsed = 0u;
	exiDoc->ChargeParameterDiscoveryRes_isUsed = 0u;
	exiDoc->ServiceDetailReq_isUsed = 0u;
	exiDoc->ServiceDetailRes_isUsed = 0u;
	exiDoc->DC_EVSEStatus_isUsed = 0u;
	exiDoc->RelativeTimeInterval_isUsed = 0u;
	exiDoc->SalesTariffEntry_isUsed = 0u;
	exiDoc->DC_EVPowerDeliveryParameter_isUsed = 0u;
	exiDoc->SASchedules_isUsed = 0u;
	exiDoc->AC_EVChargeParameter_isUsed = 0u;
	exiDoc->SAScheduleList_isUsed = 0u;
	exiDoc->DC_EVStatus_isUsed = 0u;
	exiDoc->EVStatus_isUsed = 0u;
	exiDoc->DC_EVChargeParameter_isUsed = 0u;
	exiDoc->DC_EVSEChargeParameter_isUsed = 0u;
	exiDoc->EVSEStatus_isUsed = 0u;
	exiDoc->TimeInterval_isUsed = 0u;
	exiDoc->EVPowerDeliveryParameter_isUsed = 0u;
	exiDoc->EVSEChargeParameter_isUsed = 0u;
	exiDoc->AC_EVSEStatus_isUsed = 0u;
	exiDoc->Entry_isUsed = 0u;
	exiDoc->AC_EVSEChargeParameter_isUsed = 0u;
	exiDoc->PMaxScheduleEntry_isUsed = 0u;
	exiDoc->EVChargeParameter_isUsed = 0u;
	exiDoc->SignatureProperty_isUsed = 0u;
	exiDoc->DSAKeyValue_isUsed = 0u;
	exiDoc->SignatureProperties_isUsed = 0u;
	exiDoc->KeyValue_isUsed = 0u;
	exiDoc->Transforms_isUsed = 0u;
	exiDoc->DigestMethod_isUsed = 0u;
	exiDoc->Signature_isUsed = 0u;
	exiDoc->RetrievalMethod_isUsed = 0u;
	exiDoc->Manifest_isUsed = 0u;
	exiDoc->Reference_isUsed = 0u;
	exiDoc->CanonicalizationMethod_isUsed = 0u;
	exiDoc->RSAKeyValue_isUsed = 0u;
	exiDoc->Transform_isUsed = 0u;
	exiDoc->PGPData_isUsed = 0u;
	exiDoc->MgmtData_isUsed = 0u;
	exiDoc->SignatureMethod_isUsed = 0u;
	exiDoc->KeyInfo_isUsed = 0u;
	exiDoc->SPKIData_isUsed = 0u;
	exiDoc->X509Data_isUsed = 0u;
	exiDoc->SignatureValue_isUsed = 0u;
	exiDoc->KeyName_isUsed = 0u;
	exiDoc->DigestValue_isUsed = 0u;
	exiDoc->SignedInfo_isUsed = 0u;
	exiDoc->Object_isUsed = 0u;
}


void init_v2gBodyType(struct v2gBodyType* v2gBodyType) {
	v2gBodyType->BodyElement_isUsed = 0u;
	v2gBodyType->SessionSetupReq_isUsed = 0u;
	v2gBodyType->SessionSetupRes_isUsed = 0u;
	v2gBodyType->ServiceDiscoveryReq_isUsed = 0u;
	v2gBodyType->ServiceDiscoveryRes_isUsed = 0u;
	v2gBodyType->ServiceDetailReq_isUsed = 0u;
	v2gBodyType->ServiceDetailRes_isUsed = 0u;
	v2gBodyType->PaymentServiceSelectionReq_isUsed = 0u;
	v2gBodyType->PaymentServiceSelectionRes_isUsed = 0u;
	v2gBodyType->PaymentDetailsReq_isUsed = 0u;
	v2gBodyType->PaymentDetailsRes_isUsed = 0u;
	v2gBodyType->AuthorizationReq_isUsed = 0u;
	v2gBodyType->AuthorizationRes_isUsed = 0u;
	v2gBodyType->ChargeParameterDiscoveryReq_isUsed = 0u;
	v2gBodyType->ChargeParameterDiscoveryRes_isUsed = 0u;
	v2gBodyType->PowerDeliveryReq_isUsed = 0u;
	v2gBodyType->PowerDeliveryRes_isUsed = 0u;
	v2gBodyType->MeteringReceiptReq_isUsed = 0u;
	v2gBodyType->MeteringReceiptRes_isUsed = 0u;
	v2gBodyType->SessionStopReq_isUsed = 0u;
	v2gBodyType->SessionStopRes_isUsed = 0u;
	v2gBodyType->CertificateUpdateReq_isUsed = 0u;
	v2gBodyType->CertificateUpdateRes_isUsed = 0u;
	v2gBodyType->CertificateInstallationReq_isUsed = 0u;
	v2gBodyType->CertificateInstallationRes_isUsed = 0u;
	v2gBodyType->ChargingStatusReq_isUsed = 0u;
	v2gBodyType->ChargingStatusRes_isUsed = 0u;
	v2gBodyType->CableCheckReq_isUsed = 0u;
	v2gBodyType->CableCheckRes_isUsed = 0u;
	v2gBodyType->PreChargeReq_isUsed = 0u;
	v2gBodyType->PreChargeRes_isUsed = 0u;
	v2gBodyType->CurrentDemandReq_isUsed = 0u;
	v2gBodyType->CurrentDemandRes_isUsed = 0u;
	v2gBodyType->WeldingDetectionReq_isUsed = 0u;
	v2gBodyType->WeldingDetectionRes_isUsed = 0u;
}

void init_v2gChargeParameterDiscoveryReqType(struct v2gChargeParameterDiscoveryReqType* v2gChargeParameterDiscoveryReqType) {
	v2gChargeParameterDiscoveryReqType->MaxEntriesSAScheduleTuple_isUsed = 0u;
	v2gChargeParameterDiscoveryReqType->EVChargeParameter_isUsed = 0u;
	v2gChargeParameterDiscoveryReqType->AC_EVChargeParameter_isUsed = 0u;
	v2gChargeParameterDiscoveryReqType->DC_EVChargeParameter_isUsed = 0u;
}

void init_v2gChargeParameterDiscoveryResType(struct v2gChargeParameterDiscoveryResType* v2gChargeParameterDiscoveryResType) {
	v2gChargeParameterDiscoveryResType->SASchedules_isUsed = 0u;
	v2gChargeParameterDiscoveryResType->SAScheduleList_isUsed = 0u;
	v2gChargeParameterDiscoveryResType->EVSEChargeParameter_isUsed = 0u;
	v2gChargeParameterDiscoveryResType->AC_EVSEChargeParameter_isUsed = 0u;
	v2gChargeParameterDiscoveryResType->DC_EVSEChargeParameter_isUsed = 0u;
}

void init_v2gDC_EVChargeParameterType(struct v2gDC_EVChargeParameterType* v2gDC_EVChargeParameterType) {
	v2gDC_EVChargeParameterType->DepartureTime_isUsed = 0u;
	v2gDC_EVChargeParameterType->EVMaximumPowerLimit_isUsed = 0u;
	v2gDC_EVChargeParameterType->EVEnergyCapacity_isUsed = 0u;
	v2gDC_EVChargeParameterType->EVEnergyRequest_isUsed = 0u;
	v2gDC_EVChargeParameterType->FullSOC_isUsed = 0u;
	v2gDC_EVChargeParameterType->BulkSOC_isUsed = 0u;
}

void init_v2gCurrentDemandReqType(struct v2gCurrentDemandReqType* v2gCurrentDemandReqType) {
	v2gCurrentDemandReqType->EVMaximumVoltageLimit_isUsed = 0u;
	v2gCurrentDemandReqType->EVMaximumCurrentLimit_isUsed = 0u;
	v2gCurrentDemandReqType->EVMaximumPowerLimit_isUsed = 0u;
	v2gCurrentDemandReqType->BulkChargingComplete_isUsed = 0u;
	v2gCurrentDemandReqType->RemainingTimeToFullSoC_isUsed = 0u;
	v2gCurrentDemandReqType->RemainingTimeToBulkSoC_isUsed = 0u;
}

void init_v2gDSAKeyValueType(struct v2gDSAKeyValueType* v2gDSAKeyValueType) {
	v2gDSAKeyValueType->P_isUsed = 0u;
	v2gDSAKeyValueType->Q_isUsed = 0u;
	v2gDSAKeyValueType->G_isUsed = 0u;
	v2gDSAKeyValueType->J_isUsed = 0u;
	v2gDSAKeyValueType->Seed_isUsed = 0u;
	v2gDSAKeyValueType->PgenCounter_isUsed = 0u;
}

void init_v2gSalesTariffType(struct v2gSalesTariffType* v2gSalesTariffType) {
	v2gSalesTariffType->Id_isUsed = 0u;
	v2gSalesTariffType->SalesTariffDescription_isUsed = 0u;
	v2gSalesTariffType->NumEPriceLevels_isUsed = 0u;
	v2gSalesTariffType->SalesTariffEntry.arrayLen = 0u;
}

void init_v2gSalesTariffEntryType(struct v2gSalesTariffEntryType* v2gSalesTariffEntryType) {
	v2gSalesTariffEntryType->TimeInterval_isUsed = 0u;
	v2gSalesTariffEntryType->RelativeTimeInterval_isUsed = 0u;
	v2gSalesTariffEntryType->EPriceLevel_isUsed = 0u;
	v2gSalesTariffEntryType->ConsumptionCost.arrayLen = 0u;
}

void init_v2gChargingStatusResType(struct v2gChargingStatusResType* v2gChargingStatusResType) {
	v2gChargingStatusResType->EVSEMaxCurrent_isUsed = 0u;
	v2gChargingStatusResType->MeterInfo_isUsed = 0u;
	v2gChargingStatusResType->ReceiptRequired_isUsed = 0u;
}

void init_v2gMeterInfoType(struct v2gMeterInfoType* v2gMeterInfoType) {
	v2gMeterInfoType->MeterReading_isUsed = 0u;
	v2gMeterInfoType->SigMeterReading_isUsed = 0u;
	v2gMeterInfoType->MeterStatus_isUsed = 0u;
	v2gMeterInfoType->TMeter_isUsed = 0u;
}

void init_v2gCurrentDemandResType(struct v2gCurrentDemandResType* v2gCurrentDemandResType) {
	v2gCurrentDemandResType->EVSEMaximumVoltageLimit_isUsed = 0u;
	v2gCurrentDemandResType->EVSEMaximumCurrentLimit_isUsed = 0u;
	v2gCurrentDemandResType->EVSEMaximumPowerLimit_isUsed = 0u;
	v2gCurrentDemandResType->MeterInfo_isUsed = 0u;
	v2gCurrentDemandResType->ReceiptRequired_isUsed = 0u;
}

void init_v2gKeyInfoType(struct v2gKeyInfoType* v2gKeyInfoType) {
	v2gKeyInfoType->Id_isUsed = 0u;
	v2gKeyInfoType->KeyName.arrayLen = 0u;
	v2gKeyInfoType->KeyValue.arrayLen = 0u;
	v2gKeyInfoType->RetrievalMethod.arrayLen = 0u;
	v2gKeyInfoType->X509Data.arrayLen = 0u;
	v2gKeyInfoType->PGPData.arrayLen = 0u;
	v2gKeyInfoType->SPKIData.arrayLen = 0u;
	v2gKeyInfoType->MgmtData.arrayLen = 0u;
}

void init_v2gX509DataType(struct v2gX509DataType* v2gX509DataType) {
	v2gX509DataType->X509IssuerSerial.arrayLen = 0u;
	v2gX509DataType->X509SKI.arrayLen = 0u;
	v2gX509DataType->X509SubjectName.arrayLen = 0u;
	v2gX509DataType->X509Certificate.arrayLen = 0u;
	v2gX509DataType->X509CRL.arrayLen = 0u;
}

void init_v2gParameterType(struct v2gParameterType* v2gParameterType) {
	v2gParameterType->boolValue_isUsed = 0u;
	v2gParameterType->byteValue_isUsed = 0u;
	v2gParameterType->shortValue_isUsed = 0u;
	v2gParameterType->intValue_isUsed = 0u;
	v2gParameterType->physicalValue_isUsed = 0u;
	v2gParameterType->stringValue_isUsed = 0u;
}

void init_v2gReferenceType(struct v2gReferenceType* v2gReferenceType) {
	v2gReferenceType->Id_isUsed = 0u;
	v2gReferenceType->URI_isUsed = 0u;
	v2gReferenceType->Type_isUsed = 0u;
	v2gReferenceType->Transforms_isUsed = 0u;
}

#endif /* DEPLOY_ISO_CODEC */

#endif

