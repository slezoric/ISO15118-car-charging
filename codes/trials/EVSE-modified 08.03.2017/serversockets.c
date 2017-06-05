/****************************************************************/
/* Dateiname	: sockets.c										*/
/* Beschreibung	: Server Programm des Sockets akzeptiert eine  	*/
/*				  TCP Verbindung und sendet und empfängt Daten	*/
/****************************************************************/


#include "serversockets.h"

# include <stdio.h>
# include <sys/types.h>
# include <arpa/inet.h>
# include <unistd.h>

#define BUFFER_SIZE 256

int socket_serverconnect(unsigned int portnummer){
	int server_socket, laenge;
	struct sockaddr_in serverinfo;

	printf("\nEVServer: socket()...");
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	serverinfo.sin_family = AF_INET;
	serverinfo.sin_addr.s_addr = INADDR_ANY;
	serverinfo.sin_port = htons(portnummer);
	laenge = sizeof(serverinfo);

	printf("\n EVServer: bind()...");

	bind(server_socket, (struct sockaddr*)&serverinfo, laenge);
	printf("\n Server: listen()...");
	printf("\n Server an Port %d wartet...\n", portnummer);
	listen(server_socket, 3);
	return server_socket;
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
