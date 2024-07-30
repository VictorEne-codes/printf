#include "main.h"

/**
 * printf_input_string - function to print string to stdout
 * @par: input
 *
 * Return: int
 */

int printf_input_string(va_list par)
{
	char *string;
	int i = 0, length;

	string = va_arg(par, char *);
	if (string == NULL)
	{
		string = "(null)";
		length = find_strlen(string);
		while (i < length)
		{
			_putchar(string[i]);
		}
		return (length);
	}
	else
	{
		length = find_strlen(string);
		while (i < length)
		{
			_putchar(string[i]);
		}
		return (length);
	}
}
