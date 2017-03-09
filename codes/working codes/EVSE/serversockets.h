/****************************************************************/
/* Dateiname	: sockets.h										*/
/* Beschreibung	: Server Programm des Sockets akzeptiert eine  	*/
/*				  TCP Verbindung und sendet und empfängt Daten	*/
/****************************************************************/

# include "EXITypes.h"

int socket_serverconnect(unsigned int portnummer);

void socket_close(int socket_nummer);

int transmit_message(int socket_number, bitstream_t* Output);


int receive_message(int socket_number, bitstream_t* Input);
