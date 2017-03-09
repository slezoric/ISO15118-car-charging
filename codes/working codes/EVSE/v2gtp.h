/*
 * v2gtp.h
 *
 *  Created on: 03.01.2016
 *      Author: melanie
 */



#ifdef __cplusplus
extern "C" {
#endif


#ifndef ISO_COMM_TRANSPORT_V2GTP_H_
#define ISO_COMM_TRANSPORT_V2GTP_H_

#include <stdint.h>

/* generic V2GTP header length */
#define V2GTP_HEADER_LENGTH 8

/* define V2GTP Version */
#define V2GTP_VERSION 0x01
#define V2GTP_VERSION_INV 0xFE

/* define V2GTP payload types*/
#define V2GTP_EXI_TYPE 0x8001

int write_v2gtpHeader(uint8_t* outStream, uint16_t outStreamLength, uint16_t payloadTypem);

int read_v2gtpHeader(uint8_t* inStream, uint16_t* payloadLength);
#endif /* ISO_COMM_TRANSPORT_V2GTP_H_ */
