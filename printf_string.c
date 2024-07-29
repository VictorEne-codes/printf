#include "main.h"

/**
 * printf_string - function to print string to stdout
 * @val: input
 *
 * Return: int
 */

int printf_input_string(va_list val)
{
	char *string;
	int i = 0, length;

	string = va_arg(val, char *);
	if (string == NULL)
	{
		string = "(null)";
		length = _strlen(string);
		while (i < length)
		{
			_putchar(string[i]);
		}
		return (length);
	}
	else
	{
		length = _strlen(string);
		while (i < length)
		{
			_putchar(string[i]);
		}
		return (length);
	}
}
