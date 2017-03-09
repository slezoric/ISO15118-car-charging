/*
 * ISO_main.h
 *
 *  Created on: 03.01.2016
 *      Author: melanie
 */

#ifndef ISO_COMM_ISO_EV_MAIN_H_
#define ISO_COMM_ISO_EV_MAIN_H_

# define CODE_EXAMPLE_SOFTWARE 0
# define CODE_EXAMPLE_HARDWARE 1
# define CODE_EXAMPLE CODE_EXAMPLE_HARDWARE



# include "v2gtp.h"
# include "Convert.h"
# include "appHandEXIDatatypes.h"
# include "appHandEXIDatatypesEncoder.h"
# include "appHandEXIDatatypesDecoder.h"
# include "EXITypes.h"
# include "clientsockets.h"

#define BUFFER_SIZE 256

/*Start ISO Communication
 * @params: socket_nummer from ethernet communikation*/
int ISO_start(int socket_nummer, int fd);

int appHandshake(int socket_nummer);

void printBinaryArray(uint8_t* byte, uint16_t len);

void printASCIIString(exi_string_character_t* string, uint16_t len);

int ac_charging(int socket_nummer, int fd);

int dc_charging(int socket_nummer, int fd);
void printACEVSEStatus(struct v2gAC_EVSEStatusType* status);
void printDCEVSEStatus(struct v2gDC_EVSEStatusType* status);


#endif /* ISO_COMM_ISO_EV_MAIN_H_ */
