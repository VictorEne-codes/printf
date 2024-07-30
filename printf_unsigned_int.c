#include "main.h"
/**
 * printf_unsigned_int - entry point prints integer
 * @par: the argument to be printed
 * Return: the number of integers printed
 */
int printf_unsigned_int(va_list par)
{
	int  i = 1;
	int num, end = n % 10, dgt, ex = 1;
	unsigned int n = va_arg(par, unsigned int);

	n /= 10;
	num = n;

	if (end < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		end = -end;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			ex *= 10;
			num /= 10;
		}
		num = n;
		while (ex > 0)
		{
			dgt = num / ex;
			_putchar(dgt + '0');
			num -= (dgt * ex);
			ex /= 10;
			i++;
		}
	}
	_putchar(end + '0');

	return (i);
}
