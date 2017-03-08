/*
 * v2gEXIDatatypesDecoder.h
 *
 *  Created on: 10.02.2016
 *      Author: melanie
 */

#ifndef ISO_COMM_CODEC_V2GEXIDATATYPESDECODER_H_
#define ISO_COMM_CODEC_V2GEXIDATATYPESDECODER_H_


# include <stdint.h>
# include "EXITypes.h"
# include "v2gEXIDatatypes.h"
#include "DecoderChannel.h"

int decode_v2gExiDocument(bitstream_t* stream, struct v2gEXIDocument* exiDoc);

/********************general***************************/
int decode_v2gPhysicalValueType(bitstream_t* stream, struct v2gPhysicalValueType* v2gPhysicalValueType, uint32_t eventCode);
int decode_v2gBodyBaseType(bitstream_t* stream, struct v2gBodyBaseType* v2gBodyBaseType, uint32_t eventCode);
int decode_v2gCanonicalizationMethodType(bitstream_t* stream, struct v2gCanonicalizationMethodType* v2gCanonicalizationMethodType, uint32_t eventCode);
int decode_v2gListOfRootCertificateIDsType(bitstream_t* stream, struct v2gListOfRootCertificateIDsType* v2gListOfRootCertificateIDsType, uint32_t eventCode);
int decode_v2gX509IssuerSerialType(bitstream_t* stream, struct v2gX509IssuerSerialType* v2gX509IssuerSerialType, uint32_t eventCode);
int decode_v2gCertificateChainType(bitstream_t* stream, struct v2gCertificateChainType* v2gCertificateChainType, uint32_t eventCode);
int decode_v2gSubCertificatesType(bitstream_t* stream, struct v2gSubCertificatesType* v2gSubCertificatesType, uint32_t eventCode);
int decode_v2gContractSignatureEncryptedPrivateKeyType(bitstream_t* stream, struct v2gContractSignatureEncryptedPrivateKeyType* v2gContractSignatureEncryptedPrivateKeyType, uint32_t eventCode);
int decode_v2gDiffieHellmanPublickeyType(bitstream_t* stream, struct v2gDiffieHellmanPublickeyType* v2gDiffieHellmanPublickeyType, uint32_t eventCode);
int decode_v2gEMAIDType(bitstream_t* stream, struct v2gEMAIDType* v2gEMAIDType, uint32_t eventCode);
int decode_v2gEVPowerDeliveryParameterType(bitstream_t* stream, struct v2gEVPowerDeliveryParameterType* v2gEVPowerDeliveryParameterType, uint32_t eventCode);
int decode_v2gSAScheduleTupleType(bitstream_t* stream, struct v2gSAScheduleTupleType* v2gSAScheduleTupleType, uint32_t eventCode);
int decode_v2gPMaxScheduleType(bitstream_t* stream, struct v2gPMaxScheduleType* v2gPMaxScheduleType, uint32_t eventCode);
int decode_v2gPMaxScheduleEntryType(bitstream_t* stream, struct v2gPMaxScheduleEntryType* v2gPMaxScheduleEntryType, uint32_t eventCode);
int decode_v2gRelativeTimeIntervalType(bitstream_t* stream, struct v2gRelativeTimeIntervalType* v2gRelativeTimeIntervalType, uint32_t eventCode);
int decode_v2gIntervalType(bitstream_t* stream, struct v2gIntervalType* v2gIntervalType, uint32_t eventCode);
int decode_v2gSalesTariffType(bitstream_t* stream, struct v2gSalesTariffType* v2gSalesTariffType, uint32_t eventCode);
int decode_v2gSalesTariffEntryType(bitstream_t* stream, struct v2gSalesTariffEntryType* v2gSalesTariffEntryType, uint32_t eventCode);
int decode_v2gConsumptionCostType(bitstream_t* stream, struct v2gConsumptionCostType* v2gConsumptionCostType, uint32_t eventCode);
int decode_v2gCostType(bitstream_t* stream, struct v2gCostType* v2gCostType, uint32_t eventCode);
int decode_v2gSASchedulesType(bitstream_t* stream, struct v2gSASchedulesType* v2gSASchedulesType, uint32_t eventCode);
int decode_v2gMeterInfoType(bitstream_t* stream, struct v2gMeterInfoType* v2gMeterInfoType, uint32_t eventCode);
int decode_v2gDSAKeyValueType(bitstream_t* stream, struct v2gDSAKeyValueType* v2gDSAKeyValueType, uint32_t eventCode);
int decode_v2gDigestMethodType(bitstream_t* stream, struct v2gDigestMethodType* v2gDigestMethodType, uint32_t eventCode);
int decode_v2gEntryType(bitstream_t* stream, struct v2gEntryType* v2gEntryType, uint32_t eventCode);
int decode_v2gKeyInfoType(bitstream_t* stream, struct v2gKeyInfoType* v2gKeyInfoType, uint32_t eventCode);
int decode_v2gKeyValueType(bitstream_t* stream, struct v2gKeyValueType* v2gKeyValueType, uint32_t eventCode);
int decode_v2gRSAKeyValueType(bitstream_t* stream, struct v2gRSAKeyValueType* v2gRSAKeyValueType, uint32_t eventCode);
int decode_v2gRetrievalMethodType(bitstream_t* stream, struct v2gRetrievalMethodType* v2gRetrievalMethodType, uint32_t);
int decode_v2gTransformsType(bitstream_t* stream, struct v2gTransformsType* v2gTransformsType, uint32_t eventCode);
int decode_v2gTransformType(bitstream_t* stream, struct v2gTransformType* v2gTransformType, uint32_t eventCode);
int decode_v2gX509DataType(bitstream_t* stream, struct v2gX509DataType* v2gX509DataType, uint32_t eventCode);
int decode_v2gPGPDataType(bitstream_t* stream, struct v2gPGPDataType* v2gPGPDataType, uint32_t eventCode);
int decode_v2gSPKIDataType(bitstream_t* stream, struct v2gSPKIDataType* v2gSPKIDataType, uint32_t eventCode);
int decode_v2gServiceParameterListType(bitstream_t* stream, struct v2gServiceParameterListType* v2gServiceParameterListType, uint32_t eventCode);
int decode_v2gParameterSetType(bitstream_t* stream, struct v2gParameterSetType* v2gParameterSetType, uint32_t eventCode);
int decode_v2gParameterType(bitstream_t* stream, struct v2gParameterType* v2gParameterType, uint32_t eventCode);
int decode_v2gManifestType(bitstream_t* stream, struct v2gManifestType* v2gManifestType, uint32_t eventCode);
int decode_v2gReferenceType(bitstream_t* stream, struct v2gReferenceType* v2gReferenceType, uint32_t eventCode);
int decode_v2gObjectType(bitstream_t* stream, struct v2gObjectType* v2gObjectType, uint32_t eventCode);
int decode_v2gSelectedServiceListType(bitstream_t* stream, struct v2gSelectedServiceListType* v2gSelectedServiceListType, uint32_t eventCode);
int decode_v2gSelectedServiceType(bitstream_t* stream, struct v2gSelectedServiceType* v2gSelectedServiceType, uint32_t eventCode);
int decode_v2gChargingProfileType(bitstream_t* stream, struct v2gChargingProfileType* v2gChargingProfileType, uint32_t eventCode);
int decode_v2gProfileEntryType(bitstream_t* stream, struct v2gProfileEntryType* v2gProfileEntryType, uint32_t eventCode);
int decode_v2gPaymentOptionListType(bitstream_t* stream, struct v2gPaymentOptionListType* v2gPaymentOptionListType, uint32_t eventCode);
int decode_v2gChargeServiceType(bitstream_t* stream, struct v2gChargeServiceType* v2gChargeServiceType, uint32_t eventCode);
int decode_v2gSupportedEnergyTransferModeType(bitstream_t* stream, struct v2gSupportedEnergyTransferModeType* v2gSupportedEnergyTransferModeType, uint32_t eventCode);
int decode_v2gServiceListType(bitstream_t* stream, struct v2gServiceListType* v2gServiceListType, uint32_t eventCode);
int decode_v2gServiceType(bitstream_t* stream, struct v2gServiceType* v2gServiceType, uint32_t eventCode);
int decode_v2gSessionSetupReqType(bitstream_t* stream, struct v2gSessionSetupReqType* v2gSessionSetupReqType, uint32_t eventCode);
int decode_v2gSessionSetupResType(bitstream_t* stream, struct v2gSessionSetupResType* v2gSessionSetupResType, uint32_t eventCode);
int decode_v2gSignatureType(bitstream_t* stream, struct v2gSignatureType* v2gSignatureType, uint32_t eventCode);
int decode_v2gSignedInfoType(bitstream_t* stream, struct v2gSignedInfoType* v2gSignedInfoType, uint32_t eventCode);
int decode_v2gSignatureMethodType(bitstream_t* stream, struct v2gSignatureMethodType* v2gSignatureMethodType, uint32_t eventCode);
int decode_v2gSignatureValueType(bitstream_t* stream, struct v2gSignatureValueType* v2gSignatureValueType, uint32_t eventCode);
int decode_v2gSignaturePropertiesType(bitstream_t* stream, struct v2gSignaturePropertiesType* v2gSignaturePropertiesType, uint32_t eventCode);
int decode_v2gSignaturePropertyType(bitstream_t* stream, struct v2gSignaturePropertyType* v2gSignaturePropertyType, uint32_t eventCode);
int decodeDeviationsCH(bitstream_t* stream);
int decode_v2gAnonType_V2G_Message(bitstream_t* stream, struct v2gAnonType_V2G_Message* v2gAnonType_V2G_Message, uint32_t eventCode);
int decode_v2gMessageHeaderType(bitstream_t* stream, struct v2gMessageHeaderType* v2gMessageHeaderType, uint32_t eventCode);
int decode_v2gNotificationType(bitstream_t* stream, struct v2gNotificationType* v2gNotificationType, uint32_t eventCode);
int decode_v2gBodyType(bitstream_t* stream, struct v2gBodyType* v2gBodyType, uint32_t eventCode) ;




/********************Request/EV***************************/
int decode_v2gAC_EVChargeParameterType(bitstream_t* stream, struct v2gAC_EVChargeParameterType* v2gAC_EVChargeParameterType, uint32_t eventCode);
int decode_v2gAuthorizationReqType(bitstream_t* stream, struct v2gAuthorizationReqType* v2gAuthorizationReqType, uint32_t eventCode);
int decode_v2gCableCheckReqType(bitstream_t* stream, struct v2gCableCheckReqType* v2gCableCheckReqType, uint32_t eventCode);
int decode_v2gDC_EVStatusType(bitstream_t* stream, struct v2gDC_EVStatusType* v2gDC_EVStatusType,uint32_t eventCode);
int decode_v2gCertificateInstallationReqType(bitstream_t* stream, struct v2gCertificateInstallationReqType* v2gCertificateInstallationReqType, uint32_t eventCode);
int decode_v2gCertificateUpdateReqType(bitstream_t* stream, struct v2gCertificateUpdateReqType* v2gCertificateUpdateReqType, uint32_t eventCode);
int decode_v2gChargeParameterDiscoveryReqType(bitstream_t* stream, struct v2gChargeParameterDiscoveryReqType* v2gChargeParameterDiscoveryReqType, uint32_t eventCode);
int decode_v2gChargingStatusReqType(bitstream_t* stream, struct v2gChargingStatusReqType* v2gChargingStatusReqType, uint32_t eventCode);
int decode_v2gDC_EVChargeParameterType(bitstream_t* stream, struct v2gDC_EVChargeParameterType* v2gDC_EVChargeParameterType, uint32_t eventCode);
int decode_v2gEVChargeParameterType(bitstream_t* stream, struct v2gEVChargeParameterType* v2gEVChargeParameterType, uint32_t eventCode);
int decode_v2gEVStatusType(bitstream_t* stream, struct v2gEVStatusType* v2gEVStatusType, uint32_t eventCode);
int decode_v2gCurrentDemandReqType(bitstream_t* stream, struct v2gCurrentDemandReqType* v2gCurrentDemandReqType, uint32_t eventCode);
int decode_v2gDC_EVPowerDeliveryParameterType(bitstream_t* stream, struct v2gDC_EVPowerDeliveryParameterType* v2gDC_EVPowerDeliveryParameterType, uint32_t eventCode);
int decode_v2gServiceDetailReqType(bitstream_t* stream, struct v2gServiceDetailReqType* v2gServiceDetailReqType, uint32_t eventCode);
int decode_v2gMeteringReceiptReqType(bitstream_t* stream, struct v2gMeteringReceiptReqType* v2gMeteringReceiptReqType, uint32_t eventCode);
int decode_v2gPaymentDetailsReqType(bitstream_t* stream, struct v2gPaymentDetailsReqType* v2gPaymentDetailsReqType, uint32_t eventCode);
int decode_v2gPaymentServiceSelectionReqType(bitstream_t* stream, struct v2gPaymentServiceSelectionReqType* v2gPaymentServiceSelectionReqType, uint32_t eventCode);
int decode_v2gPowerDeliveryReqType(bitstream_t* stream, struct v2gPowerDeliveryReqType* v2gPowerDeliveryReqType, uint32_t eventCode);
int decode_v2gPreChargeReqType(bitstream_t* stream, struct v2gPreChargeReqType* v2gPreChargeReqType, uint32_t eventCode);
int decode_v2gServiceDiscoveryReqType(bitstream_t* stream, struct v2gServiceDiscoveryReqType* v2gServiceDiscoveryReqType, uint32_t eventCode);
int decode_v2gSessionStopReqType(bitstream_t* stream, struct v2gSessionStopReqType* v2gSessionStopReqType, uint32_t eventCode);
int decode_v2gWeldingDetectionReqType(bitstream_t* stream, struct v2gWeldingDetectionReqType* v2gWeldingDetectionReqType, uint32_t eventCode);



#endif /* ISO_COMM_CODEC_V2GEXIDATATYPESDECODER_H_ */
