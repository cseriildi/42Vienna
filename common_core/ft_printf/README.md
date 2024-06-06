# About the ft_printf project

## Summary
In this project, you have to recode the `printf()` function that you can add to your `libft` to use in later projects. You will learn about variadic functions.
- **Allowed external functions**: `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`
- **Prototype**: `int ft_printf(const char *str, ...);`

## Useful Stuff
- [Video explanation for variadic functions](https://youtu.be/oDC208zvsdg?si=t25PEgcDZSt8L0Ti)

## Mandatory Part

Implement the following conversions:
- `%c`: Prints a single character.
- `%s`: Prints a string.
- `%p`: Prints the address of a pointer in hexadecimal format.
- `%d`: Prints a decimal number.
- `%i`: Prints an integer.
- `%u`: Prints an unsigned decimal number.
- `%x`: Prints a number in hexadecimal lowercase format.
- `%X`: Prints a number in hexadecimal uppercase format.
- `%%`: Prints a percent sign.

## Bonus Part

- Manage any combination of the following flags:
	- `-`: Left-justify the output within the given field width.
	- `0`: Pad the output with leading zeros instead of spaces (except when left-justified).
	- `.`: Precision specifier, which defines the number of digits to be printed for numeric values or the maximum number of characters to be printed for strings.

- Manage all the following flags:
	- `#`: Alternate form; for `x` or `X` conversions, it prefixes `0x` or `0X` to the output, respectively; for `o` conversion, it ensures the output begins with a zero.
	- ` ` (space): If no sign is going to be written, a blank space is inserted before the value.
	- `+`: Forces a sign (`+` or `-`) to be placed before the number, even for positive numbers.