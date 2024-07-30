#include "main.h"

/**
 * printf_hex_helper - converts to hex
 * @n: input
 *
 * Return: int
 */

int printf_hex_helper(unsigned int n)
{
	int digits, i = 0;
	int *arr;
	int count = 0;
	unsigned int temp = n;

	while (n / 16 != 0)
	{
		n /= 16;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));

	while (i < count)
	{
		digits = temp % 16;
		if (digit < 10)
		{
			arr[i] = digit + '0';
		}
		else
		{
			arr[i] = digit - 10 + 'a';
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
