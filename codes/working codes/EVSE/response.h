/*
 * response.h
 *
 *  Created on: 16.02.2016
 *      Author: melanie
 */

#ifndef ISO_COMM_RESPONSE_H_
#define ISO_COMM_RESPONSE_H_

# include "v2gEXIDatatypes.h"

int sessionSetup(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut);

int serviceDiscovery(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut);

int serviceDetail(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut);

int paymentServiceSelection(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut);

int paymentDetails(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut);

int authorization(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut);

int chargeParameterDiscovery(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut);

int powerDelivery(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut);

int chargingStatus(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut);

int meteringReceipt(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut);

int cableCheck(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut);

int preCharge(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut);

int currentDemand(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut);

int weldingDetection(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut);

int sessionStop(struct v2gEXIDocument* exiIn, struct v2gEXIDocument* exiOut);




#endif /* ISO_COMM_RESPONSE_H_ */
