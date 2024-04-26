# Program Output

A program isn't very useful if it can't communicate with the outside world. Lets figure out how to make our program produce output! Specifically, we will learn how to print a message to the screen.

As we previously discussed, the kernel is responsible for managing computer resources, including:
- The CPU.
- Memory.
- Display devices, such as a monitor.
- Input device, such as a keyboard.
- Storage devices, such as a hard drive.

Between the kernel and the physical display you are viewing this text on is a *virtual* device ("psuedo-terminal"). And guess what? The kernel manages it too! Some program is responsible for reading data from the psuedo-terminal, and ultimately drawing pixels to the physical screen. This **program** is called a *terminal emulator*.

You could write your own terminal emulator, but let's first learn how to just print a message to the terminal emulator that we already have. We'll do this by making a system call to the kernel, which will then pass our message to the terminal emulator, which will then draw the message on the screen.

In order for two programs to communicate, they must communicate through some *interface*. The interface is a contract between the two programs, which specifies how they will communicate. Program processes are yet another collection of resources which the kernel manages, and so, it manages communication between processes. The kernel provides a set of **system calls** that programs can use to communicate with each other, as facilitated by the kernel.

We previously saw the *exit* system call, but there are many more system calls that a program can make. One of them is the *write* system call, which allows a program to write data to a file. Another is the *read* system call, which allows a program to read data from a file.

Files are another resource the kernel manages! In fact, in Linux, most resources on a computer are actually **represented as files**. Your monitor is a file. Your keyboard is a file. Your hard drive is a file. Your process is a file. Your psuedo-terminal is a file. Your "regular" files are files. Everything is a file! Do not be narrow-minded about the concept of a file, it's just something that supports a simple interface with operations like read and write! This is a very useful abstraction, and it's one of the reasons why Linux is so powerful.

In order to print a message to the screen, we are going to write our message to a psuedo-terminal file, which your terminal emulator is *already* busy reading from and drawing to the screen. We'll use the *write* system call to do this.
