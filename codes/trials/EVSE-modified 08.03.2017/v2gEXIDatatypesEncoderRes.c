/*
 * v2gEXIDatatypesEncoderRes.c
 *
 *  Created on: 12.02.2016
 *      Author: melanie
 */


# include "v2gEXIDatatypesEncoder.h"

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,AC_EVSEChargeParameterType',  base type name='EVSEChargeParameterType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":AC_EVSEStatus,"urn:iso:15118:2:2013:MsgDataTypes":EVSENominalVoltage,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMaxCurrent)',  derivedBy='EXTENSION'.  */
int encode_v2gAC_EVSEChargeParameterType(bitstream_t* stream, struct v2gAC_EVSEChargeParameterType* v2gAC_EVSEChargeParameterType) {
	int grammarID = 122;
	int done = 0;
	int errn;


	while(!done) {
		switch(grammarID) {
		case 122:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}AC_EVSEStatus)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gAC_EVSEStatusType(stream, &v2gAC_EVSEChargeParameterType->AC_EVSEStatus );
				}
				grammarID = 123;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 123:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSENominalVoltage)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gAC_EVSEChargeParameterType->EVSENominalVoltage );
				}
				grammarID = 124;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 124:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEMaxCurrent)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gAC_EVSEChargeParameterType->EVSEMaxCurrent );
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,AC_EVSEStatusType',  base type name='EVSEStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification),("urn:iso:15118:2:2013:MsgDataTypes":RCD))',  derivedBy='EXTENSION'.  */
int encode_v2gAC_EVSEStatusType(bitstream_t* stream, struct v2gAC_EVSEStatusType* v2gAC_EVSEStatusType) {
	int grammarID = 20;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 20:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}NotificationMaxDelay)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, v2gAC_EVSEStatusType->NotificationMaxDelay);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 21;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 21:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSENotification)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 2, v2gAC_EVSEStatusType->EVSENotification);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 22;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 22:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}RCD)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gAC_EVSEStatusType->RCD);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgBody,AuthorizationResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":EVSEProcessing)',  derivedBy='EXTENSION'.  */
int encode_v2gAuthorizationResType(bitstream_t* stream, struct v2gAuthorizationResType* v2gAuthorizationResType) {
	int grammarID = 230;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 230:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 5, v2gAuthorizationResType->ResponseCode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 231;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 231:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEProcessing)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 2, v2gAuthorizationResType->EVSEProcessing);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgBody,CableCheckResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":DC_EVSEStatus,"urn:iso:15118:2:2013:MsgBody":EVSEProcessing)',  derivedBy='EXTENSION'.  */
int encode_v2gCableCheckResType(bitstream_t* stream, struct v2gCableCheckResType* v2gCableCheckResType) {
	int grammarID = 300;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 300:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 5, v2gCableCheckResType->ResponseCode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 301;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 301:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}DC_EVSEStatus)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gDC_EVSEStatusType(stream, &v2gCableCheckResType->DC_EVSEStatus );
				}
				grammarID = 231;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 231:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEProcessing)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 2, v2gCableCheckResType->EVSEProcessing);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVSEStatusType',  base type name='EVSEStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification),("urn:iso:15118:2:2013:MsgDataTypes":EVSEIsolationStatus{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVSEStatusCode))',  derivedBy='EXTENSION'.  */
int encode_v2gDC_EVSEStatusType(bitstream_t* stream, struct v2gDC_EVSEStatusType* v2gDC_EVSEStatusType) {
	int grammarID = 291;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 291:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}NotificationMaxDelay)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, v2gDC_EVSEStatusType->NotificationMaxDelay);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 292;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 292:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSENotification)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 2, v2gDC_EVSEStatusType->EVSENotification);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 293;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 293:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEIsolationStatus), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEStatusCode)] */
			if ( v2gDC_EVSEStatusType->EVSEIsolationStatus_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 3, v2gDC_EVSEStatusType->EVSEIsolationStatus);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 294;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 4, v2gDC_EVSEStatusType->EVSEStatusCode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 294:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEStatusCode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 4, v2gDC_EVSEStatusType->EVSEStatusCode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgBody,CertificateInstallationResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":SAProvisioningCertificateChain,"urn:iso:15118:2:2013:MsgBody":ContractSignatureCertChain,"urn:iso:15118:2:2013:MsgBody":ContractSignatureEncryptedPrivateKey,"urn:iso:15118:2:2013:MsgBody":DHpublickey,"urn:iso:15118:2:2013:MsgBody":eMAID)',  derivedBy='EXTENSION'.  */
int encode_v2gCertificateInstallationResType(bitstream_t* stream, struct v2gCertificateInstallationResType* v2gCertificateInstallationResType) {
	int grammarID = 151;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 151:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 5, v2gCertificateInstallationResType->ResponseCode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 152;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 152:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SAProvisioningCertificateChain)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gCertificateChainType(stream, &v2gCertificateInstallationResType->SAProvisioningCertificateChain );
				}
				grammarID = 153;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 153:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ContractSignatureCertChain)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gCertificateChainType(stream, &v2gCertificateInstallationResType->ContractSignatureCertChain );
				}
				grammarID = 154;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 154:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ContractSignatureEncryptedPrivateKey)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gContractSignatureEncryptedPrivateKeyType(stream, &v2gCertificateInstallationResType->ContractSignatureEncryptedPrivateKey );
				}
				grammarID = 155;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 155:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}DHpublickey)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gDiffieHellmanPublickeyType(stream, &v2gCertificateInstallationResType->DHpublickey );
				}
				grammarID = 156;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 156:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}eMAID)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gEMAIDType(stream, &v2gCertificateInstallationResType->eMAID );
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgBody,CertificateUpdateResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":SAProvisioningCertificateChain,"urn:iso:15118:2:2013:MsgBody":ContractSignatureCertChain,"urn:iso:15118:2:2013:MsgBody":ContractSignatureEncryptedPrivateKey,"urn:iso:15118:2:2013:MsgBody":DHpublickey,"urn:iso:15118:2:2013:MsgBody":eMAID,"urn:iso:15118:2:2013:MsgBody":RetryCounter{0-1})',  derivedBy='EXTENSION'.  */
int encode_v2gCertificateUpdateResType(bitstream_t* stream, struct v2gCertificateUpdateResType* v2gCertificateUpdateResType) {
	int grammarID = 144;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 144:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 5, v2gCertificateUpdateResType->ResponseCode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 145;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 145:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SAProvisioningCertificateChain)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gCertificateChainType(stream, &v2gCertificateUpdateResType->SAProvisioningCertificateChain );
				}
				grammarID = 146;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 146:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ContractSignatureCertChain)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gCertificateChainType(stream, &v2gCertificateUpdateResType->ContractSignatureCertChain );
				}
				grammarID = 147;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 147:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ContractSignatureEncryptedPrivateKey)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gContractSignatureEncryptedPrivateKeyType(stream, &v2gCertificateUpdateResType->ContractSignatureEncryptedPrivateKey );
				}
				grammarID = 148;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 148:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}DHpublickey)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gDiffieHellmanPublickeyType(stream, &v2gCertificateUpdateResType->DHpublickey );
				}
				grammarID = 149;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 149:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}eMAID)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gEMAIDType(stream, &v2gCertificateUpdateResType->eMAID );
				}
				grammarID = 150;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 150:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}RetryCounter), END_ELEMENT] */
			if ( v2gCertificateUpdateResType->RetryCounter_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeInteger16(stream, v2gCertificateUpdateResType->RetryCounter);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 5;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgBody,ChargeParameterDiscoveryResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":EVSEProcessing,"urn:iso:15118:2:2013:MsgDataTypes":SASchedules{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVSEChargeParameter)',  derivedBy='EXTENSION'.  */
int encode_v2gChargeParameterDiscoveryResType(bitstream_t* stream, struct v2gChargeParameterDiscoveryResType* v2gChargeParameterDiscoveryResType) {
	int grammarID = 307;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 307:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 5, v2gChargeParameterDiscoveryResType->ResponseCode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 308;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 308:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEProcessing)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 2, v2gChargeParameterDiscoveryResType->EVSEProcessing);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 309;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 309:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SAScheduleList), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SASchedules), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}AC_EVSEChargeParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVSEChargeParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEChargeParameter)] */
			if ( v2gChargeParameterDiscoveryResType->SAScheduleList_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					errn = encode_v2gSAScheduleListType(stream, &v2gChargeParameterDiscoveryResType->SAScheduleList );
				}
				grammarID = 310;
			} else 			if ( v2gChargeParameterDiscoveryResType->SASchedules_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 1);
				if(errn == 0) {
					errn = encode_v2gSASchedulesType(stream, &v2gChargeParameterDiscoveryResType->SASchedules );
				}
				grammarID = 310;
			} else 			if ( v2gChargeParameterDiscoveryResType->AC_EVSEChargeParameter_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					errn = encode_v2gAC_EVSEChargeParameterType(stream, &v2gChargeParameterDiscoveryResType->AC_EVSEChargeParameter );
				}
				grammarID = 5;
			} else 			if ( v2gChargeParameterDiscoveryResType->DC_EVSEChargeParameter_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 3);
				if(errn == 0) {
					errn = encode_v2gDC_EVSEChargeParameterType(stream, &v2gChargeParameterDiscoveryResType->DC_EVSEChargeParameter );
				}
				grammarID = 5;
			} else 			if ( v2gChargeParameterDiscoveryResType->EVSEChargeParameter_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 4);
				if(errn == 0) {
					errn = encode_v2gEVSEChargeParameterType(stream, &v2gChargeParameterDiscoveryResType->EVSEChargeParameter );
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 310:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}AC_EVSEChargeParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVSEChargeParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEChargeParameter)] */
			if ( v2gChargeParameterDiscoveryResType->AC_EVSEChargeParameter_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gAC_EVSEChargeParameterType(stream, &v2gChargeParameterDiscoveryResType->AC_EVSEChargeParameter );
				}
				grammarID = 5;
			} else 			if ( v2gChargeParameterDiscoveryResType->DC_EVSEChargeParameter_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gDC_EVSEChargeParameterType(stream, &v2gChargeParameterDiscoveryResType->DC_EVSEChargeParameter );
				}
				grammarID = 5;
			} else 			if ( v2gChargeParameterDiscoveryResType->EVSEChargeParameter_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 2);
				if(errn == 0) {
					errn = encode_v2gEVSEChargeParameterType(stream, &v2gChargeParameterDiscoveryResType->EVSEChargeParameter );
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVSEChargeParameterType',  base type name='EVSEChargeParameterType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":DC_EVSEStatus,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMaximumCurrentLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMaximumPowerLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMaximumVoltageLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMinimumCurrentLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMinimumVoltageLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVSECurrentRegulationTolerance{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVSEPeakCurrentRipple,"urn:iso:15118:2:2013:MsgDataTypes":EVSEEnergyToBeDelivered{0-1})',  derivedBy='EXTENSION'.  */
int encode_v2gDC_EVSEChargeParameterType(bitstream_t* stream, struct v2gDC_EVSEChargeParameterType* v2gDC_EVSEChargeParameterType) {
	int grammarID = 255;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 255:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVSEStatus)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gDC_EVSEStatusType(stream, &v2gDC_EVSEChargeParameterType->DC_EVSEStatus );
				}
				grammarID = 256;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 256:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEMaximumCurrentLimit)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gDC_EVSEChargeParameterType->EVSEMaximumCurrentLimit );
				}
				grammarID = 257;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 257:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEMaximumPowerLimit)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gDC_EVSEChargeParameterType->EVSEMaximumPowerLimit );
				}
				grammarID = 258;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 258:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEMaximumVoltageLimit)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gDC_EVSEChargeParameterType->EVSEMaximumVoltageLimit );
				}
				grammarID = 259;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 259:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEMinimumCurrentLimit)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gDC_EVSEChargeParameterType->EVSEMinimumCurrentLimit );
				}
				grammarID = 260;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 260:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEMinimumVoltageLimit)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gDC_EVSEChargeParameterType->EVSEMinimumVoltageLimit );
				}
				grammarID = 261;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 261:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSECurrentRegulationTolerance), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEPeakCurrentRipple)] */
			if ( v2gDC_EVSEChargeParameterType->EVSECurrentRegulationTolerance_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gDC_EVSEChargeParameterType->EVSECurrentRegulationTolerance );
				}
				grammarID = 262;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gDC_EVSEChargeParameterType->EVSEPeakCurrentRipple );
				}
				grammarID = 263;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 262:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEPeakCurrentRipple)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gDC_EVSEChargeParameterType->EVSEPeakCurrentRipple );
				}
				grammarID = 263;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 263:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEEnergyToBeDelivered), END_ELEMENT] */
			if ( v2gDC_EVSEChargeParameterType->EVSEEnergyToBeDelivered_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gDC_EVSEChargeParameterType->EVSEEnergyToBeDelivered );
				}
				grammarID = 5;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EVSEChargeParameterType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
int encode_v2gEVSEChargeParameterType(bitstream_t* stream, struct v2gEVSEChargeParameterType* v2gEVSEChargeParameterType) {
	int grammarID = 0;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 0:
			/* FirstStartTag[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgBody,ChargingStatusResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":EVSEID,"urn:iso:15118:2:2013:MsgBody":SAScheduleTupleID,"urn:iso:15118:2:2013:MsgBody":EVSEMaxCurrent{0-1},"urn:iso:15118:2:2013:MsgBody":MeterInfo{0-1},"urn:iso:15118:2:2013:MsgBody":ReceiptRequired{0-1},"urn:iso:15118:2:2013:MsgBody":AC_EVSEStatus)',  derivedBy='EXTENSION'.  */
int encode_v2gChargingStatusResType(bitstream_t* stream, struct v2gChargingStatusResType* v2gChargingStatusResType) {
	int grammarID = 185;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 185:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 5, v2gChargingStatusResType->ResponseCode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 186;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 186:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEID)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gChargingStatusResType->EVSEID.charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gChargingStatusResType->EVSEID.characters, v2gChargingStatusResType->EVSEID.charactersLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 187;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 187:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SAScheduleTupleID)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 8, (uint32_t)(v2gChargingStatusResType->SAScheduleTupleID - 1));
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 188;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 188:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEMaxCurrent), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}MeterInfo), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ReceiptRequired), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}AC_EVSEStatus)] */
			if ( v2gChargingStatusResType->EVSEMaxCurrent_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gChargingStatusResType->EVSEMaxCurrent );
				}
				grammarID = 189;
			} else 			if ( v2gChargingStatusResType->MeterInfo_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 1);
				if(errn == 0) {
					errn = encode_v2gMeterInfoType(stream, &v2gChargingStatusResType->MeterInfo );
				}
				grammarID = 190;
			} else 			if ( v2gChargingStatusResType->ReceiptRequired_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gChargingStatusResType->ReceiptRequired);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 191;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 3);
				if(errn == 0) {
					errn = encode_v2gAC_EVSEStatusType(stream, &v2gChargingStatusResType->AC_EVSEStatus );
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 189:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}MeterInfo), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ReceiptRequired), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}AC_EVSEStatus)] */
			if ( v2gChargingStatusResType->MeterInfo_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gMeterInfoType(stream, &v2gChargingStatusResType->MeterInfo );
				}
				grammarID = 190;
			} else 			if ( v2gChargingStatusResType->ReceiptRequired_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gChargingStatusResType->ReceiptRequired);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 191;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 2);
				if(errn == 0) {
					errn = encode_v2gAC_EVSEStatusType(stream, &v2gChargingStatusResType->AC_EVSEStatus );
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 190:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ReceiptRequired), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}AC_EVSEStatus)] */
			if ( v2gChargingStatusResType->ReceiptRequired_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gChargingStatusResType->ReceiptRequired);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 191;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gAC_EVSEStatusType(stream, &v2gChargingStatusResType->AC_EVSEStatus );
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 191:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}AC_EVSEStatus)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gAC_EVSEStatusType(stream, &v2gChargingStatusResType->AC_EVSEStatus );
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgBody,CurrentDemandResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":DC_EVSEStatus,"urn:iso:15118:2:2013:MsgBody":EVSEPresentVoltage,"urn:iso:15118:2:2013:MsgBody":EVSEPresentCurrent,"urn:iso:15118:2:2013:MsgBody":EVSECurrentLimitAchieved,"urn:iso:15118:2:2013:MsgBody":EVSEVoltageLimitAchieved,"urn:iso:15118:2:2013:MsgBody":EVSEPowerLimitAchieved,"urn:iso:15118:2:2013:MsgBody":EVSEMaximumVoltageLimit{0-1},"urn:iso:15118:2:2013:MsgBody":EVSEMaximumCurrentLimit{0-1},"urn:iso:15118:2:2013:MsgBody":EVSEMaximumPowerLimit{0-1},"urn:iso:15118:2:2013:MsgBody":EVSEID,"urn:iso:15118:2:2013:MsgBody":SAScheduleTupleID,"urn:iso:15118:2:2013:MsgBody":MeterInfo{0-1},"urn:iso:15118:2:2013:MsgBody":ReceiptRequired{0-1})',  derivedBy='EXTENSION'.  */
int encode_v2gCurrentDemandResType(bitstream_t* stream, struct v2gCurrentDemandResType* v2gCurrentDemandResType) {
	int grammarID = 6;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 6:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 5, v2gCurrentDemandResType->ResponseCode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 7;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 7:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}DC_EVSEStatus)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gDC_EVSEStatusType(stream, &v2gCurrentDemandResType->DC_EVSEStatus );
				}
				grammarID = 8;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 8:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEPresentVoltage)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gCurrentDemandResType->EVSEPresentVoltage );
				}
				grammarID = 9;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 9:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEPresentCurrent)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gCurrentDemandResType->EVSEPresentCurrent );
				}
				grammarID = 10;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 10:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSECurrentLimitAchieved)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gCurrentDemandResType->EVSECurrentLimitAchieved);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 11;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 11:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEVoltageLimitAchieved)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gCurrentDemandResType->EVSEVoltageLimitAchieved);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 12;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 12:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEPowerLimitAchieved)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gCurrentDemandResType->EVSEPowerLimitAchieved);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 13;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 13:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEMaximumVoltageLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEMaximumCurrentLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEMaximumPowerLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEID)] */
			if ( v2gCurrentDemandResType->EVSEMaximumVoltageLimit_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gCurrentDemandResType->EVSEMaximumVoltageLimit );
				}
				grammarID = 14;
			} else 			if ( v2gCurrentDemandResType->EVSEMaximumCurrentLimit_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 1);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gCurrentDemandResType->EVSEMaximumCurrentLimit );
				}
				grammarID = 15;
			} else 			if ( v2gCurrentDemandResType->EVSEMaximumPowerLimit_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gCurrentDemandResType->EVSEMaximumPowerLimit );
				}
				grammarID = 16;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 3);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gCurrentDemandResType->EVSEID.charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gCurrentDemandResType->EVSEID.characters, v2gCurrentDemandResType->EVSEID.charactersLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 17;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 14:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEMaximumCurrentLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEMaximumPowerLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEID)] */
			if ( v2gCurrentDemandResType->EVSEMaximumCurrentLimit_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gCurrentDemandResType->EVSEMaximumCurrentLimit );
				}
				grammarID = 15;
			} else 			if ( v2gCurrentDemandResType->EVSEMaximumPowerLimit_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gCurrentDemandResType->EVSEMaximumPowerLimit );
				}
				grammarID = 16;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 2);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gCurrentDemandResType->EVSEID.charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gCurrentDemandResType->EVSEID.characters, v2gCurrentDemandResType->EVSEID.charactersLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 17;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 15:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEMaximumPowerLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEID)] */
			if ( v2gCurrentDemandResType->EVSEMaximumPowerLimit_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gCurrentDemandResType->EVSEMaximumPowerLimit );
				}
				grammarID = 16;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gCurrentDemandResType->EVSEID.charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gCurrentDemandResType->EVSEID.characters, v2gCurrentDemandResType->EVSEID.charactersLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 17;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 16:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEID)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gCurrentDemandResType->EVSEID.charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gCurrentDemandResType->EVSEID.characters, v2gCurrentDemandResType->EVSEID.charactersLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 17;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 17:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SAScheduleTupleID)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 8, (uint32_t)(v2gCurrentDemandResType->SAScheduleTupleID - 1));
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 18;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 18:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}MeterInfo), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ReceiptRequired), END_ELEMENT] */
			if ( v2gCurrentDemandResType->MeterInfo_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gMeterInfoType(stream, &v2gCurrentDemandResType->MeterInfo );
				}
				grammarID = 19;
			} else 			if ( v2gCurrentDemandResType->ReceiptRequired_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gCurrentDemandResType->ReceiptRequired);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 5;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 2, 2);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 19:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ReceiptRequired), END_ELEMENT] */
			if ( v2gCurrentDemandResType->ReceiptRequired_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gCurrentDemandResType->ReceiptRequired);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 5;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EVSEStatusType',  base type name='anyType',  content type='ELEMENT',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification)',  derivedBy='RESTRICTION'.  */
int encode_v2gEVSEStatusType(bitstream_t* stream, struct v2gEVSEStatusType* v2gEVSEStatusType) {
	int grammarID = 109;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 109:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}NotificationMaxDelay)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, v2gEVSEStatusType->NotificationMaxDelay);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 110;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 110:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSENotification)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 2, v2gEVSEStatusType->EVSENotification);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgBody,MeteringReceiptResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgDataTypes":EVSEStatus)',  derivedBy='EXTENSION'.  */
int encode_v2gMeteringReceiptResType(bitstream_t* stream, struct v2gMeteringReceiptResType* v2gMeteringReceiptResType) {
	int grammarID = 311;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 311:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 5, v2gMeteringReceiptResType->ResponseCode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 312;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 312:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}AC_EVSEStatus), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVSEStatus), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEStatus)] */
			if ( v2gMeteringReceiptResType->AC_EVSEStatus_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gAC_EVSEStatusType(stream, &v2gMeteringReceiptResType->AC_EVSEStatus );
				}
				grammarID = 5;
			} else 			if ( v2gMeteringReceiptResType->DC_EVSEStatus_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gDC_EVSEStatusType(stream, &v2gMeteringReceiptResType->DC_EVSEStatus );
				}
				grammarID = 5;
			} else 			if ( v2gMeteringReceiptResType->EVSEStatus_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 2);
				if(errn == 0) {
					errn = encode_v2gEVSEStatusType(stream, &v2gMeteringReceiptResType->EVSEStatus );
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgBody,PaymentDetailsResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":GenChallenge,"urn:iso:15118:2:2013:MsgBody":EVSETimeStamp)',  derivedBy='EXTENSION'.  */
int encode_v2gPaymentDetailsResType(bitstream_t* stream, struct v2gPaymentDetailsResType* v2gPaymentDetailsResType) {
	int grammarID = 302;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 302:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 5, v2gPaymentDetailsResType->ResponseCode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 303;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 303:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}GenChallenge)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gPaymentDetailsResType->GenChallenge.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gPaymentDetailsResType->GenChallenge.bytes, v2gPaymentDetailsResType->GenChallenge.bytesLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 304;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 304:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSETimeStamp)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeInteger64(stream, v2gPaymentDetailsResType->EVSETimeStamp);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgBody,PaymentServiceSelectionResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode)',  derivedBy='EXTENSION'.  */
int encode_v2gPaymentServiceSelectionResType(bitstream_t* stream, struct v2gPaymentServiceSelectionResType* v2gPaymentServiceSelectionResType) {
	int grammarID = 54;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 54:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 5, v2gPaymentServiceSelectionResType->ResponseCode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgBody,PowerDeliveryResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgDataTypes":EVSEStatus)',  derivedBy='EXTENSION'.  */
int encode_v2gPowerDeliveryResType(bitstream_t* stream, struct v2gPowerDeliveryResType* v2gPowerDeliveryResType) {
	int grammarID = 311;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 311:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 5, v2gPowerDeliveryResType->ResponseCode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 312;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 312:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}AC_EVSEStatus), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVSEStatus), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEStatus)] */
			if ( v2gPowerDeliveryResType->AC_EVSEStatus_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gAC_EVSEStatusType(stream, &v2gPowerDeliveryResType->AC_EVSEStatus );
				}
				grammarID = 5;
			} else 			if ( v2gPowerDeliveryResType->DC_EVSEStatus_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gDC_EVSEStatusType(stream, &v2gPowerDeliveryResType->DC_EVSEStatus );
				}
				grammarID = 5;
			} else 			if ( v2gPowerDeliveryResType->EVSEStatus_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 2);
				if(errn == 0) {
					errn = encode_v2gEVSEStatusType(stream, &v2gPowerDeliveryResType->EVSEStatus );
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgBody,PreChargeResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":DC_EVSEStatus,"urn:iso:15118:2:2013:MsgBody":EVSEPresentVoltage)',  derivedBy='EXTENSION'.  */
int encode_v2gPreChargeResType(bitstream_t* stream, struct v2gPreChargeResType* v2gPreChargeResType) {
	int grammarID = 23;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 23:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 5, v2gPreChargeResType->ResponseCode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 24;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 24:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}DC_EVSEStatus)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gDC_EVSEStatusType(stream, &v2gPreChargeResType->DC_EVSEStatus );
				}
				grammarID = 25;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 25:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEPresentVoltage)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gPreChargeResType->EVSEPresentVoltage );
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgBody,ServiceDetailResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":ServiceID,"urn:iso:15118:2:2013:MsgBody":ServiceParameterList{0-1})',  derivedBy='EXTENSION'.  */
int encode_v2gServiceDetailResType(bitstream_t* stream, struct v2gServiceDetailResType* v2gServiceDetailResType) {
	int grammarID = 246;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 246:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 5, v2gServiceDetailResType->ResponseCode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 247;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 247:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceID)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, v2gServiceDetailResType->ServiceID);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 248;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 248:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceParameterList), END_ELEMENT] */
			if ( v2gServiceDetailResType->ServiceParameterList_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gServiceParameterListType(stream, &v2gServiceDetailResType->ServiceParameterList );
				}
				grammarID = 5;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgBody,ServiceDiscoveryResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":PaymentOptionList,"urn:iso:15118:2:2013:MsgBody":ChargeService,"urn:iso:15118:2:2013:MsgBody":ServiceList{0-1})',  derivedBy='EXTENSION'.  */
int encode_v2gServiceDiscoveryResType(bitstream_t* stream, struct v2gServiceDiscoveryResType* v2gServiceDiscoveryResType) {
	int grammarID = 136;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 136:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 5, v2gServiceDiscoveryResType->ResponseCode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 137;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 137:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PaymentOptionList)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPaymentOptionListType(stream, &v2gServiceDiscoveryResType->PaymentOptionList );
				}
				grammarID = 138;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 138:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargeService)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gChargeServiceType(stream, &v2gServiceDiscoveryResType->ChargeService );
				}
				grammarID = 139;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 139:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceList), END_ELEMENT] */
			if ( v2gServiceDiscoveryResType->ServiceList_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gServiceListType(stream, &v2gServiceDiscoveryResType->ServiceList );
				}
				grammarID = 5;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgBody,SessionSetupResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":EVSEID,"urn:iso:15118:2:2013:MsgBody":EVSETimeStamp{0-1})',  derivedBy='EXTENSION'.  */
int encode_v2gSessionSetupResType(bitstream_t* stream, struct v2gSessionSetupResType* v2gSessionSetupResType) {
	int grammarID = 215;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 215:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 5, v2gSessionSetupResType->ResponseCode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 216;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 216:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEID)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gSessionSetupResType->EVSEID.charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gSessionSetupResType->EVSEID.characters, v2gSessionSetupResType->EVSEID.charactersLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 217;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 217:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSETimeStamp), END_ELEMENT] */
			if ( v2gSessionSetupResType->EVSETimeStamp_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeInteger64(stream, v2gSessionSetupResType->EVSETimeStamp);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 5;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgBody,SessionStopResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode)',  derivedBy='EXTENSION'.  */
int encode_v2gSessionStopResType(bitstream_t* stream, struct v2gSessionStopResType* v2gSessionStopResType) {
	int grammarID = 54;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 54:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 5, v2gSessionStopResType->ResponseCode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}


/////////////////////////////////////////////////////aus general ausgerufen///////////////////////////////////////////
/* Complex type name='urn:iso:15118:2:2013:MsgBody,WeldingDetectionResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":DC_EVSEStatus,"urn:iso:15118:2:2013:MsgBody":EVSEPresentVoltage)',  derivedBy='EXTENSION'.  */
int encode_v2gWeldingDetectionResType(bitstream_t* stream, struct v2gWeldingDetectionResType* v2gWeldingDetectionResType) {
	int grammarID = 23;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 23:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 5, v2gWeldingDetectionResType->ResponseCode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 24;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 24:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}DC_EVSEStatus)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gDC_EVSEStatusType(stream, &v2gWeldingDetectionResType->DC_EVSEStatus );
				}
				grammarID = 25;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 25:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEPresentVoltage)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gWeldingDetectionResType->EVSEPresentVoltage );
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		default:
			errn = EXI_ERROR_UNKOWN_GRAMMAR_ID;
			break;
		}
		if(errn) {
			done = 1;
		}
	}
	return errn;
}
