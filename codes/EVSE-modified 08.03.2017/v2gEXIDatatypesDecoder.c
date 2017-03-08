/*
 * v2gEXIDatatypesDecoder.c
 *
 *  Created on: 06.01.2016
 *      Author: melanie
 */

# include <stdio.h>
# include "DecoderChannel.h"
# include "v2gEXIDatatypes.h"
# include "EXIHeaderDecoder.h"
# include "ErrorCodes.h"
# include "v2gEXIDatatypesDecoder.h"



# ifndef ISO_COMM_CODEC_V2GEXIDATATYPESDECODER_C_
# define ISO_COMM_CODEC_V2GEXIDATATYPESDECODER_C_

#if DEPLOY_ISO_CODEC == SUPPORT_YES

int decode_v2gExiDocument(bitstream_t* stream, struct v2gEXIDocument* exiDoc) {	//EV+EVSE seite nur case 76?
	int errn;
	uint32_t eventCode;

	errn = readEXIHeader(stream);

	if(errn == 0) {
		/* DocContent[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}AC_EVChargeParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}AC_EVSEChargeParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}AC_EVSEStatus), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}AuthorizationReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}AuthorizationRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}BodyElement), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CableCheckReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CableCheckRes), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}CanonicalizationMethod), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CertificateInstallationReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CertificateInstallationRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CertificateUpdateReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CertificateUpdateRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargeParameterDiscoveryReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargeParameterDiscoveryRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingStatusReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingStatusRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CurrentDemandReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CurrentDemandRes), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVChargeParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVPowerDeliveryParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVSEChargeParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVSEStatus), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVStatus), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DSAKeyValue), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DigestMethod), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DigestValue), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVChargeParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVPowerDeliveryParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEChargeParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEStatus), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVStatus), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Entry), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyInfo), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyName), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyValue), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Manifest), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}MeteringReceiptReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}MeteringReceiptRes), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}MgmtData), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Object), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PGPData), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}PMaxScheduleEntry), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PaymentDetailsReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PaymentDetailsRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PaymentServiceSelectionReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PaymentServiceSelectionRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PowerDeliveryReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PowerDeliveryRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PreChargeReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PreChargeRes), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}RSAKeyValue), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Reference), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}RelativeTimeInterval), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}RetrievalMethod), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SAScheduleList), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SASchedules), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SPKIData), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SalesTariffEntry), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceDetailReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceDetailRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceDiscoveryReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceDiscoveryRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionSetupReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionSetupRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionStopReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionStopRes), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Signature), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignatureMethod), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignatureProperties), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignatureProperty), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignatureValue), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignedInfo), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}TimeInterval), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transform), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transforms), START_ELEMENT({urn:iso:15118:2:2013:MsgDef}V2G_Message), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}WeldingDetectionReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}WeldingDetectionRes), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509Data), START_ELEMENT_GENERIC] */
		init_v2gEXIDocument(exiDoc);
		errn = decodeNBitUnsignedInteger(stream, 7, &eventCode);
		if(errn == 0) {
			switch(eventCode) {
			case 0:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}AC_EVChargeParameter) */
				errn = decode_v2gAC_EVChargeParameterType(stream, &exiDoc->AC_EVChargeParameter, eventCode);
				exiDoc->AC_EVChargeParameter_isUsed = 1u;
				break;
			case 1:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}AC_EVSEChargeParameter) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->AC_EVSEChargeParameter_isUsed = 1u;
				break;
			case 2:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}AC_EVSEStatus) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->AC_EVSEStatus_isUsed = 1u;
				break;
			case 3:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}AuthorizationReq) */
				errn = decode_v2gAuthorizationReqType(stream, &exiDoc->AuthorizationReq, eventCode);
				exiDoc->AuthorizationReq_isUsed = 1u;
				break;
			case 4:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}AuthorizationRes) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->AuthorizationRes_isUsed = 1u;
				break;
			case 5:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}BodyElement) */
				errn = decode_v2gBodyBaseType(stream, &exiDoc->BodyElement, eventCode);
				exiDoc->BodyElement_isUsed = 1u;
				break;
			case 6:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CableCheckReq) */
				errn = decode_v2gCableCheckReqType(stream, &exiDoc->CableCheckReq, eventCode);
				exiDoc->CableCheckReq_isUsed = 1u;
				break;
			case 7:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CableCheckRes) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->CableCheckRes_isUsed = 1u;
				break;
			case 8:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}CanonicalizationMethod) */
				errn = decode_v2gCanonicalizationMethodType(stream, &exiDoc->CanonicalizationMethod, eventCode);
				exiDoc->CanonicalizationMethod_isUsed = 1u;
				break;
			case 9:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CertificateInstallationReq) */
				errn = decode_v2gCertificateInstallationReqType(stream, &exiDoc->CertificateInstallationReq, eventCode);
				exiDoc->CertificateInstallationReq_isUsed = 1u;
				break;
			case 10:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CertificateInstallationRes) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->CertificateInstallationRes_isUsed = 1u;
				break;
			case 11:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CertificateUpdateReq) */
				errn = decode_v2gCertificateUpdateReqType(stream, &exiDoc->CertificateUpdateReq, eventCode);
				exiDoc->CertificateUpdateReq_isUsed = 1u;
				break;
			case 12:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CertificateUpdateRes) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->CertificateUpdateRes_isUsed = 1u;
				break;
			case 13:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargeParameterDiscoveryReq) */
				errn = decode_v2gChargeParameterDiscoveryReqType(stream, &exiDoc->ChargeParameterDiscoveryReq, eventCode);
				exiDoc->ChargeParameterDiscoveryReq_isUsed = 1u;
				break;
			case 14:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargeParameterDiscoveryRes) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->ChargeParameterDiscoveryRes_isUsed = 1u;
				break;
			case 15:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingStatusReq) */
				errn = decode_v2gChargingStatusReqType(stream, &exiDoc->ChargingStatusReq, eventCode);
				exiDoc->ChargingStatusReq_isUsed = 1u;
				break;
			case 16:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingStatusRes) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->ChargingStatusRes_isUsed = 1u;
				break;
			case 17:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CurrentDemandReq) */
				errn = decode_v2gCurrentDemandReqType(stream, &exiDoc->CurrentDemandReq, eventCode);
				exiDoc->CurrentDemandReq_isUsed = 1u;
				break;
			case 18:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CurrentDemandRes) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->CurrentDemandRes_isUsed = 1u;
				break;
			case 19:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVChargeParameter) */
				errn = decode_v2gDC_EVChargeParameterType(stream, &exiDoc->DC_EVChargeParameter, eventCode);
				exiDoc->DC_EVChargeParameter_isUsed = 1u;
				break;
			case 20:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVPowerDeliveryParameter) */
				errn = decode_v2gDC_EVPowerDeliveryParameterType(stream, &exiDoc->DC_EVPowerDeliveryParameter, eventCode);
				exiDoc->DC_EVPowerDeliveryParameter_isUsed = 1u;
				break;
			case 21:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVSEChargeParameter) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->DC_EVSEChargeParameter_isUsed = 1u;
				break;
			case 22:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVSEStatus) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->DC_EVSEStatus_isUsed = 1u;
				break;
			case 23:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVStatus) */
				errn = decode_v2gDC_EVStatusType(stream, &exiDoc->DC_EVStatus, eventCode);
				exiDoc->DC_EVStatus_isUsed = 1u;
				break;
			case 24:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DSAKeyValue) */
				errn = decode_v2gDSAKeyValueType(stream, &exiDoc->DSAKeyValue, eventCode);
				exiDoc->DSAKeyValue_isUsed = 1u;
				break;
			case 25:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DigestMethod) */
				errn = decode_v2gDigestMethodType(stream, &exiDoc->DigestMethod, eventCode);
				exiDoc->DigestMethod_isUsed = 1u;
				break;
			case 26:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DigestValue) */
				/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
				errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
				if(errn == 0) {
					if(eventCode == 0) {
						errn = decodeUnsignedInteger16(stream, &exiDoc->DigestValue.bytesLen);
						if (errn == 0) {
							errn =  (exiDoc->DigestValue.bytesLen) <= EXIDocument_DigestValue_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
						}
						if (errn == 0) {
							errn = decodeBytes(stream, exiDoc->DigestValue.bytesLen, exiDoc->DigestValue.bytes);
						}
						exiDoc->DigestValue_isUsed = 1u;
					} else {
						/* Second level event (e.g., xsi:type, xsi:nil, ...) */
						errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					}
				}
				break;
			case 27:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVChargeParameter) */
				errn = decode_v2gEVChargeParameterType(stream, &exiDoc->EVChargeParameter, eventCode);
				exiDoc->EVChargeParameter_isUsed = 1u;
				break;
			case 28:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVPowerDeliveryParameter) */
				errn = decode_v2gEVPowerDeliveryParameterType(stream, &exiDoc->EVPowerDeliveryParameter, eventCode);
				exiDoc->EVPowerDeliveryParameter_isUsed = 1u;
				break;
			case 29:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEChargeParameter) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->EVSEChargeParameter_isUsed = 1u;
				break;
			case 30:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEStatus) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->EVSEStatus_isUsed = 1u;
				break;
			case 31:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVStatus) */
				errn = decode_v2gEVStatusType(stream, &exiDoc->EVStatus, eventCode);
				exiDoc->EVStatus_isUsed = 1u;
				break;
			case 32:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Entry) */
				errn = decode_v2gEntryType(stream, &exiDoc->Entry, eventCode);
				exiDoc->Entry_isUsed = 1u;
				break;
			case 33:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyInfo) */
				errn = decode_v2gKeyInfoType(stream, &exiDoc->KeyInfo, eventCode);
				exiDoc->KeyInfo_isUsed = 1u;
				break;
			case 34:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyName) */
				/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
				errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
				if(errn == 0) {
					if(eventCode == 0) {
						errn = decodeUnsignedInteger16(stream, &exiDoc->KeyName.charactersLen);
						if (errn == 0) {
							errn =  (exiDoc->KeyName.charactersLen - 2) <= EXIDocument_KeyName_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
						}
						if (errn == 0) {
							if (exiDoc->KeyName.charactersLen >= 2) {
								exiDoc->KeyName.charactersLen = (uint16_t)(exiDoc->KeyName.charactersLen - 2); /* string table miss */
								errn = decodeCharacters(stream, exiDoc->KeyName.charactersLen, exiDoc->KeyName.characters);
							} else {
								/* string table hit */
								errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
							}
						}
						exiDoc->KeyName_isUsed = 1u;
					} else {
						/* Second level event (e.g., xsi:type, xsi:nil, ...) */
						errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					}
				}
				break;
			case 35:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyValue) */
				errn = decode_v2gKeyValueType(stream, &exiDoc->KeyValue, eventCode);
				exiDoc->KeyValue_isUsed = 1u;
				break;
			case 36:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Manifest) */
				errn = decode_v2gManifestType(stream, &exiDoc->Manifest, eventCode);
				exiDoc->Manifest_isUsed = 1u;
				break;
			case 37:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}MeteringReceiptReq) */
				errn = decode_v2gMeteringReceiptReqType(stream, &exiDoc->MeteringReceiptReq, eventCode);
				exiDoc->MeteringReceiptReq_isUsed = 1u;
				break;
			case 38:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}MeteringReceiptRes) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->MeteringReceiptRes_isUsed = 1u;
				break;
			case 39:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}MgmtData) */
				/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
				errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
				if(errn == 0) {
					if(eventCode == 0) {
						errn = decodeUnsignedInteger16(stream, &exiDoc->MgmtData.charactersLen);
						if (errn == 0) {
							errn =  (exiDoc->MgmtData.charactersLen - 2) <= EXIDocument_MgmtData_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
						}
						if (errn == 0) {
							if (exiDoc->MgmtData.charactersLen >= 2) {
								exiDoc->MgmtData.charactersLen = (uint16_t)(exiDoc->MgmtData.charactersLen - 2); /* string table miss */
								errn = decodeCharacters(stream, exiDoc->MgmtData.charactersLen, exiDoc->MgmtData.characters);
							} else {
								/* string table hit */
								errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
							}
						}
						exiDoc->MgmtData_isUsed = 1u;
					} else {
						/* Second level event (e.g., xsi:type, xsi:nil, ...) */
						errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					}
				}
				break;
			case 40:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Object) */
				errn = decode_v2gObjectType(stream, &exiDoc->Object, eventCode);
				exiDoc->Object_isUsed = 1u;
				break;
			case 41:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PGPData) */
				errn = decode_v2gPGPDataType(stream, &exiDoc->PGPData, eventCode);
				exiDoc->PGPData_isUsed = 1u;
				break;
			case 42:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}PMaxScheduleEntry) */
				errn = decode_v2gPMaxScheduleEntryType(stream, &exiDoc->PMaxScheduleEntry, eventCode);
				exiDoc->PMaxScheduleEntry_isUsed = 1u;
				break;
			case 43:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PaymentDetailsReq) */
				errn = decode_v2gPaymentDetailsReqType(stream, &exiDoc->PaymentDetailsReq, eventCode);
				exiDoc->PaymentDetailsReq_isUsed = 1u;
				break;
			case 44:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PaymentDetailsRes) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->PaymentDetailsRes_isUsed = 1u;
				break;
			case 45:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PaymentServiceSelectionReq) */
				errn = decode_v2gPaymentServiceSelectionReqType(stream, &exiDoc->PaymentServiceSelectionReq, eventCode);
				exiDoc->PaymentServiceSelectionReq_isUsed = 1u;
				break;
			case 46:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PaymentServiceSelectionRes) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->PaymentServiceSelectionRes_isUsed = 1u;
				break;
			case 47:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PowerDeliveryReq) */
				errn = decode_v2gPowerDeliveryReqType(stream, &exiDoc->PowerDeliveryReq, eventCode);
				exiDoc->PowerDeliveryReq_isUsed = 1u;
				break;
			case 48:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PowerDeliveryRes) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->PowerDeliveryRes_isUsed = 1u;
				break;
			case 49:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PreChargeReq) */
				errn = decode_v2gPreChargeReqType(stream, &exiDoc->PreChargeReq, eventCode);
				exiDoc->PreChargeReq_isUsed = 1u;
				break;
			case 50:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PreChargeRes) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->PreChargeRes_isUsed = 1u;
				break;
			case 51:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}RSAKeyValue) */
				errn = decode_v2gRSAKeyValueType(stream, &exiDoc->RSAKeyValue, eventCode);
				exiDoc->RSAKeyValue_isUsed = 1u;
				break;
			case 52:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Reference) */
				errn = decode_v2gReferenceType(stream, &exiDoc->Reference, eventCode);
				exiDoc->Reference_isUsed = 1u;
				break;
			case 53:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}RelativeTimeInterval) */
				errn = decode_v2gRelativeTimeIntervalType(stream, &exiDoc->RelativeTimeInterval, eventCode);
				exiDoc->RelativeTimeInterval_isUsed = 1u;
				break;
			case 54:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}RetrievalMethod) */
				errn = decode_v2gRetrievalMethodType(stream, &exiDoc->RetrievalMethod, eventCode);
				exiDoc->RetrievalMethod_isUsed = 1u;
				break;
			case 55:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SAScheduleList) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->SAScheduleList_isUsed = 1u;
				break;
			case 56:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SASchedules) */
				errn = decode_v2gSASchedulesType(stream, &exiDoc->SASchedules, eventCode);
				exiDoc->SASchedules_isUsed = 1u;
				break;
			case 57:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SPKIData) */
				errn = decode_v2gSPKIDataType(stream, &exiDoc->SPKIData, eventCode);
				exiDoc->SPKIData_isUsed = 1u;
				break;
			case 58:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SalesTariffEntry) */
				errn = decode_v2gSalesTariffEntryType(stream, &exiDoc->SalesTariffEntry, eventCode);
				exiDoc->SalesTariffEntry_isUsed = 1u;
				break;
			case 59:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceDetailReq) */
				errn = decode_v2gServiceDetailReqType(stream, &exiDoc->ServiceDetailReq, eventCode);
				exiDoc->ServiceDetailReq_isUsed = 1u;
				break;
			case 60:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceDetailRes) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->ServiceDetailRes_isUsed = 1u;
				break;
			case 61:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceDiscoveryReq) */
				errn = decode_v2gServiceDiscoveryReqType(stream, &exiDoc->ServiceDiscoveryReq, eventCode);
				exiDoc->ServiceDiscoveryReq_isUsed = 1u;
				break;
			case 62:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceDiscoveryRes) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->ServiceDiscoveryRes_isUsed = 1u;
				break;
			case 63:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionSetupReq) */
				errn = decode_v2gSessionSetupReqType(stream, &exiDoc->SessionSetupReq, eventCode);
				exiDoc->SessionSetupReq_isUsed = 1u;
				break;
			case 64:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionSetupRes) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->SessionSetupRes_isUsed = 1u;
				break;
			case 65:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionStopReq) */
				errn = decode_v2gSessionStopReqType(stream, &exiDoc->SessionStopReq, eventCode);
				exiDoc->SessionStopReq_isUsed = 1u;
				break;
			case 66:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionStopRes) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->SessionStopRes_isUsed = 1u;
				break;
			case 67:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Signature) */
				errn = decode_v2gSignatureType(stream, &exiDoc->Signature, eventCode);
				exiDoc->Signature_isUsed = 1u;
				break;
			case 68:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignatureMethod) */
				errn = decode_v2gSignatureMethodType(stream, &exiDoc->SignatureMethod, eventCode);
				exiDoc->SignatureMethod_isUsed = 1u;
				break;
			case 69:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignatureProperties) */
				errn = decode_v2gSignaturePropertiesType(stream, &exiDoc->SignatureProperties, eventCode);
				exiDoc->SignatureProperties_isUsed = 1u;
				break;
			case 70:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignatureProperty) */
				errn = decode_v2gSignaturePropertyType(stream, &exiDoc->SignatureProperty, eventCode);
				exiDoc->SignatureProperty_isUsed = 1u;
				break;
			case 71:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignatureValue) */
				errn = decode_v2gSignatureValueType(stream, &exiDoc->SignatureValue, eventCode);
				exiDoc->SignatureValue_isUsed = 1u;
				break;
			case 72:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignedInfo) */
				errn = decode_v2gSignedInfoType(stream, &exiDoc->SignedInfo, eventCode);
				exiDoc->SignedInfo_isUsed = 1u;
				break;
			case 73:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}TimeInterval) */
				errn = decode_v2gIntervalType(stream, &exiDoc->TimeInterval, eventCode);
				exiDoc->TimeInterval_isUsed = 1u;
				break;
			case 74:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transform) */
				errn = decode_v2gTransformType(stream, &exiDoc->Transform, eventCode);
				exiDoc->Transform_isUsed = 1u;
				break;
			case 75:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transforms) */
				errn = decode_v2gTransformsType(stream, &exiDoc->Transforms, eventCode);
				exiDoc->Transforms_isUsed = 1u;
				break;
			case 76:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgDef}V2G_Message) */
				errn = decode_v2gAnonType_V2G_Message(stream, &exiDoc->V2G_Message, eventCode);
				exiDoc->V2G_Message_isUsed = 1u;
				break;
			case 77:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}WeldingDetectionReq) */
				errn = decode_v2gWeldingDetectionReqType(stream, &exiDoc->WeldingDetectionReq, eventCode);
				exiDoc->WeldingDetectionReq_isUsed = 1u;
				break;
			case 78:
				/* START_ELEMENT({urn:iso:15118:2:2013:MsgBody}WeldingDetectionRes) */
				printf ("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTt\n");				exiDoc->WeldingDetectionRes_isUsed = 1u;
				break;
			case 79:
				/* START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509Data) */
				errn = decode_v2gX509DataType(stream, &exiDoc->X509Data, eventCode);
				exiDoc->X509Data_isUsed = 1u;
				break;
			default:
				errn = EXI_ERROR_UNEXPECTED_EVENT_LEVEL1;
				break;
			}
		}

	}

	return errn;
}

#endif /* DEPLOY_ISO_CODEC */

#endif
