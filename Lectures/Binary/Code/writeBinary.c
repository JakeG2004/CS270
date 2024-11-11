#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fp = fopen("btest.bin", "wb");
    if(!fp)
    {
        printf("Unable to open file \"btest.bin\"!");
        return 1;
    }

    char c = 'N';
    int n = 11;
    double x = 3.14;

    fwrite(&c, sizeof(char), 1, fp);
    fwrite(&n, sizeof(int), 1, fp);
    fwrite(&x, sizeof(double), 1, fp);

    fclose(fp);

    return 0;
}