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
