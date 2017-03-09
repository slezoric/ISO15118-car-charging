/*
 * v2gEXIDatatypesDecoderRes.c
 *
 *  Created on: 11.02.2016
 *      Author: melanie
 */

/*Responses-EVSE*/
# include "ErrorCodes.h"
# include "DecoderChannel.h"
# include <stdio.h>
# include "v2gEXIDatatypesDecoder.h"
# include "DecoderChannel.h"

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,AC_EVSEChargeParameterType',  base type name='EVSEChargeParameterType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":AC_EVSEStatus,"urn:iso:15118:2:2013:MsgDataTypes":EVSENominalVoltage,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMaxCurrent)',  derivedBy='EXTENSION'.  */
int decode_v2gAC_EVSEChargeParameterType(bitstream_t* stream, struct v2gAC_EVSEChargeParameterType* v2gAC_EVSEChargeParameterType, uint32_t eventCode) {
	int grammarID = 122;
	int done = 0;
	int errn;

	while(!done) {
		switch(grammarID) {
		case 122:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}AC_EVSEStatus)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gAC_EVSEStatusType(stream, &v2gAC_EVSEChargeParameterType->AC_EVSEStatus, eventCode);
					grammarID = 123;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 123:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSENominalVoltage)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gAC_EVSEChargeParameterType->EVSENominalVoltage, eventCode);
					grammarID = 124;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 124:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEMaxCurrent)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gAC_EVSEChargeParameterType->EVSEMaxCurrent, eventCode);
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,AC_EVSEStatusType',  base type name='EVSEStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification),("urn:iso:15118:2:2013:MsgDataTypes":RCD))',  derivedBy='EXTENSION'.  */
int decode_v2gAC_EVSEStatusType(bitstream_t* stream, struct v2gAC_EVSEStatusType* v2gAC_EVSEStatusType, uint32_t eventCode) {
	int grammarID = 20;
	int done = 0;
	int errn;
	uint32_t uint32;

	while(!done) {
		switch(grammarID) {
		case 20:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}NotificationMaxDelay)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gAC_EVSEStatusType->NotificationMaxDelay);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}NotificationMaxDelay) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 21;
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
		case 21:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSENotification)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 2, &uint32);
							v2gAC_EVSEStatusType->EVSENotification = (v2gEVSENotificationType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSENotification) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 22;
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
		case 22:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}RCD)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gAC_EVSEStatusType->RCD);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}RCD) ? */
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,AuthorizationResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":EVSEProcessing)',  derivedBy='EXTENSION'.  */
int decode_v2gAuthorizationResType(bitstream_t* stream, struct v2gAuthorizationResType* v2gAuthorizationResType, uint32_t eventCode) {
	int grammarID = 230;
	int done = 0;
	int errn;
	uint32_t uint32;

	while(!done) {
		switch(grammarID) {
		case 230:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 5, &uint32);
							v2gAuthorizationResType->ResponseCode = (v2gresponseCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 231;
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
		case 231:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEProcessing)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 2, &uint32);
							v2gAuthorizationResType->EVSEProcessing = (v2gEVSEProcessingType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEProcessing) ? */
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,CableCheckResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":DC_EVSEStatus,"urn:iso:15118:2:2013:MsgBody":EVSEProcessing)',  derivedBy='EXTENSION'.  */
int decode_v2gCableCheckResType(bitstream_t* stream, struct v2gCableCheckResType* v2gCableCheckResType, uint32_t eventCode) {
	int grammarID = 300;
	int done = 0;
	int errn;
	uint32_t uint32;

	while(!done) {
		switch(grammarID) {
		case 300:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 5, &uint32);
							v2gCableCheckResType->ResponseCode = (v2gresponseCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 301;
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
		case 301:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}DC_EVSEStatus)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gDC_EVSEStatusType(stream, &v2gCableCheckResType->DC_EVSEStatus, eventCode);
					grammarID = 231;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 231:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEProcessing)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 2, &uint32);
							v2gCableCheckResType->EVSEProcessing = (v2gEVSEProcessingType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEProcessing) ? */
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVSEStatusType',  base type name='EVSEStatusType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification),("urn:iso:15118:2:2013:MsgDataTypes":EVSEIsolationStatus{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVSEStatusCode))',  derivedBy='EXTENSION'.  */
int decode_v2gDC_EVSEStatusType(bitstream_t* stream, struct v2gDC_EVSEStatusType* v2gDC_EVSEStatusType, uint32_t eventCode) {
	int grammarID = 291;
	int done = 0;
	int errn;
	uint32_t uint32;

	v2gDC_EVSEStatusType->EVSEIsolationStatus_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 291:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}NotificationMaxDelay)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gDC_EVSEStatusType->NotificationMaxDelay);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}NotificationMaxDelay) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 292;
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
		case 292:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSENotification)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 2, &uint32);
							v2gDC_EVSEStatusType->EVSENotification = (v2gEVSENotificationType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSENotification) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 293;
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
		case 293:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEIsolationStatus), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEStatusCode)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 3, &uint32);
							v2gDC_EVSEStatusType->EVSEIsolationStatus = (v2gisolationLevelType) uint32;
							v2gDC_EVSEStatusType->EVSEIsolationStatus_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEIsolationStatus) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 294;
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
							errn = decodeNBitUnsignedInteger(stream, 4, &uint32);
							v2gDC_EVSEStatusType->EVSEStatusCode = (v2gDC_EVSEStatusCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEStatusCode) ? */
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
		case 294:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEStatusCode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 4, &uint32);
							v2gDC_EVSEStatusType->EVSEStatusCode = (v2gDC_EVSEStatusCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEStatusCode) ? */
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,CertificateInstallationResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":SAProvisioningCertificateChain,"urn:iso:15118:2:2013:MsgBody":ContractSignatureCertChain,"urn:iso:15118:2:2013:MsgBody":ContractSignatureEncryptedPrivateKey,"urn:iso:15118:2:2013:MsgBody":DHpublickey,"urn:iso:15118:2:2013:MsgBody":eMAID)',  derivedBy='EXTENSION'.  */
int decode_v2gCertificateInstallationResType(bitstream_t* stream, struct v2gCertificateInstallationResType* v2gCertificateInstallationResType, uint32_t eventCode) {
	int grammarID = 151;
	int done = 0;
	int errn;
	uint32_t uint32;

	while(!done) {
		switch(grammarID) {
		case 151:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 5, &uint32);
							v2gCertificateInstallationResType->ResponseCode = (v2gresponseCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 152;
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
		case 152:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SAProvisioningCertificateChain)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gCertificateChainType(stream, &v2gCertificateInstallationResType->SAProvisioningCertificateChain, eventCode);
					grammarID = 153;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 153:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ContractSignatureCertChain)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gCertificateChainType(stream, &v2gCertificateInstallationResType->ContractSignatureCertChain, eventCode);
					grammarID = 154;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 154:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ContractSignatureEncryptedPrivateKey)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gContractSignatureEncryptedPrivateKeyType(stream, &v2gCertificateInstallationResType->ContractSignatureEncryptedPrivateKey, eventCode);
					grammarID = 155;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 155:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}DHpublickey)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gDiffieHellmanPublickeyType(stream, &v2gCertificateInstallationResType->DHpublickey, eventCode);
					grammarID = 156;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 156:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}eMAID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gEMAIDType(stream, &v2gCertificateInstallationResType->eMAID, eventCode);
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,CertificateUpdateResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":SAProvisioningCertificateChain,"urn:iso:15118:2:2013:MsgBody":ContractSignatureCertChain,"urn:iso:15118:2:2013:MsgBody":ContractSignatureEncryptedPrivateKey,"urn:iso:15118:2:2013:MsgBody":DHpublickey,"urn:iso:15118:2:2013:MsgBody":eMAID,"urn:iso:15118:2:2013:MsgBody":RetryCounter{0-1})',  derivedBy='EXTENSION'.  */
int decode_v2gCertificateUpdateResType(bitstream_t* stream, struct v2gCertificateUpdateResType* v2gCertificateUpdateResType, uint32_t eventCode) {
	int grammarID = 144;
	int done = 0;
	int errn;
	uint32_t uint32;

	v2gCertificateUpdateResType->RetryCounter_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 144:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 5, &uint32);
							v2gCertificateUpdateResType->ResponseCode = (v2gresponseCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 145;
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
		case 145:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SAProvisioningCertificateChain)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gCertificateChainType(stream, &v2gCertificateUpdateResType->SAProvisioningCertificateChain, eventCode);
					grammarID = 146;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 146:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ContractSignatureCertChain)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gCertificateChainType(stream, &v2gCertificateUpdateResType->ContractSignatureCertChain, eventCode);
					grammarID = 147;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 147:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ContractSignatureEncryptedPrivateKey)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gContractSignatureEncryptedPrivateKeyType(stream, &v2gCertificateUpdateResType->ContractSignatureEncryptedPrivateKey, eventCode);
					grammarID = 148;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 148:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}DHpublickey)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gDiffieHellmanPublickeyType(stream, &v2gCertificateUpdateResType->DHpublickey, eventCode);
					grammarID = 149;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 149:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}eMAID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gEMAIDType(stream, &v2gCertificateUpdateResType->eMAID, eventCode);
					grammarID = 150;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 150:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}RetryCounter), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeInteger16(stream, &v2gCertificateUpdateResType->RetryCounter);
							v2gCertificateUpdateResType->RetryCounter_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}RetryCounter) ? */
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,ChargeParameterDiscoveryResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":EVSEProcessing,"urn:iso:15118:2:2013:MsgDataTypes":SASchedules{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVSEChargeParameter)',  derivedBy='EXTENSION'.  */
int decode_v2gChargeParameterDiscoveryResType(bitstream_t* stream, struct v2gChargeParameterDiscoveryResType* v2gChargeParameterDiscoveryResType, uint32_t eventCode) {
	int grammarID = 307;
	int done = 0;
	int errn;
	uint32_t uint32;

	init_v2gChargeParameterDiscoveryResType(v2gChargeParameterDiscoveryResType);

	while(!done) {
		switch(grammarID) {
		case 307:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 5, &uint32);
							v2gChargeParameterDiscoveryResType->ResponseCode = (v2gresponseCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 308;
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
		case 308:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEProcessing)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 2, &uint32);
							v2gChargeParameterDiscoveryResType->EVSEProcessing = (v2gEVSEProcessingType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEProcessing) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 309;
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
		case 309:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SAScheduleList), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SASchedules), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}AC_EVSEChargeParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVSEChargeParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEChargeParameter)] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gSAScheduleListType(stream, &v2gChargeParameterDiscoveryResType->SAScheduleList, eventCode);
					v2gChargeParameterDiscoveryResType->SAScheduleList_isUsed = 1u;
					grammarID = 310;
					break;
				case 1:
					errn = decode_v2gSASchedulesType(stream, &v2gChargeParameterDiscoveryResType->SASchedules, eventCode);
					v2gChargeParameterDiscoveryResType->SASchedules_isUsed = 1u;
					grammarID = 310;
					break;
				case 2:
					errn = decode_v2gAC_EVSEChargeParameterType(stream, &v2gChargeParameterDiscoveryResType->AC_EVSEChargeParameter, eventCode);
					v2gChargeParameterDiscoveryResType->AC_EVSEChargeParameter_isUsed = 1u;
					grammarID = 5;
					break;
				case 3:
					errn = decode_v2gDC_EVSEChargeParameterType(stream, &v2gChargeParameterDiscoveryResType->DC_EVSEChargeParameter, eventCode);
					v2gChargeParameterDiscoveryResType->DC_EVSEChargeParameter_isUsed = 1u;
					grammarID = 5;
					break;
				case 4:
					errn = decode_v2gEVSEChargeParameterType(stream, &v2gChargeParameterDiscoveryResType->EVSEChargeParameter, eventCode);
					v2gChargeParameterDiscoveryResType->EVSEChargeParameter_isUsed = 1u;
					grammarID = 5;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 310:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}AC_EVSEChargeParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVSEChargeParameter), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEChargeParameter)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gAC_EVSEChargeParameterType(stream, &v2gChargeParameterDiscoveryResType->AC_EVSEChargeParameter, eventCode);
					v2gChargeParameterDiscoveryResType->AC_EVSEChargeParameter_isUsed = 1u;
					grammarID = 5;
					break;
				case 1:
					errn = decode_v2gDC_EVSEChargeParameterType(stream, &v2gChargeParameterDiscoveryResType->DC_EVSEChargeParameter, eventCode);
					v2gChargeParameterDiscoveryResType->DC_EVSEChargeParameter_isUsed = 1u;
					grammarID = 5;
					break;
				case 2:
					errn = decode_v2gEVSEChargeParameterType(stream, &v2gChargeParameterDiscoveryResType->EVSEChargeParameter, eventCode);
					v2gChargeParameterDiscoveryResType->EVSEChargeParameter_isUsed = 1u;
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,SAScheduleListType',  base type name='SASchedulesType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":SAScheduleTuple{1-3})',  derivedBy='EXTENSION'.  */
int decode_v2gSAScheduleListType(bitstream_t* stream, struct v2gSAScheduleListType* v2gSAScheduleListType, uint32_t eventCode) {
	int grammarID = 264;
	int done = 0;
	int errn;

	v2gSAScheduleListType->SAScheduleTuple.arrayLen = 0u;
	while(!done) {
		switch(grammarID) {
		case 264:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SAScheduleTuple)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSAScheduleListType->SAScheduleTuple.arrayLen < v2gSAScheduleListType_SAScheduleTuple_ARRAY_SIZE) {
						errn = decode_v2gSAScheduleTupleType(stream, &v2gSAScheduleListType->SAScheduleTuple.array[v2gSAScheduleListType->SAScheduleTuple.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 265;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 265:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SAScheduleTuple), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSAScheduleListType->SAScheduleTuple.arrayLen < v2gSAScheduleListType_SAScheduleTuple_ARRAY_SIZE) {
						errn = decode_v2gSAScheduleTupleType(stream, &v2gSAScheduleListType->SAScheduleTuple.array[v2gSAScheduleListType->SAScheduleTuple.arrayLen++], eventCode);
					} else {
						errn = EXI_ERROR_OUT_OF_BOUNDS;
					}
					grammarID = 266;
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
		case 266:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}SAScheduleTuple), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					if (v2gSAScheduleListType->SAScheduleTuple.arrayLen < v2gSAScheduleListType_SAScheduleTuple_ARRAY_SIZE) {
						errn = decode_v2gSAScheduleTupleType(stream, &v2gSAScheduleListType->SAScheduleTuple.array[v2gSAScheduleListType->SAScheduleTuple.arrayLen++], eventCode);
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,DC_EVSEChargeParameterType',  base type name='EVSEChargeParameterType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":DC_EVSEStatus,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMaximumCurrentLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMaximumPowerLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMaximumVoltageLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMinimumCurrentLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVSEMinimumVoltageLimit,"urn:iso:15118:2:2013:MsgDataTypes":EVSECurrentRegulationTolerance{0-1},"urn:iso:15118:2:2013:MsgDataTypes":EVSEPeakCurrentRipple,"urn:iso:15118:2:2013:MsgDataTypes":EVSEEnergyToBeDelivered{0-1})',  derivedBy='EXTENSION'.  */
int decode_v2gDC_EVSEChargeParameterType(bitstream_t* stream, struct v2gDC_EVSEChargeParameterType* v2gDC_EVSEChargeParameterType, uint32_t eventCode) {
	int grammarID = 255;
	int done = 0;
	int errn;

	v2gDC_EVSEChargeParameterType->EVSECurrentRegulationTolerance_isUsed = 0u;
	v2gDC_EVSEChargeParameterType->EVSEEnergyToBeDelivered_isUsed = 0u;
	while(!done) {
		switch(grammarID) {
		case 255:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVSEStatus)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gDC_EVSEStatusType(stream, &v2gDC_EVSEChargeParameterType->DC_EVSEStatus, eventCode);
					grammarID = 256;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 256:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEMaximumCurrentLimit)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gDC_EVSEChargeParameterType->EVSEMaximumCurrentLimit, eventCode);
					grammarID = 257;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 257:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEMaximumPowerLimit)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gDC_EVSEChargeParameterType->EVSEMaximumPowerLimit, eventCode);
					grammarID = 258;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 258:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEMaximumVoltageLimit)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gDC_EVSEChargeParameterType->EVSEMaximumVoltageLimit, eventCode);
					grammarID = 259;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 259:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEMinimumCurrentLimit)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gDC_EVSEChargeParameterType->EVSEMinimumCurrentLimit, eventCode);
					grammarID = 260;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 260:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEMinimumVoltageLimit)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gDC_EVSEChargeParameterType->EVSEMinimumVoltageLimit, eventCode);
					grammarID = 261;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 261:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSECurrentRegulationTolerance), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEPeakCurrentRipple)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gDC_EVSEChargeParameterType->EVSECurrentRegulationTolerance, eventCode);
					v2gDC_EVSEChargeParameterType->EVSECurrentRegulationTolerance_isUsed = 1u;
					grammarID = 262;
					break;
				case 1:
					errn = decode_v2gPhysicalValueType(stream, &v2gDC_EVSEChargeParameterType->EVSEPeakCurrentRipple, eventCode);
					grammarID = 263;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 262:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEPeakCurrentRipple)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gDC_EVSEChargeParameterType->EVSEPeakCurrentRipple, eventCode);
					grammarID = 263;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 263:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEEnergyToBeDelivered), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gDC_EVSEChargeParameterType->EVSEEnergyToBeDelivered, eventCode);
					v2gDC_EVSEChargeParameterType->EVSEEnergyToBeDelivered_isUsed = 1u;
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,ChargingStatusResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":EVSEID,"urn:iso:15118:2:2013:MsgBody":SAScheduleTupleID,"urn:iso:15118:2:2013:MsgBody":EVSEMaxCurrent{0-1},"urn:iso:15118:2:2013:MsgBody":MeterInfo{0-1},"urn:iso:15118:2:2013:MsgBody":ReceiptRequired{0-1},"urn:iso:15118:2:2013:MsgBody":AC_EVSEStatus)',  derivedBy='EXTENSION'.  */
int decode_v2gChargingStatusResType(bitstream_t* stream, struct v2gChargingStatusResType* v2gChargingStatusResType, uint32_t eventCode) {
	int grammarID = 185;
	int done = 0;
	int errn;
	uint32_t uint32;

	init_v2gChargingStatusResType(v2gChargingStatusResType);

	while(!done) {
		switch(grammarID) {
		case 185:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 5, &uint32);
							v2gChargingStatusResType->ResponseCode = (v2gresponseCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 186;
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
		case 186:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gChargingStatusResType->EVSEID.charactersLen);
							if (errn == 0) {
								errn =  (v2gChargingStatusResType->EVSEID.charactersLen - 2) <= v2gChargingStatusResType_EVSEID_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
							}
							if (errn == 0) {
								if (v2gChargingStatusResType->EVSEID.charactersLen >= 2) {
									v2gChargingStatusResType->EVSEID.charactersLen = (uint16_t)(v2gChargingStatusResType->EVSEID.charactersLen - 2); /* string table miss */
									errn = decodeCharacters(stream, v2gChargingStatusResType->EVSEID.charactersLen, v2gChargingStatusResType->EVSEID.characters);
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
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 187;
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
		case 187:
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
							v2gChargingStatusResType->SAScheduleTupleID = (uint8_t)(uint32 + 1);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SAScheduleTupleID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 188;
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
		case 188:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEMaxCurrent), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}MeterInfo), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ReceiptRequired), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}AC_EVSEStatus)] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gChargingStatusResType->EVSEMaxCurrent, eventCode);
					v2gChargingStatusResType->EVSEMaxCurrent_isUsed = 1u;
					grammarID = 189;
					break;
				case 1:
					errn = decode_v2gMeterInfoType(stream, &v2gChargingStatusResType->MeterInfo, eventCode);
					v2gChargingStatusResType->MeterInfo_isUsed = 1u;
					grammarID = 190;
					break;
				case 2:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gChargingStatusResType->ReceiptRequired);
							v2gChargingStatusResType->ReceiptRequired_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ReceiptRequired) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 191;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 3:
					errn = decode_v2gAC_EVSEStatusType(stream, &v2gChargingStatusResType->AC_EVSEStatus, eventCode);
					grammarID = 5;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 189:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}MeterInfo), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ReceiptRequired), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}AC_EVSEStatus)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gMeterInfoType(stream, &v2gChargingStatusResType->MeterInfo, eventCode);
					v2gChargingStatusResType->MeterInfo_isUsed = 1u;
					grammarID = 190;
					break;
				case 1:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gChargingStatusResType->ReceiptRequired);
							v2gChargingStatusResType->ReceiptRequired_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ReceiptRequired) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 191;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 2:
					errn = decode_v2gAC_EVSEStatusType(stream, &v2gChargingStatusResType->AC_EVSEStatus, eventCode);
					grammarID = 5;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 190:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ReceiptRequired), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}AC_EVSEStatus)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gChargingStatusResType->ReceiptRequired);
							v2gChargingStatusResType->ReceiptRequired_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ReceiptRequired) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 191;
						} else {
							errn = EXI_DEVIANT_SUPPORT_NOT_DEPLOYED; /* or also typecast and nillable */
						}
					}
					break;
				case 1:
					errn = decode_v2gAC_EVSEStatusType(stream, &v2gChargingStatusResType->AC_EVSEStatus, eventCode);
					grammarID = 5;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 191:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}AC_EVSEStatus)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gAC_EVSEStatusType(stream, &v2gChargingStatusResType->AC_EVSEStatus, eventCode);
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,CurrentDemandResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":DC_EVSEStatus,"urn:iso:15118:2:2013:MsgBody":EVSEPresentVoltage,"urn:iso:15118:2:2013:MsgBody":EVSEPresentCurrent,"urn:iso:15118:2:2013:MsgBody":EVSECurrentLimitAchieved,"urn:iso:15118:2:2013:MsgBody":EVSEVoltageLimitAchieved,"urn:iso:15118:2:2013:MsgBody":EVSEPowerLimitAchieved,"urn:iso:15118:2:2013:MsgBody":EVSEMaximumVoltageLimit{0-1},"urn:iso:15118:2:2013:MsgBody":EVSEMaximumCurrentLimit{0-1},"urn:iso:15118:2:2013:MsgBody":EVSEMaximumPowerLimit{0-1},"urn:iso:15118:2:2013:MsgBody":EVSEID,"urn:iso:15118:2:2013:MsgBody":SAScheduleTupleID,"urn:iso:15118:2:2013:MsgBody":MeterInfo{0-1},"urn:iso:15118:2:2013:MsgBody":ReceiptRequired{0-1})',  derivedBy='EXTENSION'.  */
int decode_v2gCurrentDemandResType(bitstream_t* stream, struct v2gCurrentDemandResType* v2gCurrentDemandResType, uint32_t eventCode) {
	int grammarID = 6;
	int done = 0;
	int errn;
	uint32_t uint32;

	init_v2gCurrentDemandResType(v2gCurrentDemandResType);

	while(!done) {
		switch(grammarID) {
		case 6:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 5, &uint32);
							v2gCurrentDemandResType->ResponseCode = (v2gresponseCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 7;
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
		case 7:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}DC_EVSEStatus)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gDC_EVSEStatusType(stream, &v2gCurrentDemandResType->DC_EVSEStatus, eventCode);
					grammarID = 8;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 8:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEPresentVoltage)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gCurrentDemandResType->EVSEPresentVoltage, eventCode);
					grammarID = 9;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 9:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEPresentCurrent)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gCurrentDemandResType->EVSEPresentCurrent, eventCode);
					grammarID = 10;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 10:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSECurrentLimitAchieved)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gCurrentDemandResType->EVSECurrentLimitAchieved);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSECurrentLimitAchieved) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 11;
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
		case 11:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEVoltageLimitAchieved)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gCurrentDemandResType->EVSEVoltageLimitAchieved);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEVoltageLimitAchieved) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 12;
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
		case 12:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEPowerLimitAchieved)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gCurrentDemandResType->EVSEPowerLimitAchieved);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEPowerLimitAchieved) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 13;
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
		case 13:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEMaximumVoltageLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEMaximumCurrentLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEMaximumPowerLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEID)] */
			errn = decodeNBitUnsignedInteger(stream, 3, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gCurrentDemandResType->EVSEMaximumVoltageLimit, eventCode);
					v2gCurrentDemandResType->EVSEMaximumVoltageLimit_isUsed = 1u;
					grammarID = 14;
					break;
				case 1:
					errn = decode_v2gPhysicalValueType(stream, &v2gCurrentDemandResType->EVSEMaximumCurrentLimit, eventCode);
					v2gCurrentDemandResType->EVSEMaximumCurrentLimit_isUsed = 1u;
					grammarID = 15;
					break;
				case 2:
					errn = decode_v2gPhysicalValueType(stream, &v2gCurrentDemandResType->EVSEMaximumPowerLimit, eventCode);
					v2gCurrentDemandResType->EVSEMaximumPowerLimit_isUsed = 1u;
					grammarID = 16;
					break;
				case 3:
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gCurrentDemandResType->EVSEID.charactersLen);
							if (errn == 0) {
								errn =  (v2gCurrentDemandResType->EVSEID.charactersLen - 2) <= v2gCurrentDemandResType_EVSEID_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
							}
							if (errn == 0) {
								if (v2gCurrentDemandResType->EVSEID.charactersLen >= 2) {
									v2gCurrentDemandResType->EVSEID.charactersLen = (uint16_t)(v2gCurrentDemandResType->EVSEID.charactersLen - 2); /* string table miss */
									errn = decodeCharacters(stream, v2gCurrentDemandResType->EVSEID.charactersLen, v2gCurrentDemandResType->EVSEID.characters);
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
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 17;
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
		case 14:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEMaximumCurrentLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEMaximumPowerLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEID)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gCurrentDemandResType->EVSEMaximumCurrentLimit, eventCode);
					v2gCurrentDemandResType->EVSEMaximumCurrentLimit_isUsed = 1u;
					grammarID = 15;
					break;
				case 1:
					errn = decode_v2gPhysicalValueType(stream, &v2gCurrentDemandResType->EVSEMaximumPowerLimit, eventCode);
					v2gCurrentDemandResType->EVSEMaximumPowerLimit_isUsed = 1u;
					grammarID = 16;
					break;
				case 2:
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gCurrentDemandResType->EVSEID.charactersLen);
							if (errn == 0) {
								errn =  (v2gCurrentDemandResType->EVSEID.charactersLen - 2) <= v2gCurrentDemandResType_EVSEID_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
							}
							if (errn == 0) {
								if (v2gCurrentDemandResType->EVSEID.charactersLen >= 2) {
									v2gCurrentDemandResType->EVSEID.charactersLen = (uint16_t)(v2gCurrentDemandResType->EVSEID.charactersLen - 2); /* string table miss */
									errn = decodeCharacters(stream, v2gCurrentDemandResType->EVSEID.charactersLen, v2gCurrentDemandResType->EVSEID.characters);
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
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 17;
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
		case 15:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEMaximumPowerLimit), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEID)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gCurrentDemandResType->EVSEMaximumPowerLimit, eventCode);
					v2gCurrentDemandResType->EVSEMaximumPowerLimit_isUsed = 1u;
					grammarID = 16;
					break;
				case 1:
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gCurrentDemandResType->EVSEID.charactersLen);
							if (errn == 0) {
								errn =  (v2gCurrentDemandResType->EVSEID.charactersLen - 2) <= v2gCurrentDemandResType_EVSEID_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
							}
							if (errn == 0) {
								if (v2gCurrentDemandResType->EVSEID.charactersLen >= 2) {
									v2gCurrentDemandResType->EVSEID.charactersLen = (uint16_t)(v2gCurrentDemandResType->EVSEID.charactersLen - 2); /* string table miss */
									errn = decodeCharacters(stream, v2gCurrentDemandResType->EVSEID.charactersLen, v2gCurrentDemandResType->EVSEID.characters);
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
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 17;
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
		case 16:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gCurrentDemandResType->EVSEID.charactersLen);
							if (errn == 0) {
								errn =  (v2gCurrentDemandResType->EVSEID.charactersLen - 2) <= v2gCurrentDemandResType_EVSEID_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
							}
							if (errn == 0) {
								if (v2gCurrentDemandResType->EVSEID.charactersLen >= 2) {
									v2gCurrentDemandResType->EVSEID.charactersLen = (uint16_t)(v2gCurrentDemandResType->EVSEID.charactersLen - 2); /* string table miss */
									errn = decodeCharacters(stream, v2gCurrentDemandResType->EVSEID.charactersLen, v2gCurrentDemandResType->EVSEID.characters);
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
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 17;
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
		case 17:
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
							v2gCurrentDemandResType->SAScheduleTupleID = (uint8_t)(uint32 + 1);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}SAScheduleTupleID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 18;
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
		case 18:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}MeterInfo), START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ReceiptRequired), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gMeterInfoType(stream, &v2gCurrentDemandResType->MeterInfo, eventCode);
					v2gCurrentDemandResType->MeterInfo_isUsed = 1u;
					grammarID = 19;
					break;
				case 1:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gCurrentDemandResType->ReceiptRequired);
							v2gCurrentDemandResType->ReceiptRequired_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ReceiptRequired) ? */
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
		case 19:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ReceiptRequired), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BOOLEAN]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeBoolean(stream, &v2gCurrentDemandResType->ReceiptRequired);
							v2gCurrentDemandResType->ReceiptRequired_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ReceiptRequired) ? */
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EVSEChargeParameterType',  base type name='anyType',  content type='EMPTY',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  derivedBy='RESTRICTION'.  */
int decode_v2gEVSEChargeParameterType(bitstream_t* stream, struct v2gEVSEChargeParameterType* v2gEVSEChargeParameterType, uint32_t eventCode) {
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

/* Complex type name='urn:iso:15118:2:2013:MsgDataTypes,EVSEStatusType',  base type name='anyType',  content type='ELEMENT',  isAbstract='true',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgDataTypes":NotificationMaxDelay,"urn:iso:15118:2:2013:MsgDataTypes":EVSENotification)',  derivedBy='RESTRICTION'.  */
int decode_v2gEVSEStatusType(bitstream_t* stream, struct v2gEVSEStatusType* v2gEVSEStatusType, uint32_t eventCode) {
	int grammarID = 109;
	int done = 0;
	int errn;
	uint32_t uint32;

	while(!done) {
		switch(grammarID) {
		case 109:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}NotificationMaxDelay)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gEVSEStatusType->NotificationMaxDelay);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}NotificationMaxDelay) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 110;
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
		case 110:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSENotification)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 2, &uint32);
							v2gEVSEStatusType->EVSENotification = (v2gEVSENotificationType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSENotification) ? */
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,ServiceDetailResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":ServiceID,"urn:iso:15118:2:2013:MsgBody":ServiceParameterList{0-1})',  derivedBy='EXTENSION'.  */
int decode_v2gServiceDetailResType(bitstream_t* stream, struct v2gServiceDetailResType* v2gServiceDetailResType, uint32_t eventCode) {
	int grammarID = 246;
	int done = 0;
	int errn;
	uint32_t uint32;

	v2gServiceDetailResType->ServiceParameterList_isUsed = 0u;
	while(!done) {
		switch(grammarID) {
		case 246:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 5, &uint32);
							v2gServiceDetailResType->ResponseCode = (v2gresponseCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 247;
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
		case 247:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[UNSIGNED_INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gServiceDetailResType->ServiceID);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 248;
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
		case 248:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceParameterList), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gServiceParameterListType(stream, &v2gServiceDetailResType->ServiceParameterList, eventCode);
					v2gServiceDetailResType->ServiceParameterList_isUsed = 1u;
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,MeteringReceiptResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgDataTypes":EVSEStatus)',  derivedBy='EXTENSION'.  */
int decode_v2gMeteringReceiptResType(bitstream_t* stream, struct v2gMeteringReceiptResType* v2gMeteringReceiptResType, uint32_t eventCode) {
	int grammarID = 311;
	int done = 0;
	int errn;
	uint32_t uint32;

	v2gMeteringReceiptResType->EVSEStatus_isUsed = 0u;
	v2gMeteringReceiptResType->AC_EVSEStatus_isUsed = 0u;
	v2gMeteringReceiptResType->DC_EVSEStatus_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 311:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 5, &uint32);
							v2gMeteringReceiptResType->ResponseCode = (v2gresponseCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 312;
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
		case 312:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}AC_EVSEStatus), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVSEStatus), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEStatus)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gAC_EVSEStatusType(stream, &v2gMeteringReceiptResType->AC_EVSEStatus, eventCode);
					v2gMeteringReceiptResType->AC_EVSEStatus_isUsed = 1u;
					grammarID = 5;
					break;
				case 1:
					errn = decode_v2gDC_EVSEStatusType(stream, &v2gMeteringReceiptResType->DC_EVSEStatus, eventCode);
					v2gMeteringReceiptResType->DC_EVSEStatus_isUsed = 1u;
					grammarID = 5;
					break;
				case 2:
					errn = decode_v2gEVSEStatusType(stream, &v2gMeteringReceiptResType->EVSEStatus, eventCode);
					v2gMeteringReceiptResType->EVSEStatus_isUsed = 1u;
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,PaymentDetailsResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":GenChallenge,"urn:iso:15118:2:2013:MsgBody":EVSETimeStamp)',  derivedBy='EXTENSION'.  */
int decode_v2gPaymentDetailsResType(bitstream_t* stream, struct v2gPaymentDetailsResType* v2gPaymentDetailsResType, uint32_t eventCode) {
	int grammarID = 302;
	int done = 0;
	int errn;
	uint32_t uint32;

	while(!done) {
		switch(grammarID) {
		case 302:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 5, &uint32);
							v2gPaymentDetailsResType->ResponseCode = (v2gresponseCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 303;
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
		case 303:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}GenChallenge)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[BINARY_BASE64]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gPaymentDetailsResType->GenChallenge.bytesLen);
							if (errn == 0) {
								errn =  (v2gPaymentDetailsResType->GenChallenge.bytesLen) <= v2gPaymentDetailsResType_GenChallenge_BYTES_SIZE ? 0 : EXI_ERROR_OUT_OF_BYTE_BUFFER;
							}
							if (errn == 0) {
								errn = decodeBytes(stream, v2gPaymentDetailsResType->GenChallenge.bytesLen, v2gPaymentDetailsResType->GenChallenge.bytes);
							}
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}GenChallenge) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 304;
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
		case 304:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSETimeStamp)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeInteger64(stream, &v2gPaymentDetailsResType->EVSETimeStamp);
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSETimeStamp) ? */
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,PaymentServiceSelectionResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode)',  derivedBy='EXTENSION'.  */
int decode_v2gPaymentServiceSelectionResType(bitstream_t* stream, struct v2gPaymentServiceSelectionResType* v2gPaymentServiceSelectionResType, uint32_t eventCode) {
	int grammarID = 54;
	int done = 0;
	int errn;
	uint32_t uint32;

	while(!done) {
		switch(grammarID) {
		case 54:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 5, &uint32);
							v2gPaymentServiceSelectionResType->ResponseCode = (v2gresponseCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode) ? */
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,PowerDeliveryResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgDataTypes":EVSEStatus)',  derivedBy='EXTENSION'.  */
int decode_v2gPowerDeliveryResType(bitstream_t* stream, struct v2gPowerDeliveryResType* v2gPowerDeliveryResType, uint32_t eventCode) {
	int grammarID = 311;
	int done = 0;
	int errn;
	uint32_t uint32;

	v2gPowerDeliveryResType->EVSEStatus_isUsed = 0u;
	v2gPowerDeliveryResType->AC_EVSEStatus_isUsed = 0u;
	v2gPowerDeliveryResType->DC_EVSEStatus_isUsed = 0u;
	while(!done) {
		switch(grammarID) {
		case 311:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 5, &uint32);
							v2gPowerDeliveryResType->ResponseCode = (v2gresponseCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 312;
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
		case 312:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}AC_EVSEStatus), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}DC_EVSEStatus), START_ELEMENT({urn:iso:15118:2:2013:MsgDataTypes}EVSEStatus)] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gAC_EVSEStatusType(stream, &v2gPowerDeliveryResType->AC_EVSEStatus, eventCode);
					v2gPowerDeliveryResType->AC_EVSEStatus_isUsed = 1u;
					grammarID = 5;
					break;
				case 1:
					errn = decode_v2gDC_EVSEStatusType(stream, &v2gPowerDeliveryResType->DC_EVSEStatus, eventCode);
					v2gPowerDeliveryResType->DC_EVSEStatus_isUsed = 1u;
					grammarID = 5;
					break;
				case 2:
					errn = decode_v2gEVSEStatusType(stream, &v2gPowerDeliveryResType->EVSEStatus, eventCode);
					v2gPowerDeliveryResType->EVSEStatus_isUsed = 1u;
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,PreChargeResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":DC_EVSEStatus,"urn:iso:15118:2:2013:MsgBody":EVSEPresentVoltage)',  derivedBy='EXTENSION'.  */
int decode_v2gPreChargeResType(bitstream_t* stream, struct v2gPreChargeResType* v2gPreChargeResType, uint32_t eventCode) {
	int grammarID = 23;
	int done = 0;
	int errn;
	uint32_t uint32;

	while(!done) {
		switch(grammarID) {
		case 23:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 5, &uint32);
							v2gPreChargeResType->ResponseCode = (v2gresponseCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 24;
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
		case 24:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}DC_EVSEStatus)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gDC_EVSEStatusType(stream, &v2gPreChargeResType->DC_EVSEStatus, eventCode);
					grammarID = 25;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 25:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEPresentVoltage)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gPreChargeResType->EVSEPresentVoltage, eventCode);
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,ServiceDiscoveryResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":PaymentOptionList,"urn:iso:15118:2:2013:MsgBody":ChargeService,"urn:iso:15118:2:2013:MsgBody":ServiceList{0-1})',  derivedBy='EXTENSION'.  */
int decode_v2gServiceDiscoveryResType(bitstream_t* stream, struct v2gServiceDiscoveryResType* v2gServiceDiscoveryResType, uint32_t eventCode) {
	int grammarID = 136;
	int done = 0;
	int errn;
	uint32_t uint32;

	v2gServiceDiscoveryResType->ServiceList_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 136:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 5, &uint32);
							v2gServiceDiscoveryResType->ResponseCode = (v2gresponseCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 137;
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
		case 137:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}PaymentOptionList)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPaymentOptionListType(stream, &v2gServiceDiscoveryResType->PaymentOptionList, eventCode);
					grammarID = 138;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 138:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ChargeService)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gChargeServiceType(stream, &v2gServiceDiscoveryResType->ChargeService, eventCode);
					grammarID = 139;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 139:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ServiceList), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gServiceListType(stream, &v2gServiceDiscoveryResType->ServiceList, eventCode);
					v2gServiceDiscoveryResType->ServiceList_isUsed = 1u;
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,SessionSetupResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":EVSEID,"urn:iso:15118:2:2013:MsgBody":EVSETimeStamp{0-1})',  derivedBy='EXTENSION'.  */
int decode_v2gSessionSetupResType(bitstream_t* stream, struct v2gSessionSetupResType* v2gSessionSetupResType, uint32_t eventCode) {
	int grammarID = 215;
	int done = 0;
	int errn;
	uint32_t uint32;

	v2gSessionSetupResType->EVSETimeStamp_isUsed = 0u;

	while(!done) {
		switch(grammarID) {
		case 215:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 5, &uint32);
							v2gSessionSetupResType->ResponseCode = (v2gresponseCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 216;
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
		case 216:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEID)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[STRING]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeUnsignedInteger16(stream, &v2gSessionSetupResType->EVSEID.charactersLen);
							if (errn == 0) {
								errn =  (v2gSessionSetupResType->EVSEID.charactersLen - 2) <= v2gSessionSetupResType_EVSEID_CHARACTERS_SIZE ? 0 : EXI_ERROR_STRINGVALUES_OUT_OF_BOUND;
							}
							if (errn == 0) {
								if (v2gSessionSetupResType->EVSEID.charactersLen >= 2) {
									v2gSessionSetupResType->EVSEID.charactersLen = (uint16_t)(v2gSessionSetupResType->EVSEID.charactersLen - 2); /* string table miss */
									errn = decodeCharacters(stream, v2gSessionSetupResType->EVSEID.charactersLen, v2gSessionSetupResType->EVSEID.characters);
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
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEID) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 217;
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
		case 217:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSETimeStamp), END_ELEMENT] */
			errn = decodeNBitUnsignedInteger(stream, 2, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* First(xsi:type)StartTag[CHARACTERS[INTEGER]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeInteger64(stream, &v2gSessionSetupResType->EVSETimeStamp);
							v2gSessionSetupResType->EVSETimeStamp_isUsed = 1u;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSETimeStamp) ? */
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,SessionStopResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode)',  derivedBy='EXTENSION'.  */
int decode_v2gSessionStopResType(bitstream_t* stream, struct v2gSessionStopResType* v2gSessionStopResType, uint32_t eventCode) {
	int grammarID = 54;
	int done = 0;
	int errn;
	uint32_t uint32;

	while(!done) {
		switch(grammarID) {
		case 54:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 5, &uint32);
							v2gSessionStopResType->ResponseCode = (v2gresponseCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode) ? */
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

/* Complex type name='urn:iso:15118:2:2013:MsgBody,WeldingDetectionResType',  base type name='BodyBaseType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='("urn:iso:15118:2:2013:MsgBody":ResponseCode,"urn:iso:15118:2:2013:MsgBody":DC_EVSEStatus,"urn:iso:15118:2:2013:MsgBody":EVSEPresentVoltage)',  derivedBy='EXTENSION'.  */
int decode_v2gWeldingDetectionResType(bitstream_t* stream, struct v2gWeldingDetectionResType* v2gWeldingDetectionResType, uint32_t eventCode) {
	int grammarID = 23;
	int done = 0;
	int errn;
	uint32_t uint32;

	while(!done) {
		switch(grammarID) {
		case 23:
			/* FirstStartTag[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					/* FirstStartTag[CHARACTERS[ENUMERATION]] */
					errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
					if(errn == 0) {
						if(eventCode == 0) {
							errn = decodeNBitUnsignedInteger(stream, 5, &uint32);
							v2gWeldingDetectionResType->ResponseCode = (v2gresponseCodeType) uint32;
						} else {
							/* Second level event (e.g., xsi:type, xsi:nil, ...) */
							errn = EXI_UNSUPPORTED_EVENT_CODE_CHARACTERISTICS;
						}
					}
					if(errn == 0) {
						/* valid EE for simple element START_ELEMENT({urn:iso:15118:2:2013:MsgBody}ResponseCode) ? */
						errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
						if(eventCode == 0) {
						grammarID = 24;
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
		case 24:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}DC_EVSEStatus)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gDC_EVSEStatusType(stream, &v2gWeldingDetectionResType->DC_EVSEStatus, eventCode);
					grammarID = 25;
					break;
				default:
					errn = EXI_ERROR_UNKOWN_EVENT_CODE;
					break;
				}
			}
			break;
		case 25:
			/* Element[START_ELEMENT({urn:iso:15118:2:2013:MsgBody}EVSEPresentVoltage)] */
			errn = decodeNBitUnsignedInteger(stream, 1, &eventCode);
			if (errn == 0) {
				switch(eventCode) {
				case 0:
					errn = decode_v2gPhysicalValueType(stream, &v2gWeldingDetectionResType->EVSEPresentVoltage, eventCode);
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
