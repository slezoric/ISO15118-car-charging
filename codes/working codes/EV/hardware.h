/*
 * hardware.h
 *
 *  Created on: 31.03.2016
 *      Author: melanie
 */

#ifndef HARDWARE_HARDWARE_H_
#define HARDWARE_HARDWARE_H_

/*
 * locked the charging cable to allow removing the plug to only after "Session Stop"
 */
int Lock_Cable(int fd);

/*
 * unlock the charging cable to allow removing the plug after "Session Stop"
 */
int Unlock_Cable(int fd);


#endif /* HARDWARE_HARDWARE_H_ */
