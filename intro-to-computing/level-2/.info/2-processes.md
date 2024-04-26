# Processes

You've already written a program that can *exit*, but exactly is "it" that exits? This thing which starts, runs, and exits is called a **process**. A process is a running instance of a program. When you run a program, the kernel creates a *process* to run that program. When your program exits, the kernel destroys the process. There could be several independent running instances--processes--of the same exact program.

The process is a resource that the kernel manages, and in turn, it has a collection of resources and attributes associated with it:
- PID: the process has a unique ID, which is used to identify it.
- CPU: the process has its own CPU state, including the general purpose registers and RIP.
- Memory: the process has its own memory space, which is isolated from other processes. We'll explore this in more detail later.
- Open Files: the process tracks which files are open, and the state of those files.
- User ID: the process has a user ID, which determines what resources it can access.
- And many more resources...

Remember how we said that the process is a resource, and on Linux, resources are files? Well, the process is a file too, with a path and everything! When a process accesses `/proc/self/`, it's accessing its own process file. The process file is a directory, and it contains a bunch of files that describe the process.

Check out some of them with the following commands:
- `ls -l /proc/self/exe`: This is a symbolic link which points to the executable that started the process.
- `cat /proc/self/maps`: This file contains all of the memory mappings for the process.
- `ls -l /proc/self/fd`: This is a directory that contains a bunch of symbolic links to the files that are open in the process. You can see that the standard input, output, and error streams are open, as well as the process file itself.

Go ahead and run these commands!
