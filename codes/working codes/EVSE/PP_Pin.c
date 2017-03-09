/*
 * PP_Pin.c
 *
 *  Created on: 19.11.2015
 *      Author: melanie
 */

# include <stdio.h>
# include <unistd.h>
# include "interface.h"
# include "PP_Pin.h"
# define PP_VOLTAGE_CONVERT 0.029

int PPacivate(int fd, int Controlvalue)
{
	char data[6];
	char result[6];
	int state = 0;
	data[0]=0x02;
	data[1]=0x04;
	data[2]=0x00;
	data[3]=0x50;
	data[4]= Controlvalue;
	data[5]=build_checksum(data,5);
	uart_send_data(fd,data,6);
	read(fd,result,6);
	if((result[0]==0x02)&& (result[3] == 0xD0))
	{
		if (result[4]==0)state =1; //printf("No errors ");
		else state = -1; //printf("Invalid Parameter in PP activate/n");
	}
	else
	{
		STX_Error(fd, result);
		state = PPacivate(fd, Controlvalue);
	}
	return state;
}
int PPpullup(int fd, int Control)
{
	char data[6];
	char result[6];
	int state = 0;
	data[0]=0x02;
	data[1]=0x04;
	data[2]=0x00;
	data[3]=0x51;
	data[4]= Control;
	data[5]=build_checksum(data,5);
	uart_send_data(fd,data,6);
	read(fd,result,6);
	if((result[0]==0x02)&& (result[3] == 0xD1)) state = result[4];
	else
	{
		STX_Error(fd, result);
		PPpullup(fd, Control);
	}
	return state;
}
double PPVol(int fd)
{
	char data[5];
	char result[7];
	double Vol = 0;
	data[0]=0x02;
	data[1]=0x03;
	data[2]=0x00;
	data[3]=0x52;
	data[4]=build_checksum(data,4);
	uart_send_data(fd,data,5);
	read(fd,result,7);
	if((result[0]==0x02)&& (result[3] == 0xD2))
	{
		Vol = PP_VOLTAGE_CONVERT * ((result[5]<<8)|result[4]);
	}
	else
	{
		STX_Error(fd, result);
		Vol = PPVol(fd);
	}
	return Vol;
}
