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
	int i = 0;

	pointer = va_arg(par, void*);
	if (pointer == NULL)
	{
		while (string[i] != '\0')
		{
			_putchar(string[i]);
			i++;
		}
		return (i);
	}

	a = (unsigned long int)pointer;
	_putchar('0');
	_putchar('x');
	b = printf_hex_aux(a);
	return (b + 2);
}
