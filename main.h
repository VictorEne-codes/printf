<<<<<<< HEAD
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#ifndef MAIN_H
#define MAIN_H

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

#define MINUS_FLG 1
#define PLUS_FLG 2
#define ZERO_FLG 4
#define HASH_FLG 8
#define SPACE_FLG 16

int _putchar(char c);
int _printf(const char *format, ...);
int printf_input_hexa(va_list par);
int printf_input_HEXA(va_list par);
int printf_unsigned_int(va_list par);
int printf_unsigned_oct(va_list par);
int printf_input_character(va_list par);
int printf_input_string(va_list par);
int printf_input_percentage(void);
int printf_input_int(va_list par);
int printf_input_dec(va_list par);
int printf_input_bin(va_list par);
int printf_input_exclusive_string(va_list par);
int printf_input_pointer(va_list par);
int printf_hex_helper(unsigned long int n);
int printf_HEX_helper(unsigned int n);
int printf_input_reverse_str(va_list par);
int find_strlen(char *c);
int find_strlens(const char *c);
int printf_input_rot13(va_list par);

/**
 * struct format - a structure to match the conversion specifiers
 * @id: d, i, u, o, x, X
 * @f: type pointer 
 */

typedef struct format
{
	char *id;
	int (*f)();
} format_match;


#endif
=======
>>>>>>> 104737c7cb6baed9d623d5d0afbcdb7cf9d4fd34
