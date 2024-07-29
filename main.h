#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
int _printf(const char *format, ...);
int printf_input_int(va_list args);
int printf_input_dec(va_list args);
int printf_input_hexa(va_list par);
int printf_input_HEXA(va_list par);
int printf_input_HEXA_aux(unsigned int num);

#endif
