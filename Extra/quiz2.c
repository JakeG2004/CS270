#include <stdio.h>
#include <math.h>

void PrintOdd(int A[], int nA);

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    int nA = sizeof(A) / sizeof(int);

    PrintOdd(A, nA);
}

void PrintOdd(int A[], int nA)
{
    for(int i = 0; i < nA; i++)
    {
        if(A[i] % 2 != 0)
        {
            printf("%i\n", A[i]);
        }
    }
}