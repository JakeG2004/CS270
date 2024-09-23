# Shells
Command line interface to system

Many types of shells
    * zsh
    * bash
    * fish

All of these shells share a common core set of operations that make life in the Linux system easier. For example, all shells allow the output of a process to be stored in a file or "piped" to another process.

The shell you use is a matter of personal taste.

## Selecting a shell
`chsh` allows you to change your default login shell

## Useful commands
`echo` - displays all of its arguments to standard output, appends newline.
`cd` - change directory

## Tee
The `tee` utility copies its standard input to the specified files *and* to its standard output. The `-a` option causes the input to be appended to the files rather than overwriting them. The `-i` option causes interrupts to be ignored.

In the following example, the output of `who` is copied to a file named `who.capture`, and also passed through to sort

`who | tee who.capture | sort`

## Command Substitution
A command surrounded by grave accents \` is executed and its output is inserted in the command in its place. Any newlines in the output are replaced by spaces. For example

`$ echo the date is 'date'`

## Sequences
If a series of simply commands or pipelines separated by semicolons in entered, the shell will execute them in sequence, from left to right. This facility is useful for type-ahead addicts who like to specift an entire sequence at once.

## Conditional sequences
Every linux process terminates with an exit value. 0 means a success, nonzero means failure.
    * If you specify a series of commands separated by `&&` tokens, the next command is executed iff the previous command returns an exit code of 0.
    * If you specify a series of commands separated by `||` tokens, the next command is executed iff the precious command returns a nonzero exit code.

The `&&` and `||` metacharacters work the same as in C.

### Why care?
If gcc compiles successfuly, it'll return 0, so `gcc myprog.c && ./a.out` would compile and run automatically, but wouldn't try to run if compilation fails. conversely, `gcc myprog.c || echo 'Compilation failed'` would tell you that compilation failed.

## Grouping commands
Commands may be groups by placing them between parantheses, which causes them to be executed by a child shell. The group of commands shares the same standard in, stdout, and sterr channels. May be redirected and piped because of this.

## Background processing
If you follow a simple command, pipeline, or sequence of pipelines, or a group of commands by the `&` metacharacter, a subshell is created and executes the process as a background process. Runs concurrently.

`sleep 5 && echo 'Done &` will wait 5 seconds and print in the background

## Redirecting background processes
Done as normal since stdin and stdout are the same between parent and child process