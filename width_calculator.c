#include "main.h"

/**
 * is_dig - finds a digit
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
 * calc_width -Entry point calculates width for printing
 * @format: input
 * @i: input
 * @par: input
 *
 * Return: int
 */

int calc_width(const char *format, int *i, va_list par)
{
	int w = 0;
	int cur_i;

	for (cur_i = *i + 1; format[cur_i] != '\0'; cur_i++)
	{
		if (is_digit(format[cur_i]))
		{
			w = w * 10;
			w = w + format[cur_i] - '0';
		}
		else if (format[cur_i] == '*')
		{
			cur_i++;
			w = va_arg(par, int);
			break;
		}
		else
		{
			break;
		}
	}

	*i = cur_i - 1;

	return (w);
}
