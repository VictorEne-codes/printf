#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * print_perc - print percent 
 * @format: input
 *
 * Return: void
 */

void print_perc(const char *format, ...)
{
	int i = 0;
	va_list arg;

	va_start(arg, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case '%':
				_putchar('%');
				i++;
				break;
			default:
				_putchar('%');
				_putchar(*format);
			}
		}
		else
		{
			_putchar(*format);
		}
		format++;
	}
	va_end(arg);
}

int main()
{
	print_perc("This is 50%%\n");
	print_perc("This is a %s\n", "boy");
	return (0);
}
