/*
 * interface.h
 *
 *  Created on: 30.10.2015
 *      Author: melanie
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_


# include <termios.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/signal.h>
# include <sys/types.h>

unsigned char build_checksum(char* data, int length);
int uart_send_data(int fd, char* data,int length);
int open_serial(void);
void STX_Error(int fd, char* result);


#endif /* INTERFACE_H_ */
