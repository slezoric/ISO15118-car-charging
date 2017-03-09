/*
*	transfer.c for EVSE
*
*	Author		: Jiztom
*	Created on	: 17.02.2017
*	Modified on	: 08.03.2017
*/

#include "transfer.h"

void init_tcp()
{
	int num;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in remoteaddr;
	remoteaddr.sin_family = AF_INET;
	remoteaddr.sin_addr.s_addr = inet_addr("192.168.37.253");
	remoteaddr.sin_port = htons(PORT);
	connect(sockfd, (struct sockaddr *)&remoteaddr, sizeof(remoteaddr));
}

unsigned char receivee(int client_fd,unsigned char *code, unsigned int *value)
{

		int num;
		static char buffer[20+1];
		if ((num = recv(client_fd, buffer, 1024,MSG_DONTWAIT))== -1) {
			printf("error");
    	}
    	else if (num == 0) 
		{
    		printf("Connection closed\n");
        	////So I can now wait for another client
        	return(0);
    	}
    	buffer[num] = '\0';
		if (num > 0)
		{	printf("Len: %d\n",num);
			printf("Server:Msg Received %d\n", buffer[0]);
		}
    	*code = buffer[0];
    	*value= (unsigned int)buffer[1]<<8 | buffer[2];
		return 1;

}

char sendd(int client_fd , char data)
{

	char data_to_send[1];
	data_to_send[0]=data;
	if ((send(client_fd,data_to_send, strlen(data_to_send),0))== -1) 
                {
                     fprintf(stderr, "Failure Sending Message\n");
                     close(client_fd);
                     return(0);
                }

    printf("Server:Msg being sent: :%d\n",data);
    return(1);
}
