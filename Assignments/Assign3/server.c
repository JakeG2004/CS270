#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#include "netInfo.h"

int ReceiveData(int sockD, char* strData, int strSize);
int GetOperands(int* op1, int* op2, char* expression);
int ParseExpression(char* expression);
int isNum(char curChar);

int main(int argc, char const* argv[])
{
    // Create socket
    int servSockD = CreateSocket();

    sockaddr_in servAddr;

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(SOCK_PORT);
    servAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the port
    bind(servSockD, (sockaddr*)&servAddr, sizeof(servAddr));

    printf("SERVER: Open and waiting for connection...\n");

    // Listen for connections
    listen(servSockD, 1);

    // Hold client socket
    int clientSocket = accept(servSockD, NULL, NULL);

    printf("Connected to %i\n", clientSocket);

    // Receive data from client
    char strData[MAX_STRING_SIZE];
    if(ReceiveData(clientSocket, strData, MAX_STRING_SIZE) == 0)
    {
        printf("Failed to receive data\n");
        exit(-1);
    }

    int result = ParseExpression(strData);
    char retStr[MAX_STRING_SIZE];

    printf("CLIENT: %s", strData);
    printf("SERVER: Result is %i\n", result);

    snprintf(retStr, MAX_STRING_SIZE, "SERVER: The result is %i", result);

    send(clientSocket, retStr, MAX_STRING_SIZE, 0);

    printf("Closing socket...\n");
    close(clientSocket);
    close(servSockD);
}

int ParseExpression(char* expression)
{
    // Get operator
    char operator = expression[0];

    int op1 = 0;
    int op2 = 0;

    // Get operands
    GetOperands(&op1, &op2, expression);

    switch(operator)
    {
        case '+':
            return op1 + op2;
            break;

        case '-':
            return op1 - op2;
            break;

        case '*':
            return op1 * op2;
            break;

        case '/':
            return op1 / op2;
            break;

        case '%':
            return op1 % op2;
            break;

        default:
            printf("Unexprected operator!\n");
            return 0;
    }
}

int GetOperands(int* op1, int* op2, char* expression)
{
    int spaceIndex = 0;
    char op1Str[MAX_STRING_SIZE];
    char op2Str[MAX_STRING_SIZE];

    // Read up to first space
    for(int i = 2; i < MAX_STRING_SIZE; i++)
    {
        spaceIndex = i;

        if(expression[i] == ' ')
        {
            break;
        }

        if(isNum(expression[i]))
        {
            op1Str[i - 2] = expression[i];
        }

        else
        {
            return 0;
        }
    }

    // 3rd char = ' ' or first operand going to max strings size -> invalid input
    if(spaceIndex == 2 || spaceIndex == MAX_STRING_SIZE)
    {
        return 0;
    }

    // Assign operand1
    *op1 = atoi(op1Str);

    // Read up to first space
    for(int i = spaceIndex + 1; i < MAX_STRING_SIZE && expression[i] != '\0'; i++)
    {
        if(expression[i] == ' ' || expression[i] == '\0' || expression[i] == '\n')
        {
            break;
        }

        if(isNum(expression[i]))
        {
            op2Str[i - (spaceIndex + 1)] = expression[i];
        }

        else
        {
            return 0;
        }
    }

    *op2 = atoi(op2Str);
}

int ReceiveData(int sockD, char* strData, int strSize) 
{
    int retVal = recv(sockD, strData, strSize - 1, 0);

    if (retVal <= 0) {
        return 0;
    }

    // Append null terminator
    strData[retVal] = '\0';
    return 1;
}

int isNum(char curChar)
{
    char* validChars = "0123456789";

    for(int i = 0; validChars[i] != '\0'; i++)
    {
        if(curChar == validChars[i])
        {
            return 1;
        }
    }

    return 0;
}