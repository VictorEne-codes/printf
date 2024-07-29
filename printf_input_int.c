#include "main.h"
/**
 * printf_input_int - prints an integer
 * @val: is the argument to be printed
 * Return: the number of integers printed
 */
int printf_input_int(va_list val)
{
	int n = va_arg(val, int);
	int num, end = n % 10, digit, ex = 1;
	int  i = 1;

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
			digit = num / ex;
			_putchar(digit + '0');
			num -= (digit * ex);
			ex /= 10;
			i++;
		}
	}
	_putchar(end + '0');

	return (i);
}

/**
 * printf_input_dec - prints decimal
 * @val: the argument to be printed
 * Return: the number of integers printed
 */

int printf_input_dec(va_list val)
{
	int n = va_arg(val, int);
	int num, end = n % 10, digit;
	int  i = 1;
	int ex = 1;

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
			digit = num / ex;
			_putchar(digit + '0');
			num -= (digit * ex);
			ex /= 10;
			i++;
		}
	}
	_putchar(end + '0');

	return (i);
}

