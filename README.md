*This project has been created as part of the 42 curriculum by wkuay*

# ft_printf - Custom Implementation of C Standard printf

> A custom implementation of the standard C library `printf` function, written in C according to 42 School specifications, featuring variadic parameter handling and dynamic character counting.

## Overview

`ft_printf` is a key project in the 42 School curriculum. The objective is to recode the C standard library function `printf()`. The resulting function mimics the behavior of the original `printf`, managing variadic arguments using `<stdarg.h>` and returning the total number of printed characters while maintaining robust error handling across string format conversions.

This project compiles into a static library (`libftprintf.a`) which integrates existing functions from `libft`.

---

## Supported Format Specifiers

The `ft_printf` function handles the following standard conversions:

| Specifier | Description | Output Format |
| :--- | :--- | :--- |
| **`%c`** | Single character | Prints a single character |
| **`%s`** | String of characters | Prints a null-terminated string (or `(null)`) |
| **`%p`** | Pointer address | Prints a `void *` memory address in lowercase hex format (`0x...`) |
| **`%d`** | Signed decimal integer | Prints a base-10 signed integer |
| **`%i`** | Signed integer | Prints a base-10 signed integer |
| **`%u`** | Unsigned decimal integer | Prints a base-10 unsigned integer |
| **`%x`** | Hexadecimal integer | Prints a number in base-16 using lowercase letters (`0123456789abcdef`) |
| **`%X`** | Hexadecimal integer | Prints a number in base-16 using uppercase letters (`0123456789ABCDEF`) |
| **`%%`** | Percent sign | Prints a literal percent sign (`%`) |

---

## Algorithm & Data Structure

* **Parsing Loop:** The main ft_printf function iterates through the format string character by character. When it encounters a % symbol, it looks ahead to the next character (the format specifier).
* **Variadic Functions:** Utilizes `va_start`, `va_arg`, and `va_end` to parse dynamic parameter lists safely.
* **Helper Delegation:** The specifier character is passed to a modular helper function (ft_print_format), which routes execution to the correct printing function (ft_putchar, ft_putstring, ft_putnbr, ft_put_unsigned_nbr, or ft_puthex).
* **Recursion for Numbers:** Numeric printing (ft_putnbr, ft_puthex) uses recursive division by 10 or 16 to break numbers down into individual digits.
* **Unified Hex Logic:** Uses standard 64-bit unsigned representation (`unsigned long long`) to handle pointers (`%p`) and hexadecimals (`%x` / `%X`) through a single helper module.
* **Error Bubbling:** Every helper function checks output write statuses to guarantee that `write` errors (`< 0`) immediately halt output streams and bubble up `-1` to the caller.
* **`libft` Integration:** Seamlessly archives object files alongside `libft.a` into a single static library target (`libftprintf.a`).

---

## Getting Started

### Prerequisites
* `cc` compiler (supporting `-Wall -Wextra -Werror`)
* `make` utility

### Building the Library

1. Clone the repository:
   ```bash
   git clone []
   cd ft_printf
   ```

2. Compile the library (`libftprintf.a`):
   ```bash
   make
   ```

3. Other Makefile targets:
   ```bash
   make clean  # Removes object files (.o) for both ft_printf and libft
   make fclean # Removes object files (.o) and compiled library (libftprintf.a)
   make re     # Performs fclean and rebuilds the library from scratch
   ```

---

## Usage Example

To test or use `ft_printf` in your own C project:

1. Include the header in your C source file:
   ```c
   #include "ft_printf.h"

   int main(void)
   {
       int count;

       count = ft_printf("Hello %s! The magic number is %d (hex: %x).\n", "World", 42, 42);
       ft_printf("Printed %d characters.\n", count);
       return (0);
   }
   ```

2. Compile your executable linking against `libftprintf.a`:
   ```bash
   cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test_program
   ```

---

## Reference Resources
1. [Linux Manual Page: PRINTF(3)](https://man7.org/linux/man-pages/man3/printf.3.html)
2. [C Variadic Functions (stdarg.h)](https://en.cppreference.com/w/c/variadic)
3. [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html)

---

## AI Usage Disclosure
In accordance with 42 School guidelines, AI tools were utilized during this project for the following specific tasks:

1. **Architecture & Error Propagation Design:** Clarifying write-error bubbling logic (`write < 0`) across recursive integer and hexadecimal functions.
2. **Makefile Target Auditing:** Structuring archive operations (`ar rcs`) to cleanly merge `libft.a` with `ft_printf` object files.
3. **Norminette & Formatting Checks:** Reviewing function layouts to ensure compliance with 42 coding style standards and line limits.