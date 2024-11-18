#include <netinet/in.h> // Struct for storing addr info
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h> // for socket APIs
#include <unistd.h>

const int SOCK_PORT = 4501;
const int MAX_STRING_SIZE = 255;

typedef struct sockaddr_in sockaddr_in;
typedef struct sockaddr sockaddr;

// Create the socket with IPv4, Stream type, and IP protocol
int CreateSocket()
{
    int retVal = socket(AF_INET, SOCK_STREAM, 0);

    if(retVal == -1)
    {
        printf("Failed to make socket!\n");
        exit(-1);
    }

    return retVal;
}