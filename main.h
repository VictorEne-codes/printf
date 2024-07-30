#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
int _printf(const char *format, ...);
int printf_37(void);
int printf_input_hexa(va_list par);
int printf_input_HEXA(va_list par);
int printf_unsigned_int(va_list par);
int printf_unsigned_oct(va_list par);
int printf_input_character(va_list par);
int printf_input_string(va_list par);
int printf_input_percentage(void);
int printf_input_int(va_list par);
int printf_input_dec(va_list par);
int printf_input_exclusive_string(va_list par);
int printf_HEX_helper(unsigned int n);
int printf_input_pointer(va_list par);
int printf_hex_helper(unsigned int n);
int printf_input_reverse_str(va_list par);
int find_strlen(char *c);
int find_strlens(const char *c);

#endif
