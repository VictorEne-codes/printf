#include "main.h"

/**
 * printf_input_rev_str - Prints reverse string.
 * @par: inputs
 * @buff: array of input
 * @f: flag
 * @w: flag
 * @p: p
 * @s: s
 * Return: Numbers of chars printed
 */

int printf_input_rev_str(va_list par, char buff[],
	int f, int w, int p, int s)
{
	char *str;
	int i, count = 0;

	UNUSED(buff);
	UNUSED(f);
	UNUSED(w);
	UNUSED(s);

	str = va_arg(par, char *);

	if (str == NULL)
	{
		UNUSED(p);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
