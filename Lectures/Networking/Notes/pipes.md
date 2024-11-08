# Pipes
* An interprocess communication mechanisms allowing 2 or more processes to send info to each other
* They are commonly used from within shells to connect the standard out of one utility to the stdin of another

## Unnamed Pipes
System Call: `int pipe(int fd[2])`
* pipe() creates an unnamed pipe and returns two file descriptors
* The descriptor associated with the read end of the pipe is in fd[0]
* The descriptor associated with the write end of the pipe is in fd[1]

### Unnamed Pipe Creation
Executing the following code will create the data structure shown below

```
int fd[2]
pipe(fd)
```

Unnamed pipes are usually used for communications between a parent process and its child, one reads and one writes.
* The parent creates a pipe useing `pipe()`
* The parent process forks
* The writer closes its read end of the pipe, and the reader closes its write end of the pipe
* The processes communicated by using `write()` and `read()`
* Each process closes its active pipe descriptor when finished with it.

### Reading from an unamed pipe
The folllowing rules apply to **processes that read** from a pipe:
* If a process reads form a pipe whos write end has been closed, the `read()` returns a 0, indicating end of input
* If a process reads from an empty pipe whose write end is still open, it sleeps until more input is available
* If a process tries to read more bytes from a pipe than are present, all of the current contens are returned and `read()` returns the # of bits received

### Writing to an unnamed pipe
* If a process writes to a pipe whose read has been close, the write fails and the writer is sent a SIGPIPE signal, which terminates the writer by default
* IF a process writes fewer bytes than can be held, `write()` is guaranteed to complete its syscall without being preempted
* If a process writes more bytes to a pipe than the pipe can hold, no similar guarantees apply.

## Named Pipes
Less restricted than unnamed pipes
* They have a name that exists in the file system
* They may be used by unrelated processes
* They exist until explicitely deleted

Note: All of the rules for unnamed pipes still apply :smile:

* A named pipe can be created in one of two ways
    * `mkfifo` from the command line
    * `mkfifo()` syscall
* Utility: `mkfifo fileName`
    * `mkfifo` creates a pipe named `fileName`
* Programmatically
    `mkfifo("myPipe", 0660);

### Named Pipe Operation
* A special file is added to the system
* Once opened by `open()`
    * `write()` puts data into the FIFO queue
    * `read()` removes data from the queue 