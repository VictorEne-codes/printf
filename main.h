#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>


int _putchar(char c);
int _printf(const char *format, ...);
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

#endif
