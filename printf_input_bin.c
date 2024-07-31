#include "main.h"

/**
 * printf_input_bin - prints a binary value of integer
 * @par: input
 * @buff: input
 * @f: flags
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */

int printf_input_bin(va_list par, char buff[],
		int f, int w, int p, int s)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int counter;

	UNUSED(buff);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);

	n = va_arg(par, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, counter = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			counter++;
		}
	}
	return (counter);
}
