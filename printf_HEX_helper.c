#include "main.h"

/**
 * printf_HEX_helper - convert to hex
 * @n: input
 *
 * Return: int
 */

int printf_HEX_helper(unsigned int n)
{
	int digit, i = 0;
	int *arr;
	int count = 0;
	unsigned int temp = n;

	while (n / 16 != 0)
	{
		n /= 16;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(char));
	while (i < count)
	{
		digit = temp % 16;
		if (digit < 10)
		{
			arr[i] = digit + '0';
		}
		else
		{
			arr[i] = digit - 10 + 'A';
		}
		temp /= 16;
		i++;
	}
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(arr[i]);
	}
	free(arr);
	return (count);
}
