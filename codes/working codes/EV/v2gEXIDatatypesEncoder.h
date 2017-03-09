/*
 * v2gEXIDatatypesEncoder.h
 *
 *  Created on: 12.02.2016
 *      Author: melanie
 */

#ifndef ISO_COMM_CODEC_V2GEXIDATATYPESENCODER_H_
#define ISO_COMM_CODEC_V2GEXIDATATYPESENCODER_H_

#ifdef __cplusplus
extern "C" {
#endif

#if DEPLOY_ISO_CODEC == SUPPORT_YES

#include <stdint.h>
#include "EXITypes.h"
#include "ErrorCodes.h"
#include "v2gEXIDatatypes.h"

#include "EncoderChannel.h"
#include "EXIHeaderEncoder.h"


int encode_v2gExiDocument(bitstream_t* stream, struct v2gEXIDocument* exiDoc);
/********************general***************************/
int encode_v2gPhysicalValueType(bitstream_t* stream, struct v2gPhysicalValueType* v2gPhysicalValueType);
int encode_v2gBodyBaseType(bitstream_t* stream, struct v2gBodyBaseType* v2gBodyBaseType);
int encode_v2gCanonicalizationMethodType(bitstream_t* stream, struct v2gCanonicalizationMethodType* v2gCanonicalizationMethodType);
int encode_v2gListOfRootCertificateIDsType(bitstream_t* stream, struct v2gListOfRootCertificateIDsType* v2gListOfRootCertificateIDsType);
int encode_v2gX509IssuerSerialType(bitstream_t* stream, struct v2gX509IssuerSerialType* v2gX509IssuerSerialType);
int encode_v2gCertificateChainType(bitstream_t* stream, struct v2gCertificateChainType* v2gCertificateChainType);
int encode_v2gSubCertificatesType(bitstream_t* stream, struct v2gSubCertificatesType* v2gSubCertificatesType);
int encode_v2gContractSignatureEncryptedPrivateKeyType(bitstream_t* stream, struct v2gContractSignatureEncryptedPrivateKeyType* v2gContractSignatureEncryptedPrivateKeyType);
int encode_v2gDiffieHellmanPublickeyType(bitstream_t* stream, struct v2gDiffieHellmanPublickeyType* v2gDiffieHellmanPublickeyType);
int encode_v2gEMAIDType(bitstream_t* stream, struct v2gEMAIDType* v2gEMAIDType);
int encode_v2gSAScheduleListType(bitstream_t* stream, struct v2gSAScheduleListType* v2gSAScheduleListType);
int encode_v2gSAScheduleTupleType(bitstream_t* stream, struct v2gSAScheduleTupleType* v2gSAScheduleTupleType);
int encode_v2gPMaxScheduleType(bitstream_t* stream, struct v2gPMaxScheduleType* v2gPMaxScheduleType);
int encode_v2gPMaxScheduleEntryType(bitstream_t* stream, struct v2gPMaxScheduleEntryType* v2gPMaxScheduleEntryType);
int encode_v2gRelativeTimeIntervalType(bitstream_t* stream, struct v2gRelativeTimeIntervalType* v2gRelativeTimeIntervalType);
int encode_v2gIntervalType(bitstream_t* stream, struct v2gIntervalType* v2gIntervalType);
int encode_v2gSalesTariffType(bitstream_t* stream, struct v2gSalesTariffType* v2gSalesTariffType);
int encode_v2gSalesTariffEntryType(bitstream_t* stream, struct v2gSalesTariffEntryType* v2gSalesTariffEntryType);
int encode_v2gConsumptionCostType(bitstream_t* stream, struct v2gConsumptionCostType* v2gConsumptionCostType);
int encode_v2gCostType(bitstream_t* stream, struct v2gCostType* v2gCostType);
int encode_v2gSASchedulesType(bitstream_t* stream, struct v2gSASchedulesType* v2gSASchedulesType);
int encode_v2gMeterInfoType(bitstream_t* stream, struct v2gMeterInfoType* v2gMeterInfoType);
int encode_v2gDSAKeyValueType(bitstream_t* stream, struct v2gDSAKeyValueType* v2gDSAKeyValueType);
int encode_v2gDigestMethodType(bitstream_t* stream, struct v2gDigestMethodType* v2gDigestMethodType);
int encode_v2gEVPowerDeliveryParameterType(bitstream_t* stream, struct v2gEVPowerDeliveryParameterType* v2gEVPowerDeliveryParameterType);
int encode_v2gEntryType(bitstream_t* stream, struct v2gEntryType* v2gEntryType);
int encode_v2gKeyInfoType(bitstream_t* stream, struct v2gKeyInfoType* v2gKeyInfoType);
int encode_v2gKeyValueType(bitstream_t* stream, struct v2gKeyValueType* v2gKeyValueType);
int encode_v2gRSAKeyValueType(bitstream_t* stream, struct v2gRSAKeyValueType* v2gRSAKeyValueType);
int encode_v2gRetrievalMethodType(bitstream_t* stream, struct v2gRetrievalMethodType* v2gRetrievalMethodType);
int encode_v2gTransformsType(bitstream_t* stream, struct v2gTransformsType* v2gTransformsType);
int encode_v2gTransformType(bitstream_t* stream, struct v2gTransformType* v2gTransformType);
int encode_v2gX509DataType(bitstream_t* stream, struct v2gX509DataType* v2gX509DataType);
int encode_v2gSPKIDataType(bitstream_t* stream, struct v2gSPKIDataType* v2gSPKIDataType);
int encode_v2gPGPDataType(bitstream_t* stream, struct v2gPGPDataType* v2gPGPDataType);
int encode_v2gManifestType(bitstream_t* stream, struct v2gManifestType* v2gManifestType);
int encode_v2gReferenceType(bitstream_t* stream, struct v2gReferenceType* v2gReferenceType);
int encode_v2gObjectType(bitstream_t* stream, struct v2gObjectType* v2gObjectType);
int encode_v2gSelectedServiceListType(bitstream_t* stream, struct v2gSelectedServiceListType* v2gSelectedServiceListType);
int encode_v2gSelectedServiceType(bitstream_t* stream, struct v2gSelectedServiceType* v2gSelectedServiceType);
int encode_v2gChargingProfileType(bitstream_t* stream, struct v2gChargingProfileType* v2gChargingProfileType);
int encode_v2gProfileEntryType(bitstream_t* stream, struct v2gProfileEntryType* v2gProfileEntryType);
int encode_v2gServiceParameterListType(bitstream_t* stream, struct v2gServiceParameterListType* v2gServiceParameterListType);
int encode_v2gParameterSetType(bitstream_t* stream, struct v2gParameterSetType* v2gParameterSetType);
int encode_v2gParameterType(bitstream_t* stream, struct v2gParameterType* v2gParameterType);
int encode_v2gPaymentOptionListType(bitstream_t* stream, struct v2gPaymentOptionListType* v2gPaymentOptionListType);
int encode_v2gChargeServiceType(bitstream_t* stream, struct v2gChargeServiceType* v2gChargeServiceType);
int encode_v2gSupportedEnergyTransferModeType(bitstream_t* stream, struct v2gSupportedEnergyTransferModeType* v2gSupportedEnergyTransferModeType);
int encode_v2gServiceListType(bitstream_t* stream, struct v2gServiceListType* v2gServiceListType);
int encode_v2gServiceType(bitstream_t* stream, struct v2gServiceType* v2gServiceType);
int encode_v2gSignatureType(bitstream_t* stream, struct v2gSignatureType* v2gSignatureType);
int encode_v2gSignedInfoType(bitstream_t* stream, struct v2gSignedInfoType* v2gSignedInfoType);
int encode_v2gSignatureValueType(bitstream_t* stream, struct v2gSignatureValueType* v2gSignatureValueType);
int encode_v2gSignatureMethodType(bitstream_t* stream, struct v2gSignatureMethodType* v2gSignatureMethodType);
int encode_v2gSignaturePropertiesType(bitstream_t* stream, struct v2gSignaturePropertiesType* v2gSignaturePropertiesType);
int encode_v2gSignaturePropertyType(bitstream_t* stream, struct v2gSignaturePropertyType* v2gSignaturePropertyType);
int encode_v2gAnonType_V2G_Message(bitstream_t* stream, struct v2gAnonType_V2G_Message* v2gAnonType_V2G_Message);
int encode_v2gMessageHeaderType(bitstream_t* stream, struct v2gMessageHeaderType* v2gMessageHeaderType);
int encode_v2gNotificationType(bitstream_t* stream, struct v2gNotificationType* v2gNotificationType);
int encode_v2gBodyType(bitstream_t* stream, struct v2gBodyType* v2gBodyType);






/********************Request/EV***************************/
int encode_v2gAC_EVChargeParameterType(bitstream_t* stream, struct v2gAC_EVChargeParameterType* v2gAC_EVChargeParameterType);
int encode_v2gAuthorizationReqType(bitstream_t* stream, struct v2gAuthorizationReqType* v2gAuthorizationReqType);
int encode_v2gCableCheckReqType(bitstream_t* stream, struct v2gCableCheckReqType* v2gCableCheckReqType);
int encode_v2gDC_EVStatusType(bitstream_t* stream, struct v2gDC_EVStatusType* v2gDC_EVStatusType);
int encode_v2gCertificateInstallationReqType(bitstream_t* stream, struct v2gCertificateInstallationReqType* v2gCertificateInstallationReqType);
int encode_v2gCertificateUpdateReqType(bitstream_t* stream, struct v2gCertificateUpdateReqType* v2gCertificateUpdateReqType);
int encode_v2gDC_EVChargeParameterType(bitstream_t* stream, struct v2gDC_EVChargeParameterType* v2gDC_EVChargeParameterType);
int encode_v2gEVChargeParameterType(bitstream_t* stream, struct v2gEVChargeParameterType* v2gEVChargeParameterType);
int encode_v2gChargingStatusReqType(bitstream_t* stream, struct v2gChargingStatusReqType* v2gChargingStatusReqType);
int encode_v2gChargeParameterDiscoveryReqType(bitstream_t* stream, struct v2gChargeParameterDiscoveryReqType* v2gChargeParameterDiscoveryReqType);
int encode_v2gCurrentDemandReqType(bitstream_t* stream, struct v2gCurrentDemandReqType* v2gCurrentDemandReqType);
int encode_v2gDC_EVPowerDeliveryParameterType(bitstream_t* stream, struct v2gDC_EVPowerDeliveryParameterType* v2gDC_EVPowerDeliveryParameterType);
int encode_v2gEVStatusType(bitstream_t* stream, struct v2gEVStatusType* v2gEVStatusType);
int encode_v2gMeteringReceiptReqType(bitstream_t* stream, struct v2gMeteringReceiptReqType* v2gMeteringReceiptReqType);
int encode_v2gPaymentDetailsReqType(bitstream_t* stream, struct v2gPaymentDetailsReqType* v2gPaymentDetailsReqType);
int encode_v2gPaymentServiceSelectionReqType(bitstream_t* stream, struct v2gPaymentServiceSelectionReqType* v2gPaymentServiceSelectionReqType);
int encode_v2gPowerDeliveryReqType(bitstream_t* stream, struct v2gPowerDeliveryReqType* v2gPowerDeliveryReqType);
int encode_v2gPreChargeReqType(bitstream_t* stream, struct v2gPreChargeReqType* v2gPreChargeReqType);
int encode_v2gServiceDetailReqType(bitstream_t* stream, struct v2gServiceDetailReqType* v2gServiceDetailReqType);
int encode_v2gServiceDiscoveryReqType(bitstream_t* stream, struct v2gServiceDiscoveryReqType* v2gServiceDiscoveryReqType);
int encode_v2gSessionSetupReqType(bitstream_t* stream, struct v2gSessionSetupReqType* v2gSessionSetupReqType);
int encode_v2gSessionStopReqType(bitstream_t* stream, struct v2gSessionStopReqType* v2gSessionStopReqType);
int encode_v2gWeldingDetectionReqType(bitstream_t* stream, struct v2gWeldingDetectionReqType* v2gWeldingDetectionReqType);



#if DEPLOY_ISO_CODEC_FRAGMENT == SUPPORT_YES
int encode_v2gExiFragment(bitstream_t* stream, struct v2gEXIFragment* exiFrag);
#endif /* DEPLOY_ISO_CODEC_FRAGMENT */


#endif /* DEPLOY_ISO_CODEC */

#ifdef __cplusplus
}
#endif



#endif /* ISO_COMM_CODEC_V2GEXIDATATYPESENCODER_H_ */
