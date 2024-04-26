# Memory

```assembly
    .intel_syntax noprefix
    .global _start
_start:
    mov rax, 60
    syscall
```

Now that we've written our first assembly program, let's take a look at what it looks like in machine code. We can use the `objdump` program to disassemble our program into machine code:

```sh

Correct answer:
mov rax, 60
syscall

Student answer:
mov 60, rax
syscall


```
mov rdi, OFFSET message
mov rsi, 13
mov rax, 1
syscall

mov rax, 60
syscall

message:
.ascii "Hello, world!\n"
```

Build a shell:
```
mov rdi, 0
mov rsi, 
```