#include <stdio.h>

extern int data[];

int SumAndAverage()
{
    int sum = 0;
    for(int i = 0; i < 5; i++)
    {
        sum += data[i];
    }

    printf("Sum: %i\n", sum);
    printf("Average: %d\n", sum / 5.0);

    return sum;
}