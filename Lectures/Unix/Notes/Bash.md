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

In addition to these two files, the sysadmin can put initialization commands appropriate for all users in the file `/etc/profile` which Bash will also read and execute. Not that Bash will read the `/etc/profile` file first, before running any initialization files belonging to the user.

## Variables
Bash allows the creation and use of shell variables for the following purposes:
* Value assignment and access
* Defining and using lists of values
* Testing a value or for existence of a variables
* Reading or writing a variable's value

### Creating and assigning a simple variable
To assign a value to a simple variable, the syntax is similar to that of other shells

`{name = value}+`

*NOTE: the `+` indicates that its value is >= 1*

If a variable doesn't exist, it is implicitely created; otherwise, its previous value is overwritten. A newly created variable is always local, although we may turn it into an environment variable using `export`. To assign a value that contains spaces, surround the value by quotes. Here are some examples

```
$ teamname="San Diego Chargers"
$ gameswon=12
$ gameslost=4
```

*NOTE: There are no spaces around the `=` character.*

### Setting variables

The `set` command can be used to set and display shell settings and to display the value of shell variables

```
$ set gameslost=4
$ set gameswon=12
$ set teamname='San Diego Chargers'
```

*NOTE: `'` instead of `"`*

### Accessing variables
Accessing the value of a simple variable
* `$name` - Replaced by the value of name
* `${name}` - Replaced by the value of the name. This form is useful if the expression is immediately followed by an alphanumeric that would otherwise be interpreted as part of the variable name.
* `${name-word}` - Replaced by the value of the name if set, and word otherwise.
* `${name+word}` - Replaced by word if name is set, and nothing otherwise.

```
% echo $gameswon
12

% echo $teamname
Sad Diego Chargers

% echo ${teamname} | wc -w
3
```

### Creating / assigning a list variable
`declare [-ax] [listname]`

If the named variable does not already exist, it is created. If an array name is not specified whe n `-a` is used, declar will display all currently defined arrays and their values. If the `-x` option i sused, te variable is exported to subshells. `declare` writes its output in a format that can be used again as input commands. This is useful when you want to create a script that sets variables as they are set in your list.

```
${name[i]}
```

### Accessing list variables
Once you build a list of values, you will want to use them for something. When accessing array values, you can always put braces around the variable name to explicitely distinguish it form other text that might be around it.

```
${name[index]} - access the index'th term of the array
${name[*]} or $name{[@]} - access all elements of the array
${#name[*]} or ${#name[@]} - access the number of elements in the array
```

### Building lists
You can build an array or list var in 1 of 2 ways. If you know how many elements you will need, you can use the declare built-in command.

### Destroying lists
List variables can be deallocated or destroyed using the `unset` command.

```
unset name
unset name[index]
```

Indices automatically updated

### Reading from stdin
`read {variable} +`

`read` reads one line from stdin and then assigns successive words from the line ot the specified variables. Any words that are left over are assigned to the last named varaible.

```
cat script.sh
echo "Please enter your name: "
read name
echo your name is $name
```

### Exporting variables
`export {variable}+`

`exports` marks the specified variables for export to the environment. If no variables are specified, a list of all the variables marked for export is displayed.

`env {variable=value}* [command]`