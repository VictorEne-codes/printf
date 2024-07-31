#include "main.h"

/**
 * is_digit - finds a digit
 * @c: input
 *
 * Return: int
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * precise_print - entry point calculates precision for printing
 * @format: input
 * @i: input
 * @par: input
 *
 * Return: int
 */

int precise_print(const char *format, int *i, va_list par)
{
	int p = -1;
	int cur_i = *i + 1;

	if (format[cur_i] != '.')
	{
		return (p);
	}

	p = 0;

	for (cur_i += 1; format[cur_i] != '\0'; cur_i++)
	{
		if (is_digit(format[cur_i]))
		{
			p = p * 10;
			p = p + format[cur_i] - '0';
		}
		else if (format[cur_i] == '*')
		{
			cur_i++;
			p = va_arg(par, int);
			break;
		}
		else
			break;
	}

	*i = cur_i - 1;

	return (p);
}
