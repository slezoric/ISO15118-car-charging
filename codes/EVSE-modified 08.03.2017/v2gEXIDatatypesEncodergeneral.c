/*
 * v2gEXIDatatypesEncodergeneral.c
 *
 *  Created on: 12.02.2016
 *      Author: melanie
 */


# include "v2gEXIDatatypesEncoder.h"

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PhysicalValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Multiplier,"urn:iso:15118:2:2013:MsgDataTypes":Unit,"urn:iso:15118:2:2013:MsgDataTypes":Value)',  derivedBy='RESTRICTION'.  */
int encode_v2gPhysicalValueType(bitstream_t* stream, struct v2gPhysicalValueType* v2gPhysicalValueType) {
	int grammarID = 129;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 129:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Multiplier)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 3, (uint32_t)(v2gPhysicalValueType->Multiplier + 3));
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 130;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 130:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Unit)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 3, v2gPhysicalValueType->Unit);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 131;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 131:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Value)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeInteger16(stream, v2gPhysicalValueType->Value);
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,BodyBaseType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
 int encode_v2gBodyBaseType(bitstream_t* stream, struct v2gBodyBaseType* v2gBodyBaseType) {
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

 /* Complex type name='http://www.w3.org/2000/09/xmldsig#,CanonicalizationMethodType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='((WC[##any]){0-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
 int encode_v2gCanonicalizationMethodType(bitstream_t* stream, struct v2gCanonicalizationMethodType* v2gCanonicalizationMethodType) {
 	int grammarID = 267;
 	int done = 0;
 	int errn;

 	while(!done) {
 		switch(grammarID) {
 		case 267:
 			/* FirstStartTag[ATTRIBUTE[STRING](Algorithm)] */
 			if (1==1) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					/* encode string as string table miss (+2 len)*/
 					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gCanonicalizationMethodType->Algorithm.charactersLen + 2));
 					if (errn == 0) {
 						errn = encodeCharacters(stream, v2gCanonicalizationMethodType->Algorithm.characters, v2gCanonicalizationMethodType->Algorithm.charactersLen);
 					}
 				}
 				grammarID = 47;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 47:
 			/* StartTag[START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
 			if (1==0) {
 				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
 				grammarID = 35;
 			} else 			if (1==1) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 1);
 				if(errn == 0) {
 					done = 1;
 				}
 				grammarID = 1;
 			} else 			if (1==0) {
 				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
 				grammarID = 35;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 35:
 			/* Element[START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
 			if (1==0) {
 				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
 				grammarID = 35;
 			} else 			if (1==1) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 1);
 				if(errn == 0) {
 					done = 1;
 				}
 				grammarID = 1;
 			} else 			if (1==0) {
 				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
 				grammarID = 35;
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

 /* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ListOfRootCertificateIDsType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":RootCertificateID{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
 int encode_v2gListOfRootCertificateIDsType(bitstream_t* stream, struct v2gListOfRootCertificateIDsType* v2gListOfRootCertificateIDsType) {
 	int grammarID = 134;
 	int done = 0;
 	int errn;

 	unsigned int v2gListOfRootCertificateIDsType_RootCertificateID_currArrayIndex = 0;

 	while(!done) {
 		switch(grammarID) {
 		case 134:
 			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}RootCertificateID)] */
 			if (v2gListOfRootCertificateIDsType_RootCertificateID_currArrayIndex < v2gListOfRootCertificateIDsType->RootCertificateID.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					errn = encode_v2gX509IssuerSerialType(stream, &v2gListOfRootCertificateIDsType->RootCertificateID.array [v2gListOfRootCertificateIDsType_RootCertificateID_currArrayIndex++]);
 				}
 				grammarID = 135;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 135:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}RootCertificateID), END_ELEMENT] */
 			if (v2gListOfRootCertificateIDsType_RootCertificateID_currArrayIndex < v2gListOfRootCertificateIDsType->RootCertificateID.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					errn = encode_v2gX509IssuerSerialType(stream, &v2gListOfRootCertificateIDsType->RootCertificateID.array [v2gListOfRootCertificateIDsType_RootCertificateID_currArrayIndex++]);
 				}
 				grammarID = 135;
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
 int encode_v2gX509IssuerSerialType(bitstream_t* stream, struct v2gX509IssuerSerialType* v2gX509IssuerSerialType) {
 	int grammarID = 132;
 	int done = 0;
 	int errn;

 	while(!done) {
 		switch(grammarID) {
 		case 132:
 			/* FirstStartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509IssuerName)] */
 			if ( 1 == 1 ) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
 					errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					if(errn == 0) {
 						/* encode string as string table miss (+2 len)*/
 						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gX509IssuerSerialType->X509IssuerName.charactersLen + 2));
 						if (errn == 0) {
 							errn = encodeCharacters(stream, v2gX509IssuerSerialType->X509IssuerName.characters, v2gX509IssuerSerialType->X509IssuerName.charactersLen);
 						}
 						/* valid EE */
 						errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					}
 				}
 				grammarID = 133;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 133:
 			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509SerialNumber)] */
 			if ( 1 == 1 ) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
 					errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					if(errn == 0) {
 						errn = encodeInteger64(stream, v2gX509IssuerSerialType->X509SerialNumber);
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

 /* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,CertificateChainType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Certificate,"urn:iso:15118:2:2013:MsgDataTypes":SubCertificates{0-1})',  derivedBy='RESTRICTION'.  */
 int encode_v2gCertificateChainType(bitstream_t* stream, struct v2gCertificateChainType* v2gCertificateChainType) {
 	int grammarID = 212;
 	int done = 0;
 	int errn;

 	while(!done) {
 		switch(grammarID) {
 		case 212:
 			/* FirstStartTag[ATTRIBUTE[STRING]({urn:iso:15118:2:2013:MsgDataTypes}Id), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Certificate)] */
 			if ( v2gCertificateChainType->Id_isUsed == 1u ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					/* encode string as string table miss (+2 len)*/
 					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gCertificateChainType->Id.charactersLen + 2));
 					if (errn == 0) {
 						errn = encodeCharacters(stream, v2gCertificateChainType->Id.characters, v2gCertificateChainType->Id.charactersLen);
 					}
 				}
 				grammarID = 213;
 			} else 			if ( 1 == 1 ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 1);
 				if(errn == 0) {
 					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
 					errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					if(errn == 0) {
 						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gCertificateChainType->Certificate.bytesLen));
 						if (errn == 0) {
 							errn = encodeBytes(stream, v2gCertificateChainType->Certificate.bytes, v2gCertificateChainType->Certificate.bytesLen);
 						}
 						/* valid EE */
 						errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					}
 				}
 				grammarID = 214;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 213:
 			/* StartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Certificate)] */
 			if ( 1 == 1 ) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
 					errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					if(errn == 0) {
 						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gCertificateChainType->Certificate.bytesLen));
 						if (errn == 0) {
 							errn = encodeBytes(stream, v2gCertificateChainType->Certificate.bytes, v2gCertificateChainType->Certificate.bytesLen);
 						}
 						/* valid EE */
 						errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					}
 				}
 				grammarID = 214;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 214:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SubCertificates), END_ELEMENT] */
 			if ( v2gCertificateChainType->SubCertificates_isUsed == 1u ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					errn = encode_v2gSubCertificatesType(stream, &v2gCertificateChainType->SubCertificates );
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

 /* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SubCertificatesType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Certificate{1-4})',  derivedBy='RESTRICTION'.  */
 int encode_v2gSubCertificatesType(bitstream_t* stream, struct v2gSubCertificatesType* v2gSubCertificatesType) {
 	int grammarID = 59;
 	int done = 0;
 	int errn;

 	unsigned int v2gSubCertificatesType_Certificate_currArrayIndex = 0;

 	while(!done) {
 		switch(grammarID) {
 		case 59:
 			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Certificate)] */
 			if (v2gSubCertificatesType_Certificate_currArrayIndex < v2gSubCertificatesType->Certificate.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
 					errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					if(errn == 0) {
 						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType_Certificate_currArrayIndex].bytesLen));
 						if (errn == 0) {
 							errn = encodeBytes(stream, v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType_Certificate_currArrayIndex].bytes, v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType_Certificate_currArrayIndex].bytesLen);
 							v2gSubCertificatesType_Certificate_currArrayIndex++;
 						}
 						/* valid EE */
 						errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					}
 				}
 				grammarID = 60;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 60:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Certificate), END_ELEMENT] */
 			if (v2gSubCertificatesType_Certificate_currArrayIndex < v2gSubCertificatesType->Certificate.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
 					errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					if(errn == 0) {
 						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType_Certificate_currArrayIndex].bytesLen));
 						if (errn == 0) {
 							errn = encodeBytes(stream, v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType_Certificate_currArrayIndex].bytes, v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType_Certificate_currArrayIndex].bytesLen);
 							v2gSubCertificatesType_Certificate_currArrayIndex++;
 						}
 						/* valid EE */
 						errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					}
 				}
 				grammarID = 61;
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
 		case 61:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Certificate), END_ELEMENT] */
 			if (v2gSubCertificatesType_Certificate_currArrayIndex < v2gSubCertificatesType->Certificate.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
 					errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					if(errn == 0) {
 						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType_Certificate_currArrayIndex].bytesLen));
 						if (errn == 0) {
 							errn = encodeBytes(stream, v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType_Certificate_currArrayIndex].bytes, v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType_Certificate_currArrayIndex].bytesLen);
 							v2gSubCertificatesType_Certificate_currArrayIndex++;
 						}
 						/* valid EE */
 						errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					}
 				}
 				grammarID = 62;
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
 		case 62:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Certificate), END_ELEMENT] */
 			if (v2gSubCertificatesType_Certificate_currArrayIndex < v2gSubCertificatesType->Certificate.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
 					errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					if(errn == 0) {
 						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType_Certificate_currArrayIndex].bytesLen));
 						if (errn == 0) {
 							errn = encodeBytes(stream, v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType_Certificate_currArrayIndex].bytes, v2gSubCertificatesType->Certificate.array[v2gSubCertificatesType_Certificate_currArrayIndex].bytesLen);
 							v2gSubCertificatesType_Certificate_currArrayIndex++;
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

 /* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ContractSignatureEncryptedPrivateKeyType',  base type name='privateKeyType',  content type='SIMPLE',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  derivedBy='EXTENSION'.  */
 int encode_v2gContractSignatureEncryptedPrivateKeyType(bitstream_t* stream, struct v2gContractSignatureEncryptedPrivateKeyType* v2gContractSignatureEncryptedPrivateKeyType) {
 	int grammarID = 57;
 	int done = 0;
 	int errn;

 	while(!done) {
 		switch(grammarID) {
 		case 57:
 			/* FirstStartTag[ATTRIBUTE[STRING]({urn:iso:15118:2:2013:MsgDataTypes}Id)] */
 			if (1==1) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					/* encode string as string table miss (+2 len)*/
 					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gContractSignatureEncryptedPrivateKeyType->Id.charactersLen + 2));
 					if (errn == 0) {
 						errn = encodeCharacters(stream, v2gContractSignatureEncryptedPrivateKeyType->Id.characters, v2gContractSignatureEncryptedPrivateKeyType->Id.charactersLen);
 					}
 				}
 				grammarID = 58;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 58:
 			/* StartTag[CHARACTERS[BINARY_BASE64]] */
 			if (1==1) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gContractSignatureEncryptedPrivateKeyType->CONTENT.bytesLen));
 					if (errn == 0) {
 						errn = encodeBytes(stream, v2gContractSignatureEncryptedPrivateKeyType->CONTENT.bytes, v2gContractSignatureEncryptedPrivateKeyType->CONTENT.bytesLen);
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

 /* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DiffieHellmanPublickeyType',  base type name='dHpublickeyType',  content type='SIMPLE',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  derivedBy='EXTENSION'.  */
 int encode_v2gDiffieHellmanPublickeyType(bitstream_t* stream, struct v2gDiffieHellmanPublickeyType* v2gDiffieHellmanPublickeyType) {
 	int grammarID = 57;
 	int done = 0;
 	int errn;

 	while(!done) {
 		switch(grammarID) {
 		case 57:
 			/* FirstStartTag[ATTRIBUTE[STRING]({urn:iso:15118:2:2013:MsgDataTypes}Id)] */
 			if (1==1) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					/* encode string as string table miss (+2 len)*/
 					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gDiffieHellmanPublickeyType->Id.charactersLen + 2));
 					if (errn == 0) {
 						errn = encodeCharacters(stream, v2gDiffieHellmanPublickeyType->Id.characters, v2gDiffieHellmanPublickeyType->Id.charactersLen);
 					}
 				}
 				grammarID = 58;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 58:
 			/* StartTag[CHARACTERS[BINARY_BASE64]] */
 			if (1==1) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gDiffieHellmanPublickeyType->CONTENT.bytesLen));
 					if (errn == 0) {
 						errn = encodeBytes(stream, v2gDiffieHellmanPublickeyType->CONTENT.bytes, v2gDiffieHellmanPublickeyType->CONTENT.bytesLen);
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

 /* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EMAIDType',  base type name='eMAIDType',  content type='SIMPLE',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  derivedBy='EXTENSION'.  */
 int encode_v2gEMAIDType(bitstream_t* stream, struct v2gEMAIDType* v2gEMAIDType) {
 	int grammarID = 223;
 	int done = 0;
 	int errn;

 	while(!done) {
 		switch(grammarID) {
 		case 223:
 			/* FirstStartTag[ATTRIBUTE[STRING]({urn:iso:15118:2:2013:MsgDataTypes}Id)] */
 			if (1==1) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					/* encode string as string table miss (+2 len)*/
 					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gEMAIDType->Id.charactersLen + 2));
 					if (errn == 0) {
 						errn = encodeCharacters(stream, v2gEMAIDType->Id.characters, v2gEMAIDType->Id.charactersLen);
 					}
 				}
 				grammarID = 224;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 224:
 			/* StartTag[CHARACTERS[STRING]] */
 			if (1==1) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					/* encode string as string table miss (+2 len)*/
 					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gEMAIDType->CONTENT.charactersLen + 2));
 					if (errn == 0) {
 						errn = encodeCharacters(stream, v2gEMAIDType->CONTENT.characters, v2gEMAIDType->CONTENT.charactersLen);
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

 /* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SAScheduleListType',  base type name='SASchedulesType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":SAScheduleTuple{1-3})',  derivedBy='EXTENSION'.  */
 int encode_v2gSAScheduleListType(bitstream_t* stream, struct v2gSAScheduleListType* v2gSAScheduleListType) {
 	int grammarID = 264;
 	int done = 0;
 	int errn;

 	unsigned int v2gSAScheduleListType_SAScheduleTuple_currArrayIndex = 0;

 	while(!done) {
 		switch(grammarID) {
 		case 264:
 			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SAScheduleTuple)] */
 			if (v2gSAScheduleListType_SAScheduleTuple_currArrayIndex < v2gSAScheduleListType->SAScheduleTuple.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					errn = encode_v2gSAScheduleTupleType(stream, &v2gSAScheduleListType->SAScheduleTuple.array [v2gSAScheduleListType_SAScheduleTuple_currArrayIndex++]);
 				}
 				grammarID = 265;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 265:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SAScheduleTuple), END_ELEMENT] */
 			if (v2gSAScheduleListType_SAScheduleTuple_currArrayIndex < v2gSAScheduleListType->SAScheduleTuple.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					errn = encode_v2gSAScheduleTupleType(stream, &v2gSAScheduleListType->SAScheduleTuple.array [v2gSAScheduleListType_SAScheduleTuple_currArrayIndex++]);
 				}
 				grammarID = 266;
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
 		case 266:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SAScheduleTuple), END_ELEMENT] */
 			if (v2gSAScheduleListType_SAScheduleTuple_currArrayIndex < v2gSAScheduleListType->SAScheduleTuple.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					errn = encode_v2gSAScheduleTupleType(stream, &v2gSAScheduleListType->SAScheduleTuple.array [v2gSAScheduleListType_SAScheduleTuple_currArrayIndex++]);
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

 /* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SAScheduleTupleType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":SAScheduleTupleID,"urn:iso:15118:2:2013:MsgDataTypes":PMaxSchedule,"urn:iso:15118:2:2013:MsgDataTypes":SalesTariff{0-1})',  derivedBy='RESTRICTION'.  */
 int encode_v2gSAScheduleTupleType(bitstream_t* stream, struct v2gSAScheduleTupleType* v2gSAScheduleTupleType) {
 	int grammarID = 313;
 	int done = 0;
 	int errn;

 	while(!done) {
 		switch(grammarID) {
 		case 313:
 			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SAScheduleTupleID)] */
 			if ( 1 == 1 ) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
 					errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					if(errn == 0) {
 						errn = encodeNBitUnsignedInteger(stream, 8, (uint32_t)(v2gSAScheduleTupleType->SAScheduleTupleID - 1));
 						/* valid EE */
 						errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					}
 				}
 				grammarID = 314;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 314:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}PMaxSchedule)] */
 			if ( 1 == 1 ) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					errn = encode_v2gPMaxScheduleType(stream, &v2gSAScheduleTupleType->PMaxSchedule );
 				}
 				grammarID = 315;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 315:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SalesTariff), END_ELEMENT] */
 			if ( v2gSAScheduleTupleType->SalesTariff_isUsed == 1u ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					errn = encode_v2gSalesTariffType(stream, &v2gSAScheduleTupleType->SalesTariff );
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

 /* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PMaxScheduleType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":PMaxScheduleEntry{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
 int encode_v2gPMaxScheduleType(bitstream_t* stream, struct v2gPMaxScheduleType* v2gPMaxScheduleType) {
 	int grammarID = 305;
 	int done = 0;
 	int errn;

 	unsigned int v2gPMaxScheduleType_PMaxScheduleEntry_currArrayIndex = 0;

 	while(!done) {
 		switch(grammarID) {
 		case 305:
 			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}PMaxScheduleEntry)] */
 			if (v2gPMaxScheduleType_PMaxScheduleEntry_currArrayIndex < v2gPMaxScheduleType->PMaxScheduleEntry.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					errn = encode_v2gPMaxScheduleEntryType(stream, &v2gPMaxScheduleType->PMaxScheduleEntry.array [v2gPMaxScheduleType_PMaxScheduleEntry_currArrayIndex++]);
 				}
 				grammarID = 306;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 306:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}PMaxScheduleEntry), END_ELEMENT] */
 			if (v2gPMaxScheduleType_PMaxScheduleEntry_currArrayIndex < v2gPMaxScheduleType->PMaxScheduleEntry.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					errn = encode_v2gPMaxScheduleEntryType(stream, &v2gPMaxScheduleType->PMaxScheduleEntry.array [v2gPMaxScheduleType_PMaxScheduleEntry_currArrayIndex++]);
 				}
 				grammarID = 306;
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
 int encode_v2gPMaxScheduleEntryType(bitstream_t* stream, struct v2gPMaxScheduleEntryType* v2gPMaxScheduleEntryType) {
 	int grammarID = 142;
 	int done = 0;
 	int errn;

 	while(!done) {
 		switch(grammarID) {
 		case 142:
 			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}RelativeTimeInterval), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}TimeInterval)] */
 			if ( v2gPMaxScheduleEntryType->RelativeTimeInterval_isUsed == 1u ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					errn = encode_v2gRelativeTimeIntervalType(stream, &v2gPMaxScheduleEntryType->RelativeTimeInterval );
 				}
 				grammarID = 143;
 			} else 			if ( v2gPMaxScheduleEntryType->TimeInterval_isUsed == 1u ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 1);
 				if(errn == 0) {
 					errn = encode_v2gIntervalType(stream, &v2gPMaxScheduleEntryType->TimeInterval );
 				}
 				grammarID = 143;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 143:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}PMax)] */
 			if ( 1 == 1 ) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					errn = encode_v2gPhysicalValueType(stream, &v2gPMaxScheduleEntryType->PMax );
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

 /* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,RelativeTimeIntervalType',  base type name='IntervalType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":start,"urn:iso:15118:2:2013:MsgDataTypes":duration{0-1})',  derivedBy='EXTENSION'.  */
 int encode_v2gRelativeTimeIntervalType(bitstream_t* stream, struct v2gRelativeTimeIntervalType* v2gRelativeTimeIntervalType) {
 	int grammarID = 55;
 	int done = 0;
 	int errn;

 	while(!done) {
 		switch(grammarID) {
 		case 55:
 			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}start)] */
 			if ( 1 == 1 ) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					/* FirstStartTag[CHARACTERS[UNSIGNED_INTEGER]] */
 					errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					if(errn == 0) {
 						errn = encodeUnsignedInteger32(stream, v2gRelativeTimeIntervalType->start);
 						/* valid EE */
 						errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					}
 				}
 				grammarID = 56;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 56:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}duration), END_ELEMENT] */
 			if ( v2gRelativeTimeIntervalType->duration_isUsed == 1u ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					/* FirstStartTag[CHARACTERS[UNSIGNED_INTEGER]] */
 					errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					if(errn == 0) {
 						errn = encodeUnsignedInteger32(stream, v2gRelativeTimeIntervalType->duration);
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

 /* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,IntervalType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
 int encode_v2gIntervalType(bitstream_t* stream, struct v2gIntervalType* v2gIntervalType) {
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

 /* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SalesTariffType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":SalesTariffID,"urn:iso:15118:2:2013:MsgDataTypes":SalesTariffDescription{0-1},"urn:iso:15118:2:2013:MsgDataTypes":NumEPriceLevels{0-1},"urn:iso:15118:2:2013:MsgDataTypes":SalesTariffEntry{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
 int encode_v2gSalesTariffType(bitstream_t* stream, struct v2gSalesTariffType* v2gSalesTariffType) {
 	int grammarID = 26;
 	int done = 0;
 	int errn;

 	unsigned int v2gSalesTariffType_SalesTariffEntry_currArrayIndex = 0;

 	while(!done) {
 		switch(grammarID) {
 		case 26:
 			/* FirstStartTag[ATTRIBUTE[STRING]({urn:iso:15118:2:2013:MsgDataTypes}Id), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SalesTariffID)] */
 			if ( v2gSalesTariffType->Id_isUsed == 1u ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					/* encode string as string table miss (+2 len)*/
 					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gSalesTariffType->Id.charactersLen + 2));
 					if (errn == 0) {
 						errn = encodeCharacters(stream, v2gSalesTariffType->Id.characters, v2gSalesTariffType->Id.charactersLen);
 					}
 				}
 				grammarID = 27;
 			} else 			if ( 1 == 1 ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 1);
 				if(errn == 0) {
 					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
 					errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					if(errn == 0) {
 						errn = encodeNBitUnsignedInteger(stream, 8, (uint32_t)(v2gSalesTariffType->SalesTariffID - 1));
 						/* valid EE */
 						errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					}
 				}
 				grammarID = 28;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 27:
 			/* StartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SalesTariffID)] */
 			if ( 1 == 1 ) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
 					errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					if(errn == 0) {
 						errn = encodeNBitUnsignedInteger(stream, 8, (uint32_t)(v2gSalesTariffType->SalesTariffID - 1));
 						/* valid EE */
 						errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					}
 				}
 				grammarID = 28;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 28:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SalesTariffDescription), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}NumEPriceLevels), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SalesTariffEntry)] */
 			if ( v2gSalesTariffType->SalesTariffDescription_isUsed == 1u ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					/* FirstStartTag[CHARACTERS[STRING]] */
 					errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					if(errn == 0) {
 						/* encode string as string table miss (+2 len)*/
 						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gSalesTariffType->SalesTariffDescription.charactersLen + 2));
 						if (errn == 0) {
 							errn = encodeCharacters(stream, v2gSalesTariffType->SalesTariffDescription.characters, v2gSalesTariffType->SalesTariffDescription.charactersLen);
 						}
 						/* valid EE */
 						errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					}
 				}
 				grammarID = 29;
 			} else 			if ( v2gSalesTariffType->NumEPriceLevels_isUsed == 1u ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 1);
 				if(errn == 0) {
 					/* First(xsi:type)StartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
 					errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					if(errn == 0) {
 						errn = encodeNBitUnsignedInteger(stream, 8, (uint32_t)(v2gSalesTariffType->NumEPriceLevels - 0));
 						/* valid EE */
 						errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					}
 				}
 				grammarID = 30;
 			} else 			if (v2gSalesTariffType_SalesTariffEntry_currArrayIndex < v2gSalesTariffType->SalesTariffEntry.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 2);
 				if(errn == 0) {
 					errn = encode_v2gSalesTariffEntryType(stream, &v2gSalesTariffType->SalesTariffEntry.array [v2gSalesTariffType_SalesTariffEntry_currArrayIndex++]);
 				}
 				grammarID = 31;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 29:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}NumEPriceLevels), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SalesTariffEntry)] */
 			if ( v2gSalesTariffType->NumEPriceLevels_isUsed == 1u ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					/* First(xsi:type)StartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
 					errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					if(errn == 0) {
 						errn = encodeNBitUnsignedInteger(stream, 8, (uint32_t)(v2gSalesTariffType->NumEPriceLevels - 0));
 						/* valid EE */
 						errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					}
 				}
 				grammarID = 30;
 			} else 			if (v2gSalesTariffType_SalesTariffEntry_currArrayIndex < v2gSalesTariffType->SalesTariffEntry.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 1);
 				if(errn == 0) {
 					errn = encode_v2gSalesTariffEntryType(stream, &v2gSalesTariffType->SalesTariffEntry.array [v2gSalesTariffType_SalesTariffEntry_currArrayIndex++]);
 				}
 				grammarID = 31;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 30:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SalesTariffEntry)] */
 			if (v2gSalesTariffType_SalesTariffEntry_currArrayIndex < v2gSalesTariffType->SalesTariffEntry.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					errn = encode_v2gSalesTariffEntryType(stream, &v2gSalesTariffType->SalesTariffEntry.array [v2gSalesTariffType_SalesTariffEntry_currArrayIndex++]);
 				}
 				grammarID = 31;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 31:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SalesTariffEntry), END_ELEMENT] */
 			if (v2gSalesTariffType_SalesTariffEntry_currArrayIndex < v2gSalesTariffType->SalesTariffEntry.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					errn = encode_v2gSalesTariffEntryType(stream, &v2gSalesTariffType->SalesTariffEntry.array [v2gSalesTariffType_SalesTariffEntry_currArrayIndex++]);
 				}
 				grammarID = 31;
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
 int encode_v2gSalesTariffEntryType(bitstream_t* stream, struct v2gSalesTariffEntryType* v2gSalesTariffEntryType) {
 	int grammarID = 65;
 	int done = 0;
 	int errn;

 	unsigned int v2gSalesTariffEntryType_ConsumptionCost_currArrayIndex = 0;

 	while(!done) {
 		switch(grammarID) {
 		case 65:
 			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}RelativeTimeInterval), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}TimeInterval)] */
 			if ( v2gSalesTariffEntryType->RelativeTimeInterval_isUsed == 1u ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					errn = encode_v2gRelativeTimeIntervalType(stream, &v2gSalesTariffEntryType->RelativeTimeInterval );
 				}
 				grammarID = 66;
 			} else 			if ( v2gSalesTariffEntryType->TimeInterval_isUsed == 1u ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 1);
 				if(errn == 0) {
 					errn = encode_v2gIntervalType(stream, &v2gSalesTariffEntryType->TimeInterval );
 				}
 				grammarID = 66;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 66:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EPriceLevel), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ConsumptionCost), END_ELEMENT] */
 			if ( v2gSalesTariffEntryType->EPriceLevel_isUsed == 1u ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					/* First(xsi:type)StartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
 					errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					if(errn == 0) {
 						errn = encodeNBitUnsignedInteger(stream, 8, (uint32_t)(v2gSalesTariffEntryType->EPriceLevel - 0));
 						/* valid EE */
 						errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					}
 				}
 				grammarID = 67;
 			} else 			if (v2gSalesTariffEntryType_ConsumptionCost_currArrayIndex < v2gSalesTariffEntryType->ConsumptionCost.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 1);
 				if(errn == 0) {
 					errn = encode_v2gConsumptionCostType(stream, &v2gSalesTariffEntryType->ConsumptionCost.array [v2gSalesTariffEntryType_ConsumptionCost_currArrayIndex++]);
 				}
 				grammarID = 68;
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
 		case 67:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ConsumptionCost), END_ELEMENT] */
 			if (v2gSalesTariffEntryType_ConsumptionCost_currArrayIndex < v2gSalesTariffEntryType->ConsumptionCost.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					errn = encode_v2gConsumptionCostType(stream, &v2gSalesTariffEntryType->ConsumptionCost.array [v2gSalesTariffEntryType_ConsumptionCost_currArrayIndex++]);
 				}
 				grammarID = 68;
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
 		case 68:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ConsumptionCost), END_ELEMENT] */
 			if (v2gSalesTariffEntryType_ConsumptionCost_currArrayIndex < v2gSalesTariffEntryType->ConsumptionCost.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					errn = encode_v2gConsumptionCostType(stream, &v2gSalesTariffEntryType->ConsumptionCost.array [v2gSalesTariffEntryType_ConsumptionCost_currArrayIndex++]);
 				}
 				grammarID = 69;
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
 		case 69:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ConsumptionCost), END_ELEMENT] */
 			if (v2gSalesTariffEntryType_ConsumptionCost_currArrayIndex < v2gSalesTariffEntryType->ConsumptionCost.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					errn = encode_v2gConsumptionCostType(stream, &v2gSalesTariffEntryType->ConsumptionCost.array [v2gSalesTariffEntryType_ConsumptionCost_currArrayIndex++]);
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

 /* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ConsumptionCostType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":startValue,"urn:iso:15118:2:2013:MsgDataTypes":Cost{1-3})',  derivedBy='RESTRICTION'.  */
 int encode_v2gConsumptionCostType(bitstream_t* stream, struct v2gConsumptionCostType* v2gConsumptionCostType) {
 	int grammarID = 82;
 	int done = 0;
 	int errn;

 	unsigned int v2gConsumptionCostType_Cost_currArrayIndex = 0;

 	while(!done) {
 		switch(grammarID) {
 		case 82:
 			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}startValue)] */
 			if ( 1 == 1 ) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					errn = encode_v2gPhysicalValueType(stream, &v2gConsumptionCostType->startValue );
 				}
 				grammarID = 83;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 83:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Cost)] */
 			if (v2gConsumptionCostType_Cost_currArrayIndex < v2gConsumptionCostType->Cost.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					errn = encode_v2gCostType(stream, &v2gConsumptionCostType->Cost.array [v2gConsumptionCostType_Cost_currArrayIndex++]);
 				}
 				grammarID = 84;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 84:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Cost), END_ELEMENT] */
 			if (v2gConsumptionCostType_Cost_currArrayIndex < v2gConsumptionCostType->Cost.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					errn = encode_v2gCostType(stream, &v2gConsumptionCostType->Cost.array [v2gConsumptionCostType_Cost_currArrayIndex++]);
 				}
 				grammarID = 85;
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
 		case 85:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Cost), END_ELEMENT] */
 			if (v2gConsumptionCostType_Cost_currArrayIndex < v2gConsumptionCostType->Cost.arrayLen ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					errn = encode_v2gCostType(stream, &v2gConsumptionCostType->Cost.array [v2gConsumptionCostType_Cost_currArrayIndex++]);
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

 /* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,CostType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":costKind,"urn:iso:15118:2:2013:MsgDataTypes":amount,"urn:iso:15118:2:2013:MsgDataTypes":amountMultiplier{0-1})',  derivedBy='RESTRICTION'.  */
int encode_v2gCostType(bitstream_t* stream, struct v2gCostType* v2gCostType) {
 	int grammarID = 218;
 	int done = 0;
 	int errn;

 	while(!done) {
 		switch(grammarID) {
 		case 218:
 			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}costKind)] */
 			if ( 1 == 1 ) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
 					errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					if(errn == 0) {
 						errn = encodeNBitUnsignedInteger(stream, 2, v2gCostType->costKind);
 						/* valid EE */
 						errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					}
 				}
 				grammarID = 219;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 219:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}amount)] */
 			if ( 1 == 1 ) {
 				errn = encodeNBitUnsignedInteger(stream, 1, 0);
 				if(errn == 0) {
 					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
 					errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					if(errn == 0) {
 						errn = encodeUnsignedInteger32(stream, v2gCostType->amount);
 						/* valid EE */
 						errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					}
 				}
 				grammarID = 220;
 			} else {
 				errn = EXI_ERROR_UNKOWN_EVENT;
 			}
 			break;
 		case 220:
 			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}amountMultiplier), END_ELEMENT] */
 			if ( v2gCostType->amountMultiplier_isUsed == 1u ) {
 				errn = encodeNBitUnsignedInteger(stream, 2, 0);
 				if(errn == 0) {
 					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
 					errn = encodeNBitUnsignedInteger(stream, 1, 0);
 					if(errn == 0) {
 						errn = encodeNBitUnsignedInteger(stream, 3, (uint32_t)(v2gCostType->amountMultiplier + 3));
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SASchedulesType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
int encode_v2gSASchedulesType(bitstream_t* stream, struct v2gSASchedulesType* v2gSASchedulesType) {
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,MeterInfoType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":MeterID,"urn:iso:15118:2:2013:MsgDataTypes":MeterReading{0-1},"urn:iso:15118:2:2013:MsgDataTypes":SigMeterReading{0-1},"urn:iso:15118:2:2013:MsgDataTypes":MeterStatus{0-1},"urn:iso:15118:2:2013:MsgDataTypes":TMeter{0-1})',  derivedBy='RESTRICTION'.  */
int encode_v2gMeterInfoType(bitstream_t* stream, struct v2gMeterInfoType* v2gMeterInfoType) {
	int grammarID = 225;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 225:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}MeterID)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gMeterInfoType->MeterID.charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gMeterInfoType->MeterID.characters, v2gMeterInfoType->MeterID.charactersLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 226;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 226:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}MeterReading), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SigMeterReading), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}MeterStatus), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}TMeter), END_ELEMENT] */
			if ( v2gMeterInfoType->MeterReading_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger64(stream, v2gMeterInfoType->MeterReading);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 227;
			} else 			if ( v2gMeterInfoType->SigMeterReading_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gMeterInfoType->SigMeterReading.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gMeterInfoType->SigMeterReading.bytes, v2gMeterInfoType->SigMeterReading.bytesLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 228;
			} else 			if ( v2gMeterInfoType->MeterStatus_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeInteger16(stream, v2gMeterInfoType->MeterStatus);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 229;
			} else 			if ( v2gMeterInfoType->TMeter_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 3);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeInteger64(stream, v2gMeterInfoType->TMeter);
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
		case 227:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SigMeterReading), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}MeterStatus), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}TMeter), END_ELEMENT] */
			if ( v2gMeterInfoType->SigMeterReading_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gMeterInfoType->SigMeterReading.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gMeterInfoType->SigMeterReading.bytes, v2gMeterInfoType->SigMeterReading.bytesLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 228;
			} else 			if ( v2gMeterInfoType->MeterStatus_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeInteger16(stream, v2gMeterInfoType->MeterStatus);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 229;
			} else 			if ( v2gMeterInfoType->TMeter_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeInteger64(stream, v2gMeterInfoType->TMeter);
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
		case 228:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}MeterStatus), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}TMeter), END_ELEMENT] */
			if ( v2gMeterInfoType->MeterStatus_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeInteger16(stream, v2gMeterInfoType->MeterStatus);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 229;
			} else 			if ( v2gMeterInfoType->TMeter_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeInteger64(stream, v2gMeterInfoType->TMeter);
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
		case 229:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}TMeter), END_ELEMENT] */
			if ( v2gMeterInfoType->TMeter_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeInteger64(stream, v2gMeterInfoType->TMeter);
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,DSAKeyValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("http://www.w3.org/2000/09/xmldsig#":P,"http://www.w3.org/2000/09/xmldsig#":Q){0-1},"http://www.w3.org/2000/09/xmldsig#":G{0-1},"http://www.w3.org/2000/09/xmldsig#":Y,"http://www.w3.org/2000/09/xmldsig#":J{0-1},("http://www.w3.org/2000/09/xmldsig#":Seed,"http://www.w3.org/2000/09/xmldsig#":PgenCounter){0-1})',  derivedBy='RESTRICTION'.  */
int encode_v2gDSAKeyValueType(bitstream_t* stream, struct v2gDSAKeyValueType* v2gDSAKeyValueType) {
	int grammarID = 178;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 178:
			/* FirstStartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}P), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}G), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Y)] */
			if ( v2gDSAKeyValueType->P_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gDSAKeyValueType->P.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gDSAKeyValueType->P.bytes, v2gDSAKeyValueType->P.bytesLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 179;
			} else 			if ( v2gDSAKeyValueType->G_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gDSAKeyValueType->G.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gDSAKeyValueType->G.bytes, v2gDSAKeyValueType->G.bytesLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 180;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 2);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gDSAKeyValueType->Y.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gDSAKeyValueType->Y.bytes, v2gDSAKeyValueType->Y.bytesLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 181;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 179:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Q)] */
			if ( v2gDSAKeyValueType->Q_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gDSAKeyValueType->Q.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gDSAKeyValueType->Q.bytes, v2gDSAKeyValueType->Q.bytesLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 182;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 182:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}G), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Y)] */
			if ( v2gDSAKeyValueType->G_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gDSAKeyValueType->G.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gDSAKeyValueType->G.bytes, v2gDSAKeyValueType->G.bytesLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 180;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gDSAKeyValueType->Y.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gDSAKeyValueType->Y.bytes, v2gDSAKeyValueType->Y.bytesLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 181;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 180:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Y)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gDSAKeyValueType->Y.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gDSAKeyValueType->Y.bytes, v2gDSAKeyValueType->Y.bytesLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 181;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 181:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}J), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Seed), END_ELEMENT] */
			if ( v2gDSAKeyValueType->J_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gDSAKeyValueType->J.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gDSAKeyValueType->J.bytes, v2gDSAKeyValueType->J.bytesLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 183;
			} else 			if ( v2gDSAKeyValueType->Seed_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gDSAKeyValueType->Seed.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gDSAKeyValueType->Seed.bytes, v2gDSAKeyValueType->Seed.bytesLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 184;
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
		case 183:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Seed), END_ELEMENT] */
			if ( v2gDSAKeyValueType->Seed_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gDSAKeyValueType->Seed.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gDSAKeyValueType->Seed.bytes, v2gDSAKeyValueType->Seed.bytesLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 184;
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
		case 184:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PgenCounter)] */
			if ( v2gDSAKeyValueType->PgenCounter_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gDSAKeyValueType->PgenCounter.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gDSAKeyValueType->PgenCounter.bytes, v2gDSAKeyValueType->PgenCounter.bytesLen);
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,DigestMethodType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='((WC[##other:"http://www.w3.org/2000/09/xmldsig#"]){0-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int encode_v2gDigestMethodType(bitstream_t* stream, struct v2gDigestMethodType* v2gDigestMethodType) {
	int grammarID = 267;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 267:
			/* FirstStartTag[ATTRIBUTE[STRING](Algorithm)] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gDigestMethodType->Algorithm.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gDigestMethodType->Algorithm.characters, v2gDigestMethodType->Algorithm.charactersLen);
					}
				}
				grammarID = 47;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 47:
			/* StartTag[START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 35:
			/* Element[START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EVPowerDeliveryParameterType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
int encode_v2gEVPowerDeliveryParameterType(bitstream_t* stream, struct v2gEVPowerDeliveryParameterType* v2gEVPowerDeliveryParameterType) {
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EntryType',  base type name='anyType',  content type='ELEMENT',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":TimeInterval)',  derivedBy='RESTRICTION'.  */
int encode_v2gEntryType(bitstream_t* stream, struct v2gEntryType* v2gEntryType) {
	int grammarID = 232;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 232:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}RelativeTimeInterval), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}TimeInterval)] */
			if ( v2gEntryType->RelativeTimeInterval_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gRelativeTimeIntervalType(stream, &v2gEntryType->RelativeTimeInterval );
				}
				grammarID = 5;
			} else 			if ( v2gEntryType->TimeInterval_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gIntervalType(stream, &v2gEntryType->TimeInterval );
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,KeyInfoType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":KeyName|"http://www.w3.org/2000/09/xmldsig#":KeyValue|"http://www.w3.org/2000/09/xmldsig#":RetrievalMethod|"http://www.w3.org/2000/09/xmldsig#":X509Data|"http://www.w3.org/2000/09/xmldsig#":PGPData|"http://www.w3.org/2000/09/xmldsig#":SPKIData|"http://www.w3.org/2000/09/xmldsig#":MgmtData|(WC[##other:"http://www.w3.org/2000/09/xmldsig#"])){1-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
int encode_v2gKeyInfoType(bitstream_t* stream, struct v2gKeyInfoType* v2gKeyInfoType) {
	int grammarID = 114;
	int done = 0;
	int errn;

	unsigned int v2gKeyInfoType_KeyName_currArrayIndex = 0;
	unsigned int v2gKeyInfoType_KeyValue_currArrayIndex = 0;
	unsigned int v2gKeyInfoType_RetrievalMethod_currArrayIndex = 0;
	unsigned int v2gKeyInfoType_X509Data_currArrayIndex = 0;
	unsigned int v2gKeyInfoType_PGPData_currArrayIndex = 0;
	unsigned int v2gKeyInfoType_SPKIData_currArrayIndex = 0;
	unsigned int v2gKeyInfoType_MgmtData_currArrayIndex = 0;

	while(!done) {
		switch(grammarID) {
		case 114:
			/* FirstStartTag[ATTRIBUTE[STRING](Id), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyName), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyValue), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}RetrievalMethod), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509Data), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PGPData), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SPKIData), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}MgmtData), START_ELEMENT_GENERIC, CHARACTERS_GENERIC[STRING]] */
			if ( v2gKeyInfoType->Id_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gKeyInfoType->Id.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gKeyInfoType->Id.characters, v2gKeyInfoType->Id.charactersLen);
					}
				}
				grammarID = 115;
			} else 			if (v2gKeyInfoType_KeyName_currArrayIndex < v2gKeyInfoType->KeyName.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 1);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gKeyInfoType->KeyName.array[v2gKeyInfoType_KeyName_currArrayIndex].charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gKeyInfoType->KeyName.array[v2gKeyInfoType_KeyName_currArrayIndex].characters, v2gKeyInfoType->KeyName.array[v2gKeyInfoType_KeyName_currArrayIndex].charactersLen);
							v2gKeyInfoType_KeyName_currArrayIndex++;
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_KeyValue_currArrayIndex < v2gKeyInfoType->KeyValue.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 2);
				if(errn == 0) {
					errn = encode_v2gKeyValueType(stream, &v2gKeyInfoType->KeyValue.array [v2gKeyInfoType_KeyValue_currArrayIndex++]);
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_RetrievalMethod_currArrayIndex < v2gKeyInfoType->RetrievalMethod.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 3);
				if(errn == 0) {
					errn = encode_v2gRetrievalMethodType(stream, &v2gKeyInfoType->RetrievalMethod.array [v2gKeyInfoType_RetrievalMethod_currArrayIndex++]);
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_X509Data_currArrayIndex < v2gKeyInfoType->X509Data.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 4);
				if(errn == 0) {
					errn = encode_v2gX509DataType(stream, &v2gKeyInfoType->X509Data.array [v2gKeyInfoType_X509Data_currArrayIndex++]);
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_PGPData_currArrayIndex < v2gKeyInfoType->PGPData.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 5);
				if(errn == 0) {
					errn = encode_v2gPGPDataType(stream, &v2gKeyInfoType->PGPData.array [v2gKeyInfoType_PGPData_currArrayIndex++]);
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_SPKIData_currArrayIndex < v2gKeyInfoType->SPKIData.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 6);
				if(errn == 0) {
					errn = encode_v2gSPKIDataType(stream, &v2gKeyInfoType->SPKIData.array [v2gKeyInfoType_SPKIData_currArrayIndex++]);
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_MgmtData_currArrayIndex < v2gKeyInfoType->MgmtData.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 7);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gKeyInfoType->MgmtData.array[v2gKeyInfoType_MgmtData_currArrayIndex].charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gKeyInfoType->MgmtData.array[v2gKeyInfoType_MgmtData_currArrayIndex].characters, v2gKeyInfoType->MgmtData.array[v2gKeyInfoType_MgmtData_currArrayIndex].charactersLen);
							v2gKeyInfoType_MgmtData_currArrayIndex++;
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 116;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 116;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 117;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 115:
			/* StartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyName), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyValue), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}RetrievalMethod), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509Data), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PGPData), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SPKIData), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}MgmtData), START_ELEMENT_GENERIC, CHARACTERS_GENERIC[STRING]] */
			if (v2gKeyInfoType_KeyName_currArrayIndex < v2gKeyInfoType->KeyName.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gKeyInfoType->KeyName.array[v2gKeyInfoType_KeyName_currArrayIndex].charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gKeyInfoType->KeyName.array[v2gKeyInfoType_KeyName_currArrayIndex].characters, v2gKeyInfoType->KeyName.array[v2gKeyInfoType_KeyName_currArrayIndex].charactersLen);
							v2gKeyInfoType_KeyName_currArrayIndex++;
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_KeyValue_currArrayIndex < v2gKeyInfoType->KeyValue.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 1);
				if(errn == 0) {
					errn = encode_v2gKeyValueType(stream, &v2gKeyInfoType->KeyValue.array [v2gKeyInfoType_KeyValue_currArrayIndex++]);
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_RetrievalMethod_currArrayIndex < v2gKeyInfoType->RetrievalMethod.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 2);
				if(errn == 0) {
					errn = encode_v2gRetrievalMethodType(stream, &v2gKeyInfoType->RetrievalMethod.array [v2gKeyInfoType_RetrievalMethod_currArrayIndex++]);
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_X509Data_currArrayIndex < v2gKeyInfoType->X509Data.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 3);
				if(errn == 0) {
					errn = encode_v2gX509DataType(stream, &v2gKeyInfoType->X509Data.array [v2gKeyInfoType_X509Data_currArrayIndex++]);
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_PGPData_currArrayIndex < v2gKeyInfoType->PGPData.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 4);
				if(errn == 0) {
					errn = encode_v2gPGPDataType(stream, &v2gKeyInfoType->PGPData.array [v2gKeyInfoType_PGPData_currArrayIndex++]);
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_SPKIData_currArrayIndex < v2gKeyInfoType->SPKIData.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 5);
				if(errn == 0) {
					errn = encode_v2gSPKIDataType(stream, &v2gKeyInfoType->SPKIData.array [v2gKeyInfoType_SPKIData_currArrayIndex++]);
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_MgmtData_currArrayIndex < v2gKeyInfoType->MgmtData.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 6);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gKeyInfoType->MgmtData.array[v2gKeyInfoType_MgmtData_currArrayIndex].charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gKeyInfoType->MgmtData.array[v2gKeyInfoType_MgmtData_currArrayIndex].characters, v2gKeyInfoType->MgmtData.array[v2gKeyInfoType_MgmtData_currArrayIndex].charactersLen);
							v2gKeyInfoType_MgmtData_currArrayIndex++;
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 116;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 116;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 117;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 116:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyName), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyValue), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}RetrievalMethod), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509Data), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PGPData), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SPKIData), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}MgmtData), START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			if (v2gKeyInfoType_KeyName_currArrayIndex < v2gKeyInfoType->KeyName.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gKeyInfoType->KeyName.array[v2gKeyInfoType_KeyName_currArrayIndex].charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gKeyInfoType->KeyName.array[v2gKeyInfoType_KeyName_currArrayIndex].characters, v2gKeyInfoType->KeyName.array[v2gKeyInfoType_KeyName_currArrayIndex].charactersLen);
							v2gKeyInfoType_KeyName_currArrayIndex++;
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_KeyValue_currArrayIndex < v2gKeyInfoType->KeyValue.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 1);
				if(errn == 0) {
					errn = encode_v2gKeyValueType(stream, &v2gKeyInfoType->KeyValue.array [v2gKeyInfoType_KeyValue_currArrayIndex++]);
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_RetrievalMethod_currArrayIndex < v2gKeyInfoType->RetrievalMethod.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 2);
				if(errn == 0) {
					errn = encode_v2gRetrievalMethodType(stream, &v2gKeyInfoType->RetrievalMethod.array [v2gKeyInfoType_RetrievalMethod_currArrayIndex++]);
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_X509Data_currArrayIndex < v2gKeyInfoType->X509Data.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 3);
				if(errn == 0) {
					errn = encode_v2gX509DataType(stream, &v2gKeyInfoType->X509Data.array [v2gKeyInfoType_X509Data_currArrayIndex++]);
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_PGPData_currArrayIndex < v2gKeyInfoType->PGPData.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 4);
				if(errn == 0) {
					errn = encode_v2gPGPDataType(stream, &v2gKeyInfoType->PGPData.array [v2gKeyInfoType_PGPData_currArrayIndex++]);
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_SPKIData_currArrayIndex < v2gKeyInfoType->SPKIData.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 5);
				if(errn == 0) {
					errn = encode_v2gSPKIDataType(stream, &v2gKeyInfoType->SPKIData.array [v2gKeyInfoType_SPKIData_currArrayIndex++]);
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_MgmtData_currArrayIndex < v2gKeyInfoType->MgmtData.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 6);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gKeyInfoType->MgmtData.array[v2gKeyInfoType_MgmtData_currArrayIndex].charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gKeyInfoType->MgmtData.array[v2gKeyInfoType_MgmtData_currArrayIndex].characters, v2gKeyInfoType->MgmtData.array[v2gKeyInfoType_MgmtData_currArrayIndex].charactersLen);
							v2gKeyInfoType_MgmtData_currArrayIndex++;
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 116;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 116;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 4, 8);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 116;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 117:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyName), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyValue), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}RetrievalMethod), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509Data), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PGPData), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SPKIData), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}MgmtData), START_ELEMENT_GENERIC, CHARACTERS_GENERIC[STRING]] */
			if (v2gKeyInfoType_KeyName_currArrayIndex < v2gKeyInfoType->KeyName.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gKeyInfoType->KeyName.array[v2gKeyInfoType_KeyName_currArrayIndex].charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gKeyInfoType->KeyName.array[v2gKeyInfoType_KeyName_currArrayIndex].characters, v2gKeyInfoType->KeyName.array[v2gKeyInfoType_KeyName_currArrayIndex].charactersLen);
							v2gKeyInfoType_KeyName_currArrayIndex++;
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_KeyValue_currArrayIndex < v2gKeyInfoType->KeyValue.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 1);
				if(errn == 0) {
					errn = encode_v2gKeyValueType(stream, &v2gKeyInfoType->KeyValue.array [v2gKeyInfoType_KeyValue_currArrayIndex++]);
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_RetrievalMethod_currArrayIndex < v2gKeyInfoType->RetrievalMethod.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 2);
				if(errn == 0) {
					errn = encode_v2gRetrievalMethodType(stream, &v2gKeyInfoType->RetrievalMethod.array [v2gKeyInfoType_RetrievalMethod_currArrayIndex++]);
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_X509Data_currArrayIndex < v2gKeyInfoType->X509Data.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 3);
				if(errn == 0) {
					errn = encode_v2gX509DataType(stream, &v2gKeyInfoType->X509Data.array [v2gKeyInfoType_X509Data_currArrayIndex++]);
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_PGPData_currArrayIndex < v2gKeyInfoType->PGPData.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 4);
				if(errn == 0) {
					errn = encode_v2gPGPDataType(stream, &v2gKeyInfoType->PGPData.array [v2gKeyInfoType_PGPData_currArrayIndex++]);
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_SPKIData_currArrayIndex < v2gKeyInfoType->SPKIData.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 5);
				if(errn == 0) {
					errn = encode_v2gSPKIDataType(stream, &v2gKeyInfoType->SPKIData.array [v2gKeyInfoType_SPKIData_currArrayIndex++]);
				}
				grammarID = 116;
			} else 			if (v2gKeyInfoType_MgmtData_currArrayIndex < v2gKeyInfoType->MgmtData.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 4, 6);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gKeyInfoType->MgmtData.array[v2gKeyInfoType_MgmtData_currArrayIndex].charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gKeyInfoType->MgmtData.array[v2gKeyInfoType_MgmtData_currArrayIndex].characters, v2gKeyInfoType->MgmtData.array[v2gKeyInfoType_MgmtData_currArrayIndex].charactersLen);
							v2gKeyInfoType_MgmtData_currArrayIndex++;
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 116;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 116;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 117;
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,KeyValueType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":DSAKeyValue|"http://www.w3.org/2000/09/xmldsig#":RSAKeyValue|(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]))',  derivedBy='RESTRICTION'.  */
int encode_v2gKeyValueType(bitstream_t* stream, struct v2gKeyValueType* v2gKeyValueType) {
	int grammarID = 268;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 268:
			/* FirstStartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DSAKeyValue), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}RSAKeyValue), START_ELEMENT_GENERIC, CHARACTERS_GENERIC[STRING]] */
			if ( v2gKeyValueType->DSAKeyValue_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					errn = encode_v2gDSAKeyValueType(stream, &v2gKeyValueType->DSAKeyValue );
				}
				grammarID = 269;
			} else 			if ( v2gKeyValueType->RSAKeyValue_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 1);
				if(errn == 0) {
					errn = encode_v2gRSAKeyValueType(stream, &v2gKeyValueType->RSAKeyValue );
				}
				grammarID = 269;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 269;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 270;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 269:
			/* Element[END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 269;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 270:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DSAKeyValue), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}RSAKeyValue), START_ELEMENT_GENERIC, CHARACTERS_GENERIC[STRING]] */
			if ( v2gKeyValueType->DSAKeyValue_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					errn = encode_v2gDSAKeyValueType(stream, &v2gKeyValueType->DSAKeyValue );
				}
				grammarID = 269;
			} else 			if ( v2gKeyValueType->RSAKeyValue_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 1);
				if(errn == 0) {
					errn = encode_v2gRSAKeyValueType(stream, &v2gKeyValueType->RSAKeyValue );
				}
				grammarID = 269;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 269;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 270;
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,RSAKeyValueType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":Modulus,"http://www.w3.org/2000/09/xmldsig#":Exponent)',  derivedBy='RESTRICTION'.  */
int encode_v2gRSAKeyValueType(bitstream_t* stream, struct v2gRSAKeyValueType* v2gRSAKeyValueType) {
	int grammarID = 198;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 198:
			/* FirstStartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Modulus)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gRSAKeyValueType->Modulus.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gRSAKeyValueType->Modulus.bytes, v2gRSAKeyValueType->Modulus.bytesLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 199;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 199:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Exponent)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gRSAKeyValueType->Exponent.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gRSAKeyValueType->Exponent.bytes, v2gRSAKeyValueType->Exponent.bytesLen);
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,RetrievalMethodType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":Transforms{0-1})',  derivedBy='RESTRICTION'.  */
int encode_v2gRetrievalMethodType(bitstream_t* stream, struct v2gRetrievalMethodType* v2gRetrievalMethodType) {
	int grammarID = 284;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 284:
			/* FirstStartTag[ATTRIBUTE[STRING](Type), ATTRIBUTE[STRING](URI), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transforms), END_ELEMENT] */
			if ( v2gRetrievalMethodType->Type_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gRetrievalMethodType->Type.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gRetrievalMethodType->Type.characters, v2gRetrievalMethodType->Type.charactersLen);
					}
				}
				grammarID = 285;
			} else 			if ( v2gRetrievalMethodType->URI_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 1);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gRetrievalMethodType->URI.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gRetrievalMethodType->URI.characters, v2gRetrievalMethodType->URI.charactersLen);
					}
				}
				grammarID = 286;
			} else 			if ( v2gRetrievalMethodType->Transforms_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					errn = encode_v2gTransformsType(stream, &v2gRetrievalMethodType->Transforms );
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
		case 285:
			/* StartTag[ATTRIBUTE[STRING](URI), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transforms), END_ELEMENT] */
			if ( v2gRetrievalMethodType->URI_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gRetrievalMethodType->URI.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gRetrievalMethodType->URI.characters, v2gRetrievalMethodType->URI.charactersLen);
					}
				}
				grammarID = 286;
			} else 			if ( v2gRetrievalMethodType->Transforms_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gTransformsType(stream, &v2gRetrievalMethodType->Transforms );
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
		case 286:
			/* StartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transforms), END_ELEMENT] */
			if ( v2gRetrievalMethodType->Transforms_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gTransformsType(stream, &v2gRetrievalMethodType->Transforms );
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,TransformsType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":Transform{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int encode_v2gTransformsType(bitstream_t* stream, struct v2gTransformsType* v2gTransformsType) {
	int grammarID = 105;
	int done = 0;
	int errn;

	unsigned int v2gTransformsType_Transform_currArrayIndex = 0;

	while(!done) {
		switch(grammarID) {
		case 105:
			/* FirstStartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transform)] */
			if (v2gTransformsType_Transform_currArrayIndex < v2gTransformsType->Transform.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gTransformType(stream, &v2gTransformsType->Transform.array [v2gTransformsType_Transform_currArrayIndex++]);
				}
				grammarID = 106;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 106:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transform), END_ELEMENT] */
			if (v2gTransformsType_Transform_currArrayIndex < v2gTransformsType->Transform.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gTransformType(stream, &v2gTransformsType->Transform.array [v2gTransformsType_Transform_currArrayIndex++]);
				}
				grammarID = 106;
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
int encode_v2gTransformType(bitstream_t* stream, struct v2gTransformType* v2gTransformType) {
	int grammarID = 271;
	int done = 0;
	int errn;

	unsigned int v2gTransformType_XPath_currArrayIndex = 0;

	while(!done) {
		switch(grammarID) {
		case 271:
			/* FirstStartTag[ATTRIBUTE[STRING](Algorithm)] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gTransformType->Algorithm.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gTransformType->Algorithm.characters, v2gTransformType->Algorithm.charactersLen);
					}
				}
				grammarID = 272;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 272:
			/* StartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}XPath), START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			if (v2gTransformType_XPath_currArrayIndex < v2gTransformType->XPath.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gTransformType->XPath.array[v2gTransformType_XPath_currArrayIndex].charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gTransformType->XPath.array[v2gTransformType_XPath_currArrayIndex].characters, v2gTransformType->XPath.array[v2gTransformType_XPath_currArrayIndex].charactersLen);
							v2gTransformType_XPath_currArrayIndex++;
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 273;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 273;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 273;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 273:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}XPath), START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			if (v2gTransformType_XPath_currArrayIndex < v2gTransformType->XPath.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gTransformType->XPath.array[v2gTransformType_XPath_currArrayIndex].charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gTransformType->XPath.array[v2gTransformType_XPath_currArrayIndex].characters, v2gTransformType->XPath.array[v2gTransformType_XPath_currArrayIndex].charactersLen);
							v2gTransformType_XPath_currArrayIndex++;
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 273;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 273;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 273;
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,X509DataType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("http://www.w3.org/2000/09/xmldsig#":X509IssuerSerial|"http://www.w3.org/2000/09/xmldsig#":X509SKI|"http://www.w3.org/2000/09/xmldsig#":X509SubjectName|"http://www.w3.org/2000/09/xmldsig#":X509Certificate|"http://www.w3.org/2000/09/xmldsig#":X509CRL|(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]))){1-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
int encode_v2gX509DataType(bitstream_t* stream, struct v2gX509DataType* v2gX509DataType) {
	int grammarID = 221;
	int done = 0;
	int errn;

	unsigned int v2gX509DataType_X509IssuerSerial_currArrayIndex = 0;
	unsigned int v2gX509DataType_X509SKI_currArrayIndex = 0;
	unsigned int v2gX509DataType_X509SubjectName_currArrayIndex = 0;
	unsigned int v2gX509DataType_X509Certificate_currArrayIndex = 0;
	unsigned int v2gX509DataType_X509CRL_currArrayIndex = 0;

	while(!done) {
		switch(grammarID) {
		case 221:
			/* FirstStartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509IssuerSerial), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509SKI), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509SubjectName), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509Certificate), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509CRL), START_ELEMENT_GENERIC] */
			if (v2gX509DataType_X509IssuerSerial_currArrayIndex < v2gX509DataType->X509IssuerSerial.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					errn = encode_v2gX509IssuerSerialType(stream, &v2gX509DataType->X509IssuerSerial.array [v2gX509DataType_X509IssuerSerial_currArrayIndex++]);
				}
				grammarID = 222;
			} else 			if (v2gX509DataType_X509SKI_currArrayIndex < v2gX509DataType->X509SKI.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 1);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gX509DataType->X509SKI.array[v2gX509DataType_X509SKI_currArrayIndex].bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gX509DataType->X509SKI.array[v2gX509DataType_X509SKI_currArrayIndex].bytes, v2gX509DataType->X509SKI.array[v2gX509DataType_X509SKI_currArrayIndex].bytesLen);
							v2gX509DataType_X509SKI_currArrayIndex++;
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 222;
			} else 			if (v2gX509DataType_X509SubjectName_currArrayIndex < v2gX509DataType->X509SubjectName.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gX509DataType->X509SubjectName.array[v2gX509DataType_X509SubjectName_currArrayIndex].charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gX509DataType->X509SubjectName.array[v2gX509DataType_X509SubjectName_currArrayIndex].characters, v2gX509DataType->X509SubjectName.array[v2gX509DataType_X509SubjectName_currArrayIndex].charactersLen);
							v2gX509DataType_X509SubjectName_currArrayIndex++;
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 222;
			} else 			if (v2gX509DataType_X509Certificate_currArrayIndex < v2gX509DataType->X509Certificate.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 3);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gX509DataType->X509Certificate.array[v2gX509DataType_X509Certificate_currArrayIndex].bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gX509DataType->X509Certificate.array[v2gX509DataType_X509Certificate_currArrayIndex].bytes, v2gX509DataType->X509Certificate.array[v2gX509DataType_X509Certificate_currArrayIndex].bytesLen);
							v2gX509DataType_X509Certificate_currArrayIndex++;
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 222;
			} else 			if (v2gX509DataType_X509CRL_currArrayIndex < v2gX509DataType->X509CRL.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 4);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gX509DataType->X509CRL.array[v2gX509DataType_X509CRL_currArrayIndex].bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gX509DataType->X509CRL.array[v2gX509DataType_X509CRL_currArrayIndex].bytes, v2gX509DataType->X509CRL.array[v2gX509DataType_X509CRL_currArrayIndex].bytesLen);
							v2gX509DataType_X509CRL_currArrayIndex++;
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 222;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 222;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 222:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509IssuerSerial), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509SKI), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509SubjectName), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509Certificate), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}X509CRL), START_ELEMENT_GENERIC, END_ELEMENT] */
			if (v2gX509DataType_X509IssuerSerial_currArrayIndex < v2gX509DataType->X509IssuerSerial.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					errn = encode_v2gX509IssuerSerialType(stream, &v2gX509DataType->X509IssuerSerial.array [v2gX509DataType_X509IssuerSerial_currArrayIndex++]);
				}
				grammarID = 222;
			} else 			if (v2gX509DataType_X509SKI_currArrayIndex < v2gX509DataType->X509SKI.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 1);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gX509DataType->X509SKI.array[v2gX509DataType_X509SKI_currArrayIndex].bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gX509DataType->X509SKI.array[v2gX509DataType_X509SKI_currArrayIndex].bytes, v2gX509DataType->X509SKI.array[v2gX509DataType_X509SKI_currArrayIndex].bytesLen);
							v2gX509DataType_X509SKI_currArrayIndex++;
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 222;
			} else 			if (v2gX509DataType_X509SubjectName_currArrayIndex < v2gX509DataType->X509SubjectName.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gX509DataType->X509SubjectName.array[v2gX509DataType_X509SubjectName_currArrayIndex].charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gX509DataType->X509SubjectName.array[v2gX509DataType_X509SubjectName_currArrayIndex].characters, v2gX509DataType->X509SubjectName.array[v2gX509DataType_X509SubjectName_currArrayIndex].charactersLen);
							v2gX509DataType_X509SubjectName_currArrayIndex++;
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 222;
			} else 			if (v2gX509DataType_X509Certificate_currArrayIndex < v2gX509DataType->X509Certificate.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 3);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gX509DataType->X509Certificate.array[v2gX509DataType_X509Certificate_currArrayIndex].bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gX509DataType->X509Certificate.array[v2gX509DataType_X509Certificate_currArrayIndex].bytes, v2gX509DataType->X509Certificate.array[v2gX509DataType_X509Certificate_currArrayIndex].bytesLen);
							v2gX509DataType_X509Certificate_currArrayIndex++;
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 222;
			} else 			if (v2gX509DataType_X509CRL_currArrayIndex < v2gX509DataType->X509CRL.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 4);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gX509DataType->X509CRL.array[v2gX509DataType_X509CRL_currArrayIndex].bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gX509DataType->X509CRL.array[v2gX509DataType_X509CRL_currArrayIndex].bytes, v2gX509DataType->X509CRL.array[v2gX509DataType_X509CRL_currArrayIndex].bytesLen);
							v2gX509DataType_X509CRL_currArrayIndex++;
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 222;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 222;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 3, 6);
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,SPKIDataType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":SPKISexp,(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]){0-1}){1-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
int encode_v2gSPKIDataType(bitstream_t* stream, struct v2gSPKIDataType* v2gSPKIDataType) {
	int grammarID = 39;
	int done = 0;
	int errn;

	unsigned int v2gSPKIDataType_SPKISexp_currArrayIndex = 0;

	while(!done) {
		switch(grammarID) {
		case 39:
			/* FirstStartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SPKISexp)] */
			if (v2gSPKIDataType_SPKISexp_currArrayIndex < v2gSPKIDataType->SPKISexp.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gSPKIDataType->SPKISexp.array[v2gSPKIDataType_SPKISexp_currArrayIndex].bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gSPKIDataType->SPKISexp.array[v2gSPKIDataType_SPKISexp_currArrayIndex].bytes, v2gSPKIDataType->SPKISexp.array[v2gSPKIDataType_SPKISexp_currArrayIndex].bytesLen);
							v2gSPKIDataType_SPKISexp_currArrayIndex++;
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 40;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 40:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SPKISexp), START_ELEMENT_GENERIC, END_ELEMENT] */
			if (v2gSPKIDataType_SPKISexp_currArrayIndex < v2gSPKIDataType->SPKISexp.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gSPKIDataType->SPKISexp.array[v2gSPKIDataType_SPKISexp_currArrayIndex].bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gSPKIDataType->SPKISexp.array[v2gSPKIDataType_SPKISexp_currArrayIndex].bytes, v2gSPKIDataType->SPKISexp.array[v2gSPKIDataType_SPKISexp_currArrayIndex].bytesLen);
							v2gSPKIDataType_SPKISexp_currArrayIndex++;
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 40;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 41;
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
		case 41:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SPKISexp), END_ELEMENT] */
			if (v2gSPKIDataType_SPKISexp_currArrayIndex < v2gSPKIDataType->SPKISexp.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gSPKIDataType->SPKISexp.array[v2gSPKIDataType_SPKISexp_currArrayIndex].bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gSPKIDataType->SPKISexp.array[v2gSPKIDataType_SPKISexp_currArrayIndex].bytes, v2gSPKIDataType->SPKISexp.array[v2gSPKIDataType_SPKISexp_currArrayIndex].bytesLen);
							v2gSPKIDataType_SPKISexp_currArrayIndex++;
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 40;
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
int encode_v2gPGPDataType(bitstream_t* stream, struct v2gPGPDataType* v2gPGPDataType) {
	int grammarID = 158;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 158:
			/* FirstStartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PGPKeyID), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PGPKeyPacket)] */
			if ( v2gPGPDataType->PGPKeyID_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gPGPDataType->PGPKeyID.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gPGPDataType->PGPKeyID.bytes, v2gPGPDataType->PGPKeyID.bytesLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 159;
			} else 			if ( v2gPGPDataType->PGPKeyPacket_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gPGPDataType->PGPKeyPacket.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gPGPDataType->PGPKeyPacket.bytes, v2gPGPDataType->PGPKeyPacket.bytesLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 160;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 159:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}PGPKeyPacket), START_ELEMENT_GENERIC, END_ELEMENT] */
			if ( v2gPGPDataType->PGPKeyPacket_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gPGPDataType->PGPKeyPacket.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gPGPDataType->PGPKeyPacket.bytes, v2gPGPDataType->PGPKeyPacket.bytesLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 160;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 160;
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
		case 160:
			/* Element[START_ELEMENT_GENERIC, END_ELEMENT] */
			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 160;
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
int encode_v2gManifestType(bitstream_t* stream, struct v2gManifestType* v2gManifestType) {
	int grammarID = 48;
	int done = 0;
	int errn;

	unsigned int v2gManifestType_Reference_currArrayIndex = 0;

	while(!done) {
		switch(grammarID) {
		case 48:
			/* FirstStartTag[ATTRIBUTE[STRING](Id), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Reference)] */
			if ( v2gManifestType->Id_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gManifestType->Id.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gManifestType->Id.characters, v2gManifestType->Id.charactersLen);
					}
				}
				grammarID = 49;
			} else 			if (v2gManifestType_Reference_currArrayIndex < v2gManifestType->Reference.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gReferenceType(stream, &v2gManifestType->Reference.array [v2gManifestType_Reference_currArrayIndex++]);
				}
				grammarID = 50;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 49:
			/* StartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Reference)] */
			if (v2gManifestType_Reference_currArrayIndex < v2gManifestType->Reference.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gReferenceType(stream, &v2gManifestType->Reference.array [v2gManifestType_Reference_currArrayIndex++]);
				}
				grammarID = 50;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 50:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Reference), END_ELEMENT] */
			if (v2gManifestType_Reference_currArrayIndex < v2gManifestType->Reference.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gReferenceType(stream, &v2gManifestType->Reference.array [v2gManifestType_Reference_currArrayIndex++]);
				}
				grammarID = 50;
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
int encode_v2gReferenceType(bitstream_t* stream, struct v2gReferenceType* v2gReferenceType) {
	int grammarID = 192;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 192:
			/* FirstStartTag[ATTRIBUTE[STRING](Id), ATTRIBUTE[STRING](Type), ATTRIBUTE[STRING](URI), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transforms), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DigestMethod)] */
			if ( v2gReferenceType->Id_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gReferenceType->Id.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gReferenceType->Id.characters, v2gReferenceType->Id.charactersLen);
					}
				}
				grammarID = 193;
			} else 			if ( v2gReferenceType->Type_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 1);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gReferenceType->Type.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gReferenceType->Type.characters, v2gReferenceType->Type.charactersLen);
					}
				}
				grammarID = 194;
			} else 			if ( v2gReferenceType->URI_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gReferenceType->URI.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gReferenceType->URI.characters, v2gReferenceType->URI.charactersLen);
					}
				}
				grammarID = 195;
			} else 			if ( v2gReferenceType->Transforms_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 3);
				if(errn == 0) {
					errn = encode_v2gTransformsType(stream, &v2gReferenceType->Transforms );
				}
				grammarID = 196;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 4);
				if(errn == 0) {
					errn = encode_v2gDigestMethodType(stream, &v2gReferenceType->DigestMethod );
				}
				grammarID = 197;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 193:
			/* StartTag[ATTRIBUTE[STRING](Type), ATTRIBUTE[STRING](URI), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transforms), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DigestMethod)] */
			if ( v2gReferenceType->Type_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gReferenceType->Type.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gReferenceType->Type.characters, v2gReferenceType->Type.charactersLen);
					}
				}
				grammarID = 194;
			} else 			if ( v2gReferenceType->URI_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 1);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gReferenceType->URI.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gReferenceType->URI.characters, v2gReferenceType->URI.charactersLen);
					}
				}
				grammarID = 195;
			} else 			if ( v2gReferenceType->Transforms_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					errn = encode_v2gTransformsType(stream, &v2gReferenceType->Transforms );
				}
				grammarID = 196;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 3);
				if(errn == 0) {
					errn = encode_v2gDigestMethodType(stream, &v2gReferenceType->DigestMethod );
				}
				grammarID = 197;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 194:
			/* StartTag[ATTRIBUTE[STRING](URI), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transforms), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DigestMethod)] */
			if ( v2gReferenceType->URI_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gReferenceType->URI.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gReferenceType->URI.characters, v2gReferenceType->URI.charactersLen);
					}
				}
				grammarID = 195;
			} else 			if ( v2gReferenceType->Transforms_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gTransformsType(stream, &v2gReferenceType->Transforms );
				}
				grammarID = 196;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 2);
				if(errn == 0) {
					errn = encode_v2gDigestMethodType(stream, &v2gReferenceType->DigestMethod );
				}
				grammarID = 197;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 195:
			/* StartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Transforms), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DigestMethod)] */
			if ( v2gReferenceType->Transforms_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gTransformsType(stream, &v2gReferenceType->Transforms );
				}
				grammarID = 196;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gDigestMethodType(stream, &v2gReferenceType->DigestMethod );
				}
				grammarID = 197;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 196:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DigestMethod)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gDigestMethodType(stream, &v2gReferenceType->DigestMethod );
				}
				grammarID = 197;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 197:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}DigestValue)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gReferenceType->DigestValue.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gReferenceType->DigestValue.bytes, v2gReferenceType->DigestValue.bytesLen);
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,ObjectType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='((WC[##any])){0-UNBOUNDED}',  derivedBy='RESTRICTION'.  */
int encode_v2gObjectType(bitstream_t* stream, struct v2gObjectType* v2gObjectType) {
	int grammarID = 44;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 44:
			/* FirstStartTag[ATTRIBUTE[STRING](Encoding), ATTRIBUTE[STRING](Id), ATTRIBUTE[STRING](MimeType), START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			if ( v2gObjectType->Encoding_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gObjectType->Encoding.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gObjectType->Encoding.characters, v2gObjectType->Encoding.charactersLen);
					}
				}
				grammarID = 45;
			} else 			if ( v2gObjectType->Id_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 1);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gObjectType->Id.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gObjectType->Id.characters, v2gObjectType->Id.charactersLen);
					}
				}
				grammarID = 46;
			} else 			if ( v2gObjectType->MimeType_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gObjectType->MimeType.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gObjectType->MimeType.characters, v2gObjectType->MimeType.charactersLen);
					}
				}
				grammarID = 47;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 3, 4);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 45:
			/* StartTag[ATTRIBUTE[STRING](Id), ATTRIBUTE[STRING](MimeType), START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			if ( v2gObjectType->Id_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gObjectType->Id.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gObjectType->Id.characters, v2gObjectType->Id.charactersLen);
					}
				}
				grammarID = 46;
			} else 			if ( v2gObjectType->MimeType_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 1);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gObjectType->MimeType.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gObjectType->MimeType.characters, v2gObjectType->MimeType.charactersLen);
					}
				}
				grammarID = 47;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 3, 3);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 46:
			/* StartTag[ATTRIBUTE[STRING](MimeType), START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			if ( v2gObjectType->MimeType_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gObjectType->MimeType.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gObjectType->MimeType.characters, v2gObjectType->MimeType.charactersLen);
					}
				}
				grammarID = 47;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 47:
			/* StartTag[START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 35:
			/* Element[START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SelectedServiceListType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":SelectedService{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int encode_v2gSelectedServiceListType(bitstream_t* stream, struct v2gSelectedServiceListType* v2gSelectedServiceListType) {
	int grammarID = 238;
	int done = 0;
	int errn;

	unsigned int v2gSelectedServiceListType_SelectedService_currArrayIndex = 0;

	while(!done) {
		switch(grammarID) {
		case 238:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SelectedService)] */
			if (v2gSelectedServiceListType_SelectedService_currArrayIndex < v2gSelectedServiceListType->SelectedService.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gSelectedServiceType(stream, &v2gSelectedServiceListType->SelectedService.array [v2gSelectedServiceListType_SelectedService_currArrayIndex++]);
				}
				grammarID = 239;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 239:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SelectedService), END_ELEMENT] */
			if (v2gSelectedServiceListType_SelectedService_currArrayIndex < v2gSelectedServiceListType->SelectedService.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gSelectedServiceType(stream, &v2gSelectedServiceListType->SelectedService.array [v2gSelectedServiceListType_SelectedService_currArrayIndex++]);
				}
				grammarID = 239;
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
int encode_v2gSelectedServiceType(bitstream_t* stream, struct v2gSelectedServiceType* v2gSelectedServiceType) {
	int grammarID = 76;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 76:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceID)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, v2gSelectedServiceType->ServiceID);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 77;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 77:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ParameterSetID), END_ELEMENT] */
			if ( v2gSelectedServiceType->ParameterSetID_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeInteger16(stream, v2gSelectedServiceType->ParameterSetID);
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ChargingProfileType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":ProfileEntry{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int encode_v2gChargingProfileType(bitstream_t* stream, struct v2gChargingProfileType* v2gChargingProfileType) {
	int grammarID = 95;
	int done = 0;
	int errn;

	unsigned int v2gChargingProfileType_ProfileEntry_currArrayIndex = 0;

	while(!done) {
		switch(grammarID) {
		case 95:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ProfileEntry)] */
			if (v2gChargingProfileType_ProfileEntry_currArrayIndex < v2gChargingProfileType->ProfileEntry.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gProfileEntryType(stream, &v2gChargingProfileType->ProfileEntry.array [v2gChargingProfileType_ProfileEntry_currArrayIndex++]);
				}
				grammarID = 96;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 96:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ProfileEntry), END_ELEMENT] */
			if (v2gChargingProfileType_ProfileEntry_currArrayIndex < v2gChargingProfileType->ProfileEntry.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gProfileEntryType(stream, &v2gChargingProfileType->ProfileEntry.array [v2gChargingProfileType_ProfileEntry_currArrayIndex++]);
				}
				grammarID = 96;
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
int encode_v2gProfileEntryType(bitstream_t* stream, struct v2gProfileEntryType* v2gProfileEntryType) {
	int grammarID = 111;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 111:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ChargingProfileEntryStart)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger32(stream, v2gProfileEntryType->ChargingProfileEntryStart);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 112;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 112:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ChargingProfileEntryMaxPower)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gProfileEntryType->ChargingProfileEntryMaxPower );
				}
				grammarID = 113;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 113:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ChargingProfileEntryMaxNumberOfPhasesInUse), END_ELEMENT] */
			if ( v2gProfileEntryType->ChargingProfileEntryMaxNumberOfPhasesInUse_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 2, (uint32_t)(v2gProfileEntryType->ChargingProfileEntryMaxNumberOfPhasesInUse - 1));
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ServiceParameterListType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":ParameterSet{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int encode_v2gServiceParameterListType(bitstream_t* stream, struct v2gServiceParameterListType* v2gServiceParameterListType) {
	int grammarID = 161;
	int done = 0;
	int errn;

	unsigned int v2gServiceParameterListType_ParameterSet_currArrayIndex = 0;

	while(!done) {
		switch(grammarID) {
		case 161:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ParameterSet)] */
			if (v2gServiceParameterListType_ParameterSet_currArrayIndex < v2gServiceParameterListType->ParameterSet.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gParameterSetType(stream, &v2gServiceParameterListType->ParameterSet.array [v2gServiceParameterListType_ParameterSet_currArrayIndex++]);
				}
				grammarID = 162;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 162:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ParameterSet), END_ELEMENT] */
			if (v2gServiceParameterListType_ParameterSet_currArrayIndex < v2gServiceParameterListType->ParameterSet.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gParameterSetType(stream, &v2gServiceParameterListType->ParameterSet.array [v2gServiceParameterListType_ParameterSet_currArrayIndex++]);
				}
				grammarID = 162;
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
int encode_v2gParameterSetType(bitstream_t* stream, struct v2gParameterSetType* v2gParameterSetType) {
	int grammarID = 51;
	int done = 0;
	int errn;

	unsigned int v2gParameterSetType_Parameter_currArrayIndex = 0;

	while(!done) {
		switch(grammarID) {
		case 51:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ParameterSetID)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeInteger16(stream, v2gParameterSetType->ParameterSetID);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 52;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 52:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Parameter)] */
			if (v2gParameterSetType_Parameter_currArrayIndex < v2gParameterSetType->Parameter.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gParameterType(stream, &v2gParameterSetType->Parameter.array [v2gParameterSetType_Parameter_currArrayIndex++]);
				}
				grammarID = 53;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 53:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Parameter), END_ELEMENT] */
			if (v2gParameterSetType_Parameter_currArrayIndex < v2gParameterSetType->Parameter.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gParameterType(stream, &v2gParameterSetType->Parameter.array [v2gParameterSetType_Parameter_currArrayIndex++]);
				}
				grammarID = 53;
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
int encode_v2gParameterType(bitstream_t* stream, struct v2gParameterType* v2gParameterType) {
	int grammarID = 274;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 274:
			/* FirstStartTag[ATTRIBUTE[STRING]({urn:iso:15118:2:2013:MsgDataTypes}Name)] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gParameterType->Name.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gParameterType->Name.characters, v2gParameterType->Name.charactersLen);
					}
				}
				grammarID = 275;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 275:
			/* StartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}boolValue), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}byteValue), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}shortValue), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}intValue), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}physicalValue), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}stringValue)] */
			if ( v2gParameterType->boolValue_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gParameterType->boolValue);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 5;
			} else 			if ( v2gParameterType->byteValue_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 1);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[NBIT_UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 8, (uint32_t)(v2gParameterType->byteValue + 128));
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 5;
			} else 			if ( v2gParameterType->shortValue_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeInteger16(stream, v2gParameterType->shortValue);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 5;
			} else 			if ( v2gParameterType->intValue_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 3);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeInteger32(stream, v2gParameterType->intValue);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 5;
			} else 			if ( v2gParameterType->physicalValue_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 4);
				if(errn == 0) {
					errn = encode_v2gPhysicalValueType(stream, &v2gParameterType->physicalValue );
				}
				grammarID = 5;
			} else 			if ( v2gParameterType->stringValue_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 5);
				if(errn == 0) {
					/* First(xsi:type)StartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gParameterType->stringValue.charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gParameterType->stringValue.characters, v2gParameterType->stringValue.charactersLen);
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,PaymentOptionListType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":PaymentOption{1-2})',  derivedBy='RESTRICTION'.  */
int encode_v2gPaymentOptionListType(bitstream_t* stream, struct v2gPaymentOptionListType* v2gPaymentOptionListType) {
	int grammarID = 63;
	int done = 0;
	int errn;

	unsigned int v2gPaymentOptionListType_PaymentOption_currArrayIndex = 0;

	while(!done) {
		switch(grammarID) {
		case 63:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}PaymentOption)] */
			if (v2gPaymentOptionListType_PaymentOption_currArrayIndex < v2gPaymentOptionListType->PaymentOption.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 1, v2gPaymentOptionListType->PaymentOption.array[v2gPaymentOptionListType_PaymentOption_currArrayIndex++]);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 64;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 64:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}PaymentOption), END_ELEMENT] */
			if (v2gPaymentOptionListType_PaymentOption_currArrayIndex < v2gPaymentOptionListType->PaymentOption.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 1, v2gPaymentOptionListType->PaymentOption.array[v2gPaymentOptionListType_PaymentOption_currArrayIndex++]);
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ChargeServiceType',  base type name='ServiceType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":ServiceID,"urn:iso:15118:2:2013:MsgDataTypes":ServiceName{0-1},"urn:iso:15118:2:2013:MsgDataTypes":ServiceCategory,"urn:iso:15118:2:2013:MsgDataTypes":ServiceScope{0-1},"urn:iso:15118:2:2013:MsgDataTypes":FreeService),("urn:iso:15118:2:2013:MsgDataTypes":SupportedEnergyTransferMode))',  derivedBy='EXTENSION'.  */
int encode_v2gChargeServiceType(bitstream_t* stream, struct v2gChargeServiceType* v2gChargeServiceType) {
	int grammarID = 240;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 240:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceID)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, v2gChargeServiceType->ServiceID);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 241;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 241:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceName), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceCategory)] */
			if ( v2gChargeServiceType->ServiceName_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gChargeServiceType->ServiceName.charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gChargeServiceType->ServiceName.characters, v2gChargeServiceType->ServiceName.charactersLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 242;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 2, v2gChargeServiceType->ServiceCategory);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 243;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 242:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceCategory)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 2, v2gChargeServiceType->ServiceCategory);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 243;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 243:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceScope), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FreeService)] */
			if ( v2gChargeServiceType->ServiceScope_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gChargeServiceType->ServiceScope.charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gChargeServiceType->ServiceScope.characters, v2gChargeServiceType->ServiceScope.charactersLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 244;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gChargeServiceType->FreeService);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 245;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 244:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FreeService)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gChargeServiceType->FreeService);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 245;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 245:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SupportedEnergyTransferMode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gSupportedEnergyTransferModeType(stream, &v2gChargeServiceType->SupportedEnergyTransferMode );
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SupportedEnergyTransferModeType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":EnergyTransferMode{1-6})',  derivedBy='RESTRICTION'.  */
int encode_v2gSupportedEnergyTransferModeType(bitstream_t* stream, struct v2gSupportedEnergyTransferModeType* v2gSupportedEnergyTransferModeType) {
	int grammarID = 70;
	int done = 0;
	int errn;

	unsigned int v2gSupportedEnergyTransferModeType_EnergyTransferMode_currArrayIndex = 0;

	while(!done) {
		switch(grammarID) {
		case 70:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EnergyTransferMode)] */
			if (v2gSupportedEnergyTransferModeType_EnergyTransferMode_currArrayIndex < v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 3, v2gSupportedEnergyTransferModeType->EnergyTransferMode.array[v2gSupportedEnergyTransferModeType_EnergyTransferMode_currArrayIndex++]);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 71;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 71:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EnergyTransferMode), END_ELEMENT] */
			if (v2gSupportedEnergyTransferModeType_EnergyTransferMode_currArrayIndex < v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 3, v2gSupportedEnergyTransferModeType->EnergyTransferMode.array[v2gSupportedEnergyTransferModeType_EnergyTransferMode_currArrayIndex++]);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 72;
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
		case 72:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EnergyTransferMode), END_ELEMENT] */
			if (v2gSupportedEnergyTransferModeType_EnergyTransferMode_currArrayIndex < v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 3, v2gSupportedEnergyTransferModeType->EnergyTransferMode.array[v2gSupportedEnergyTransferModeType_EnergyTransferMode_currArrayIndex++]);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 73;
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
		case 73:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EnergyTransferMode), END_ELEMENT] */
			if (v2gSupportedEnergyTransferModeType_EnergyTransferMode_currArrayIndex < v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 3, v2gSupportedEnergyTransferModeType->EnergyTransferMode.array[v2gSupportedEnergyTransferModeType_EnergyTransferMode_currArrayIndex++]);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 74;
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
		case 74:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EnergyTransferMode), END_ELEMENT] */
			if (v2gSupportedEnergyTransferModeType_EnergyTransferMode_currArrayIndex < v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 3, v2gSupportedEnergyTransferModeType->EnergyTransferMode.array[v2gSupportedEnergyTransferModeType_EnergyTransferMode_currArrayIndex++]);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 75;
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
		case 75:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EnergyTransferMode), END_ELEMENT] */
			if (v2gSupportedEnergyTransferModeType_EnergyTransferMode_currArrayIndex < v2gSupportedEnergyTransferModeType->EnergyTransferMode.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 3, v2gSupportedEnergyTransferModeType->EnergyTransferMode.array[v2gSupportedEnergyTransferModeType_EnergyTransferMode_currArrayIndex++]);
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ServiceListType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":Service{1-8})',  derivedBy='RESTRICTION'.  */
int encode_v2gServiceListType(bitstream_t* stream, struct v2gServiceListType* v2gServiceListType) {
	int grammarID = 276;
	int done = 0;
	int errn;

	unsigned int v2gServiceListType_Service_currArrayIndex = 0;

	while(!done) {
		switch(grammarID) {
		case 276:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Service)] */
			if (v2gServiceListType_Service_currArrayIndex < v2gServiceListType->Service.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gServiceType(stream, &v2gServiceListType->Service.array [v2gServiceListType_Service_currArrayIndex++]);
				}
				grammarID = 277;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 277:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Service), END_ELEMENT] */
			if (v2gServiceListType_Service_currArrayIndex < v2gServiceListType->Service.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gServiceType(stream, &v2gServiceListType->Service.array [v2gServiceListType_Service_currArrayIndex++]);
				}
				grammarID = 278;
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
		case 278:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Service), END_ELEMENT] */
			if (v2gServiceListType_Service_currArrayIndex < v2gServiceListType->Service.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gServiceType(stream, &v2gServiceListType->Service.array [v2gServiceListType_Service_currArrayIndex++]);
				}
				grammarID = 279;
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
		case 279:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Service), END_ELEMENT] */
			if (v2gServiceListType_Service_currArrayIndex < v2gServiceListType->Service.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gServiceType(stream, &v2gServiceListType->Service.array [v2gServiceListType_Service_currArrayIndex++]);
				}
				grammarID = 280;
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
		case 280:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Service), END_ELEMENT] */
			if (v2gServiceListType_Service_currArrayIndex < v2gServiceListType->Service.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gServiceType(stream, &v2gServiceListType->Service.array [v2gServiceListType_Service_currArrayIndex++]);
				}
				grammarID = 281;
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
		case 281:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Service), END_ELEMENT] */
			if (v2gServiceListType_Service_currArrayIndex < v2gServiceListType->Service.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gServiceType(stream, &v2gServiceListType->Service.array [v2gServiceListType_Service_currArrayIndex++]);
				}
				grammarID = 282;
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
		case 282:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Service), END_ELEMENT] */
			if (v2gServiceListType_Service_currArrayIndex < v2gServiceListType->Service.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gServiceType(stream, &v2gServiceListType->Service.array [v2gServiceListType_Service_currArrayIndex++]);
				}
				grammarID = 283;
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
		case 283:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}Service), END_ELEMENT] */
			if (v2gServiceListType_Service_currArrayIndex < v2gServiceListType->Service.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gServiceType(stream, &v2gServiceListType->Service.array [v2gServiceListType_Service_currArrayIndex++]);
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,ServiceType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":ServiceID,"urn:iso:15118:2:2013:MsgDataTypes":ServiceName{0-1},"urn:iso:15118:2:2013:MsgDataTypes":ServiceCategory,"urn:iso:15118:2:2013:MsgDataTypes":ServiceScope{0-1},"urn:iso:15118:2:2013:MsgDataTypes":FreeService)',  derivedBy='RESTRICTION'.  */
int encode_v2gServiceType(bitstream_t* stream, struct v2gServiceType* v2gServiceType) {
	int grammarID = 233;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 233:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceID)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, v2gServiceType->ServiceID);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 234;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 234:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceName), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceCategory)] */
			if ( v2gServiceType->ServiceName_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gServiceType->ServiceName.charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gServiceType->ServiceName.characters, v2gServiceType->ServiceName.charactersLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 235;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 2, v2gServiceType->ServiceCategory);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 236;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 235:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceCategory)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 2, v2gServiceType->ServiceCategory);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 236;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 236:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}ServiceScope), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FreeService)] */
			if ( v2gServiceType->ServiceScope_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gServiceType->ServiceScope.charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gServiceType->ServiceScope.characters, v2gServiceType->ServiceScope.charactersLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 237;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gServiceType->FreeService);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 237:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FreeService)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeBoolean(stream, v2gServiceType->FreeService);
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,SignatureType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":SignedInfo,"http://www.w3.org/2000/09/xmldsig#":SignatureValue,"http://www.w3.org/2000/09/xmldsig#":KeyInfo{0-1},"http://www.w3.org/2000/09/xmldsig#":Object{0-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int encode_v2gSignatureType(bitstream_t* stream, struct v2gSignatureType* v2gSignatureType) {
	int grammarID = 295;
	int done = 0;
	int errn;

	unsigned int v2gSignatureType_Object_currArrayIndex = 0;

	while(!done) {
		switch(grammarID) {
		case 295:
			/* FirstStartTag[ATTRIBUTE[STRING](Id), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignedInfo)] */
			if ( v2gSignatureType->Id_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gSignatureType->Id.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gSignatureType->Id.characters, v2gSignatureType->Id.charactersLen);
					}
				}
				grammarID = 296;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gSignedInfoType(stream, &v2gSignatureType->SignedInfo );
				}
				grammarID = 297;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 296:
			/* StartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignedInfo)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gSignedInfoType(stream, &v2gSignatureType->SignedInfo );
				}
				grammarID = 297;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 297:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignatureValue)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gSignatureValueType(stream, &v2gSignatureType->SignatureValue );
				}
				grammarID = 298;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 298:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}KeyInfo), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Object), END_ELEMENT] */
			if ( v2gSignatureType->KeyInfo_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gKeyInfoType(stream, &v2gSignatureType->KeyInfo );
				}
				grammarID = 299;
			} else 			if (v2gSignatureType_Object_currArrayIndex < v2gSignatureType->Object.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gObjectType(stream, &v2gSignatureType->Object.array [v2gSignatureType_Object_currArrayIndex++]);
				}
				grammarID = 299;
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
		case 299:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Object), END_ELEMENT] */
			if (v2gSignatureType_Object_currArrayIndex < v2gSignatureType->Object.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gObjectType(stream, &v2gSignatureType->Object.array [v2gSignatureType_Object_currArrayIndex++]);
				}
				grammarID = 299;
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
int encode_v2gSignedInfoType(bitstream_t* stream, struct v2gSignedInfoType* v2gSignedInfoType) {
	int grammarID = 316;
	int done = 0;
	int errn;

	unsigned int v2gSignedInfoType_Reference_currArrayIndex = 0;

	while(!done) {
		switch(grammarID) {
		case 316:
			/* FirstStartTag[ATTRIBUTE[STRING](Id), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}CanonicalizationMethod)] */
			if ( v2gSignedInfoType->Id_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gSignedInfoType->Id.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gSignedInfoType->Id.characters, v2gSignedInfoType->Id.charactersLen);
					}
				}
				grammarID = 317;
			} else 			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gCanonicalizationMethodType(stream, &v2gSignedInfoType->CanonicalizationMethod );
				}
				grammarID = 318;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 317:
			/* StartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}CanonicalizationMethod)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gCanonicalizationMethodType(stream, &v2gSignedInfoType->CanonicalizationMethod );
				}
				grammarID = 318;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 318:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignatureMethod)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gSignatureMethodType(stream, &v2gSignedInfoType->SignatureMethod );
				}
				grammarID = 319;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 319:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Reference)] */
			if (v2gSignedInfoType_Reference_currArrayIndex < v2gSignedInfoType->Reference.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gReferenceType(stream, &v2gSignedInfoType->Reference.array [v2gSignedInfoType_Reference_currArrayIndex++]);
				}
				grammarID = 50;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 50:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Reference), END_ELEMENT] */
			if (v2gSignedInfoType_Reference_currArrayIndex < v2gSignedInfoType->Reference.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gReferenceType(stream, &v2gSignedInfoType->Reference.array [v2gSignedInfoType_Reference_currArrayIndex++]);
				}
				grammarID = 50;
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
int encode_v2gSignatureValueType(bitstream_t* stream, struct v2gSignatureValueType* v2gSignatureValueType) {
	int grammarID = 249;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 249:
			/* FirstStartTag[ATTRIBUTE[STRING](Id), CHARACTERS[BINARY_BASE64]] */
			if ( v2gSignatureValueType->Id_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gSignatureValueType->Id.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gSignatureValueType->Id.characters, v2gSignatureValueType->Id.charactersLen);
					}
				}
				grammarID = 58;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gSignatureValueType->CONTENT.bytesLen));
					if (errn == 0) {
						errn = encodeBytes(stream, v2gSignatureValueType->CONTENT.bytes, v2gSignatureValueType->CONTENT.bytesLen);
					}
				}
				grammarID = 5;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 58:
			/* StartTag[CHARACTERS[BINARY_BASE64]] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gSignatureValueType->CONTENT.bytesLen));
					if (errn == 0) {
						errn = encodeBytes(stream, v2gSignatureValueType->CONTENT.bytes, v2gSignatureValueType->CONTENT.bytesLen);
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,SignatureMethodType',  base type name='anyType',  content type='MIXED',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":HMACOutputLength{0-1},(WC[##other:"http://www.w3.org/2000/09/xmldsig#"]){0-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int encode_v2gSignatureMethodType(bitstream_t* stream, struct v2gSignatureMethodType* v2gSignatureMethodType) {
	int grammarID = 207;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 207:
			/* FirstStartTag[ATTRIBUTE[STRING](Algorithm)] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gSignatureMethodType->Algorithm.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gSignatureMethodType->Algorithm.characters, v2gSignatureMethodType->Algorithm.charactersLen);
					}
				}
				grammarID = 208;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 208:
			/* StartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}HMACOutputLength), START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			if ( v2gSignatureMethodType->HMACOutputLength_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeInteger64(stream, v2gSignatureMethodType->HMACOutputLength);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 35;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 209;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 35:
			/* Element[START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 209:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}HMACOutputLength), START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			if ( v2gSignatureMethodType->HMACOutputLength_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 3, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[INTEGER]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeInteger64(stream, v2gSignatureMethodType->HMACOutputLength);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 35;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 3, 2);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 209;
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

/* Complex type name='http://www.w3.org/2000/09/xmldsig#,SignaturePropertiesType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("http://www.w3.org/2000/09/xmldsig#":SignatureProperty{1-UNBOUNDED})',  derivedBy='RESTRICTION'.  */
int encode_v2gSignaturePropertiesType(bitstream_t* stream, struct v2gSignaturePropertiesType* v2gSignaturePropertiesType) {
	int grammarID = 250;
	int done = 0;
	int errn;

	unsigned int v2gSignaturePropertiesType_SignatureProperty_currArrayIndex = 0;

	while(!done) {
		switch(grammarID) {
		case 250:
			/* FirstStartTag[ATTRIBUTE[STRING](Id), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignatureProperty)] */
			if ( v2gSignaturePropertiesType->Id_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gSignaturePropertiesType->Id.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gSignaturePropertiesType->Id.characters, v2gSignaturePropertiesType->Id.charactersLen);
					}
				}
				grammarID = 251;
			} else 			if (v2gSignaturePropertiesType_SignatureProperty_currArrayIndex < v2gSignaturePropertiesType->SignatureProperty.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gSignaturePropertyType(stream, &v2gSignaturePropertiesType->SignatureProperty.array [v2gSignaturePropertiesType_SignatureProperty_currArrayIndex++]);
				}
				grammarID = 252;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 251:
			/* StartTag[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignatureProperty)] */
			if (v2gSignaturePropertiesType_SignatureProperty_currArrayIndex < v2gSignaturePropertiesType->SignatureProperty.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gSignaturePropertyType(stream, &v2gSignaturePropertiesType->SignatureProperty.array [v2gSignaturePropertiesType_SignatureProperty_currArrayIndex++]);
				}
				grammarID = 252;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 252:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}SignatureProperty), END_ELEMENT] */
			if (v2gSignaturePropertiesType_SignatureProperty_currArrayIndex < v2gSignaturePropertiesType->SignatureProperty.arrayLen ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gSignaturePropertyType(stream, &v2gSignaturePropertiesType->SignatureProperty.array [v2gSignaturePropertiesType_SignatureProperty_currArrayIndex++]);
				}
				grammarID = 252;
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
int encode_v2gSignaturePropertyType(bitstream_t* stream, struct v2gSignaturePropertyType* v2gSignaturePropertyType) {
	int grammarID = 32;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 32:
			/* FirstStartTag[ATTRIBUTE[STRING](Id), ATTRIBUTE[STRING](Target)] */
			if ( v2gSignaturePropertyType->Id_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gSignaturePropertyType->Id.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gSignaturePropertyType->Id.characters, v2gSignaturePropertyType->Id.charactersLen);
					}
				}
				grammarID = 33;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gSignaturePropertyType->Target.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gSignaturePropertyType->Target.characters, v2gSignaturePropertyType->Target.charactersLen);
					}
				}
				grammarID = 34;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 33:
			/* StartTag[ATTRIBUTE[STRING](Target)] */
			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* encode string as string table miss (+2 len)*/
					errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gSignaturePropertyType->Target.charactersLen + 2));
					if (errn == 0) {
						errn = encodeCharacters(stream, v2gSignaturePropertyType->Target.characters, v2gSignaturePropertyType->Target.charactersLen);
					}
				}
				grammarID = 34;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 34:
			/* StartTag[START_ELEMENT_GENERIC, CHARACTERS_GENERIC[STRING]] */
			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 36;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 35:
			/* Element[START_ELEMENT_GENERIC, END_ELEMENT, CHARACTERS_GENERIC[STRING]] */
			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					done = 1;
				}
				grammarID = 1;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 36:
			/* Element[START_ELEMENT_GENERIC, CHARACTERS_GENERIC[STRING]] */
			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 35;
			} else 			if (1==0) {
				errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
				grammarID = 36;
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

/* Complex type name='urn:iso:15118:2:2013:MsgDef,#AnonType_V2G_Message',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDef":Header,"urn:iso:15118:2:2013:MsgDef":Body)',  derivedBy='RESTRICTION'.  */
int encode_v2gAnonType_V2G_Message(bitstream_t* stream, struct v2gAnonType_V2G_Message* v2gAnonType_V2G_Message) {
	int grammarID = 200;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 200:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDef}Header)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gMessageHeaderType(stream, &v2gAnonType_V2G_Message->Header );
				}
				grammarID = 201;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 201:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDef}Body)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					errn = encode_v2gBodyType(stream, &v2gAnonType_V2G_Message->Body );
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

/* Complex type name='urn:iso:15118:2:2013:MsgHeader,MessageHeaderType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgHeader":SessionID,"urn:iso:15118:2:2013:MsgHeader":Notification{0-1},"http://www.w3.org/2000/09/xmldsig#":Signature{0-1})',  derivedBy='RESTRICTION'.  */
int encode_v2gMessageHeaderType(bitstream_t* stream, struct v2gMessageHeaderType* v2gMessageHeaderType) {
	int grammarID = 118;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 118:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgHeader}SessionID)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[BINARY_HEX]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gMessageHeaderType->SessionID.bytesLen));
						if (errn == 0) {
							errn = encodeBytes(stream, v2gMessageHeaderType->SessionID.bytes, v2gMessageHeaderType->SessionID.bytesLen);
						}
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 119;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 119:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgHeader}Notification), START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Signature), END_ELEMENT] */
			if ( v2gMessageHeaderType->Notification_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gNotificationType(stream, &v2gMessageHeaderType->Notification );
				}
				grammarID = 120;
			} else 			if ( v2gMessageHeaderType->Signature_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 1);
				if(errn == 0) {
					errn = encode_v2gSignatureType(stream, &v2gMessageHeaderType->Signature );
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
		case 120:
			/* Element[START_ELEMENT({http://www.w3.org/2000/09/xmldsig#}Signature), END_ELEMENT] */
			if ( v2gMessageHeaderType->Signature_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					errn = encode_v2gSignatureType(stream, &v2gMessageHeaderType->Signature );
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,NotificationType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":FaultCode,"urn:iso:15118:2:2013:MsgDataTypes":FaultMsg{0-1})',  derivedBy='RESTRICTION'.  */
int encode_v2gNotificationType(bitstream_t* stream, struct v2gNotificationType* v2gNotificationType) {
	int grammarID = 42;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 42:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FaultCode)] */
			if ( 1 == 1 ) {
				errn = encodeNBitUnsignedInteger(stream, 1, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						errn = encodeNBitUnsignedInteger(stream, 2, v2gNotificationType->FaultCode);
						/* valid EE */
						errn = encodeNBitUnsignedInteger(stream, 1, 0);
					}
				}
				grammarID = 43;
			} else {
				errn = EXI_ERROR_UNKOWN_EVENT;
			}
			break;
		case 43:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}FaultMsg), END_ELEMENT] */
			if ( v2gNotificationType->FaultMsg_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 2, 0);
				if(errn == 0) {
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = encodeNBitUnsignedInteger(stream, 1, 0);
					if(errn == 0) {
						/* encode string as string table miss (+2 len)*/
						errn = encodeUnsignedInteger16(stream, (uint16_t)(v2gNotificationType->FaultMsg.charactersLen + 2));
						if (errn == 0) {
							errn = encodeCharacters(stream, v2gNotificationType->FaultMsg.characters, v2gNotificationType->FaultMsg.charactersLen);
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,BodyType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":BodyElement{0-1})',  derivedBy='RESTRICTION'.  */
int encode_v2gBodyType(bitstream_t* stream, struct v2gBodyType* v2gBodyType) {
	int grammarID = 104;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 104:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}AuthorizationReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}AuthorizationRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}BodyElement), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CableCheckReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CableCheckRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CertificateInstallationReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CertificateInstallationRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CertificateUpdateReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CertificateUpdateRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargeParameterDiscoveryReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargeParameterDiscoveryRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingStatusReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargingStatusRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CurrentDemandReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}CurrentDemandRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}MeteringReceiptReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}MeteringReceiptRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PaymentDetailsReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PaymentDetailsRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PaymentServiceSelectionReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PaymentServiceSelectionRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PowerDeliveryReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PowerDeliveryRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PreChargeReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PreChargeRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceDetailReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceDetailRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceDiscoveryReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceDiscoveryRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionSetupReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionSetupRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionStopReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SessionStopRes), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}WeldingDetectionReq), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}WeldingDetectionRes), END_ELEMENT] */
			if ( v2gBodyType->AuthorizationRes_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 6, 1);
				if(errn == 0) {
					errn = encode_v2gAuthorizationResType(stream, &v2gBodyType->AuthorizationRes );
				}
				grammarID = 5;
			} else 			if ( v2gBodyType->BodyElement_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 6, 2);
				if(errn == 0) {
					errn = encode_v2gBodyBaseType(stream, &v2gBodyType->BodyElement );
				}
				grammarID = 5;
			} else 			if ( v2gBodyType->CableCheckRes_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 6, 4);
				if(errn == 0) {
					errn = encode_v2gCableCheckResType(stream, &v2gBodyType->CableCheckRes );
				}
				grammarID = 5;
			} else 			if ( v2gBodyType->CertificateInstallationRes_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 6, 6);
				if(errn == 0) {
					errn = encode_v2gCertificateInstallationResType(stream, &v2gBodyType->CertificateInstallationRes );
				}
				grammarID = 5;
			} else 			if ( v2gBodyType->CertificateUpdateRes_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 6, 8);
				if(errn == 0) {
					errn = encode_v2gCertificateUpdateResType(stream, &v2gBodyType->CertificateUpdateRes );
				}
				grammarID = 5;
			} else 			if ( v2gBodyType->ChargeParameterDiscoveryRes_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 6, 10);
				if(errn == 0) {
					errn = encode_v2gChargeParameterDiscoveryResType(stream, &v2gBodyType->ChargeParameterDiscoveryRes );
				}
				grammarID = 5;
			} else 			if ( v2gBodyType->ChargingStatusRes_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 6, 12);
				if(errn == 0) {
					errn = encode_v2gChargingStatusResType(stream, &v2gBodyType->ChargingStatusRes );
				}
				grammarID = 5;
			} else 			if ( v2gBodyType->CurrentDemandRes_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 6, 14);
				if(errn == 0) {
					errn = encode_v2gCurrentDemandResType(stream, &v2gBodyType->CurrentDemandRes );
				}
				grammarID = 5;
			} else 			if ( v2gBodyType->MeteringReceiptRes_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 6, 16);
				if(errn == 0) {
					errn = encode_v2gMeteringReceiptResType(stream, &v2gBodyType->MeteringReceiptRes );
				}
				grammarID = 5;
			} else 			if ( v2gBodyType->PaymentDetailsRes_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 6, 18);
				if(errn == 0) {
					errn = encode_v2gPaymentDetailsResType(stream, &v2gBodyType->PaymentDetailsRes );
				}
				grammarID = 5;
			} else 			if ( v2gBodyType->PaymentServiceSelectionRes_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 6, 20);
				if(errn == 0) {
					errn = encode_v2gPaymentServiceSelectionResType(stream, &v2gBodyType->PaymentServiceSelectionRes );
				}
				grammarID = 5;
			} else 			if ( v2gBodyType->PowerDeliveryRes_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 6, 22);
				if(errn == 0) {
					errn = encode_v2gPowerDeliveryResType(stream, &v2gBodyType->PowerDeliveryRes );
				}
				grammarID = 5;
			} else 			if ( v2gBodyType->PreChargeRes_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 6, 24);
				if(errn == 0) {
					errn = encode_v2gPreChargeResType(stream, &v2gBodyType->PreChargeRes );
				}
				grammarID = 5;
			} else 			if ( v2gBodyType->ServiceDetailRes_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 6, 26);
				if(errn == 0) {
					errn = encode_v2gServiceDetailResType(stream, &v2gBodyType->ServiceDetailRes );
				}
				grammarID = 5;
			} else 			if ( v2gBodyType->ServiceDiscoveryRes_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 6, 28);
				if(errn == 0) {
					errn = encode_v2gServiceDiscoveryResType(stream, &v2gBodyType->ServiceDiscoveryRes );
				}
				grammarID = 5;
			} else 			if ( v2gBodyType->SessionSetupRes_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 6, 30);
				if(errn == 0) {
					errn = encode_v2gSessionSetupResType(stream, &v2gBodyType->SessionSetupRes );
				}
				grammarID = 5;
			} else 			if ( v2gBodyType->SessionStopRes_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 6, 32);
				if(errn == 0) {
					errn = encode_v2gSessionStopResType(stream, &v2gBodyType->SessionStopRes );
				}
				grammarID = 5;
			} else 			if ( v2gBodyType->WeldingDetectionRes_isUsed == 1u ) {
				errn = encodeNBitUnsignedInteger(stream, 6, 34);
				if(errn == 0) {
					errn = encode_v2gWeldingDetectionResType(stream, &v2gBodyType->WeldingDetectionRes );
				}
				grammarID = 5;
			} else 			if (1==1) {
				errn = encodeNBitUnsignedInteger(stream, 6, 35);
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
