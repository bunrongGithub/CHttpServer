#include <stdio.h>
#include <string.h>
#include "Server.h"
#include <unistd.h>
void launch(struct Server *server)
{
    char buffer[30000];
    char *hello = "HTTP/1.1 200 OK\n"
                  "Date: Mon,27 2009 12:28:53 GMT\n"
                  "Server: Apache/2.2.14 (Win32)\n"
                  "Last-Modified: Web, 22 Jul 2009 19:15:56 GMT\n"
                  "Content-Length: 43\n"
                  "Content-Type: text/html\n"
                  "Connection: Closed\n"
                  "\n"
                  "<html><body><h1>Homo Deus</h1></body></html>";

    int address_length = sizeof(server->address);
    int new_socket;
    while (1)
    {
        printf("======= Waiting for connection =========");
        new_socket = accept(server->socket, (struct sockaddr *)&server->address, (socklen_t *)&address_length);
        read(new_socket, buffer, 30000);
        printf("%s\n", buffer);
        write(new_socket, hello, strlen(hello));
        close(new_socket);
        /* code */
    }
}
int main()
{
    struct Server server = server_constructor(AF_INET,
                                              SOCK_STREAM, 0, INADDR_ANY, 80, 10, launch);
    server.launch(&server);
}