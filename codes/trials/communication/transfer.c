/*
*	transfer.c
*
*	Author		: Jiztom
*	Created on	: 17.02.2017
*	Modified on	: 17.02.2017
*/

#include "transfer.h"

char *receivee( int client_fd)
{
	//while(1)
	//{
		int num;
		static char buffer[20+1];
		if ((num = recv(client_fd, buffer, 1024,0))== -1) {
    		perror("recv");
        	exit(1);
    	}
    	else if (num == 0) 
		{
    		printf("Connection closed\n");
        	//So I can now wait for another client
        	return(0);
    	}
    	buffer[num] = '\0';
    	printf("Server:Msg Received %s\n", buffer);
		return buffer;
	//}
}

char *sendd(int client_fd , char data[])
{
	int i;
	if ((send(client_fd,data, strlen(data),0))== -1) 
                {
                     fprintf(stderr, "Failure Sending Message\n");
                     close(client_fd);
                     return(0);
                }
	i =strlen (data);
    printf("Server:Msg being sent: %s\nNumber of bytes sent:%d\n",data,i);
}