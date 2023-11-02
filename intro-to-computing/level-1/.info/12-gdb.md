# GDB

Welcome to `gdb`! This is one of the most important tools you'll ever use. It will allow you to step through your program, one instruction at a time if you want to, and inspect the state of the CPU, registers, and memory at any point in time.

It is another program! This program doesn't produce programs like `as` and `ld`, or *statically* analyze them like `objdump` or `readelf`: it *dynamically* analyzes them as they are running! How cool is that?! It's a program that *dynamically* analyzes other programs as they are running! Are you starting to feel how powerful a program can be? You could actually create any of these programs yourself, they're just programs!

Here's how we can start `gdb`:

```sh
$ gdb -q program
```

The `-q` flag here tells `gdb` to run in "quiet" mode, which means it won't print a bunch of (uninteresting) stuff when it starts up. What you'll see is:

```
Reading symbols from program...
(No debugging symbols found in program)
(gdb)
```

`gdb` knows how to parse ELF files, and find symbols. Labels are symbols, and so `gdb` will find the `_start` label in our program. However, it doesn't know how to find "debugging symbols" in our program because we didn't build it with debugging symbols. Debugging symbols aren't super important for us right now, so we'll ignore this warning.

Like your shell which you use to run programs, `gdb` is an interactive program. It will display a `(gdb)` prompt, and wait for you to enter a command. Here are some of the important commands to know for now:

- `starti`: Start execution of the program, and stop before executing the first instruction.
- `si`: Step one instruction, or in other words, execute one instruction and then stop.
- `p $rax`: Print the value of the RAX register. You can also print the value of any other register (or any other expression).
- `x/i $rip`: Examine memory at the address stored in the RIP register, and display it as one instruction. The `x` command can take on several different forms, and is very powerful for understanding the state of memory. We'll learn more about the other ways it can be used later.
- `quit`: Quit `gdb`!

There are many more commands, and we'll explore them as we go. `gdb` is a language in its own right. For now, let's focus on these.

So how do we answer our question: is my instruction running and working as expected? Well, let's try it out! Here's the sequence of commands that will answer your question:

- `starti`: Let's start the program.
- `x/i $rip`: Let's see what instruction the CPU is about to execute: is it what I expect?
- `p $rax`: Let's see what the current value of RAX is.
- `si`: Let's execute one instruction.
- `p $rax`: Let's see what the new value of RAX is: is it what I expect?
- `x/i $rip`: Let's see what the next instruction the CPU is about to execute: is it what I expect?
- `si`: Let's execute one more instruction.
- `quit`: Let's quit `gdb`.

Your task in debugging with `gdb` is figuring out how to translate your question into a falsifiable hypothesis, and then figuring out how to experimentally test that hypothesis with the right sequence of `gdb` commands. This is as much an art as it is a science, and it takes practice. Don't worry, you'll get there!

Now, let's try it out! Start `gdb` (in quiet mode) and run the sequence of commands above. What is the value of RAX after executing the instruction?
