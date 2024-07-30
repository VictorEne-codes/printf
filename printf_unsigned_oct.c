#include "main.h"

/**
 * printf_unsigned_oct - entry point prints unsigned octal number.
 * @par: is the arguments to be printed.
 * Return: the value of variable count.
 */
int printf_unsigned_oct(va_list par)
{
	int *arr;
	int i;
	int count = 0;
	unsigned int num = va_arg(par, unsigned int);
	unsigned int tmp = num;

	while (num / 8 != 0)
	{
		num /= 8;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));

	i = 0;
	while (i < count)
	{
		arr[i] = tmp % 8;
		tmp /= 8;
		i++;
	}
	i = count - 1;
	while (i >= 0)
	{
		_putchar(arr[i] + '0');
		i--;
	}
	free(arr);
	return (count);
}
