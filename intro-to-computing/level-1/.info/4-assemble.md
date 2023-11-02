# Assembling

Now it's time to actually assemble your program using the assembler. This is how we can invoke the assembler:

```sh
$ as -o program.o program.s
```

This command invokes the assembler (`as`) and instructs it to assemble the assembly file at `program.s` into an object file at `program.o`. The `-o` flag specifies the output file path.

The object file is a binary file containing the machine code for your program. This object file is stored in the ELF file format, which is the standard format for object files on Linux. ELF stands for "Executable and Linkable Format". In this case, the object file our assembler produces will be linkable (often referred to as relocatable), but not yet executable.

Now go forth and assemble your program!
