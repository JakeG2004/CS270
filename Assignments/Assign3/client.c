#include <netinet/in.h> // Struct for storing addr info
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h> // for socket APIs
#include <unistd.h>

#include "netInfo.h"

int ConnectToServer(int sockD);
int ReceiveData(int sockD, char* strData, int strSize);

char* GetUserExpression();

int GetOperands(int* op1, int* op2, char* expression);

int isOperator(char curChar);
int isNum(char curChar);

int main(int argc, char* argv)
{
    int sockD = CreateSocket();

    ConnectToServer(sockD);

    char* expression = GetUserExpression();

    if(send(sockD, expression, MAX_STRING_SIZE, 0) == -1)
    {
        printf("Failed to send\n");
    }

    char* strData = (char*)malloc(sizeof(char ) * MAX_STRING_SIZE);
    int receiveCondition = ReceiveData(sockD, strData, MAX_STRING_SIZE);

    if(receiveCondition == 0)
    {
        printf("Failed to get data from server\n");
        exit(-1);
    }

    printf("%s\n", strData);

    // Close socket
    close(sockD);
}

int ConnectToServer(int sockD)
{
    struct sockaddr_in servAddr;

    // Initialize values
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(SOCK_PORT);
    servAddr.sin_addr.s_addr = INADDR_ANY;

    // Connect to server
    int connectStatus = connect(sockD, (struct sockaddr*)&servAddr, sizeof(servAddr));

    if (connectStatus == -1) {
        perror("Error connecting to server");
        close(sockD);
        exit(-1);
    }

    return 0;  // Success
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


char* GetUserExpression()
{
    char* expression = (char*)malloc(sizeof(char) * MAX_STRING_SIZE);
    int validInput = 0;

    // Loop to get valid input
    while(!validInput)
    {
        printf("Enter a valid expression (<operator> <operand> <operand>)\n");

        // Read in expression
        fgets(expression, MAX_STRING_SIZE, stdin);

        // Ensure first char is operator
        if(!isOperator(expression[0]))
        {
            printf("Invalid expression! ");
            validInput = 0;
            continue;
        } 
        
        else 
        {
            validInput = 1;
        }

        // Ensure operand is followed by a space 
        if(expression[1] != ' ')
        {
            printf("Invalid expression! ");
            validInput = 0;
            continue;
        }

        // Get the two operands
        int op1;
        int op2;

        // Failure to get operands
        if(GetOperands(&op1, &op2, expression) == 0)
        {
            printf("Invalid expression! ");
            validInput = 0;
            continue;
        }

        // Valid string
        validInput = 1;
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
int isOperator(char curChar)
{
    char* validChars = "+-/%%*";

    for(int i = 0; validChars[i] != '\0'; i++)
    {
        if(curChar == validChars[i])
        {
            return 1;
        }
    }

    return 0;
}