# Analyzing ELF Files with *readelf*

Another tool for examining ELF files is `readelf`. Let's go ahead and use it to examine the executable's headers:

```sh
$ readelf -h program
```

The `-h` flag tells `readelf` to display the ELF file's headers.


With readelf, we can see the ELF file's headers. The headers contain metadata about the ELF file, such as the ELF file's type, machine architecture, entry point, and more.

Pay special attention to the the "Entry point address". When the ELF file is executed, the program will begin executing at this address, or in more technical terms, RIP will be set to this value. If you're paying attention, you'll notice that this value is exactly the same as what you might expect after reading the output of `objdump`!

Why that address? Well, the linker decided that's a good spot for your machine code to go! If we want to change that location, we *can*, but let's not worry about that for now.
