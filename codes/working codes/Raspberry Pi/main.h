/*
 * main.h 
 * 
 * Created on	: 06.03.2017
 * 		Author	: Jiztom Francis	
 * 
 * 
 */
 
#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "transfer.h"
#include "switchpi.h"


#define ST_PLUG 1
#define ST_SIGN_IN 2
#define ST_CHARGE 3
#define ST_POST_CHARGE 4

#define HMI_READY 5

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

#endif /*MAIN_H_*/
