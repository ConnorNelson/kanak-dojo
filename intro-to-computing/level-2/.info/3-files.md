# Files

As we previously discussed, the kernel keeps track of which files a process has open. These files are stored sequentially in the process's **file descriptor table**. Each file in the file descriptor table has an associated **file descriptor**. The file descriptor *describes* the file. The file descriptor is just a number that uniquely identifies the file, and is used to refer to the file. In the kernel, the file descriptor table is an array of files, and the file descriptor is just an index into the file descriptor table.

When your program starts up, it inherits all of the files that were open in the parent process. By *convention*, there are three standard files that are open when your program starts:
- Standard input (stdin): file descriptor 0.
- Standard output (stdout): file descriptor 1.
- Standard error (stderr): file descriptor 2.

Your program can have more files open when it starts, or less. This is dictated by the process that starts your program. But by convention, you can reasonably expect that these three files will be open when your program starts.

When you want to describe a process's open file, you do so by specifying the file descriptor. For example, you might decide to write to stdout, which is file descriptor 1. Or, you might decide to read from stdin, which is file descriptor 0.

You already saw the file descriptor table of a process when you ran `ls -al /proc/self/fd`, and you saw stdin, stdout, and stderr were all pointed at the same file, the psuedo-terminal file which your terminal emulator is reading from and writing to: `{{ fd_0_path }}`. This is because the shell that started your program had its stdin, stdout, and stderr all pointed at the same psuedo-terminal file, and when it started your program, it inherited those file descriptors.

You would have also seen that the file descriptor table itself was open on file descriptor 3. This is because the `ls` program opened the file descriptor table in order to inspect it and list its contents. How introspective!

We previously saw that we can make a system call to exit our program as follows:
```assembly
mov rax, 60
syscall
```

This worked because the *exit* system call number is 60. Well, the *read* system call number is 0, and the *write* system call number is 1. Our goal is to write to the psuedo-terminal file, so we can see our message on the screen, and our current hiearchy of processes has stdout pointed at the psuedo-terminal file, so we can use the *write* system call to write to stdout, which will write to the psuedo-terminal file, which will write to the screen.
