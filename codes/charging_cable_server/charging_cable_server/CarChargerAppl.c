
/// \file TCPServer.c
/// \brief Application example of TCP/IP communication in the C programming  for Jiztom.
/// \date 02.03.2017
/// \author Daniel Tuchscherer

#include "TCPSocket.h"
#include <stdio.h> //< for printing purposes

/// TCP/IP port the clients will connect to and the server is listening on.
#define TCP_PORT (3490U)

static const char* CLIENT_IP = "255.255.255.0";

////////////////////////////////////////////////////////////////////////////////
int main()
{
    // first create a socket to exchange data via TCP/IP
    // socket must be of type AF_INET (IPv4 Internet protocols) and SOCK_STREAM for TCP/IP
#ifdef DEBUG
    printf("Creating a TCP socket... ");
#endif
    const Handle handle = create_tcp_socket();
    Handle datasocket = -1;

    if ( handle >= 0)
    {
#ifdef DEBUG
        printf("success.\n");
        printf("Listening for... ");
#endif
        const int listen = tcp_server_listen(handle, CLIENT_IP, TCP_PORT);

        if (listen >= 0)
        {
#ifdef DEBUG
            printf("success.\n");
            printf("Waiting for incoming connections (blocking wait)...");
#endif
            datasocket = tcp_server_accept(handle);
#ifdef DEBUG
            printf("client connected.\n");
#endif
        }
        else
        {
            // errno is set
            printf("Error listening: %d\n", errno);
        }
    }
    else
    {
        // errno is set
        printf("Error creating socket for TCP server: %d\n", errno);
    }

    int running = 1;

    while (running)
    {
        static const uint8_t* msg = "hello client\n";
        const int sent1 = tcp_send(datasocket, msg, 13U);

        // send some binary data
        static uint8_t b[3];
        b[0] = 0x11U;
        b[1] = 0x22U;
        b[2] = '\n';
        const int sent2 = tcp_send(datasocket, &b[0U], 3U);

        if ((sent1 > 0) && (sent2 > 0))
        {
            static uint8_t msg_buffer[1024U];
            // does a blocking receive...
            // you must set the socket to non-blocking mode for polling!
            const int received = tcp_receive(datasocket, &msg_buffer[0U], 1024U);

            if (received > 0)
            {
                // do your application specific handling
                switch (msg_buffer[0U])
                {
                    case 'v':
                    {
                        printf("Car charging server 0.1\n");
                        static const uint8_t* vmsg = "V0.1\n";
                        const int sent = tcp_send(datasocket, vmsg, 5U);
                        break;
                    }

                    case 's':
                    {
                        printf("Starts charging...\n");
                        break;
                    }

                    case 'e':
                    {
                        printf("Exiting...\n");
                        running = 0;
                        break;
                    }

                    default:
                    {
                        break;
                    }
                }
            }
        }
    }

    close_tcp_socket(handle);
    close_tcp_socket(datasocket);

    return 0;
}
