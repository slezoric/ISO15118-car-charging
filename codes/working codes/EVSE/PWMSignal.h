/*
 * PWMSignal.h
 *
 *  Created on: 30.10.2015
 *      Author: melanie
 */

#ifndef PWMSIGNAL_H_
#define PWMSIGNAL_H_

# define PWM_FREQ 1000 	//Frequenz des erzeugten PWM Signals[Hz]
# define CP_VOLTAGE_CONVERT 0.029

int control_pwm(int fd, unsigned char control_code);
int set_pwm(int fd, short DutyCycle);
int get_pwm(int fd);

double get_Ucp(int fd);
int set_Ucp(int fd, unsigned int control_code);


#endif /* PWMSIGNAL_H_ */
