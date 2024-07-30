#include "main.h"

/**
 * printf_input_exclusive_string - print all exclusive strings in ASCII
 * @par: input
 *
 * Return: int
 */

int printf_input_exclusive_string(va_list par)
{
	char *string;
	int i = 0, length = 0;
	int count;

	string = va_arg(par, char *);
	if (string == NULL)
	{
		string = "(null)";
	}
	while (string[i] != '\0')
	{
		if (string[i] < 32 || string[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			length = length + 2;
			count = string[i];
			if (count < 16)
			{
				_putchar('0');
				length++;
			}
			length = length + printf_HEX_helper(count);
		}
		else
		{
			_putchar(string[i]);
			length++;
		}
		i++;
	}
	return (length);
}
