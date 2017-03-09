/*
*	transfer.c
*
*	Author		: Jiztom
*	Created on	: 17.02.2017
*	Modified on	: 17.02.2017
*/

#include "transfer.h"

int status, socket_fd, client_fd,num;
    struct sockaddr_in server;
    struct sockaddr_in dest;
        socklen_t size;

int init_tcp()
{

    int yes =1;

	if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0))== -1) {
        fprintf(stderr, "Socket failure!!\n");
        return(0);
    }

    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("setsockopt");
        return(0);
    }
    memset(&server, 0, sizeof(server));
    memset(&dest,0,sizeof(dest));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY; 
    if ((bind(socket_fd, (struct sockaddr *)&server, sizeof(struct sockaddr )))== -1)    
    { //sizeof(struct sockaddr) 
        fprintf(stderr, "Binding Failure\n");
        return(0);
    }

    if ((listen(socket_fd, BACKLOG))== -1)
    {
        fprintf(stderr, "Listening Failure\n");
        return(0);
    }

    return socket_fd;
}

int accept_client(int sfd)
{
    if ((client_fd = accept(socket_fd, (struct sockaddr *)&dest, &size))==-1 ) 
    {
        perror("accept");
        return(-1);
    }
    else fprintf(stdout,"Accepted %s\n",inet_ntoa(dest.sin_addr));
    return(client_fd);
}

unsigned char receivee(int client_fd,unsigned char *code, unsigned int *value)
{

		int num;
		static char buffer[20+1];
		if ((num = recv(client_fd, buffer, 1024,MSG_DONTWAIT))== -1) {
 
    	}
    	else if (num == 0) 
		{
    		printf("Connection closed\n");
        	//So I can now wait for another client
        	return(0);
    	}
    	buffer[num] = '\0';
		if (num > 0)
		{	printf("Len: %d\n",num);
			printf("Server:Msg Received %s\n", buffer);
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
