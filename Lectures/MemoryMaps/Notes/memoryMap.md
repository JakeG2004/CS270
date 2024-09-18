# Memory maps

## Binary file formats
* a.out
* COFF (Common Object File Format)
* XCOFF (eXtended COFF)
* ELF (Executable and Linking Format)
* Mach-O (Mach Object)
* PE (Portable Executable)

## Object file format
The original Unix object file format `a.out` is a very simple design, unable to adequately support, for example, shared libraries, foreign format identification, or explicit address linkage. As development of Unix-like systems continued both inside and outside AT&T, different solutions ot these and other issues emerged.

Contains up to 7 secions in the following order
1) **exec header** - Containes parameters used by kernel to load bin into memory and execute
2) **text segment** - Contains machine code and related data
3) **Data segment** - Contains initialized data
4) **text relocations** - Contains records used by the link editor to update pointers in the text segment when combining binary files
5) **data relocations** - Like the text relocation section, but for data segment pointers
6) **symbol table** - Contains records used by the link editor to cross-reference the addresses of named variables and functions
7) **string table** - contains the character strings corresponding to the symbol names

## Tools
* `readelf` - look inside an elf file
* `objdump` - disassembles a program

