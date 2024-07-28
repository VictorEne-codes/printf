#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * convert_binary - converts unsigned int to bunary
 * @num: inout
 *
 * Return: char
 */

char *convert_binary(unsigned int num)
{
	char *bin_str;
	int i, len = sizeof(unsigned int) * 8;
	char *trimmed_bin_str;

	bin_str = (char *)malloc(len + 1);
	if (!bin_str)
	{
		return (NULL);
	}
	bin_str[len] = '\0';
	for (i = len - 1; i >= 0; i--)
	{
		bin_str[i] = (num & 1) ? '1' : '0';
		num >>= 1;
	}
	for (i = 0; bin_str[i] == '0' && bin_str[i + 1] != '\0'; )
	{
		i++;
	}
	trimmed_bin_str = strdup(bin_str + i);
	free(bin_str);
	return (trimmed_bin_str);
}

/**
 * int_to_bin - prints out binary from number
 * @format: input
 *
 * Return: void
 */

void int_to_bin(const char *format, ...)
{
	va_list arg;
	char *bin;
	unsigned int u;
	char *bin_ptr;

	va_start(arg, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'b':
				u = va_arg(arg, unsigned int);
				bin = convert_binary(u);
				if (bin)
				{
					bin_ptr = bin;
					while (*bin)
					{
						_putchar(*bin++);
					}
					free(bin_ptr);
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
		}
		format++;
	}
	va_end(arg);
}

int main()
{
	unsigned int num = 42;
	int_to_bin("The binary of %d is %b\n", num, num);
	return (0);
}
