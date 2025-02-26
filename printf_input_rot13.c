#include "main.h"

/**
 * printf_input_rot13 - Entry point prints a string in rot13.
 * @par: inputs
 * @buff: array of input
 * @f: flag
 * @w: flag
 * @p: p
 * @s: s
 * Return: Numbers of chars printed
 */
int printf_input_rot13(va_list par, char buff[],
	int f, int w, int p, int s)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(par, char *);
	UNUSED(buff);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
