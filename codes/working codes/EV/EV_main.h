/*
 * EV_main.h
 *
 *  Created on: 30.06.2016
 *      Author: melanie
 */

#ifndef EV_MAIN_H_
#define EV_MAIN_H_


#include "ISO_EV_main.h"
# include <stdio.h>
# include <netinet/in.h>
# include "PWMSignal.h"
# include "interface.h"
# include "motors_lock.h"
# include "PP_Pin.h"
# include "clientsockets.h"
# include "hardware.h"

# define PWM_CTRL 0 // 0=disable --> EV-Side, 1=enable-->EVSE-Side, 2= query PWM-Signal
# define PP_RESISTOR 3 //0 = 2,7k, 1=150, 2=487, 3=1,5k, 4=680, 5=220, 6=100, 7=Off, 8-255=reserved
# if CODE_EXAMPLE == CODE_EXAMPLE_HARDWARE
	# define IP_ADRESSE "192.168.38.33"// wenn EV auf 192.168.37.251
#else
	# define IP_ADRESSE "127.0.0.1"
#endif
# define PORT_NUMMER 5000


#endif /* EV_MAIN_H_ */
