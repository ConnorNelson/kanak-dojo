# Data Representation

Data is stored as bits, which are the smallest unit of data in a computer. A single bit can be though of as either a 0 or a 1. In physics, it's a lot simpler to represent on and off states (using voltage), compared to something like on, less on, even less on, kinda sorta on, and so on (10 distinct values) to represent "normal" (decimal) numbers.

A collection of bits can be used to represent a number, a character (like the letter "A"), a boolean value (true or false), or any other type of data. We simply need to agree on how to interpret the bits.

For example, a collection of bits can be used to represent the number 60. We can interpret a number by using the decimal number system. In this system, each digit in a number represents a power of 10. For example, the number 60 can be represented as `6 * 10^1 + 0 * 10^0`. In binary, the (decimal) number 60 is represented using 6 bits as 111100. We can interpret this number as `1 * 2^5 + 1 * 2^4 + 1 * 2^3 + 1 * 2^2 + 0 * 2^1 + 0 * 2^0 = 32 + 16 + 8 + 4 = 60`.