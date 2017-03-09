/*
 * EXIConfig.h
 *
 *  Created on: 03.01.2016
 *      Author: melanie
 */

/**
 * \file 	EXIConfig.h
 * \brief 	EXI Configurations for the EXI Codec
 *
 */


#ifndef ISO_COMM_CODEC_EXICONFIG_H_
#define ISO_COMM_CODEC_EXICONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

/** EXI stream - Option Byte Array */
#define BYTE_ARRAY 1
/** EXI stream - Option File */
#define FILE_STREAM 2
/** \brief 	EXI stream
 * 			Byte array or file
 * */
#define EXI_STREAM BYTE_ARRAY

/** String representation ASCII */
#define STRING_REPRESENTATION_ASCII 1
/** String representation Universal Character Set (UCS) */
#define STRING_REPRESENTATION_UCS 2
/** */
/** \brief 	String representation mode
 *
 * 			ASCII or UCS
 * */
#define STRING_REPRESENTATION STRING_REPRESENTATION_ASCII






#endif /* ISO_COMM_CODEC_EXICONFIG_H_ */
