#include "main.h"

/**
 * printf_input_pointer - prints pointer to stdout
 * @par: inpit
 *
 * Return: int
 */

int printf_input_pointer(va_list par)
{
	void *pointer;
	char *string = "(nil)";
	long int a;
	int b;
	int i;

	pointer = va_arg(par, void*);
	if (pointer == NULL)
	{
		for (i = 0; string[i] != '\0'; i++)
		{
			_putchar(string[i]);
		}
		return (i);
	}

	a = (unsigned long int)pointer;
	_putchar('0');
	_putchar('x');
	b = printf_hex_helper(a);
	return (b + 2);
}
