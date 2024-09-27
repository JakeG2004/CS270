#include <stdio.h>

int Minimum(int* data, int size)
{
    int min = data[0];

    for(int i = 1; i < 5; i++)
    {
        if(min > data[i])
        {
            min = data[i];
        }
    }
    return min;
}