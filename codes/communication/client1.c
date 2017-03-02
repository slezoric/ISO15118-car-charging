/*
*  	client1.c
*
*	Author 		: Jiztom	
*	Created on	: 18.02.2017
*	Modified on	: 18.02.2017
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "transfer.h"

#define PORT 3490
#define MAXSIZE 1024

void main()
{
	char buff[1024];
	char buffer[1024];
	int num;
	// Error checking omitted for expository purposes
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	// Bind to a specific network interface (and optionally a specific local port)
	struct sockaddr_in localaddr;
	localaddr.sin_family = AF_INET;
	localaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	localaddr.sin_port = 0;  // Any local port will do
	bind(sockfd, (struct sockaddr *)&localaddr, sizeof(localaddr));

	// Connect to the remote server
	struct sockaddr_in remoteaddr;
	remoteaddr.sin_family = AF_INET;
	remoteaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	remoteaddr.sin_port = htons(PORT);
	connect(sockfd, (struct sockaddr *)&remoteaddr, sizeof(remoteaddr));
	while(1) {
        printf("Client: Enter Data for Server:\n");
        fgets(buffer,MAXSIZE-1,stdin);
        sendd(sockfd , buffer);
        receivee(sockfd);
    }
    close(sockfd);

}//End of main