/*
 * v2gEXIDatatypes.h
 *
 *  Created on: 06.01.2016
 *      Author: melanie
 */

#ifndef ISO_COMM_CODEC_V2GEXIDATATYPES_H_
#define ISO_COMM_CODEC_V2GEXIDATATYPES_H_


#ifdef __cplusplus
extern "C" {
#endif

#define SUPPORT_YES 1
#define SUPPORT_NO 2
#define DEPLOY_ISO_CODEC SUPPORT_YES

#if DEPLOY_ISO_CODEC == SUPPORT_YES

#include <stdint.h>

#include "EXITypes.h"


/* Datatype definitions and structs for given XML Schema definitions */

#define UNION_YES 1
#define UNION_NO 2
#define SAVE_MEMORY_WITH_UNNAMED_UNION UNION_YES

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ContractSignatureEncryptedPrivateKeyType',  base type name='privateKeyType',  content type='SIMPLE',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  derivedBy='EXTENSION'.  */
#define v2gContractSignatureEncryptedPrivateKeyType_Id_CHARACTERS_SIZE 50
#define v2gContractSignatureEncryptedPrivateKeyType_CONTENT_BYTES_SIZE 350
struct v2gContractSignatureEncryptedPrivateKeyType {
	/* attribute: Id {http://www.w3.org/2001/XMLSchema,ID} */
	struct {
		exi_string_character_t characters[v2gContractSignatureEncryptedPrivateKeyType_Id_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Id ;
	/* simple content: urn:iso:15118:2:2013:MsgDataTypes,privateKeyType */
	struct {
		uint8_t bytes[v2gContractSignatureEncryptedPrivateKeyType_CONTENT_BYTES_SIZE];
		uint16_t bytesLen;
	}  CONTENT ;
};

typedef enum {
	v2gunitSymbolType_h = 0,
	v2gunitSymbolType_m = 1,
	v2gunitSymbolType_s = 2,
	v2gunitSymbolType_A = 3,
	v2gunitSymbolType_V = 4,
	v2gunitSymbolType_W = 5,
	v2gunitSymbolType_Wh = 6
} v2gunitSymbolType;

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,X509IssuerSerialType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":X509IssuerName,"http://www.w3.org/2000/09/xmldsig#":X509SerialNumber)',  derivedBy='RESTRICTION'.  */
#define v2gX509IssuerSerialType_X509IssuerName_CHARACTERS_SIZE 50
struct v2gX509IssuerSerialType {
	/* element: "http://www.w3.org/2000/09/xmldsig#":X509IssuerName, http://www.w3.org/2001/XMLSchema,string */
	struct {
		exi_string_character_t characters[v2gX509IssuerSerialType_X509IssuerName_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  X509IssuerName ;
	/* element: "http://www.w3.org/2000/09/xmldsig#":X509SerialNumber, http://www.w3.org/2001/XMLSchema,integer */
	int64_t X509SerialNumber ;
};

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,SignaturePropertyType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='((WC[##other:"http://www.w3.org/2000/09/xmldsig#"])){1-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
#define v2gSignaturePropertyType_Target_CHARACTERS_SIZE 50
#define v2gSignaturePropertyType_Id_CHARACTERS_SIZE 50
struct v2gSignaturePropertyType {
	/* attribute: Target {http://www.w3.org/2001/XMLSchema,anyURI} */
	struct {
		exi_string_character_t characters[v2gSignaturePropertyType_Target_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Target ;
	/* attribute: Id {http://www.w3.org/2001/XMLSchema,ID} */
	struct {
		exi_string_character_t characters[v2gSignaturePropertyType_Id_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Id ;
	unsigned int Id_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SelectedServiceType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":ServiceID,"urn:iso:15118:2:2013:MsgDataTypes":ParameterSetID{0-1})',  derivedBy='RESTRICTION'.  */
struct v2gSelectedServiceType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":ServiceID, urn:iso:15118:2:2013:MsgDataTypes,serviceIDType */
	uint16_t ServiceID ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":ParameterSetID, http://www.w3.org/2001/XMLSchema,short */
	int16_t ParameterSetID ;
	unsigned int ParameterSetID_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EVChargeParameterType',  base type name='anyType',  content type='ELEMENT',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":DepartureTime{0-1})',  derivedBy='RESTRICTION'.  */
struct v2gEVChargeParameterType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":DepartureTime, http://www.w3.org/2001/XMLSchema,unsignedInt */
	uint32_t DepartureTime ;
	unsigned int DepartureTime_isUsed:1;
};

typedef enum {
	v2gDC_EVErrorCodeType_NO_ERROR = 0,
	v2gDC_EVErrorCodeType_FAILED_RESSTemperatureInhibit = 1,
	v2gDC_EVErrorCodeType_FAILED_EVShiftPosition = 2,
	v2gDC_EVErrorCodeType_FAILED_ChargerConnectorLockFault = 3,
	v2gDC_EVErrorCodeType_FAILED_EVRESSMalfunction = 4,
	v2gDC_EVErrorCodeType_FAILED_ChargingCurrentdifferential = 5,
	v2gDC_EVErrorCodeType_FAILED_ChargingVoltageOutOfRange = 6,
	v2gDC_EVErrorCodeType_Reserved_A = 7,
	v2gDC_EVErrorCodeType_Reserved_B = 8,
	v2gDC_EVErrorCodeType_Reserved_C = 9,
	v2gDC_EVErrorCodeType_FAILED_ChargingSystemIncompatibility = 10,
	v2gDC_EVErrorCodeType_NoData = 11
} v2gDC_EVErrorCodeType;

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EVSEChargeParameterType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
struct v2gEVSEChargeParameterType {
	int noContent; /* avoid warning */
};

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,CanonicalizationMethodType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='((WC[##any]){0-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
#define v2gCanonicalizationMethodType_Algorithm_CHARACTERS_SIZE 50
struct v2gCanonicalizationMethodType {
	/* attribute: Algorithm {http://www.w3.org/2001/XMLSchema,anyURI} */
	struct {
		exi_string_character_t characters[v2gCanonicalizationMethodType_Algorithm_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Algorithm ;
};

typedef enum {
	v2gisolationLevelType_Invalid = 0,
	v2gisolationLevelType_Valid = 1,
	v2gisolationLevelType_Warning = 2,
	v2gisolationLevelType_Fault = 3,
	v2gisolationLevelType_No_IMD = 4
} v2gisolationLevelType;

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SASchedulesType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
struct v2gSASchedulesType {
	int noContent; /* avoid warning */
};

typedef enum {
	v2gcostKindType_relativePricePercentage = 0,
	v2gcostKindType_RenewableGenerationPercentage = 1,
	v2gcostKindType_CarbonDioxideEmission = 2
} v2gcostKindType;

typedef enum {
	v2gresponseCodeType_OK = 0,
	v2gresponseCodeType_OK_NewSessionEstablished = 1,
	v2gresponseCodeType_OK_OldSessionJoined = 2,
	v2gresponseCodeType_OK_CertificateExpiresSoon = 3,
	v2gresponseCodeType_FAILED = 4,
	v2gresponseCodeType_FAILED_SequenceError = 5,
	v2gresponseCodeType_FAILED_ServiceIDInvalid = 6,
	v2gresponseCodeType_FAILED_UnknownSession = 7,
	v2gresponseCodeType_FAILED_ServiceSelectionInvalid = 8,
	v2gresponseCodeType_FAILED_PaymentSelectionInvalid = 9,
	v2gresponseCodeType_FAILED_CertificateExpired = 10,
	v2gresponseCodeType_FAILED_SignatureError = 11,
	v2gresponseCodeType_FAILED_NoCertificateAvailable = 12,
	v2gresponseCodeType_FAILED_CertChainError = 13,
	v2gresponseCodeType_FAILED_ChallengeInvalid = 14,
	v2gresponseCodeType_FAILED_ContractCanceled = 15,
	v2gresponseCodeType_FAILED_WrongChargeParameter = 16,
	v2gresponseCodeType_FAILED_PowerDeliveryNotApplied = 17,
	v2gresponseCodeType_FAILED_TariffSelectionInvalid = 18,
	v2gresponseCodeType_FAILED_ChargingProfileInvalid = 19,
	v2gresponseCodeType_FAILED_MeteringSignatureNotValid = 20,
	v2gresponseCodeType_FAILED_NoChargeServiceSelected = 21,
	v2gresponseCodeType_FAILED_WrongEnergyTransferMode = 22,
	v2gresponseCodeType_FAILED_ContactorError = 23,
	v2gresponseCodeType__FAILED_CertificateNotAllowedAtThisEVSE = 24,
	v2gresponseCodeType_FAILED_CertificateRevoked = 25
} v2gresponseCodeType;

/* Complex type name='urn:iso:15118:2:2013:MsgBody,SessionSetupResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":EVSEID,"urn:iso:15118:2:2013:MsgBody":EVSETimeStamp{0-1})',  derivedBy='EXTENSION'.  */
#define v2gSessionSetupResType_EVSEID_CHARACTERS_SIZE 37 /* XML schema facet maxLength for urn:iso:15118:2:2013:MsgDataTypes,evseIDType is 37 */
struct v2gSessionSetupResType {
	/* element: "urn:iso:15118:2:2013:MsgBody":ResponseCode, urn:iso:15118:2:2013:MsgDataTypes,responseCodeType */
	v2gresponseCodeType ResponseCode ;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVSEID, urn:iso:15118:2:2013:MsgDataTypes,evseIDType */
	struct {
		exi_string_character_t characters[v2gSessionSetupResType_EVSEID_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  EVSEID ;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVSETimeStamp, http://www.w3.org/2001/XMLSchema,long */
	int64_t EVSETimeStamp ;
	unsigned int EVSETimeStamp_isUsed:1;
};

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,X509DataType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("http://www.w3.org/2000/09/xmldsig#":X509IssuerSerial|"http://www.w3.org/2000/09/xmldsig#":X509SKI|"http://www.w3.org/2000/09/xmldsig#":X509SubjectName|"http://www.w3.org/2000/09/xmldsig#":X509Certificate|"http://www.w3.org/2000/09/xmldsig#":X509CRL|(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]))){1-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
#define v2gX509DataType_X509IssuerSerial_ARRAY_SIZE 1
#define v2gX509DataType_X509SKI_BYTES_SIZE 350
#define v2gX509DataType_X509SKI_ARRAY_SIZE 1
#define v2gX509DataType_X509SubjectName_CHARACTERS_SIZE 50
#define v2gX509DataType_X509SubjectName_ARRAY_SIZE 1
#define v2gX509DataType_X509Certificate_BYTES_SIZE 350
#define v2gX509DataType_X509Certificate_ARRAY_SIZE 1
#define v2gX509DataType_X509CRL_BYTES_SIZE 350
#define v2gX509DataType_X509CRL_ARRAY_SIZE 1
struct v2gX509DataType {
	/* element: "http://www.w3.org/2000/09/xmldsig#":X509IssuerSerial, Complex type name='http://www.w3.org/2000/09/xmldsig#,X509IssuerSerialType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":X509IssuerName,"http://www.w3.org/2000/09/xmldsig#":X509SerialNumber)',  derivedBy='RESTRICTION'.  */
	struct {
		struct v2gX509IssuerSerialType array[v2gX509DataType_X509IssuerSerial_ARRAY_SIZE];
		uint16_t arrayLen;
	} X509IssuerSerial;
	/* element: "http://www.w3.org/2000/09/xmldsig#":X509SKI, http://www.w3.org/2001/XMLSchema,base64Binary */
	struct {
		struct {
			uint8_t bytes[v2gX509DataType_X509SKI_BYTES_SIZE];
			uint16_t bytesLen;
		}  array[v2gX509DataType_X509SKI_ARRAY_SIZE];
		uint16_t arrayLen;
	} X509SKI;
	/* element: "http://www.w3.org/2000/09/xmldsig#":X509SubjectName, http://www.w3.org/2001/XMLSchema,string */
	struct {
		struct {
			exi_string_character_t characters[v2gX509DataType_X509SubjectName_CHARACTERS_SIZE];
			uint16_t charactersLen;
		}  array[v2gX509DataType_X509SubjectName_ARRAY_SIZE];
		uint16_t arrayLen;
	} X509SubjectName;
	/* element: "http://www.w3.org/2000/09/xmldsig#":X509Certificate, http://www.w3.org/2001/XMLSchema,base64Binary */
	struct {
		struct {
			uint8_t bytes[v2gX509DataType_X509Certificate_BYTES_SIZE];
			uint16_t bytesLen;
		}  array[v2gX509DataType_X509Certificate_ARRAY_SIZE];
		uint16_t arrayLen;
	} X509Certificate;
	/* element: "http://www.w3.org/2000/09/xmldsig#":X509CRL, http://www.w3.org/2001/XMLSchema,base64Binary */
	struct {
		struct {
			uint8_t bytes[v2gX509DataType_X509CRL_BYTES_SIZE];
			uint16_t bytesLen;
		}  array[v2gX509DataType_X509CRL_ARRAY_SIZE];
		uint16_t arrayLen;
	} X509CRL;
};

typedef enum {
	v2gchargeProgressType_Start = 0,
	v2gchargeProgressType_Stop = 1,
	v2gchargeProgressType_Renegotiate = 2
} v2gchargeProgressType;

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,SignatureMethodType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":HMACOutputLength{0-1},(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]){0-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
#define v2gSignatureMethodType_Algorithm_CHARACTERS_SIZE 50
struct v2gSignatureMethodType {
	/* attribute: Algorithm {http://www.w3.org/2001/XMLSchema,anyURI} */
	struct {
		exi_string_character_t characters[v2gSignatureMethodType_Algorithm_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Algorithm ;
	/* element: "http://www.w3.org/2000/09/xmldsig#":HMACOutputLength, http://www.w3.org/2000/09/xmldsig#,HMACOutputLengthType */
	int64_t HMACOutputLength ;
	unsigned int HMACOutputLength_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EVPowerDeliveryParameterType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
struct v2gEVPowerDeliveryParameterType {
	int noContent; /* avoid warning */
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ListOfRootCertificateIDsType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":RootCertificateID{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
#define v2gListOfRootCertificateIDsType_RootCertificateID_ARRAY_SIZE 5
struct v2gListOfRootCertificateIDsType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":RootCertificateID, Complex type name='http://www.w3.org/2000/09/xmldsig#,X509IssuerSerialType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":X509IssuerName,"http://www.w3.org/2000/09/xmldsig#":X509SerialNumber)',  derivedBy='RESTRICTION'.  */
	struct {
		struct v2gX509IssuerSerialType array[v2gListOfRootCertificateIDsType_RootCertificateID_ARRAY_SIZE];
		uint16_t arrayLen;
	} RootCertificateID;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVStatusType',  base type name='EVStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":EVReady,"urn:iso:15118:2:2013:MsgDataTypes":EVErrorCode,"urn:iso:15118:2:2013:MsgDataTypes":EVRESSSOC)',  derivedBy='EXTENSION'.  */
struct v2gDC_EVStatusType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVReady, http://www.w3.org/2001/XMLSchema,boolean */
	int EVReady ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVErrorCode, urn:iso:15118:2:2013:MsgDataTypes,DC_EVErrorCodeType */
	v2gDC_EVErrorCodeType EVErrorCode ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVRESSSOC, urn:iso:15118:2:2013:MsgDataTypes,percentValueType */
	int8_t EVRESSSOC ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,SessionStopResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode)',  derivedBy='EXTENSION'.  */
struct v2gSessionStopResType {
	/* element: "urn:iso:15118:2:2013:MsgBody":ResponseCode, urn:iso:15118:2:2013:MsgDataTypes,responseCodeType */
	v2gresponseCodeType ResponseCode ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,ChargingStatusReqType',  base type name='BodyBaseType',  content type='EMPTY',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  derivedBy='EXTENSION'.  */
struct v2gChargingStatusReqType {
	int noContent; /* avoid warning */
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,WeldingDetectionReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":DC_EVStatus)',  derivedBy='EXTENSION'.  */
struct v2gWeldingDetectionReqType {
	/* element: "urn:iso:15118:2:2013:MsgBody":DC_EVStatus, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVStatusType',  base type name='EVStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":EVReady,"urn:iso:15118:2:2013:MsgDataTypes":EVErrorCode,"urn:iso:15118:2:2013:MsgDataTypes":EVRESSSOC)',  derivedBy='EXTENSION'.  */
	struct v2gDC_EVStatusType DC_EVStatus ;
};

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,SignaturePropertiesType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":SignatureProperty{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
#define v2gSignaturePropertiesType_Id_CHARACTERS_SIZE 50
#define v2gSignaturePropertiesType_SignatureProperty_ARRAY_SIZE 1
struct v2gSignaturePropertiesType {
	/* attribute: Id {http://www.w3.org/2001/XMLSchema,ID} */
	struct {
		exi_string_character_t characters[v2gSignaturePropertiesType_Id_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Id ;
	unsigned int Id_isUsed:1;
	/* element: "http://www.w3.org/2000/09/xmldsig#":SignatureProperty, Complex type name='http://www.w3.org/2000/09/xmldsig#,SignaturePropertyType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='((WC[##other:"http://www.w3.org/2000/09/xmldsig#"])){1-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
	struct {
		struct v2gSignaturePropertyType array[v2gSignaturePropertiesType_SignatureProperty_ARRAY_SIZE];
		uint16_t arrayLen;
	} SignatureProperty;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SelectedServiceListType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":SelectedService{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
#define v2gSelectedServiceListType_SelectedService_ARRAY_SIZE 5
struct v2gSelectedServiceListType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":SelectedService, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SelectedServiceType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":ServiceID,"urn:iso:15118:2:2013:MsgDataTypes":ParameterSetID{0-1})',  derivedBy='RESTRICTION'.  */
	struct {
		struct v2gSelectedServiceType array[v2gSelectedServiceListType_SelectedService_ARRAY_SIZE];
		uint16_t arrayLen;
	} SelectedService;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EMAIDType',  base type name='eMAIDType',  content type='SIMPLE',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  derivedBy='EXTENSION'.  */
#define v2gEMAIDType_Id_CHARACTERS_SIZE 50
#define v2gEMAIDType_CONTENT_CHARACTERS_SIZE 50
struct v2gEMAIDType {
	/* attribute: Id {http://www.w3.org/2001/XMLSchema,ID} */
	struct {
		exi_string_character_t characters[v2gEMAIDType_Id_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Id ;
	/* simple content: urn:iso:15118:2:2013:MsgDataTypes,eMAIDType */
	struct {
		exi_string_character_t characters[v2gEMAIDType_CONTENT_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  CONTENT ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,IntervalType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
struct v2gIntervalType {
	int noContent; /* avoid warning */
};

typedef enum {
	v2gEVSEProcessingType_Finished = 0,
	v2gEVSEProcessingType_Ongoing = 1,
	v2gEVSEProcessingType_Ongoing_WaitingForCustomerInteraction = 2
} v2gEVSEProcessingType;

/* Complex type name='urn:iso:15118:2:2013:MsgBody,CableCheckReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":DC_EVStatus)',  derivedBy='EXTENSION'.  */
struct v2gCableCheckReqType {
	/* element: "urn:iso:15118:2:2013:MsgBody":DC_EVStatus, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVStatusType',  base type name='EVStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":EVReady,"urn:iso:15118:2:2013:MsgDataTypes":EVErrorCode,"urn:iso:15118:2:2013:MsgDataTypes":EVRESSSOC)',  derivedBy='EXTENSION'.  */
	struct v2gDC_EVStatusType DC_EVStatus ;
};

typedef enum {
	v2gEVSENotificationType_None = 0,
	v2gEVSENotificationType_StopCharging = 1,
	v2gEVSENotificationType_ReNegotiation = 2
} v2gEVSENotificationType;

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,AC_EVSEStatusType',  base type name='EVSEStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification),("urn:iso:15118:2:2013:MsgDataTypes":RCD))',  derivedBy='EXTENSION'.  */
struct v2gAC_EVSEStatusType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay, http://www.w3.org/2001/XMLSchema,unsignedShort */
	uint16_t NotificationMaxDelay ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVSENotification, urn:iso:15118:2:2013:MsgDataTypes,EVSENotificationType */
	v2gEVSENotificationType EVSENotification ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":RCD, http://www.w3.org/2001/XMLSchema,boolean */
	int RCD ;
};

typedef enum {
	v2gchargingSessionType_Terminate = 0,
	v2gchargingSessionType_Pause = 1
} v2gchargingSessionType;

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,SPKIDataType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":SPKISexp,(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]){0-1}){1-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
#define v2gSPKIDataType_SPKISexp_BYTES_SIZE 350
#define v2gSPKIDataType_SPKISexp_ARRAY_SIZE 1
struct v2gSPKIDataType {
	/* element: "http://www.w3.org/2000/09/xmldsig#":SPKISexp, http://www.w3.org/2001/XMLSchema,base64Binary */
	struct {
		struct {
			uint8_t bytes[v2gSPKIDataType_SPKISexp_BYTES_SIZE];
			uint16_t bytesLen;
		}  array[v2gSPKIDataType_SPKISexp_ARRAY_SIZE];
		uint16_t arrayLen;
	} SPKISexp;
};

typedef enum {
	v2gEnergyTransferModeType_AC_single_phase_core = 0,
	v2gEnergyTransferModeType_AC_three_phase_core = 1,
	v2gEnergyTransferModeType_DC_core = 2,
	v2gEnergyTransferModeType_DC_extended = 3,
	v2gEnergyTransferModeType_DC_combo_core = 4,
	v2gEnergyTransferModeType_DC_unique = 5
} v2gEnergyTransferModeType;

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,ObjectType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='((WC[##any])){0-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
#define v2gObjectType_Id_CHARACTERS_SIZE 50
#define v2gObjectType_MimeType_CHARACTERS_SIZE 50
#define v2gObjectType_Encoding_CHARACTERS_SIZE 50
struct v2gObjectType {
	/* attribute: Id {http://www.w3.org/2001/XMLSchema,ID} */
	struct {
		exi_string_character_t characters[v2gObjectType_Id_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Id ;
	unsigned int Id_isUsed:1;
	/* attribute: MimeType {http://www.w3.org/2001/XMLSchema,string} */
	struct {
		exi_string_character_t characters[v2gObjectType_MimeType_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  MimeType ;
	unsigned int MimeType_isUsed:1;
	/* attribute: Encoding {http://www.w3.org/2001/XMLSchema,anyURI} */
	struct {
		exi_string_character_t characters[v2gObjectType_Encoding_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Encoding ;
	unsigned int Encoding_isUsed:1;
};

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,SignatureValueType',  base type name='base64Binary',  content type='SIMPLE',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  derivedBy='EXTENSION'.  */
#define v2gSignatureValueType_Id_CHARACTERS_SIZE 50
#define v2gSignatureValueType_CONTENT_BYTES_SIZE 350
struct v2gSignatureValueType {
	/* attribute: Id {http://www.w3.org/2001/XMLSchema,ID} */
	struct {
		exi_string_character_t characters[v2gSignatureValueType_Id_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Id ;
	unsigned int Id_isUsed:1;
	/* simple content: http://www.w3.org/2001/XMLSchema,base64Binary */
	struct {
		uint8_t bytes[v2gSignatureValueType_CONTENT_BYTES_SIZE];
		uint16_t bytesLen;
	}  CONTENT ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SubCertificatesType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Certificate{1-4})',  derivedBy='RESTRICTION'.  */
#define v2gSubCertificatesType_Certificate_BYTES_SIZE 800 /* XML schema facet maxLength for urn:iso:15118:2:2013:MsgDataTypes,certificateType is 800 */
#define v2gSubCertificatesType_Certificate_ARRAY_SIZE 4
struct v2gSubCertificatesType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":Certificate, urn:iso:15118:2:2013:MsgDataTypes,certificateType */
	struct {
		struct {
		uint8_t bytes[v2gSubCertificatesType_Certificate_BYTES_SIZE];
		uint16_t bytesLen;
	}  array[v2gSubCertificatesType_Certificate_ARRAY_SIZE];
		uint16_t arrayLen;
	} Certificate;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,AuthorizationReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":GenChallenge{0-1})',  derivedBy='EXTENSION'.  */
#define v2gAuthorizationReqType_Id_CHARACTERS_SIZE 50
#define v2gAuthorizationReqType_GenChallenge_BYTES_SIZE 16 /* XML schema facet length for urn:iso:15118:2:2013:MsgDataTypes,genChallengeType is 16 */
struct v2gAuthorizationReqType {
	/* attribute: Id {http://www.w3.org/2001/XMLSchema,ID} */
	struct {
		exi_string_character_t characters[v2gAuthorizationReqType_Id_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Id ;
	unsigned int Id_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgBody":GenChallenge, urn:iso:15118:2:2013:MsgDataTypes,genChallengeType */
	struct {
		uint8_t bytes[v2gAuthorizationReqType_GenChallenge_BYTES_SIZE];
		uint16_t bytesLen;
	}  GenChallenge ;
	unsigned int GenChallenge_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SupportedEnergyTransferModeType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":EnergyTransferMode{1-6})',  derivedBy='RESTRICTION'.  */
#define v2gSupportedEnergyTransferModeType_EnergyTransferMode_ARRAY_SIZE 5
struct v2gSupportedEnergyTransferModeType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EnergyTransferMode, urn:iso:15118:2:2013:MsgDataTypes,EnergyTransferModeType */
	struct {
		v2gEnergyTransferModeType array[v2gSupportedEnergyTransferModeType_EnergyTransferMode_ARRAY_SIZE];
		uint16_t arrayLen;
	} EnergyTransferMode;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
struct v2gPhysicalValueType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":Multiplier, urn:iso:15118:2:2013:MsgDataTypes,unitMultiplierType */
	int8_t Multiplier ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":Unit, urn:iso:15118:2:2013:MsgDataTypes,unitSymbolType */
	v2gunitSymbolType Unit ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":Value, http://www.w3.org/2001/XMLSchema,short */
	int16_t Value ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,MeterInfoType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":MeterID,"urn:iso:15118:2:2013:MsgDataTypes":MeterReading{0-1},"urn:iso:15118:2:2013:MsgDataTypes":SigMeterReading{0-1},"urn:iso:15118:2:2013:MsgDataTypes":MeterStatus{0-1},"urn:iso:15118:2:2013:MsgDataTypes":TMeter{0-1})',  derivedBy='RESTRICTION'.  */
#define v2gMeterInfoType_MeterID_CHARACTERS_SIZE 32 /* XML schema facet maxLength for urn:iso:15118:2:2013:MsgDataTypes,meterIDType is 32 */
#define v2gMeterInfoType_SigMeterReading_BYTES_SIZE 64 /* XML schema facet maxLength for urn:iso:15118:2:2013:MsgDataTypes,sigMeterReadingType is 64 */
struct v2gMeterInfoType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":MeterID, urn:iso:15118:2:2013:MsgDataTypes,meterIDType */
	struct {
		exi_string_character_t characters[v2gMeterInfoType_MeterID_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  MeterID ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":MeterReading, http://www.w3.org/2001/XMLSchema,unsignedLong */
	uint64_t MeterReading ;
	unsigned int MeterReading_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":SigMeterReading, urn:iso:15118:2:2013:MsgDataTypes,sigMeterReadingType */
	struct {
		uint8_t bytes[v2gMeterInfoType_SigMeterReading_BYTES_SIZE];
		uint16_t bytesLen;
	}  SigMeterReading ;
	unsigned int SigMeterReading_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":MeterStatus, urn:iso:15118:2:2013:MsgDataTypes,meterStatusType */
	int16_t MeterStatus ;
	unsigned int MeterStatus_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":TMeter, http://www.w3.org/2001/XMLSchema,long */
	int64_t TMeter ;
	unsigned int TMeter_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,SessionSetupReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":EVCCID)',  derivedBy='EXTENSION'.  */
#define v2gSessionSetupReqType_EVCCID_BYTES_SIZE 6 /* XML schema facet maxLength for urn:iso:15118:2:2013:MsgDataTypes,evccIDType is 6 */
struct v2gSessionSetupReqType {
	/* element: "urn:iso:15118:2:2013:MsgBody":EVCCID, urn:iso:15118:2:2013:MsgDataTypes,evccIDType */
	struct {
		uint8_t bytes[v2gSessionSetupReqType_EVCCID_BYTES_SIZE];
		uint16_t bytesLen;
	}  EVCCID ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVChargeParameterType',  base type name='EVChargeParameterType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":DepartureTime{0-1}),("urn:iso:15118:2:2013:MsgDataTypes":DC_EVStatus,"urn:iso:15118:2:2013:MsgDataTypes":EVMaximumCurrentLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVMaximumPowerLimit{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVMaximumVoltageLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVEnergyCapacity{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVEnergyRequest{0-1},"urn:iso:15118:2:2013:MsgDataTypes":FullSOC{0-1},"urn:iso:15118:2:2013:MsgDataTypes":BulkSOC{0-1}))',  derivedBy='EXTENSION'.  */
struct v2gDC_EVChargeParameterType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":DepartureTime, http://www.w3.org/2001/XMLSchema,unsignedInt */
	uint32_t DepartureTime ;
	unsigned int DepartureTime_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":DC_EVStatus, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVStatusType',  base type name='EVStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":EVReady,"urn:iso:15118:2:2013:MsgDataTypes":EVErrorCode,"urn:iso:15118:2:2013:MsgDataTypes":EVRESSSOC)',  derivedBy='EXTENSION'.  */
	struct v2gDC_EVStatusType DC_EVStatus ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVMaximumCurrentLimit, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVMaximumCurrentLimit ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVMaximumPowerLimit, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVMaximumPowerLimit ;
	unsigned int EVMaximumPowerLimit_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVMaximumVoltageLimit, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVMaximumVoltageLimit ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVEnergyCapacity, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVEnergyCapacity ;
	unsigned int EVEnergyCapacity_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVEnergyRequest, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVEnergyRequest ;
	unsigned int EVEnergyRequest_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":FullSOC, urn:iso:15118:2:2013:MsgDataTypes,percentValueType */
	int8_t FullSOC ;
	unsigned int FullSOC_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":BulkSOC, urn:iso:15118:2:2013:MsgDataTypes,percentValueType */
	int8_t BulkSOC ;
	unsigned int BulkSOC_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVPowerDeliveryParameterType',  base type name='EVPowerDeliveryParameterType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":DC_EVStatus,"urn:iso:15118:2:2013:MsgDataTypes":BulkChargingComplete{0-1},"urn:iso:15118:2:2013:MsgDataTypes":ChargingComplete)',  derivedBy='EXTENSION'.  */
struct v2gDC_EVPowerDeliveryParameterType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":DC_EVStatus, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVStatusType',  base type name='EVStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":EVReady,"urn:iso:15118:2:2013:MsgDataTypes":EVErrorCode,"urn:iso:15118:2:2013:MsgDataTypes":EVRESSSOC)',  derivedBy='EXTENSION'.  */
	struct v2gDC_EVStatusType DC_EVStatus ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":BulkChargingComplete, http://www.w3.org/2001/XMLSchema,boolean */
	int BulkChargingComplete ;
	unsigned int BulkChargingComplete_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":ChargingComplete, http://www.w3.org/2001/XMLSchema,boolean */
	int ChargingComplete ;
};

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,RSAKeyValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":Modulus,"http://www.w3.org/2000/09/xmldsig#":Exponent)',  derivedBy='RESTRICTION'.  */
#define v2gRSAKeyValueType_Modulus_BYTES_SIZE 350
#define v2gRSAKeyValueType_Exponent_BYTES_SIZE 350
struct v2gRSAKeyValueType {
	/* element: "http://www.w3.org/2000/09/xmldsig#":Modulus, http://www.w3.org/2000/09/xmldsig#,CryptoBinary */
	struct {
		uint8_t bytes[v2gRSAKeyValueType_Modulus_BYTES_SIZE];
		uint16_t bytesLen;
	}  Modulus ;
	/* element: "http://www.w3.org/2000/09/xmldsig#":Exponent, http://www.w3.org/2000/09/xmldsig#,CryptoBinary */
	struct {
		uint8_t bytes[v2gRSAKeyValueType_Exponent_BYTES_SIZE];
		uint16_t bytesLen;
	}  Exponent ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,RelativeTimeIntervalType',  base type name='IntervalType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":start,"urn:iso:15118:2:2013:MsgDataTypes":duration{0-1})',  derivedBy='EXTENSION'.  */
struct v2gRelativeTimeIntervalType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":start, urn:iso:15118:2:2013:MsgDataTypes,#AnonType_startRelativeTimeIntervalType */
	uint32_t start ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":duration, urn:iso:15118:2:2013:MsgDataTypes,#AnonType_durationRelativeTimeIntervalType */
	uint32_t duration ;
	unsigned int duration_isUsed:1;
};

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,PGPDataType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("http://www.w3.org/2000/09/xmldsig#":PGPKeyID,"http://www.w3.org/2000/09/xmldsig#":PGPKeyPacket{0-1},(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]){0-UNBOUNDED})|("http://www.w3.org/2000/09/xmldsig#":PGPKeyPacket,(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]){0-UNBOUNDED}))',  derivedBy='RESTRICTION'.  */
#define v2gPGPDataType_PGPKeyID_BYTES_SIZE 350
#define v2gPGPDataType_PGPKeyPacket_BYTES_SIZE 350
struct v2gPGPDataType {
	/* element: "http://www.w3.org/2000/09/xmldsig#":PGPKeyID, http://www.w3.org/2001/XMLSchema,base64Binary */
	struct {
		uint8_t bytes[v2gPGPDataType_PGPKeyID_BYTES_SIZE];
		uint16_t bytesLen;
	}  PGPKeyID ;
	unsigned int PGPKeyID_isUsed:1;
	/* element: "http://www.w3.org/2000/09/xmldsig#":PGPKeyPacket, http://www.w3.org/2001/XMLSchema,base64Binary */
	struct {
		uint8_t bytes[v2gPGPDataType_PGPKeyPacket_BYTES_SIZE];
		uint16_t bytesLen;
	}  PGPKeyPacket ;
	unsigned int PGPKeyPacket_isUsed:1;
};

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,DSAKeyValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("http://www.w3.org/2000/09/xmldsig#":P,"http://www.w3.org/2000/09/xmldsig#":Q){0-1},"http://www.w3.org/2000/09/xmldsig#":G{0-1},"http://www.w3.org/2000/09/xmldsig#":Y,"http://www.w3.org/2000/09/xmldsig#":J{0-1},("http://www.w3.org/2000/09/xmldsig#":Seed,"http://www.w3.org/2000/09/xmldsig#":PgenCounter){0-1})',  derivedBy='RESTRICTION'.  */
#define v2gDSAKeyValueType_P_BYTES_SIZE 350
#define v2gDSAKeyValueType_Q_BYTES_SIZE 350
#define v2gDSAKeyValueType_G_BYTES_SIZE 350
#define v2gDSAKeyValueType_Y_BYTES_SIZE 350
#define v2gDSAKeyValueType_J_BYTES_SIZE 350
#define v2gDSAKeyValueType_Seed_BYTES_SIZE 350
#define v2gDSAKeyValueType_PgenCounter_BYTES_SIZE 350
struct v2gDSAKeyValueType {
	/* element: "http://www.w3.org/2000/09/xmldsig#":P, http://www.w3.org/2000/09/xmldsig#,CryptoBinary */
	struct {
		uint8_t bytes[v2gDSAKeyValueType_P_BYTES_SIZE];
		uint16_t bytesLen;
	}  P ;
	unsigned int P_isUsed:1;
	/* element: "http://www.w3.org/2000/09/xmldsig#":Q, http://www.w3.org/2000/09/xmldsig#,CryptoBinary */
	struct {
		uint8_t bytes[v2gDSAKeyValueType_Q_BYTES_SIZE];
		uint16_t bytesLen;
	}  Q ;
	unsigned int Q_isUsed:1;
	/* element: "http://www.w3.org/2000/09/xmldsig#":G, http://www.w3.org/2000/09/xmldsig#,CryptoBinary */
	struct {
		uint8_t bytes[v2gDSAKeyValueType_G_BYTES_SIZE];
		uint16_t bytesLen;
	}  G ;
	unsigned int G_isUsed:1;
	/* element: "http://www.w3.org/2000/09/xmldsig#":Y, http://www.w3.org/2000/09/xmldsig#,CryptoBinary */
	struct {
		uint8_t bytes[v2gDSAKeyValueType_Y_BYTES_SIZE];
		uint16_t bytesLen;
	}  Y ;
	/* element: "http://www.w3.org/2000/09/xmldsig#":J, http://www.w3.org/2000/09/xmldsig#,CryptoBinary */
	struct {
		uint8_t bytes[v2gDSAKeyValueType_J_BYTES_SIZE];
		uint16_t bytesLen;
	}  J ;
	unsigned int J_isUsed:1;
	/* element: "http://www.w3.org/2000/09/xmldsig#":Seed, http://www.w3.org/2000/09/xmldsig#,CryptoBinary */
	struct {
		uint8_t bytes[v2gDSAKeyValueType_Seed_BYTES_SIZE];
		uint16_t bytesLen;
	}  Seed ;
	unsigned int Seed_isUsed:1;
	/* element: "http://www.w3.org/2000/09/xmldsig#":PgenCounter, http://www.w3.org/2000/09/xmldsig#,CryptoBinary */
	struct {
		uint8_t bytes[v2gDSAKeyValueType_PgenCounter_BYTES_SIZE];
		uint16_t bytesLen;
	}  PgenCounter ;
	unsigned int PgenCounter_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,PaymentDetailsResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":GenChallenge,"urn:iso:15118:2:2013:MsgBody":EVSETimeStamp)',  derivedBy='EXTENSION'.  */
#define v2gPaymentDetailsResType_GenChallenge_BYTES_SIZE 16 /* XML schema facet length for urn:iso:15118:2:2013:MsgDataTypes,genChallengeType is 16 */
struct v2gPaymentDetailsResType {
	/* element: "urn:iso:15118:2:2013:MsgBody":ResponseCode, urn:iso:15118:2:2013:MsgDataTypes,responseCodeType */
	v2gresponseCodeType ResponseCode ;
	/* element: "urn:iso:15118:2:2013:MsgBody":GenChallenge, urn:iso:15118:2:2013:MsgDataTypes,genChallengeType */
	struct {
		uint8_t bytes[v2gPaymentDetailsResType_GenChallenge_BYTES_SIZE];
		uint16_t bytesLen;
	}  GenChallenge ;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVSETimeStamp, http://www.w3.org/2001/XMLSchema,long */
	int64_t EVSETimeStamp ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,CertificateInstallationReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":OEMProvisioningCert,"urn:iso:15118:2:2013:MsgBody":ListOfRootCertificateIDs)',  derivedBy='EXTENSION'.  */
#define v2gCertificateInstallationReqType_Id_CHARACTERS_SIZE 50
#define v2gCertificateInstallationReqType_OEMProvisioningCert_BYTES_SIZE 800 /* XML schema facet maxLength for urn:iso:15118:2:2013:MsgDataTypes,certificateType is 800 */
struct v2gCertificateInstallationReqType {
	/* attribute: Id {http://www.w3.org/2001/XMLSchema,ID} */
	struct {
		exi_string_character_t characters[v2gCertificateInstallationReqType_Id_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Id ;
	/* element: "urn:iso:15118:2:2013:MsgBody":OEMProvisioningCert, urn:iso:15118:2:2013:MsgDataTypes,certificateType */
	struct {
		uint8_t bytes[v2gCertificateInstallationReqType_OEMProvisioningCert_BYTES_SIZE];
		uint16_t bytesLen;
	}  OEMProvisioningCert ;
	/* element: "urn:iso:15118:2:2013:MsgBody":ListOfRootCertificateIDs, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ListOfRootCertificateIDsType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":RootCertificateID{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
	struct v2gListOfRootCertificateIDsType ListOfRootCertificateIDs ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EVStatusType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
struct v2gEVStatusType {
	int noContent; /* avoid warning */
};

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,DigestMethodType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='((WC[##other:"http://www.w3.org/2000/09/xmldsig#"]){0-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
#define v2gDigestMethodType_Algorithm_CHARACTERS_SIZE 50
struct v2gDigestMethodType {
	/* attribute: Algorithm {http://www.w3.org/2001/XMLSchema,anyURI} */
	struct {
		exi_string_character_t characters[v2gDigestMethodType_Algorithm_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Algorithm ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,CostType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":costKind,"urn:iso:15118:2:2013:MsgDataTypes":amount,"urn:iso:15118:2:2013:MsgDataTypes":amountMultiplier{0-1})',  derivedBy='RESTRICTION'.  */
struct v2gCostType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":costKind, urn:iso:15118:2:2013:MsgDataTypes,costKindType */
	v2gcostKindType costKind ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":amount, http://www.w3.org/2001/XMLSchema,unsignedInt */
	uint32_t amount ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":amountMultiplier, urn:iso:15118:2:2013:MsgDataTypes,unitMultiplierType */
	int8_t amountMultiplier ;
	unsigned int amountMultiplier_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,ServiceDetailReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ServiceID)',  derivedBy='EXTENSION'.  */
struct v2gServiceDetailReqType {
	/* element: "urn:iso:15118:2:2013:MsgBody":ServiceID, urn:iso:15118:2:2013:MsgDataTypes,serviceIDType */
	uint16_t ServiceID ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,AC_EVChargeParameterType',  base type name='EVChargeParameterType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":DepartureTime{0-1}),("urn:iso:15118:2:2013:MsgDataTypes":EAmount,"urn:iso:15118:2:2013:MsgDataTypes":EVMaxVoltage,"urn:iso:15118:2:2013:MsgDataTypes":EVMaxCurrent,"urn:iso:15118:2:2013:MsgDataTypes":EVMinCurrent))',  derivedBy='EXTENSION'.  */
struct v2gAC_EVChargeParameterType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":DepartureTime, http://www.w3.org/2001/XMLSchema,unsignedInt */
	uint32_t DepartureTime ;
	unsigned int DepartureTime_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EAmount, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EAmount ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVMaxVoltage, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVMaxVoltage ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVMaxCurrent, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVMaxCurrent ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVMinCurrent, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVMinCurrent ;
};

typedef enum {
	v2gDC_EVSEStatusCodeType_EVSE_NotReady = 0,
	v2gDC_EVSEStatusCodeType_EVSE_Ready = 1,
	v2gDC_EVSEStatusCodeType_EVSE_Shutdown = 2,
	v2gDC_EVSEStatusCodeType_EVSE_UtilityInterruptEvent = 3,
	v2gDC_EVSEStatusCodeType_EVSE_IsolationMonitoringActive = 4,
	v2gDC_EVSEStatusCodeType_EVSE_EmergencyShutdown = 5,
	v2gDC_EVSEStatusCodeType_EVSE_Malfunction = 6,
	v2gDC_EVSEStatusCodeType_Reserved_8 = 7,
	v2gDC_EVSEStatusCodeType_Reserved_9 = 8,
	v2gDC_EVSEStatusCodeType_Reserved_A = 9,
	v2gDC_EVSEStatusCodeType_Reserved_B = 10,
	v2gDC_EVSEStatusCodeType_Reserved_C = 11
} v2gDC_EVSEStatusCodeType;

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PMaxScheduleEntryType',  base type name='EntryType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":TimeInterval),("urn:iso:15118:2:2013:MsgDataTypes":PMax))',  derivedBy='EXTENSION'.  */
struct v2gPMaxScheduleEntryType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":TimeInterval, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,IntervalType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
	struct v2gIntervalType TimeInterval ;
	unsigned int TimeInterval_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":RelativeTimeInterval, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,RelativeTimeIntervalType',  base type name='IntervalType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":start,"urn:iso:15118:2:2013:MsgDataTypes":duration{0-1})',  derivedBy='EXTENSION'.  */
	struct v2gRelativeTimeIntervalType RelativeTimeInterval ;
	unsigned int RelativeTimeInterval_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":PMax, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType PMax ;
};

typedef enum {
	v2gpaymentOptionType_Contract = 0,
	v2gpaymentOptionType_ExternalPayment = 1
} v2gpaymentOptionType;

typedef enum {
	v2gfaultCodeType_ParsingError = 0,
	v2gfaultCodeType_NoTLSRootCertificatAvailable = 1,
	v2gfaultCodeType_UnknownError = 2
} v2gfaultCodeType;

/* Complex type name='urn:iso:15118:2:2013:MsgBody,BodyBaseType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
struct v2gBodyBaseType {
	int noContent; /* avoid warning */
};

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,TransformType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='((WC[##other:"http://www.w3.org/2000/09/xmldsig#"])|"http://www.w3.org/2000/09/xmldsig#":XPath){0-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
#define v2gTransformType_Algorithm_CHARACTERS_SIZE 50
#define v2gTransformType_XPath_CHARACTERS_SIZE 50
#define v2gTransformType_XPath_ARRAY_SIZE 1
struct v2gTransformType {
	/* attribute: Algorithm {http://www.w3.org/2001/XMLSchema,anyURI} */
	struct {
		exi_string_character_t characters[v2gTransformType_Algorithm_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Algorithm ;
	/* element: "http://www.w3.org/2000/09/xmldsig#":XPath, http://www.w3.org/2001/XMLSchema,string */
	struct {
		struct {
			exi_string_character_t characters[v2gTransformType_XPath_CHARACTERS_SIZE];
			uint16_t charactersLen;
		}  array[v2gTransformType_XPath_ARRAY_SIZE];
		uint16_t arrayLen;
	} XPath;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DiffieHellmanPublickeyType',  base type name='dHpublickeyType',  content type='SIMPLE',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  derivedBy='EXTENSION'.  */
#define v2gDiffieHellmanPublickeyType_Id_CHARACTERS_SIZE 50
#define v2gDiffieHellmanPublickeyType_CONTENT_BYTES_SIZE 350
struct v2gDiffieHellmanPublickeyType {
	/* attribute: Id {http://www.w3.org/2001/XMLSchema,ID} */
	struct {
		exi_string_character_t characters[v2gDiffieHellmanPublickeyType_Id_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Id ;
	/* simple content: urn:iso:15118:2:2013:MsgDataTypes,dHpublickeyType */
	struct {
		uint8_t bytes[v2gDiffieHellmanPublickeyType_CONTENT_BYTES_SIZE];
		uint16_t bytesLen;
	}  CONTENT ;
};

typedef enum {
	v2gserviceCategoryType_EVCharging = 0,
	v2gserviceCategoryType_Internet = 1,
	v2gserviceCategoryType_ContractCertificate = 2,
	v2gserviceCategoryType_OtherCustom = 3
} v2gserviceCategoryType;

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ProfileEntryType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":ChargingProfileEntryStart,"urn:iso:15118:2:2013:MsgDataTypes":ChargingProfileEntryMaxPower,"urn:iso:15118:2:2013:MsgDataTypes":ChargingProfileEntryMaxNumberOfPhasesInUse{0-1})',  derivedBy='RESTRICTION'.  */
struct v2gProfileEntryType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":ChargingProfileEntryStart, http://www.w3.org/2001/XMLSchema,unsignedInt */
	uint32_t ChargingProfileEntryStart ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":ChargingProfileEntryMaxPower, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType ChargingProfileEntryMaxPower ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":ChargingProfileEntryMaxNumberOfPhasesInUse, urn:iso:15118:2:2013:MsgDataTypes,maxNumPhasesType */
	int8_t ChargingProfileEntryMaxNumberOfPhasesInUse ;
	unsigned int ChargingProfileEntryMaxNumberOfPhasesInUse_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,ServiceDiscoveryReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ServiceScope{0-1},"urn:iso:15118:2:2013:MsgBody":ServiceCategory{0-1})',  derivedBy='EXTENSION'.  */
#define v2gServiceDiscoveryReqType_ServiceScope_CHARACTERS_SIZE 64 /* XML schema facet maxLength for urn:iso:15118:2:2013:MsgDataTypes,serviceScopeType is 64 */
struct v2gServiceDiscoveryReqType {
	/* element: "urn:iso:15118:2:2013:MsgBody":ServiceScope, urn:iso:15118:2:2013:MsgDataTypes,serviceScopeType */
	struct {
		exi_string_character_t characters[v2gServiceDiscoveryReqType_ServiceScope_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  ServiceScope ;
	unsigned int ServiceScope_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgBody":ServiceCategory, urn:iso:15118:2:2013:MsgDataTypes,serviceCategoryType */
	v2gserviceCategoryType ServiceCategory ;
	unsigned int ServiceCategory_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,NotificationType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":FaultCode,"urn:iso:15118:2:2013:MsgDataTypes":FaultMsg{0-1})',  derivedBy='RESTRICTION'.  */
#define v2gNotificationType_FaultMsg_CHARACTERS_SIZE 64 /* XML schema facet maxLength for urn:iso:15118:2:2013:MsgDataTypes,faultMsgType is 64 */
struct v2gNotificationType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":FaultCode, urn:iso:15118:2:2013:MsgDataTypes,faultCodeType */
	v2gfaultCodeType FaultCode ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":FaultMsg, urn:iso:15118:2:2013:MsgDataTypes,faultMsgType */
	struct {
		exi_string_character_t characters[v2gNotificationType_FaultMsg_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  FaultMsg ;
	unsigned int FaultMsg_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,AC_EVSEChargeParameterType',  base type name='EVSEChargeParameterType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":AC_EVSEStatus,"urn:iso:15118:2:2013:MsgDataTypes":EVSENominalVoltage,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMaxCurrent)',  derivedBy='EXTENSION'.  */
struct v2gAC_EVSEChargeParameterType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":AC_EVSEStatus, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,AC_EVSEStatusType',  base type name='EVSEStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification),("urn:iso:15118:2:2013:MsgDataTypes":RCD))',  derivedBy='EXTENSION'.  */
	struct v2gAC_EVSEStatusType AC_EVSEStatus ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVSENominalVoltage, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVSENominalVoltage ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVSEMaxCurrent, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVSEMaxCurrent ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,ChargingStatusResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":EVSEID,"urn:iso:15118:2:2013:MsgBody":SAScheduleTupleID,"urn:iso:15118:2:2013:MsgBody":EVSEMaxCurrent{0-1},"urn:iso:15118:2:2013:MsgBody":MeterInfo{0-1},"urn:iso:15118:2:2013:MsgBody":ReceiptRequired{0-1},"urn:iso:15118:2:2013:MsgBody":AC_EVSEStatus)',  derivedBy='EXTENSION'.  */
#define v2gChargingStatusResType_EVSEID_CHARACTERS_SIZE 37 /* XML schema facet maxLength for urn:iso:15118:2:2013:MsgDataTypes,evseIDType is 37 */
struct v2gChargingStatusResType {
	/* element: "urn:iso:15118:2:2013:MsgBody":ResponseCode, urn:iso:15118:2:2013:MsgDataTypes,responseCodeType */
	v2gresponseCodeType ResponseCode ;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVSEID, urn:iso:15118:2:2013:MsgDataTypes,evseIDType */
	struct {
		exi_string_character_t characters[v2gChargingStatusResType_EVSEID_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  EVSEID ;
	/* element: "urn:iso:15118:2:2013:MsgBody":SAScheduleTupleID, urn:iso:15118:2:2013:MsgDataTypes,SAIDType */
	uint8_t SAScheduleTupleID ;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVSEMaxCurrent, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVSEMaxCurrent ;
	unsigned int EVSEMaxCurrent_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgBody":MeterInfo, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,MeterInfoType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":MeterID,"urn:iso:15118:2:2013:MsgDataTypes":MeterReading{0-1},"urn:iso:15118:2:2013:MsgDataTypes":SigMeterReading{0-1},"urn:iso:15118:2:2013:MsgDataTypes":MeterStatus{0-1},"urn:iso:15118:2:2013:MsgDataTypes":TMeter{0-1})',  derivedBy='RESTRICTION'.  */
	struct v2gMeterInfoType MeterInfo ;
	unsigned int MeterInfo_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgBody":ReceiptRequired, http://www.w3.org/2001/XMLSchema,boolean */
	int ReceiptRequired ;
	unsigned int ReceiptRequired_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgBody":AC_EVSEStatus, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,AC_EVSEStatusType',  base type name='EVSEStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification),("urn:iso:15118:2:2013:MsgDataTypes":RCD))',  derivedBy='EXTENSION'.  */
	struct v2gAC_EVSEStatusType AC_EVSEStatus ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EVSEStatusType',  base type name='anyType',  content type='ELEMENT',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification)',  derivedBy='RESTRICTION'.  */
struct v2gEVSEStatusType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay, http://www.w3.org/2001/XMLSchema,unsignedShort */
	uint16_t NotificationMaxDelay ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVSENotification, urn:iso:15118:2:2013:MsgDataTypes,EVSENotificationType */
	v2gEVSENotificationType EVSENotification ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,MeteringReceiptReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":SessionID,"urn:iso:15118:2:2013:MsgBody":SAScheduleTupleID{0-1},"urn:iso:15118:2:2013:MsgBody":MeterInfo)',  derivedBy='EXTENSION'.  */
#define v2gMeteringReceiptReqType_Id_CHARACTERS_SIZE 50
#define v2gMeteringReceiptReqType_SessionID_BYTES_SIZE 8 /* XML schema facet maxLength for urn:iso:15118:2:2013:MsgDataTypes,sessionIDType is 8 */
struct v2gMeteringReceiptReqType {
	/* attribute: Id {http://www.w3.org/2001/XMLSchema,ID} */
	struct {
		exi_string_character_t characters[v2gMeteringReceiptReqType_Id_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Id ;
	unsigned int Id_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgBody":SessionID, urn:iso:15118:2:2013:MsgDataTypes,sessionIDType */
	struct {
		uint8_t bytes[v2gMeteringReceiptReqType_SessionID_BYTES_SIZE];
		uint16_t bytesLen;
	}  SessionID ;
	/* element: "urn:iso:15118:2:2013:MsgBody":SAScheduleTupleID, urn:iso:15118:2:2013:MsgDataTypes,SAIDType */
	uint8_t SAScheduleTupleID ;
	unsigned int SAScheduleTupleID_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgBody":MeterInfo, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,MeterInfoType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":MeterID,"urn:iso:15118:2:2013:MsgDataTypes":MeterReading{0-1},"urn:iso:15118:2:2013:MsgDataTypes":SigMeterReading{0-1},"urn:iso:15118:2:2013:MsgDataTypes":MeterStatus{0-1},"urn:iso:15118:2:2013:MsgDataTypes":TMeter{0-1})',  derivedBy='RESTRICTION'.  */
	struct v2gMeterInfoType MeterInfo ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,CertificateChainType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Certificate,"urn:iso:15118:2:2013:MsgDataTypes":SubCertificates{0-1})',  derivedBy='RESTRICTION'.  */
#define v2gCertificateChainType_Id_CHARACTERS_SIZE 50
#define v2gCertificateChainType_Certificate_BYTES_SIZE 800 /* XML schema facet maxLength for urn:iso:15118:2:2013:MsgDataTypes,certificateType is 800 */
struct v2gCertificateChainType {
	/* attribute: Id {http://www.w3.org/2001/XMLSchema,ID} */
	struct {
		exi_string_character_t characters[v2gCertificateChainType_Id_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Id ;
	unsigned int Id_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":Certificate, urn:iso:15118:2:2013:MsgDataTypes,certificateType */
	struct {
		uint8_t bytes[v2gCertificateChainType_Certificate_BYTES_SIZE];
		uint16_t bytesLen;
	}  Certificate ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":SubCertificates, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SubCertificatesType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Certificate{1-4})',  derivedBy='RESTRICTION'.  */
	struct v2gSubCertificatesType SubCertificates ;
	unsigned int SubCertificates_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PMaxScheduleType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":PMaxScheduleEntry{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
#define v2gPMaxScheduleType_PMaxScheduleEntry_ARRAY_SIZE 5
struct v2gPMaxScheduleType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":PMaxScheduleEntry, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PMaxScheduleEntryType',  base type name='EntryType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":TimeInterval),("urn:iso:15118:2:2013:MsgDataTypes":PMax))',  derivedBy='EXTENSION'.  */
	struct {
		struct v2gPMaxScheduleEntryType array[v2gPMaxScheduleType_PMaxScheduleEntry_ARRAY_SIZE];
		uint16_t arrayLen;
	} PMaxScheduleEntry;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,SessionStopReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ChargingSession)',  derivedBy='EXTENSION'.  */
struct v2gSessionStopReqType {
	/* element: "urn:iso:15118:2:2013:MsgBody":ChargingSession, urn:iso:15118:2:2013:MsgDataTypes,chargingSessionType */
	v2gchargingSessionType ChargingSession ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ParameterType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":boolValue|"urn:iso:15118:2:2013:MsgDataTypes":byteValue|"urn:iso:15118:2:2013:MsgDataTypes":shortValue|"urn:iso:15118:2:2013:MsgDataTypes":intValue|"urn:iso:15118:2:2013:MsgDataTypes":physicalValue|"urn:iso:15118:2:2013:MsgDataTypes":stringValue)',  derivedBy='RESTRICTION'.  */
#define v2gParameterType_Name_CHARACTERS_SIZE 50
#define v2gParameterType_stringValue_CHARACTERS_SIZE 50
struct v2gParameterType {
	/* attribute: Name {http://www.w3.org/2001/XMLSchema,string} */
	struct {
		exi_string_character_t characters[v2gParameterType_Name_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Name ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":boolValue, http://www.w3.org/2001/XMLSchema,boolean */
	int boolValue ;
	unsigned int boolValue_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":byteValue, http://www.w3.org/2001/XMLSchema,byte */
	int8_t byteValue ;
	unsigned int byteValue_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":shortValue, http://www.w3.org/2001/XMLSchema,short */
	int16_t shortValue ;
	unsigned int shortValue_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":intValue, http://www.w3.org/2001/XMLSchema,int */
	int32_t intValue ;
	unsigned int intValue_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":physicalValue, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType physicalValue ;
	unsigned int physicalValue_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":stringValue, http://www.w3.org/2001/XMLSchema,string */
	struct {
		exi_string_character_t characters[v2gParameterType_stringValue_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  stringValue ;
	unsigned int stringValue_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ChargeServiceType',  base type name='ServiceType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":ServiceID,"urn:iso:15118:2:2013:MsgDataTypes":ServiceName{0-1},"urn:iso:15118:2:2013:MsgDataTypes":ServiceCategory,"urn:iso:15118:2:2013:MsgDataTypes":ServiceScope{0-1},"urn:iso:15118:2:2013:MsgDataTypes":FreeService),("urn:iso:15118:2:2013:MsgDataTypes":SupportedEnergyTransferMode))',  derivedBy='EXTENSION'.  */
#define v2gChargeServiceType_ServiceName_CHARACTERS_SIZE 32 /* XML schema facet maxLength for urn:iso:15118:2:2013:MsgDataTypes,serviceNameType is 32 */
#define v2gChargeServiceType_ServiceScope_CHARACTERS_SIZE 64 /* XML schema facet maxLength for urn:iso:15118:2:2013:MsgDataTypes,serviceScopeType is 64 */
struct v2gChargeServiceType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":ServiceID, urn:iso:15118:2:2013:MsgDataTypes,serviceIDType */
	uint16_t ServiceID ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":ServiceName, urn:iso:15118:2:2013:MsgDataTypes,serviceNameType */
	struct {
		exi_string_character_t characters[v2gChargeServiceType_ServiceName_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  ServiceName ;
	unsigned int ServiceName_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":ServiceCategory, urn:iso:15118:2:2013:MsgDataTypes,serviceCategoryType */
	v2gserviceCategoryType ServiceCategory ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":ServiceScope, urn:iso:15118:2:2013:MsgDataTypes,serviceScopeType */
	struct {
		exi_string_character_t characters[v2gChargeServiceType_ServiceScope_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  ServiceScope ;
	unsigned int ServiceScope_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":FreeService, http://www.w3.org/2001/XMLSchema,boolean */
	int FreeService ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":SupportedEnergyTransferMode, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SupportedEnergyTransferModeType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":EnergyTransferMode{1-6})',  derivedBy='RESTRICTION'.  */
	struct v2gSupportedEnergyTransferModeType SupportedEnergyTransferMode ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,PaymentServiceSelectionResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode)',  derivedBy='EXTENSION'.  */
struct v2gPaymentServiceSelectionResType {
	/* element: "urn:iso:15118:2:2013:MsgBody":ResponseCode, urn:iso:15118:2:2013:MsgDataTypes,responseCodeType */
	v2gresponseCodeType ResponseCode ;
};

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,KeyValueType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":DSAKeyValue|"http://www.w3.org/2000/09/xmldsig#":RSAKeyValue|(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]))',  derivedBy='RESTRICTION'.  */
struct v2gKeyValueType {
	/* element: "http://www.w3.org/2000/09/xmldsig#":DSAKeyValue, Complex type name='http://www.w3.org/2000/09/xmldsig#,DSAKeyValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("http://www.w3.org/2000/09/xmldsig#":P,"http://www.w3.org/2000/09/xmldsig#":Q){0-1},"http://www.w3.org/2000/09/xmldsig#":G{0-1},"http://www.w3.org/2000/09/xmldsig#":Y,"http://www.w3.org/2000/09/xmldsig#":J{0-1},("http://www.w3.org/2000/09/xmldsig#":Seed,"http://www.w3.org/2000/09/xmldsig#":PgenCounter){0-1})',  derivedBy='RESTRICTION'.  */
	struct v2gDSAKeyValueType DSAKeyValue ;
	unsigned int DSAKeyValue_isUsed:1;
	/* element: "http://www.w3.org/2000/09/xmldsig#":RSAKeyValue, Complex type name='http://www.w3.org/2000/09/xmldsig#,RSAKeyValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":Modulus,"http://www.w3.org/2000/09/xmldsig#":Exponent)',  derivedBy='RESTRICTION'.  */
	struct v2gRSAKeyValueType RSAKeyValue ;
	unsigned int RSAKeyValue_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,AuthorizationResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":EVSEProcessing)',  derivedBy='EXTENSION'.  */
struct v2gAuthorizationResType {
	/* element: "urn:iso:15118:2:2013:MsgBody":ResponseCode, urn:iso:15118:2:2013:MsgDataTypes,responseCodeType */
	v2gresponseCodeType ResponseCode ;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVSEProcessing, urn:iso:15118:2:2013:MsgDataTypes,EVSEProcessingType */
	v2gEVSEProcessingType EVSEProcessing ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,CertificateUpdateReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ContractSignatureCertChain,"urn:iso:15118:2:2013:MsgBody":eMAID,"urn:iso:15118:2:2013:MsgBody":ListOfRootCertificateIDs)',  derivedBy='EXTENSION'.  */
#define v2gCertificateUpdateReqType_Id_CHARACTERS_SIZE 50
#define v2gCertificateUpdateReqType_eMAID_CHARACTERS_SIZE 15 /* XML schema facet maxLength for urn:iso:15118:2:2013:MsgDataTypes,eMAIDType is 15 */
struct v2gCertificateUpdateReqType {
	/* attribute: Id {http://www.w3.org/2001/XMLSchema,ID} */
	struct {
		exi_string_character_t characters[v2gCertificateUpdateReqType_Id_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Id ;
	/* element: "urn:iso:15118:2:2013:MsgBody":ContractSignatureCertChain, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,CertificateChainType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Certificate,"urn:iso:15118:2:2013:MsgDataTypes":SubCertificates{0-1})',  derivedBy='RESTRICTION'.  */
	struct v2gCertificateChainType ContractSignatureCertChain ;
	/* element: "urn:iso:15118:2:2013:MsgBody":eMAID, urn:iso:15118:2:2013:MsgDataTypes,eMAIDType */
	struct {
		exi_string_character_t characters[v2gCertificateUpdateReqType_eMAID_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  eMAID ;
	/* element: "urn:iso:15118:2:2013:MsgBody":ListOfRootCertificateIDs, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ListOfRootCertificateIDsType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":RootCertificateID{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
	struct v2gListOfRootCertificateIDsType ListOfRootCertificateIDs ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PaymentOptionListType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":PaymentOption{1-2})',  derivedBy='RESTRICTION'.  */
#define v2gPaymentOptionListType_PaymentOption_ARRAY_SIZE 2
struct v2gPaymentOptionListType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":PaymentOption, urn:iso:15118:2:2013:MsgDataTypes,paymentOptionType */
	struct {
		v2gpaymentOptionType array[v2gPaymentOptionListType_PaymentOption_ARRAY_SIZE];
		uint16_t arrayLen;
	} PaymentOption;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,ChargeParameterDiscoveryReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":MaxEntriesSAScheduleTuple{0-1},"urn:iso:15118:2:2013:MsgBody":RequestedEnergyTransferMode,"urn:iso:15118:2:2013:MsgDataTypes":EVChargeParameter)',  derivedBy='EXTENSION'.  */
struct v2gChargeParameterDiscoveryReqType {
	/* element: "urn:iso:15118:2:2013:MsgBody":MaxEntriesSAScheduleTuple, http://www.w3.org/2001/XMLSchema,unsignedShort */
	uint16_t MaxEntriesSAScheduleTuple ;
	unsigned int MaxEntriesSAScheduleTuple_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgBody":RequestedEnergyTransferMode, urn:iso:15118:2:2013:MsgDataTypes,EnergyTransferModeType */
	v2gEnergyTransferModeType RequestedEnergyTransferMode ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVChargeParameter, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EVChargeParameterType',  base type name='anyType',  content type='ELEMENT',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":DepartureTime{0-1})',  derivedBy='RESTRICTION'.  */
	struct v2gEVChargeParameterType EVChargeParameter ;
	unsigned int EVChargeParameter_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":AC_EVChargeParameter, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,AC_EVChargeParameterType',  base type name='EVChargeParameterType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":DepartureTime{0-1}),("urn:iso:15118:2:2013:MsgDataTypes":EAmount,"urn:iso:15118:2:2013:MsgDataTypes":EVMaxVoltage,"urn:iso:15118:2:2013:MsgDataTypes":EVMaxCurrent,"urn:iso:15118:2:2013:MsgDataTypes":EVMinCurrent))',  derivedBy='EXTENSION'.  */
	struct v2gAC_EVChargeParameterType AC_EVChargeParameter ;
	unsigned int AC_EVChargeParameter_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":DC_EVChargeParameter, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVChargeParameterType',  base type name='EVChargeParameterType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":DepartureTime{0-1}),("urn:iso:15118:2:2013:MsgDataTypes":DC_EVStatus,"urn:iso:15118:2:2013:MsgDataTypes":EVMaximumCurrentLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVMaximumPowerLimit{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVMaximumVoltageLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVEnergyCapacity{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVEnergyRequest{0-1},"urn:iso:15118:2:2013:MsgDataTypes":FullSOC{0-1},"urn:iso:15118:2:2013:MsgDataTypes":BulkSOC{0-1}))',  derivedBy='EXTENSION'.  */
	struct v2gDC_EVChargeParameterType DC_EVChargeParameter ;
	unsigned int DC_EVChargeParameter_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,CertificateInstallationResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":SAProvisioningCertificateChain,"urn:iso:15118:2:2013:MsgBody":ContractSignatureCertChain,"urn:iso:15118:2:2013:MsgBody":ContractSignatureEncryptedPrivateKey,"urn:iso:15118:2:2013:MsgBody":DHpublickey,"urn:iso:15118:2:2013:MsgBody":eMAID)',  derivedBy='EXTENSION'.  */
struct v2gCertificateInstallationResType {
	/* element: "urn:iso:15118:2:2013:MsgBody":ResponseCode, urn:iso:15118:2:2013:MsgDataTypes,responseCodeType */
	v2gresponseCodeType ResponseCode ;
	/* element: "urn:iso:15118:2:2013:MsgBody":SAProvisioningCertificateChain, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,CertificateChainType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Certificate,"urn:iso:15118:2:2013:MsgDataTypes":SubCertificates{0-1})',  derivedBy='RESTRICTION'.  */
	struct v2gCertificateChainType SAProvisioningCertificateChain ;
	/* element: "urn:iso:15118:2:2013:MsgBody":ContractSignatureCertChain, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,CertificateChainType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Certificate,"urn:iso:15118:2:2013:MsgDataTypes":SubCertificates{0-1})',  derivedBy='RESTRICTION'.  */
	struct v2gCertificateChainType ContractSignatureCertChain ;
	/* element: "urn:iso:15118:2:2013:MsgBody":ContractSignatureEncryptedPrivateKey, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ContractSignatureEncryptedPrivateKeyType',  base type name='privateKeyType',  content type='SIMPLE',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  derivedBy='EXTENSION'.  */
	struct v2gContractSignatureEncryptedPrivateKeyType ContractSignatureEncryptedPrivateKey ;
	/* element: "urn:iso:15118:2:2013:MsgBody":DHpublickey, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DiffieHellmanPublickeyType',  base type name='dHpublickeyType',  content type='SIMPLE',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  derivedBy='EXTENSION'.  */
	struct v2gDiffieHellmanPublickeyType DHpublickey ;
	/* element: "urn:iso:15118:2:2013:MsgBody":eMAID, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EMAIDType',  base type name='eMAIDType',  content type='SIMPLE',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  derivedBy='EXTENSION'.  */
	struct v2gEMAIDType eMAID ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,CurrentDemandReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":DC_EVStatus,"urn:iso:15118:2:2013:MsgBody":EVTargetCurrent,"urn:iso:15118:2:2013:MsgBody":EVMaximumVoltageLimit{0-1},"urn:iso:15118:2:2013:MsgBody":EVMaximumCurrentLimit{0-1},"urn:iso:15118:2:2013:MsgBody":EVMaximumPowerLimit{0-1},"urn:iso:15118:2:2013:MsgBody":BulkChargingComplete{0-1},"urn:iso:15118:2:2013:MsgBody":ChargingComplete,"urn:iso:15118:2:2013:MsgBody":RemainingTimeToFullSoC{0-1},"urn:iso:15118:2:2013:MsgBody":RemainingTimeToBulkSoC{0-1},"urn:iso:15118:2:2013:MsgBody":EVTargetVoltage)',  derivedBy='EXTENSION'.  */
struct v2gCurrentDemandReqType {
	/* element: "urn:iso:15118:2:2013:MsgBody":DC_EVStatus, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVStatusType',  base type name='EVStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":EVReady,"urn:iso:15118:2:2013:MsgDataTypes":EVErrorCode,"urn:iso:15118:2:2013:MsgDataTypes":EVRESSSOC)',  derivedBy='EXTENSION'.  */
	struct v2gDC_EVStatusType DC_EVStatus ;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVTargetCurrent, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVTargetCurrent ;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVMaximumVoltageLimit, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVMaximumVoltageLimit ;
	unsigned int EVMaximumVoltageLimit_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVMaximumCurrentLimit, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVMaximumCurrentLimit ;
	unsigned int EVMaximumCurrentLimit_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVMaximumPowerLimit, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVMaximumPowerLimit ;
	unsigned int EVMaximumPowerLimit_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgBody":BulkChargingComplete, http://www.w3.org/2001/XMLSchema,boolean */
	int BulkChargingComplete ;
	unsigned int BulkChargingComplete_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgBody":ChargingComplete, http://www.w3.org/2001/XMLSchema,boolean */
	int ChargingComplete ;
	/* element: "urn:iso:15118:2:2013:MsgBody":RemainingTimeToFullSoC, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType RemainingTimeToFullSoC ;
	unsigned int RemainingTimeToFullSoC_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgBody":RemainingTimeToBulkSoC, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType RemainingTimeToBulkSoC ;
	unsigned int RemainingTimeToBulkSoC_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVTargetVoltage, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVTargetVoltage ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ServiceType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":ServiceID,"urn:iso:15118:2:2013:MsgDataTypes":ServiceName{0-1},"urn:iso:15118:2:2013:MsgDataTypes":ServiceCategory,"urn:iso:15118:2:2013:MsgDataTypes":ServiceScope{0-1},"urn:iso:15118:2:2013:MsgDataTypes":FreeService)',  derivedBy='RESTRICTION'.  */
#define v2gServiceType_ServiceName_CHARACTERS_SIZE 32 /* XML schema facet maxLength for urn:iso:15118:2:2013:MsgDataTypes,serviceNameType is 32 */
#define v2gServiceType_ServiceScope_CHARACTERS_SIZE 64 /* XML schema facet maxLength for urn:iso:15118:2:2013:MsgDataTypes,serviceScopeType is 64 */
struct v2gServiceType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":ServiceID, urn:iso:15118:2:2013:MsgDataTypes,serviceIDType */
	uint16_t ServiceID ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":ServiceName, urn:iso:15118:2:2013:MsgDataTypes,serviceNameType */
	struct {
		exi_string_character_t characters[v2gServiceType_ServiceName_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  ServiceName ;
	unsigned int ServiceName_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":ServiceCategory, urn:iso:15118:2:2013:MsgDataTypes,serviceCategoryType */
	v2gserviceCategoryType ServiceCategory ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":ServiceScope, urn:iso:15118:2:2013:MsgDataTypes,serviceScopeType */
	struct {
		exi_string_character_t characters[v2gServiceType_ServiceScope_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  ServiceScope ;
	unsigned int ServiceScope_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":FreeService, http://www.w3.org/2001/XMLSchema,boolean */
	int FreeService ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ConsumptionCostType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":startValue,"urn:iso:15118:2:2013:MsgDataTypes":Cost{1-3})',  derivedBy='RESTRICTION'.  */
#define v2gConsumptionCostType_Cost_ARRAY_SIZE 3
struct v2gConsumptionCostType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":startValue, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType startValue ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":Cost, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,CostType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":costKind,"urn:iso:15118:2:2013:MsgDataTypes":amount,"urn:iso:15118:2:2013:MsgDataTypes":amountMultiplier{0-1})',  derivedBy='RESTRICTION'.  */
	struct {
		struct v2gCostType array[v2gConsumptionCostType_Cost_ARRAY_SIZE];
		uint16_t arrayLen;
	} Cost;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,PreChargeReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":DC_EVStatus,"urn:iso:15118:2:2013:MsgBody":EVTargetVoltage,"urn:iso:15118:2:2013:MsgBody":EVTargetCurrent)',  derivedBy='EXTENSION'.  */
struct v2gPreChargeReqType {
	/* element: "urn:iso:15118:2:2013:MsgBody":DC_EVStatus, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVStatusType',  base type name='EVStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":EVReady,"urn:iso:15118:2:2013:MsgDataTypes":EVErrorCode,"urn:iso:15118:2:2013:MsgDataTypes":EVRESSSOC)',  derivedBy='EXTENSION'.  */
	struct v2gDC_EVStatusType DC_EVStatus ;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVTargetVoltage, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVTargetVoltage ;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVTargetCurrent, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVTargetCurrent ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ServiceListType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Service{1-8})',  derivedBy='RESTRICTION'.  */
#define v2gServiceListType_Service_ARRAY_SIZE 5
struct v2gServiceListType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":Service, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ServiceType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":ServiceID,"urn:iso:15118:2:2013:MsgDataTypes":ServiceName{0-1},"urn:iso:15118:2:2013:MsgDataTypes":ServiceCategory,"urn:iso:15118:2:2013:MsgDataTypes":ServiceScope{0-1},"urn:iso:15118:2:2013:MsgDataTypes":FreeService)',  derivedBy='RESTRICTION'.  */
	struct {
		struct v2gServiceType array[v2gServiceListType_Service_ARRAY_SIZE];
		uint16_t arrayLen;
	} Service;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVSEStatusType',  base type name='EVSEStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification),("urn:iso:15118:2:2013:MsgDataTypes":EVSEIsolationStatus{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVSEStatusCode))',  derivedBy='EXTENSION'.  */
struct v2gDC_EVSEStatusType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay, http://www.w3.org/2001/XMLSchema,unsignedShort */
	uint16_t NotificationMaxDelay ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVSENotification, urn:iso:15118:2:2013:MsgDataTypes,EVSENotificationType */
	v2gEVSENotificationType EVSENotification ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVSEIsolationStatus, urn:iso:15118:2:2013:MsgDataTypes,isolationLevelType */
	v2gisolationLevelType EVSEIsolationStatus ;
	unsigned int EVSEIsolationStatus_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVSEStatusCode, urn:iso:15118:2:2013:MsgDataTypes,DC_EVSEStatusCodeType */
	v2gDC_EVSEStatusCodeType EVSEStatusCode ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,CurrentDemandResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":DC_EVSEStatus,"urn:iso:15118:2:2013:MsgBody":EVSEPresentVoltage,"urn:iso:15118:2:2013:MsgBody":EVSEPresentCurrent,"urn:iso:15118:2:2013:MsgBody":EVSECurrentLimitAchieved,"urn:iso:15118:2:2013:MsgBody":EVSEVoltageLimitAchieved,"urn:iso:15118:2:2013:MsgBody":EVSEPowerLimitAchieved,"urn:iso:15118:2:2013:MsgBody":EVSEMaximumVoltageLimit{0-1},"urn:iso:15118:2:2013:MsgBody":EVSEMaximumCurrentLimit{0-1},"urn:iso:15118:2:2013:MsgBody":EVSEMaximumPowerLimit{0-1},"urn:iso:15118:2:2013:MsgBody":EVSEID,"urn:iso:15118:2:2013:MsgBody":SAScheduleTupleID,"urn:iso:15118:2:2013:MsgBody":MeterInfo{0-1},"urn:iso:15118:2:2013:MsgBody":ReceiptRequired{0-1})',  derivedBy='EXTENSION'.  */
#define v2gCurrentDemandResType_EVSEID_CHARACTERS_SIZE 37 /* XML schema facet maxLength for urn:iso:15118:2:2013:MsgDataTypes,evseIDType is 37 */
struct v2gCurrentDemandResType {
	/* element: "urn:iso:15118:2:2013:MsgBody":ResponseCode, urn:iso:15118:2:2013:MsgDataTypes,responseCodeType */
	v2gresponseCodeType ResponseCode ;
	/* element: "urn:iso:15118:2:2013:MsgBody":DC_EVSEStatus, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVSEStatusType',  base type name='EVSEStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification),("urn:iso:15118:2:2013:MsgDataTypes":EVSEIsolationStatus{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVSEStatusCode))',  derivedBy='EXTENSION'.  */
	struct v2gDC_EVSEStatusType DC_EVSEStatus ;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVSEPresentVoltage, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVSEPresentVoltage ;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVSEPresentCurrent, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVSEPresentCurrent ;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVSECurrentLimitAchieved, http://www.w3.org/2001/XMLSchema,boolean */
	int EVSECurrentLimitAchieved ;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVSEVoltageLimitAchieved, http://www.w3.org/2001/XMLSchema,boolean */
	int EVSEVoltageLimitAchieved ;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVSEPowerLimitAchieved, http://www.w3.org/2001/XMLSchema,boolean */
	int EVSEPowerLimitAchieved ;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVSEMaximumVoltageLimit, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVSEMaximumVoltageLimit ;
	unsigned int EVSEMaximumVoltageLimit_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVSEMaximumCurrentLimit, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVSEMaximumCurrentLimit ;
	unsigned int EVSEMaximumCurrentLimit_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVSEMaximumPowerLimit, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVSEMaximumPowerLimit ;
	unsigned int EVSEMaximumPowerLimit_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVSEID, urn:iso:15118:2:2013:MsgDataTypes,evseIDType */
	struct {
		exi_string_character_t characters[v2gCurrentDemandResType_EVSEID_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  EVSEID ;
	/* element: "urn:iso:15118:2:2013:MsgBody":SAScheduleTupleID, urn:iso:15118:2:2013:MsgDataTypes,SAIDType */
	uint8_t SAScheduleTupleID ;
	/* element: "urn:iso:15118:2:2013:MsgBody":MeterInfo, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,MeterInfoType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":MeterID,"urn:iso:15118:2:2013:MsgDataTypes":MeterReading{0-1},"urn:iso:15118:2:2013:MsgDataTypes":SigMeterReading{0-1},"urn:iso:15118:2:2013:MsgDataTypes":MeterStatus{0-1},"urn:iso:15118:2:2013:MsgDataTypes":TMeter{0-1})',  derivedBy='RESTRICTION'.  */
	struct v2gMeterInfoType MeterInfo ;
	unsigned int MeterInfo_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgBody":ReceiptRequired, http://www.w3.org/2001/XMLSchema,boolean */
	int ReceiptRequired ;
	unsigned int ReceiptRequired_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,PowerDeliveryResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgDataTypes":EVSEStatus)',  derivedBy='EXTENSION'.  */
struct v2gPowerDeliveryResType {
	/* element: "urn:iso:15118:2:2013:MsgBody":ResponseCode, urn:iso:15118:2:2013:MsgDataTypes,responseCodeType */
	v2gresponseCodeType ResponseCode ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVSEStatus, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EVSEStatusType',  base type name='anyType',  content type='ELEMENT',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification)',  derivedBy='RESTRICTION'.  */
	struct v2gEVSEStatusType EVSEStatus ;
	unsigned int EVSEStatus_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":AC_EVSEStatus, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,AC_EVSEStatusType',  base type name='EVSEStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification),("urn:iso:15118:2:2013:MsgDataTypes":RCD))',  derivedBy='EXTENSION'.  */
	struct v2gAC_EVSEStatusType AC_EVSEStatus ;
	unsigned int AC_EVSEStatus_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":DC_EVSEStatus, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVSEStatusType',  base type name='EVSEStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification),("urn:iso:15118:2:2013:MsgDataTypes":EVSEIsolationStatus{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVSEStatusCode))',  derivedBy='EXTENSION'.  */
	struct v2gDC_EVSEStatusType DC_EVSEStatus ;
	unsigned int DC_EVSEStatus_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ChargingProfileType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":ProfileEntry{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
#define v2gChargingProfileType_ProfileEntry_ARRAY_SIZE 5
struct v2gChargingProfileType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":ProfileEntry, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ProfileEntryType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":ChargingProfileEntryStart,"urn:iso:15118:2:2013:MsgDataTypes":ChargingProfileEntryMaxPower,"urn:iso:15118:2:2013:MsgDataTypes":ChargingProfileEntryMaxNumberOfPhasesInUse{0-1})',  derivedBy='RESTRICTION'.  */
	struct {
		struct v2gProfileEntryType array[v2gChargingProfileType_ProfileEntry_ARRAY_SIZE];
		uint16_t arrayLen;
	} ProfileEntry;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EntryType',  base type name='anyType',  content type='ELEMENT',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":TimeInterval)',  derivedBy='RESTRICTION'.  */
struct v2gEntryType {
	/* substitutionGroup */
#if SAVE_MEMORY_WITH_UNNAMED_UNION == UNION_YES
	union {
#endif /* SAVE_MEMORY_WITH_UNNAMED_UNION == UNION_YES */
		/* element: "urn:iso:15118:2:2013:MsgDataTypes":TimeInterval, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,IntervalType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
		struct v2gIntervalType TimeInterval ;
		/* element: "urn:iso:15118:2:2013:MsgDataTypes":RelativeTimeInterval, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,RelativeTimeIntervalType',  base type name='IntervalType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":start,"urn:iso:15118:2:2013:MsgDataTypes":duration{0-1})',  derivedBy='EXTENSION'.  */
		struct v2gRelativeTimeIntervalType RelativeTimeInterval ;
#if SAVE_MEMORY_WITH_UNNAMED_UNION == UNION_YES
	};
#endif /* SAVE_MEMORY_WITH_UNNAMED_UNION == UNION_YES */
		unsigned int TimeInterval_isUsed:1;
		unsigned int RelativeTimeInterval_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,CableCheckResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":DC_EVSEStatus,"urn:iso:15118:2:2013:MsgBody":EVSEProcessing)',  derivedBy='EXTENSION'.  */
struct v2gCableCheckResType {
	/* element: "urn:iso:15118:2:2013:MsgBody":ResponseCode, urn:iso:15118:2:2013:MsgDataTypes,responseCodeType */
	v2gresponseCodeType ResponseCode ;
	/* element: "urn:iso:15118:2:2013:MsgBody":DC_EVSEStatus, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVSEStatusType',  base type name='EVSEStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification),("urn:iso:15118:2:2013:MsgDataTypes":EVSEIsolationStatus{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVSEStatusCode))',  derivedBy='EXTENSION'.  */
	struct v2gDC_EVSEStatusType DC_EVSEStatus ;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVSEProcessing, urn:iso:15118:2:2013:MsgDataTypes,EVSEProcessingType */
	v2gEVSEProcessingType EVSEProcessing ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ParameterSetType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":ParameterSetID,"urn:iso:15118:2:2013:MsgDataTypes":Parameter{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
#define v2gParameterSetType_Parameter_ARRAY_SIZE 5
struct v2gParameterSetType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":ParameterSetID, http://www.w3.org/2001/XMLSchema,short */
	int16_t ParameterSetID ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":Parameter, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ParameterType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":boolValue|"urn:iso:15118:2:2013:MsgDataTypes":byteValue|"urn:iso:15118:2:2013:MsgDataTypes":shortValue|"urn:iso:15118:2:2013:MsgDataTypes":intValue|"urn:iso:15118:2:2013:MsgDataTypes":physicalValue|"urn:iso:15118:2:2013:MsgDataTypes":stringValue)',  derivedBy='RESTRICTION'.  */
	struct {
		struct v2gParameterType array[v2gParameterSetType_Parameter_ARRAY_SIZE];
		uint16_t arrayLen;
	} Parameter;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,PaymentDetailsReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":eMAID,"urn:iso:15118:2:2013:MsgBody":ContractSignatureCertChain)',  derivedBy='EXTENSION'.  */
#define v2gPaymentDetailsReqType_eMAID_CHARACTERS_SIZE 15 /* XML schema facet maxLength for urn:iso:15118:2:2013:MsgDataTypes,eMAIDType is 15 */
struct v2gPaymentDetailsReqType {
	/* element: "urn:iso:15118:2:2013:MsgBody":eMAID, urn:iso:15118:2:2013:MsgDataTypes,eMAIDType */
	struct {
		exi_string_character_t characters[v2gPaymentDetailsReqType_eMAID_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  eMAID ;
	/* element: "urn:iso:15118:2:2013:MsgBody":ContractSignatureCertChain, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,CertificateChainType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Certificate,"urn:iso:15118:2:2013:MsgDataTypes":SubCertificates{0-1})',  derivedBy='RESTRICTION'.  */
	struct v2gCertificateChainType ContractSignatureCertChain ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,PaymentServiceSelectionReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":SelectedPaymentOption,"urn:iso:15118:2:2013:MsgBody":SelectedServiceList)',  derivedBy='EXTENSION'.  */
struct v2gPaymentServiceSelectionReqType {
	/* element: "urn:iso:15118:2:2013:MsgBody":SelectedPaymentOption, urn:iso:15118:2:2013:MsgDataTypes,paymentOptionType */
	v2gpaymentOptionType SelectedPaymentOption ;
	/* element: "urn:iso:15118:2:2013:MsgBody":SelectedServiceList, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SelectedServiceListType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":SelectedService{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
	struct v2gSelectedServiceListType SelectedServiceList ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,CertificateUpdateResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":SAProvisioningCertificateChain,"urn:iso:15118:2:2013:MsgBody":ContractSignatureCertChain,"urn:iso:15118:2:2013:MsgBody":ContractSignatureEncryptedPrivateKey,"urn:iso:15118:2:2013:MsgBody":DHpublickey,"urn:iso:15118:2:2013:MsgBody":eMAID,"urn:iso:15118:2:2013:MsgBody":RetryCounter{0-1})',  derivedBy='EXTENSION'.  */
struct v2gCertificateUpdateResType {
	/* element: "urn:iso:15118:2:2013:MsgBody":ResponseCode, urn:iso:15118:2:2013:MsgDataTypes,responseCodeType */
	v2gresponseCodeType ResponseCode ;
	/* element: "urn:iso:15118:2:2013:MsgBody":SAProvisioningCertificateChain, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,CertificateChainType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Certificate,"urn:iso:15118:2:2013:MsgDataTypes":SubCertificates{0-1})',  derivedBy='RESTRICTION'.  */
	struct v2gCertificateChainType SAProvisioningCertificateChain ;
	/* element: "urn:iso:15118:2:2013:MsgBody":ContractSignatureCertChain, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,CertificateChainType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Certificate,"urn:iso:15118:2:2013:MsgDataTypes":SubCertificates{0-1})',  derivedBy='RESTRICTION'.  */
	struct v2gCertificateChainType ContractSignatureCertChain ;
	/* element: "urn:iso:15118:2:2013:MsgBody":ContractSignatureEncryptedPrivateKey, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ContractSignatureEncryptedPrivateKeyType',  base type name='privateKeyType',  content type='SIMPLE',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  derivedBy='EXTENSION'.  */
	struct v2gContractSignatureEncryptedPrivateKeyType ContractSignatureEncryptedPrivateKey ;
	/* element: "urn:iso:15118:2:2013:MsgBody":DHpublickey, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DiffieHellmanPublickeyType',  base type name='dHpublickeyType',  content type='SIMPLE',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  derivedBy='EXTENSION'.  */
	struct v2gDiffieHellmanPublickeyType DHpublickey ;
	/* element: "urn:iso:15118:2:2013:MsgBody":eMAID, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EMAIDType',  base type name='eMAIDType',  content type='SIMPLE',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  derivedBy='EXTENSION'.  */
	struct v2gEMAIDType eMAID ;
	/* element: "urn:iso:15118:2:2013:MsgBody":RetryCounter, http://www.w3.org/2001/XMLSchema,short */
	int16_t RetryCounter ;
	unsigned int RetryCounter_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ServiceParameterListType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":ParameterSet{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
#define v2gServiceParameterListType_ParameterSet_ARRAY_SIZE 5
struct v2gServiceParameterListType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":ParameterSet, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ParameterSetType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":ParameterSetID,"urn:iso:15118:2:2013:MsgDataTypes":Parameter{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
	struct {
		struct v2gParameterSetType array[v2gServiceParameterListType_ParameterSet_ARRAY_SIZE];
		uint16_t arrayLen;
	} ParameterSet;
};

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,TransformsType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":Transform{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
#define v2gTransformsType_Transform_ARRAY_SIZE 1
struct v2gTransformsType {
	/* element: "http://www.w3.org/2000/09/xmldsig#":Transform, Complex type name='http://www.w3.org/2000/09/xmldsig#,TransformType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='((WC[##other:"http://www.w3.org/2000/09/xmldsig#"])|"http://www.w3.org/2000/09/xmldsig#":XPath){0-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
	struct {
		struct v2gTransformType array[v2gTransformsType_Transform_ARRAY_SIZE];
		uint16_t arrayLen;
	} Transform;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,WeldingDetectionResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":DC_EVSEStatus,"urn:iso:15118:2:2013:MsgBody":EVSEPresentVoltage)',  derivedBy='EXTENSION'.  */
struct v2gWeldingDetectionResType {
	/* element: "urn:iso:15118:2:2013:MsgBody":ResponseCode, urn:iso:15118:2:2013:MsgDataTypes,responseCodeType */
	v2gresponseCodeType ResponseCode ;
	/* element: "urn:iso:15118:2:2013:MsgBody":DC_EVSEStatus, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVSEStatusType',  base type name='EVSEStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification),("urn:iso:15118:2:2013:MsgDataTypes":EVSEIsolationStatus{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVSEStatusCode))',  derivedBy='EXTENSION'.  */
	struct v2gDC_EVSEStatusType DC_EVSEStatus ;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVSEPresentVoltage, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVSEPresentVoltage ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,PreChargeResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":DC_EVSEStatus,"urn:iso:15118:2:2013:MsgBody":EVSEPresentVoltage)',  derivedBy='EXTENSION'.  */
struct v2gPreChargeResType {
	/* element: "urn:iso:15118:2:2013:MsgBody":ResponseCode, urn:iso:15118:2:2013:MsgDataTypes,responseCodeType */
	v2gresponseCodeType ResponseCode ;
	/* element: "urn:iso:15118:2:2013:MsgBody":DC_EVSEStatus, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVSEStatusType',  base type name='EVSEStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification),("urn:iso:15118:2:2013:MsgDataTypes":EVSEIsolationStatus{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVSEStatusCode))',  derivedBy='EXTENSION'.  */
	struct v2gDC_EVSEStatusType DC_EVSEStatus ;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVSEPresentVoltage, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVSEPresentVoltage ;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SalesTariffEntryType',  base type name='EntryType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":TimeInterval),("urn:iso:15118:2:2013:MsgDataTypes":EPriceLevel{0-1},"urn:iso:15118:2:2013:MsgDataTypes":ConsumptionCost{0-3}))',  derivedBy='EXTENSION'.  */
#define v2gSalesTariffEntryType_ConsumptionCost_ARRAY_SIZE 3
struct v2gSalesTariffEntryType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":TimeInterval, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,IntervalType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
	struct v2gIntervalType TimeInterval ;
	unsigned int TimeInterval_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":RelativeTimeInterval, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,RelativeTimeIntervalType',  base type name='IntervalType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":start,"urn:iso:15118:2:2013:MsgDataTypes":duration{0-1})',  derivedBy='EXTENSION'.  */
	struct v2gRelativeTimeIntervalType RelativeTimeInterval ;
	unsigned int RelativeTimeInterval_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EPriceLevel, http://www.w3.org/2001/XMLSchema,unsignedByte */
	uint8_t EPriceLevel ;
	unsigned int EPriceLevel_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":ConsumptionCost, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ConsumptionCostType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":startValue,"urn:iso:15118:2:2013:MsgDataTypes":Cost{1-3})',  derivedBy='RESTRICTION'.  */
	struct {
		struct v2gConsumptionCostType array[v2gSalesTariffEntryType_ConsumptionCost_ARRAY_SIZE];
		uint16_t arrayLen;
	} ConsumptionCost;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SalesTariffType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":SalesTariffID,"urn:iso:15118:2:2013:MsgDataTypes":SalesTariffDescription{0-1},"urn:iso:15118:2:2013:MsgDataTypes":NumEPriceLevels{0-1},"urn:iso:15118:2:2013:MsgDataTypes":SalesTariffEntry{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
#define v2gSalesTariffType_Id_CHARACTERS_SIZE 50
#define v2gSalesTariffType_SalesTariffDescription_CHARACTERS_SIZE 32 /* XML schema facet maxLength for urn:iso:15118:2:2013:MsgDataTypes,tariffDescriptionType is 32 */
#define v2gSalesTariffType_SalesTariffEntry_ARRAY_SIZE 5
struct v2gSalesTariffType {
	/* attribute: Id {http://www.w3.org/2001/XMLSchema,ID} */
	struct {
		exi_string_character_t characters[v2gSalesTariffType_Id_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Id ;
	unsigned int Id_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":SalesTariffID, urn:iso:15118:2:2013:MsgDataTypes,SAIDType */
	uint8_t SalesTariffID ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":SalesTariffDescription, urn:iso:15118:2:2013:MsgDataTypes,tariffDescriptionType */
	struct {
		exi_string_character_t characters[v2gSalesTariffType_SalesTariffDescription_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  SalesTariffDescription ;
	unsigned int SalesTariffDescription_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":NumEPriceLevels, http://www.w3.org/2001/XMLSchema,unsignedByte */
	uint8_t NumEPriceLevels ;
	unsigned int NumEPriceLevels_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":SalesTariffEntry, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SalesTariffEntryType',  base type name='EntryType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":TimeInterval),("urn:iso:15118:2:2013:MsgDataTypes":EPriceLevel{0-1},"urn:iso:15118:2:2013:MsgDataTypes":ConsumptionCost{0-3}))',  derivedBy='EXTENSION'.  */
	struct {
		struct v2gSalesTariffEntryType array[v2gSalesTariffType_SalesTariffEntry_ARRAY_SIZE];
		uint16_t arrayLen;
	} SalesTariffEntry;
};

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,ReferenceType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":Transforms{0-1},"http://www.w3.org/2000/09/xmldsig#":DigestMethod,"http://www.w3.org/2000/09/xmldsig#":DigestValue)',  derivedBy='RESTRICTION'.  */
#define v2gReferenceType_Id_CHARACTERS_SIZE 50
#define v2gReferenceType_URI_CHARACTERS_SIZE 50
#define v2gReferenceType_Type_CHARACTERS_SIZE 50
#define v2gReferenceType_DigestValue_BYTES_SIZE 350
struct v2gReferenceType {
	/* attribute: Id {http://www.w3.org/2001/XMLSchema,ID} */
	struct {
		exi_string_character_t characters[v2gReferenceType_Id_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Id ;
	unsigned int Id_isUsed:1;
	/* attribute: URI {http://www.w3.org/2001/XMLSchema,anyURI} */
	struct {
		exi_string_character_t characters[v2gReferenceType_URI_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  URI ;
	unsigned int URI_isUsed:1;
	/* attribute: Type {http://www.w3.org/2001/XMLSchema,anyURI} */
	struct {
		exi_string_character_t characters[v2gReferenceType_Type_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Type ;
	unsigned int Type_isUsed:1;
	/* element: "http://www.w3.org/2000/09/xmldsig#":Transforms, Complex type name='http://www.w3.org/2000/09/xmldsig#,TransformsType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":Transform{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
	struct v2gTransformsType Transforms ;
	unsigned int Transforms_isUsed:1;
	/* element: "http://www.w3.org/2000/09/xmldsig#":DigestMethod, Complex type name='http://www.w3.org/2000/09/xmldsig#,DigestMethodType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='((WC[##other:"http://www.w3.org/2000/09/xmldsig#"]){0-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
	struct v2gDigestMethodType DigestMethod ;
	/* element: "http://www.w3.org/2000/09/xmldsig#":DigestValue, http://www.w3.org/2000/09/xmldsig#,DigestValueType */
	struct {
		uint8_t bytes[v2gReferenceType_DigestValue_BYTES_SIZE];
		uint16_t bytesLen;
	}  DigestValue ;
};

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,ManifestType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":Reference{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
#define v2gManifestType_Id_CHARACTERS_SIZE 50
#define v2gManifestType_Reference_ARRAY_SIZE 1
struct v2gManifestType {
	/* attribute: Id {http://www.w3.org/2001/XMLSchema,ID} */
	struct {
		exi_string_character_t characters[v2gManifestType_Id_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Id ;
	unsigned int Id_isUsed:1;
	/* element: "http://www.w3.org/2000/09/xmldsig#":Reference, Complex type name='http://www.w3.org/2000/09/xmldsig#,ReferenceType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":Transforms{0-1},"http://www.w3.org/2000/09/xmldsig#":DigestMethod,"http://www.w3.org/2000/09/xmldsig#":DigestValue)',  derivedBy='RESTRICTION'.  */
	struct {
		struct v2gReferenceType array[v2gManifestType_Reference_ARRAY_SIZE];
		uint16_t arrayLen;
	} Reference;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVSEChargeParameterType',  base type name='EVSEChargeParameterType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":DC_EVSEStatus,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMaximumCurrentLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMaximumPowerLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMaximumVoltageLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMinimumCurrentLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMinimumVoltageLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVSECurrentRegulationTolerance{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVSEPeakCurrentRipple,"urn:iso:15118:2:2013:MsgDataTypes":EVSEEnergyToBeDelivered{0-1})',  derivedBy='EXTENSION'.  */
struct v2gDC_EVSEChargeParameterType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":DC_EVSEStatus, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVSEStatusType',  base type name='EVSEStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification),("urn:iso:15118:2:2013:MsgDataTypes":EVSEIsolationStatus{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVSEStatusCode))',  derivedBy='EXTENSION'.  */
	struct v2gDC_EVSEStatusType DC_EVSEStatus ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVSEMaximumCurrentLimit, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVSEMaximumCurrentLimit ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVSEMaximumPowerLimit, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVSEMaximumPowerLimit ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVSEMaximumVoltageLimit, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVSEMaximumVoltageLimit ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVSEMinimumCurrentLimit, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVSEMinimumCurrentLimit ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVSEMinimumVoltageLimit, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVSEMinimumVoltageLimit ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVSECurrentRegulationTolerance, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVSECurrentRegulationTolerance ;
	unsigned int EVSECurrentRegulationTolerance_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVSEPeakCurrentRipple, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVSEPeakCurrentRipple ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVSEEnergyToBeDelivered, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
	struct v2gPhysicalValueType EVSEEnergyToBeDelivered ;
	unsigned int EVSEEnergyToBeDelivered_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,ServiceDetailResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":ServiceID,"urn:iso:15118:2:2013:MsgBody":ServiceParameterList{0-1})',  derivedBy='EXTENSION'.  */
struct v2gServiceDetailResType {
	/* element: "urn:iso:15118:2:2013:MsgBody":ResponseCode, urn:iso:15118:2:2013:MsgDataTypes,responseCodeType */
	v2gresponseCodeType ResponseCode ;
	/* element: "urn:iso:15118:2:2013:MsgBody":ServiceID, urn:iso:15118:2:2013:MsgDataTypes,serviceIDType */
	uint16_t ServiceID ;
	/* element: "urn:iso:15118:2:2013:MsgBody":ServiceParameterList, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ServiceParameterListType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":ParameterSet{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
	struct v2gServiceParameterListType ServiceParameterList ;
	unsigned int ServiceParameterList_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,MeteringReceiptResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgDataTypes":EVSEStatus)',  derivedBy='EXTENSION'.  */
struct v2gMeteringReceiptResType {
	/* element: "urn:iso:15118:2:2013:MsgBody":ResponseCode, urn:iso:15118:2:2013:MsgDataTypes,responseCodeType */
	v2gresponseCodeType ResponseCode ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVSEStatus, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EVSEStatusType',  base type name='anyType',  content type='ELEMENT',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification)',  derivedBy='RESTRICTION'.  */
	struct v2gEVSEStatusType EVSEStatus ;
	unsigned int EVSEStatus_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":AC_EVSEStatus, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,AC_EVSEStatusType',  base type name='EVSEStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification),("urn:iso:15118:2:2013:MsgDataTypes":RCD))',  derivedBy='EXTENSION'.  */
	struct v2gAC_EVSEStatusType AC_EVSEStatus ;
	unsigned int AC_EVSEStatus_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":DC_EVSEStatus, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVSEStatusType',  base type name='EVSEStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification),("urn:iso:15118:2:2013:MsgDataTypes":EVSEIsolationStatus{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVSEStatusCode))',  derivedBy='EXTENSION'.  */
	struct v2gDC_EVSEStatusType DC_EVSEStatus ;
	unsigned int DC_EVSEStatus_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,PowerDeliveryReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ChargeProgress,"urn:iso:15118:2:2013:MsgBody":SAScheduleTupleID,"urn:iso:15118:2:2013:MsgBody":ChargingProfile{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVPowerDeliveryParameter{0-1})',  derivedBy='EXTENSION'.  */
struct v2gPowerDeliveryReqType {
	/* element: "urn:iso:15118:2:2013:MsgBody":ChargeProgress, urn:iso:15118:2:2013:MsgDataTypes,chargeProgressType */
	v2gchargeProgressType ChargeProgress ;
	/* element: "urn:iso:15118:2:2013:MsgBody":SAScheduleTupleID, urn:iso:15118:2:2013:MsgDataTypes,SAIDType */
	uint8_t SAScheduleTupleID ;
	/* element: "urn:iso:15118:2:2013:MsgBody":ChargingProfile, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ChargingProfileType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":ProfileEntry{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
	struct v2gChargingProfileType ChargingProfile ;
	unsigned int ChargingProfile_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVPowerDeliveryParameter, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EVPowerDeliveryParameterType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
	struct v2gEVPowerDeliveryParameterType EVPowerDeliveryParameter ;
	unsigned int EVPowerDeliveryParameter_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":DC_EVPowerDeliveryParameter, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVPowerDeliveryParameterType',  base type name='EVPowerDeliveryParameterType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":DC_EVStatus,"urn:iso:15118:2:2013:MsgDataTypes":BulkChargingComplete{0-1},"urn:iso:15118:2:2013:MsgDataTypes":ChargingComplete)',  derivedBy='EXTENSION'.  */
	struct v2gDC_EVPowerDeliveryParameterType DC_EVPowerDeliveryParameter ;
	unsigned int DC_EVPowerDeliveryParameter_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,ServiceDiscoveryResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":PaymentOptionList,"urn:iso:15118:2:2013:MsgBody":ChargeService,"urn:iso:15118:2:2013:MsgBody":ServiceList{0-1})',  derivedBy='EXTENSION'.  */
struct v2gServiceDiscoveryResType {
	/* element: "urn:iso:15118:2:2013:MsgBody":ResponseCode, urn:iso:15118:2:2013:MsgDataTypes,responseCodeType */
	v2gresponseCodeType ResponseCode ;
	/* element: "urn:iso:15118:2:2013:MsgBody":PaymentOptionList, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PaymentOptionListType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":PaymentOption{1-2})',  derivedBy='RESTRICTION'.  */
	struct v2gPaymentOptionListType PaymentOptionList ;
	/* element: "urn:iso:15118:2:2013:MsgBody":ChargeService, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ChargeServiceType',  base type name='ServiceType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":ServiceID,"urn:iso:15118:2:2013:MsgDataTypes":ServiceName{0-1},"urn:iso:15118:2:2013:MsgDataTypes":ServiceCategory,"urn:iso:15118:2:2013:MsgDataTypes":ServiceScope{0-1},"urn:iso:15118:2:2013:MsgDataTypes":FreeService),("urn:iso:15118:2:2013:MsgDataTypes":SupportedEnergyTransferMode))',  derivedBy='EXTENSION'.  */
	struct v2gChargeServiceType ChargeService ;
	/* element: "urn:iso:15118:2:2013:MsgBody":ServiceList, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ServiceListType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Service{1-8})',  derivedBy='RESTRICTION'.  */
	struct v2gServiceListType ServiceList ;
	unsigned int ServiceList_isUsed:1;
};

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,SignedInfoType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":CanonicalizationMethod,"http://www.w3.org/2000/09/xmldsig#":SignatureMethod,"http://www.w3.org/2000/09/xmldsig#":Reference{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
#define v2gSignedInfoType_Id_CHARACTERS_SIZE 50
#define v2gSignedInfoType_Reference_ARRAY_SIZE 1
struct v2gSignedInfoType {
	/* attribute: Id {http://www.w3.org/2001/XMLSchema,ID} */
	struct {
		exi_string_character_t characters[v2gSignedInfoType_Id_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Id ;
	unsigned int Id_isUsed:1;
	/* element: "http://www.w3.org/2000/09/xmldsig#":CanonicalizationMethod, Complex type name='http://www.w3.org/2000/09/xmldsig#,CanonicalizationMethodType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='((WC[##any]){0-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
	struct v2gCanonicalizationMethodType CanonicalizationMethod ;
	/* element: "http://www.w3.org/2000/09/xmldsig#":SignatureMethod, Complex type name='http://www.w3.org/2000/09/xmldsig#,SignatureMethodType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":HMACOutputLength{0-1},(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]){0-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
	struct v2gSignatureMethodType SignatureMethod ;
	/* element: "http://www.w3.org/2000/09/xmldsig#":Reference, Complex type name='http://www.w3.org/2000/09/xmldsig#,ReferenceType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":Transforms{0-1},"http://www.w3.org/2000/09/xmldsig#":DigestMethod,"http://www.w3.org/2000/09/xmldsig#":DigestValue)',  derivedBy='RESTRICTION'.  */
	struct {
		struct v2gReferenceType array[v2gSignedInfoType_Reference_ARRAY_SIZE];
		uint16_t arrayLen;
	} Reference;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SAScheduleTupleType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":SAScheduleTupleID,"urn:iso:15118:2:2013:MsgDataTypes":PMaxSchedule,"urn:iso:15118:2:2013:MsgDataTypes":SalesTariff{0-1})',  derivedBy='RESTRICTION'.  */
struct v2gSAScheduleTupleType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":SAScheduleTupleID, urn:iso:15118:2:2013:MsgDataTypes,SAIDType */
	uint8_t SAScheduleTupleID ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":PMaxSchedule, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PMaxScheduleType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":PMaxScheduleEntry{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
	struct v2gPMaxScheduleType PMaxSchedule ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":SalesTariff, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SalesTariffType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":SalesTariffID,"urn:iso:15118:2:2013:MsgDataTypes":SalesTariffDescription{0-1},"urn:iso:15118:2:2013:MsgDataTypes":NumEPriceLevels{0-1},"urn:iso:15118:2:2013:MsgDataTypes":SalesTariffEntry{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
	struct v2gSalesTariffType SalesTariff ;
	unsigned int SalesTariff_isUsed:1;
};

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,RetrievalMethodType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":Transforms{0-1})',  derivedBy='RESTRICTION'.  */
#define v2gRetrievalMethodType_URI_CHARACTERS_SIZE 50
#define v2gRetrievalMethodType_Type_CHARACTERS_SIZE 50
struct v2gRetrievalMethodType {
	/* attribute: URI {http://www.w3.org/2001/XMLSchema,anyURI} */
	struct {
		exi_string_character_t characters[v2gRetrievalMethodType_URI_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  URI ;
	unsigned int URI_isUsed:1;
	/* attribute: Type {http://www.w3.org/2001/XMLSchema,anyURI} */
	struct {
		exi_string_character_t characters[v2gRetrievalMethodType_Type_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Type ;
	unsigned int Type_isUsed:1;
	/* element: "http://www.w3.org/2000/09/xmldsig#":Transforms, Complex type name='http://www.w3.org/2000/09/xmldsig#,TransformsType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":Transform{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
	struct v2gTransformsType Transforms ;
	unsigned int Transforms_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SAScheduleListType',  base type name='SASchedulesType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":SAScheduleTuple{1-3})',  derivedBy='EXTENSION'.  */
#define v2gSAScheduleListType_SAScheduleTuple_ARRAY_SIZE 3
struct v2gSAScheduleListType {
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":SAScheduleTuple, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SAScheduleTupleType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":SAScheduleTupleID,"urn:iso:15118:2:2013:MsgDataTypes":PMaxSchedule,"urn:iso:15118:2:2013:MsgDataTypes":SalesTariff{0-1})',  derivedBy='RESTRICTION'.  */
	struct {
		struct v2gSAScheduleTupleType array[v2gSAScheduleListType_SAScheduleTuple_ARRAY_SIZE];
		uint16_t arrayLen;
	} SAScheduleTuple;
};

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,KeyInfoType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":KeyName|"http://www.w3.org/2000/09/xmldsig#":KeyValue|"http://www.w3.org/2000/09/xmldsig#":RetrievalMethod|"http://www.w3.org/2000/09/xmldsig#":X509Data|"http://www.w3.org/2000/09/xmldsig#":PGPData|"http://www.w3.org/2000/09/xmldsig#":SPKIData|"http://www.w3.org/2000/09/xmldsig#":MgmtData|(WC[##other:"http://www.w3.org/2000/09/xmldsig#"])){1-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
#define v2gKeyInfoType_Id_CHARACTERS_SIZE 50
#define v2gKeyInfoType_KeyName_CHARACTERS_SIZE 50
#define v2gKeyInfoType_KeyName_ARRAY_SIZE 1
#define v2gKeyInfoType_KeyValue_ARRAY_SIZE 1
#define v2gKeyInfoType_RetrievalMethod_ARRAY_SIZE 1
#define v2gKeyInfoType_X509Data_ARRAY_SIZE 1
#define v2gKeyInfoType_PGPData_ARRAY_SIZE 1
#define v2gKeyInfoType_SPKIData_ARRAY_SIZE 1
#define v2gKeyInfoType_MgmtData_CHARACTERS_SIZE 50
#define v2gKeyInfoType_MgmtData_ARRAY_SIZE 1
struct v2gKeyInfoType {
	/* attribute: Id {http://www.w3.org/2001/XMLSchema,ID} */
	struct {
		exi_string_character_t characters[v2gKeyInfoType_Id_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Id ;
	unsigned int Id_isUsed:1;
	/* element: "http://www.w3.org/2000/09/xmldsig#":KeyName, http://www.w3.org/2001/XMLSchema,string */
	struct {
		struct {
			exi_string_character_t characters[v2gKeyInfoType_KeyName_CHARACTERS_SIZE];
			uint16_t charactersLen;
		}  array[v2gKeyInfoType_KeyName_ARRAY_SIZE];
		uint16_t arrayLen;
	} KeyName;
	/* element: "http://www.w3.org/2000/09/xmldsig#":KeyValue, Complex type name='http://www.w3.org/2000/09/xmldsig#,KeyValueType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":DSAKeyValue|"http://www.w3.org/2000/09/xmldsig#":RSAKeyValue|(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]))',  derivedBy='RESTRICTION'.  */
	struct {
		struct v2gKeyValueType array[v2gKeyInfoType_KeyValue_ARRAY_SIZE];
		uint16_t arrayLen;
	} KeyValue;
	/* element: "http://www.w3.org/2000/09/xmldsig#":RetrievalMethod, Complex type name='http://www.w3.org/2000/09/xmldsig#,RetrievalMethodType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":Transforms{0-1})',  derivedBy='RESTRICTION'.  */
	struct {
		struct v2gRetrievalMethodType array[v2gKeyInfoType_RetrievalMethod_ARRAY_SIZE];
		uint16_t arrayLen;
	} RetrievalMethod;
	/* element: "http://www.w3.org/2000/09/xmldsig#":X509Data, Complex type name='http://www.w3.org/2000/09/xmldsig#,X509DataType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("http://www.w3.org/2000/09/xmldsig#":X509IssuerSerial|"http://www.w3.org/2000/09/xmldsig#":X509SKI|"http://www.w3.org/2000/09/xmldsig#":X509SubjectName|"http://www.w3.org/2000/09/xmldsig#":X509Certificate|"http://www.w3.org/2000/09/xmldsig#":X509CRL|(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]))){1-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
	struct {
		struct v2gX509DataType array[v2gKeyInfoType_X509Data_ARRAY_SIZE];
		uint16_t arrayLen;
	} X509Data;
	/* element: "http://www.w3.org/2000/09/xmldsig#":PGPData, Complex type name='http://www.w3.org/2000/09/xmldsig#,PGPDataType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("http://www.w3.org/2000/09/xmldsig#":PGPKeyID,"http://www.w3.org/2000/09/xmldsig#":PGPKeyPacket{0-1},(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]){0-UNBOUNDED})|("http://www.w3.org/2000/09/xmldsig#":PGPKeyPacket,(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]){0-UNBOUNDED}))',  derivedBy='RESTRICTION'.  */
	struct {
		struct v2gPGPDataType array[v2gKeyInfoType_PGPData_ARRAY_SIZE];
		uint16_t arrayLen;
	} PGPData;
	/* element: "http://www.w3.org/2000/09/xmldsig#":SPKIData, Complex type name='http://www.w3.org/2000/09/xmldsig#,SPKIDataType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":SPKISexp,(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]){0-1}){1-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
	struct {
		struct v2gSPKIDataType array[v2gKeyInfoType_SPKIData_ARRAY_SIZE];
		uint16_t arrayLen;
	} SPKIData;
	/* element: "http://www.w3.org/2000/09/xmldsig#":MgmtData, http://www.w3.org/2001/XMLSchema,string */
	struct {
		struct {
			exi_string_character_t characters[v2gKeyInfoType_MgmtData_CHARACTERS_SIZE];
			uint16_t charactersLen;
		}  array[v2gKeyInfoType_MgmtData_ARRAY_SIZE];
		uint16_t arrayLen;
	} MgmtData;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,ChargeParameterDiscoveryResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":EVSEProcessing,"urn:iso:15118:2:2013:MsgDataTypes":SASchedules{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVSEChargeParameter)',  derivedBy='EXTENSION'.  */
struct v2gChargeParameterDiscoveryResType {
	/* element: "urn:iso:15118:2:2013:MsgBody":ResponseCode, urn:iso:15118:2:2013:MsgDataTypes,responseCodeType */
	v2gresponseCodeType ResponseCode ;
	/* element: "urn:iso:15118:2:2013:MsgBody":EVSEProcessing, urn:iso:15118:2:2013:MsgDataTypes,EVSEProcessingType */
	v2gEVSEProcessingType EVSEProcessing ;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":SASchedules, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SASchedulesType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
	struct v2gSASchedulesType SASchedules ;
	unsigned int SASchedules_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":SAScheduleList, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SAScheduleListType',  base type name='SASchedulesType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":SAScheduleTuple{1-3})',  derivedBy='EXTENSION'.  */
	struct v2gSAScheduleListType SAScheduleList ;
	unsigned int SAScheduleList_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":EVSEChargeParameter, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EVSEChargeParameterType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
	struct v2gEVSEChargeParameterType EVSEChargeParameter ;
	unsigned int EVSEChargeParameter_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":AC_EVSEChargeParameter, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,AC_EVSEChargeParameterType',  base type name='EVSEChargeParameterType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":AC_EVSEStatus,"urn:iso:15118:2:2013:MsgDataTypes":EVSENominalVoltage,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMaxCurrent)',  derivedBy='EXTENSION'.  */
	struct v2gAC_EVSEChargeParameterType AC_EVSEChargeParameter ;
	unsigned int AC_EVSEChargeParameter_isUsed:1;
	/* element: "urn:iso:15118:2:2013:MsgDataTypes":DC_EVSEChargeParameter, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVSEChargeParameterType',  base type name='EVSEChargeParameterType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":DC_EVSEStatus,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMaximumCurrentLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMaximumPowerLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMaximumVoltageLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMinimumCurrentLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMinimumVoltageLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVSECurrentRegulationTolerance{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVSEPeakCurrentRipple,"urn:iso:15118:2:2013:MsgDataTypes":EVSEEnergyToBeDelivered{0-1})',  derivedBy='EXTENSION'.  */
	struct v2gDC_EVSEChargeParameterType DC_EVSEChargeParameter ;
	unsigned int DC_EVSEChargeParameter_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgBody,BodyType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":BodyElement{0-1})',  derivedBy='RESTRICTION'.  */
struct v2gBodyType {
	/* substitutionGroup */
#if SAVE_MEMORY_WITH_UNNAMED_UNION == UNION_YES
	union {
#endif /* SAVE_MEMORY_WITH_UNNAMED_UNION == UNION_YES */
		/* element: "urn:iso:15118:2:2013:MsgBody":BodyElement, Complex type name='urn:iso:15118:2:2013:MsgBody,BodyBaseType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
		struct v2gBodyBaseType BodyElement ;
		/* element: "urn:iso:15118:2:2013:MsgBody":SessionSetupReq, Complex type name='urn:iso:15118:2:2013:MsgBody,SessionSetupReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":EVCCID)',  derivedBy='EXTENSION'.  */
		struct v2gSessionSetupReqType SessionSetupReq ;
		/* element: "urn:iso:15118:2:2013:MsgBody":SessionSetupRes, Complex type name='urn:iso:15118:2:2013:MsgBody,SessionSetupResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":EVSEID,"urn:iso:15118:2:2013:MsgBody":EVSETimeStamp{0-1})',  derivedBy='EXTENSION'.  */
		struct v2gSessionSetupResType SessionSetupRes ;
		/* element: "urn:iso:15118:2:2013:MsgBody":ServiceDiscoveryReq, Complex type name='urn:iso:15118:2:2013:MsgBody,ServiceDiscoveryReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ServiceScope{0-1},"urn:iso:15118:2:2013:MsgBody":ServiceCategory{0-1})',  derivedBy='EXTENSION'.  */
		struct v2gServiceDiscoveryReqType ServiceDiscoveryReq ;
		/* element: "urn:iso:15118:2:2013:MsgBody":ServiceDiscoveryRes, Complex type name='urn:iso:15118:2:2013:MsgBody,ServiceDiscoveryResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":PaymentOptionList,"urn:iso:15118:2:2013:MsgBody":ChargeService,"urn:iso:15118:2:2013:MsgBody":ServiceList{0-1})',  derivedBy='EXTENSION'.  */
		struct v2gServiceDiscoveryResType ServiceDiscoveryRes ;
		/* element: "urn:iso:15118:2:2013:MsgBody":ServiceDetailReq, Complex type name='urn:iso:15118:2:2013:MsgBody,ServiceDetailReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ServiceID)',  derivedBy='EXTENSION'.  */
		struct v2gServiceDetailReqType ServiceDetailReq ;
		/* element: "urn:iso:15118:2:2013:MsgBody":ServiceDetailRes, Complex type name='urn:iso:15118:2:2013:MsgBody,ServiceDetailResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":ServiceID,"urn:iso:15118:2:2013:MsgBody":ServiceParameterList{0-1})',  derivedBy='EXTENSION'.  */
		struct v2gServiceDetailResType ServiceDetailRes ;
		/* element: "urn:iso:15118:2:2013:MsgBody":PaymentServiceSelectionReq, Complex type name='urn:iso:15118:2:2013:MsgBody,PaymentServiceSelectionReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":SelectedPaymentOption,"urn:iso:15118:2:2013:MsgBody":SelectedServiceList)',  derivedBy='EXTENSION'.  */
		struct v2gPaymentServiceSelectionReqType PaymentServiceSelectionReq ;
		/* element: "urn:iso:15118:2:2013:MsgBody":PaymentServiceSelectionRes, Complex type name='urn:iso:15118:2:2013:MsgBody,PaymentServiceSelectionResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode)',  derivedBy='EXTENSION'.  */
		struct v2gPaymentServiceSelectionResType PaymentServiceSelectionRes ;
		/* element: "urn:iso:15118:2:2013:MsgBody":PaymentDetailsReq, Complex type name='urn:iso:15118:2:2013:MsgBody,PaymentDetailsReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":eMAID,"urn:iso:15118:2:2013:MsgBody":ContractSignatureCertChain)',  derivedBy='EXTENSION'.  */
		struct v2gPaymentDetailsReqType PaymentDetailsReq ;
		/* element: "urn:iso:15118:2:2013:MsgBody":PaymentDetailsRes, Complex type name='urn:iso:15118:2:2013:MsgBody,PaymentDetailsResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":GenChallenge,"urn:iso:15118:2:2013:MsgBody":EVSETimeStamp)',  derivedBy='EXTENSION'.  */
		struct v2gPaymentDetailsResType PaymentDetailsRes ;
		/* element: "urn:iso:15118:2:2013:MsgBody":AuthorizationReq, Complex type name='urn:iso:15118:2:2013:MsgBody,AuthorizationReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":GenChallenge{0-1})',  derivedBy='EXTENSION'.  */
		struct v2gAuthorizationReqType AuthorizationReq ;
		/* element: "urn:iso:15118:2:2013:MsgBody":AuthorizationRes, Complex type name='urn:iso:15118:2:2013:MsgBody,AuthorizationResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":EVSEProcessing)',  derivedBy='EXTENSION'.  */
		struct v2gAuthorizationResType AuthorizationRes ;
		/* element: "urn:iso:15118:2:2013:MsgBody":ChargeParameterDiscoveryReq, Complex type name='urn:iso:15118:2:2013:MsgBody,ChargeParameterDiscoveryReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":MaxEntriesSAScheduleTuple{0-1},"urn:iso:15118:2:2013:MsgBody":RequestedEnergyTransferMode,"urn:iso:15118:2:2013:MsgDataTypes":EVChargeParameter)',  derivedBy='EXTENSION'.  */
		struct v2gChargeParameterDiscoveryReqType ChargeParameterDiscoveryReq ;
		/* element: "urn:iso:15118:2:2013:MsgBody":ChargeParameterDiscoveryRes, Complex type name='urn:iso:15118:2:2013:MsgBody,ChargeParameterDiscoveryResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":EVSEProcessing,"urn:iso:15118:2:2013:MsgDataTypes":SASchedules{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVSEChargeParameter)',  derivedBy='EXTENSION'.  */
		struct v2gChargeParameterDiscoveryResType ChargeParameterDiscoveryRes ;
		/* element: "urn:iso:15118:2:2013:MsgBody":PowerDeliveryReq, Complex type name='urn:iso:15118:2:2013:MsgBody,PowerDeliveryReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ChargeProgress,"urn:iso:15118:2:2013:MsgBody":SAScheduleTupleID,"urn:iso:15118:2:2013:MsgBody":ChargingProfile{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVPowerDeliveryParameter{0-1})',  derivedBy='EXTENSION'.  */
		struct v2gPowerDeliveryReqType PowerDeliveryReq ;
		/* element: "urn:iso:15118:2:2013:MsgBody":PowerDeliveryRes, Complex type name='urn:iso:15118:2:2013:MsgBody,PowerDeliveryResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgDataTypes":EVSEStatus)',  derivedBy='EXTENSION'.  */
		struct v2gPowerDeliveryResType PowerDeliveryRes ;
		/* element: "urn:iso:15118:2:2013:MsgBody":MeteringReceiptReq, Complex type name='urn:iso:15118:2:2013:MsgBody,MeteringReceiptReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":SessionID,"urn:iso:15118:2:2013:MsgBody":SAScheduleTupleID{0-1},"urn:iso:15118:2:2013:MsgBody":MeterInfo)',  derivedBy='EXTENSION'.  */
		struct v2gMeteringReceiptReqType MeteringReceiptReq ;
		/* element: "urn:iso:15118:2:2013:MsgBody":MeteringReceiptRes, Complex type name='urn:iso:15118:2:2013:MsgBody,MeteringReceiptResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgDataTypes":EVSEStatus)',  derivedBy='EXTENSION'.  */
		struct v2gMeteringReceiptResType MeteringReceiptRes ;
		/* element: "urn:iso:15118:2:2013:MsgBody":SessionStopReq, Complex type name='urn:iso:15118:2:2013:MsgBody,SessionStopReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ChargingSession)',  derivedBy='EXTENSION'.  */
		struct v2gSessionStopReqType SessionStopReq ;
		/* element: "urn:iso:15118:2:2013:MsgBody":SessionStopRes, Complex type name='urn:iso:15118:2:2013:MsgBody,SessionStopResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode)',  derivedBy='EXTENSION'.  */
		struct v2gSessionStopResType SessionStopRes ;
		/* element: "urn:iso:15118:2:2013:MsgBody":CertificateUpdateReq, Complex type name='urn:iso:15118:2:2013:MsgBody,CertificateUpdateReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ContractSignatureCertChain,"urn:iso:15118:2:2013:MsgBody":eMAID,"urn:iso:15118:2:2013:MsgBody":ListOfRootCertificateIDs)',  derivedBy='EXTENSION'.  */
		struct v2gCertificateUpdateReqType CertificateUpdateReq ;
		/* element: "urn:iso:15118:2:2013:MsgBody":CertificateUpdateRes, Complex type name='urn:iso:15118:2:2013:MsgBody,CertificateUpdateResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":SAProvisioningCertificateChain,"urn:iso:15118:2:2013:MsgBody":ContractSignatureCertChain,"urn:iso:15118:2:2013:MsgBody":ContractSignatureEncryptedPrivateKey,"urn:iso:15118:2:2013:MsgBody":DHpublickey,"urn:iso:15118:2:2013:MsgBody":eMAID,"urn:iso:15118:2:2013:MsgBody":RetryCounter{0-1})',  derivedBy='EXTENSION'.  */
		struct v2gCertificateUpdateResType CertificateUpdateRes ;
		/* element: "urn:iso:15118:2:2013:MsgBody":CertificateInstallationReq, Complex type name='urn:iso:15118:2:2013:MsgBody,CertificateInstallationReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":OEMProvisioningCert,"urn:iso:15118:2:2013:MsgBody":ListOfRootCertificateIDs)',  derivedBy='EXTENSION'.  */
		struct v2gCertificateInstallationReqType CertificateInstallationReq ;
		/* element: "urn:iso:15118:2:2013:MsgBody":CertificateInstallationRes, Complex type name='urn:iso:15118:2:2013:MsgBody,CertificateInstallationResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":SAProvisioningCertificateChain,"urn:iso:15118:2:2013:MsgBody":ContractSignatureCertChain,"urn:iso:15118:2:2013:MsgBody":ContractSignatureEncryptedPrivateKey,"urn:iso:15118:2:2013:MsgBody":DHpublickey,"urn:iso:15118:2:2013:MsgBody":eMAID)',  derivedBy='EXTENSION'.  */
		struct v2gCertificateInstallationResType CertificateInstallationRes ;
		/* element: "urn:iso:15118:2:2013:MsgBody":ChargingStatusReq, Complex type name='urn:iso:15118:2:2013:MsgBody,ChargingStatusReqType',  base type name='BodyBaseType',  content type='EMPTY',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  derivedBy='EXTENSION'.  */
		struct v2gChargingStatusReqType ChargingStatusReq ;
		/* element: "urn:iso:15118:2:2013:MsgBody":ChargingStatusRes, Complex type name='urn:iso:15118:2:2013:MsgBody,ChargingStatusResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":EVSEID,"urn:iso:15118:2:2013:MsgBody":SAScheduleTupleID,"urn:iso:15118:2:2013:MsgBody":EVSEMaxCurrent{0-1},"urn:iso:15118:2:2013:MsgBody":MeterInfo{0-1},"urn:iso:15118:2:2013:MsgBody":ReceiptRequired{0-1},"urn:iso:15118:2:2013:MsgBody":AC_EVSEStatus)',  derivedBy='EXTENSION'.  */
		struct v2gChargingStatusResType ChargingStatusRes ;
		/* element: "urn:iso:15118:2:2013:MsgBody":CableCheckReq, Complex type name='urn:iso:15118:2:2013:MsgBody,CableCheckReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":DC_EVStatus)',  derivedBy='EXTENSION'.  */
		struct v2gCableCheckReqType CableCheckReq ;
		/* element: "urn:iso:15118:2:2013:MsgBody":CableCheckRes, Complex type name='urn:iso:15118:2:2013:MsgBody,CableCheckResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":DC_EVSEStatus,"urn:iso:15118:2:2013:MsgBody":EVSEProcessing)',  derivedBy='EXTENSION'.  */
		struct v2gCableCheckResType CableCheckRes ;
		/* element: "urn:iso:15118:2:2013:MsgBody":PreChargeReq, Complex type name='urn:iso:15118:2:2013:MsgBody,PreChargeReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":DC_EVStatus,"urn:iso:15118:2:2013:MsgBody":EVTargetVoltage,"urn:iso:15118:2:2013:MsgBody":EVTargetCurrent)',  derivedBy='EXTENSION'.  */
		struct v2gPreChargeReqType PreChargeReq ;
		/* element: "urn:iso:15118:2:2013:MsgBody":PreChargeRes, Complex type name='urn:iso:15118:2:2013:MsgBody,PreChargeResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":DC_EVSEStatus,"urn:iso:15118:2:2013:MsgBody":EVSEPresentVoltage)',  derivedBy='EXTENSION'.  */
		struct v2gPreChargeResType PreChargeRes ;
		/* element: "urn:iso:15118:2:2013:MsgBody":CurrentDemandReq, Complex type name='urn:iso:15118:2:2013:MsgBody,CurrentDemandReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":DC_EVStatus,"urn:iso:15118:2:2013:MsgBody":EVTargetCurrent,"urn:iso:15118:2:2013:MsgBody":EVMaximumVoltageLimit{0-1},"urn:iso:15118:2:2013:MsgBody":EVMaximumCurrentLimit{0-1},"urn:iso:15118:2:2013:MsgBody":EVMaximumPowerLimit{0-1},"urn:iso:15118:2:2013:MsgBody":BulkChargingComplete{0-1},"urn:iso:15118:2:2013:MsgBody":ChargingComplete,"urn:iso:15118:2:2013:MsgBody":RemainingTimeToFullSoC{0-1},"urn:iso:15118:2:2013:MsgBody":RemainingTimeToBulkSoC{0-1},"urn:iso:15118:2:2013:MsgBody":EVTargetVoltage)',  derivedBy='EXTENSION'.  */
		struct v2gCurrentDemandReqType CurrentDemandReq ;
		/* element: "urn:iso:15118:2:2013:MsgBody":CurrentDemandRes, Complex type name='urn:iso:15118:2:2013:MsgBody,CurrentDemandResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":DC_EVSEStatus,"urn:iso:15118:2:2013:MsgBody":EVSEPresentVoltage,"urn:iso:15118:2:2013:MsgBody":EVSEPresentCurrent,"urn:iso:15118:2:2013:MsgBody":EVSECurrentLimitAchieved,"urn:iso:15118:2:2013:MsgBody":EVSEVoltageLimitAchieved,"urn:iso:15118:2:2013:MsgBody":EVSEPowerLimitAchieved,"urn:iso:15118:2:2013:MsgBody":EVSEMaximumVoltageLimit{0-1},"urn:iso:15118:2:2013:MsgBody":EVSEMaximumCurrentLimit{0-1},"urn:iso:15118:2:2013:MsgBody":EVSEMaximumPowerLimit{0-1},"urn:iso:15118:2:2013:MsgBody":EVSEID,"urn:iso:15118:2:2013:MsgBody":SAScheduleTupleID,"urn:iso:15118:2:2013:MsgBody":MeterInfo{0-1},"urn:iso:15118:2:2013:MsgBody":ReceiptRequired{0-1})',  derivedBy='EXTENSION'.  */
		struct v2gCurrentDemandResType CurrentDemandRes ;
		/* element: "urn:iso:15118:2:2013:MsgBody":WeldingDetectionReq, Complex type name='urn:iso:15118:2:2013:MsgBody,WeldingDetectionReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":DC_EVStatus)',  derivedBy='EXTENSION'.  */
		struct v2gWeldingDetectionReqType WeldingDetectionReq ;
		/* element: "urn:iso:15118:2:2013:MsgBody":WeldingDetectionRes, Complex type name='urn:iso:15118:2:2013:MsgBody,WeldingDetectionResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":DC_EVSEStatus,"urn:iso:15118:2:2013:MsgBody":EVSEPresentVoltage)',  derivedBy='EXTENSION'.  */
		struct v2gWeldingDetectionResType WeldingDetectionRes ;
#if SAVE_MEMORY_WITH_UNNAMED_UNION == UNION_YES
	};
#endif /* SAVE_MEMORY_WITH_UNNAMED_UNION == UNION_YES */
		unsigned int BodyElement_isUsed:1;
		unsigned int SessionSetupReq_isUsed:1;
		unsigned int SessionSetupRes_isUsed:1;
		unsigned int ServiceDiscoveryReq_isUsed:1;
		unsigned int ServiceDiscoveryRes_isUsed:1;
		unsigned int ServiceDetailReq_isUsed:1;
		unsigned int ServiceDetailRes_isUsed:1;
		unsigned int PaymentServiceSelectionReq_isUsed:1;
		unsigned int PaymentServiceSelectionRes_isUsed:1;
		unsigned int PaymentDetailsReq_isUsed:1;
		unsigned int PaymentDetailsRes_isUsed:1;
		unsigned int AuthorizationReq_isUsed:1;
		unsigned int AuthorizationRes_isUsed:1;
		unsigned int ChargeParameterDiscoveryReq_isUsed:1;
		unsigned int ChargeParameterDiscoveryRes_isUsed:1;
		unsigned int PowerDeliveryReq_isUsed:1;
		unsigned int PowerDeliveryRes_isUsed:1;
		unsigned int MeteringReceiptReq_isUsed:1;
		unsigned int MeteringReceiptRes_isUsed:1;
		unsigned int SessionStopReq_isUsed:1;
		unsigned int SessionStopRes_isUsed:1;
		unsigned int CertificateUpdateReq_isUsed:1;
		unsigned int CertificateUpdateRes_isUsed:1;
		unsigned int CertificateInstallationReq_isUsed:1;
		unsigned int CertificateInstallationRes_isUsed:1;
		unsigned int ChargingStatusReq_isUsed:1;
		unsigned int ChargingStatusRes_isUsed:1;
		unsigned int CableCheckReq_isUsed:1;
		unsigned int CableCheckRes_isUsed:1;
		unsigned int PreChargeReq_isUsed:1;
		unsigned int PreChargeRes_isUsed:1;
		unsigned int CurrentDemandReq_isUsed:1;
		unsigned int CurrentDemandRes_isUsed:1;
		unsigned int WeldingDetectionReq_isUsed:1;
		unsigned int WeldingDetectionRes_isUsed:1;
};

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,SignatureType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":SignedInfo,"http://www.w3.org/2000/09/xmldsig#":SignatureValue,"http://www.w3.org/2000/09/xmldsig#":KeyInfo{0-1},"http://www.w3.org/2000/09/xmldsig#":Object{0-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
#define v2gSignatureType_Id_CHARACTERS_SIZE 50
#define v2gSignatureType_Object_ARRAY_SIZE 1
struct v2gSignatureType {
	/* attribute: Id {http://www.w3.org/2001/XMLSchema,ID} */
	struct {
		exi_string_character_t characters[v2gSignatureType_Id_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  Id ;
	unsigned int Id_isUsed:1;
	/* element: "http://www.w3.org/2000/09/xmldsig#":SignedInfo, Complex type name='http://www.w3.org/2000/09/xmldsig#,SignedInfoType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":CanonicalizationMethod,"http://www.w3.org/2000/09/xmldsig#":SignatureMethod,"http://www.w3.org/2000/09/xmldsig#":Reference{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
	struct v2gSignedInfoType SignedInfo ;
	/* element: "http://www.w3.org/2000/09/xmldsig#":SignatureValue, Complex type name='http://www.w3.org/2000/09/xmldsig#,SignatureValueType',  base type name='base64Binary',  content type='SIMPLE',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  derivedBy='EXTENSION'.  */
	struct v2gSignatureValueType SignatureValue ;
	/* element: "http://www.w3.org/2000/09/xmldsig#":KeyInfo, Complex type name='http://www.w3.org/2000/09/xmldsig#,KeyInfoType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":KeyName|"http://www.w3.org/2000/09/xmldsig#":KeyValue|"http://www.w3.org/2000/09/xmldsig#":RetrievalMethod|"http://www.w3.org/2000/09/xmldsig#":X509Data|"http://www.w3.org/2000/09/xmldsig#":PGPData|"http://www.w3.org/2000/09/xmldsig#":SPKIData|"http://www.w3.org/2000/09/xmldsig#":MgmtData|(WC[##other:"http://www.w3.org/2000/09/xmldsig#"])){1-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
	struct v2gKeyInfoType KeyInfo ;
	unsigned int KeyInfo_isUsed:1;
	/* element: "http://www.w3.org/2000/09/xmldsig#":Object, Complex type name='http://www.w3.org/2000/09/xmldsig#,ObjectType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='((WC[##any])){0-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
	struct {
		struct v2gObjectType array[v2gSignatureType_Object_ARRAY_SIZE];
		uint16_t arrayLen;
	} Object;
};

/* Complex type name='urn:iso:15118:2:2013:MsgHeader,MessageHeaderType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgHeader":SessionID,"urn:iso:15118:2:2013:MsgHeader":Notification{0-1},"http://www.w3.org/2000/09/xmldsig#":Signature{0-1})',  derivedBy='RESTRICTION'.  */
#define v2gMessageHeaderType_SessionID_BYTES_SIZE 8 /* XML schema facet maxLength for urn:iso:15118:2:2013:MsgDataTypes,sessionIDType is 8 */
struct v2gMessageHeaderType {
	/* element: "urn:iso:15118:2:2013:MsgHeader":SessionID, urn:iso:15118:2:2013:MsgDataTypes,sessionIDType */
	struct {
		uint8_t bytes[v2gMessageHeaderType_SessionID_BYTES_SIZE];
		uint16_t bytesLen;
	}  SessionID ;
	/* element: "urn:iso:15118:2:2013:MsgHeader":Notification, Complex type name='urn:iso:15118:2:2013:MsgDataTypes,NotificationType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":FaultCode,"urn:iso:15118:2:2013:MsgDataTypes":FaultMsg{0-1})',  derivedBy='RESTRICTION'.  */
	struct v2gNotificationType Notification ;
	unsigned int Notification_isUsed:1;
	/* element: "http://www.w3.org/2000/09/xmldsig#":Signature, Complex type name='http://www.w3.org/2000/09/xmldsig#,SignatureType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":SignedInfo,"http://www.w3.org/2000/09/xmldsig#":SignatureValue,"http://www.w3.org/2000/09/xmldsig#":KeyInfo{0-1},"http://www.w3.org/2000/09/xmldsig#":Object{0-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
	struct v2gSignatureType Signature ;
	unsigned int Signature_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2013:MsgDef,#AnonType_V2G_Message',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDef":Header,"urn:iso:15118:2:2013:MsgDef":Body)',  derivedBy='RESTRICTION'.  */
struct v2gAnonType_V2G_Message {
	/* element: "urn:iso:15118:2:2013:MsgDef":Header, Complex type name='urn:iso:15118:2:2013:MsgHeader,MessageHeaderType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgHeader":SessionID,"urn:iso:15118:2:2013:MsgHeader":Notification{0-1},"http://www.w3.org/2000/09/xmldsig#":Signature{0-1})',  derivedBy='RESTRICTION'.  */
	struct v2gMessageHeaderType Header ;
	/* element: "urn:iso:15118:2:2013:MsgDef":Body, Complex type name='urn:iso:15118:2:2013:MsgBody,BodyType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":BodyElement{0-1})',  derivedBy='RESTRICTION'.  */
	struct v2gBodyType Body ;
};



#define EXIDocument_MgmtData_CHARACTERS_SIZE 50
#define EXIDocument_KeyName_CHARACTERS_SIZE 50
#define EXIDocument_DigestValue_BYTES_SIZE 350


/* Possible root elements of EXI Document */
struct v2gEXIDocument {
#if SAVE_MEMORY_WITH_UNNAMED_UNION == UNION_YES
	union {
#endif /* SAVE_MEMORY_WITH_UNNAMED_UNION == UNION_YES */
	struct v2gAnonType_V2G_Message V2G_Message ;
	struct v2gServiceDiscoveryReqType ServiceDiscoveryReq ;
	struct v2gServiceDiscoveryResType ServiceDiscoveryRes ;
	struct v2gMeteringReceiptReqType MeteringReceiptReq ;
	struct v2gPaymentDetailsReqType PaymentDetailsReq ;
	struct v2gMeteringReceiptResType MeteringReceiptRes ;
	struct v2gPaymentDetailsResType PaymentDetailsRes ;
	struct v2gSessionSetupReqType SessionSetupReq ;
	struct v2gSessionSetupResType SessionSetupRes ;
	struct v2gCableCheckReqType CableCheckReq ;
	struct v2gCableCheckResType CableCheckRes ;
	struct v2gCertificateInstallationReqType CertificateInstallationReq ;
	struct v2gCertificateInstallationResType CertificateInstallationRes ;
	struct v2gWeldingDetectionReqType WeldingDetectionReq ;
	struct v2gWeldingDetectionResType WeldingDetectionRes ;
	struct v2gCertificateUpdateReqType CertificateUpdateReq ;
	struct v2gCertificateUpdateResType CertificateUpdateRes ;
	struct v2gPaymentServiceSelectionReqType PaymentServiceSelectionReq ;
	struct v2gPowerDeliveryReqType PowerDeliveryReq ;
	struct v2gPaymentServiceSelectionResType PaymentServiceSelectionRes ;
	struct v2gPowerDeliveryResType PowerDeliveryRes ;
	struct v2gChargingStatusReqType ChargingStatusReq ;
	struct v2gChargingStatusResType ChargingStatusRes ;
	struct v2gBodyBaseType BodyElement ;
	struct v2gCurrentDemandReqType CurrentDemandReq ;
	struct v2gPreChargeReqType PreChargeReq ;
	struct v2gCurrentDemandResType CurrentDemandRes ;
	struct v2gPreChargeResType PreChargeRes ;
	struct v2gSessionStopReqType SessionStopReq ;
	struct v2gAuthorizationReqType AuthorizationReq ;
	struct v2gSessionStopResType SessionStopRes ;
	struct v2gAuthorizationResType AuthorizationRes ;
	struct v2gChargeParameterDiscoveryReqType ChargeParameterDiscoveryReq ;
	struct v2gChargeParameterDiscoveryResType ChargeParameterDiscoveryRes ;
	struct v2gServiceDetailReqType ServiceDetailReq ;
	struct v2gServiceDetailResType ServiceDetailRes ;
	struct v2gDC_EVSEStatusType DC_EVSEStatus ;
	struct v2gRelativeTimeIntervalType RelativeTimeInterval ;
	struct v2gSalesTariffEntryType SalesTariffEntry ;
	struct v2gDC_EVPowerDeliveryParameterType DC_EVPowerDeliveryParameter ;
	struct v2gSASchedulesType SASchedules ;
	struct v2gAC_EVChargeParameterType AC_EVChargeParameter ;
	struct v2gSAScheduleListType SAScheduleList ;
	struct v2gDC_EVStatusType DC_EVStatus ;
	struct v2gEVStatusType EVStatus ;
	struct v2gDC_EVChargeParameterType DC_EVChargeParameter ;
	struct v2gDC_EVSEChargeParameterType DC_EVSEChargeParameter ;
	struct v2gEVSEStatusType EVSEStatus ;
	struct v2gIntervalType TimeInterval ;
	struct v2gEVPowerDeliveryParameterType EVPowerDeliveryParameter ;
	struct v2gEVSEChargeParameterType EVSEChargeParameter ;
	struct v2gAC_EVSEStatusType AC_EVSEStatus ;
	struct v2gEntryType Entry ;
	struct v2gAC_EVSEChargeParameterType AC_EVSEChargeParameter ;
	struct v2gPMaxScheduleEntryType PMaxScheduleEntry ;
	struct v2gEVChargeParameterType EVChargeParameter ;
	struct v2gSignaturePropertyType SignatureProperty ;
	struct v2gDSAKeyValueType DSAKeyValue ;
	struct v2gSignaturePropertiesType SignatureProperties ;
	struct v2gKeyValueType KeyValue ;
	struct v2gTransformsType Transforms ;
	struct v2gDigestMethodType DigestMethod ;
	struct v2gSignatureType Signature ;
	struct v2gRetrievalMethodType RetrievalMethod ;
	struct v2gManifestType Manifest ;
	struct v2gReferenceType Reference ;
	struct v2gCanonicalizationMethodType CanonicalizationMethod ;
	struct v2gRSAKeyValueType RSAKeyValue ;
	struct v2gTransformType Transform ;
	struct v2gPGPDataType PGPData ;
	struct {
		exi_string_character_t characters[EXIDocument_MgmtData_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  MgmtData ;
	struct v2gSignatureMethodType SignatureMethod ;
	struct v2gKeyInfoType KeyInfo ;
	struct v2gSPKIDataType SPKIData ;
	struct v2gX509DataType X509Data ;
	struct v2gSignatureValueType SignatureValue ;
	struct {
		exi_string_character_t characters[EXIDocument_KeyName_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  KeyName ;
	struct {
		uint8_t bytes[EXIDocument_DigestValue_BYTES_SIZE];
		uint16_t bytesLen;
	}  DigestValue ;
	struct v2gSignedInfoType SignedInfo ;
	struct v2gObjectType Object ;
#if SAVE_MEMORY_WITH_UNNAMED_UNION == UNION_YES
	};
#endif /* SAVE_MEMORY_WITH_UNNAMED_UNION == UNION_YES */
	unsigned int V2G_Message_isUsed:1;
	unsigned int ServiceDiscoveryReq_isUsed:1;
	unsigned int ServiceDiscoveryRes_isUsed:1;
	unsigned int MeteringReceiptReq_isUsed:1;
	unsigned int PaymentDetailsReq_isUsed:1;
	unsigned int MeteringReceiptRes_isUsed:1;
	unsigned int PaymentDetailsRes_isUsed:1;
	unsigned int SessionSetupReq_isUsed:1;
	unsigned int SessionSetupRes_isUsed:1;
	unsigned int CableCheckReq_isUsed:1;
	unsigned int CableCheckRes_isUsed:1;
	unsigned int CertificateInstallationReq_isUsed:1;
	unsigned int CertificateInstallationRes_isUsed:1;
	unsigned int WeldingDetectionReq_isUsed:1;
	unsigned int WeldingDetectionRes_isUsed:1;
	unsigned int CertificateUpdateReq_isUsed:1;
	unsigned int CertificateUpdateRes_isUsed:1;
	unsigned int PaymentServiceSelectionReq_isUsed:1;
	unsigned int PowerDeliveryReq_isUsed:1;
	unsigned int PaymentServiceSelectionRes_isUsed:1;
	unsigned int PowerDeliveryRes_isUsed:1;
	unsigned int ChargingStatusReq_isUsed:1;
	unsigned int ChargingStatusRes_isUsed:1;
	unsigned int BodyElement_isUsed:1;
	unsigned int CurrentDemandReq_isUsed:1;
	unsigned int PreChargeReq_isUsed:1;
	unsigned int CurrentDemandRes_isUsed:1;
	unsigned int PreChargeRes_isUsed:1;
	unsigned int SessionStopReq_isUsed:1;
	unsigned int AuthorizationReq_isUsed:1;
	unsigned int SessionStopRes_isUsed:1;
	unsigned int AuthorizationRes_isUsed:1;
	unsigned int ChargeParameterDiscoveryReq_isUsed:1;
	unsigned int ChargeParameterDiscoveryRes_isUsed:1;
	unsigned int ServiceDetailReq_isUsed:1;
	unsigned int ServiceDetailRes_isUsed:1;
	unsigned int DC_EVSEStatus_isUsed:1;
	unsigned int RelativeTimeInterval_isUsed:1;
	unsigned int SalesTariffEntry_isUsed:1;
	unsigned int DC_EVPowerDeliveryParameter_isUsed:1;
	unsigned int SASchedules_isUsed:1;
	unsigned int AC_EVChargeParameter_isUsed:1;
	unsigned int SAScheduleList_isUsed:1;
	unsigned int DC_EVStatus_isUsed:1;
	unsigned int EVStatus_isUsed:1;
	unsigned int DC_EVChargeParameter_isUsed:1;
	unsigned int DC_EVSEChargeParameter_isUsed:1;
	unsigned int EVSEStatus_isUsed:1;
	unsigned int TimeInterval_isUsed:1;
	unsigned int EVPowerDeliveryParameter_isUsed:1;
	unsigned int EVSEChargeParameter_isUsed:1;
	unsigned int AC_EVSEStatus_isUsed:1;
	unsigned int Entry_isUsed:1;
	unsigned int AC_EVSEChargeParameter_isUsed:1;
	unsigned int PMaxScheduleEntry_isUsed:1;
	unsigned int EVChargeParameter_isUsed:1;
	unsigned int SignatureProperty_isUsed:1;
	unsigned int DSAKeyValue_isUsed:1;
	unsigned int SignatureProperties_isUsed:1;
	unsigned int KeyValue_isUsed:1;
	unsigned int Transforms_isUsed:1;
	unsigned int DigestMethod_isUsed:1;
	unsigned int Signature_isUsed:1;
	unsigned int RetrievalMethod_isUsed:1;
	unsigned int Manifest_isUsed:1;
	unsigned int Reference_isUsed:1;
	unsigned int CanonicalizationMethod_isUsed:1;
	unsigned int RSAKeyValue_isUsed:1;
	unsigned int Transform_isUsed:1;
	unsigned int PGPData_isUsed:1;
	unsigned int MgmtData_isUsed:1;
	unsigned int SignatureMethod_isUsed:1;
	unsigned int KeyInfo_isUsed:1;
	unsigned int SPKIData_isUsed:1;
	unsigned int X509Data_isUsed:1;
	unsigned int SignatureValue_isUsed:1;
	unsigned int KeyName_isUsed:1;
	unsigned int DigestValue_isUsed:1;
	unsigned int SignedInfo_isUsed:1;
	unsigned int Object_isUsed:1;
	int _warning_;
};

/**********Struct init****/

void init_v2gEXIDocument(struct v2gEXIDocument* exiDoc);
void init_v2gBodyType(struct v2gBodyType* v2gBodyType);
void init_v2gEXIDocument(struct v2gEXIDocument* exiDoc);
void init_v2gChargeParameterDiscoveryReqType(struct v2gChargeParameterDiscoveryReqType* v2gChargeParameterDiscoveryReqType);
void init_v2gChargeParameterDiscoveryResType(struct v2gChargeParameterDiscoveryResType* v2gChargeParameterDiscoveryResType);
void init_v2gDC_EVChargeParameterType(struct v2gDC_EVChargeParameterType* v2gDC_EVChargeParameterType);
void init_v2gCurrentDemandReqType(struct v2gCurrentDemandReqType* v2gCurrentDemandReqType);
void init_v2gDSAKeyValueType(struct v2gDSAKeyValueType* v2gDSAKeyValueType);
void init_v2gSalesTariffType(struct v2gSalesTariffType* v2gSalesTariffType);
void init_v2gSalesTariffEntryType(struct v2gSalesTariffEntryType* v2gSalesTariffEntryType);
void init_v2gChargingStatusResType(struct v2gChargingStatusResType* v2gChargingStatusResType);
void init_v2gMeterInfoType(struct v2gMeterInfoType* v2gMeterInfoType);
void init_v2gCurrentDemandReqType(struct v2gCurrentDemandReqType* v2gCurrentDemandReqType);
void init_v2gCurrentDemandResType(struct v2gCurrentDemandResType* v2gCurrentDemandResType);
void init_v2gDSAKeyValueType(struct v2gDSAKeyValueType* v2gDSAKeyValueType);
void init_v2gKeyInfoType(struct v2gKeyInfoType* v2gKeyInfoType);
void init_v2gX509DataType(struct v2gX509DataType* v2gX509DataType);
void init_v2gParameterType(struct v2gParameterType* v2gParameterType);
void init_v2gReferenceType(struct v2gReferenceType* v2gReferenceType);









#endif /* DEPLOY_ISO_CODEC */

#ifdef __cplusplus
}
#endif

#endif /* ISO_COMM_CODEC_V2GEXIDATATYPES_H_ */
