/*
 * v2gEXIDatatypesEncoderReq.c
 *
 *  Created on: 12.02.2016
 *      Author: melanie
 */


# include "v2gEXIDatatypesEncoder.h"


/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,AC_EVChargeParameterType',  base type name='EVChargeParameterType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":DepartureTime{0-1}),("urn:iso:15118:2:2013:MsgDataTypes":EAmount,"urn:iso:15118:2:2013:MsgDataTypes":EVMaxVoltage,"urn:iso:15118:2:2013:MsgDataTypes":EVMaxCurrent,"urn:iso:15118:2:2013:MsgDataTypes":EVMinCurrent))',  derivedBy='EXTENSION'.  */
int encode_v2gAC_EVChargeParameterType(bitstream_t* stream, struct v2gAC_EVChargeParameterType* v2gAC_EVChargeParameterType) {
	int grammarID = 202;
	int done = 0;
	int errn;


	while(!done) {
		switch(grammarID) {
		case 202:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DepartureTime), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EAmount)] */
			if ( v2gAC_EVChargeParameterType->DepartureTime_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger32(stream, v2gAC_EVChargeParameterType->DepartureTime);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 203;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gAC_EVChargeParameterType->EAmount );
				}
				grammarID = 204;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 203:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EAmount)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gAC_EVChargeParameterType->EAmount );
				}
				grammarID = 204;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 204:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVMaxVoltage)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gAC_EVChargeParameterType->EVMaxVoltage );
				}
				grammarID = 205;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 205:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVMaxCurrent)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gAC_EVChargeParameterType->EVMaxCurrent );
				}
				grammarID = 206;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 206:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVMinCurrent)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gAC_EVChargeParameterType->EVMinCurrent );
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,AuthorizationReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":GenChallenge{0-1})',  derivedBy='EXTENSION'.  */
int encode_v2gAuthorizationReqType(bitstream_t* stream, struct v2gAuthorizationReqType* v2gAuthorizationReqType) {
	int grammarID = 253;
	int done = 0;
	int errn;


	while(!done) {
		switch(grammarID) {
		case 253:
			/* FirstStartTag[ATTRIBUTE[STRING]({urn:iso:15118:2:2013:MsgBody}Id), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}GenChallenge), END_ELEMENT] */
			if ( v2gAuthorizationReqType->Id_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gAuthorizationReqType->Id.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gAuthorizationReqType->Id.characters, v2gAuthorizationReqType->Id.charactersLen);
					}
				}
				grammarID = 254;
			} else 			if ( v2gAuthorizationReqType->GenChallenge_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gAuthorizationReqType->GenChallenge.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gAuthorizationReqType->GenChallenge.bytes, v2gAuthorizationReqType->GenChallenge.bytesLen);
						}
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
		case 254:
			/* StartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}GenChallenge), END_ELEMENT] */
			if ( v2gAuthorizationReqType->GenChallenge_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gAuthorizationReqType->GenChallenge.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gAuthorizationReqType->GenChallenge.bytes, v2gAuthorizationReqType->GenChallenge.bytesLen);
						}
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,CableCheckReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":DC_EVStatus)',  derivedBy='EXTENSION'.  */
int encode_v2gCableCheckReqType(bitstream_t* stream, struct v2gCableCheckReqType* v2gCableCheckReqType) {
	int grammarID = 157;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 157:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}DC_EVStatus)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gDC_EVStatusType(stream, &v2gCableCheckReqType->DC_EVStatus );
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVStatusType',  base type name='EVStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":EVReady,"urn:iso:15118:2:2013:MsgDataTypes":EVErrorCode,"urn:iso:15118:2:2013:MsgDataTypes":EVRESSSOC)',  derivedBy='EXTENSION'.  */
int encode_v2gDC_EVStatusType(bitstream_t* stream, struct v2gDC_EVStatusType* v2gDC_EVStatusType) {
	int grammarID = 175;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 175:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVReady)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gDC_EVStatusType->EVReady);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 176;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 176:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVErrorCode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 4, v2gDC_EVStatusType->EVErrorCode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 177;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 177:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVRESSSOC)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 7, (uint32_t)(v2gDC_EVStatusType->EVRESSSOC - 0));
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,CertificateInstallationReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":OEMProvisioningCert,"urn:iso:15118:2:2013:MsgBody":ListOfRootCertificateIDs)',  derivedBy='EXTENSION'.  */
int encode_v2gCertificateInstallationReqType(bitstream_t* stream, struct v2gCertificateInstallationReqType* v2gCertificateInstallationReqType) {
	int grammarID = 210;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 210:
			/* FirstStartTag[ATTRIBUTE[STRING]({urn:iso:15118:2:2013:MsgBody}Id)] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gCertificateInstallationReqType->Id.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gCertificateInstallationReqType->Id.characters, v2gCertificateInstallationReqType->Id.charactersLen);
					}
				}
				grammarID = 211;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 211:
			/* StartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}OEMProvisioningCert)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gCertificateInstallationReqType->OEMProvisioningCert.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gCertificateInstallationReqType->OEMProvisioningCert.bytes, v2gCertificateInstallationReqType->OEMProvisioningCert.bytesLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 128;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 128:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ListOfRootCertificateIDs)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gListOfRootCertificateIDsType(stream, &v2gCertificateInstallationReqType->ListOfRootCertificateIDs );
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,CertificateUpdateReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ContractSignatureCertChain,"urn:iso:15118:2:2013:MsgBody":eMAID,"urn:iso:15118:2:2013:MsgBody":ListOfRootCertificateIDs)',  derivedBy='EXTENSION'.  */
int encode_v2gCertificateUpdateReqType(bitstream_t* stream, struct v2gCertificateUpdateReqType* v2gCertificateUpdateReqType) {
	int grammarID = 125;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 125:
			/* FirstStartTag[ATTRIBUTE[STRING]({urn:iso:15118:2:2013:MsgBody}Id)] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gCertificateUpdateReqType->Id.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gCertificateUpdateReqType->Id.characters, v2gCertificateUpdateReqType->Id.charactersLen);
					}
				}
				grammarID = 126;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 126:
			/* StartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ContractSignatureCertChain)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gCertificateChainType(stream, &v2gCertificateUpdateReqType->ContractSignatureCertChain );
				}
				grammarID = 127;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 127:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}eMAID)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gCertificateUpdateReqType->eMAID.charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gCertificateUpdateReqType->eMAID.characters, v2gCertificateUpdateReqType->eMAID.charactersLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 128;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 128:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ListOfRootCertificateIDs)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gListOfRootCertificateIDsType(stream, &v2gCertificateUpdateReqType->ListOfRootCertificateIDs );
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,ChargeParameterDiscoveryReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":MaxEntriesSAScheduleTuple{0-1},"urn:iso:15118:2:2013:MsgBody":RequestedEnergyTransferMode,"urn:iso:15118:2:2013:MsgDataTypes":EVChargeParameter)',  derivedBy='EXTENSION'.  */
int encode_v2gChargeParameterDiscoveryReqType(bitstream_t* stream, struct v2gChargeParameterDiscoveryReqType* v2gChargeParameterDiscoveryReqType) {
	int grammarID = 101;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 101:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}MaxEntriesSAScheduleTuple), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}RequestedEnergyTransferMode)] */
			if ( v2gChargeParameterDiscoveryReqType->MaxEntriesSAScheduleTuple_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, v2gChargeParameterDiscoveryReqType->MaxEntriesSAScheduleTuple);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 102;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 3, v2gChargeParameterDiscoveryReqType->RequestedEnergyTransferMode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 103;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 102:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}RequestedEnergyTransferMode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 3, v2gChargeParameterDiscoveryReqType->RequestedEnergyTransferMode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 103;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 103:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}AC_EVChargeParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVChargeParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVChargeParameter)] */
			if ( v2gChargeParameterDiscoveryReqType->AC_EVChargeParameter_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gAC_EVChargeParameterType(stream, &v2gChargeParameterDiscoveryReqType->AC_EVChargeParameter );
				}
				grammarID = 5;
			} else 			if ( v2gChargeParameterDiscoveryReqType->DC_EVChargeParameter_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gDC_EVChargeParameterType(stream, &v2gChargeParameterDiscoveryReqType->DC_EVChargeParameter );
				}
				grammarID = 5;
			} else 			if ( v2gChargeParameterDiscoveryReqType->EVChargeParameter_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 2);
				if(errn == 0) {
					errn = encode_v2gEVChargeParameterType(stream, &v2gChargeParameterDiscoveryReqType->EVChargeParameter );
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVChargeParameterType',  base type name='EVChargeParameterType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":DepartureTime{0-1}),("urn:iso:15118:2:2013:MsgDataTypes":DC_EVStatus,"urn:iso:15118:2:2013:MsgDataTypes":EVMaximumCurrentLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVMaximumPowerLimit{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVMaximumVoltageLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVEnergyCapacity{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVEnergyRequest{0-1},"urn:iso:15118:2:2013:MsgDataTypes":FullSOC{0-1},"urn:iso:15118:2:2013:MsgDataTypes":BulkSOC{0-1}))',  derivedBy='EXTENSION'.  */
int encode_v2gDC_EVChargeParameterType(bitstream_t* stream, struct v2gDC_EVChargeParameterType* v2gDC_EVChargeParameterType) {
	int grammarID = 86;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 86:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DepartureTime), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVStatus)] */
			if ( v2gDC_EVChargeParameterType->DepartureTime_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger32(stream, v2gDC_EVChargeParameterType->DepartureTime);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 87;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gDC_EVStatusType(stream, &v2gDC_EVChargeParameterType->DC_EVStatus );
				}
				grammarID = 88;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 87:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVStatus)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gDC_EVStatusType(stream, &v2gDC_EVChargeParameterType->DC_EVStatus );
				}
				grammarID = 88;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 88:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVMaximumCurrentLimit)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gDC_EVChargeParameterType->EVMaximumCurrentLimit );
				}
				grammarID = 89;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 89:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVMaximumPowerLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVMaximumVoltageLimit)] */
			if ( v2gDC_EVChargeParameterType->EVMaximumPowerLimit_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gDC_EVChargeParameterType->EVMaximumPowerLimit );
				}
				grammarID = 90;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gDC_EVChargeParameterType->EVMaximumVoltageLimit );
				}
				grammarID = 91;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 90:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVMaximumVoltageLimit)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gDC_EVChargeParameterType->EVMaximumVoltageLimit );
				}
				grammarID = 91;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 91:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVEnergyCapacity), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVEnergyRequest), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FullSOC), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}BulkSOC), END_ELEMENT] */
			if ( v2gDC_EVChargeParameterType->EVEnergyCapacity_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gDC_EVChargeParameterType->EVEnergyCapacity );
				}
				grammarID = 92;
			} else 			if ( v2gDC_EVChargeParameterType->EVEnergyRequest_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 1);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gDC_EVChargeParameterType->EVEnergyRequest );
				}
				grammarID = 93;
			} else 			if ( v2gDC_EVChargeParameterType->FullSOC_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 7, (uint32_t)(v2gDC_EVChargeParameterType->FullSOC - 0));
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 94;
			} else 			if ( v2gDC_EVChargeParameterType->BulkSOC_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 3);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 7, (uint32_t)(v2gDC_EVChargeParameterType->BulkSOC - 0));
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 5;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 3, 4);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 92:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVEnergyRequest), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FullSOC), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}BulkSOC), END_ELEMENT] */
			if ( v2gDC_EVChargeParameterType->EVEnergyRequest_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gDC_EVChargeParameterType->EVEnergyRequest );
				}
				grammarID = 93;
			} else 			if ( v2gDC_EVChargeParameterType->FullSOC_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 7, (uint32_t)(v2gDC_EVChargeParameterType->FullSOC - 0));
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 94;
			} else 			if ( v2gDC_EVChargeParameterType->BulkSOC_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 7, (uint32_t)(v2gDC_EVChargeParameterType->BulkSOC - 0));
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 5;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 3, 3);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 93:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FullSOC), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}BulkSOC), END_ELEMENT] */
			if ( v2gDC_EVChargeParameterType->FullSOC_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 7, (uint32_t)(v2gDC_EVChargeParameterType->FullSOC - 0));
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 94;
			} else 			if ( v2gDC_EVChargeParameterType->BulkSOC_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 7, (uint32_t)(v2gDC_EVChargeParameterType->BulkSOC - 0));
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
		case 94:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}BulkSOC), END_ELEMENT] */
			if ( v2gDC_EVChargeParameterType->BulkSOC_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 7, (uint32_t)(v2gDC_EVChargeParameterType->BulkSOC - 0));
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EVChargeParameterType',  base type name='anyType',  content type='ELEMENT',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":DepartureTime{0-1})',  derivedBy='RESTRICTION'.  */
int encode_v2gEVChargeParameterType(bitstream_t* stream, struct v2gEVChargeParameterType* v2gEVChargeParameterType) {
	int grammarID = 287;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 287:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DepartureTime), END_ELEMENT] */
			if ( v2gEVChargeParameterType->DepartureTime_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger32(stream, v2gEVChargeParameterType->DepartureTime);
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,ChargingStatusReqType',  base type name='BodyBaseType',  content type='EMPTY',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  derivedBy='EXTENSION'.  */
int encode_v2gChargingStatusReqType(bitstream_t* stream, struct v2gChargingStatusReqType* v2gChargingStatusReqType) {
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,CurrentDemandReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":DC_EVStatus,"urn:iso:15118:2:2013:MsgBody":EVTargetCurrent,"urn:iso:15118:2:2013:MsgBody":EVMaximumVoltageLimit{0-1},"urn:iso:15118:2:2013:MsgBody":EVMaximumCurrentLimit{0-1},"urn:iso:15118:2:2013:MsgBody":EVMaximumPowerLimit{0-1},"urn:iso:15118:2:2013:MsgBody":BulkChargingComplete{0-1},"urn:iso:15118:2:2013:MsgBody":ChargingComplete,"urn:iso:15118:2:2013:MsgBody":RemainingTimeToFullSoC{0-1},"urn:iso:15118:2:2013:MsgBody":RemainingTimeToBulkSoC{0-1},"urn:iso:15118:2:2013:MsgBody":EVTargetVoltage)',  derivedBy='EXTENSION'.  */
int encode_v2gCurrentDemandReqType(bitstream_t* stream, struct v2gCurrentDemandReqType* v2gCurrentDemandReqType) {
	int grammarID = 165;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 165:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}DC_EVStatus)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gDC_EVStatusType(stream, &v2gCurrentDemandReqType->DC_EVStatus );
				}
				grammarID = 166;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 166:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVTargetCurrent)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->EVTargetCurrent );
				}
				grammarID = 167;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 167:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVMaximumVoltageLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVMaximumCurrentLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVMaximumPowerLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}BulkChargingComplete), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingComplete)] */
			if ( v2gCurrentDemandReqType->EVMaximumVoltageLimit_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->EVMaximumVoltageLimit );
				}
				grammarID = 168;
			} else 			if ( v2gCurrentDemandReqType->EVMaximumCurrentLimit_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 1);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->EVMaximumCurrentLimit );
				}
				grammarID = 169;
			} else 			if ( v2gCurrentDemandReqType->EVMaximumPowerLimit_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->EVMaximumPowerLimit );
				}
				grammarID = 170;
			} else 			if ( v2gCurrentDemandReqType->BulkChargingComplete_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 3);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gCurrentDemandReqType->BulkChargingComplete);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 171;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 4);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gCurrentDemandReqType->ChargingComplete);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 172;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 168:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVMaximumCurrentLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVMaximumPowerLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}BulkChargingComplete), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingComplete)] */
			if ( v2gCurrentDemandReqType->EVMaximumCurrentLimit_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->EVMaximumCurrentLimit );
				}
				grammarID = 169;
			} else 			if ( v2gCurrentDemandReqType->EVMaximumPowerLimit_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 1);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->EVMaximumPowerLimit );
				}
				grammarID = 170;
			} else 			if ( v2gCurrentDemandReqType->BulkChargingComplete_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gCurrentDemandReqType->BulkChargingComplete);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 171;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 3);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gCurrentDemandReqType->ChargingComplete);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 172;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 169:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVMaximumPowerLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}BulkChargingComplete), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingComplete)] */
			if ( v2gCurrentDemandReqType->EVMaximumPowerLimit_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->EVMaximumPowerLimit );
				}
				grammarID = 170;
			} else 			if ( v2gCurrentDemandReqType->BulkChargingComplete_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gCurrentDemandReqType->BulkChargingComplete);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 171;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 2);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gCurrentDemandReqType->ChargingComplete);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 172;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 170:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}BulkChargingComplete), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingComplete)] */
			if ( v2gCurrentDemandReqType->BulkChargingComplete_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gCurrentDemandReqType->BulkChargingComplete);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 171;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gCurrentDemandReqType->ChargingComplete);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 172;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 171:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingComplete)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gCurrentDemandReqType->ChargingComplete);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 172;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 172:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}RemainingTimeToFullSoC), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}RemainingTimeToBulkSoC), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVTargetVoltage)] */
			if ( v2gCurrentDemandReqType->RemainingTimeToFullSoC_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->RemainingTimeToFullSoC );
				}
				grammarID = 173;
			} else 			if ( v2gCurrentDemandReqType->RemainingTimeToBulkSoC_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->RemainingTimeToBulkSoC );
				}
				grammarID = 174;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 2);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->EVTargetVoltage );
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 173:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}RemainingTimeToBulkSoC), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVTargetVoltage)] */
			if ( v2gCurrentDemandReqType->RemainingTimeToBulkSoC_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->RemainingTimeToBulkSoC );
				}
				grammarID = 174;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->EVTargetVoltage );
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 174:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVTargetVoltage)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->EVTargetVoltage );
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVPowerDeliveryParameterType',  base type name='EVPowerDeliveryParameterType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":DC_EVStatus,"urn:iso:15118:2:2013:MsgDataTypes":BulkChargingComplete{0-1},"urn:iso:15118:2:2013:MsgDataTypes":ChargingComplete)',  derivedBy='EXTENSION'.  */
int encode_v2gDC_EVPowerDeliveryParameterType(bitstream_t* stream, struct v2gDC_EVPowerDeliveryParameterType* v2gDC_EVPowerDeliveryParameterType) {
	int grammarID = 2;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 2:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVStatus)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gDC_EVStatusType(stream, &v2gDC_EVPowerDeliveryParameterType->DC_EVStatus );
				}
				grammarID = 3;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 3:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}BulkChargingComplete), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ChargingComplete)] */
			if ( v2gDC_EVPowerDeliveryParameterType->BulkChargingComplete_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gDC_EVPowerDeliveryParameterType->BulkChargingComplete);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 4;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gDC_EVPowerDeliveryParameterType->ChargingComplete);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 4:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ChargingComplete)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gDC_EVPowerDeliveryParameterType->ChargingComplete);
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EVStatusType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
int encode_v2gEVStatusType(bitstream_t* stream, struct v2gEVStatusType* v2gEVStatusType) {
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,MeteringReceiptReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":SessionID,"urn:iso:15118:2:2013:MsgBody":SAScheduleTupleID{0-1},"urn:iso:15118:2:2013:MsgBody":MeterInfo)',  derivedBy='EXTENSION'.  */
int encode_v2gMeteringReceiptReqType(bitstream_t* stream, struct v2gMeteringReceiptReqType* v2gMeteringReceiptReqType) {
	int grammarID = 97;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 97:
			/* FirstStartTag[ATTRIBUTE[STRING]({urn:iso:15118:2:2013:MsgBody}Id), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionID)] */
			if ( v2gMeteringReceiptReqType->Id_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gMeteringReceiptReqType->Id.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gMeteringReceiptReqType->Id.characters, v2gMeteringReceiptReqType->Id.charactersLen);
					}
				}
				grammarID = 98;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_HEX]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gMeteringReceiptReqType->SessionID.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gMeteringReceiptReqType->SessionID.bytes, v2gMeteringReceiptReqType->SessionID.bytesLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 99;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 98:
			/* StartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionID)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_HEX]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gMeteringReceiptReqType->SessionID.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gMeteringReceiptReqType->SessionID.bytes, v2gMeteringReceiptReqType->SessionID.bytesLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 99;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 99:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SAScheduleTupleID), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}MeterInfo)] */
			if ( v2gMeteringReceiptReqType->SAScheduleTupleID_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 8, (uint32_t)(v2gMeteringReceiptReqType->SAScheduleTupleID - 1));
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 100;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gMeterInfoType(stream, &v2gMeteringReceiptReqType->MeterInfo );
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 100:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}MeterInfo)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gMeterInfoType(stream, &v2gMeteringReceiptReqType->MeterInfo );
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,PaymentDetailsReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":eMAID,"urn:iso:15118:2:2013:MsgBody":ContractSignatureCertChain)',  derivedBy='EXTENSION'.  */
int encode_v2gPaymentDetailsReqType(bitstream_t* stream, struct v2gPaymentDetailsReqType* v2gPaymentDetailsReqType) {
	int grammarID = 140;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 140:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}eMAID)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gPaymentDetailsReqType->eMAID.charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gPaymentDetailsReqType->eMAID.characters, v2gPaymentDetailsReqType->eMAID.charactersLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 141;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 141:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ContractSignatureCertChain)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gCertificateChainType(stream, &v2gPaymentDetailsReqType->ContractSignatureCertChain );
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,PaymentServiceSelectionReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":SelectedPaymentOption,"urn:iso:15118:2:2013:MsgBody":SelectedServiceList)',  derivedBy='EXTENSION'.  */
int encode_v2gPaymentServiceSelectionReqType(bitstream_t* stream, struct v2gPaymentServiceSelectionReqType* v2gPaymentServiceSelectionReqType) {
	int grammarID = 37;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 37:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SelectedPaymentOption)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 1, v2gPaymentServiceSelectionReqType->SelectedPaymentOption);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 38;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 38:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SelectedServiceList)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gSelectedServiceListType(stream, &v2gPaymentServiceSelectionReqType->SelectedServiceList );
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,PowerDeliveryReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ChargeProgress,"urn:iso:15118:2:2013:MsgBody":SAScheduleTupleID,"urn:iso:15118:2:2013:MsgBody":ChargingProfile{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVPowerDeliveryParameter{0-1})',  derivedBy='EXTENSION'.  */
int encode_v2gPowerDeliveryReqType(bitstream_t* stream, struct v2gPowerDeliveryReqType* v2gPowerDeliveryReqType) {
	int grammarID = 78;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 78:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargeProgress)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 2, v2gPowerDeliveryReqType->ChargeProgress);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 79;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 79:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SAScheduleTupleID)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 8, (uint32_t)(v2gPowerDeliveryReqType->SAScheduleTupleID - 1));
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 80;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 80:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingProfile), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVPowerDeliveryParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVPowerDeliveryParameter), END_ELEMENT] */
			if ( v2gPowerDeliveryReqType->ChargingProfile_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					errn = encode_v2gChargingProfileType(stream, &v2gPowerDeliveryReqType->ChargingProfile );
				}
				grammarID = 81;
			} else 			if ( v2gPowerDeliveryReqType->DC_EVPowerDeliveryParameter_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 1);
				if(errn == 0) {
					errn = encode_v2gDC_EVPowerDeliveryParameterType(stream, &v2gPowerDeliveryReqType->DC_EVPowerDeliveryParameter );
				}
				grammarID = 5;
			} else 			if ( v2gPowerDeliveryReqType->EVPowerDeliveryParameter_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					errn = encode_v2gEVPowerDeliveryParameterType(stream, &v2gPowerDeliveryReqType->EVPowerDeliveryParameter );
				}
				grammarID = 5;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 3, 3);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 81:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVPowerDeliveryParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVPowerDeliveryParameter), END_ELEMENT] */
			if ( v2gPowerDeliveryReqType->DC_EVPowerDeliveryParameter_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gDC_EVPowerDeliveryParameterType(stream, &v2gPowerDeliveryReqType->DC_EVPowerDeliveryParameter );
				}
				grammarID = 5;
			} else 			if ( v2gPowerDeliveryReqType->EVPowerDeliveryParameter_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gEVPowerDeliveryParameterType(stream, &v2gPowerDeliveryReqType->EVPowerDeliveryParameter );
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,PreChargeReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":DC_EVStatus,"urn:iso:15118:2:2013:MsgBody":EVTargetVoltage,"urn:iso:15118:2:2013:MsgBody":EVTargetCurrent)',  derivedBy='EXTENSION'.  */
int encode_v2gPreChargeReqType(bitstream_t* stream, struct v2gPreChargeReqType* v2gPreChargeReqType) {
	int grammarID = 288;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 288:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}DC_EVStatus)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gDC_EVStatusType(stream, &v2gPreChargeReqType->DC_EVStatus );
				}
				grammarID = 289;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 289:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVTargetVoltage)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gPreChargeReqType->EVTargetVoltage );
				}
				grammarID = 290;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 290:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVTargetCurrent)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gPreChargeReqType->EVTargetCurrent );
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,ServiceDetailReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ServiceID)',  derivedBy='EXTENSION'.  */
int encode_v2gServiceDetailReqType(bitstream_t* stream, struct v2gServiceDetailReqType* v2gServiceDetailReqType) {
	int grammarID = 121;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 121:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceID)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, v2gServiceDetailReqType->ServiceID);
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,ServiceDiscoveryReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ServiceScope{0-1},"urn:iso:15118:2:2013:MsgBody":ServiceCategory{0-1})',  derivedBy='EXTENSION'.  */
int encode_v2gServiceDiscoveryReqType(bitstream_t* stream, struct v2gServiceDiscoveryReqType* v2gServiceDiscoveryReqType) {
	int grammarID = 107;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 107:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceScope), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceCategory), END_ELEMENT] */
			if ( v2gServiceDiscoveryReqType->ServiceScope_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gServiceDiscoveryReqType->ServiceScope.charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gServiceDiscoveryReqType->ServiceScope.characters, v2gServiceDiscoveryReqType->ServiceScope.charactersLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 108;
			} else 			if ( v2gServiceDiscoveryReqType->ServiceCategory_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 2, v2gServiceDiscoveryReqType->ServiceCategory);
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
		case 108:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceCategory), END_ELEMENT] */
			if ( v2gServiceDiscoveryReqType->ServiceCategory_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 2, v2gServiceDiscoveryReqType->ServiceCategory);
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,SessionSetupReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":EVCCID)',  derivedBy='EXTENSION'.  */
int encode_v2gSessionSetupReqType(bitstream_t* stream, struct v2gSessionSetupReqType* v2gSessionSetupReqType) {
	int grammarID = 164;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 164:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVCCID)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_HEX]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gSessionSetupReqType->EVCCID.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gSessionSetupReqType->EVCCID.bytes, v2gSessionSetupReqType->EVCCID.bytesLen);
						}
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,SessionStopReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ChargingSession)',  derivedBy='EXTENSION'.  */
int encode_v2gSessionStopReqType(bitstream_t* stream, struct v2gSessionStopReqType* v2gSessionStopReqType) {
	int grammarID = 163;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 163:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingSession)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 1, v2gSessionStopReqType->ChargingSession);
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
/* Complex type name='urn:iso:15118:2:2013:MsgBody,WeldingDetectionReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":DC_EVStatus)',  derivedBy='EXTENSION'.  */
int encode_v2gWeldingDetectionReqType(bitstream_t* stream, struct v2gWeldingDetectionReqType* v2gWeldingDetectionReqType) {
	int grammarID = 157;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 157:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}DC_EVStatus)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gDC_EVStatusType(stream, &v2gWeldingDetectionReqType->DC_EVStatus );
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

