#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - function to print out characters
 * @format: input
 *
 * Return: void
 */
void print_char(const char *format, ...)
{
	va_list arg;
	int i;
	char c;

	va_start(arg, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format){
				case 'c':
					c = (char)va_arg(arg, int);
					_putchar(c);
					i++;
					break;
				default:
					_putchar('%');
					i++;
			}
		}
		else
		{
			_putchar(*format);
			i++;
		}
		format++;
	}
	va_end(arg);
}
