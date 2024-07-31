#include "main.h"

/**
 * write_unsgn - prints unsigned integer
 * @is_neg: input
 * @ind: input
 * @buff: input
 * @f: flags
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */

int write_unsgn(int is_neg, int ind,
	char buff[],
	int f, int w, int p, int s)
{
	int len = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_neg);
	UNUSED(s);

	if (p == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')
		return (0);

	if (p > 0 && p < len)
		padd = ' ';

	while (p > len)
	{
		buff[--ind] = '0';
		len++;
	}
	if ((f & F_ZERO) && !(f & F_MINUS))
		padd = '0';
	if (w > len)
	{
		for (i = 0; i < w - len; i++)
			buff[i] = padd;

		buff[i] = '\0';
		if (f & F_MINUS)
		{
			return (write(1, &buff[ind], len) + write(1, &buff[0], i));
		}
		else
		{
			return (write(1, &buff[0], i) + write(1, &buff[ind], len));
		}
	}
	return (write(1, &buff[ind], len));
}

/**
 * convert_unsgn - prints an unsigned
 * @n: input
 * @size: input
 *
 * Return: int
 */

long int convert_unsgn(unsigned long int n, int size)
{
	if (size == S_LONG)
		return (n);
	else if (size == S_SHORT)
		return ((unsigned short)n);

	return ((unsigned int)n);
}

/**
 * printf_input_unsigned - prints an unsigned integer
 * @par: input
 * @buff: input
 * @f: flags
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */

int printf_input_unsigned(va_list par, char buff[],
		int f, int w, int p, int s)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(par, unsigned long int);

	num = convert_unsgn(n, size);

	if (num == 0)
		buff[i--] = '0';
	buff[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgn(0, i, b, f, w, p, s));
}
