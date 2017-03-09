/*
 * hardware.h
 *
 *  Created on: 31.03.2016
 *      Author: melanie
 */

#ifndef HARDWARE_HARDWARE_H_
#define HARDWARE_HARDWARE_H_


/**
 * \brief 		locked the charging cable to allow removing the plug to only after "Session Stop"
 *
 * \param
 * \return      errn	0: locking successful
 *
 */
int Lock_Cable(int fd);

/**
 * \brief 		unlock the charging cable to allow removing the plug after "Session Stop"
 *
 * \param
 * \return      errn	0: locking successful
 *
 */
int Unlock_Cable(int fd);




/**
 * \brief 		close the Contractors for start charging
 *
 * \param
 * \return      errn	0: closing successful
 *
 */
int Close_Contractors(int fd);

/**
 * \brief 		open the Contractors for end charging
 *
 * \param
 * \return      errn	0: opening successful
 *
 */
int Open_Contractors(int fd);

#endif /* HARDWARE_HARDWARE_H_ */
