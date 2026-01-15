
*This project has been created as part of the 42 curriculum by cabboud.*

# ft_printf

## Description

`ft_printf` is a custom implementation of the standard C `printf` function.  
The goal of this project is to reproduce the core behavior of `printf` while respecting strict constraints imposed by the 42 curriculum, such as limited use of standard library functions and a strong focus on low-level programming concepts.

This project provides formatted output conversion and printing, supporting a subset of the original `printf` format specifiers. It is designed to deepen understanding of:
- Variadic functions
- Memory representation
- Number base conversions
- Recursion
- Modular and reusable code design in C

## Supported Conversions

The implementation supports the following format specifiers:

| Specifier | Description |
|---------|-------------|
| `%c` | Print a character |
| `%s` | Print a string |
| `%p` | Print a pointer address |
| `%d` / `%i` | Print a signed integer |
| `%u` | Print an unsigned integer |
| `%x` | Print a hexadecimal number (lowercase) |
| `%X` | Print a hexadecimal number (uppercase) |
| `%%` | Print a percent sign |

## Instructions

### Compilation

To compile the project, simply run:

```bash
make
````

This will generate a static library named `libftprintf.a`.

To clean object files:

```bash
make clean
```

To remove all compiled files:

```bash
make fclean
```

To recompile everything:

```bash
make re
```

### Usage

Include the header file in your C project:

```c
#include "ft_printf.h"
```

Link the library when compiling:

```bash
gcc main.c libftprintf.a
```

Example usage:

```c
ft_printf("Hello %s, number: %d\n", "world", 42);
```

## Project Structure

```c
.
├── ft_printf.c // Core ft_printf function that parses the format string and dispatches conversions
├── ft_printf.h // Header file containing function prototypes and required includes for ft_printf
├── ft_print_char.c // Handles printing of single characters and returns the printed length
├── ft_print_string.c // Handles printing of strings with NULL protection and length counting
├── ft_print_number.c // Handles printing of signed decimal integers using recursion
├── ft_print_unsigned.c // Handles printing of unsigned integers in base 10
├── ft_print_hexa.c // Handles printing of hexadecimal numbers in lowercase or uppercase
├── ft_print_pointer.c // Handles printing of memory addresses in hexadecimal format with 0x prefix
├── Makefile # Compiles and manages the ft_printf static library build rules
└── README.md
```

Each conversion is handled in a dedicated source file to ensure clarity, modularity, and ease of maintenance.

## Algorithm & Data Structure Explanation

### Core Algorithm

The main function `ft_printf` follows this algorithm:

1. Iterate through the format string character by character.
2. When a `%` is encountered:

   * The next character determines the conversion type.
   * Dispatch to the appropriate helper function.
3. Each helper function prints its value and returns the number of characters printed.
4. Accumulate and return the total printed length.

### Variadic Arguments

The project uses:

```c
va_list   // Declares a variable to manage access to variadic function arguments
va_start  // Initializes the va_list to retrieve arguments after the last named parameter
va_arg    // Retrieves the next argument from the va_list with a specified type
va_end    // Cleans up the va_list after finishing argument processing
```

to retrieve an unknown number of arguments at runtime.
This allows `ft_printf` to behave like the real `printf`.

### Number Conversion Strategy

* **Decimal numbers** are printed using **recursion**, dividing by 10 until a single digit is reached.
* **Hexadecimal numbers** are converted by repeatedly dividing by 16 and indexing into a base string.
* **Pointers** are printed by:

  * Casting the address to `unsigned long`
  * Printing a `0x` prefix
  * Printing the address in hexadecimal format

This approach avoids dynamic memory allocation and ensures compliance with 42 rules.

### Data Structures

No complex data structures are used.
The project relies on:

* Primitive types (`int`, `unsigned int`, `unsigned long`)
* `va_list` for argument handling
* Constant character arrays as number bases

This choice keeps the implementation efficient, simple, and deterministic.

## Technical Choices

* **Recursive printing** instead of buffers to simplify logic and avoid memory allocation.
* **Separation of concerns**: one file per conversion type.
* **Low-level output** using `write`.

These decisions align with best practices for constrained C environments.

## Testing

A minimal main.c was used during development to validate all mandatory conversions, edge cases, and mixed format strings by comparing the output with the standard printf.

```c
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
    ft_printf("Char: %c\n", 'A');
    printf("Char: %c\n\n", 'A');

    ft_printf("String: %s\n", "Hello");
    printf("String: %s\n\n", "Hello");

    ft_printf("NULL string: %s\n", (char *)0);
    printf("NULL string: %s\n\n", (char *)0);

    ft_printf("Pointer: %p\n", "test");
    printf("Pointer: %p\n\n", "test");

    ft_printf("NULL pointer: %p\n", (void *)0);
    printf("NULL pointer: %p\n\n", (void *)0);

    ft_printf("Int: %d %i\n", 42, -42);
    printf("Int: %d %i\n\n", 42, -42);

    ft_printf("INT_MIN INT_MAX: %d %d\n", INT_MIN, INT_MAX);
    printf("INT_MIN INT_MAX: %d %d\n\n", INT_MIN, INT_MAX);

    ft_printf("Unsigned: %u\n", UINT_MAX);
    printf("Unsigned: %u\n\n", UINT_MAX);

    ft_printf("Hex: %x %X\n", 48879, 48879);
    printf("Hex: %x %X\n\n", 48879, 48879);

    ft_printf("Mix: %c %s %p %d %u %x %%\n",
            'Z', "42", "ptr", -123, 42u, 42u);
    printf("Mix: %c %s %p %d %u %x %%\n",
            'Z', "42", "ptr", -123, 42u, 42u);

    return (0);
}
```

### Compilation
```c
gcc main.c libftprintf.a && ./a.out
```

## Resources

### Documentation & References

* https://linux.die.net/man/3/printf
* https://en.cppreference.com/w/c/variadic.html
* https://www.geeksforgeeks.org/c/variadic-functions-in-c/
