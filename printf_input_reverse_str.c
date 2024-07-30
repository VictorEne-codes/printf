#include "main.h"

/**
 * printf_input_reverse_str - prints strings in reverse
 * @par: input
 *
 * Return: int
 */

int printf_input_reverse_str(va_list par)
{
	char *string = va_arg(par, char*);
	int i;
	int j = 0;

	if (string == NULL)
	{
		string = "(null)";
	}
	while (string[j] != '\0')
	{
		j++;
	}
	i = j - 1;
	while (i >= 0)
	{
		_putchar(string[i]);
		i--;
	}
	return (j);
}
