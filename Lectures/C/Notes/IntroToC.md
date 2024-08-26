# Introduction to C
* Developed in the early 70s by Dennis Ritchie (Bell Labs)
* Unix written in C (a little assembly)
* Still popular

## C/C++
* What's the same?
    * Basic data types
        * char
        * int (short, long)
        * double (float)
    * Comments
    * Syntax
        * Function defs
        * Conditionals `if, switch`
        * Loops `for, while, do-while`
        * Arrays
        * Abstract data type: `structs, unions`
    * Naming conventions

* What's different?
    * Compiler invocation `gcc vs g++`
    * I/O
        * input
            * `scanf()`
            * `read()`
        * output
            * `printf()`
            * `write()`
        * `read()` and `write()` are low level, may not be used in this class.
    * Parameter passing - `pointers`
        * MyFunc(*x, *y) in C vs MyFunc(&x, &y) in C++. x and y must be dereferenced for use in C.
    * Strings are `char[]`
    * Memory manipulation (`malloc` and `free` in C instead of `new` and `delete`)
    * No generics (templates in cpp)
    * Macros (C preprocessor)

## Unions
* Allow two variables to exist in the same memory
* This code allows for my_int and my_bytes to exist in the same memory
```
union {
    uint32_t my_int;
    uint8_t my_bytes[4];
} endian_tester;

endian_tester et;
et.my_int = 0x0a0b0c0d;

if( et.my_bytes[0] == 0x0a )
    printf( "I’m on a big-endian system\n" );
else
    printf( "I’m on a little-endian system\n" );
```

## Copy file program
* **NOTE**: char\*\* argv is the same as char\* argv[]
```
#include <stdio.h>

int main(int argc, char** argv)
{
    //define our variables
    FILE *fp;
    int c;

    //if the file is open and contains content
    if((fp = fopen(*++argv, "r")) != EOF)
    {
        //copy the current character from the file to standard output
        while((c = getc(fp)) != EOF)
            putc(c, stdout);
    }

    //close the file
    fclose(fp);
}
```

## String Manipulation
* Strings are character arrays in C. The standard string library functions are in `string.h`. Typical string functions include:
    * `strlen()`
    * `strcat()`
    * `strcmp()`
* We can read from and write to strings using hte function `sscanf()` for input and `sprintf()` for output.
    * Read an integer: `sscanf(s, "%d", &i)`
    * Write an integer to a string: `sprintf(s, "&d", &i)`

## Dynamic Memory
* Dynamic allocated memory is manipulated using *operators* in C++, and *functions* in C.
    * `malloc() / calloc() / alloc()` instead of `new`
    * `free()` instead of `delete`

* Declare / Allocate / Deallocate an int array with N elements

    * C++
    ```
    int *pA;
    pA = new int[N];
    delete [] pA;
    ```

    * C
        * **NOTE:** free() may not need a `void*` to work, dependent upon the compiler.
    ```
    int *pA;
    pA = (int*)malloc(N* sizeof(int));
    free((void*)pA);
    ```

* Same thing, 2D array with nRows and nColumns

    * C++
    ```
    int** arr2D;

    arr2D = new int* [nRows];

    for(int i = 0; i < nRows; i++)
    {
        arr2D[i] = new int[nCols];

        //check for valid memory
        if(arr2D == NULL)
        {
            cout << "Error" << endl;
        }
    }

    for(int i = 0; i < nRows; i++)
    {
        delete arr2D[i];
    }

    delete [] arr2D;
    ```

    * C
    ```
    int** arr2D;

    //init array
    arr2D = (int**)malloc(sizeof(int*) * nRows);

    //allocate rows
    for(int i = 0; i < nRows; i++)
    {
        //allocate cols
        arr2D[i] = (int*)malloc(sizeof(int) * nColumns);
    }

    //delete cols
    for(int i = 0; i < nRows; i++)
    {
        free((void*)(arr2D[i]));
    }
    
    //delete the whole thing
    free((void*)arr2D);
    ```

