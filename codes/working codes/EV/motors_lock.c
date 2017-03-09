/*
 * cablelock.c
 *
 *  Created on: 12.11.2015
 *      Author: melanie
 */

# include "motors_lock.h"
# include "interface.h"
# include <stdio.h>
# include <unistd.h>



int lock_cable(int fd, unsigned int cable_nummer, unsigned int control_code)
{
	char data[6];
	char result[6];
	int state = 0;
	data[0]=0x02;
	data[1]=0x04;
	data[2]=0x00;
	if(cable_nummer == 1)data[3]=0x17;
	else data[3]=0x18;
	data[4] = control_code;
	data[5]=build_checksum(data,5);
	uart_send_data(fd,data,6);
	read(fd,result,6);
	if((result[0]==0x02)&& ((result[3] == 0x97)|(result[3] == 0x98)))
	{
		if (((control_code < 2) && (result[4] == control_code))|(control_code == 2)){
		state =result[4];
			//printf("Lock Status %x\n",(result[4]));
		}
		else printf("Lock Cable: Fehler bei Ausführung \n");
	}
	else
	{
		STX_Error(fd, result);
		state = lock_cable(fd, cable_nummer, control_code);
	}
	return state;
}
int get_lock_motor_fault(int fd)
{
	char data[5];
	char result[6];
	int state =0;
	data[0]=0x02;
	data[1]=0x03;
	data[2]=0x00;
	data[3]=0x1A;
	data[4]=build_checksum(data,4);
	uart_send_data(fd,data,5);
	read(fd,result,6);
	if((result[0]==0x02) && (result[3] == 0x9A))
	{
		if (result[4] == 0)state =0;//printf ("motor fault pin not activated\n");
		else state =1; // printf("motor fault pin activated\n");
	}
	else
	{
		STX_Error(fd, result);
		state = get_lock_motor_fault(fd);
	}
	return state;
}
