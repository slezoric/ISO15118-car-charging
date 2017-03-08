/*
 * ISO_main.h
 *
 *  Created on	: 03.01.2016
 *      Author	: melanie
 *  Modified by :Jiztom Francis K 
 * 	Modified on : 07.03.2017
 */

#ifndef ISO_COMM_ISO_EVSE_MAIN_H_
#define ISO_COMM_ISO_EVSE_MAIN_H_

# include "ErrorCodes.h"
# include "EXITypes.h"
# include "v2gEXIDatatypes.h"

/*Define shold basic status of the Signal 10-15*/
# define STATE_A 10
# define STATE_B1 11
# define STATE_C 12
# define STATE_B2 13
# define STATE_ERROR 15

/*Define charging state AC/DC */
# define AC_CHARGING 21
# define DC_CHARGING 22


/*Define States in state machines for cases B1, C, B2 */
/*State B1: 100-110*/
# define STATE_B1_SUPPORTED_APP_PROTOCOL 100
# define STATE_B1_SESSION_SETUP 101
# define STATE_B1_SERVICE_DICOVERY 102
# define STATE_B1_SERVICE_AND_PAYMENT_SELECTION 103
# define STATE_B1_PAYMENT_DETAILS 104
# define STATE_B1_CONTRACT_AUTHENTICATION 105
# define STATE_B1_CHARGE_PARAMETER_DISCOVERY 106

/*State C: 111 - 120*/
# define STATE_C_BEGIN_POWER_DELIVERY 111
# define STATE_C_AC_CHARGING_STATUS 112
//# define STATE_C_AC_METERING_RECEIPT 113
# define STATE_C_DC_CABLE_CHECK 114
# define STATE_C_DC_PRE_CHARGE 115
# define STATE_C_DC_CURRENT_DEMAND 116
# define STATE_C_END_POWER_DELIVERY 117

/*State B2: 121 - 130*/
# define STATE_B2_SESSION_STOP 121
# define STATE_B2_DC_WELDING_DETECTION 122

#define CABLE_LOCK 12
#define PROTOCOL_DETECT 13
#define LOCKING_ERROR 14

#define REGISTER 21
#define AUTHORIZATION 22

#define START_CHARGE 31
#define CHARGING_STATUS 32
#define MANUAL_STOP 33
#define FULL_CHARGE 34
#define METER_RECEIPT 36

#define INITIATE_PAYMENT 41
#define PAYMENT_SUCESSFUL 42
#define PAYMENT_UNSUCESSFUL 43
#define CABLE_UN_LOCK 45


#define ISO15118_DETECTED 51
#define IEC61851_DETECTED 52
#define NO_PROTOCOL_DETECTED 53

#define SEMI_ISO15118 61
#define MANUAL_CHARGING 62



/*Start ISO Communication
 * @params: socket_number from ethernet communikation*/
int appHandshake(int socket_number);

int Communication_State_B1(int socket_number,struct v2gEXIDocument* Input, struct v2gEXIDocument* Output);


int Communication_State_B2(int socket_number,struct v2gEXIDocument* Input, struct v2gEXIDocument* Output);

int Communication_State_C(int fd, int socket_number,struct v2gEXIDocument* Input, struct v2gEXIDocument* Output);

#endif /* ISO_COMM_ISO_EVSE_MAIN_H_ */
