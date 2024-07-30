#include "main.h"

/**
 * printf_input_bin - entry point prints binary numbers.
 * @par: the arguments to be printed.
 * Return: Always 1 if success.
 */
int printf_bin(va_list par)
{
	unsigned int num = va_arg(par, unsigned int);
	unsigned int p;
	int flg = 0;
	int cont = 0;
	int i, x = 1, y;

	i = 0;
	while (i < 32)
	{
		p = ((x << (31 - i)) & num);
		if (p >> (31 - i))
			flg = 1;
		if (flg)
		{
			y = p >> (31 - i);
			_putchar(y + 48);
			cont++;
		}
		i++;
	}
	if (cont == 0)
	{
		cont++;
		_putchar('0');
	}
	return (cont);
}
