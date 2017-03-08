`/*
 * EVSE_main.h
 *
 *  Created on	: 30.06.2016
 *      Author	: melanie
 *  Modified by :Jiztom Francis K 
 * 	Modified on : 07.03.2017
 */

#ifndef EVSE_MAIN_H_
#define EVSE_MAIN_H_

# include <stdio.h>
# include <netinet/in.h>
# include "PWMSignal.h"
# include "interface.h"
# include "motors_lock.h"
# include "PP_Pin.h"
# include "serversockets.h"
# include "v2gEXIDatatypes.h"
# include "response.h"
# include "hardware.h"
# include "v2gtp.h"
# include <sys/types.h>
# include <sys/socket.h>
# include "ISO_EVSE_main.h"

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

#include "transfer.h"



# define PWM_CTRL 1 // 0=disable --> EV-Side, 1=enable-->EVSE-Side, 2= query PWM-Signal
# define PWM_DUTYCYCLE 250 //500 Hz of 1 kHz = 25% --> max current EVSE 15A
# define CODE_EXAMPLE_SOFTWARE 0
# define CODE_EXAMPLE_HARDWARE 1
# define CODE_EXAMPLE CODE_EXAMPLE_HARDWARE
# define PORT_NUMMER 5000
# define PORT 3490
# define MAXSIZE 1024


#define CABLE_DETECTED 11

 




#endif /* EVSE_MAIN_H_ */
