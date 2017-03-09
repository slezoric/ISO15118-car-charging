/*
 *  switchpi.h
 * 
 *  header file for switchpi.c
 * 
 * 	Author 		: Jiztom
 * 	Created on	: 01.03.2017
 * modified on	:
 */
 
 
# include <stdio.h>
# include <netinet/in.h>
# include <sys/types.h>
# include <sys/socket.h>
#include "transfer.h" 


#ifndef SWITCHPI_H_
#define SWITCHPI_H_

int fire_event ( int event, int param , int socket_fd);
unsigned char get_state();
void init_statemachine();

#endif /*SWITCHPI_H_*/
 
