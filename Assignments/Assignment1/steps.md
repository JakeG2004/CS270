1) write code
2) compile with gcc file.c -o file.o
3) Merge files with gcc file1.0 ... filen.o -o combined
4) Use readelf -s combined to show the symbol table of the file
    * Layout is num, value, size, type, bind, vis, ndx, name
    * Value, Size, and name are the important ones
    * This will handle the first 3 bullet points