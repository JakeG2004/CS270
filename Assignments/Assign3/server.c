#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "netInfo.h"

int main(int argc, char const* argv[])
{
    // Create socket
    int servSockD = CreateSocket();

    char serMsg[255] = "FROM SERVER - \"Hello!\"\n";

    sockaddr_in servAddr;

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(SOCK_PORT);
    servAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the port
    bind(servSockD, (sockaddr*)&servAddr, sizeof(servAddr));

    // Listen for connections
    listen(servSockD, 1);

    // Hold client socket
    int clientSocket = accept(servSockD, NULL, NULL);

    send(clientSocket, serMsg, sizeof(serMsg), 0);

    //close(clientSocket);
    //close(servSockD);
}