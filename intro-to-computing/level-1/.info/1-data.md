# Computation and Data

At the most basic level, a computer is a machine that can perform computation. Computation is a process that takes some input and produces some output. For example, a calculator is a simple computer that takes some numbers and operators as input and produces a number as output. Modern computers are much more complex, but they are still fundamentally just machines that perform computation.

Data is stored as bits, which are the smallest unit of data in a computer. A single bit can be thought of as either a 0 or a 1. In physics, it's a lot simpler to represent on and off states (using voltage), compared to something like on, less on, even less on, kinda sorta on, and so on (10 distinct values) to represent "normal" (decimal) numbers.

A sequence of bits can be used to represent a number, a character (like the letter "A"), a boolean value (true or false), or **any** other type of data. We simply need to agree on how to interpret the bits.

For example, a sequence of bits can be used to represent the number 65. You're probably used to interpreting a number by using the decimal number system. In this system, each digit in a number represents a power of 10. The number 65 can be represented as `6(10¹) + 5(10⁰) = 65`. In binary, each symbol in a number represents a power of 2. So, the (decimal) number 65 is represented as 1000001. We can interpret this number as `1(2⁶) + 0(2⁵) + 0(2⁴) + 0(2³) + 0(2²) + 0(2¹) + 1(2⁰) = 64 + 1 = 65`. In the same way that we can perform addition and subtraction with decimal numbers, we can perform addition and subtraction with binary numbers—"carry the 1" is the same in both systems!

Numbers aren't the only thing we can represent with bits though, we can also represent characters. The letter "A", for example, is represented as 1000001 in the ASCII character encoding, and "B" is 1000010. If you noticed that's the same value as the decimal numbers 65 and 66, you're right! What bits mean is in the eye of the beholder. Some computation might be treating those bits as a number, performing math on it, or treating it as a character, using it to find a glyph in a font file and display it on the screen: it just depends on the computation being performed, and how us people decide to assign meaning to it all.

We can come up with all sorts of schemes. We might decide that 100 means "permission to read", 010 means "permission to write", and 110 means "permission to read and write". We can then use these bits to represent the permissions for a file. Or we can group together a few million bits and use them to represent an image (jpeg, png), or document (pdf). We can use bits to represent anything we want, as long as we agree on what the bits mean.

Long sequences of 1s and 0s are hard to think about and look at. To make it slightly easier we can group bits together into bytes. A byte is a sequence of 8 bits. 8 bits gives us `2⁸ = 256` unique values. Rather than binary, which has 2 symbols (0-1) to represent 2 values, or decimal, which has 10 symbols (0-9) to represent 10 values, we can represent these values using hexadecimal, which has 16 symbols to represent 16 values. Binary was easy for our symbols, we just got rid of 2-9, so what do we do for hexadecimal? We simply use the letters A-F to represent the values 10-15! The number 65 can be represented as 41 in hexadecimal (`4(16¹) + 1(16⁰) = 65`). Since it's hard to know if that 41 is decimal or hexadecimal, when it might be more ambiguous, we often prefix hexadecimal numbers with 0x, so 0x41—or we might not! In the same way we don't specify in every day life that by 65 we mean decimal 65, when we're talking about bytes, we often just assume that we mean hexadecimal. So if you see `41 42 43` you might assume that we mean the bytes `0x41 0x42 0x43`, or decimal numbers `65 66 67`, or ASCII characters `A B C`. It's all just a matter of perspective.

Now, to make sure we're on the same page, let's look at some bits. Here are 8 bits:

```
00111100
```

Figure out what these bits mean, and then write the corresponding number in decimal and hexadecimal. Then figure out what the corresponding ASCII character is. An ASCII table might be helpful!
