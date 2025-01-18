//
// Created by RONG on 18/1/25.
//

#ifndef SERVER_H
#define SERVER_H

#include <sys/socket.h>
#include <netinet/in.h>

// Define the Server structure
struct Server {
    int domain;
    int service;
    u_long interface;
    int protocol;
    int port;
    int backlog;
    struct sockaddr_in address;
    void (*launch)(struct Server *server); // Updated to match the implementation

    int socket;
};

// Define the function prototype for server_constructor
struct Server server_constructor(int domain, int service, int protocol, u_long interface, int port, int backlog, void (*launch)(struct Server *server)); // Updated launch parameter

#endif /* SERVER_H */
