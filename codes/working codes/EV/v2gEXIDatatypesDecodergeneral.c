/*
 * v2gEXIDatatypesDecoder_functions.c
 *
 *  Created on: 10.02.2016
 *      Author: melanie
 */

# include "ErrorCodes.h"
# include "DecoderChannel.h"
# include <stdio.h>
# include "v2gEXIDatatypesDecoder.h"
# include "EXITypes.h"

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
int decode_v2gPhysicalValueType(bitstream_t* stream, struct v2gPhysicalValueType* v2gPhysicalValueType, uint32_t eventCode) {
	int grammarID = 129;
	int done = 0;
	int errn;
	uint32_t uint32;

	while(!done) {
		switch(grammarID) {
		case 129:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Multiplier)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 3, &(uint32));
							v2gPhysicalValueType->Multiplier = (int8_t)(uint32 -3);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Multiplier) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 130;
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
		case 130:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Unit)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 3, &uint32);
							v2gPhysicalValueType->Unit = (v2gunitSymbolType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Unit) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 131;
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
		case 131:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Value)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeInteger16(stream, &v2gPhysicalValueType->Value);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Value) ? */
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,BodyBaseType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
int decode_v2gBodyBaseType(bitstream_t* stream, struct v2gBodyBaseType* v2gBodyBaseType, uint32_t eventCode) {
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,CanonicalizationMethodType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='((WC[##any]){0-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int decode_v2gCanonicalizationMethodType(bitstream_t* stream, struct v2gCanonicalizationMethodType* v2gCanonicalizationMethodType, uint32_t eventCode) {
	int grammarID = 267;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 267:
			/* FirstStartTag[ATTRIBUTE[STRING](Algorithm)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gCanonicalizationMethodType->Algorithm.charactersLen);
					if (errn == 0) {
						errn =  (v2gCanonicalizationMethodType->Algorithm.charactersLen - 2) <= v2gCanonicalizationMethodType_Algorithm_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gCanonicalizationMethodType->Algorithm.charactersLen >= 2) {
							v2gCanonicalizationMethodType->Algorithm.charactersLen = (uint16_t)(v2gCanonicalizationMethodType->Algorithm.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gCanonicalizationMethodType->Algorithm.charactersLen, v2gCanonicalizationMethodType->Algorithm.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					grammarID = 47;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 47:
			/* StartTag[START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 35;
					break;
				case 1:
					done = 1;
					grammarID = 1;
					break;
				case 2:
					grammarID = 35;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 35:
			/* Element[START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 35;
					break;
				case 1:
					done = 1;
					grammarID = 1;
					break;
				case 2:
					grammarID = 35;
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ListOfRootCertificateIDsType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":RootCertificateID{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int decode_v2gListOfRootCertificateIDsType(bitstream_t* stream, struct v2gListOfRootCertificateIDsType* v2gListOfRootCertificateIDsType, uint32_t eventCode) {
	int grammarID = 134;
	int done = 0;
	int errn;

	v2gListOfRootCertificateIDsType->RootCertificateID.arrayLen = 0u;

	while(!done) {
		switch(grammarID) {
		case 134:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}RootCertificateID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gListOfRootCertificateIDsType->RootCertificateID.arrayLen < v2gListOfRootCertificateIDsType_RootCertificateID_ARRAY_SIZE) {
						errn = decode_v2gX509IssuerSerialType(stream, &v2gListOfRootCertificateIDsType->RootCertificateID.array[v2gListOfRootCertificateIDsType->RootCertificateID.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 135;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 135:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}RootCertificateID), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gListOfRootCertificateIDsType->RootCertificateID.arrayLen < v2gListOfRootCertificateIDsType_RootCertificateID_ARRAY_SIZE) {
						errn = decode_v2gX509IssuerSerialType(stream, &v2gListOfRootCertificateIDsType->RootCertificateID.array[v2gListOfRootCertificateIDsType->RootCertificateID.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 135;
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,X509IssuerSerialType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":X509IssuerName,"http://www.w3.org/2000/09/xmldsig#":X509SerialNumber)',  derivedBy='RESTRICTION'.  */
int decode_v2gX509IssuerSerialType(bitstream_t* stream, struct v2gX509IssuerSerialType* v2gX509IssuerSerialType, uint32_t eventCode) {
	int grammarID = 132;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 132:
			/* FirstStartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509IssuerName)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gX509IssuerSerialType->X509IssuerName.charactersLen);
							if (errn == 0) {
								errn =  (v2gX509IssuerSerialType->X509IssuerName.charactersLen - 2) <= v2gX509IssuerSerialType_X509IssuerName_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
							}
							if (errn == 0) {
								if (v2gX509IssuerSerialType->X509IssuerName.charactersLen >= 2) {
									v2gX509IssuerSerialType->X509IssuerName.charactersLen = (uint16_t)(v2gX509IssuerSerialType->X509IssuerName.charactersLen - 2); /* string table miss */
									errn = decodeCharacters(stream, v2gX509IssuerSerialType->X509IssuerName.charactersLen, v2gX509IssuerSerialType->X509IssuerName.characters);
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
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509IssuerName) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 133;
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
		case 133:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509SerialNumber)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeInteger64(stream, &v2gX509IssuerSerialType->X509SerialNumber);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509SerialNumber) ? */
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,CertificateChainType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Certificate,"urn:iso:15118:2:2013:MsgDataTypes":SubCertificates{0-1})',  derivedBy='RESTRICTION'.  */
int decode_v2gCertificateChainType(bitstream_t* stream, struct v2gCertificateChainType* v2gCertificateChainType, uint32_t eventCode) {
	int grammarID = 212;
	int done = 0;
	int errn;

	v2gCertificateChainType->Id_isUsed = 0u;
	v2gCertificateChainType->SubCertificates_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 212:
			/* FirstStartTag[ATTRIBUTE[STRING]({urn:iso:15118:2:2013:MsgDataTypes}Id), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Certificate)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gCertificateChainType->Id.charactersLen);
					if (errn == 0) {
						errn =  (v2gCertificateChainType->Id.charactersLen - 2) <= v2gCertificateChainType_Id_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gCertificateChainType->Id.charactersLen >= 2) {
							v2gCertificateChainType->Id.charactersLen = (uint16_t)(v2gCertificateChainType->Id.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gCertificateChainType->Id.charactersLen, v2gCertificateChainType->Id.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gCertificateChainType->Id_isUsed = 1u;
					grammarID = 213;
					break;
				case 1:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gCertificateChainType->Certificate.bytesLen);
							if (errn == 0) {
								errn =  (v2gCertificateChainType->Certificate.bytesLen) <= v2gCertificateChainType_Certificate_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gCertificateChainType->Certificate.bytesLen, v2gCertificateChainType->Certificate.bytes);
							}
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Certificate) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 214;
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
		case 213:
			/* StartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Certificate)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gCertificateChainType->Certificate.bytesLen);
							if (errn == 0) {
								errn =  (v2gCertificateChainType->Certificate.bytesLen) <= v2gCertificateChainType_Certificate_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gCertificateChainType->Certificate.bytesLen, v2gCertificateChainType->Certificate.bytes);
							}
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Certificate) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 214;
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
		case 214:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SubCertificates), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gSubCertificatesType(stream, &v2gCertificateChainType->SubCertificates, eventCode);
					v2gCertificateChainType->SubCertificates_isUsed = 1u;
					grammarID = 5;
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SubCertificatesType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Certificate{1-4})',  derivedBy='RESTRICTION'.  */
int decode_v2gSubCertificatesType(bitstream_t* stream, struct v2gSubCertificatesType* v2gSubCertificatesType, uint32_t eventCode) {
	int grammarID = 59;
	int done = 0;
	int errn;

	v2gSubCertificatesType->Certificate.arrayLen = 0u;

	while(!done) {
		switch(grammarID) {
		case 59:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Certificate)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSubCertificatesType->Certificate.arrayLen < v2gSubCertificatesType_Certificate_ARRAY_SIZE) {
						/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType->Certificate.arrayLen].bytesLen);
								if (errn == 0) {
									errn =  (v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType->Certificate.arrayLen].bytesLen) <= v2gSubCertificatesType_Certificate_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
								}
								if (errn == 0) {
									errn = decodeBytes(stream, v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType->Certificate.arrayLen].bytesLen, v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType->Certificate.arrayLen].bytes);
								}
								v2gSubCertificatesType->Certificate.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Certificate) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 60;
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
		case 60:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Certificate), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSubCertificatesType->Certificate.arrayLen < v2gSubCertificatesType_Certificate_ARRAY_SIZE) {
						/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType->Certificate.arrayLen].bytesLen);
								if (errn == 0) {
									errn =  (v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType->Certificate.arrayLen].bytesLen) <= v2gSubCertificatesType_Certificate_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
								}
								if (errn == 0) {
									errn = decodeBytes(stream, v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType->Certificate.arrayLen].bytesLen, v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType->Certificate.arrayLen].bytes);
								}
								v2gSubCertificatesType->Certificate.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Certificate) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 61;
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
		case 61:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Certificate), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSubCertificatesType->Certificate.arrayLen < v2gSubCertificatesType_Certificate_ARRAY_SIZE) {
						/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType->Certificate.arrayLen].bytesLen);
								if (errn == 0) {
									errn =  (v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType->Certificate.arrayLen].bytesLen) <= v2gSubCertificatesType_Certificate_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
								}
								if (errn == 0) {
									errn = decodeBytes(stream, v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType->Certificate.arrayLen].bytesLen, v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType->Certificate.arrayLen].bytes);
								}
								v2gSubCertificatesType->Certificate.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Certificate) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 62;
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
		case 62:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Certificate), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSubCertificatesType->Certificate.arrayLen < v2gSubCertificatesType_Certificate_ARRAY_SIZE) {
						/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType->Certificate.arrayLen].bytesLen);
								if (errn == 0) {
									errn =  (v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType->Certificate.arrayLen].bytesLen) <= v2gSubCertificatesType_Certificate_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
								}
								if (errn == 0) {
									errn = decodeBytes(stream, v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType->Certificate.arrayLen].bytesLen, v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType->Certificate.arrayLen].bytes);
								}
								v2gSubCertificatesType->Certificate.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Certificate) ? */
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ContractSignatureEncryptedPrivateKeyType',  base type name='privateKeyType',  content type='SIMPLE',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  derivedBy='EXTENSION'.  */
int decode_v2gContractSignatureEncryptedPrivateKeyType(bitstream_t* stream, struct v2gContractSignatureEncryptedPrivateKeyType* v2gContractSignatureEncryptedPrivateKeyType, uint32_t eventCode) {
	int grammarID = 57;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 57:
			/* FirstStartTag[ATTRIBUTE[STRING]({urn:iso:15118:2:2013:MsgDataTypes}Id)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gContractSignatureEncryptedPrivateKeyType->Id.charactersLen);
					if (errn == 0) {
						errn =  (v2gContractSignatureEncryptedPrivateKeyType->Id.charactersLen - 2) <= v2gContractSignatureEncryptedPrivateKeyType_Id_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gContractSignatureEncryptedPrivateKeyType->Id.charactersLen >= 2) {
							v2gContractSignatureEncryptedPrivateKeyType->Id.charactersLen = (uint16_t)(v2gContractSignatureEncryptedPrivateKeyType->Id.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gContractSignatureEncryptedPrivateKeyType->Id.charactersLen, v2gContractSignatureEncryptedPrivateKeyType->Id.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					grammarID = 58;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 58:
			/* StartTag[CHARACTERS[BINARY_BASE64]] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gContractSignatureEncryptedPrivateKeyType->CONTENT.bytesLen);
					if (errn == 0) {
						errn =  (v2gContractSignatureEncryptedPrivateKeyType->CONTENT.bytesLen) <= v2gContractSignatureEncryptedPrivateKeyType_CONTENT_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
					}
					if (errn == 0) {
						errn = decodeBytes(stream, v2gContractSignatureEncryptedPrivateKeyType->CONTENT.bytesLen, v2gContractSignatureEncryptedPrivateKeyType->CONTENT.bytes);
					}
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DiffieHellmanPublickeyType',  base type name='dHpublickeyType',  content type='SIMPLE',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  derivedBy='EXTENSION'.  */
int decode_v2gDiffieHellmanPublickeyType(bitstream_t* stream, struct v2gDiffieHellmanPublickeyType* v2gDiffieHellmanPublickeyType, uint32_t eventCode) {
	int grammarID = 57;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 57:
			/* FirstStartTag[ATTRIBUTE[STRING]({urn:iso:15118:2:2013:MsgDataTypes}Id)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gDiffieHellmanPublickeyType->Id.charactersLen);
					if (errn == 0) {
						errn =  (v2gDiffieHellmanPublickeyType->Id.charactersLen - 2) <= v2gDiffieHellmanPublickeyType_Id_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gDiffieHellmanPublickeyType->Id.charactersLen >= 2) {
							v2gDiffieHellmanPublickeyType->Id.charactersLen = (uint16_t)(v2gDiffieHellmanPublickeyType->Id.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gDiffieHellmanPublickeyType->Id.charactersLen, v2gDiffieHellmanPublickeyType->Id.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					grammarID = 58;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 58:
			/* StartTag[CHARACTERS[BINARY_BASE64]] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gDiffieHellmanPublickeyType->CONTENT.bytesLen);
					if (errn == 0) {
						errn =  (v2gDiffieHellmanPublickeyType->CONTENT.bytesLen) <= v2gDiffieHellmanPublickeyType_CONTENT_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
					}
					if (errn == 0) {
						errn = decodeBytes(stream, v2gDiffieHellmanPublickeyType->CONTENT.bytesLen, v2gDiffieHellmanPublickeyType->CONTENT.bytes);
					}
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EMAIDType',  base type name='eMAIDType',  content type='SIMPLE',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  derivedBy='EXTENSION'.  */
int decode_v2gEMAIDType(bitstream_t* stream, struct v2gEMAIDType* v2gEMAIDType, uint32_t eventCode) {
	int grammarID = 223;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 223:
			/* FirstStartTag[ATTRIBUTE[STRING]({urn:iso:15118:2:2013:MsgDataTypes}Id)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gEMAIDType->Id.charactersLen);
					if (errn == 0) {
						errn =  (v2gEMAIDType->Id.charactersLen - 2) <= v2gEMAIDType_Id_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gEMAIDType->Id.charactersLen >= 2) {
							v2gEMAIDType->Id.charactersLen = (uint16_t)(v2gEMAIDType->Id.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gEMAIDType->Id.charactersLen, v2gEMAIDType->Id.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					grammarID = 224;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 224:
			/* StartTag[CHARACTERS[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gEMAIDType->CONTENT.charactersLen);
					if (errn == 0) {
						errn =  (v2gEMAIDType->CONTENT.charactersLen - 2) <= v2gEMAIDType_CONTENT_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gEMAIDType->CONTENT.charactersLen >= 2) {
							v2gEMAIDType->CONTENT.charactersLen = (uint16_t)(v2gEMAIDType->CONTENT.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gEMAIDType->CONTENT.charactersLen, v2gEMAIDType->CONTENT.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EVPowerDeliveryParameterType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
int decode_v2gEVPowerDeliveryParameterType(bitstream_t* stream, struct v2gEVPowerDeliveryParameterType* v2gEVPowerDeliveryParameterType, uint32_t eventCode) {
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SAScheduleTupleType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":SAScheduleTupleID,"urn:iso:15118:2:2013:MsgDataTypes":PMaxSchedule,"urn:iso:15118:2:2013:MsgDataTypes":SalesTariff{0-1})',  derivedBy='RESTRICTION'.  */
int decode_v2gSAScheduleTupleType(bitstream_t* stream, struct v2gSAScheduleTupleType* v2gSAScheduleTupleType, uint32_t eventCode) {
	int grammarID = 313;
	int done = 0;
	int errn;
	uint32_t uint32;

	v2gSAScheduleTupleType->SalesTariff_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 313:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SAScheduleTupleID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 8, &(uint32));
							v2gSAScheduleTupleType->SAScheduleTupleID = (uint8_t)(uint32 + 1);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SAScheduleTupleID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 314;
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
		case 314:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}PMaxSchedule)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPMaxScheduleType(stream, &v2gSAScheduleTupleType->PMaxSchedule, eventCode);
					grammarID = 315;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 315:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SalesTariff), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gSalesTariffType(stream, &v2gSAScheduleTupleType->SalesTariff, eventCode);
					v2gSAScheduleTupleType->SalesTariff_isUsed = 1u;
					grammarID = 5;
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PMaxScheduleType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":PMaxScheduleEntry{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int decode_v2gPMaxScheduleType(bitstream_t* stream, struct v2gPMaxScheduleType* v2gPMaxScheduleType, uint32_t eventCode) {
	int grammarID = 305;
	int done = 0;
	int errn;

	v2gPMaxScheduleType->PMaxScheduleEntry.arrayLen = 0u;
	while(!done) {
		switch(grammarID) {
		case 305:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}PMaxScheduleEntry)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gPMaxScheduleType->PMaxScheduleEntry.arrayLen < v2gPMaxScheduleType_PMaxScheduleEntry_ARRAY_SIZE) {
						errn = decode_v2gPMaxScheduleEntryType(stream, &v2gPMaxScheduleType->PMaxScheduleEntry.array[v2gPMaxScheduleType->PMaxScheduleEntry.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 306;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 306:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}PMaxScheduleEntry), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gPMaxScheduleType->PMaxScheduleEntry.arrayLen < v2gPMaxScheduleType_PMaxScheduleEntry_ARRAY_SIZE) {
						errn = decode_v2gPMaxScheduleEntryType(stream, &v2gPMaxScheduleType->PMaxScheduleEntry.array[v2gPMaxScheduleType->PMaxScheduleEntry.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 306;
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PMaxScheduleEntryType',  base type name='EntryType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":TimeInterval),("urn:iso:15118:2:2013:MsgDataTypes":PMax))',  derivedBy='EXTENSION'.  */
int decode_v2gPMaxScheduleEntryType(bitstream_t* stream, struct v2gPMaxScheduleEntryType* v2gPMaxScheduleEntryType, uint32_t eventCode) {
	int grammarID = 142;
	int done = 0;
	int errn;

	v2gPMaxScheduleEntryType->TimeInterval_isUsed = 0u;
	v2gPMaxScheduleEntryType->RelativeTimeInterval_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 142:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}RelativeTimeInterval), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}TimeInterval)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gRelativeTimeIntervalType(stream, &v2gPMaxScheduleEntryType->RelativeTimeInterval, eventCode);
					v2gPMaxScheduleEntryType->RelativeTimeInterval_isUsed = 1u;
					grammarID = 143;
					break;
				case 1:
					errn = decode_v2gIntervalType(stream, &v2gPMaxScheduleEntryType->TimeInterval, eventCode);
					v2gPMaxScheduleEntryType->TimeInterval_isUsed = 1u;
					grammarID = 143;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 143:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}PMax)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gPMaxScheduleEntryType->PMax, eventCode);
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,RelativeTimeIntervalType',  base type name='IntervalType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":start,"urn:iso:15118:2:2013:MsgDataTypes":duration{0-1})',  derivedBy='EXTENSION'.  */
int decode_v2gRelativeTimeIntervalType(bitstream_t* stream, struct v2gRelativeTimeIntervalType* v2gRelativeTimeIntervalType, uint32_t eventCode) {
	int grammarID = 55;
	int done = 0;
	int errn;

	v2gRelativeTimeIntervalType->duration_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 55:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}start)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger32(stream, &v2gRelativeTimeIntervalType->start);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}start) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 56;
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
		case 56:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}duration), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger32(stream, &v2gRelativeTimeIntervalType->duration);
							v2gRelativeTimeIntervalType->duration_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}duration) ? */
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,IntervalType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
int decode_v2gIntervalType(bitstream_t* stream, struct v2gIntervalType* v2gIntervalType, uint32_t eventCode) {
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SalesTariffType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":SalesTariffID,"urn:iso:15118:2:2013:MsgDataTypes":SalesTariffDescription{0-1},"urn:iso:15118:2:2013:MsgDataTypes":NumEPriceLevels{0-1},"urn:iso:15118:2:2013:MsgDataTypes":SalesTariffEntry{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int decode_v2gSalesTariffType(bitstream_t* stream, struct v2gSalesTariffType* v2gSalesTariffType, uint32_t eventCode) {
	int grammarID = 26;
	int done = 0;
	int errn;
	uint32_t uint32;

	init_v2gSalesTariffType(v2gSalesTariffType);

	while(!done) {
		switch(grammarID) {
		case 26:
			/* FirstStartTag[ATTRIBUTE[STRING]({urn:iso:15118:2:2013:MsgDataTypes}Id), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SalesTariffID)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gSalesTariffType->Id.charactersLen);
					if (errn == 0) {
						errn =  (v2gSalesTariffType->Id.charactersLen - 2) <= v2gSalesTariffType_Id_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gSalesTariffType->Id.charactersLen >= 2) {
							v2gSalesTariffType->Id.charactersLen = (uint16_t)(v2gSalesTariffType->Id.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gSalesTariffType->Id.charactersLen, v2gSalesTariffType->Id.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gSalesTariffType->Id_isUsed = 1u;
					grammarID = 27;
					break;
				case 1:
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 8, &(uint32));
							v2gSalesTariffType->SalesTariffID = (uint8_t)(uint32 + 1);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SalesTariffID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 28;
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
		case 27:
			/* StartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SalesTariffID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 8, &(uint32));
							v2gSalesTariffType->SalesTariffID = (uint8_t)(uint32 + 1);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SalesTariffID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 28;
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
		case 28:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SalesTariffDescription), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}NumEPriceLevels), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SalesTariffEntry)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gSalesTariffType->SalesTariffDescription.charactersLen);
							if (errn == 0) {
								errn =  (v2gSalesTariffType->SalesTariffDescription.charactersLen - 2) <= v2gSalesTariffType_SalesTariffDescription_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
							}
							if (errn == 0) {
								if (v2gSalesTariffType->SalesTariffDescription.charactersLen >= 2) {
									v2gSalesTariffType->SalesTariffDescription.charactersLen = (uint16_t)(v2gSalesTariffType->SalesTariffDescription.charactersLen - 2); /* string table miss */
									errn = decodeCharacters(stream, v2gSalesTariffType->SalesTariffDescription.charactersLen, v2gSalesTariffType->SalesTariffDescription.characters);
								} else {
									/* string table hit */
									errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
								}
							}
							v2gSalesTariffType->SalesTariffDescription_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SalesTariffDescription) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 29;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					/* First(xsi:type)StartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 8, &(uint32));
							v2gSalesTariffType->NumEPriceLevels = (uint8_t)(uint32 + 0);
							v2gSalesTariffType->NumEPriceLevels_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}NumEPriceLevels) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 30;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 2:
					if (v2gSalesTariffType->SalesTariffEntry.arrayLen < v2gSalesTariffType_SalesTariffEntry_ARRAY_SIZE) {
						errn = decode_v2gSalesTariffEntryType(stream, &v2gSalesTariffType->SalesTariffEntry.array[v2gSalesTariffType->SalesTariffEntry.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 31;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 29:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}NumEPriceLevels), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SalesTariffEntry)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 8, &(uint32));
							v2gSalesTariffType->NumEPriceLevels = (uint8_t)(uint32 + 0);
							v2gSalesTariffType->NumEPriceLevels_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}NumEPriceLevels) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 30;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					if (v2gSalesTariffType->SalesTariffEntry.arrayLen < v2gSalesTariffType_SalesTariffEntry_ARRAY_SIZE) {
						errn = decode_v2gSalesTariffEntryType(stream, &v2gSalesTariffType->SalesTariffEntry.array[v2gSalesTariffType->SalesTariffEntry.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 31;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 30:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SalesTariffEntry)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSalesTariffType->SalesTariffEntry.arrayLen < v2gSalesTariffType_SalesTariffEntry_ARRAY_SIZE) {
						errn = decode_v2gSalesTariffEntryType(stream, &v2gSalesTariffType->SalesTariffEntry.array[v2gSalesTariffType->SalesTariffEntry.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 31;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 31:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SalesTariffEntry), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSalesTariffType->SalesTariffEntry.arrayLen < v2gSalesTariffType_SalesTariffEntry_ARRAY_SIZE) {
						errn = decode_v2gSalesTariffEntryType(stream, &v2gSalesTariffType->SalesTariffEntry.array[v2gSalesTariffType->SalesTariffEntry.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 31;
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SalesTariffEntryType',  base type name='EntryType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":TimeInterval),("urn:iso:15118:2:2013:MsgDataTypes":EPriceLevel{0-1},"urn:iso:15118:2:2013:MsgDataTypes":ConsumptionCost{0-3}))',  derivedBy='EXTENSION'.  */
int decode_v2gSalesTariffEntryType(bitstream_t* stream, struct v2gSalesTariffEntryType* v2gSalesTariffEntryType, uint32_t eventCode) {
	int grammarID = 65;
	int done = 0;
	int errn;
	uint32_t uint32;

	init_v2gSalesTariffEntryType(v2gSalesTariffEntryType);

	while(!done) {
		switch(grammarID) {
		case 65:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}RelativeTimeInterval), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}TimeInterval)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gRelativeTimeIntervalType(stream, &v2gSalesTariffEntryType->RelativeTimeInterval, eventCode);
					v2gSalesTariffEntryType->RelativeTimeInterval_isUsed = 1u;
					grammarID = 66;
					break;
				case 1:
					errn = decode_v2gIntervalType(stream, &v2gSalesTariffEntryType->TimeInterval, eventCode);
					v2gSalesTariffEntryType->TimeInterval_isUsed = 1u;
					grammarID = 66;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 66:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EPriceLevel), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ConsumptionCost), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 8, &(uint32));
							v2gSalesTariffEntryType->EPriceLevel = (uint8_t)(uint32 + 0);
							v2gSalesTariffEntryType->EPriceLevel_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EPriceLevel) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 67;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					if (v2gSalesTariffEntryType->ConsumptionCost.arrayLen < v2gSalesTariffEntryType_ConsumptionCost_ARRAY_SIZE) {
						errn = decode_v2gConsumptionCostType(stream, &v2gSalesTariffEntryType->ConsumptionCost.array[v2gSalesTariffEntryType->ConsumptionCost.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 68;
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
		case 67:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ConsumptionCost), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSalesTariffEntryType->ConsumptionCost.arrayLen < v2gSalesTariffEntryType_ConsumptionCost_ARRAY_SIZE) {
						errn = decode_v2gConsumptionCostType(stream, &v2gSalesTariffEntryType->ConsumptionCost.array[v2gSalesTariffEntryType->ConsumptionCost.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 68;
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
		case 68:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ConsumptionCost), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSalesTariffEntryType->ConsumptionCost.arrayLen < v2gSalesTariffEntryType_ConsumptionCost_ARRAY_SIZE) {
						errn = decode_v2gConsumptionCostType(stream, &v2gSalesTariffEntryType->ConsumptionCost.array[v2gSalesTariffEntryType->ConsumptionCost.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 69;
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
		case 69:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ConsumptionCost), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSalesTariffEntryType->ConsumptionCost.arrayLen < v2gSalesTariffEntryType_ConsumptionCost_ARRAY_SIZE) {
						errn = decode_v2gConsumptionCostType(stream, &v2gSalesTariffEntryType->ConsumptionCost.array[v2gSalesTariffEntryType->ConsumptionCost.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 5;
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ConsumptionCostType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":startValue,"urn:iso:15118:2:2013:MsgDataTypes":Cost{1-3})',  derivedBy='RESTRICTION'.  */
int decode_v2gConsumptionCostType(bitstream_t* stream, struct v2gConsumptionCostType* v2gConsumptionCostType, uint32_t eventCode) {
	int grammarID = 82;
	int done = 0;
	int errn;

	v2gConsumptionCostType->Cost.arrayLen = 0u;

	while(!done) {
		switch(grammarID) {
		case 82:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}startValue)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gConsumptionCostType->startValue, eventCode);
					grammarID = 83;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 83:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Cost)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gConsumptionCostType->Cost.arrayLen < v2gConsumptionCostType_Cost_ARRAY_SIZE) {
						errn = decode_v2gCostType(stream, &v2gConsumptionCostType->Cost.array[v2gConsumptionCostType->Cost.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 84;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 84:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Cost), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gConsumptionCostType->Cost.arrayLen < v2gConsumptionCostType_Cost_ARRAY_SIZE) {
						errn = decode_v2gCostType(stream, &v2gConsumptionCostType->Cost.array[v2gConsumptionCostType->Cost.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 85;
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
		case 85:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Cost), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gConsumptionCostType->Cost.arrayLen < v2gConsumptionCostType_Cost_ARRAY_SIZE) {
						errn = decode_v2gCostType(stream, &v2gConsumptionCostType->Cost.array[v2gConsumptionCostType->Cost.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 5;
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,CostType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":costKind,"urn:iso:15118:2:2013:MsgDataTypes":amount,"urn:iso:15118:2:2013:MsgDataTypes":amountMultiplier{0-1})',  derivedBy='RESTRICTION'.  */
int decode_v2gCostType(bitstream_t* stream, struct v2gCostType* v2gCostType, uint32_t eventCode) {
	int grammarID = 218;
	int done = 0;
	int errn;
	uint32_t uint32;

	v2gCostType->amountMultiplier_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 218:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}costKind)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 2, &uint32);
							v2gCostType->costKind = (v2gcostKindType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}costKind) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 219;
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
		case 219:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}amount)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger32(stream, &v2gCostType->amount);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}amount) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 220;
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
		case 220:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}amountMultiplier), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 3, &(uint32));
							v2gCostType->amountMultiplier = (int8_t)(uint32 -3);
							v2gCostType->amountMultiplier_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}amountMultiplier) ? */
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SASchedulesType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
int decode_v2gSASchedulesType(bitstream_t* stream, struct v2gSASchedulesType* v2gSASchedulesType, uint32_t eventCode) {
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,MeterInfoType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":MeterID,"urn:iso:15118:2:2013:MsgDataTypes":MeterReading{0-1},"urn:iso:15118:2:2013:MsgDataTypes":SigMeterReading{0-1},"urn:iso:15118:2:2013:MsgDataTypes":MeterStatus{0-1},"urn:iso:15118:2:2013:MsgDataTypes":TMeter{0-1})',  derivedBy='RESTRICTION'.  */
int decode_v2gMeterInfoType(bitstream_t* stream, struct v2gMeterInfoType* v2gMeterInfoType, uint32_t eventCode) {
	int grammarID = 225;
	int done = 0;
	int errn;

	init_v2gMeterInfoType(v2gMeterInfoType);

	while(!done) {
		switch(grammarID) {
		case 225:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}MeterID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gMeterInfoType->MeterID.charactersLen);
							if (errn == 0) {
								errn =  (v2gMeterInfoType->MeterID.charactersLen - 2) <= v2gMeterInfoType_MeterID_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
							}
							if (errn == 0) {
								if (v2gMeterInfoType->MeterID.charactersLen >= 2) {
									v2gMeterInfoType->MeterID.charactersLen = (uint16_t)(v2gMeterInfoType->MeterID.charactersLen - 2); /* string table miss */
									errn = decodeCharacters(stream, v2gMeterInfoType->MeterID.charactersLen, v2gMeterInfoType->MeterID.characters);
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
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}MeterID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 226;
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
		case 226:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}MeterReading), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SigMeterReading), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}MeterStatus), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}TMeter), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger64(stream, &v2gMeterInfoType->MeterReading);
							v2gMeterInfoType->MeterReading_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}MeterReading) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 227;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gMeterInfoType->SigMeterReading.bytesLen);
							if (errn == 0) {
								errn =  (v2gMeterInfoType->SigMeterReading.bytesLen) <= v2gMeterInfoType_SigMeterReading_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gMeterInfoType->SigMeterReading.bytesLen, v2gMeterInfoType->SigMeterReading.bytes);
							}
							v2gMeterInfoType->SigMeterReading_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SigMeterReading) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 228;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 2:
					/* FirstStartTag[CHARACTERS[INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeInteger16(stream, &v2gMeterInfoType->MeterStatus);
							v2gMeterInfoType->MeterStatus_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}MeterStatus) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 229;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 3:
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeInteger64(stream, &v2gMeterInfoType->TMeter);
							v2gMeterInfoType->TMeter_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}TMeter) ? */
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
		case 227:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SigMeterReading), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}MeterStatus), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}TMeter), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gMeterInfoType->SigMeterReading.bytesLen);
							if (errn == 0) {
								errn =  (v2gMeterInfoType->SigMeterReading.bytesLen) <= v2gMeterInfoType_SigMeterReading_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gMeterInfoType->SigMeterReading.bytesLen, v2gMeterInfoType->SigMeterReading.bytes);
							}
							v2gMeterInfoType->SigMeterReading_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SigMeterReading) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 228;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					/* FirstStartTag[CHARACTERS[INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeInteger16(stream, &v2gMeterInfoType->MeterStatus);
							v2gMeterInfoType->MeterStatus_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}MeterStatus) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 229;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 2:
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeInteger64(stream, &v2gMeterInfoType->TMeter);
							v2gMeterInfoType->TMeter_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}TMeter) ? */
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
		case 228:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}MeterStatus), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}TMeter), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeInteger16(stream, &v2gMeterInfoType->MeterStatus);
							v2gMeterInfoType->MeterStatus_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}MeterStatus) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 229;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeInteger64(stream, &v2gMeterInfoType->TMeter);
							v2gMeterInfoType->TMeter_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}TMeter) ? */
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
		case 229:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}TMeter), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeInteger64(stream, &v2gMeterInfoType->TMeter);
							v2gMeterInfoType->TMeter_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}TMeter) ? */
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,DSAKeyValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("http://www.w3.org/2000/09/xmldsig#":P,"http://www.w3.org/2000/09/xmldsig#":Q){0-1},"http://www.w3.org/2000/09/xmldsig#":G{0-1},"http://www.w3.org/2000/09/xmldsig#":Y,"http://www.w3.org/2000/09/xmldsig#":J{0-1},("http://www.w3.org/2000/09/xmldsig#":Seed,"http://www.w3.org/2000/09/xmldsig#":PgenCounter){0-1})',  derivedBy='RESTRICTION'.  */
int decode_v2gDSAKeyValueType(bitstream_t* stream, struct v2gDSAKeyValueType* v2gDSAKeyValueType, uint32_t eventCode) {
	int grammarID = 178;
	int done = 0;
	int errn;

	init_v2gDSAKeyValueType(v2gDSAKeyValueType);

	while(!done) {
		switch(grammarID) {
		case 178:
			/* FirstStartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}P), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}G), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Y)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gDSAKeyValueType->P.bytesLen);
							if (errn == 0) {
								errn =  (v2gDSAKeyValueType->P.bytesLen) <= v2gDSAKeyValueType_P_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gDSAKeyValueType->P.bytesLen, v2gDSAKeyValueType->P.bytes);
							}
							v2gDSAKeyValueType->P_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}P) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 179;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gDSAKeyValueType->G.bytesLen);
							if (errn == 0) {
								errn =  (v2gDSAKeyValueType->G.bytesLen) <= v2gDSAKeyValueType_G_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gDSAKeyValueType->G.bytesLen, v2gDSAKeyValueType->G.bytes);
							}
							v2gDSAKeyValueType->G_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}G) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 180;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 2:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gDSAKeyValueType->Y.bytesLen);
							if (errn == 0) {
								errn =  (v2gDSAKeyValueType->Y.bytesLen) <= v2gDSAKeyValueType_Y_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gDSAKeyValueType->Y.bytesLen, v2gDSAKeyValueType->Y.bytes);
							}
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Y) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 181;
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
		case 179:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Q)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gDSAKeyValueType->Q.bytesLen);
							if (errn == 0) {
								errn =  (v2gDSAKeyValueType->Q.bytesLen) <= v2gDSAKeyValueType_Q_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gDSAKeyValueType->Q.bytesLen, v2gDSAKeyValueType->Q.bytes);
							}
							v2gDSAKeyValueType->Q_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Q) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 182;
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
		case 182:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}G), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Y)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gDSAKeyValueType->G.bytesLen);
							if (errn == 0) {
								errn =  (v2gDSAKeyValueType->G.bytesLen) <= v2gDSAKeyValueType_G_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gDSAKeyValueType->G.bytesLen, v2gDSAKeyValueType->G.bytes);
							}
							v2gDSAKeyValueType->G_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}G) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 180;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gDSAKeyValueType->Y.bytesLen);
							if (errn == 0) {
								errn =  (v2gDSAKeyValueType->Y.bytesLen) <= v2gDSAKeyValueType_Y_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gDSAKeyValueType->Y.bytesLen, v2gDSAKeyValueType->Y.bytes);
							}
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Y) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 181;
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
		case 180:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Y)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gDSAKeyValueType->Y.bytesLen);
							if (errn == 0) {
								errn =  (v2gDSAKeyValueType->Y.bytesLen) <= v2gDSAKeyValueType_Y_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gDSAKeyValueType->Y.bytesLen, v2gDSAKeyValueType->Y.bytes);
							}
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Y) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 181;
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
		case 181:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}J), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Seed), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gDSAKeyValueType->J.bytesLen);
							if (errn == 0) {
								errn =  (v2gDSAKeyValueType->J.bytesLen) <= v2gDSAKeyValueType_J_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gDSAKeyValueType->J.bytesLen, v2gDSAKeyValueType->J.bytes);
							}
							v2gDSAKeyValueType->J_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}J) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 183;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gDSAKeyValueType->Seed.bytesLen);
							if (errn == 0) {
								errn =  (v2gDSAKeyValueType->Seed.bytesLen) <= v2gDSAKeyValueType_Seed_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gDSAKeyValueType->Seed.bytesLen, v2gDSAKeyValueType->Seed.bytes);
							}
							v2gDSAKeyValueType->Seed_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Seed) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 184;
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
		case 183:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Seed), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gDSAKeyValueType->Seed.bytesLen);
							if (errn == 0) {
								errn =  (v2gDSAKeyValueType->Seed.bytesLen) <= v2gDSAKeyValueType_Seed_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gDSAKeyValueType->Seed.bytesLen, v2gDSAKeyValueType->Seed.bytes);
							}
							v2gDSAKeyValueType->Seed_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Seed) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 184;
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
		case 184:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PgenCounter)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gDSAKeyValueType->PgenCounter.bytesLen);
							if (errn == 0) {
								errn =  (v2gDSAKeyValueType->PgenCounter.bytesLen) <= v2gDSAKeyValueType_PgenCounter_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gDSAKeyValueType->PgenCounter.bytesLen, v2gDSAKeyValueType->PgenCounter.bytes);
							}
							v2gDSAKeyValueType->PgenCounter_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PgenCounter) ? */
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,DigestMethodType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='((WC[##other:"http://www.w3.org/2000/09/xmldsig#"]){0-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int decode_v2gDigestMethodType(bitstream_t* stream, struct v2gDigestMethodType* v2gDigestMethodType, uint32_t eventCode) {
	int grammarID = 267;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 267:
			/* FirstStartTag[ATTRIBUTE[STRING](Algorithm)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gDigestMethodType->Algorithm.charactersLen);
					if (errn == 0) {
						errn =  (v2gDigestMethodType->Algorithm.charactersLen - 2) <= v2gDigestMethodType_Algorithm_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gDigestMethodType->Algorithm.charactersLen >= 2) {
							v2gDigestMethodType->Algorithm.charactersLen = (uint16_t)(v2gDigestMethodType->Algorithm.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gDigestMethodType->Algorithm.charactersLen, v2gDigestMethodType->Algorithm.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					grammarID = 47;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 47:
			/* StartTag[START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 35;
					break;
				case 1:
					done = 1;
					grammarID = 1;
					break;
				case 2:
					grammarID = 35;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 35:
			/* Element[START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 35;
					break;
				case 1:
					done = 1;
					grammarID = 1;
					break;
				case 2:
					grammarID = 35;
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EntryType',  base type name='anyType',  content type='ELEMENT',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":TimeInterval)',  derivedBy='RESTRICTION'.  */
int decode_v2gEntryType(bitstream_t* stream, struct v2gEntryType* v2gEntryType, uint32_t eventCode) {
	int grammarID = 232;
	int done = 0;
	int errn;

	v2gEntryType->RelativeTimeInterval_isUsed = 0u;
	v2gEntryType->RelativeTimeInterval_isUsed = 0u;
	while(!done) {
		switch(grammarID) {
		case 232:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}RelativeTimeInterval), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}TimeInterval)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gRelativeTimeIntervalType(stream, &v2gEntryType->RelativeTimeInterval, eventCode);
					v2gEntryType->RelativeTimeInterval_isUsed = 1u;
					grammarID = 5;
					break;
				case 1:
					errn = decode_v2gIntervalType(stream, &v2gEntryType->TimeInterval, eventCode);
					v2gEntryType->TimeInterval_isUsed = 1u;
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,KeyInfoType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":KeyName|"http://www.w3.org/2000/09/xmldsig#":KeyValue|"http://www.w3.org/2000/09/xmldsig#":RetrievalMethod|"http://www.w3.org/2000/09/xmldsig#":X509Data|"http://www.w3.org/2000/09/xmldsig#":PGPData|"http://www.w3.org/2000/09/xmldsig#":SPKIData|"http://www.w3.org/2000/09/xmldsig#":MgmtData|(WC[##other:"http://www.w3.org/2000/09/xmldsig#"])){1-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
int decode_v2gKeyInfoType(bitstream_t* stream, struct v2gKeyInfoType* v2gKeyInfoType, uint32_t eventCode) {
	int grammarID = 114;
	int done = 0;
	int errn;

	init_v2gKeyInfoType(v2gKeyInfoType);

	while(!done) {
		switch(grammarID) {
		case 114:
			/* FirstStartTag[ATTRIBUTE[STRING](Id), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyName), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyValue), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}RetrievalMethod), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509Data), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PGPData), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SPKIData), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}MgmtData), START_ELEMENT_GENERIC, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 4, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gKeyInfoType->Id.charactersLen);
					if (errn == 0) {
						errn =  (v2gKeyInfoType->Id.charactersLen - 2) <= v2gKeyInfoType_Id_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gKeyInfoType->Id.charactersLen >= 2) {
							v2gKeyInfoType->Id.charactersLen = (uint16_t)(v2gKeyInfoType->Id.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gKeyInfoType->Id.charactersLen, v2gKeyInfoType->Id.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gKeyInfoType->Id_isUsed = 1u;
					grammarID = 115;
					break;
				case 1:
					if (v2gKeyInfoType->KeyName.arrayLen < v2gKeyInfoType_KeyName_ARRAY_SIZE) {
						/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen);
								if (errn == 0) {
									errn =  (v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen - 2) <= v2gKeyInfoType_KeyName_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
								}
								if (errn == 0) {
									if (v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen >= 2) {
										v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen = (uint16_t)(v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen - 2); /* string table miss */
										errn = decodeCharacters(stream, v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen, v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].characters);
									} else {
										/* string table hit */
										errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
									}
								}
								v2gKeyInfoType->KeyName.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyName) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 116;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 2:
					if (v2gKeyInfoType->KeyValue.arrayLen < v2gKeyInfoType_KeyValue_ARRAY_SIZE) {
						errn = decode_v2gKeyValueType(stream, &v2gKeyInfoType->KeyValue.array[v2gKeyInfoType->KeyValue.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 116;
					break;
				case 3:
					if (v2gKeyInfoType->RetrievalMethod.arrayLen < v2gKeyInfoType_RetrievalMethod_ARRAY_SIZE) {
						errn = decode_v2gRetrievalMethodType(stream, &v2gKeyInfoType->RetrievalMethod.array[v2gKeyInfoType->RetrievalMethod.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 116;
					break;
				case 4:
					if (v2gKeyInfoType->X509Data.arrayLen < v2gKeyInfoType_X509Data_ARRAY_SIZE) {
						errn = decode_v2gX509DataType(stream, &v2gKeyInfoType->X509Data.array[v2gKeyInfoType->X509Data.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 116;
					break;
				case 5:
					if (v2gKeyInfoType->PGPData.arrayLen < v2gKeyInfoType_PGPData_ARRAY_SIZE) {
						errn = decode_v2gPGPDataType(stream, &v2gKeyInfoType->PGPData.array[v2gKeyInfoType->PGPData.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 116;
					break;
				case 6:
					if (v2gKeyInfoType->SPKIData.arrayLen < v2gKeyInfoType_SPKIData_ARRAY_SIZE) {
						errn = decode_v2gSPKIDataType(stream, &v2gKeyInfoType->SPKIData.array[v2gKeyInfoType->SPKIData.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 116;
					break;
				case 7:
					if (v2gKeyInfoType->MgmtData.arrayLen < v2gKeyInfoType_MgmtData_ARRAY_SIZE) {
						/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen);
								if (errn == 0) {
									errn =  (v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen - 2) <= v2gKeyInfoType_MgmtData_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
								}
								if (errn == 0) {
									if (v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen >= 2) {
										v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen = (uint16_t)(v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen - 2); /* string table miss */
										errn = decodeCharacters(stream, v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen, v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].characters);
									} else {
										/* string table hit */
										errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
									}
								}
								v2gKeyInfoType->MgmtData.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}MgmtData) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 116;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 8:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 116;
					break;
				case 9:
					grammarID = 117;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 115:
			/* StartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyName), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyValue), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}RetrievalMethod), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509Data), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PGPData), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SPKIData), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}MgmtData), START_ELEMENT_GENERIC, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 4, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gKeyInfoType->KeyName.arrayLen < v2gKeyInfoType_KeyName_ARRAY_SIZE) {
						/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen);
								if (errn == 0) {
									errn =  (v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen - 2) <= v2gKeyInfoType_KeyName_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
								}
								if (errn == 0) {
									if (v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen >= 2) {
										v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen = (uint16_t)(v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen - 2); /* string table miss */
										errn = decodeCharacters(stream, v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen, v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].characters);
									} else {
										/* string table hit */
										errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
									}
								}
								v2gKeyInfoType->KeyName.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyName) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 116;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					if (v2gKeyInfoType->KeyValue.arrayLen < v2gKeyInfoType_KeyValue_ARRAY_SIZE) {
						errn = decode_v2gKeyValueType(stream, &v2gKeyInfoType->KeyValue.array[v2gKeyInfoType->KeyValue.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 116;
					break;
				case 2:
					if (v2gKeyInfoType->RetrievalMethod.arrayLen < v2gKeyInfoType_RetrievalMethod_ARRAY_SIZE) {
						errn = decode_v2gRetrievalMethodType(stream, &v2gKeyInfoType->RetrievalMethod.array[v2gKeyInfoType->RetrievalMethod.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 116;
					break;
				case 3:
					if (v2gKeyInfoType->X509Data.arrayLen < v2gKeyInfoType_X509Data_ARRAY_SIZE) {
						errn = decode_v2gX509DataType(stream, &v2gKeyInfoType->X509Data.array[v2gKeyInfoType->X509Data.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 116;
					break;
				case 4:
					if (v2gKeyInfoType->PGPData.arrayLen < v2gKeyInfoType_PGPData_ARRAY_SIZE) {
						errn = decode_v2gPGPDataType(stream, &v2gKeyInfoType->PGPData.array[v2gKeyInfoType->PGPData.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 116;
					break;
				case 5:
					if (v2gKeyInfoType->SPKIData.arrayLen < v2gKeyInfoType_SPKIData_ARRAY_SIZE) {
						errn = decode_v2gSPKIDataType(stream, &v2gKeyInfoType->SPKIData.array[v2gKeyInfoType->SPKIData.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 116;
					break;
				case 6:
					if (v2gKeyInfoType->MgmtData.arrayLen < v2gKeyInfoType_MgmtData_ARRAY_SIZE) {
						/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen);
								if (errn == 0) {
									errn =  (v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen - 2) <= v2gKeyInfoType_MgmtData_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
								}
								if (errn == 0) {
									if (v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen >= 2) {
										v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen = (uint16_t)(v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen - 2); /* string table miss */
										errn = decodeCharacters(stream, v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen, v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].characters);
									} else {
										/* string table hit */
										errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
									}
								}
								v2gKeyInfoType->MgmtData.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}MgmtData) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 116;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 7:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 116;
					break;
				case 8:
					grammarID = 117;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 116:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyName), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyValue), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}RetrievalMethod), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509Data), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PGPData), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SPKIData), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}MgmtData), START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 4, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gKeyInfoType->KeyName.arrayLen < v2gKeyInfoType_KeyName_ARRAY_SIZE) {
						/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen);
								if (errn == 0) {
									errn =  (v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen - 2) <= v2gKeyInfoType_KeyName_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
								}
								if (errn == 0) {
									if (v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen >= 2) {
										v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen = (uint16_t)(v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen - 2); /* string table miss */
										errn = decodeCharacters(stream, v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen, v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].characters);
									} else {
										/* string table hit */
										errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
									}
								}
								v2gKeyInfoType->KeyName.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyName) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 116;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					if (v2gKeyInfoType->KeyValue.arrayLen < v2gKeyInfoType_KeyValue_ARRAY_SIZE) {
						errn = decode_v2gKeyValueType(stream, &v2gKeyInfoType->KeyValue.array[v2gKeyInfoType->KeyValue.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 116;
					break;
				case 2:
					if (v2gKeyInfoType->RetrievalMethod.arrayLen < v2gKeyInfoType_RetrievalMethod_ARRAY_SIZE) {
						errn = decode_v2gRetrievalMethodType(stream, &v2gKeyInfoType->RetrievalMethod.array[v2gKeyInfoType->RetrievalMethod.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 116;
					break;
				case 3:
					if (v2gKeyInfoType->X509Data.arrayLen < v2gKeyInfoType_X509Data_ARRAY_SIZE) {
						errn = decode_v2gX509DataType(stream, &v2gKeyInfoType->X509Data.array[v2gKeyInfoType->X509Data.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 116;
					break;
				case 4:
					if (v2gKeyInfoType->PGPData.arrayLen < v2gKeyInfoType_PGPData_ARRAY_SIZE) {
						errn = decode_v2gPGPDataType(stream, &v2gKeyInfoType->PGPData.array[v2gKeyInfoType->PGPData.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 116;
					break;
				case 5:
					if (v2gKeyInfoType->SPKIData.arrayLen < v2gKeyInfoType_SPKIData_ARRAY_SIZE) {
						errn = decode_v2gSPKIDataType(stream, &v2gKeyInfoType->SPKIData.array[v2gKeyInfoType->SPKIData.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 116;
					break;
				case 6:
					if (v2gKeyInfoType->MgmtData.arrayLen < v2gKeyInfoType_MgmtData_ARRAY_SIZE) {
						/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen);
								if (errn == 0) {
									errn =  (v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen - 2) <= v2gKeyInfoType_MgmtData_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
								}
								if (errn == 0) {
									if (v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen >= 2) {
										v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen = (uint16_t)(v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen - 2); /* string table miss */
										errn = decodeCharacters(stream, v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen, v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].characters);
									} else {
										/* string table hit */
										errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
									}
								}
								v2gKeyInfoType->MgmtData.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}MgmtData) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 116;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 7:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 116;
					break;
				case 8:
					done = 1;
					grammarID = 1;
					break;
				case 9:
					grammarID = 116;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 117:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyName), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyValue), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}RetrievalMethod), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509Data), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PGPData), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SPKIData), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}MgmtData), START_ELEMENT_GENERIC, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 4, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gKeyInfoType->KeyName.arrayLen < v2gKeyInfoType_KeyName_ARRAY_SIZE) {
						/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen);
								if (errn == 0) {
									errn =  (v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen - 2) <= v2gKeyInfoType_KeyName_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
								}
								if (errn == 0) {
									if (v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen >= 2) {
										v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen = (uint16_t)(v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen - 2); /* string table miss */
										errn = decodeCharacters(stream, v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].charactersLen, v2gKeyInfoType->KeyName.array[v2gKeyInfoType->KeyName.arrayLen].characters);
									} else {
										/* string table hit */
										errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
									}
								}
								v2gKeyInfoType->KeyName.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyName) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 116;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					if (v2gKeyInfoType->KeyValue.arrayLen < v2gKeyInfoType_KeyValue_ARRAY_SIZE) {
						errn = decode_v2gKeyValueType(stream, &v2gKeyInfoType->KeyValue.array[v2gKeyInfoType->KeyValue.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 116;
					break;
				case 2:
					if (v2gKeyInfoType->RetrievalMethod.arrayLen < v2gKeyInfoType_RetrievalMethod_ARRAY_SIZE) {
						errn = decode_v2gRetrievalMethodType(stream, &v2gKeyInfoType->RetrievalMethod.array[v2gKeyInfoType->RetrievalMethod.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 116;
					break;
				case 3:
					if (v2gKeyInfoType->X509Data.arrayLen < v2gKeyInfoType_X509Data_ARRAY_SIZE) {
						errn = decode_v2gX509DataType(stream, &v2gKeyInfoType->X509Data.array[v2gKeyInfoType->X509Data.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 116;
					break;
				case 4:
					if (v2gKeyInfoType->PGPData.arrayLen < v2gKeyInfoType_PGPData_ARRAY_SIZE) {
						errn = decode_v2gPGPDataType(stream, &v2gKeyInfoType->PGPData.array[v2gKeyInfoType->PGPData.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 116;
					break;
				case 5:
					if (v2gKeyInfoType->SPKIData.arrayLen < v2gKeyInfoType_SPKIData_ARRAY_SIZE) {
						errn = decode_v2gSPKIDataType(stream, &v2gKeyInfoType->SPKIData.array[v2gKeyInfoType->SPKIData.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 116;
					break;
				case 6:
					if (v2gKeyInfoType->MgmtData.arrayLen < v2gKeyInfoType_MgmtData_ARRAY_SIZE) {
						/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen);
								if (errn == 0) {
									errn =  (v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen - 2) <= v2gKeyInfoType_MgmtData_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
								}
								if (errn == 0) {
									if (v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen >= 2) {
										v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen = (uint16_t)(v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen - 2); /* string table miss */
										errn = decodeCharacters(stream, v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].charactersLen, v2gKeyInfoType->MgmtData.array[v2gKeyInfoType->MgmtData.arrayLen].characters);
									} else {
										/* string table hit */
										errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
									}
								}
								v2gKeyInfoType->MgmtData.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}MgmtData) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 116;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 7:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 116;
					break;
				case 8:
					grammarID = 117;
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,KeyValueType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":DSAKeyValue|"http://www.w3.org/2000/09/xmldsig#":RSAKeyValue|(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]))',  derivedBy='RESTRICTION'.  */
int decode_v2gKeyValueType(bitstream_t* stream, struct v2gKeyValueType* v2gKeyValueType, uint32_t eventCode) {
	int grammarID = 268;
	int done = 0;
	int errn;

	v2gKeyValueType->DSAKeyValue_isUsed = 0u;
	v2gKeyValueType->RSAKeyValue_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 268:
			/* FirstStartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DSAKeyValue), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}RSAKeyValue), START_ELEMENT_GENERIC, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gDSAKeyValueType(stream, &v2gKeyValueType->DSAKeyValue, eventCode);
					v2gKeyValueType->DSAKeyValue_isUsed = 1u;
					grammarID = 269;
					break;
				case 1:
					errn = decode_v2gRSAKeyValueType(stream, &v2gKeyValueType->RSAKeyValue, eventCode);
					v2gKeyValueType->RSAKeyValue_isUsed = 1u;
					grammarID = 269;
					break;
				case 2:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 269;
					break;
				case 3:
					grammarID = 270;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 269:
			/* Element[END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					done = 1;
					grammarID = 1;
					break;
				case 1:
					grammarID = 269;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 270:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DSAKeyValue), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}RSAKeyValue), START_ELEMENT_GENERIC, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gDSAKeyValueType(stream, &v2gKeyValueType->DSAKeyValue, eventCode);
					v2gKeyValueType->DSAKeyValue_isUsed = 1u;
					grammarID = 269;
					break;
				case 1:
					errn = decode_v2gRSAKeyValueType(stream, &v2gKeyValueType->RSAKeyValue, eventCode);
					v2gKeyValueType->RSAKeyValue_isUsed = 1u;
					grammarID = 269;
					break;
				case 2:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 269;
					break;
				case 3:
					grammarID = 270;
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,RSAKeyValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":Modulus,"http://www.w3.org/2000/09/xmldsig#":Exponent)',  derivedBy='RESTRICTION'.  */
int decode_v2gRSAKeyValueType(bitstream_t* stream, struct v2gRSAKeyValueType* v2gRSAKeyValueType, uint32_t eventCode) {
	int grammarID = 198;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 198:
			/* FirstStartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Modulus)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gRSAKeyValueType->Modulus.bytesLen);
							if (errn == 0) {
								errn =  (v2gRSAKeyValueType->Modulus.bytesLen) <= v2gRSAKeyValueType_Modulus_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gRSAKeyValueType->Modulus.bytesLen, v2gRSAKeyValueType->Modulus.bytes);
							}
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Modulus) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 199;
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
		case 199:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Exponent)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gRSAKeyValueType->Exponent.bytesLen);
							if (errn == 0) {
								errn =  (v2gRSAKeyValueType->Exponent.bytesLen) <= v2gRSAKeyValueType_Exponent_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gRSAKeyValueType->Exponent.bytesLen, v2gRSAKeyValueType->Exponent.bytes);
							}
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Exponent) ? */
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,RetrievalMethodType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":Transforms{0-1})',  derivedBy='RESTRICTION'.  */
int decode_v2gRetrievalMethodType(bitstream_t* stream, struct v2gRetrievalMethodType* v2gRetrievalMethodType, uint32_t eventCode) {
	int grammarID = 284;
	int done = 0;
	int errn;

	v2gRetrievalMethodType->URI_isUsed = 0u;
	v2gRetrievalMethodType->Type_isUsed = 0u;
	v2gRetrievalMethodType->Transforms_isUsed = 0u;
	while(!done) {
		switch(grammarID) {
		case 284:
			/* FirstStartTag[ATTRIBUTE[STRING](Type), ATTRIBUTE[STRING](URI), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transforms), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gRetrievalMethodType->Type.charactersLen);
					if (errn == 0) {
						errn =  (v2gRetrievalMethodType->Type.charactersLen - 2) <= v2gRetrievalMethodType_Type_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gRetrievalMethodType->Type.charactersLen >= 2) {
							v2gRetrievalMethodType->Type.charactersLen = (uint16_t)(v2gRetrievalMethodType->Type.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gRetrievalMethodType->Type.charactersLen, v2gRetrievalMethodType->Type.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gRetrievalMethodType->Type_isUsed = 1u;
					grammarID = 285;
					break;
				case 1:
					errn = decodeUnsignedInteger16(stream, &v2gRetrievalMethodType->URI.charactersLen);
					if (errn == 0) {
						errn =  (v2gRetrievalMethodType->URI.charactersLen - 2) <= v2gRetrievalMethodType_URI_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gRetrievalMethodType->URI.charactersLen >= 2) {
							v2gRetrievalMethodType->URI.charactersLen = (uint16_t)(v2gRetrievalMethodType->URI.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gRetrievalMethodType->URI.charactersLen, v2gRetrievalMethodType->URI.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gRetrievalMethodType->URI_isUsed = 1u;
					grammarID = 286;
					break;
				case 2:
					errn = decode_v2gTransformsType(stream, &v2gRetrievalMethodType->Transforms, eventCode);
					v2gRetrievalMethodType->Transforms_isUsed = 1u;
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
		case 285:
			/* StartTag[ATTRIBUTE[STRING](URI), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transforms), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gRetrievalMethodType->URI.charactersLen);
					if (errn == 0) {
						errn =  (v2gRetrievalMethodType->URI.charactersLen - 2) <= v2gRetrievalMethodType_URI_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gRetrievalMethodType->URI.charactersLen >= 2) {
							v2gRetrievalMethodType->URI.charactersLen = (uint16_t)(v2gRetrievalMethodType->URI.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gRetrievalMethodType->URI.charactersLen, v2gRetrievalMethodType->URI.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gRetrievalMethodType->URI_isUsed = 1u;
					grammarID = 286;
					break;
				case 1:
					errn = decode_v2gTransformsType(stream, &v2gRetrievalMethodType->Transforms, eventCode);
					v2gRetrievalMethodType->Transforms_isUsed = 1u;
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
		case 286:
			/* StartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transforms), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gTransformsType(stream, &v2gRetrievalMethodType->Transforms, eventCode);
					v2gRetrievalMethodType->Transforms_isUsed = 1u;
					grammarID = 5;
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,TransformsType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":Transform{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int decode_v2gTransformsType(bitstream_t* stream, struct v2gTransformsType* v2gTransformsType, uint32_t eventCode) {
	int grammarID = 105;
	int done = 0;
	int errn;

	v2gTransformsType->Transform.arrayLen = 0u;
	while(!done) {
		switch(grammarID) {
		case 105:
			/* FirstStartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transform)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gTransformsType->Transform.arrayLen < v2gTransformsType_Transform_ARRAY_SIZE) {
						errn = decode_v2gTransformType(stream, &v2gTransformsType->Transform.array[v2gTransformsType->Transform.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 106;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 106:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transform), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gTransformsType->Transform.arrayLen < v2gTransformsType_Transform_ARRAY_SIZE) {
						errn = decode_v2gTransformType(stream, &v2gTransformsType->Transform.array[v2gTransformsType->Transform.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 106;
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,TransformType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='((WC[##other:"http://www.w3.org/2000/09/xmldsig#"])|"http://www.w3.org/2000/09/xmldsig#":XPath){0-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
int decode_v2gTransformType(bitstream_t* stream, struct v2gTransformType* v2gTransformType, uint32_t eventCode) {
	int grammarID = 271;
	int done = 0;
	int errn;

	v2gTransformType->XPath.arrayLen = 0u;
	while(!done) {
		switch(grammarID) {
		case 271:
			/* FirstStartTag[ATTRIBUTE[STRING](Algorithm)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gTransformType->Algorithm.charactersLen);
					if (errn == 0) {
						errn =  (v2gTransformType->Algorithm.charactersLen - 2) <= v2gTransformType_Algorithm_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gTransformType->Algorithm.charactersLen >= 2) {
							v2gTransformType->Algorithm.charactersLen = (uint16_t)(v2gTransformType->Algorithm.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gTransformType->Algorithm.charactersLen, v2gTransformType->Algorithm.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					grammarID = 272;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 272:
			/* StartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}XPath), START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gTransformType->XPath.arrayLen < v2gTransformType_XPath_ARRAY_SIZE) {
						/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gTransformType->XPath.array[v2gTransformType->XPath.arrayLen].charactersLen);
								if (errn == 0) {
									errn =  (v2gTransformType->XPath.array[v2gTransformType->XPath.arrayLen].charactersLen - 2) <= v2gTransformType_XPath_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
								}
								if (errn == 0) {
									if (v2gTransformType->XPath.array[v2gTransformType->XPath.arrayLen].charactersLen >= 2) {
										v2gTransformType->XPath.array[v2gTransformType->XPath.arrayLen].charactersLen = (uint16_t)(v2gTransformType->XPath.array[v2gTransformType->XPath.arrayLen].charactersLen - 2); /* string table miss */
										errn = decodeCharacters(stream, v2gTransformType->XPath.array[v2gTransformType->XPath.arrayLen].charactersLen, v2gTransformType->XPath.array[v2gTransformType->XPath.arrayLen].characters);
									} else {
										/* string table hit */
										errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
									}
								}
								v2gTransformType->XPath.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}XPath) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 273;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 273;
					break;
				case 2:
					done = 1;
					grammarID = 1;
					break;
				case 3:
					grammarID = 273;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 273:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}XPath), START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gTransformType->XPath.arrayLen < v2gTransformType_XPath_ARRAY_SIZE) {
						/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gTransformType->XPath.array[v2gTransformType->XPath.arrayLen].charactersLen);
								if (errn == 0) {
									errn =  (v2gTransformType->XPath.array[v2gTransformType->XPath.arrayLen].charactersLen - 2) <= v2gTransformType_XPath_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
								}
								if (errn == 0) {
									if (v2gTransformType->XPath.array[v2gTransformType->XPath.arrayLen].charactersLen >= 2) {
										v2gTransformType->XPath.array[v2gTransformType->XPath.arrayLen].charactersLen = (uint16_t)(v2gTransformType->XPath.array[v2gTransformType->XPath.arrayLen].charactersLen - 2); /* string table miss */
										errn = decodeCharacters(stream, v2gTransformType->XPath.array[v2gTransformType->XPath.arrayLen].charactersLen, v2gTransformType->XPath.array[v2gTransformType->XPath.arrayLen].characters);
									} else {
										/* string table hit */
										errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
									}
								}
								v2gTransformType->XPath.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}XPath) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 273;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 273;
					break;
				case 2:
					done = 1;
					grammarID = 1;
					break;
				case 3:
					grammarID = 273;
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,X509DataType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("http://www.w3.org/2000/09/xmldsig#":X509IssuerSerial|"http://www.w3.org/2000/09/xmldsig#":X509SKI|"http://www.w3.org/2000/09/xmldsig#":X509SubjectName|"http://www.w3.org/2000/09/xmldsig#":X509Certificate|"http://www.w3.org/2000/09/xmldsig#":X509CRL|(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]))){1-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
int decode_v2gX509DataType(bitstream_t* stream, struct v2gX509DataType* v2gX509DataType, uint32_t eventCode) {
	int grammarID = 221;
	int done = 0;
	int errn;

	init_v2gX509DataType(v2gX509DataType);

	while(!done) {
		switch(grammarID) {
		case 221:
			/* FirstStartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509IssuerSerial), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509SKI), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509SubjectName), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509Certificate), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509CRL), START_ELEMENT_GENERIC] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gX509DataType->X509IssuerSerial.arrayLen < v2gX509DataType_X509IssuerSerial_ARRAY_SIZE) {
						errn = decode_v2gX509IssuerSerialType(stream, &v2gX509DataType->X509IssuerSerial.array[v2gX509DataType->X509IssuerSerial.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 222;
					break;
				case 1:
					if (v2gX509DataType->X509SKI.arrayLen < v2gX509DataType_X509SKI_ARRAY_SIZE) {
						/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gX509DataType->X509SKI.array[v2gX509DataType->X509SKI.arrayLen].bytesLen);
								if (errn == 0) {
									errn =  (v2gX509DataType->X509SKI.array[v2gX509DataType->X509SKI.arrayLen].bytesLen) <= v2gX509DataType_X509SKI_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
								}
								if (errn == 0) {
									errn = decodeBytes(stream, v2gX509DataType->X509SKI.array[v2gX509DataType->X509SKI.arrayLen].bytesLen, v2gX509DataType->X509SKI.array[v2gX509DataType->X509SKI.arrayLen].bytes);
								}
								v2gX509DataType->X509SKI.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509SKI) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 222;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 2:
					if (v2gX509DataType->X509SubjectName.arrayLen < v2gX509DataType_X509SubjectName_ARRAY_SIZE) {
						/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gX509DataType->X509SubjectName.array[v2gX509DataType->X509SubjectName.arrayLen].charactersLen);
								if (errn == 0) {
									errn =  (v2gX509DataType->X509SubjectName.array[v2gX509DataType->X509SubjectName.arrayLen].charactersLen - 2) <= v2gX509DataType_X509SubjectName_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
								}
								if (errn == 0) {
									if (v2gX509DataType->X509SubjectName.array[v2gX509DataType->X509SubjectName.arrayLen].charactersLen >= 2) {
										v2gX509DataType->X509SubjectName.array[v2gX509DataType->X509SubjectName.arrayLen].charactersLen = (uint16_t)(v2gX509DataType->X509SubjectName.array[v2gX509DataType->X509SubjectName.arrayLen].charactersLen - 2); /* string table miss */
										errn = decodeCharacters(stream, v2gX509DataType->X509SubjectName.array[v2gX509DataType->X509SubjectName.arrayLen].charactersLen, v2gX509DataType->X509SubjectName.array[v2gX509DataType->X509SubjectName.arrayLen].characters);
									} else {
										/* string table hit */
										errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
									}
								}
								v2gX509DataType->X509SubjectName.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509SubjectName) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 222;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 3:
					if (v2gX509DataType->X509Certificate.arrayLen < v2gX509DataType_X509Certificate_ARRAY_SIZE) {
						/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gX509DataType->X509Certificate.array[v2gX509DataType->X509Certificate.arrayLen].bytesLen);
								if (errn == 0) {
									errn =  (v2gX509DataType->X509Certificate.array[v2gX509DataType->X509Certificate.arrayLen].bytesLen) <= v2gX509DataType_X509Certificate_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
								}
								if (errn == 0) {
									errn = decodeBytes(stream, v2gX509DataType->X509Certificate.array[v2gX509DataType->X509Certificate.arrayLen].bytesLen, v2gX509DataType->X509Certificate.array[v2gX509DataType->X509Certificate.arrayLen].bytes);
								}
								v2gX509DataType->X509Certificate.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509Certificate) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 222;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 4:
					if (v2gX509DataType->X509CRL.arrayLen < v2gX509DataType_X509CRL_ARRAY_SIZE) {
						/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gX509DataType->X509CRL.array[v2gX509DataType->X509CRL.arrayLen].bytesLen);
								if (errn == 0) {
									errn =  (v2gX509DataType->X509CRL.array[v2gX509DataType->X509CRL.arrayLen].bytesLen) <= v2gX509DataType_X509CRL_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
								}
								if (errn == 0) {
									errn = decodeBytes(stream, v2gX509DataType->X509CRL.array[v2gX509DataType->X509CRL.arrayLen].bytesLen, v2gX509DataType->X509CRL.array[v2gX509DataType->X509CRL.arrayLen].bytes);
								}
								v2gX509DataType->X509CRL.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509CRL) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 222;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 5:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 222;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 222:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509IssuerSerial), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509SKI), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509SubjectName), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509Certificate), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509CRL), START_ELEMENT_GENERIC, END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gX509DataType->X509IssuerSerial.arrayLen < v2gX509DataType_X509IssuerSerial_ARRAY_SIZE) {
						errn = decode_v2gX509IssuerSerialType(stream, &v2gX509DataType->X509IssuerSerial.array[v2gX509DataType->X509IssuerSerial.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 222;
					break;
				case 1:
					if (v2gX509DataType->X509SKI.arrayLen < v2gX509DataType_X509SKI_ARRAY_SIZE) {
						/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gX509DataType->X509SKI.array[v2gX509DataType->X509SKI.arrayLen].bytesLen);
								if (errn == 0) {
									errn =  (v2gX509DataType->X509SKI.array[v2gX509DataType->X509SKI.arrayLen].bytesLen) <= v2gX509DataType_X509SKI_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
								}
								if (errn == 0) {
									errn = decodeBytes(stream, v2gX509DataType->X509SKI.array[v2gX509DataType->X509SKI.arrayLen].bytesLen, v2gX509DataType->X509SKI.array[v2gX509DataType->X509SKI.arrayLen].bytes);
								}
								v2gX509DataType->X509SKI.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509SKI) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 222;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 2:
					if (v2gX509DataType->X509SubjectName.arrayLen < v2gX509DataType_X509SubjectName_ARRAY_SIZE) {
						/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gX509DataType->X509SubjectName.array[v2gX509DataType->X509SubjectName.arrayLen].charactersLen);
								if (errn == 0) {
									errn =  (v2gX509DataType->X509SubjectName.array[v2gX509DataType->X509SubjectName.arrayLen].charactersLen - 2) <= v2gX509DataType_X509SubjectName_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
								}
								if (errn == 0) {
									if (v2gX509DataType->X509SubjectName.array[v2gX509DataType->X509SubjectName.arrayLen].charactersLen >= 2) {
										v2gX509DataType->X509SubjectName.array[v2gX509DataType->X509SubjectName.arrayLen].charactersLen = (uint16_t)(v2gX509DataType->X509SubjectName.array[v2gX509DataType->X509SubjectName.arrayLen].charactersLen - 2); /* string table miss */
										errn = decodeCharacters(stream, v2gX509DataType->X509SubjectName.array[v2gX509DataType->X509SubjectName.arrayLen].charactersLen, v2gX509DataType->X509SubjectName.array[v2gX509DataType->X509SubjectName.arrayLen].characters);
									} else {
										/* string table hit */
										errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
									}
								}
								v2gX509DataType->X509SubjectName.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509SubjectName) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 222;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 3:
					if (v2gX509DataType->X509Certificate.arrayLen < v2gX509DataType_X509Certificate_ARRAY_SIZE) {
						/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gX509DataType->X509Certificate.array[v2gX509DataType->X509Certificate.arrayLen].bytesLen);
								if (errn == 0) {
									errn =  (v2gX509DataType->X509Certificate.array[v2gX509DataType->X509Certificate.arrayLen].bytesLen) <= v2gX509DataType_X509Certificate_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
								}
								if (errn == 0) {
									errn = decodeBytes(stream, v2gX509DataType->X509Certificate.array[v2gX509DataType->X509Certificate.arrayLen].bytesLen, v2gX509DataType->X509Certificate.array[v2gX509DataType->X509Certificate.arrayLen].bytes);
								}
								v2gX509DataType->X509Certificate.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509Certificate) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 222;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 4:
					if (v2gX509DataType->X509CRL.arrayLen < v2gX509DataType_X509CRL_ARRAY_SIZE) {
						/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gX509DataType->X509CRL.array[v2gX509DataType->X509CRL.arrayLen].bytesLen);
								if (errn == 0) {
									errn =  (v2gX509DataType->X509CRL.array[v2gX509DataType->X509CRL.arrayLen].bytesLen) <= v2gX509DataType_X509CRL_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
								}
								if (errn == 0) {
									errn = decodeBytes(stream, v2gX509DataType->X509CRL.array[v2gX509DataType->X509CRL.arrayLen].bytesLen, v2gX509DataType->X509CRL.array[v2gX509DataType->X509CRL.arrayLen].bytes);
								}
								v2gX509DataType->X509CRL.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509CRL) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 222;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 5:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 222;
					break;
				case 6:
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,PGPDataType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("http://www.w3.org/2000/09/xmldsig#":PGPKeyID,"http://www.w3.org/2000/09/xmldsig#":PGPKeyPacket{0-1},(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]){0-UNBOUNDED})|("http://www.w3.org/2000/09/xmldsig#":PGPKeyPacket,(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]){0-UNBOUNDED}))',  derivedBy='RESTRICTION'.  */
int decode_v2gPGPDataType(bitstream_t* stream, struct v2gPGPDataType* v2gPGPDataType, uint32_t eventCode) {
	int grammarID = 158;
	int done = 0;
	int errn;

	v2gPGPDataType->PGPKeyID_isUsed = 0u;
	v2gPGPDataType->PGPKeyPacket_isUsed = 0u;
	while(!done) {
		switch(grammarID) {
		case 158:
			/* FirstStartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PGPKeyID), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PGPKeyPacket)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gPGPDataType->PGPKeyID.bytesLen);
							if (errn == 0) {
								errn =  (v2gPGPDataType->PGPKeyID.bytesLen) <= v2gPGPDataType_PGPKeyID_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gPGPDataType->PGPKeyID.bytesLen, v2gPGPDataType->PGPKeyID.bytes);
							}
							v2gPGPDataType->PGPKeyID_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PGPKeyID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 159;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gPGPDataType->PGPKeyPacket.bytesLen);
							if (errn == 0) {
								errn =  (v2gPGPDataType->PGPKeyPacket.bytesLen) <= v2gPGPDataType_PGPKeyPacket_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gPGPDataType->PGPKeyPacket.bytesLen, v2gPGPDataType->PGPKeyPacket.bytes);
							}
							v2gPGPDataType->PGPKeyPacket_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PGPKeyPacket) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 160;
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
		case 159:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PGPKeyPacket), START_ELEMENT_GENERIC, END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gPGPDataType->PGPKeyPacket.bytesLen);
							if (errn == 0) {
								errn =  (v2gPGPDataType->PGPKeyPacket.bytesLen) <= v2gPGPDataType_PGPKeyPacket_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gPGPDataType->PGPKeyPacket.bytesLen, v2gPGPDataType->PGPKeyPacket.bytes);
							}
							v2gPGPDataType->PGPKeyPacket_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PGPKeyPacket) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 160;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 160;
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
		case 160:
			/* Element[START_ELEMENT_GENERIC, END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 160;
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,SPKIDataType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":SPKISexp,(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]){0-1}){1-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
int decode_v2gSPKIDataType(bitstream_t* stream, struct v2gSPKIDataType* v2gSPKIDataType, uint32_t eventCode) {
	int grammarID = 39;
	int done = 0;
	int errn;

	v2gSPKIDataType->SPKISexp.arrayLen = 0u;

	while(!done) {
		switch(grammarID) {
		case 39:
			/* FirstStartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SPKISexp)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSPKIDataType->SPKISexp.arrayLen < v2gSPKIDataType_SPKISexp_ARRAY_SIZE) {
						/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gSPKIDataType->SPKISexp.array[v2gSPKIDataType->SPKISexp.arrayLen].bytesLen);
								if (errn == 0) {
									errn =  (v2gSPKIDataType->SPKISexp.array[v2gSPKIDataType->SPKISexp.arrayLen].bytesLen) <= v2gSPKIDataType_SPKISexp_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
								}
								if (errn == 0) {
									errn = decodeBytes(stream, v2gSPKIDataType->SPKISexp.array[v2gSPKIDataType->SPKISexp.arrayLen].bytesLen, v2gSPKIDataType->SPKISexp.array[v2gSPKIDataType->SPKISexp.arrayLen].bytes);
								}
								v2gSPKIDataType->SPKISexp.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SPKISexp) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 40;
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
		case 40:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SPKISexp), START_ELEMENT_GENERIC, END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSPKIDataType->SPKISexp.arrayLen < v2gSPKIDataType_SPKISexp_ARRAY_SIZE) {
						/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gSPKIDataType->SPKISexp.array[v2gSPKIDataType->SPKISexp.arrayLen].bytesLen);
								if (errn == 0) {
									errn =  (v2gSPKIDataType->SPKISexp.array[v2gSPKIDataType->SPKISexp.arrayLen].bytesLen) <= v2gSPKIDataType_SPKISexp_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
								}
								if (errn == 0) {
									errn = decodeBytes(stream, v2gSPKIDataType->SPKISexp.array[v2gSPKIDataType->SPKISexp.arrayLen].bytesLen, v2gSPKIDataType->SPKISexp.array[v2gSPKIDataType->SPKISexp.arrayLen].bytes);
								}
								v2gSPKIDataType->SPKISexp.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SPKISexp) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 40;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 41;
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
		case 41:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SPKISexp), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSPKIDataType->SPKISexp.arrayLen < v2gSPKIDataType_SPKISexp_ARRAY_SIZE) {
						/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeUnsignedInteger16(stream, &v2gSPKIDataType->SPKISexp.array[v2gSPKIDataType->SPKISexp.arrayLen].bytesLen);
								if (errn == 0) {
									errn =  (v2gSPKIDataType->SPKISexp.array[v2gSPKIDataType->SPKISexp.arrayLen].bytesLen) <= v2gSPKIDataType_SPKISexp_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
								}
								if (errn == 0) {
									errn = decodeBytes(stream, v2gSPKIDataType->SPKISexp.array[v2gSPKIDataType->SPKISexp.arrayLen].bytesLen, v2gSPKIDataType->SPKISexp.array[v2gSPKIDataType->SPKISexp.arrayLen].bytes);
								}
								v2gSPKIDataType->SPKISexp.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SPKISexp) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 40;
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ServiceParameterListType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":ParameterSet{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int decode_v2gServiceParameterListType(bitstream_t* stream, struct v2gServiceParameterListType* v2gServiceParameterListType, uint32_t eventCode) {
	int grammarID = 161;
	int done = 0;
	int errn;

	v2gServiceParameterListType->ParameterSet.arrayLen = 0u;
	while(!done) {
		switch(grammarID) {
		case 161:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ParameterSet)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gServiceParameterListType->ParameterSet.arrayLen < v2gServiceParameterListType_ParameterSet_ARRAY_SIZE) {
						errn = decode_v2gParameterSetType(stream, &v2gServiceParameterListType->ParameterSet.array[v2gServiceParameterListType->ParameterSet.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 162;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 162:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ParameterSet), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gServiceParameterListType->ParameterSet.arrayLen < v2gServiceParameterListType_ParameterSet_ARRAY_SIZE) {
						errn = decode_v2gParameterSetType(stream, &v2gServiceParameterListType->ParameterSet.array[v2gServiceParameterListType->ParameterSet.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 162;
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ParameterSetType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":ParameterSetID,"urn:iso:15118:2:2013:MsgDataTypes":Parameter{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int decode_v2gParameterSetType(bitstream_t* stream, struct v2gParameterSetType* v2gParameterSetType, uint32_t eventCode) {
	int grammarID = 51;
	int done = 0;
	int errn;

	v2gParameterSetType->Parameter.arrayLen = 0u;

	while(!done) {
		switch(grammarID) {
		case 51:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ParameterSetID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeInteger16(stream, &v2gParameterSetType->ParameterSetID);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ParameterSetID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 52;
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
		case 52:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Parameter)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gParameterSetType->Parameter.arrayLen < v2gParameterSetType_Parameter_ARRAY_SIZE) {
						errn = decode_v2gParameterType(stream, &v2gParameterSetType->Parameter.array[v2gParameterSetType->Parameter.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 53;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 53:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Parameter), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gParameterSetType->Parameter.arrayLen < v2gParameterSetType_Parameter_ARRAY_SIZE) {
						errn = decode_v2gParameterType(stream, &v2gParameterSetType->Parameter.array[v2gParameterSetType->Parameter.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 53;
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ParameterType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":boolValue|"urn:iso:15118:2:2013:MsgDataTypes":byteValue|"urn:iso:15118:2:2013:MsgDataTypes":shortValue|"urn:iso:15118:2:2013:MsgDataTypes":intValue|"urn:iso:15118:2:2013:MsgDataTypes":physicalValue|"urn:iso:15118:2:2013:MsgDataTypes":stringValue)',  derivedBy='RESTRICTION'.  */
int decode_v2gParameterType(bitstream_t* stream, struct v2gParameterType* v2gParameterType, uint32_t eventCode) {
	int grammarID = 274;
	int done = 0;
	int errn;
	uint32_t uint32;

	init_v2gParameterType(v2gParameterType);

	while(!done) {
		switch(grammarID) {
		case 274:
			/* FirstStartTag[ATTRIBUTE[STRING]({urn:iso:15118:2:2013:MsgDataTypes}Name)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gParameterType->Name.charactersLen);
					if (errn == 0) {
						errn =  (v2gParameterType->Name.charactersLen - 2) <= v2gParameterType_Name_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gParameterType->Name.charactersLen >= 2) {
							v2gParameterType->Name.charactersLen = (uint16_t)(v2gParameterType->Name.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gParameterType->Name.charactersLen, v2gParameterType->Name.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					grammarID = 275;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 275:
			/* StartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}boolValue), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}byteValue), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}shortValue), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}intValue), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}physicalValue), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}stringValue)] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gParameterType->boolValue);
							v2gParameterType->boolValue_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}boolValue) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 5;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					/* First(xsi:type)StartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 8, &(uint32));
							v2gParameterType->byteValue = (int8_t)(uint32 -128);
							v2gParameterType->byteValue_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}byteValue) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 5;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 2:
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeInteger16(stream, &v2gParameterType->shortValue);
							v2gParameterType->shortValue_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}shortValue) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 5;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 3:
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeInteger32(stream, &v2gParameterType->intValue);
							v2gParameterType->intValue_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}intValue) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 5;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 4:
					errn = decode_v2gPhysicalValueType(stream, &v2gParameterType->physicalValue, eventCode);
					v2gParameterType->physicalValue_isUsed = 1u;
					grammarID = 5;
					break;
				case 5:
					/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gParameterType->stringValue.charactersLen);
							if (errn == 0) {
								errn =  (v2gParameterType->stringValue.charactersLen - 2) <= v2gParameterType_stringValue_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
							}
							if (errn == 0) {
								if (v2gParameterType->stringValue.charactersLen >= 2) {
									v2gParameterType->stringValue.charactersLen = (uint16_t)(v2gParameterType->stringValue.charactersLen - 2); /* string table miss */
									errn = decodeCharacters(stream, v2gParameterType->stringValue.charactersLen, v2gParameterType->stringValue.characters);
								} else {
									/* string table hit */
									errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
								}
							}
							v2gParameterType->stringValue_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}stringValue) ? */
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,ManifestType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":Reference{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int decode_v2gManifestType(bitstream_t* stream, struct v2gManifestType* v2gManifestType, uint32_t eventCode) {
	int grammarID = 48;
	int done = 0;
	int errn;

	v2gManifestType->Id_isUsed = 0u;
	v2gManifestType->Reference.arrayLen = 0u;

	while(!done) {
		switch(grammarID) {
		case 48:
			/* FirstStartTag[ATTRIBUTE[STRING](Id), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Reference)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gManifestType->Id.charactersLen);
					if (errn == 0) {
						errn =  (v2gManifestType->Id.charactersLen - 2) <= v2gManifestType_Id_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gManifestType->Id.charactersLen >= 2) {
							v2gManifestType->Id.charactersLen = (uint16_t)(v2gManifestType->Id.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gManifestType->Id.charactersLen, v2gManifestType->Id.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gManifestType->Id_isUsed = 1u;
					grammarID = 49;
					break;
				case 1:
					if (v2gManifestType->Reference.arrayLen < v2gManifestType_Reference_ARRAY_SIZE) {
						errn = decode_v2gReferenceType(stream, &v2gManifestType->Reference.array[v2gManifestType->Reference.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 50;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 49:
			/* StartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Reference)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gManifestType->Reference.arrayLen < v2gManifestType_Reference_ARRAY_SIZE) {
						errn = decode_v2gReferenceType(stream, &v2gManifestType->Reference.array[v2gManifestType->Reference.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 50;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 50:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Reference), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gManifestType->Reference.arrayLen < v2gManifestType_Reference_ARRAY_SIZE) {
						errn = decode_v2gReferenceType(stream, &v2gManifestType->Reference.array[v2gManifestType->Reference.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 50;
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,ReferenceType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":Transforms{0-1},"http://www.w3.org/2000/09/xmldsig#":DigestMethod,"http://www.w3.org/2000/09/xmldsig#":DigestValue)',  derivedBy='RESTRICTION'.  */
int decode_v2gReferenceType(bitstream_t* stream, struct v2gReferenceType* v2gReferenceType, uint32_t eventCode) {
	int grammarID = 192;
	int done = 0;
	int errn;

	init_v2gReferenceType(v2gReferenceType);

	while(!done) {
		switch(grammarID) {
		case 192:
			/* FirstStartTag[ATTRIBUTE[STRING](Id), ATTRIBUTE[STRING](Type), ATTRIBUTE[STRING](URI), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transforms), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DigestMethod)] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gReferenceType->Id.charactersLen);
					if (errn == 0) {
						errn =  (v2gReferenceType->Id.charactersLen - 2) <= v2gReferenceType_Id_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gReferenceType->Id.charactersLen >= 2) {
							v2gReferenceType->Id.charactersLen = (uint16_t)(v2gReferenceType->Id.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gReferenceType->Id.charactersLen, v2gReferenceType->Id.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gReferenceType->Id_isUsed = 1u;
					grammarID = 193;
					break;
				case 1:
					errn = decodeUnsignedInteger16(stream, &v2gReferenceType->Type.charactersLen);
					if (errn == 0) {
						errn =  (v2gReferenceType->Type.charactersLen - 2) <= v2gReferenceType_Type_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gReferenceType->Type.charactersLen >= 2) {
							v2gReferenceType->Type.charactersLen = (uint16_t)(v2gReferenceType->Type.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gReferenceType->Type.charactersLen, v2gReferenceType->Type.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gReferenceType->Type_isUsed = 1u;
					grammarID = 194;
					break;
				case 2:
					errn = decodeUnsignedInteger16(stream, &v2gReferenceType->URI.charactersLen);
					if (errn == 0) {
						errn =  (v2gReferenceType->URI.charactersLen - 2) <= v2gReferenceType_URI_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gReferenceType->URI.charactersLen >= 2) {
							v2gReferenceType->URI.charactersLen = (uint16_t)(v2gReferenceType->URI.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gReferenceType->URI.charactersLen, v2gReferenceType->URI.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gReferenceType->URI_isUsed = 1u;
					grammarID = 195;
					break;
				case 3:
					errn = decode_v2gTransformsType(stream, &v2gReferenceType->Transforms, eventCode);
					v2gReferenceType->Transforms_isUsed = 1u;
					grammarID = 196;
					break;
				case 4:
					errn = decode_v2gDigestMethodType(stream, &v2gReferenceType->DigestMethod, eventCode);
					grammarID = 197;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 193:
			/* StartTag[ATTRIBUTE[STRING](Type), ATTRIBUTE[STRING](URI), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transforms), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DigestMethod)] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gReferenceType->Type.charactersLen);
					if (errn == 0) {
						errn =  (v2gReferenceType->Type.charactersLen - 2) <= v2gReferenceType_Type_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gReferenceType->Type.charactersLen >= 2) {
							v2gReferenceType->Type.charactersLen = (uint16_t)(v2gReferenceType->Type.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gReferenceType->Type.charactersLen, v2gReferenceType->Type.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gReferenceType->Type_isUsed = 1u;
					grammarID = 194;
					break;
				case 1:
					errn = decodeUnsignedInteger16(stream, &v2gReferenceType->URI.charactersLen);
					if (errn == 0) {
						errn =  (v2gReferenceType->URI.charactersLen - 2) <= v2gReferenceType_URI_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gReferenceType->URI.charactersLen >= 2) {
							v2gReferenceType->URI.charactersLen = (uint16_t)(v2gReferenceType->URI.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gReferenceType->URI.charactersLen, v2gReferenceType->URI.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gReferenceType->URI_isUsed = 1u;
					grammarID = 195;
					break;
				case 2:
					errn = decode_v2gTransformsType(stream, &v2gReferenceType->Transforms, eventCode);
					v2gReferenceType->Transforms_isUsed = 1u;
					grammarID = 196;
					break;
				case 3:
					errn = decode_v2gDigestMethodType(stream, &v2gReferenceType->DigestMethod, eventCode);
					grammarID = 197;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 194:
			/* StartTag[ATTRIBUTE[STRING](URI), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transforms), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DigestMethod)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gReferenceType->URI.charactersLen);
					if (errn == 0) {
						errn =  (v2gReferenceType->URI.charactersLen - 2) <= v2gReferenceType_URI_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gReferenceType->URI.charactersLen >= 2) {
							v2gReferenceType->URI.charactersLen = (uint16_t)(v2gReferenceType->URI.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gReferenceType->URI.charactersLen, v2gReferenceType->URI.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gReferenceType->URI_isUsed = 1u;
					grammarID = 195;
					break;
				case 1:
					errn = decode_v2gTransformsType(stream, &v2gReferenceType->Transforms, eventCode);
					v2gReferenceType->Transforms_isUsed = 1u;
					grammarID = 196;
					break;
				case 2:
					errn = decode_v2gDigestMethodType(stream, &v2gReferenceType->DigestMethod, eventCode);
					grammarID = 197;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 195:
			/* StartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transforms), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DigestMethod)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gTransformsType(stream, &v2gReferenceType->Transforms, eventCode);
					v2gReferenceType->Transforms_isUsed = 1u;
					grammarID = 196;
					break;
				case 1:
					errn = decode_v2gDigestMethodType(stream, &v2gReferenceType->DigestMethod, eventCode);
					grammarID = 197;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 196:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DigestMethod)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gDigestMethodType(stream, &v2gReferenceType->DigestMethod, eventCode);
					grammarID = 197;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 197:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DigestValue)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gReferenceType->DigestValue.bytesLen);
							if (errn == 0) {
								errn =  (v2gReferenceType->DigestValue.bytesLen) <= v2gReferenceType_DigestValue_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gReferenceType->DigestValue.bytesLen, v2gReferenceType->DigestValue.bytes);
							}
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DigestValue) ? */
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,ObjectType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='((WC[##any])){0-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
int decode_v2gObjectType(bitstream_t* stream, struct v2gObjectType* v2gObjectType, uint32_t eventCode) {
	int grammarID = 44;
	int done = 0;
	int errn;

	v2gObjectType->Id_isUsed = 0u;
	v2gObjectType->MimeType_isUsed = 0u;
	v2gObjectType->Encoding_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 44:
			/* FirstStartTag[ATTRIBUTE[STRING](Encoding), ATTRIBUTE[STRING](Id), ATTRIBUTE[STRING](MimeType), START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gObjectType->Encoding.charactersLen);
					if (errn == 0) {
						errn =  (v2gObjectType->Encoding.charactersLen - 2) <= v2gObjectType_Encoding_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gObjectType->Encoding.charactersLen >= 2) {
							v2gObjectType->Encoding.charactersLen = (uint16_t)(v2gObjectType->Encoding.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gObjectType->Encoding.charactersLen, v2gObjectType->Encoding.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gObjectType->Encoding_isUsed = 1u;
					grammarID = 45;
					break;
				case 1:
					errn = decodeUnsignedInteger16(stream, &v2gObjectType->Id.charactersLen);
					if (errn == 0) {
						errn =  (v2gObjectType->Id.charactersLen - 2) <= v2gObjectType_Id_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gObjectType->Id.charactersLen >= 2) {
							v2gObjectType->Id.charactersLen = (uint16_t)(v2gObjectType->Id.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gObjectType->Id.charactersLen, v2gObjectType->Id.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gObjectType->Id_isUsed = 1u;
					grammarID = 46;
					break;
				case 2:
					errn = decodeUnsignedInteger16(stream, &v2gObjectType->MimeType.charactersLen);
					if (errn == 0) {
						errn =  (v2gObjectType->MimeType.charactersLen - 2) <= v2gObjectType_MimeType_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gObjectType->MimeType.charactersLen >= 2) {
							v2gObjectType->MimeType.charactersLen = (uint16_t)(v2gObjectType->MimeType.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gObjectType->MimeType.charactersLen, v2gObjectType->MimeType.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gObjectType->MimeType_isUsed = 1u;
					grammarID = 47;
					break;
				case 3:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 35;
					break;
				case 4:
					done = 1;
					grammarID = 1;
					break;
				case 5:
					grammarID = 35;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 45:
			/* StartTag[ATTRIBUTE[STRING](Id), ATTRIBUTE[STRING](MimeType), START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gObjectType->Id.charactersLen);
					if (errn == 0) {
						errn =  (v2gObjectType->Id.charactersLen - 2) <= v2gObjectType_Id_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gObjectType->Id.charactersLen >= 2) {
							v2gObjectType->Id.charactersLen = (uint16_t)(v2gObjectType->Id.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gObjectType->Id.charactersLen, v2gObjectType->Id.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gObjectType->Id_isUsed = 1u;
					grammarID = 46;
					break;
				case 1:
					errn = decodeUnsignedInteger16(stream, &v2gObjectType->MimeType.charactersLen);
					if (errn == 0) {
						errn =  (v2gObjectType->MimeType.charactersLen - 2) <= v2gObjectType_MimeType_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gObjectType->MimeType.charactersLen >= 2) {
							v2gObjectType->MimeType.charactersLen = (uint16_t)(v2gObjectType->MimeType.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gObjectType->MimeType.charactersLen, v2gObjectType->MimeType.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gObjectType->MimeType_isUsed = 1u;
					grammarID = 47;
					break;
				case 2:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 35;
					break;
				case 3:
					done = 1;
					grammarID = 1;
					break;
				case 4:
					grammarID = 35;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 46:
			/* StartTag[ATTRIBUTE[STRING](MimeType), START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gObjectType->MimeType.charactersLen);
					if (errn == 0) {
						errn =  (v2gObjectType->MimeType.charactersLen - 2) <= v2gObjectType_MimeType_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gObjectType->MimeType.charactersLen >= 2) {
							v2gObjectType->MimeType.charactersLen = (uint16_t)(v2gObjectType->MimeType.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gObjectType->MimeType.charactersLen, v2gObjectType->MimeType.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gObjectType->MimeType_isUsed = 1u;
					grammarID = 47;
					break;
				case 1:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 35;
					break;
				case 2:
					done = 1;
					grammarID = 1;
					break;
				case 3:
					grammarID = 35;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 47:
			/* StartTag[START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 35;
					break;
				case 1:
					done = 1;
					grammarID = 1;
					break;
				case 2:
					grammarID = 35;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 35:
			/* Element[START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 35;
					break;
				case 1:
					done = 1;
					grammarID = 1;
					break;
				case 2:
					grammarID = 35;
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SelectedServiceListType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":SelectedService{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int decode_v2gSelectedServiceListType(bitstream_t* stream, struct v2gSelectedServiceListType* v2gSelectedServiceListType, uint32_t eventCode) {
	int grammarID = 238;
	int done = 0;
	int errn;

	v2gSelectedServiceListType->SelectedService.arrayLen = 0u;

	while(!done) {
		switch(grammarID) {
		case 238:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SelectedService)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSelectedServiceListType->SelectedService.arrayLen < v2gSelectedServiceListType_SelectedService_ARRAY_SIZE) {
						errn = decode_v2gSelectedServiceType(stream, &v2gSelectedServiceListType->SelectedService.array[v2gSelectedServiceListType->SelectedService.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 239;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 239:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SelectedService), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSelectedServiceListType->SelectedService.arrayLen < v2gSelectedServiceListType_SelectedService_ARRAY_SIZE) {
						errn = decode_v2gSelectedServiceType(stream, &v2gSelectedServiceListType->SelectedService.array[v2gSelectedServiceListType->SelectedService.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 239;
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SelectedServiceType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":ServiceID,"urn:iso:15118:2:2013:MsgDataTypes":ParameterSetID{0-1})',  derivedBy='RESTRICTION'.  */
int decode_v2gSelectedServiceType(bitstream_t* stream, struct v2gSelectedServiceType* v2gSelectedServiceType, uint32_t eventCode) {
	int grammarID = 76;
	int done = 0;
	int errn;

	v2gSelectedServiceType->ParameterSetID_isUsed = 0u;
	while(!done) {
		switch(grammarID) {
		case 76:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gSelectedServiceType->ServiceID);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 77;
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
		case 77:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ParameterSetID), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeInteger16(stream, &v2gSelectedServiceType->ParameterSetID);
							v2gSelectedServiceType->ParameterSetID_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ParameterSetID) ? */
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ChargingProfileType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":ProfileEntry{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int decode_v2gChargingProfileType(bitstream_t* stream, struct v2gChargingProfileType* v2gChargingProfileType, uint32_t eventCode) {
	int grammarID = 95;
	int done = 0;
	int errn;

	v2gChargingProfileType->ProfileEntry.arrayLen = 0u;

	while(!done) {
		switch(grammarID) {
		case 95:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ProfileEntry)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gChargingProfileType->ProfileEntry.arrayLen < v2gChargingProfileType_ProfileEntry_ARRAY_SIZE) {
						errn = decode_v2gProfileEntryType(stream, &v2gChargingProfileType->ProfileEntry.array[v2gChargingProfileType->ProfileEntry.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 96;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 96:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ProfileEntry), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gChargingProfileType->ProfileEntry.arrayLen < v2gChargingProfileType_ProfileEntry_ARRAY_SIZE) {
						errn = decode_v2gProfileEntryType(stream, &v2gChargingProfileType->ProfileEntry.array[v2gChargingProfileType->ProfileEntry.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 96;
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ProfileEntryType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":ChargingProfileEntryStart,"urn:iso:15118:2:2013:MsgDataTypes":ChargingProfileEntryMaxPower,"urn:iso:15118:2:2013:MsgDataTypes":ChargingProfileEntryMaxNumberOfPhasesInUse{0-1})',  derivedBy='RESTRICTION'.  */
int decode_v2gProfileEntryType(bitstream_t* stream, struct v2gProfileEntryType* v2gProfileEntryType, uint32_t eventCode) {
	int grammarID = 111;
	int done = 0;
	int errn;
	uint32_t uint32;

	v2gProfileEntryType->ChargingProfileEntryMaxNumberOfPhasesInUse_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 111:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ChargingProfileEntryStart)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger32(stream, &v2gProfileEntryType->ChargingProfileEntryStart);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ChargingProfileEntryStart) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 112;
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
		case 112:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ChargingProfileEntryMaxPower)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gProfileEntryType->ChargingProfileEntryMaxPower, eventCode);
					grammarID = 113;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 113:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ChargingProfileEntryMaxNumberOfPhasesInUse), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 2, &(uint32));
							v2gProfileEntryType->ChargingProfileEntryMaxNumberOfPhasesInUse = (int8_t)(uint32 + 1);
							v2gProfileEntryType->ChargingProfileEntryMaxNumberOfPhasesInUse_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ChargingProfileEntryMaxNumberOfPhasesInUse) ? */
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PaymentOptionListType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":PaymentOption{1-2})',  derivedBy='RESTRICTION'.  */
int decode_v2gPaymentOptionListType(bitstream_t* stream, struct v2gPaymentOptionListType* v2gPaymentOptionListType, uint32_t eventCode) {
	int grammarID = 63;
	int done = 0;
	int errn;
	uint32_t uint32;

	v2gPaymentOptionListType->PaymentOption.arrayLen = 0u;

	while(!done) {
		switch(grammarID) {
		case 63:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}PaymentOption)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gPaymentOptionListType->PaymentOption.arrayLen < v2gPaymentOptionListType_PaymentOption_ARRAY_SIZE) {
						/* FirstStartTag[CHARACTERS[ENUMERATION]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeNBitUnsignedInteger(stream, 1, &uint32);
								v2gPaymentOptionListType->PaymentOption.array[v2gPaymentOptionListType->PaymentOption.arrayLen] = (v2gpaymentOptionType) uint32;
								v2gPaymentOptionListType->PaymentOption.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}PaymentOption) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 64;
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
		case 64:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}PaymentOption), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gPaymentOptionListType->PaymentOption.arrayLen < v2gPaymentOptionListType_PaymentOption_ARRAY_SIZE) {
						/* FirstStartTag[CHARACTERS[ENUMERATION]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeNBitUnsignedInteger(stream, 1, &uint32);
								v2gPaymentOptionListType->PaymentOption.array[v2gPaymentOptionListType->PaymentOption.arrayLen] = (v2gpaymentOptionType) uint32;
								v2gPaymentOptionListType->PaymentOption.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}PaymentOption) ? */
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ChargeServiceType',  base type name='ServiceType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":ServiceID,"urn:iso:15118:2:2013:MsgDataTypes":ServiceName{0-1},"urn:iso:15118:2:2013:MsgDataTypes":ServiceCategory,"urn:iso:15118:2:2013:MsgDataTypes":ServiceScope{0-1},"urn:iso:15118:2:2013:MsgDataTypes":FreeService),("urn:iso:15118:2:2013:MsgDataTypes":SupportedEnergyTransferMode))',  derivedBy='EXTENSION'.  */
int decode_v2gChargeServiceType(bitstream_t* stream, struct v2gChargeServiceType* v2gChargeServiceType, uint32_t eventCode) {
	int grammarID = 240;
	int done = 0;
	int errn;
	uint32_t uint32;

	v2gChargeServiceType->ServiceName_isUsed = 0u;
	v2gChargeServiceType->ServiceScope_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 240:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gChargeServiceType->ServiceID);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 241;
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
		case 241:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceName), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceCategory)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gChargeServiceType->ServiceName.charactersLen);
							if (errn == 0) {
								errn =  (v2gChargeServiceType->ServiceName.charactersLen - 2) <= v2gChargeServiceType_ServiceName_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
							}
							if (errn == 0) {
								if (v2gChargeServiceType->ServiceName.charactersLen >= 2) {
									v2gChargeServiceType->ServiceName.charactersLen = (uint16_t)(v2gChargeServiceType->ServiceName.charactersLen - 2); /* string table miss */
									errn = decodeCharacters(stream, v2gChargeServiceType->ServiceName.charactersLen, v2gChargeServiceType->ServiceName.characters);
								} else {
									/* string table hit */
									errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
								}
							}
							v2gChargeServiceType->ServiceName_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceName) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 242;
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
							v2gChargeServiceType->ServiceCategory = (v2gserviceCategoryType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceCategory) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 243;
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
		case 242:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceCategory)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 2, &uint32);
							v2gChargeServiceType->ServiceCategory = (v2gserviceCategoryType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceCategory) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 243;
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
		case 243:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceScope), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FreeService)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gChargeServiceType->ServiceScope.charactersLen);
							if (errn == 0) {
								errn =  (v2gChargeServiceType->ServiceScope.charactersLen - 2) <= v2gChargeServiceType_ServiceScope_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
							}
							if (errn == 0) {
								if (v2gChargeServiceType->ServiceScope.charactersLen >= 2) {
									v2gChargeServiceType->ServiceScope.charactersLen = (uint16_t)(v2gChargeServiceType->ServiceScope.charactersLen - 2); /* string table miss */
									errn = decodeCharacters(stream, v2gChargeServiceType->ServiceScope.charactersLen, v2gChargeServiceType->ServiceScope.characters);
								} else {
									/* string table hit */
									errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
								}
							}
							v2gChargeServiceType->ServiceScope_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceScope) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 244;
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
							errn = decodeBoolean(stream, &v2gChargeServiceType->FreeService);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FreeService) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 245;
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
		case 244:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FreeService)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gChargeServiceType->FreeService);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FreeService) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 245;
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
		case 245:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SupportedEnergyTransferMode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gSupportedEnergyTransferModeType(stream, &v2gChargeServiceType->SupportedEnergyTransferMode, eventCode);
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SupportedEnergyTransferModeType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":EnergyTransferMode{1-6})',  derivedBy='RESTRICTION'.  */
int decode_v2gSupportedEnergyTransferModeType(bitstream_t* stream, struct v2gSupportedEnergyTransferModeType* v2gSupportedEnergyTransferModeType, uint32_t eventCode) {
	int grammarID = 70;
	int done = 0;
	int errn;
	uint32_t uint32;

	v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen = 0u;

	while(!done) {
		switch(grammarID) {
		case 70:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EnergyTransferMode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen < v2gSupportedEnergyTransferModeType_EnergyTransferMode_ARRAY_SIZE) {
						/* FirstStartTag[CHARACTERS[ENUMERATION]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeNBitUnsignedInteger(stream, 3, &uint32);
								v2gSupportedEnergyTransferModeType->EnergyTransferMode.array[v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen] = (v2gEnergyTransferModeType) uint32;
								v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EnergyTransferMode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 71;
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
		case 71:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EnergyTransferMode), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen < v2gSupportedEnergyTransferModeType_EnergyTransferMode_ARRAY_SIZE) {
						/* FirstStartTag[CHARACTERS[ENUMERATION]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeNBitUnsignedInteger(stream, 3, &uint32);
								v2gSupportedEnergyTransferModeType->EnergyTransferMode.array[v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen] = (v2gEnergyTransferModeType) uint32;
								v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EnergyTransferMode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 72;
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
		case 72:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EnergyTransferMode), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen < v2gSupportedEnergyTransferModeType_EnergyTransferMode_ARRAY_SIZE) {
						/* FirstStartTag[CHARACTERS[ENUMERATION]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeNBitUnsignedInteger(stream, 3, &uint32);
								v2gSupportedEnergyTransferModeType->EnergyTransferMode.array[v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen] = (v2gEnergyTransferModeType) uint32;
								v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EnergyTransferMode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 73;
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
		case 73:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EnergyTransferMode), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen < v2gSupportedEnergyTransferModeType_EnergyTransferMode_ARRAY_SIZE) {
						/* FirstStartTag[CHARACTERS[ENUMERATION]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeNBitUnsignedInteger(stream, 3, &uint32);
								v2gSupportedEnergyTransferModeType->EnergyTransferMode.array[v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen] = (v2gEnergyTransferModeType) uint32;
								v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EnergyTransferMode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 74;
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
		case 74:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EnergyTransferMode), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen < v2gSupportedEnergyTransferModeType_EnergyTransferMode_ARRAY_SIZE) {
						/* FirstStartTag[CHARACTERS[ENUMERATION]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeNBitUnsignedInteger(stream, 3, &uint32);
								v2gSupportedEnergyTransferModeType->EnergyTransferMode.array[v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen] = (v2gEnergyTransferModeType) uint32;
								v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EnergyTransferMode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 75;
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
		case 75:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EnergyTransferMode), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen < v2gSupportedEnergyTransferModeType_EnergyTransferMode_ARRAY_SIZE) {
						/* FirstStartTag[CHARACTERS[ENUMERATION]] */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(errn == 0) {
							if(eventCode == 0) {
								errn = decodeNBitUnsignedInteger(stream, 3, &uint32);
								v2gSupportedEnergyTransferModeType->EnergyTransferMode.array[v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen] = (v2gEnergyTransferModeType) uint32;
								v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen++;
							} else {
								/* Second level event (e.g., xsi:type, xsi:nil, ...) */
								errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
							}
						}
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EnergyTransferMode) ? */
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ServiceListType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Service{1-8})',  derivedBy='RESTRICTION'.  */
int decode_v2gServiceListType(bitstream_t* stream, struct v2gServiceListType* v2gServiceListType, uint32_t eventCode) {
	int grammarID = 276;
	int done = 0;
	int errn;

	v2gServiceListType->Service.arrayLen = 0u;

	while(!done) {
		switch(grammarID) {
		case 276:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Service)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gServiceListType->Service.arrayLen < v2gServiceListType_Service_ARRAY_SIZE) {
						errn = decode_v2gServiceType(stream, &v2gServiceListType->Service.array[v2gServiceListType->Service.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 277;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 277:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Service), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gServiceListType->Service.arrayLen < v2gServiceListType_Service_ARRAY_SIZE) {
						errn = decode_v2gServiceType(stream, &v2gServiceListType->Service.array[v2gServiceListType->Service.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 278;
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
		case 278:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Service), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gServiceListType->Service.arrayLen < v2gServiceListType_Service_ARRAY_SIZE) {
						errn = decode_v2gServiceType(stream, &v2gServiceListType->Service.array[v2gServiceListType->Service.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 279;
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
		case 279:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Service), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gServiceListType->Service.arrayLen < v2gServiceListType_Service_ARRAY_SIZE) {
						errn = decode_v2gServiceType(stream, &v2gServiceListType->Service.array[v2gServiceListType->Service.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 280;
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
		case 280:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Service), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gServiceListType->Service.arrayLen < v2gServiceListType_Service_ARRAY_SIZE) {
						errn = decode_v2gServiceType(stream, &v2gServiceListType->Service.array[v2gServiceListType->Service.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 281;
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
		case 281:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Service), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gServiceListType->Service.arrayLen < v2gServiceListType_Service_ARRAY_SIZE) {
						errn = decode_v2gServiceType(stream, &v2gServiceListType->Service.array[v2gServiceListType->Service.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 282;
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
		case 282:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Service), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gServiceListType->Service.arrayLen < v2gServiceListType_Service_ARRAY_SIZE) {
						errn = decode_v2gServiceType(stream, &v2gServiceListType->Service.array[v2gServiceListType->Service.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 283;
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
		case 283:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Service), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gServiceListType->Service.arrayLen < v2gServiceListType_Service_ARRAY_SIZE) {
						errn = decode_v2gServiceType(stream, &v2gServiceListType->Service.array[v2gServiceListType->Service.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 5;
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ServiceType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":ServiceID,"urn:iso:15118:2:2013:MsgDataTypes":ServiceName{0-1},"urn:iso:15118:2:2013:MsgDataTypes":ServiceCategory,"urn:iso:15118:2:2013:MsgDataTypes":ServiceScope{0-1},"urn:iso:15118:2:2013:MsgDataTypes":FreeService)',  derivedBy='RESTRICTION'.  */
int decode_v2gServiceType(bitstream_t* stream, struct v2gServiceType* v2gServiceType, uint32_t eventCode) {
	int grammarID = 233;
	int done = 0;
	int errn;
	uint32_t uint32;

	v2gServiceType->ServiceName_isUsed = 0u;
	v2gServiceType->ServiceScope_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 233:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gServiceType->ServiceID);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 234;
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
		case 234:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceName), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceCategory)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gServiceType->ServiceName.charactersLen);
							if (errn == 0) {
								errn =  (v2gServiceType->ServiceName.charactersLen - 2) <= v2gServiceType_ServiceName_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
							}
							if (errn == 0) {
								if (v2gServiceType->ServiceName.charactersLen >= 2) {
									v2gServiceType->ServiceName.charactersLen = (uint16_t)(v2gServiceType->ServiceName.charactersLen - 2); /* string table miss */
									errn = decodeCharacters(stream, v2gServiceType->ServiceName.charactersLen, v2gServiceType->ServiceName.characters);
								} else {
									/* string table hit */
									errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
								}
							}
							v2gServiceType->ServiceName_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceName) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 235;
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
							v2gServiceType->ServiceCategory = (v2gserviceCategoryType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceCategory) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 236;
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
		case 235:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceCategory)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 2, &uint32);
							v2gServiceType->ServiceCategory = (v2gserviceCategoryType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceCategory) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 236;
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
		case 236:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceScope), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FreeService)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gServiceType->ServiceScope.charactersLen);
							if (errn == 0) {
								errn =  (v2gServiceType->ServiceScope.charactersLen - 2) <= v2gServiceType_ServiceScope_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
							}
							if (errn == 0) {
								if (v2gServiceType->ServiceScope.charactersLen >= 2) {
									v2gServiceType->ServiceScope.charactersLen = (uint16_t)(v2gServiceType->ServiceScope.charactersLen - 2); /* string table miss */
									errn = decodeCharacters(stream, v2gServiceType->ServiceScope.charactersLen, v2gServiceType->ServiceScope.characters);
								} else {
									/* string table hit */
									errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
								}
							}
							v2gServiceType->ServiceScope_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceScope) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 237;
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
							errn = decodeBoolean(stream, &v2gServiceType->FreeService);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FreeService) ? */
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
		case 237:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FreeService)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gServiceType->FreeService);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FreeService) ? */
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,SignatureType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":SignedInfo,"http://www.w3.org/2000/09/xmldsig#":SignatureValue,"http://www.w3.org/2000/09/xmldsig#":KeyInfo{0-1},"http://www.w3.org/2000/09/xmldsig#":Object{0-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int decode_v2gSignatureType(bitstream_t* stream, struct v2gSignatureType* v2gSignatureType, uint32_t eventCode) {
	int grammarID = 295;
	int done = 0;
	int errn;

	v2gSignatureType->Id_isUsed =0u;
	v2gSignatureType->KeyInfo_isUsed = 0u;
	v2gSignatureType->Object.arrayLen = 0u;

	while(!done) {
		switch(grammarID) {
		case 295:
			/* FirstStartTag[ATTRIBUTE[STRING](Id), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignedInfo)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gSignatureType->Id.charactersLen);
					if (errn == 0) {
						errn =  (v2gSignatureType->Id.charactersLen - 2) <= v2gSignatureType_Id_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gSignatureType->Id.charactersLen >= 2) {
							v2gSignatureType->Id.charactersLen = (uint16_t)(v2gSignatureType->Id.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gSignatureType->Id.charactersLen, v2gSignatureType->Id.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gSignatureType->Id_isUsed = 1u;
					grammarID = 296;
					break;
				case 1:
					errn = decode_v2gSignedInfoType(stream, &v2gSignatureType->SignedInfo, eventCode);
					grammarID = 297;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 296:
			/* StartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignedInfo)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gSignedInfoType(stream, &v2gSignatureType->SignedInfo, eventCode);
					grammarID = 297;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 297:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignatureValue)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gSignatureValueType(stream, &v2gSignatureType->SignatureValue, eventCode);
					grammarID = 298;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 298:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyInfo), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Object), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gKeyInfoType(stream, &v2gSignatureType->KeyInfo, eventCode);
					v2gSignatureType->KeyInfo_isUsed = 1u;
					grammarID = 299;
					break;
				case 1:
					if (v2gSignatureType->Object.arrayLen < v2gSignatureType_Object_ARRAY_SIZE) {
						errn = decode_v2gObjectType(stream, &v2gSignatureType->Object.array[v2gSignatureType->Object.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 299;
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
		case 299:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Object), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSignatureType->Object.arrayLen < v2gSignatureType_Object_ARRAY_SIZE) {
						errn = decode_v2gObjectType(stream, &v2gSignatureType->Object.array[v2gSignatureType->Object.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 299;
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,SignedInfoType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":CanonicalizationMethod,"http://www.w3.org/2000/09/xmldsig#":SignatureMethod,"http://www.w3.org/2000/09/xmldsig#":Reference{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int decode_v2gSignedInfoType(bitstream_t* stream, struct v2gSignedInfoType* v2gSignedInfoType, uint32_t eventCode) {
	int grammarID = 316;
	int done = 0;
	int errn;

	v2gSignedInfoType->Id_isUsed = 0u;
	v2gSignedInfoType->Reference.arrayLen = 0u;

	while(!done) {
		switch(grammarID) {
		case 316:
			/* FirstStartTag[ATTRIBUTE[STRING](Id), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}CanonicalizationMethod)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gSignedInfoType->Id.charactersLen);
					if (errn == 0) {
						errn =  (v2gSignedInfoType->Id.charactersLen - 2) <= v2gSignedInfoType_Id_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gSignedInfoType->Id.charactersLen >= 2) {
							v2gSignedInfoType->Id.charactersLen = (uint16_t)(v2gSignedInfoType->Id.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gSignedInfoType->Id.charactersLen, v2gSignedInfoType->Id.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gSignedInfoType->Id_isUsed = 1u;
					grammarID = 317;
					break;
				case 1:
					errn = decode_v2gCanonicalizationMethodType(stream, &v2gSignedInfoType->CanonicalizationMethod, eventCode);
					grammarID = 318;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 317:
			/* StartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}CanonicalizationMethod)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gCanonicalizationMethodType(stream, &v2gSignedInfoType->CanonicalizationMethod, eventCode);
					grammarID = 318;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 318:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignatureMethod)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gSignatureMethodType(stream, &v2gSignedInfoType->SignatureMethod, eventCode);
					grammarID = 319;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 319:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Reference)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSignedInfoType->Reference.arrayLen < v2gSignedInfoType_Reference_ARRAY_SIZE) {
						errn = decode_v2gReferenceType(stream, &v2gSignedInfoType->Reference.array[v2gSignedInfoType->Reference.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 50;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 50:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Reference), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSignedInfoType->Reference.arrayLen < v2gSignedInfoType_Reference_ARRAY_SIZE) {
						errn = decode_v2gReferenceType(stream, &v2gSignedInfoType->Reference.array[v2gSignedInfoType->Reference.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 50;
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,SignatureMethodType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":HMACOutputLength{0-1},(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]){0-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int decode_v2gSignatureMethodType(bitstream_t* stream, struct v2gSignatureMethodType* v2gSignatureMethodType, uint32_t eventCode) {
	int grammarID = 207;
	int done = 0;
	int errn;

	v2gSignatureMethodType->HMACOutputLength_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 207:
			/* FirstStartTag[ATTRIBUTE[STRING](Algorithm)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gSignatureMethodType->Algorithm.charactersLen);
					if (errn == 0) {
						errn =  (v2gSignatureMethodType->Algorithm.charactersLen - 2) <= v2gSignatureMethodType_Algorithm_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gSignatureMethodType->Algorithm.charactersLen >= 2) {
							v2gSignatureMethodType->Algorithm.charactersLen = (uint16_t)(v2gSignatureMethodType->Algorithm.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gSignatureMethodType->Algorithm.charactersLen, v2gSignatureMethodType->Algorithm.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					grammarID = 208;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 208:
			/* StartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}HMACOutputLength), START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeInteger64(stream, &v2gSignatureMethodType->HMACOutputLength);
							v2gSignatureMethodType->HMACOutputLength_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}HMACOutputLength) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 35;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 35;
					break;
				case 2:
					done = 1;
					grammarID = 1;
					break;
				case 3:
					grammarID = 209;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 35:
			/* Element[START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 35;
					break;
				case 1:
					done = 1;
					grammarID = 1;
					break;
				case 2:
					grammarID = 35;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 209:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}HMACOutputLength), START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeInteger64(stream, &v2gSignatureMethodType->HMACOutputLength);
							v2gSignatureMethodType->HMACOutputLength_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}HMACOutputLength) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 35;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 35;
					break;
				case 2:
					done = 1;
					grammarID = 1;
					break;
				case 3:
					grammarID = 209;
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,SignatureValueType',  base type name='base64Binary',  content type='SIMPLE',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  derivedBy='EXTENSION'.  */
int decode_v2gSignatureValueType(bitstream_t* stream, struct v2gSignatureValueType* v2gSignatureValueType, uint32_t eventCode) {
	int grammarID = 249;
	int done = 0;
	int errn;

	v2gSignatureValueType->Id_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 249:
			/* FirstStartTag[ATTRIBUTE[STRING](Id), CHARACTERS[BINARY_BASE64]] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gSignatureValueType->Id.charactersLen);
					if (errn == 0) {
						errn =  (v2gSignatureValueType->Id.charactersLen - 2) <= v2gSignatureValueType_Id_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gSignatureValueType->Id.charactersLen >= 2) {
							v2gSignatureValueType->Id.charactersLen = (uint16_t)(v2gSignatureValueType->Id.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gSignatureValueType->Id.charactersLen, v2gSignatureValueType->Id.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gSignatureValueType->Id_isUsed = 1u;
					grammarID = 58;
					break;
				case 1:
					errn = decodeUnsignedInteger16(stream, &v2gSignatureValueType->CONTENT.bytesLen);
					if (errn == 0) {
						errn =  (v2gSignatureValueType->CONTENT.bytesLen) <= v2gSignatureValueType_CONTENT_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
					}
					if (errn == 0) {
						errn = decodeBytes(stream, v2gSignatureValueType->CONTENT.bytesLen, v2gSignatureValueType->CONTENT.bytes);
					}
					grammarID = 5;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 58:
			/* StartTag[CHARACTERS[BINARY_BASE64]] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gSignatureValueType->CONTENT.bytesLen);
					if (errn == 0) {
						errn =  (v2gSignatureValueType->CONTENT.bytesLen) <= v2gSignatureValueType_CONTENT_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
					}
					if (errn == 0) {
						errn = decodeBytes(stream, v2gSignatureValueType->CONTENT.bytesLen, v2gSignatureValueType->CONTENT.bytes);
					}
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,SignaturePropertiesType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":SignatureProperty{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int decode_v2gSignaturePropertiesType(bitstream_t* stream, struct v2gSignaturePropertiesType* v2gSignaturePropertiesType, uint32_t eventCode) {
	int grammarID = 250;
	int done = 0;
	int errn;

	v2gSignaturePropertiesType->Id_isUsed = 0u;
	v2gSignaturePropertiesType->SignatureProperty.arrayLen = 0u;

	while(!done) {
		switch(grammarID) {
		case 250:
			/* FirstStartTag[ATTRIBUTE[STRING](Id), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignatureProperty)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gSignaturePropertiesType->Id.charactersLen);
					if (errn == 0) {
						errn =  (v2gSignaturePropertiesType->Id.charactersLen - 2) <= v2gSignaturePropertiesType_Id_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gSignaturePropertiesType->Id.charactersLen >= 2) {
							v2gSignaturePropertiesType->Id.charactersLen = (uint16_t)(v2gSignaturePropertiesType->Id.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gSignaturePropertiesType->Id.charactersLen, v2gSignaturePropertiesType->Id.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gSignaturePropertiesType->Id_isUsed = 1u;
					grammarID = 251;
					break;
				case 1:
					if (v2gSignaturePropertiesType->SignatureProperty.arrayLen < v2gSignaturePropertiesType_SignatureProperty_ARRAY_SIZE) {
						errn = decode_v2gSignaturePropertyType(stream, &v2gSignaturePropertiesType->SignatureProperty.array[v2gSignaturePropertiesType->SignatureProperty.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 252;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 251:
			/* StartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignatureProperty)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSignaturePropertiesType->SignatureProperty.arrayLen < v2gSignaturePropertiesType_SignatureProperty_ARRAY_SIZE) {
						errn = decode_v2gSignaturePropertyType(stream, &v2gSignaturePropertiesType->SignatureProperty.array[v2gSignaturePropertiesType->SignatureProperty.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 252;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 252:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignatureProperty), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSignaturePropertiesType->SignatureProperty.arrayLen < v2gSignaturePropertiesType_SignatureProperty_ARRAY_SIZE) {
						errn = decode_v2gSignaturePropertyType(stream, &v2gSignaturePropertiesType->SignatureProperty.array[v2gSignaturePropertiesType->SignatureProperty.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 252;
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,SignaturePropertyType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='((WC[##other:"http://www.w3.org/2000/09/xmldsig#"])){1-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
int decode_v2gSignaturePropertyType(bitstream_t* stream, struct v2gSignaturePropertyType* v2gSignaturePropertyType, uint32_t eventCode) {
	int grammarID = 32;
	int done = 0;
	int errn;

	v2gSignaturePropertyType->Id_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 32:
			/* FirstStartTag[ATTRIBUTE[STRING](Id), ATTRIBUTE[STRING](Target)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gSignaturePropertyType->Id.charactersLen);
					if (errn == 0) {
						errn =  (v2gSignaturePropertyType->Id.charactersLen - 2) <= v2gSignaturePropertyType_Id_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gSignaturePropertyType->Id.charactersLen >= 2) {
							v2gSignaturePropertyType->Id.charactersLen = (uint16_t)(v2gSignaturePropertyType->Id.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gSignaturePropertyType->Id.charactersLen, v2gSignaturePropertyType->Id.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					v2gSignaturePropertyType->Id_isUsed = 1u;
					grammarID = 33;
					break;
				case 1:
					errn = decodeUnsignedInteger16(stream, &v2gSignaturePropertyType->Target.charactersLen);
					if (errn == 0) {
						errn =  (v2gSignaturePropertyType->Target.charactersLen - 2) <= v2gSignaturePropertyType_Target_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gSignaturePropertyType->Target.charactersLen >= 2) {
							v2gSignaturePropertyType->Target.charactersLen = (uint16_t)(v2gSignaturePropertyType->Target.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gSignaturePropertyType->Target.charactersLen, v2gSignaturePropertyType->Target.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					grammarID = 34;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 33:
			/* StartTag[ATTRIBUTE[STRING](Target)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decodeUnsignedInteger16(stream, &v2gSignaturePropertyType->Target.charactersLen);
					if (errn == 0) {
						errn =  (v2gSignaturePropertyType->Target.charactersLen - 2) <= v2gSignaturePropertyType_Target_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
					}
					if (errn == 0) {
						if (v2gSignaturePropertyType->Target.charactersLen >= 2) {
							v2gSignaturePropertyType->Target.charactersLen = (uint16_t)(v2gSignaturePropertyType->Target.charactersLen - 2); /* string table miss */
							errn = decodeCharacters(stream, v2gSignaturePropertyType->Target.charactersLen, v2gSignaturePropertyType->Target.characters);
						} else {
							/* string table hit */
							errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
						}
					}
					grammarID = 34;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 34:
			/* StartTag[START_ELEMENT_GENERIC, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 35;
					break;
				case 1:
					errn = decodeDeviationsCH(stream);
					grammarID = 36;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 35:
			/* Element[START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 35;
					break;
				case 1:
					done = 1;
					grammarID = 1;
					break;
				case 2:
					grammarID = 35;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 36:
			/* Element[START_ELEMENT_GENERIC, CHARACTERS_GENERIC[STRING]] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
					/* TODO unsupported event : START_ELEMENT_GENERIC */
					grammarID = 35;
					break;
				case 1:
					grammarID = 36;
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

/* Deviant data decoding (skip functions) */
int decodeDeviationsCH(bitstream_t* stream) {
	int i=0;
	uint16_t uint16;
	uint32_t uint32;
	int errn = 0;

	errn = decodeUnsignedInteger16(stream, &uint16);
	if (errn == 0) {
		for(i=0; i<uint16 && errn == 0; i++) {
			errn = decodeUnsignedInteger32(stream, &uint32);
		}
	}
	return errn;
}

/* Complex type name='urn:iso:15118:2:2013:MsgDef,#AnonType_V2G_Message',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDef":Header,"urn:iso:15118:2:2013:MsgDef":Body)',  derivedBy='RESTRICTION'.  */
int decode_v2gAnonType_V2G_Message(bitstream_t* stream, struct v2gAnonType_V2G_Message* v2gAnonType_V2G_Message, uint32_t eventCode) {
	int grammarID = 200;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 200:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDef}Header)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gMessageHeaderType(stream, &v2gAnonType_V2G_Message->Header, eventCode);
					grammarID = 201;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 201:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDef}Body)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gBodyType(stream, &v2gAnonType_V2G_Message->Body, eventCode);
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

/* Complex type name='urn:iso:15118:2:2013:MsgHeader,MessageHeaderType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgHeader":SessionID,"urn:iso:15118:2:2013:MsgHeader":Notification{0-1},"http://www.w3.org/2000/09/xmldsig#":Signature{0-1})',  derivedBy='RESTRICTION'.  */
int decode_v2gMessageHeaderType(bitstream_t* stream, struct v2gMessageHeaderType* v2gMessageHeaderType, uint32_t eventCode) {
	int grammarID = 118;
	int done = 0;
	int errn;

	v2gMessageHeaderType->Notification_isUsed = 0u;
	v2gMessageHeaderType->Signature_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 118:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgHeader}SessionID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BINARY_HEX]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gMessageHeaderType->SessionID.bytesLen);
							if (errn == 0) {
								errn =  (v2gMessageHeaderType->SessionID.bytesLen) <= v2gMessageHeaderType_SessionID_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gMessageHeaderType->SessionID.bytesLen, v2gMessageHeaderType->SessionID.bytes);
							}
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgHeader}SessionID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 119;
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
		case 119:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgHeader}Notification), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Signature), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gNotificationType(stream, &v2gMessageHeaderType->Notification, eventCode);
					v2gMessageHeaderType->Notification_isUsed = 1u;
					grammarID = 120;
					break;
				case 1:
					errn = decode_v2gSignatureType(stream, &v2gMessageHeaderType->Signature, eventCode);
					v2gMessageHeaderType->Signature_isUsed = 1u;
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
		case 120:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Signature), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gSignatureType(stream, &v2gMessageHeaderType->Signature, eventCode);
					v2gMessageHeaderType->Signature_isUsed = 1u;
					grammarID = 5;
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,NotificationType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":FaultCode,"urn:iso:15118:2:2013:MsgDataTypes":FaultMsg{0-1})',  derivedBy='RESTRICTION'.  */
int decode_v2gNotificationType(bitstream_t* stream, struct v2gNotificationType* v2gNotificationType, uint32_t eventCode) {
	int grammarID = 42;
	int done = 0;
	int errn;
	uint32_t uint32;

	v2gNotificationType->FaultMsg_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 42:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FaultCode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 2, &uint32);
							v2gNotificationType->FaultCode = (v2gfaultCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FaultCode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 43;
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
		case 43:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FaultMsg), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gNotificationType->FaultMsg.charactersLen);
							if (errn == 0) {
								errn =  (v2gNotificationType->FaultMsg.charactersLen - 2) <= v2gNotificationType_FaultMsg_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
							}
							if (errn == 0) {
								if (v2gNotificationType->FaultMsg.charactersLen >= 2) {
									v2gNotificationType->FaultMsg.charactersLen = (uint16_t)(v2gNotificationType->FaultMsg.charactersLen - 2); /* string table miss */
									errn = decodeCharacters(stream, v2gNotificationType->FaultMsg.charactersLen, v2gNotificationType->FaultMsg.characters);
								} else {
									/* string table hit */
									errn = EXI_ERROR_STRINGVALUES_NOT_SUPPORTED;
								}
							}
							v2gNotificationType->FaultMsg_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FaultMsg) ? */
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,BodyType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":BodyElement{0-1})',  derivedBy='RESTRICTION'.  */
int decode_v2gBodyType(bitstream_t* stream, struct v2gBodyType* v2gBodyType, uint32_t eventCode) {
	int grammarID = 104;
	int done = 0;
	int errn;

	init_v2gBodyType(v2gBodyType);

	while(!done) {
		switch(grammarID) {
		case 104:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}AuthorizationReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}AuthorizationRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}BodyElement), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CableCheckReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CableCheckRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CertificateInstallationReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CertificateInstallationRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CertificateUpdateReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CertificateUpdateRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargeParameterDiscoveryReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargeParameterDiscoveryRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingStatusReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingStatusRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CurrentDemandReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CurrentDemandRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}MeteringReceiptReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}MeteringReceiptRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PaymentDetailsReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PaymentDetailsRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PaymentServiceSelectionReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PaymentServiceSelectionRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PowerDeliveryReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PowerDeliveryRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PreChargeReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PreChargeRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceDetailReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceDetailRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceDiscoveryReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceDiscoveryRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionSetupReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionSetupRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionStopReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionStopRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}WeldingDetectionReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}WeldingDetectionRes), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 6, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 1:
					errn = decode_v2gAuthorizationResType(stream, &v2gBodyType->AuthorizationRes, eventCode);
					v2gBodyType->AuthorizationRes_isUsed = 1u;
					grammarID = 5;
					break;
				case 2:
					errn = decode_v2gBodyBaseType(stream, &v2gBodyType->BodyElement, eventCode);
					v2gBodyType->BodyElement_isUsed = 1u;
					grammarID = 5;
					break;
				case 4:
					errn = decode_v2gCableCheckResType(stream, &v2gBodyType->CableCheckRes, eventCode);
					v2gBodyType->CableCheckRes_isUsed = 1u;
					grammarID = 5;
					break;
				case 6:
					errn = decode_v2gCertificateInstallationResType(stream, &v2gBodyType->CertificateInstallationRes, eventCode);
					v2gBodyType->CertificateInstallationRes_isUsed = 1u;
					grammarID = 5;
					break;
				case 8:
					errn = decode_v2gCertificateUpdateResType(stream, &v2gBodyType->CertificateUpdateRes, eventCode);
					v2gBodyType->CertificateUpdateRes_isUsed = 1u;
					grammarID = 5;
					break;
				case 10:
					errn = decode_v2gChargeParameterDiscoveryResType(stream, &v2gBodyType->ChargeParameterDiscoveryRes, eventCode);
					v2gBodyType->ChargeParameterDiscoveryRes_isUsed = 1u;
					grammarID = 5;
					break;
				case 12:
					errn = decode_v2gChargingStatusResType(stream, &v2gBodyType->ChargingStatusRes, eventCode);
					v2gBodyType->ChargingStatusRes_isUsed = 1u;
					grammarID = 5;
					break;
				case 14:
					errn = decode_v2gCurrentDemandResType(stream, &v2gBodyType->CurrentDemandRes, eventCode);
					v2gBodyType->CurrentDemandRes_isUsed = 1u;
					grammarID = 5;
					break;
				case 16:
					errn = decode_v2gMeteringReceiptResType(stream, &v2gBodyType->MeteringReceiptRes, eventCode);
					v2gBodyType->MeteringReceiptRes_isUsed = 1u;
					grammarID = 5;
					break;
				case 18:
					errn = decode_v2gPaymentDetailsResType(stream, &v2gBodyType->PaymentDetailsRes, eventCode);
					v2gBodyType->PaymentDetailsRes_isUsed = 1u;
					grammarID = 5;
					break;
				case 20:
					errn = decode_v2gPaymentServiceSelectionResType(stream, &v2gBodyType->PaymentServiceSelectionRes, eventCode);
					v2gBodyType->PaymentServiceSelectionRes_isUsed = 1u;
					grammarID = 5;
					break;
				case 22:
					errn = decode_v2gPowerDeliveryResType(stream, &v2gBodyType->PowerDeliveryRes, eventCode);
					v2gBodyType->PowerDeliveryRes_isUsed = 1u;
					grammarID = 5;
					break;
				case 24:
					errn = decode_v2gPreChargeResType(stream, &v2gBodyType->PreChargeRes, eventCode);
					v2gBodyType->PreChargeRes_isUsed = 1u;
					grammarID = 5;
					break;
				case 26:
					errn = decode_v2gServiceDetailResType(stream, &v2gBodyType->ServiceDetailRes, eventCode);
					v2gBodyType->ServiceDetailRes_isUsed = 1u;
					grammarID = 5;
					break;
				case 28:
					errn = decode_v2gServiceDiscoveryResType(stream, &v2gBodyType->ServiceDiscoveryRes, eventCode);
					v2gBodyType->ServiceDiscoveryRes_isUsed = 1u;
					grammarID = 5;
					break;
				case 30:
					errn = decode_v2gSessionSetupResType(stream, &v2gBodyType->SessionSetupRes, eventCode);
					v2gBodyType->SessionSetupRes_isUsed = 1u;
					grammarID = 5;
					break;
				case 32:
					errn = decode_v2gSessionStopResType(stream, &v2gBodyType->SessionStopRes, eventCode);
					v2gBodyType->SessionStopRes_isUsed = 1u;
					grammarID = 5;
					break;
				case 34:
					errn = decode_v2gWeldingDetectionResType(stream, &v2gBodyType->WeldingDetectionRes, eventCode);
					v2gBodyType->WeldingDetectionRes_isUsed = 1u;
					grammarID = 5;
					break;
				case 35:
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
