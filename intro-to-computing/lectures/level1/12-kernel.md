# The Kernel

How can we make our program not crash? What we'd like to do is to make sure that the CPU doesn't try to execute any random bytes that happen to be in memory after our `mov` instruction. Instead, we'd like our program's process to exit gracefully.

The CPU doesn't really have any concept of "graceful" or "exit". It doesn't even really have any concept of a "program" or a "process". It just executes instructions. So how can we make it do what we want?

This is where the operating system comes in, and specifically, the kernel, which is the core of the operating system. The kernel is a program. Would you be surprised if I told you that it is stored as an ELF file, assembled by an assembler, and linked by a linker? It is. The kernel is responsible for managing all of the resources of the computer, including the CPU. It is responsible for pointing the CPU at our program, and responsible for pointing the CPU away from our program. In other words, the kernel is responsible for setting the RIP register to point at our program's entry point address when the process starts, and taking care of where RIP points after our process exits.

A program can request to start another program by communicating with the kernel, and a program can also request to exit by communicating with the kernel. This is the life cycle of a process: it starts, it runs, it exits. The kernel is responsible for managing this life cycle.

One of the primary mechanisms for communicating with the kernel is the **system call** interface. A system call is a special instruction that a program can execute, and which ultimately causes RIP to point at kernel code. The kernel code handles the system call, sequentially executing kernel code instructions. When the kernel is done, it points RIP back at the instruction after the system call instruction, and the program continues executing (or not, in the case of the *exit* system call). It's really that simple. The kernel is just another program, and the CPU just executes instructions.

In fact, you could write your own kernel program, and maybe at some point, you will!

So how do we make a system call? Well, we need to execute a specific instruction, which is the system call instruction: `syscall`. It has no operands, and the CPU knows what to do when it sees it, because the kernel already told the CPU where to find the kernel code that handles system calls. How does the kernel know how to return to our program when its done? Well, when the `syscall` instruction executes, the CPU just puts the address of the next instruction in our program into the RCX register. The kernel knows to look there when it's done handling the system call, and to put that address back into RIP. It might seem a little arbitrary: why RCX? Well, that's just how it was designed, and it works. You'll see that there are a lot of *arbitrary* things in computing: we make a contract, and we stick to it, and it works.

One final question for now: if we want to make a system call, how do we specify which system call to make? The kernel has a list of system calls, and each system call has a number associated with it. As we already discussed, `syscall` has no operands, so how do we specify this number? Simple: by convention, we put the number of the system call we want to make in RAX before executing the `syscall` instruction. The kernel knows to look there to find out which system call we want to make.

So let's make our first system call! We'll use the *exit* system call, which on Linux, is system call number 60. We'll put that number in RAX, and then execute the `syscall` instruction. How convenient, we already wrote a program that will put 60 into RAX!

Exactly as we want, the *exit* system call, will exit our program, and so our program will not crash! And soon, we'll look at more system calls, and we'll be able to do more interesting things.

The curious among you might be wondering, where does RIP point after out program exits? We'll get there! For now, let's just say that's the kernel's responsibility, and it's not something we need to worry about.

Now go write this simple `exit-program` out to a file, assemble (`as`) it, link (`ld`) it, run it, `hexdump` it, `objdump` it, `readelf` it, `gdb` it. You should see that it doesn't crash, and that it all works as expected! Get comfortable with all these tools at your disposal, and make sure you understand what's going on; as you'll quickly realize: the devil is in the details.

When you're done having fun with your new program, go ahead and rerun the challenge, passing your program in as the first argument. *My program* will make sure that *your program* is correct, and then give you the flag.

```sh
$ {{ challenge_path }} program
```