/*
*	transfer.h for EVSE
*
*	Author		: Jiztom
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


#ifndef TRANSFER_H_
#define TRANSFER_H_

# define PORT 3490
# define MAXSIZE 1024

char buff[1024];
char buffer[1024];
int sockfd;
unsigned char code;
unsigned int value;

void init_tcp();
char sendd(int sockfd , char data);
unsigned char receivee(int client_fd,unsigned char *code, unsigned int *value);

#endif /* TRANSFER_H_*/
