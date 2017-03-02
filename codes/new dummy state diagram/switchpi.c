/*
* 
* switchpi.c
* 
* the switch case function for the raspberry pi
* Author: Jiztom Francis K
* Created on : 01.03.2017
* Modified on: 01.03.2017
*/

#include "switchpi.h"

#define ST_PLUG 1
#define ST_SIGN_IN 2
#define ST_CHARGE 3
#define ST_POST_CHARGE 4

#define CABLE_DETECTED 11
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

#define SEMI_ISO15118 101
#define MANUAL_CHARGING 102
 

unsigned char state ;

void init_statemachine()
{
	state=ST_PLUG;
}

unsigned char get_state()
{
	return state;
}

void fire_event ( int event, int param)
{
	switch(state)
	{
		case ST_PLUG:
			switch(event)
			{
				case CABLE_DETECTED:
					printf("the car has been detected ");
					event = CABLE_LOCK;
					break;
						
				case CABLE_LOCK:
					if(param == 1)
					{
						printf("the cable has been locked");
						event = PROTOCOL_DETECT;
					}
					else
					{
						printf("there is a cable lcok error");
						event = LOCKING_ERROR;
					}
					break;
					
				case PROTOCOL_DETECT:
					if(param == ISO15118_DETECTED)
					{
						printf("Protocol ISO15118 detected.\n Car is not ready to charge");
						state = ST_SIGN_IN;
						event = REGISTER;
					}
					else if ( param == IEC61851_DETECTED)
					{
						event = SEMI_ISO15118;
					}
					else if ( param == NO_PROTOCOL_DETECTED)
					{
						event = MANUAL_CHARGING;
					}
					break;
			
				case LOCKING_ERROR:
					printf("Restarting the locking preocess");
					event = CABLE_DETECTED;
					break;
				
			}
		
		case ST_SIGN_IN:
			switch(event)
			{
				case REGISTER:
					printf("initialize the payment procedure with the sign in details");
					event = AUTHORIZATION;
					break;
				
				case AUTHORIZATION:
					printf(" Authorize the charging station to start the charging process");
					event = START_CHARGE;
					state = ST_CHARGE;
					break;
			}
			
		case ST_CHARGE:
			switch(event)
			{
				case START_CHARGE:
					printf("to start the charging process");
					event = CHARGING_STATUS;
					break;
				
				case CHARGING_STATUS:
				
				case FULL_CHARGE:
				
				case MANUAL_STOP:
				
				case METER_RECEIPT:
				
			}
		
		case ST_POST_CHARGE:
			switch(event)
			{
				case INITIATE_PAYMENT:
				
				case PAYMENT_SUCESSFUL:
				
				case PAYMENT_UNSUCESSFUL:
				
				case CABLE_UN_LOCK:
				
			}
		
	
	}
}				


