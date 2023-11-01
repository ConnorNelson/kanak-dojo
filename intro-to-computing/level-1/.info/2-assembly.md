# Writing Assembly

Now how do we create something that our processor can actually understand and run? The CPU executes machine code, some sequence of bytes; a bunch of bits that it interprets and acts on. We'll see what those bytes look like later, but for now, let's focus on how we can create those bytes and get them running on the CPU.

We'll write our program in a human-readable language called **assembly**, which some other program (the *assembler*) knows how to convert into machine code.

Take a step back, this is **super cool**: we're going to use a *program* that will take in our *human-readable program* as input to create a *computer-readable program* as output! As it turns out, what is code and what is data is just a matter of perspective. In this context, our assembly code is data, and the machine code it produces is code. Or is it? From the perspective of the CPU, isn't that machine code just data that the CPU is going to interpret? It's all just a bunch of bits, and what those bits mean is in the eye of the beholder.

Here is what your instruction looks like in a fully-formed assembly program:

```assembly
    .intel_syntax noprefix
    .global _start
_start:
    {{ instruction_asm }}
```

Let's break down the extra stuff that we've added before your instruction:
- `.intel_syntax noprefix`: This directive sets the assembly syntax to the Intel format, which is the standard we'll use here and `noprefix` ensures that register names don't need a `%` prefix.
- `.global _start`: This directive marks the `_start` label as global, meaning it can be accessed by external modules, such as the *linker* (we'll get there, it's yet another program).
- `_start:` is our starting label. Labels mark specific locations in the code, and in this case, `_start` marks the beginning of the program.

You might be thinking, why do we need all of this other garbage? Why can't we just run some assembly instructions?!

What we've written is simply a human-readable representation of machine code. The assembler, which we are about to use, will convert our assembly code into machine code for us. This extra stuff is just some metadata for the assembler program we're going to use, to give it necessary context about what we're trying to do. Be happy you aren't writing a stream of bits by hand! But guess what, if you don't like this workflow, you will soon be able to write a program of your own--that does what **you** want--maybe the *add-three-lame-lines-to-the-start* program; let the computer work for you!

Now, it's time for you to write this complete assembly program out to a file. The standard file extension for assembly files is `.s`, so let's call this file `program.s`.

Use your favorite text editor to create and edit the file `program.s`. Not sure which one to use? `vim`, `emacs`, `nano`, `VSCode`, and `gedit` are all good, popular options.

{% if user_environment == "vscode" %}
You can edit the file in VSCode by running the following command in the terminal:

```sh
$ code-server program.s
```

{% else %}
If you're not sure how to use any of these, give `nano` a try: you can use `Ctrl+O` to save, `Ctrl+X` to exit, and `Ctrl+G` to get help. You can launch it with:

```sh
$ nano program.s
```
{% endif %}

You might want to copy the code snippet up above before you launch up your text editor!