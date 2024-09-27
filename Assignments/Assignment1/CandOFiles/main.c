/*
Jake Gendreau

MainPBR.c
Main file implemented with pass by reference rather than global variable.

11/26/2024
*/

#include <stdio.h>

extern int Sum(int* data, int size);
extern int Maximum(int* data, int size);
extern int Minimum(int* data, int size);

int main()
{
    int data[] = {10, 20, 30, 40, 40};
    int size = 5;

    printf("Sum: %i\n", Sum(data, size));
    printf("Max: %i\n", Maximum(data, size));
    printf("Min: %i\n", Minimum(data, size));
}