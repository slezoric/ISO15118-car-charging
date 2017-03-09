/*
 * PP_Pin.h
 *
 *  Created on: 19.11.2015
 *      Author: melanie
 */

#ifndef PP_PIN_H_
#define PP_PIN_H_

int PPacivate(int fd, int Controlvalue);
int PPpullup(int fd, int Control);
double PPVol(int fd);


#endif /* PP_PIN_H_ */
