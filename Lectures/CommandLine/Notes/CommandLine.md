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