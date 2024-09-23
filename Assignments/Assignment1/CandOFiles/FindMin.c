#include <stdio.h>

extern int data[];

int Minimum()
{
    int min = data[0];

    for(int i = 1; i < 5; i++)
    {
        if(min > data[i])
        {
            min = data[i];
        }
    }

    printf("Min: %i\n", min);

    return min;
}