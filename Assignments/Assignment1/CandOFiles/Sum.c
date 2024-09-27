#include <stdio.h>

int Sum(int* data, int size)
{
    int sum = 0;
    for(int i = 0; i < 5; i++)
    {
        sum += data[i];
    }

    return sum;
}