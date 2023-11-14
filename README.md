#printf function custom implementation
##description
The printf function writes formatted output to stdout.
 This is a custom _printf() for learning purposes was developed by cohort #1 blended students Yunus Kedir and Dawit Yifru.
 _printf() function format string is a character string, beginning and ending in its initial shift state, if any.
 These arguments are placed using the percentage '%' operator</p>
## Prototype
```int _printf(const char *format, ...);```

## Usage
* Prints a string to the standard output, according to a given format
* All files were created and compiled on Ubuntu 20.04 LTS using GCC with the command ```gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c```
* Returns the number of characters in the output string on success, -1 otherwise
* Call it this way: ```_printf("format string", arguments...)``` where ```format string``` can contain conversion specifiers and flags,
along with regular characters

## Examples

* ```_printf("Hello, main\n")``` *prints "Hello, Main", followed by a new line*
* ```_printf("%s", "Hello")``` *prints "Hello"*
* ```_printf("This is a number: %d", 98)``` *prints "This is a number: 98"*

---

## Supported Format Types

TYPE - OUTPUT

c - Single character

s - String

r - String in reverse

R - String in rot13

d - Integer in decimal

i - integer

% - Percent sign

Xl - Lowercase hex

X - Uppercase hex

b - binary

o - octal

u - unsigned

p - pointer

F - expletive

## Authors
Yunus Kedir
Dawit Yifru
