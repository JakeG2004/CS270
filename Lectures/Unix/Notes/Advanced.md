# Advanced Unix

## Searching files
`grep, egrep, fgrep` (Global or get regular expression and print) is a utility that allows you to seach for a pattern in a list of files.

### Usage Example
`grep include *.c *.cpp`

`grep printf *.c *.cpp`

`history | grep ssh`

## Filtering Files
uniq filters out duplicate adjacent lines.

`uniq -c -number [inputfile[outputfile]]`

uniq is a utility that displays its input file with all adjacent repeated lines collapsed to a single record.

## Sorting files

The sort utility sorts a file in ascending or descending order.

`sort filename`

## Comparing files

There are two utilities

`cmp` and `diff`

`cmp hello.c hello.cpp`

`diff hello.c hello.cpp`