/****************************************************************/
/* Dateiname	: sockets.c										*/
/* Beschreibung	: Server Programm des Sockets akzeptiert eine  	*/
/*				  TCP Verbindung und sendet und empfängt Daten	*/
/****************************************************************/


#include "clientsockets.h"

# include <stdio.h>
# include <sys/types.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <sys/socket.h>
# include <netinet/in.h>

#define BUFFER_SIZE 256

int socket_clientconnect(int socket_nummer, char ip_adresse[],unsigned int portnummer){

	struct sockaddr_in adresse;
	int ergebnis;
	int laenge;

	adresse.sin_family = AF_INET;
	adresse.sin_addr.s_addr = inet_addr(ip_adresse);
	adresse.sin_port = htons(portnummer);
	laenge = sizeof(adresse);
	ergebnis = connect(socket_nummer, (struct sockaddr*)&adresse, laenge);

return ergebnis;

}

void socket_close(int socket_nummer){
	printf("\n Client: close()...");
	close(socket_nummer);
	printf("\nProgramm beendet\n\n");
}

int transmit_message(int socket_number, bitstream_t* Output){
		int errn, i;
		uint8_t buffer;
		uint8_t capacity;
		uint8_t data[BUFFER_SIZE];
		uint16_t size;
		uint16_t pos;

		printf("send stream... ");

		buffer = Output->buffer;
		errn = send(socket_number, & buffer, sizeof ( buffer), 0);

		if (errn == sizeof(buffer)){
		capacity = Output->capacity;
		errn = send(socket_number, & capacity, sizeof ( capacity), 0);
		}

		if (errn == sizeof(capacity)){
		for (i=0; i<BUFFER_SIZE; i++){
			data[i] = Output->data[i];
		}
		errn = send(socket_number, & data, BUFFER_SIZE, 0);
		}

		if (errn == BUFFER_SIZE){
		pos = *Output->pos;
		errn = send(socket_number, &pos, sizeof(pos),0);
		}

		if (errn == sizeof(pos)){
		size = Output->size;
		errn = send(socket_number, & size, sizeof ( size), 0);
		}
		printf("...sent \n");
		if(errn == sizeof(size)){
		return (0);
		}else{
			return (errn);}
	}


int receive_message(int socket_number, bitstream_t* Input){
	int errn, i;
	printf("receive stream...");

	uint8_t buffer;
	uint8_t capacity;
	uint8_t data[BUFFER_SIZE];
	uint16_t size;
	uint16_t pos;


	errn = recv(socket_number, &( buffer), sizeof( buffer), 0);
	Input->buffer = buffer;
	while(errn != sizeof( buffer));

	errn = recv(socket_number, & capacity, sizeof( capacity), 0);
	while(errn != sizeof( capacity));
	Input->capacity = capacity;

	errn = recv(socket_number, & data, sizeof(data), 0);
	while(errn != sizeof( data));

	for (i=0; i<sizeof(data); i++){
		Input->data[i] = data[i];
	}

	errn = recv(socket_number, & pos, sizeof( pos), 0);
	while(errn != sizeof( pos));
	*Input->pos = pos;

	errn = recv(socket_number, & size, sizeof( size), 0);
	while(errn != sizeof( size));
	Input->size = size;

	printf("...received stream \n");

	return (0);
}
