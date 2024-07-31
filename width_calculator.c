#include "main.h"

/**
 * calc_width -Entry point calculates width for printing
 * @format: Formatted string where arguments are to be printed.
 * @i: Arguments to be printed.
 * @list: Arguments list.
 *
 * Return: width.
 */
int calc_width(const char *format, int *i, va_list list)
{
	int width = 0;
	int cur_i;

	for (cur_i = *i + 1; format[cur_i] != '\0'; cur_i++)
	{
		if (is_digit(format[cur_i]))
		{
			width = width 10;
			width = width + format[cur_i] - '0';
		}
		else if (format[cur_i] == '*')
		{
			cur_i++;
			width = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}

	*i = cur_i - 1;

	return (width);
}
