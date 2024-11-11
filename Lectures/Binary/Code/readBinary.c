#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fp = fopen("btest.bin", "rb");
    if(!fp)
    {
        printf("Unable to open file!\n");
        return 1;
    }

    char c;
    int n;
    double x;

    fread(&c, sizeof(char), 1, fp);
    fread(&n, sizeof(int), 1, fp);
    fread(&x, sizeof(double), 1, fp);

    fclose(fp);

    printf("Read:\n");
    printf("\tc: %c\n", c);
    printf("\tn: %i\n", n);
    printf("\tx: %f\n", x);

    return 1;
}