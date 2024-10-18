# Make
Make is a build automation tool.

Basic idea:
* Minimize work (only compile changes)
* Automate work (remember how to build the whole system)

## What does *compile* mean?
Compiling a single program typically involves several stages

`preprocess -> compile -> link -> a.out`

Compiling multiple programs involves several stages for each C file:

`preprocess -> compile -> file.o`

Finally:

`link <.o file, lib files> -> a.out`

## Rules
The *rules* in a makefile tells `make` how to execute commands to build a *target* file from the *source* files. It also specifies a list of dependencies of the target file.

Make files can contain comments. Comments start with a `#` and are used to describe what is happening in the makefile or to hide definitions form `make`

## Sample make file for a stack program
```
# Makefile
# a makefile for the stack example

    CXX = g++

# CCOPTIONS = 
# CFLAGS = $(CDEBUGFLAGS) $(CCOPTIONS) $(ALLDEFINES)

SRCS = teststack.cpp \ # '\' is a continuation!
    stack.cpp \ # tab starts the line
    link.cpp

OBJS = teststack.o \
    stack.o \
    link.o

teststack.o: stack.h

stack.o: stack.h \
    link.h

link.o: link.h

PROGRAMS = testStack

all:: $(PROGRAMS)

testStack: $(OBJS)
    $(CXX) -o $@ $(OBJS)

clean::
    $(RM) testStack # what is RM?

latex:: #typeset notes
    latex stack.tex

#################################################
# common rules for all Makefles - do not edit

emptyrule::

clean::
    rm *.o
```