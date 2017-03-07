/*
 *  main.c
 * 
 * 	Author 		: Jiztom Franics K	
 * 	Created on	: 01.03.2017 
 *  Modified on	: 01.03.2017
 */

/*
*  server.c
*
* Original Author 	: found on the internet
* Modified by		: Jiztom  
* Modified on		:17.02.2017
*/


///////global variable //////////////////////////////////////
int state = 0;

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
    int status,socket_fd, client_fd,num;
    socklen_t size;
	int i=0;

    char buffer[1024];
    char buff[100];
    char buff2[100];
//  memset(buffer,0,sizeof(buffer));
    int yes =1;
  
    unsigned char code;
    unsigned int value;

/////////////variables for inner loop////////////
	int language;
	int condition = 0;
	int detect = 0;
	int lock-condition = 0;

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0))== -1) {
        fprintf(stderr, "Socket failure!!\n");
        exit(1);
    }

    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("setsockopt");
        exit(1);
    }
    memset(&server, 0, sizeof(server));
    memset(&dest,0,sizeof(dest));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY; 
    if ((bind(socket_fd, (struct sockaddr *)&server, sizeof(struct sockaddr )))== -1)    
    { //sizeof(struct sockaddr) 
        fprintf(stderr, "Binding Failure\n");
        exit(1);
    }

    if ((listen(socket_fd, BACKLOG))== -1)
    {
        fprintf(stderr, "Listening Failure\n");
        exit(1);
    }

    while(1) 
    {

        size = sizeof(struct sockaddr_in);

        if ((client_fd = accept(socket_fd, (struct sockaddr *)&dest, &size))==-1 ) 
        {
            perror("accept");
            exit(1);
        }
        
        printf("Server got connection from client %s\n", inet_ntoa(dest.sin_addr));
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
				/////----->>>>> send signal to the EB guide for language selection
				condtion++;
			}
			if(condition == 1)////// plug detection and intialization////// 
			{
				printf(" \n please insert the plug into the system \n");
				init_statemachine();
				detect = fire_event(CABLE_DETECTED , 0);
				if( detect == 1)
				{
					printf("\n the cable has been connected and the car has been detected");
					///////the signal from the EVSE for the lock status ////////					
					// receiveee ();
					if(fire_event( CABLE_LOCK , signal) == 1)
					{
						condititon++;
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
			if(condtion == 2)
			{
				printf("\n the vehicle status is :");
				/////signal for the protocol detected////////////
				// receivee
				if (/* ISO 15118*/)
				{
				printf("\n the ISO 15118 was detected and proceeding to next state \n");
				fire_event(PROTOCOL_DETECT , ISO15118_DETECTED);
				condition = 3;
				}
				else if(/* IEC 61851*/ )
				{
					printf("\nthe IEC 61851 was detected\n"):
					fire_event(PROTOCOL_DETECT, IEC61851_DETECTED);
					////condition = //////////////// ;
				}
				else if(/* Manual charging*/)
				{
					printf("\n no protocol detected will need to move towards manual charging\n");
					fire_event(PROTOCOL_DETECT, MANUAL_CHARGING);					
					//////condition = //////////
				}
				else /// is this even required?
				{
					printf ("\n error in detection. Lost communication\n resetting connection \n");
					init_statemachine();
					condition =0;
				}
			}
			
			if(condition == 3)
			{
				printf("\n the protocol has been detected . Now initiating the information and account details process\n"); 
				fire_event(REGISTER , 0);
				printf("\n the payment and the initial requirement has been done\n");
				fire_event(AUTHORIZATION , 0);
				condition++;
			}
			
			if( condition == 4)
			{
				printf(" \n the car is ready for charging.\n\n please press the button to charge the vehicle\n");
				fire_event(START_CHARGE,0);
				do
				{
					fire_event(CHARGING_STATUS , 0);
					
				}while((fire_event(FULL_CHARGE,0)|| fire_event(MANUAL_STOP,0)) == 1);
				printf("the car has stopped charging");
				printf("the payment details are as follows:");
				fire_event(METER_RECEIPT , 0);
				condition++;
			}
			
			if(condition == 5)
			{
				printf("The payment will be processed now");
				///////try the payment using the details logged before////
				if ( fire_event(INITIATE_PAYMENT , 0 ) == 1)
				{
					printf(" the payment was sucessful");
					fire_event(PAYMENT_SUCESSFUL , 0);
					condition++;
				}
				else 
				{
					printf(" the payment was unsucessful\n");
					fire_event(PAYMENT_UNSUCESSFUL,0);
					condition = ;////special error case
				}
			}
			
			if (condition == 6)
			{
				printf(" the cable will be unlocked now ");
				fire_event(CABLE_UN_LOCK , 0);
				condition = 0;
				printf(" the charging process has been completed \n Thankyou please use me again");
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
