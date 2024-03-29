# Analyzing ELF Files with *objdump*

As you can see, viewing the object file in this format is not very useful. It's just a bunch of bytes, what did you expect?!

Maybe you noticed the bytes "ELF" near the beginning of the file. This (and the 0x79 byte just before it) is the ELF "magic number", which is used to identify the file format. The other bytes have meaning too! This file format is usable by any program that knows how to correctly parse it.

One of such programs is `objdump`, which is a tool that can be used to analyze object files, and for example, disassemble them back into assembly code:

```sh
$ objdump -d -Mintel program.o
```

The `-d` flag here tells `objdump` to disassemble the object file, and the `-Mintel` flag tells it to use Intel syntax.

You'll notice that the output contains our very first assembly instruction, along with the `_start` label we defined. In addition to seeing the machine code represented back in assembly format, we can also see the bytes that make up the machine code represented in hexadecimal format. If you look carefully, you'll see those same bytes in the hexdump output at location `00000040`!

After you run `objdump`, figure out what the bytes of machine code are that make up your instruction. Please enter them as space-separated hex values, e.g. `00 01 02 03`.
