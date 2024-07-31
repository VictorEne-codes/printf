#include "main.h"

/**
 * precise_print - entry point calculates precision for printing
 * @format: Formatted string in which the arguments are to be printed
 * @i: arguments.
 * @list: arguments list.
 *
 * Return: Precision.
 */
int precise_print(const char *format, int *i, va_list list)
{
	int precision = -1;
	int cur_i = *i + 1;

	if (format[cur_i] != '.')
	{
		return (precision);
	}

	precision = 0;

	for (cur_i += 1; format[cur_i] != '\0'; cur_i++)
	{
		if (is_digit(format[cur_i]))
		{
			precision = precision * 10;
			precision = precision + format[cur_i] - '0';
		}
		else if (format[cur_i] == '*')
		{
			cur_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cur_i - 1;

	return (precision);
}
