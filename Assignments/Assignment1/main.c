#include <stdio.h>

extern int SumAndAverage();
extern int Maximum();
extern int Minimum();

int data[] = {10, 20, 30, 40, 40};

int main()
{
    SumAndAverage();
    Maximum();
    Minimum();
}