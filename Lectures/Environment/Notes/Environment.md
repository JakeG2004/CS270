# Environment

## Quick Review - Argument list
When a program is executed, the process that does the exec can pass CLI args into the porgram.

## Envrionment List
Each program is also passed an environment list. Like the argument list, the envrionment list is an array of strings, null terminated C-style strings. The address of the array of pointers is contained in the global variable environ:

`extern char** environ;`

For example, if the environment consisted of five things, it could look like the following figure. The *nul* byte at the end of each strings is explicitely shown. We'll call `envrion` the environment pointer, the array of pointers the *envrionment list*, and hte strings they point to the *environment strings*.

```
envriron -> | Env List | -> HOME=/home/sar
            |          | -> PATH=:/bin:/usr/bin
            |          | -> SHELL=/bin/bash
            |          | -> USER=sar
            |          | -> LOGNAME=sar
            |   NULL   |
```

**NOTE**: Not necessarily in this order.

Historically, most UNIX systems have provided a third argument to the `main` function that is the address of the environment list:

`int main(int argc, char* argv[], char* envp[]);`

Because ISO C specifies that the main function be written with two arguments, and because this third argument provides no benefit over the global variable `environ`, POSIX.1 specifies that `environ` should be used instead of the possible third arhument. Access to specific environment variables is normally through the `getenv`and `putenv` functions, instead of throught the `environ` variable. But to go through the entire environment, the `environ` pointer must be used.

## Environment Variables
As mentioned earlier, the environment strings are usually of the form

`name=value`

The UNIX kernel never looks at these strings; their interpretation is up to the various applications. The shells, for example, use numerous environment variables. Some, such as `HOME` and `USER`, are set automatically at login, and others are for us to  set. Normally envrionemnt variables are set in a shell setup file to control the shell's actions. If we set the env variable MAILPATH. for example, it tells BASH, Korn, or any other shell where mail is.

ISO C defines a function that we can use to fetch values from the env, but this standard says that the contents of the env are implementation defined.

`char* getenv(const char* name);`

In addition, variables can be set and unset

```
int putenv(char* str);
int setenv(const char* name, const char* value, int rewrite)
int unsetenv(const char* name)
```

