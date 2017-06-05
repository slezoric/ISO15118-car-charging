/*
 * v2gEXIDatatypesDecoderReq.c
 *
 *  Created on: 10.02.2016
 *      Author: melanie
 */

/*Requests - EV*/
# include "ErrorCodes.h"
# include "DecoderChannel.h"
# include <stdio.h>
# include "v2gEXIDatatypesDecoder.h"
# include "v2gEXIDatatypes.h"

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,AC_EVChargeParameterType',  base type name='EVChargeParameterType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":DepartureTime{0-1}),("urn:iso:15118:2:2013:MsgDataTypes":EAmount,"urn:iso:15118:2:2013:MsgDataTypes":EVMaxVoltage,"urn:iso:15118:2:2013:MsgDataTypes":EVMaxCurrent,"urn:iso:15118:2:2013:MsgDataTypes":EVMinCurrent))',  derivedBy='EXTENSION'.  */
int decode_v2gAC_EVChargeParameterType(bitstream_t* stream, struct v2gAC_EVChargeParameterType* v2gAC_EVChargeParameterType, uint32_t eventCode) {
	int grammarID = 202;
	int done = 0;
	int errn;

	v2gAC_EVChargeParameterType->DepartureTime_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 202:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DepartureTime), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EAmount)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger32(stream, &v2gAC_EVChargeParameterType->DepartureTime);
							v2gAC_EVChargeParameterType->DepartureTime_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DepartureTime) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 203;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					errn = decode_v2gPhysicalValueType(stream, &v2gAC_EVChargeParameterType->EAmount, eventCode);
					grammarID = 204;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 203:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EAmount)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gAC_EVChargeParameterType->EAmount, eventCode);
					grammarID = 204;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 204:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVMaxVoltage)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gAC_EVChargeParameterType->EVMaxVoltage, eventCode);
					grammarID = 205;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 205:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVMaxCurrent)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gAC_EVChargeParameterType->EVMaxCurrent, eventCode);
					grammarID = 206;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 206:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVMinCurrent)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gAC_EVChargeParameterType->EVMinCurrent, eventCode);
					grammarID = 5;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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
int decode_v2gAuthorizationReqType(bitstream_t* stream, struct v2gAuthorizationReqType* v2gAuthorizationReqType, uint32_t eventCode) {
	int grammarID = 253;
	int done = 0;
	int errn;

	v2gAuthorizationReqType->Id_isUsed = 0u;
	v2gAuthorizationReqType->GenChallenge_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 253:
			/* FirstStartTag[ATTRIBUTE[STRING]({urn:iso:15118:2:2013:MsgBody}Id), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}GenChallenge), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gAuthorizationReqType->Id.charactersLen);
					if (errn == 0) {
						errn =  (v2gAuthorizationReqType->Id.charactersLen - 2) <= v2gAuthorizationReqType_Id_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gAuthorizationReqType->Id.charactersLen >= 2) {
							v2gAuthorizationReqType->Id.charactersLen = (uint16_t)(v2gAuthorizationReqType->Id.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gAuthorizationReqType->Id.charactersLen, v2gAuthorizationReqType->Id.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gAuthorizationReqType->Id_isUsed = 1u;
					grammarID = 254;
					break;
				case 1:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gAuthorizationReqType->GenChallenge.bytesLen);
							if (errn == 0) {
								errn =  (v2gAuthorizationReqType->GenChallenge.bytesLen) <= v2gAuthorizationReqType_GenChallenge_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gAuthorizationReqType->GenChallenge.bytesLen, v2gAuthorizationReqType->GenChallenge.bytes);
							}
							v2gAuthorizationReqType->GenChallenge_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}GenChallenge) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 5;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 2:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 254:
			/* StartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}GenChallenge), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gAuthorizationReqType->GenChallenge.bytesLen);
							if (errn == 0) {
								errn =  (v2gAuthorizationReqType->GenChallenge.bytesLen) <= v2gAuthorizationReqType_GenChallenge_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gAuthorizationReqType->GenChallenge.bytesLen, v2gAuthorizationReqType->GenChallenge.bytes);
							}
							v2gAuthorizationReqType->GenChallenge_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}GenChallenge) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 5;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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
int decode_v2gCableCheckReqType(bitstream_t* stream, struct v2gCableCheckReqType* v2gCableCheckReqType, uint32_t eventCode) {
	int grammarID = 157;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 157:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}DC_EVStatus)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gDC_EVStatusType(stream, &v2gCableCheckReqType->DC_EVStatus, eventCode);
					grammarID = 5;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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
int decode_v2gDC_EVStatusType(bitstream_t* stream, struct v2gDC_EVStatusType* v2gDC_EVStatusType,uint32_t eventCode) {
	int grammarID = 175;
	int done = 0;
	int errn;
	uint32_t uint32;

	while(!done) {
		switch(grammarID) {
		case 175:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVReady)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gDC_EVStatusType->EVReady);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVReady) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 176;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 176:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVErrorCode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 4, &uint32);
							v2gDC_EVStatusType->EVErrorCode = (v2gDC_EVErrorCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVErrorCode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 177;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 177:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVRESSSOC)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 7, &(uint32));
							v2gDC_EVStatusType->EVRESSSOC = (int8_t)(uint32 + 0);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVRESSSOC) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 5;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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
int decode_v2gCertificateInstallationReqType(bitstream_t* stream, struct v2gCertificateInstallationReqType* v2gCertificateInstallationReqType, uint32_t eventCode) {
	int grammarID = 210;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 210:
			/* FirstStartTag[ATTRIBUTE[STRING]({urn:iso:15118:2:2013:MsgBody}Id)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gCertificateInstallationReqType->Id.charactersLen);
					if (errn == 0) {
						errn =  (v2gCertificateInstallationReqType->Id.charactersLen - 2) <= v2gCertificateInstallationReqType_Id_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gCertificateInstallationReqType->Id.charactersLen >= 2) {
							v2gCertificateInstallationReqType->Id.charactersLen = (uint16_t)(v2gCertificateInstallationReqType->Id.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gCertificateInstallationReqType->Id.charactersLen, v2gCertificateInstallationReqType->Id.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					grammarID = 211;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 211:
			/* StartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}OEMProvisioningCert)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gCertificateInstallationReqType->OEMProvisioningCert.bytesLen);
							if (errn == 0) {
								errn =  (v2gCertificateInstallationReqType->OEMProvisioningCert.bytesLen) <= v2gCertificateInstallationReqType_OEMProvisioningCert_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gCertificateInstallationReqType->OEMProvisioningCert.bytesLen, v2gCertificateInstallationReqType->OEMProvisioningCert.bytes);
							}
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}OEMProvisioningCert) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 128;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 128:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ListOfRootCertificateIDs)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gListOfRootCertificateIDsType(stream, &v2gCertificateInstallationReqType->ListOfRootCertificateIDs, eventCode);
					grammarID = 5;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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
int decode_v2gCertificateUpdateReqType(bitstream_t* stream, struct v2gCertificateUpdateReqType* v2gCertificateUpdateReqType, uint32_t eventCode) {
	int grammarID = 125;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 125:
			/* FirstStartTag[ATTRIBUTE[STRING]({urn:iso:15118:2:2013:MsgBody}Id)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gCertificateUpdateReqType->Id.charactersLen);
					if (errn == 0) {
						errn =  (v2gCertificateUpdateReqType->Id.charactersLen - 2) <= v2gCertificateUpdateReqType_Id_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gCertificateUpdateReqType->Id.charactersLen >= 2) {
							v2gCertificateUpdateReqType->Id.charactersLen = (uint16_t)(v2gCertificateUpdateReqType->Id.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gCertificateUpdateReqType->Id.charactersLen, v2gCertificateUpdateReqType->Id.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					grammarID = 126;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 126:
			/* StartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ContractSignatureCertChain)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gCertificateChainType(stream, &v2gCertificateUpdateReqType->ContractSignatureCertChain, eventCode);
					grammarID = 127;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 127:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}eMAID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gCertificateUpdateReqType->eMAID.charactersLen);
							if (errn == 0) {
								errn =  (v2gCertificateUpdateReqType->eMAID.charactersLen - 2) <= v2gCertificateUpdateReqType_eMAID_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
							}
							if (errn == 0) {
								if (v2gCertificateUpdateReqType->eMAID.charactersLen >= 2) {
									v2gCertificateUpdateReqType->eMAID.charactersLen = (uint16_t)(v2gCertificateUpdateReqType->eMAID.charactersLen - 2); /* string table miss */
									errn = decodeCharacters(stream, v2gCertificateUpdateReqType->eMAID.charactersLen, v2gCertificateUpdateReqType->eMAID.characters);
								} else {
									/* string table hit */
									errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
								}
							}
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}eMAID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 128;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 128:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ListOfRootCertificateIDs)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gListOfRootCertificateIDsType(stream, &v2gCertificateUpdateReqType->ListOfRootCertificateIDs, eventCode);
					grammarID = 5;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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
int decode_v2gChargeParameterDiscoveryReqType(bitstream_t* stream, struct v2gChargeParameterDiscoveryReqType* v2gChargeParameterDiscoveryReqType, uint32_t eventCode) {
	int grammarID = 101;
	int done = 0;
	int errn;
	uint32_t uint32;

	init_v2gChargeParameterDiscoveryReqType(v2gChargeParameterDiscoveryReqType);

	while(!done) {
		switch(grammarID) {
		case 101:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}MaxEntriesSAScheduleTuple), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}RequestedEnergyTransferMode)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gChargeParameterDiscoveryReqType->MaxEntriesSAScheduleTuple);
							v2gChargeParameterDiscoveryReqType->MaxEntriesSAScheduleTuple_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}MaxEntriesSAScheduleTuple) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 102;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 3, &uint32);
							v2gChargeParameterDiscoveryReqType->RequestedEnergyTransferMode = (v2gEnergyTransferModeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}RequestedEnergyTransferMode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 103;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 102:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}RequestedEnergyTransferMode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 3, &uint32);
							v2gChargeParameterDiscoveryReqType->RequestedEnergyTransferMode = (v2gEnergyTransferModeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}RequestedEnergyTransferMode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 103;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 103:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}AC_EVChargeParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVChargeParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVChargeParameter)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gAC_EVChargeParameterType(stream, &v2gChargeParameterDiscoveryReqType->AC_EVChargeParameter, eventCode);
					v2gChargeParameterDiscoveryReqType->AC_EVChargeParameter_isUsed = 1u;
					grammarID = 5;
					break;
				case 1:
					errn = decode_v2gDC_EVChargeParameterType(stream, &v2gChargeParameterDiscoveryReqType->DC_EVChargeParameter, eventCode);
					v2gChargeParameterDiscoveryReqType->DC_EVChargeParameter_isUsed = 1u;
					grammarID = 5;
					break;
				case 2:
					errn = decode_v2gEVChargeParameterType(stream, &v2gChargeParameterDiscoveryReqType->EVChargeParameter, eventCode);
					v2gChargeParameterDiscoveryReqType->EVChargeParameter_isUsed = 1u;
					grammarID = 5;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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
int decode_v2gChargingStatusReqType(bitstream_t* stream, struct v2gChargingStatusReqType* v2gChargingStatusReqType, uint32_t eventCode) {
	int grammarID = 0;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 0:
			/* FirstStartTag[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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
int decode_v2gDC_EVChargeParameterType(bitstream_t* stream, struct v2gDC_EVChargeParameterType* v2gDC_EVChargeParameterType, uint32_t eventCode) {
	int grammarID = 86;
	int done = 0;
	int errn;
	uint32_t uint32;

	init_v2gDC_EVChargeParameterType(v2gDC_EVChargeParameterType);

	while(!done) {
		switch(grammarID) {
		case 86:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DepartureTime), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVStatus)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger32(stream, &v2gDC_EVChargeParameterType->DepartureTime);
							v2gDC_EVChargeParameterType->DepartureTime_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DepartureTime) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 87;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					errn = decode_v2gDC_EVStatusType(stream, &v2gDC_EVChargeParameterType->DC_EVStatus, eventCode);
					grammarID = 88;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 87:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVStatus)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gDC_EVStatusType(stream, &v2gDC_EVChargeParameterType->DC_EVStatus, eventCode);
					grammarID = 88;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 88:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVMaximumCurrentLimit)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gDC_EVChargeParameterType->EVMaximumCurrentLimit, eventCode);
					grammarID = 89;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 89:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVMaximumPowerLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVMaximumVoltageLimit)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gDC_EVChargeParameterType->EVMaximumPowerLimit, eventCode);
					v2gDC_EVChargeParameterType->EVMaximumPowerLimit_isUsed = 1u;
					grammarID = 90;
					break;
				case 1:
					errn = decode_v2gPhysicalValueType(stream, &v2gDC_EVChargeParameterType->EVMaximumVoltageLimit, eventCode);
					grammarID = 91;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 90:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVMaximumVoltageLimit)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gDC_EVChargeParameterType->EVMaximumVoltageLimit, eventCode);
					grammarID = 91;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 91:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVEnergyCapacity), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVEnergyRequest), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FullSOC), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}BulkSOC), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gDC_EVChargeParameterType->EVEnergyCapacity, eventCode);
					v2gDC_EVChargeParameterType->EVEnergyCapacity_isUsed = 1u;
					grammarID = 92;
					break;
				case 1:
					errn = decode_v2gPhysicalValueType(stream, &v2gDC_EVChargeParameterType->EVEnergyRequest, eventCode);
					v2gDC_EVChargeParameterType->EVEnergyRequest_isUsed = 1u;
					grammarID = 93;
					break;
				case 2:
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 7, &(uint32));
							v2gDC_EVChargeParameterType->FullSOC = (int8_t)(uint32 + 0);
							v2gDC_EVChargeParameterType->FullSOC_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FullSOC) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 94;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 3:
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 7, &(uint32));
							v2gDC_EVChargeParameterType->BulkSOC = (int8_t)(uint32 + 0);
							v2gDC_EVChargeParameterType->BulkSOC_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}BulkSOC) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 5;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 4:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 92:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVEnergyRequest), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FullSOC), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}BulkSOC), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gDC_EVChargeParameterType->EVEnergyRequest, eventCode);
					v2gDC_EVChargeParameterType->EVEnergyRequest_isUsed = 1u;
					grammarID = 93;
					break;
				case 1:
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 7, &(uint32));
							v2gDC_EVChargeParameterType->FullSOC = (int8_t)(uint32 + 0);
							v2gDC_EVChargeParameterType->FullSOC_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FullSOC) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 94;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 2:
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 7, &(uint32));
							v2gDC_EVChargeParameterType->BulkSOC = (int8_t)(uint32 + 0);
							v2gDC_EVChargeParameterType->BulkSOC_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}BulkSOC) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 5;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 3:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 93:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FullSOC), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}BulkSOC), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 7, &(uint32));
							v2gDC_EVChargeParameterType->FullSOC = (int8_t)(uint32 + 0);
							v2gDC_EVChargeParameterType->FullSOC_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FullSOC) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 94;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 7, &(uint32));
							v2gDC_EVChargeParameterType->BulkSOC = (int8_t)(uint32 + 0);
							v2gDC_EVChargeParameterType->BulkSOC_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}BulkSOC) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 5;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 2:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 94:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}BulkSOC), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 7, &(uint32));
							v2gDC_EVChargeParameterType->BulkSOC = (int8_t)(uint32 + 0);
							v2gDC_EVChargeParameterType->BulkSOC_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}BulkSOC) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 5;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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
int decode_v2gEVChargeParameterType(bitstream_t* stream, struct v2gEVChargeParameterType* v2gEVChargeParameterType, uint32_t eventCode) {
	int grammarID = 287;
	int done = 0;
	int errn;

	v2gEVChargeParameterType->DepartureTime_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 287:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DepartureTime), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger32(stream, &v2gEVChargeParameterType->DepartureTime);
							v2gEVChargeParameterType->DepartureTime_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DepartureTime) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 5;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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
int decode_v2gEVStatusType(bitstream_t* stream, struct v2gEVStatusType* v2gEVStatusType, uint32_t eventCode) {
	int grammarID = 0;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 0:
			/* FirstStartTag[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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
int decode_v2gCurrentDemandReqType(bitstream_t* stream, struct v2gCurrentDemandReqType* v2gCurrentDemandReqType, uint32_t eventCode) {
	int grammarID = 165;
	int done = 0;
	int errn;

	init_v2gCurrentDemandReqType(v2gCurrentDemandReqType);

	while(!done) {
		switch(grammarID) {
		case 165:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}DC_EVStatus)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gDC_EVStatusType(stream, &v2gCurrentDemandReqType->DC_EVStatus, eventCode);
					grammarID = 166;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 166:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVTargetCurrent)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->EVTargetCurrent, eventCode);
					grammarID = 167;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 167:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVMaximumVoltageLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVMaximumCurrentLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVMaximumPowerLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}BulkChargingComplete), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingComplete)] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->EVMaximumVoltageLimit, eventCode);
					v2gCurrentDemandReqType->EVMaximumVoltageLimit_isUsed = 1u;
					grammarID = 168;
					break;
				case 1:
					errn = decode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->EVMaximumCurrentLimit, eventCode);
					v2gCurrentDemandReqType->EVMaximumCurrentLimit_isUsed = 1u;
					grammarID = 169;
					break;
				case 2:
					errn = decode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->EVMaximumPowerLimit, eventCode);
					v2gCurrentDemandReqType->EVMaximumPowerLimit_isUsed = 1u;
					grammarID = 170;
					break;
				case 3:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gCurrentDemandReqType->BulkChargingComplete);
							v2gCurrentDemandReqType->BulkChargingComplete_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}BulkChargingComplete) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 171;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 4:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gCurrentDemandReqType->ChargingComplete);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingComplete) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 172;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 168:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVMaximumCurrentLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVMaximumPowerLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}BulkChargingComplete), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingComplete)] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->EVMaximumCurrentLimit, eventCode);
					v2gCurrentDemandReqType->EVMaximumCurrentLimit_isUsed = 1u;
					grammarID = 169;
					break;
				case 1:
					errn = decode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->EVMaximumPowerLimit, eventCode);
					v2gCurrentDemandReqType->EVMaximumPowerLimit_isUsed = 1u;
					grammarID = 170;
					break;
				case 2:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gCurrentDemandReqType->BulkChargingComplete);
							v2gCurrentDemandReqType->BulkChargingComplete_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}BulkChargingComplete) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 171;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 3:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gCurrentDemandReqType->ChargingComplete);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingComplete) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 172;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 169:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVMaximumPowerLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}BulkChargingComplete), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingComplete)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->EVMaximumPowerLimit, eventCode);
					v2gCurrentDemandReqType->EVMaximumPowerLimit_isUsed = 1u;
					grammarID = 170;
					break;
				case 1:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gCurrentDemandReqType->BulkChargingComplete);
							v2gCurrentDemandReqType->BulkChargingComplete_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}BulkChargingComplete) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 171;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 2:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gCurrentDemandReqType->ChargingComplete);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingComplete) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 172;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 170:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}BulkChargingComplete), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingComplete)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gCurrentDemandReqType->BulkChargingComplete);
							v2gCurrentDemandReqType->BulkChargingComplete_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}BulkChargingComplete) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 171;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gCurrentDemandReqType->ChargingComplete);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingComplete) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 172;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 171:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingComplete)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gCurrentDemandReqType->ChargingComplete);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingComplete) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 172;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 172:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}RemainingTimeToFullSoC), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}RemainingTimeToBulkSoC), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVTargetVoltage)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->RemainingTimeToFullSoC, eventCode);
					v2gCurrentDemandReqType->RemainingTimeToFullSoC_isUsed = 1u;
					grammarID = 173;
					break;
				case 1:
					errn = decode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->RemainingTimeToBulkSoC, eventCode);
					v2gCurrentDemandReqType->RemainingTimeToBulkSoC_isUsed = 1u;
					grammarID = 174;
					break;
				case 2:
					errn = decode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->EVTargetVoltage, eventCode);
					grammarID = 5;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 173:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}RemainingTimeToBulkSoC), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVTargetVoltage)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->RemainingTimeToBulkSoC, eventCode);
					v2gCurrentDemandReqType->RemainingTimeToBulkSoC_isUsed = 1u;
					grammarID = 174;
					break;
				case 1:
					errn = decode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->EVTargetVoltage, eventCode);
					grammarID = 5;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 174:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVTargetVoltage)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gCurrentDemandReqType->EVTargetVoltage, eventCode);
					grammarID = 5;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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

int decode_v2gDC_EVPowerDeliveryParameterType(bitstream_t* stream, struct v2gDC_EVPowerDeliveryParameterType* v2gDC_EVPowerDeliveryParameterType, uint32_t eventCode) {
	int grammarID = 2;
	int done = 0;
	int errn;

	v2gDC_EVPowerDeliveryParameterType->BulkChargingComplete_isUsed = 0u;
	while(!done) {
		switch(grammarID) {
		case 2:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVStatus)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gDC_EVStatusType(stream, &v2gDC_EVPowerDeliveryParameterType->DC_EVStatus, eventCode);
					grammarID = 3;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 3:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}BulkChargingComplete), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ChargingComplete)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gDC_EVPowerDeliveryParameterType->BulkChargingComplete);
							v2gDC_EVPowerDeliveryParameterType->BulkChargingComplete_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}BulkChargingComplete) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 4;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gDC_EVPowerDeliveryParameterType->ChargingComplete);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ChargingComplete) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 5;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 4:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ChargingComplete)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gDC_EVPowerDeliveryParameterType->ChargingComplete);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ChargingComplete) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 5;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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
int decode_v2gServiceDetailReqType(bitstream_t* stream, struct v2gServiceDetailReqType* v2gServiceDetailReqType, uint32_t eventCode) {
	int grammarID = 121;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 121:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gServiceDetailReqType->ServiceID);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 5;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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
int decode_v2gMeteringReceiptReqType(bitstream_t* stream, struct v2gMeteringReceiptReqType* v2gMeteringReceiptReqType, uint32_t eventCode) {
	int grammarID = 97;
	int done = 0;
	int errn;
	uint32_t uint32;

	v2gMeteringReceiptReqType->Id_isUsed = 0u;
	v2gMeteringReceiptReqType->SAScheduleTupleID_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 97:
			/* FirstStartTag[ATTRIBUTE[STRING]({urn:iso:15118:2:2013:MsgBody}Id), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionID)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gMeteringReceiptReqType->Id.charactersLen);
					if (errn == 0) {
						errn =  (v2gMeteringReceiptReqType->Id.charactersLen - 2) <= v2gMeteringReceiptReqType_Id_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gMeteringReceiptReqType->Id.charactersLen >= 2) {
							v2gMeteringReceiptReqType->Id.charactersLen = (uint16_t)(v2gMeteringReceiptReqType->Id.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gMeteringReceiptReqType->Id.charactersLen, v2gMeteringReceiptReqType->Id.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gMeteringReceiptReqType->Id_isUsed = 1u;
					grammarID = 98;
					break;
				case 1:
					/* FirstStartTag[CHARACTERS[BINARY_HEX]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gMeteringReceiptReqType->SessionID.bytesLen);
							if (errn == 0) {
								errn =  (v2gMeteringReceiptReqType->SessionID.bytesLen) <= v2gMeteringReceiptReqType_SessionID_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gMeteringReceiptReqType->SessionID.bytesLen, v2gMeteringReceiptReqType->SessionID.bytes);
							}
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 99;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 98:
			/* StartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BINARY_HEX]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gMeteringReceiptReqType->SessionID.bytesLen);
							if (errn == 0) {
								errn =  (v2gMeteringReceiptReqType->SessionID.bytesLen) <= v2gMeteringReceiptReqType_SessionID_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gMeteringReceiptReqType->SessionID.bytesLen, v2gMeteringReceiptReqType->SessionID.bytes);
							}
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 99;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 99:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SAScheduleTupleID), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}MeterInfo)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 8, &(uint32));
							v2gMeteringReceiptReqType->SAScheduleTupleID = (uint8_t)(uint32 + 1);
							v2gMeteringReceiptReqType->SAScheduleTupleID_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SAScheduleTupleID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 100;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					errn = decode_v2gMeterInfoType(stream, &v2gMeteringReceiptReqType->MeterInfo, eventCode);
					grammarID = 5;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 100:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}MeterInfo)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gMeterInfoType(stream, &v2gMeteringReceiptReqType->MeterInfo, eventCode);
					grammarID = 5;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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
int decode_v2gPaymentDetailsReqType(bitstream_t* stream, struct v2gPaymentDetailsReqType* v2gPaymentDetailsReqType, uint32_t eventCode) {
	int grammarID = 140;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 140:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}eMAID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gPaymentDetailsReqType->eMAID.charactersLen);
							if (errn == 0) {
								errn =  (v2gPaymentDetailsReqType->eMAID.charactersLen - 2) <= v2gPaymentDetailsReqType_eMAID_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
							}
							if (errn == 0) {
								if (v2gPaymentDetailsReqType->eMAID.charactersLen >= 2) {
									v2gPaymentDetailsReqType->eMAID.charactersLen = (uint16_t)(v2gPaymentDetailsReqType->eMAID.charactersLen - 2); /* string table miss */
									errn = decodeCharacters(stream, v2gPaymentDetailsReqType->eMAID.charactersLen, v2gPaymentDetailsReqType->eMAID.characters);
								} else {
									/* string table hit */
									errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
								}
							}
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}eMAID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 141;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 141:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ContractSignatureCertChain)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gCertificateChainType(stream, &v2gPaymentDetailsReqType->ContractSignatureCertChain, eventCode);
					grammarID = 5;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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
int decode_v2gPaymentServiceSelectionReqType(bitstream_t* stream, struct v2gPaymentServiceSelectionReqType* v2gPaymentServiceSelectionReqType, uint32_t eventCode) {
	int grammarID = 37;
	int done = 0;
	int errn;
	uint32_t uint32;

	while(!done) {
		switch(grammarID) {
		case 37:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SelectedPaymentOption)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 1, &uint32);
							v2gPaymentServiceSelectionReqType->SelectedPaymentOption = (v2gpaymentOptionType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SelectedPaymentOption) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 38;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 38:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SelectedServiceList)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gSelectedServiceListType(stream, &v2gPaymentServiceSelectionReqType->SelectedServiceList, eventCode);
					grammarID = 5;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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
int decode_v2gPowerDeliveryReqType(bitstream_t* stream, struct v2gPowerDeliveryReqType* v2gPowerDeliveryReqType, uint32_t eventCode) {
	int grammarID = 78;
	int done = 0;
	int errn;
	uint32_t uint32;

	v2gPowerDeliveryReqType->ChargingProfile_isUsed = 0u;
	v2gPowerDeliveryReqType->EVPowerDeliveryParameter_isUsed = 0;
	v2gPowerDeliveryReqType->DC_EVPowerDeliveryParameter_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 78:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargeProgress)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 2, &uint32);
							v2gPowerDeliveryReqType->ChargeProgress = (v2gchargeProgressType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargeProgress) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 79;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 79:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SAScheduleTupleID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 8, &(uint32));
							v2gPowerDeliveryReqType->SAScheduleTupleID = (uint8_t)(uint32 + 1);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SAScheduleTupleID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 80;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 80:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingProfile), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVPowerDeliveryParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVPowerDeliveryParameter), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gChargingProfileType(stream, &v2gPowerDeliveryReqType->ChargingProfile, eventCode);
					v2gPowerDeliveryReqType->ChargingProfile_isUsed = 1u;
					grammarID = 81;
					break;
				case 1:
					errn = decode_v2gDC_EVPowerDeliveryParameterType(stream, &v2gPowerDeliveryReqType->DC_EVPowerDeliveryParameter, eventCode);
					v2gPowerDeliveryReqType->DC_EVPowerDeliveryParameter_isUsed = 1u;
					grammarID = 5;
					break;
				case 2:
					errn = decode_v2gEVPowerDeliveryParameterType(stream, &v2gPowerDeliveryReqType->EVPowerDeliveryParameter, eventCode);
					v2gPowerDeliveryReqType->EVPowerDeliveryParameter_isUsed = 1u;
					grammarID = 5;
					break;
				case 3:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 81:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVPowerDeliveryParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVPowerDeliveryParameter), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gDC_EVPowerDeliveryParameterType(stream, &v2gPowerDeliveryReqType->DC_EVPowerDeliveryParameter, eventCode);
					v2gPowerDeliveryReqType->DC_EVPowerDeliveryParameter_isUsed = 1u;
					grammarID = 5;
					break;
				case 1:
					errn = decode_v2gEVPowerDeliveryParameterType(stream, &v2gPowerDeliveryReqType->EVPowerDeliveryParameter, eventCode);
					v2gPowerDeliveryReqType->EVPowerDeliveryParameter_isUsed = 1u;
					grammarID = 5;
					break;
				case 2:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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
int decode_v2gPreChargeReqType(bitstream_t* stream, struct v2gPreChargeReqType* v2gPreChargeReqType, uint32_t eventCode) {
	int grammarID = 288;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 288:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}DC_EVStatus)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gDC_EVStatusType(stream, &v2gPreChargeReqType->DC_EVStatus, eventCode);
					grammarID = 289;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 289:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVTargetVoltage)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gPreChargeReqType->EVTargetVoltage, eventCode);
					grammarID = 290;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 290:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVTargetCurrent)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gPreChargeReqType->EVTargetCurrent, eventCode);
					grammarID = 5;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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
int decode_v2gServiceDiscoveryReqType(bitstream_t* stream, struct v2gServiceDiscoveryReqType* v2gServiceDiscoveryReqType, uint32_t eventCode) {
	int grammarID = 107;
	int done = 0;
	int errn;
	uint32_t uint32;

	v2gServiceDiscoveryReqType->ServiceScope_isUsed = 0u;
	v2gServiceDiscoveryReqType->ServiceCategory_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 107:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceScope), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceCategory), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gServiceDiscoveryReqType->ServiceScope.charactersLen);
							if (errn == 0) {
								errn =  (v2gServiceDiscoveryReqType->ServiceScope.charactersLen - 2) <= v2gServiceDiscoveryReqType_ServiceScope_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
							}
							if (errn == 0) {
								if (v2gServiceDiscoveryReqType->ServiceScope.charactersLen >= 2) {
									v2gServiceDiscoveryReqType->ServiceScope.charactersLen = (uint16_t)(v2gServiceDiscoveryReqType->ServiceScope.charactersLen - 2); /* string table miss */
									errn = decodeCharacters(stream, v2gServiceDiscoveryReqType->ServiceScope.charactersLen, v2gServiceDiscoveryReqType->ServiceScope.characters);
								} else {
									/* string table hit */
									errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
								}
							}
							v2gServiceDiscoveryReqType->ServiceScope_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceScope) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 108;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 2, &uint32);
							v2gServiceDiscoveryReqType->ServiceCategory = (v2gserviceCategoryType) uint32;
							v2gServiceDiscoveryReqType->ServiceCategory_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceCategory) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 5;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 2:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 108:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceCategory), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 2, &uint32);
							v2gServiceDiscoveryReqType->ServiceCategory = (v2gserviceCategoryType) uint32;
							v2gServiceDiscoveryReqType->ServiceCategory_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceCategory) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 5;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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
int decode_v2gSessionSetupReqType(bitstream_t* stream, struct v2gSessionSetupReqType* v2gSessionSetupReqType, uint32_t eventCode) {
	int grammarID = 164;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 164:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVCCID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BINARY_HEX]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gSessionSetupReqType->EVCCID.bytesLen);
							if (errn == 0) {
								errn =  (v2gSessionSetupReqType->EVCCID.bytesLen) <= v2gSessionSetupReqType_EVCCID_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gSessionSetupReqType->EVCCID.bytesLen, v2gSessionSetupReqType->EVCCID.bytes);
							}
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVCCID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 5;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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
int decode_v2gSessionStopReqType(bitstream_t* stream, struct v2gSessionStopReqType* v2gSessionStopReqType, uint32_t eventCode) {
	int grammarID = 163;
	int done = 0;
	int errn;
	uint32_t uint32;

	while(!done) {
		switch(grammarID) {
		case 163:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingSession)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 1, &uint32);
							v2gSessionStopReqType->ChargingSession = (v2gchargingSessionType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingSession) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 5;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,WeldingDetectionReqType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":DC_EVStatus)',  derivedBy='EXTENSION'.  */
int decode_v2gWeldingDetectionReqType(bitstream_t* stream, struct v2gWeldingDetectionReqType* v2gWeldingDetectionReqType, uint32_t eventCode) {
	int grammarID = 157;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 157:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}DC_EVStatus)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gDC_EVStatusType(stream, &v2gWeldingDetectionReqType->DC_EVStatus, eventCode);
					grammarID = 5;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 5:
			/* Element[END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
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
