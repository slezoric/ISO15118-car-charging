/*
 *  main.c
 * 
 * 	Author 		: Jiztom Franics K	
 * 	Created on	: 01.03.2017 
 *  Modified on	: 08.03.2017
 */

/*
*  server.c
*
* Original Author 	: found on the internet
* Modified by		: Jiztom  
* Modified on		:17.02.2017
*/
#include "main.h"

///////global variable //////////////////////////////////////
int state = 0;
//int socket_fd;

long timespec_diff(struct timespec a, struct timespec b)
{
  long diff;
  diff = (a.tv_sec - b.tv_sec);
  return diff;
}

int main()
{
    struct sockaddr_in server;
    struct sockaddr_in dest;
    struct timespec start;
    struct timespec end;
    long t_diff;
    int status, socket_fd, client_fd,num;
    socklen_t size;
	int i=0;

    char buffer[1024];
    char buff[100];
    char buff2[100];
//  memset(buffer,0,sizeof(buffer));

  
    unsigned char code;
    unsigned int value;

/////////////variables for inner loop////////////
	int language;
	int condition = 0;
	int detect = 0;
	int lock_condition = 0;
	int signal = 0;
	
	socket_fd = init_tcp();
	if (!socket_fd) exit(1);


    while(1) 
    {

        size = sizeof(struct sockaddr_in);
        
      /*  if (accept_client(socket_fd)==-1)
        {
			fprintf(stderr, "Accept did not work\n");
			exit(1);
		}*/

		if ((client_fd = accept(socket_fd, (struct sockaddr *)&dest, &size))==-1 ) 
		{
			perror("accept");
			return(-1);
		}

        
        
        printf("\nServer got connection from client %s\n", inet_ntoa(dest.sin_addr));
        clock_gettime(CLOCK_MONOTONIC_RAW, &start); 

        while(1) 
        {
			if(condition == 0) ////language selection/////
			{
				printf(" Please choose the language to be selected");
				printf(" \n 1. English \t 2. German \n");
				printf(" your option please : \n"); 
				scanf("%d", & language );
				printf("\n");
				sendd(client_fd , HMI_READY );
				/////----->>>>> send signal to the EB guide for language selection
				condition++;
			}
			if(condition == 1)////// plug detection and intialization////// 
			{
				printf(" \n please insert the plug into the system \n");
				init_statemachine();
				detect = fire_event(CABLE_DETECTED , 0 ,client_fd);
				if( detect == 1)
				{
					printf("\n the cable has been connected and the car has been detected");
					///////the signal from the EVSE for the lock status ////////					
					signal = receivee(socket_fd , &code, &value);
					if(fire_event( CABLE_LOCK , signal,client_fd) == 1)
					{
						condition++;
					}
					else
					{
						init_statemachine();
						condition = 1;
					}
				}
				else
					printf(" \n the cable has not been detected continue loop" );
			}
			if(condition == 2)
			{
				printf("\n the vehicle status is :");
				//signal =0;/////signal for the protocol detected////////////
				signal = receivee(client_fd , &code, &value);
				
				fire_event( PROTOCOL_DETECT , code , client_fd);
				condition++;
				/*if (code == ISO15118_DETECTED)
				{
				printf("\n the ISO 15118 was detected and proceeding to next state \n");
				fire_event(PROTOCOL_DETECT , ISO15118_DETECTED ,client_fd);
				condition++;
				}
				else if(code == IEC61851_DETECTED )
				{
					printf("\nthe IEC 61851 was detected\n");
					fire_event(PROTOCOL_DETECT, IEC61851_DETECTED,client_fd);
					////condition = //////////////// ;
				}
				else if(code == MANUAL_CHARGING)
				{
					printf("\n no protocol detected will need to move towards manual charging\n");
					fire_event(PROTOCOL_DETECT, MANUAL_CHARGING,client_fd);					
					//////condition = //////////
				}
				else /// is this even required?
				{
					printf ("\n error in detection. Lost communication\n resetting connection \n");
					init_statemachine();
					condition =0;
				}*/
			}
			
			if(condition == 3)
			{
				printf("\n the protocol has been detected . Now initiating the information and account details process\n"); 
				fire_event(REGISTER , 0 , client_fd);
				printf("\n the payment and the initial requirement has been done\n");
				fire_event(AUTHORIZATION , 0 , client_fd);
				condition++;
			}
			
			if( condition == 4)
			{
				printf(" \n the car is ready for charging.\n\n please press the button to charge the vehicle\n");
				//fire_event(START_CHARGE, 0 , client_fd);
				//do
				//{
				fire_event(CHARGING_STATUS , 0 , client_fd);
				fire_event(MANUAL_STOP,0,client_fd);	
				//}while((fire_event(FULL_CHARGE,0 , client_fd)|| fire_event(MANUAL_STOP,0,client_fd)) == 1);
				printf("\nthe car has stopped charging");
				printf("\nthe payment details are as follows:");
				fire_event(METER_RECEIPT , 0,client_fd);
				condition++;
			}
			
			if(condition == 5)
			{
				printf("\nThe payment will be processed now");
				///////try the payment using the details logged before////
				fire_event(INITIATE_PAYMENT,0,client_fd);
				fire_event(PAYMENT_SUCESSFUL,0,client_fd);
				condition++;
				/*if ( fire_event(INITIATE_PAYMENT , 0 ,client_fd) == 1)
				{
					printf(" the payment was sucessful");
					fire_event(PAYMENT_SUCESSFUL , 0,client_fd);
					condition++;
				}
				else 
				{
					printf(" the payment was unsucessful\n");
					fire_event(PAYMENT_UNSUCESSFUL,0,client_fd);
					//condition = ;////special error case
				}*/
			}
			
			if (condition == 6)
			{
				printf("\n the cable will be unlocked now ");
				fire_event(CABLE_UN_LOCK , 0,client_fd);
				condition = 0;
				printf("\n the charging process has been completed \n Thankyou please use me again\n\n\n\n");
				printf("++++++++++++++++++++++++++++++++++++\n");
			}
		} //End of Inner While...
        //Close Connection Socket
        close(client_fd);
    } //Outer While

    close(socket_fd);
    return 0;
}

//End of main


//unsigned char receivee(int client_fd,unsigned char *code, unsigned int *value);
