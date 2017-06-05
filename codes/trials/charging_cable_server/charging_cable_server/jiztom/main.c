/*
 *  main.c
 * 
 * 	Author 		: Jiztom Franics K	
 * 	Created on	: 01.03.2017 
 *  Modified on	: 01.03.2017
 */

/*
*  server.c
*
* Original Author 	: found on the internet
* Modified by		: Jiztom  
* Modified on		:17.02.2017
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "transfer.h"

#define PORT 3490
#define BACKLOG 10


long timespec_diff(struct timespec a, struct timespec b)
{
  long diff;
  diff = (a.tv_sec - b.tv_sec);
  return diff;
}

int main()
{
    struct sockaddr_in server;
    struct sockaddr_in dest;
    struct timespec start;
    struct timespec end;
    long t_diff;
    int status,socket_fd, client_fd,num;
    socklen_t size;
	int i=0;

    char buffer[1024];
    char buff[100];
    char buff2[100];
//  memset(buffer,0,sizeof(buffer));
    int yes =1;
    char nivas[1024] = "hello world";
    unsigned char code;
    unsigned int value;


    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0))== -1) {
        fprintf(stderr, "Socket failure!!\n");
        exit(1);
    }

    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("setsockopt");
        exit(1);
    }
    memset(&server, 0, sizeof(server));
    memset(&dest,0,sizeof(dest));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY; 
    if ((bind(socket_fd, (struct sockaddr *)&server, sizeof(struct sockaddr )))== -1)    
    { //sizeof(struct sockaddr) 
        fprintf(stderr, "Binding Failure\n");
        exit(1);
    }

    if ((listen(socket_fd, BACKLOG))== -1)
    {
        fprintf(stderr, "Listening Failure\n");
        exit(1);
    }

    while(1) 
    {

        size = sizeof(struct sockaddr_in);

        if ((client_fd = accept(socket_fd, (struct sockaddr *)&dest, &size))==-1 ) 
        {
            perror("accept");
            exit(1);
        }
        
        printf("Server got connection from client %s\n", inet_ntoa(dest.sin_addr));
        clock_gettime(CLOCK_MONOTONIC_RAW, &start); 

        while(1) 
        {
			buff = receivee(client_fd,&code,&value); // -----> the calling function
			//num=recv(client_fd,buff,100,MSG_DONTWAIT); // -------> directly recieving data
	
			if (num>0)
			{
				sprintf(buff2,"Why are you sendig me %s", buff);
                clock_gettime(CLOCK_MONOTONIC_RAW, &start); 
                sendd(client_fd , buff2); //-----> the signal being send
			}
            clock_gettime(CLOCK_MONOTONIC_RAW, &end); 
			t_diff = timespec_diff(end, start);
			printf("Difference %d\n",t_diff);
			if (t_diff % 5==0)
            {
				sprintf(buff2,"You fool forgot to send something");
                sendd(client_fd , buff2); //-----> the signal being send
            } 
            fprintf(stdout,"Running....\n");
		
        } //End of Inner While...
        //Close Connection Socket
        close(client_fd);
    } //Outer While

    close(socket_fd);
    return 0;
}

//End of main


//unsigned char receivee(client_fd,unsigned char *code, unsigned int *value)
