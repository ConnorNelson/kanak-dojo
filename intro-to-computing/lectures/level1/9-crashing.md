# Crashing

You better get used to "Segmentation fault (core dumped)". You'll see it a lot.

Your program just crashed! What happened? Well, your `mov` instruction executed just fine, but then what?

The CPU executes instructions sequentially. It started execution at the "Entry point address", where your `mov` instruction was located. It faithfully executed it, setting RAX to {{ target_rax }}. As it turns out though, `mov` doesn't only affect RAX, it also affects RIP! RIP was set to the address of the next instruction. Our `mov` instruction is 7 bytes long, so RIP was incremented by 7, and now RIP points to the next instruction after the `mov` instruction. Then, the machine code located *there* was executed.

But you didn't put any machine code there! The machine code that was there is just whatever happened to be in memory at that location. In this case, it was some random bytes, which the CPU tried to interpret as an instruction. It didn't work, and the program crashed. In this particular case it crashed with a "Segmentation fault", which is a common error that occurs when a program tries to access memory that it doesn't have permission to access. We'll learn more about this later.

When the program crashed, it also dumped a "core" file. This is a file that contains a snapshot of the program's memory and state of all of the registers at the time of the crash. Guess what? This file is also an ELF file!

Go ahead and run `ls` to see the files in your current directory. You should see a file which starts with `core.`. This is the core file that was dumped when your program crashed.

If you have already crashed your program a view times, you may see multiple core files. You can delete them with `rm core.*`. For now, just consider any one of them.