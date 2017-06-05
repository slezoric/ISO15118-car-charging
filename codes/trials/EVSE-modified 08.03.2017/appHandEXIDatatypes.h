/*
 * EXIDatatypes.h
 *
 *  Created on: 03.01.2016
 *      Author: melanie
 */

#ifndef ISO_COMM_APPHANDSHAKE_APPHANDEXIDATATYPES_H_
#define ISO_COMM_APPHANDSHAKE_APPHANDEXIDATATYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "EXITypes.h"

/* Datatype definitions and structs for given XML Schema definitions */

#define UNION_YES 1
#define UNION_NO 2
#define SAVE_MEMORY_WITH_UNNAMED_UNION UNION_YES


/* Complex type name='urn:iso:15118:2:2010:AppProtocol,AppProtocolType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(ProtocolNamespace,VersionNumberMajor,VersionNumberMinor,SchemaID,Priority)',  derivedBy='RESTRICTION'.  */
#define appHandAppProtocolType_ProtocolNamespace_CHARACTERS_SIZE 100 /* XML schema facet maxLength for urn:iso:15118:2:2010:AppProtocol,protocolNamespaceType is 100 */
struct appHandAppProtocolType {
	/* element: ProtocolNamespace, urn:iso:15118:2:2010:AppProtocol,protocolNamespaceType */
	struct {
		exi_string_character_t characters[appHandAppProtocolType_ProtocolNamespace_CHARACTERS_SIZE];
		uint16_t charactersLen;
	}  ProtocolNamespace ;
	/* element: VersionNumberMajor, http://www.w3.org/2001/XMLSchema,unsignedInt */
	uint32_t VersionNumberMajor ;
	/* element: VersionNumberMinor, http://www.w3.org/2001/XMLSchema,unsignedInt */
	uint32_t VersionNumberMinor ;
	/* element: SchemaID, urn:iso:15118:2:2010:AppProtocol,idType */
	uint8_t SchemaID ;
	/* element: Priority, urn:iso:15118:2:2010:AppProtocol,priorityType */
	uint8_t Priority ;
};

typedef enum {
	appHandresponseCodeType_OK_SuccessfulNegotiation = 0,
	appHandresponseCodeType_OK_SuccessfulNegotiationWithMinorDeviation = 1,
	appHandresponseCodeType_Failed_NoNegotiation = 2
} appHandresponseCodeType;

/* Complex type name='urn:iso:15118:2:2010:AppProtocol,#AnonType_supportedAppProtocolRes',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(ResponseCode,SchemaID{0-1})',  derivedBy='RESTRICTION'.  */
struct appHandAnonType_supportedAppProtocolRes {
	/* element: ResponseCode, urn:iso:15118:2:2010:AppProtocol,responseCodeType */
	appHandresponseCodeType ResponseCode ;
	/* element: SchemaID, urn:iso:15118:2:2010:AppProtocol,idType */
	uint8_t SchemaID ;
	unsigned int SchemaID_isUsed:1;
};

/* Complex type name='urn:iso:15118:2:2010:AppProtocol,#AnonType_supportedAppProtocolReq',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(AppProtocol{1-20})',  derivedBy='RESTRICTION'.  */
#define appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE 5
struct appHandAnonType_supportedAppProtocolReq {
	/* element: AppProtocol, Complex type name='urn:iso:15118:2:2010:AppProtocol,AppProtocolType',  base type name='anyType',  content type='ELEMENT',  isAbstract='false',  hasTypeId='false',  final='0',  block='0',  particle='(ProtocolNamespace,VersionNumberMajor,VersionNumberMinor,SchemaID,Priority)',  derivedBy='RESTRICTION'.  */
	struct {
		struct appHandAppProtocolType array[appHandAnonType_supportedAppProtocolReq_AppProtocol_ARRAY_SIZE];
		uint16_t arrayLen;
	} AppProtocol;
};


/* Possible root elements of EXI Document */
struct appHandEXIDocument {
#if SAVE_MEMORY_WITH_UNNAMED_UNION == UNION_YES
	union {
#endif /* SAVE_MEMORY_WITH_UNNAMED_UNION == UNION_YES */
	struct appHandAnonType_supportedAppProtocolReq supportedAppProtocolReq ;
	struct appHandAnonType_supportedAppProtocolRes supportedAppProtocolRes ;
#if SAVE_MEMORY_WITH_UNNAMED_UNION == UNION_YES
	};
#endif /* SAVE_MEMORY_WITH_UNNAMED_UNION == UNION_YES */
	unsigned int supportedAppProtocolReq_isUsed:1;
	unsigned int supportedAppProtocolRes_isUsed:1;


	int _warning_;
};



#endif /* ISO_COMM_APPHANDSHAKE_APPHANDEXIDATATYPES_H_ */
