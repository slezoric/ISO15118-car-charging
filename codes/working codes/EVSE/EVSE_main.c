/*
 * EVSE_main.c
 *
 *  Created on	: 02.12.2015
 *      Author	: melanie
 *  Edited by 	: Jiztom Francis
 *  Modified on : 08.03.2017
 */


#include "EVSE_main.h"



int main (void)
{
	
# if CODE_EXAMPLE == CODE_EXAMPLE_HARDWARE
	/*init EVAchargeSE board */
	int fd;
	double UCP;
	int round_UCP;
	fd=open_serial();
	//Init PWM Signal
	control_pwm(fd, PWM_CTRL);
	set_pwm(fd, PWM_DUTYCYCLE);
	//get_pwm(fd); // data EVSE --> 1kHz, Duty cycle depending on max current of the EVSE
# endif

	int ev;
	int i;
/////* the variables for the TCP IP connection*////////////////////////
	
	init_tcp();
	
	
	
/////*start ISO 15118 protocol************************/////////////////
	int new_socket, server_socket;
	int laenge;
	struct sockaddr_in clientinfo;
	struct v2gEXIDocument exiIn;
	struct v2gEXIDocument exiOut;
	int errn;

	server_socket = socket_serverconnect(PORT_NUMMER);
	//pi_server = pi_connect(PORTPI_NUMBER);
	do
	{
		i=receivee(sockfd,&code,&value);
	}while(code!=HMI_READY);
//////the TCP IP establishment between raspberry pi and the EVSE //
	

////////////////////////////////////////////////////////////////////////

	while(1)
	{
		printf("\n+++ Start protocol example ISO 15118 +++\n");
		laenge = sizeof(clientinfo);
		new_socket = accept(server_socket, (struct sockaddr *) &clientinfo, (socklen_t*)&laenge);
		/*DIN Test --> optional*/
		/*XMLDSIG Test --> optional*/

		# if CODE_EXAMPLE == CODE_EXAMPLE_HARDWARE
			UCP = get_Ucp(fd) * 10;
			round_UCP = UCP;
			UCP = round_UCP / 10;
			printf("+++ check level on CP for state B: EV detected, %f +++\n\n", UCP); 
			sendd(sockfd , CABLE_DETECTED);
			////// --------------->>>>>>event CABLE_DETECTED
		#else
			int fd =0;
			double UCP = 9;
		# endif

		if (((UCP>8)||(UCP==8)) && ((UCP<10)||(UCP==10))){ //Level for State B
			do{
				errn = Lock_Cable(fd);
			} while (errn !=1);

			printf("+++ release for charging: State B: vehicle detected +++\n");
			printf("+++ Start application handshake protocol example +++\n\n");
			ev = appHandshake(new_socket);
			if (ev == 0){
				ev = STATE_B1;
			}
			printf("+++ Terminate application handshake protocol example +++\n\n");
			while (ev == STATE_B1){
				ev = Communication_State_B1(new_socket, &exiIn, &exiOut);
			}



			# if CODE_EXAMPLE == CODE_EXAMPLE_HARDWARE
				UCP = get_Ucp(fd) * 10;
				round_UCP = UCP;
				UCP = round_UCP / 10;
				printf("+++ check level on CP for state C: EV connected, ready, %f +++\n\n", UCP);
			#else
				double UCP = 6;
			# endif

			if (((UCP>5)||(UCP==5)) && ((UCP<7.5)||(UCP== 7.0)) && (ev == STATE_C))////get_Ucp -->6V state C Communication ToDo Pegel auf 7.1V-> Toleranz 6+-1V
			{
				printf("+++ Start Communication State C +++\n\n");

				while (ev == STATE_C){
					ev = Communication_State_C(fd, new_socket, &exiIn, &exiOut);
				}

				# if CODE_EXAMPLE == CODE_EXAMPLE_HARDWARE
					UCP = get_Ucp(fd) * 10;
					round_UCP = UCP;
					UCP = round_UCP / 10;
					printf("+++ check level on CP for state B: EV detected, %f +++\n\n", UCP);
				#else
					double UCP = 9;
				# endif
		
				printf("+++ Start Communication State B +++\n\n");
				if (((UCP>8)||(UCP==8)) && ((UCP<10)||(UCP==10)) && (ev == STATE_B2)) ////get_Ucp --> 9 V state B Communication
				{
					while (ev == STATE_B2){
						ev = Communication_State_B2(new_socket, &exiIn, &exiOut);
					}
				}
			}
		}
		if (ev == STATE_ERROR)
		{
			printf(" Error during ISO 15118 Communication. \nPlease restart ");
		}
		printf("+++ End of example +++ \n");

		ev = STATE_A;
		do{
			errn = Unlock_Cable(fd);
		} while (errn !=1);

	}	//end while
	socket_close(server_socket);
	close(sockfd);
	return 0;
} 	//end main
