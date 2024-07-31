#include "main.h"

/**
 * size_cast - entry point calculates the size for argument to be casted
 * @format: Formatted string where arguments are to be printed
 * @i: arguments list to be printed.
 *
 * Return: size.
 */
int size_cast(const char *format, int *i)
{
	int size = 0;
	int cur_i = *i + 1;

	if (format[cur_i] == 'l')
	{
		size = S_LONG;
	}
	else if (format[cur_i] == 'h')
	{
		size = S_SHORT;
	}
	if (size == 0)
	{
		*i = cur_i - 1;
	}
	else
	{
		*i = cur_i;
	}
	return (size);
}
