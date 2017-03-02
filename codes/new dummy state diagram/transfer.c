/*
*	transfer.c for client
*
*	Author		: Jiztom
*	Created on	: 18.02.2017
*	Modified on	: 18.02.2017
*/

#include "transfer.h"

char *receivee( int sockfd)
{
	int num;
	static char buffer[1024];
    char buff[1024];
	if ((send(sockfd,buffer, strlen(buffer),0))!= -1)
	{
		//intf("Client:Message being sent: %s\n",buffer);
        num = recv(sockfd, buffer, sizeof(buffer),0);
                if ( num <= 0 )
                {
                        printf("Either Connection Closed or Error\n");
                        //Break from the While
                        return(0);
                }

        buff[num] = '\0';
        //intf("Client:Message Received From Server -  %s\n",buffer);
		return buffer;			
	}
	
}

char *sendd(int sockfd , char data[])
{
	if ((send(sockfd,data, strlen(data),0))== -1) 
	{
                fprintf(stderr, "Failure Sending Message\n");
                close(sockfd);
                return(0);
    }
}