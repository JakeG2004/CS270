#include <stdio.h>

extern int data[];

int Maximum()
{
    int max = data[0];

    for(int i = 1; i < 5; i++)
    {
        if(max < data[i])
        {
            max = data[i];
        }
    }

    printf("Max: %i\n", max);

    return max;
}