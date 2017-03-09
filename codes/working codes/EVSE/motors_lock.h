/*
 * cablelock.h
 *
 *  Created on: 12.11.2015
 *      Author: melanie
 */

#ifndef MOTORS_LOCK_H_
#define MOTORS_LOCK_H_



/* Parameter
 * cable nummer 1 for 0x17 or 2 for 0x18
 * control code
 * 		0 for unlock
 * 		1 for lock
 * 		2 for query status
 * 		3...255 Reserved
 */
int lock_cable(int fd, unsigned int cable_nummer, unsigned int control_code);
int get_lock_motor_fault(int fd);


#endif /* MOTORS_LOCK_H_ */
