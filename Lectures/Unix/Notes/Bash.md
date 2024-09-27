# Bash - The Bourne Again Shell

## Environment
Bash, *aka*, the Bourne Again shell
    * Default shell for Linux users
    * originally written by Brian Fox of the Free Software Foundation

Bash is an attempt to create a "best of all shells" that not only provides backwards compatibility with the original UNIX Bourne shell, but also the most useful features of both the C shell and Korn shell..

Anotehr advantage is that Bash, as FOSS can be found and installed on any Linux distribution.

## Shell commands
Bash has numerous commands
* alias, unalias
* bg, fg
* jobs, kill
* builtin
* cd, popd, pushd
* dirs
* env
* export
* history
* local
* set, unset
* read, readonly
* ps
* source
* trap

## Shell programming
* declare
* function
* case..in..esac
* for..do..done
* if..then..elif..then..else..fi
* select..do..done
* until..do..done
* while..do..done
* return

## Introduction
Bash is the shell of choice on most Linux systems
* Implements all the core facilities described in chapter 5, "The Linux Shells"
* Compatible withe the original UNIX Bournce shell
* Conforms to POSIX standard for command shells
* Also implements the best features from the original UNIX C shell

On Linux systems, Bash is installed as /bin/bash, but /bin/sh is a pointer to /bin/bash, since any script expecting Bash functionality will run properly under Bash.

The following features of bash that are new or a bit different from what has been discussed previously:
* Variable manipulation
* CLI Processing, aliases, and history
* Arithmetic, conditional expressions, control structures
* Directory stack
* Job control
* Shell functions

## Startup
Bash, like other shells, is a program. When a new Bash shell starts, it executes commands in the file `.bashrc` in the user's home directory.

The exception is when Bash is starterd as a login shell, in which case it runs the commands in the file `.bash_profile` in the user's home directory instead. If you want your `.bashrc` file to be executed in your login shell as well, you have to add this to your `.bash_profile` file:

```
if [ -f ~/.bashrc ]; then
    ~/.bashrc
fi
```

*Note how the `if` statement is ended by the `fi` statement. Note also that the `-f` means "check for file existance"*

In addition to these two files, the sysadmin can put initialization commands appropriate for all users in the file `/etc/profile` which Bash will also read and execute. Not that Bahs will read the `/etc/profile` file first, before running any initialization files belonging to the user.