# Linking

Over the course of developing a full program, we might have multiple object files that we want to link together into a single executable file. This modular approach to programming is very common, and will show up again and again, as it allows us to split up a program into multiple sub-programs, enabling us to only have to think about a single sub-program at a time, and reuse our sub-programs. This is where the *linker* comes in.

The linker is responsible for linking multiple object files together into a single executable file. The linker is also responsible for resolving and assigning addresses to the labels in our code. If you pay attention to the output of running `objdump` against the object file, you'll notice that the `_start` label in the object file has an address of `0000000000000000`. This is because the object file does not yet have addresses assigned to the labels. The linker will assign addresses to the labels when it links the object file into an executable file.

Here is how we can invoke the linker:

```sh
$ ld -o program program.o
```

This command invokes the linker (`ld`) and instructs it to link the object file at `program.o` into an executable file at `program`. The `-o` flag specifies the output file path. You'll notice that the format of this command is very similar to the format of the command we used to invoke the assembler. As an aside, if we wanted to actually link multiple object files together, we would simply list them all as arguments to the linker, with more paths separated by spaces after `program.o`.

The executable file is a binary file containing the machine code for your program. Like the object file, the executable file is also stored in the ELF file format, which is the standard format for executable files on Linux. As a reminder ELF stands for "Executable and Linkable Format". In this case, our ELF file is now executable.

Now go forth and link your program, and then run the `hexdump` and `objdump` as we did before, but now against the executable file to see what it looks like!
