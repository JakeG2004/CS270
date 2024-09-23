## PART 1
1) write code
2) compile with gcc file.c -c file.o
    * -c indicates don't link
3) Merge files with gcc file1.0 ... filen.o -o combined
4) Use readelf -s combined to show the symbol table of the file
    * Layout is num, value, size, type, bind, vis, ndx, name
    * Value, Size, and name are the important ones
    * This will handle the first 3 bullet points

## PART 2
1) write code
2) compile with gcc -O file.c -c file.o
    * -O means optimize
3) Merge files with gcc -O file1.0 ... filen.o -o combined
4) Use readelf -s combined to show the symbol table of the file
    * Layout is num, value, size, type, bind, vis, ndx, name
    * Value, Size, and name are the important ones
    * This will handle the first 3 bullet points

## PART 3
1) write code, defining the array in main() and passing it to the functions
2) compile with gcc file.c -c file.o
    * -c indicates don't link
3) Merge files with gcc file1.0 ... filen.o -o combined
4) Use readelf -s combined to show the symbol table of the file
    * Layout is num, value, size, type, bind, vis, ndx, name
    * Value, Size, and name are the important ones
    * This will handle the first 3 bullet points