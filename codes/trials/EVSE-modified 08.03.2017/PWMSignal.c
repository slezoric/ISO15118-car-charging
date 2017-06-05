/*
 * PWMSignal.c
 *
 *  Created on: 30.10.2015
 *      Author: melanie
 */


# include <stdio.h>
# include <unistd.h>
# include "PWMSignal.h"
# include "interface.h"


int get_pwm(int fd)
{
	char data[5];
	char result[9];
	int duty_cycle=0;
	data[0]=0x02;
	data[1]=0x03;
	data[2]=0x00;
	data[3]=0x10;
	data[4]=build_checksum(data,4);
	uart_send_data(fd,data,5);
	read(fd,result,9);
	if((result[0]==0x02)&& (result[3] == 0x90))
	{
		duty_cycle = (result[7]<<8)|result[6];
		//printf("gemessene Frequenz %d Hz\n",(result[5]<<8)|result[4]);
		//printf("Duty cycle %d Hz \n",duty_cycle);
	}
	else
	{
		STX_Error(fd, result);
		duty_cycle = get_pwm(fd);
	}
	return duty_cycle;
}

int set_pwm(int fd, short DutyCycle)
{
	char data[9];
	char result[6];
	int state =0;
	data[0]=0x02;
	data[1]=0x07;
	data[2]=0x00;
	data[3]=0x11;
	data[4]=(unsigned char)(PWM_FREQ & 0xFF);		//1kHz lt Iso 15118
	data[5]=(unsigned char)((PWM_FREQ>>8) & 0xFF);
	data[6]=(unsigned char)(DutyCycle & 0xFF);
	data[7]=(unsigned char)((DutyCycle>>8) & 0xFF);
	data[8]=build_checksum(data,8);
	uart_send_data(fd,data,9);
	read(fd,result,6);
	if((result[0]==0x02)&& (result[3] == 0x91)) state = result[4];//Response Error Code
	else
	{
		STX_Error(fd, result);
		state = set_pwm(fd, DutyCycle);
	}

	return state;
}
int control_pwm(int fd, unsigned char control_code)
{
	char data[6];
	char result[6];
	int state =0;
	data[0]=0x02;
	data[1]=0x04;
	data[2]=0x00;
	data[3]=0x12;
	data[4]=control_code;
	data[5]=build_checksum(data,5);
	uart_send_data(fd,data,6);
	read(fd,result,6);
	if((result[0]==0x02)&& (result[3] == 0x92)) state = result[4]; //Response Code
	else
	{
		STX_Error(fd, result);
		state = control_pwm(fd, control_code);
	}
	return state;
}
double get_Ucp(int fd)
{
	char data[5];
	char result[9];
	double Neg_Voltage =0;
	double Pos_Voltage=0;
	data[0]=0x02;
	data[1]=0x03;
	data[2]=0x00;
	data[3]=0x14;
	data[4]=build_checksum(data,4);
	uart_send_data(fd,data,5);
	read(fd,result,9);
	if((result[0]==0x02)&& (result[3] == 0x94))
	{
		Pos_Voltage = CP_VOLTAGE_CONVERT * ((result[5]<<8)|result[4]);
		printf("Pos Voltage %f V",Pos_Voltage);
		Neg_Voltage = CP_VOLTAGE_CONVERT * ((65535 -((result[7]<<8)|result[6]))-100); //Bitumkehrung
		printf(" Neg Voltage %f V\n",Neg_Voltage );
	}
	else
	{
		STX_Error(fd, result);
		Pos_Voltage = get_Ucp(fd);
	}
	return Pos_Voltage;
}
int set_Ucp(int fd, unsigned int control_code)
{
	char data[6];
	char result[6];
	int state =0;
	data[0]=0x02;
	data[1]=0x04;
	data[2]=0x00;
	data[3]=0x15;
	data[4]=control_code;
	data[5]=build_checksum(data,5);
	uart_send_data(fd,data,6);
	read(fd,result,6);
	if((result[0]==0x02)&& (result[3] == 0x95)) state = result[4];
	else
	{
		STX_Error(fd, result);
		state = set_Ucp(fd, control_code);
	}
	return state;
}
