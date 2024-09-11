# The Command Line

## Arrays of Pointers
The following code declares an array of pointers to chars

`char* argv[]`

*Note, this is the same as `char** argv`, since a character array and a character pointer are the same*

Each element can contain a pointer to char, often used for strings

The letter 'r' could be addressed with `*(arr[3] + 8)` or `arr[3][8]`. Don't do the first one though, it's silly to use a memory offset for this.

### Ragged array
An n dimensional array where the dimensions are not necessarily equal

### Are these two declarations different?
`char a[2][15] = {"abc:   ", "a is for apple"};`

and

`char* p[2] = {"abc:   ", "a is for apple"};`

**ANSWER**: No, the first results in a nice rectangular array where each string is of defined size 15, the second has undefinied string size

## Command Line Arguments
`int main(int argc, char* argv[])`
* argc - the number of arcumets (includes the command name itself)
* argv[] - a pointer to array of pointers to characters (array of strings) containing the command line arguments
* argv[0] - the command name itself

## Some Executable (binary) Internals
Consider the following programs:

```
#include <stdio.h>

int main(void)
{
    static int myArr[50000] = {1, 2, 3, 4};
}
```

and

```
#include <stdio.h>

int main(void)
{
    static int myArr[50000];
}
```

When compiled, the first executable takes up considerably more memory, despire the program using the same amount of memory. 

This is because static variables are not explicitely initialized in their declarations are initialized to 0 at runtime.

Initialized static variables and uninitialized static variables occupy different sections in the program image.

Typically, initialized static variables are part of the executable on the disk, but uninitialized static variables are not. The initial values of automatic variables are **UNDETERMINED** unless the programm explicitely initializes them.

### Static variables can make a program unsafe for threaded applications
Static variables can make aa program unsafe for threaded execution. For example, the C library function `readdir()` and its relatives use static variables to hold return values.

The function `strtok()` uses a static variable to keep track of its pprogress between calls.

Neither of these functions can be safely called by multiple threads within a program. In other words, they are not thread safe. Externals static variables also make code more difficult to debug because successive invocations of a function that references a static variable may behave in unexpected ways. For these reasons, avoid using static variables except under controlled circumstances.