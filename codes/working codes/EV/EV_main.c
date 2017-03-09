/*
 * EV_main.c
 *
 *  Created on: 02.12.2015
 *      Author: melanie
 */

#include "EV_main.h"


int main(void)
{
int fd = 0;

# if CODE_EXAMPLE == CODE_EXAMPLE_HARDWARE
	/*init EVAchargeSE board ***************************/
	double DutyCycle;
	double UCP;
	fd=open_serial();
	//Init PWM Signal
	control_pwm(fd, PWM_CTRL);
	UCP = set_Ucp(fd,0);	// 12V
	UCP = get_Ucp(fd);
	printf("+++ level on CP: standby, %f +++\n\n", UCP);
	DutyCycle = (get_pwm(fd)/1000) * 60; // data from EVSE --> Duty cycle depending on max current of the EVSE in % * 60A
	//--> PP_Resistor bei bedarf anpassen
	PPacivate(fd, PP_RESISTOR);// max current of the EV

# endif

	int socket_nummer, errn, no_oftrials=0;

	socket_nummer = socket(AF_INET, SOCK_STREAM,0);
	do
	{
		errn = socket_clientconnect(socket_nummer,IP_ADRESSE,PORT_NUMMER);
		no_oftrials++;
	} while (errn==-1 && no_oftrials<20);

	if(errn == -1)
	{
		printf("\n Verbindung nicht hergestellt ");
	}
	else
	{
		do{
			errn = 1;
			Lock_Cable(fd); // einschalten sobald Verriegelung vorhanden
		} while (errn !=1);

		errn = ISO_start(socket_nummer, fd);
		if (errn != 0){
			printf("error during ISO 15118 Communication");
		}
		do{
			errn =1;
			Unlock_Cable(fd); // einschalten sobald Verriegelung vorhanden
		} while (errn !=1);
	}
	/*close TCP socket*/
	close(socket_nummer);

return 0;

}

