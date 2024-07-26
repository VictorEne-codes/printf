#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * print_str - function to print out strings
 * @format: input
 *
 * Return void
 */

void print_str(const char *format, ...)
{
	int i = 0;
	char *s;
	va_list arg;

	va_start(arg, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 's':
				s = va_arg(arg, char *);
				while (*s != '\0')
				{
					_putchar(*s);
					i++;
					s++;
				}
				break;
			default:
				_putchar('%');
				_putchar(*format);
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
