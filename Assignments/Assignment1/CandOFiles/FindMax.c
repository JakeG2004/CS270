#include <stdio.h>

int Maximum(int* data, int size)
{
    int max = data[0];

    for(int i = 1; i < 5; i++)
    {
        if(max < data[i])
        {
            max = data[i];
        }
    }

    return max;
}