#include "main.h"

/**
 * printf_char_helper - helps prints a character
 * @buff: input
 * @c: input
 * @f: flags
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */

int printf_char_helper(char c, char buff[],
	int f, int w, int p, int s)
{
	int i = 0;
	char padd = ' ';

	UNUSED(p);
	UNUSED(s);

	if (f & F_ZERO)
		padd = '0';

	buff[i++] = c;
	buff[i] = '\0';

	if (w > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < w - 1; i++)
			buff[BUFF_SIZE - i - 2] = padd;

		if (f & F_MINUS)
			return (write(1, &buff[0], 1) +
					write(1, &buff[BUFF_SIZE - i - 1], w - 1));
		else
			return (write(1, &buff[BUFF_SIZE - i - 1], w - 1) +
					write(1, &buff[0], 1));
	}
	return (write(1, &buff[0], 1));
}

/**
 * printf_input_char - prints a character
 * @par: input
 * @buff: input
 * @f: flags
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */

int printf_input_char(va_list par, char buff[],
	int f, int w, int p, int s)
{
	char c = va_arg(par, int);

	return (printf_char_helper(c, buff, f, w, p, s));
}
