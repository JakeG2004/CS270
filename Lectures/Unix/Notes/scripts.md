# Scripts
*What is a shell script?*

A shell script is a file filled with shell commands

*Why use shell scripts?*

Makes doing repetitive tasks easier. Store commands for later use.

## Specify shell
Scripts can be written in a shell or some other programming language, eg Perl or Python.

The shell / language is specified in the first line of the script. It starts with the `#!` and is followed by the shell or language.

### Bash
```
#!/bin/sh

echo "Hello, Kitty!"
```

### Perl
```
#!/usr/bin/perl
# hello.pl

print "Hello world!\n"
```

### Combined: bash and perl
```
#!/bin/bash
# bashandperl.sh

echo "Greetings from the bash part of the script."
# More bash commands may follow

exit 0
# end bash part

#!usr/bin/perl
# This part of the script must be invoked with -x option

print("Greetings from the Perl part of the script\n");
# More perl commands may follow
```

### Python
```
#!usr/bin/env python
helloPython.py

print("Hello world!)
```

## Make executable
`chmod +x <script>`

## Run
`./script.sh`

## Read / if
```
#!/bin/sh
echo 'Enter a number: \c'
read number

if [ $number -lt 0 ]
then
    echo negative
elif [ $number -eq 0 ]
then
    echo zero
else
    echo positive
fi
```

## Menu
```
#!/bin/sh
echo menu test program
stop=0
while test $stop -eq 0
do
 cat << ENDOFMENU                             # display menu
 1: print the date
 2,3: print the current working directory.
 4: exit
ENDOFMENU
 echo
 echo 'Your choice? \c'                       # prompt
 read reply                                   # read response
 echo
 case $reply in                               # process response
   "1")
     date                                     # display date
     ;;
   "2"|"3")
     pwd                                      # display working directory
     ;;
    "4")
      stop=1                                  # set loop termination flag
      ;;
    *)                                        # default
      echo illegal choice                     # error
      ;;
 esac
done
```

## Until loop
```
#!/bin/sh
x=1
until [ $x -gt 3 ]
do
    echo x = $x
    x=`expr $x + 1`
done
```

## Multiple Loops
```
#!bin/bash
if["$1" = ""]
then
    echo "Usage: multi number"
    exit
fi
x=1 # set outer loop value
while[$x -le $1]                    # Outer loop
do
    y=1
    while[$y -le $1]
    do
        echo -n -e `expr $x \* $y`"   \t"
```

## Track
This script tracks a user's logins and logouts, generating a report of their sessions
```
pause=20                                  # default pause between scans
loopCount=10000                           # default scan count
error=0                                   # error flag

for arg in $*                             # parse command line arguments
do
  case $arg in
    -t*)                                  # time
      pause='expr substring $arg 3 10'    # extract number
      ;;
    -n*)                                  # scan count
      loopCount='expr substr $arg 3 10'   # extract number
      ;;
    *)
      user=$arg                           # user name
      ;;
  esac
done

if [ ! "$user" ]                          # check a user ID was found
then
  error=1
fi

if [ $error -eq 1]                        # display error if error(s) found
then
  cat << ENDOFERROR                       # display usage message
usage: track [-n#] [-t#] userId
ENDOFERROR
fi

MORE LOGIC IN HERE THAT I DONT WANT TO COPY <3
```