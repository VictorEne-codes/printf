#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>


int _putchar(char c);
int _printf(const char *format, ...);
int printf_input_character(va_list val);
int printf_input_string(va_list val);
int printf_inputIpercentage(va_list val);
int printf_input_int(va_list args);
int printf_input_dec(va_list args);

#endif
