/*
* 
* switchpi.c
* 
* the switch case function for the raspberry pi
* Author: Jiztom Francis K
* Created on : 01.03.2017
* Modified on: 08.03.2017
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

#define SEMI_ISO15118 61
#define MANUAL_CHARGING 62
 

unsigned char state ;

void init_statemachine()
{
	state=ST_PLUG;
}

unsigned char get_state()
{
	return state;
}

int fire_event ( int event, int param , int socket_fd)
{
	int j =0;
	char i;
	unsigned char code;
	unsigned int value;
	switch(state)
	{
		case ST_PLUG:
			switch(event)
			{
				case CABLE_DETECTED:
					do
					{
						i = receivee(socket_fd, &code , &value);
					}while(code!= CABLE_DETECTED);//(strcmp(i,CABLE_DETECTED)!= 1);
					printf("\nthe car has been detected ");
					
					j= 1;
					return j;
					break;
						
				case CABLE_LOCK:
					if(param == 1)
					{
						printf("\nthe cable has been locked");
						j= 1;
								
					}
					else
					{
						printf("\nthere is a cable lock error");
						j = 0;
					}
					return j;
					break;
					
				case PROTOCOL_DETECT:
					if(param == ISO15118_DETECTED)
					{
						printf("\nProtocol ISO15118 detected.\n Car is not ready to charge");
						state = ST_SIGN_IN;
						
					}
					else if ( param == IEC61851_DETECTED)
					{
						state = SEMI_ISO15118;
					}
					else if ( param == NO_PROTOCOL_DETECTED)
					{
						state = MANUAL_CHARGING;
					}
					//state = ST_SIGN_IN;
					break;
			
				case LOCKING_ERROR:
					printf("\nRestarting the locking preocess");
					
					break;
				
			}
		
		case ST_SIGN_IN:
			switch(event)
			{
				case REGISTER:
					printf("\ninitialize the payment procedure with the sign in details");
					
					do
					{
						i=receivee(socket_fd ,&code ,&value);
					}while(code!=REGISTER);//(strcmp(i,REGISTER)!=1);
					break;
				
				case AUTHORIZATION:
					printf(" \nAuthorize the charging station to start the charging process");
					sendd(socket_fd , AUTHORIZATION);
					state = ST_CHARGE;
					break;
			}
			
		case ST_CHARGE:
			switch(event)
			{
				case START_CHARGE:
					printf("\nto start the charging process");
					sendd(socket_fd, START_CHARGE);
					break;
				
				case CHARGING_STATUS:
					printf("\nthe charging status of the car with all necessary details");
					do
					{
						i = receivee(socket_fd , &code ,&value);
					}while(code!= CHARGING_STATUS);//(strcmp(i,CHARGING_STATUS)!= 1);
					break; 
				
				case FULL_CHARGE:
					printf("\nthe car has been fully charged ");
					do
					{
						i = receivee(socket_fd , &code , &value);
					}while(code!= FULL_CHARGE);//(strcmp(i,FULL_CHARGE)!= 1);
					break;
				
				case MANUAL_STOP:
					printf("\nthe car charging should be stopped immediately");
					sendd(socket_fd , MANUAL_STOP);
					break;
					
				case METER_RECEIPT:
					printf("\nthe receipt of the power and duration the vehicle has been charged");
					do
					{
						i=receivee(socket_fd ,&code,&value);
					}while(code!= METER_RECEIPT);//(strcmp(i,METER_RECEIPT)!= 1);//maybe an internal process
					state = ST_POST_CHARGE;
					break;
					
			}
		
		case ST_POST_CHARGE:
			switch(event)
			{
				case INITIATE_PAYMENT:
					printf(" \n the payment based on the meter receipt in initiated \n ");
					do
					{
						i = receivee(socket_fd , &code , &value);
					}while(code!= INITIATE_PAYMENT);//(strcmp(i,INITIATE_PAYMENT) != 1);
					printf(" \n the payment will be assesed for completion and will proceed to next stage \n");
					break;
				
				case PAYMENT_SUCESSFUL:
					printf(" \n The payment was sucessful and the sucessful display is displayed \n");
					sendd(socket_fd , PAYMENT_SUCESSFUL);
					break;
					
				case PAYMENT_UNSUCESSFUL:
					printf(" if the payment is unsicessful please retry to pay");
					///////////requires an internal code to replace pre used account details////////
					printf("if failed thrice allow user to re enter their card details. Car will not be released until the payment is sucessful");
					break;
					
				case CABLE_UN_LOCK:
					printf("\n the car is being unlocked");
					do
					{
						i = receivee(socket_fd , &code ,&value);
					}while(code!= CABLE_UN_LOCK);//(strcmp(i,CABLE_UN_LOCK)!= 1);
					printf("\ncharging has been completed");
					break;
			}
		
	
	}
	return j;
}

				


