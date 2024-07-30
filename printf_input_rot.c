#include "main.h"

/**
 * printf_input_rot13 - entry point converts str to ROT13
 * @par: type struct va_arg where is allocated printf arguments
 * Return: the value of variable count
 *
 */
int printf_input_rot13(va_list par)
{
	int i, j, count = 0, x = 0;
	char *s = va_arg(par, char*);
	char alpha[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char beta[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (s == NULL)
	{
		s = "(null)";
	}
	for (i = 0; s[i]; i++)
	{
		x = 0;
		for (j = 0; alpha[j] && !x; j++)
		{
			if (s[i] == alpha[j])
			{
				_putchar(beta[j]);
				count++;
				x = 1;
			}
		}
		if (!x)
		{
			_putchar(s[i]);
			count++;
		}
	}
	return (count);
}
