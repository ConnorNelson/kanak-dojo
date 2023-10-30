# Analyzing Files with *hexdump*

Take a look at the object file's contents using the `hexdump` command:

```sh
$ hexdump -C program.o
```

This is going to produce a hexdump of the object file's contents. This is a common way to view binary data. Each line represents 16 bytes of data. The first column shows the offset of the data in the file, and the second column shows the data in hexadecimal format. The third column shows the data in ASCII format, with non-printable characters replaced by `.`.
