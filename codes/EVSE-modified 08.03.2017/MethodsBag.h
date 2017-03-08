/*
 * MethodsBag.h
 *
 *  Created on: 03.01.2016
 *      Author: melanie
 */

#ifndef ISO_COMM_CODEC_METHODSBAG_H_
#define ISO_COMM_CODEC_METHODSBAG_H_

#include <stdint.h>


/**
 * \brief  	Returns the least number of 7 bit-blocks that is needed to represent the passed integer value
 *
 *			Note: Returns 1 if passed parameter is 0.
 *
 * \param       n				integer value
 * \return                  	Error-Code <> 0
 *
 */
uint8_t numberOf7BitBlocksToRepresent(uint32_t n);

#endif /* ISO_COMM_CODEC_METHODSBAG_H_ */
