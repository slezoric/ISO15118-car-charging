
/// \file TCPSocket.h
/// \brief Example for Jiztom
/// \date 02.03.2017
/// \author Daniel Tuchscherer

#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <errno.h>
#include <stdint.h>

/// Easier to read.
typedef int Handle;

/// Creates a TCP socket
/// \return the socket handle as an integer
Handle create_tcp_socket();

/// Listen for incoming TCP client connections.
/// \param[in] client_ip to accept as characters. If you give "255.255.255.0" it
/// will accept any connections from outside.
/// \param[in] the port to listen to.
int tcp_server_listen(const Handle server, const char *client_ip,
                      const uint16_t port);

/// blocking wait for incoming client connections
/// \return the data socket to send data.
Handle tcp_server_accept(const Handle server);

/// Receive data via TCP/IP.
/// \return number of bytes received.
int tcp_receive(const Handle datasocket, uint8_t *msg, const uint16_t len);

/// Send data via TCP/IP.
/// \return number of bytes sent.
int tcp_send(const Handle datasocket, const uint8_t *msg, const uint16_t len);

/// Closes one socket
int close_tcp_socket(const Handle handle);

#endif /* TCPSOCKET_H */
