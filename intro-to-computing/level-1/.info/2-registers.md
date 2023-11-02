# Registers in x86-64

Now that we've learned about bits and bytes, let's learn about how that data interacts with the processor. We will be using the x86-64 processor architecture, which is the architecture used by many modern computers. Inside the x86-64 processor architecture, there are specific storage locations known as "registers". These registers store data for quick access during processing.

Key registers in x86-64 include:

1. **RAX, RBX, RCX, RDX, RDI, RSI, R8, R9, R10**: General-purpose registers used for various tasks, including storing temporary data. These registers are 64 bits wide, meaning they can store 64 bits of data at a time. Don't worry about the names of these registers for now. We'll cover them in more detail later.

2. **RIP**: The instruction pointer, also known as the program counter. RIP holds the location, or address, of the next instruction that the processor will execute. As instructions are processed, RIP is updated to point to the subsequent instruction. This is also stored as a 64-bit value.

To demonstrate, let's place a value into one of these registers:

```assembly
mov rax, 5
```

Here, we're instructing the processor to store the value 5 into the RAX register.

Now, let's see how to "move" (or more accurately, copy) the value from one register to another:

```assembly
mov rbx, rax
```

This instruction copies the value from the RAX register to the RBX register. It's essential to note that the value in RAX remains unchanged; we've simply created a copy in RBX.

Now craft the instruction which stores the value {{ target_rax }} into the RAX register.
