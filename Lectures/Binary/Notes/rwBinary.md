# Binary I/O

## Some basic questions
* What's a binary file?
    * Information stored as ones and zeroes
* Why use binary files?
    * Obscures information and smaller
* How do you read / write a binary file
    * Nearly the same as text files

## Specific questions
* How are files specified as binary?
    * The `.bin` file extension
* How do you open a binary for reading / writing in C?
    * Use a b in the file mode when opening the file.
    * Recall tha the open function needs the *name* and *mode* of how the file is to be opened

## fread() and fwrite()
Function prototypes:
```
size_t fwrite(const void* p, size_t sz, size_t n, FILE* fp);
size_t fread(void* p, size_t sz, size_t n, FILE* fp);
```

## writeBinary.c
```
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
```

## readBinary.c
```
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
    printf("\tx: %d\n", x);

    return 1;
}
```