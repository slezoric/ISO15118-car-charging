/*
*	transfer.h
*
*	Author		: Jiztom
*	Created on	: 17.02.2017
*	Modified on	: 17.02.2017
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

char *sendd(int client_fd , char data[]);
char *receivee(int client_fd);

#endif /* TRANSFER_H_*/