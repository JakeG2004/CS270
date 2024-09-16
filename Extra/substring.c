#include <stdio.h>
#include <stdlib.h>

char* SubString(char*, int, int);

int main(void)
{
    char test[] = "abcdefgh";
    printf("%s\n", SubString(test, 1, 1));
}

char* SubString(char* inString, int iStart, int iEnd)
{
    //allocate memory
    char* retStr = (char*)(malloc(sizeof(char) * (iEnd - iStart + 2)));

    //error check
    if(inString == NULL || iStart > iEnd || iStart < 0 || iEnd < 0)
    {
        printf("Error!\n");
        return NULL;
    }

    //copy from iStart to iEnd
    for(int i = iStart; i <= iEnd; i++)
    {
        retStr[i - iStart] = inString[i];
    }

    //append null terminator
    retStr[iEnd - iStart + 1] = '\0';

    return retStr;
}