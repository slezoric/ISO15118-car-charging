
/// \file TCPSocket.h
/// \brief Example for Jiztom
/// \date 02.03.2017
/// \author Daniel Tuchscherer

#include "TCPSocket.h"
#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////
Handle create_tcp_socket()
{
    // Create a socket to exchange data via TCP/IP
    // socket must be of type AF_INET (IPv4 Internet protocols) and SOCK_STREAM for TCP/IP
    const int handle = socket(AF_INET, SOCK_STREAM, 0);
    return handle;
}

////////////////////////////////////////////////////////////////////////////////
int tcp_server_listen(const Handle handle, const char* client_ip, const uint16_t port)
{
    int success = 0;
    uint32_t address_binary = 0U;

    if (strcmp(client_ip, "255.255.255.0") == 0)
    {
        address_binary = INADDR_ANY;
    }
    else
    {
        address_binary = inet_addr(client_ip);
    }

    // one address struct
    struct sockaddr_in client;

    // check if the address is valid or not
    if ( address_binary != INADDR_NONE )
    {
        memset(&client, 0, sizeof(client));
        client.sin_addr.s_addr = htonl(address_binary);
        client.sin_family      = AF_INET;
        client.sin_port        = htons(port);

        int reuse_addr = 1;
        setsockopt(handle, SOL_SOCKET, SO_REUSEADDR, (char*)&reuse_addr,
        sizeof(reuse_addr));

        // bind the socket onto the client address
        const int bound = bind(handle, (struct sockaddr*)&client, sizeof(client));

        // only accept one client connection
        const int listen_success = listen(handle, 1);

        if ((bound >= 0) && (listen_success >= 0))
        {
            success = 0;
        }
        else
        {
            success = -1;
        }
    }
    else
    {
        success = -1;
    }

    return success;
}

////////////////////////////////////////////////////////////////////////////////
Handle tcp_server_accept(const Handle server)
{
    struct sockaddr_in client;
    socklen_t len = sizeof(client);
    return accept(server, (struct sockaddr*)&client, &len);
}

////////////////////////////////////////////////////////////////////////////////
int tcp_receive(const Handle datasocket, uint8_t *msg, const uint16_t len)
{
    const int nbytes = recv(datasocket, (void*)msg, len, 0);
    return nbytes;
}

////////////////////////////////////////////////////////////////////////////////
int tcp_send(const Handle datasocket, const uint8_t *msg, const uint16_t len)
{
    const int nbytes = send(datasocket, msg, len, MSG_NOSIGNAL);
    return nbytes;
}

////////////////////////////////////////////////////////////////////////////////
int close_tcp_socket(const Handle handle)
{
    // tidy up
    shutdown(handle, -2);
    const int cl = close(handle);
    return cl;
}
