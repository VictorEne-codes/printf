<<<<<<< HEAD
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
=======
>>>>>>> 9e42b118ae100f2e90eb1db7af06b138333ad929
#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>


int _putchar(char c);
int _printf(const char *format, ...);
<<<<<<< HEAD
int printf_input_int(va_list args);
int printf_input_dec(va_list args);
int printf_input_hexa(va_list par);
int printf_input_HEXA(va_list par);
int printf_input_HEXA_aux(unsigned int num);

=======
int printf_input_character(va_list par);
int printf_input_string(va_list par);
int printf_input_percentage(void);
int printf_input_int(va_list par);
int printf_input_dec(va_list par);
int printf_input_exclusive_string(va_list par);
>>>>>>> 9e42b118ae100f2e90eb1db7af06b138333ad929
#endif
