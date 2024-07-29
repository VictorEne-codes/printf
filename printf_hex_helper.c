#include "main.h"

/**
 * printf_hex_helper - converts to hex
 * @n: input
 *
 * Return: int
 */

int printf_hex_helper(unsigned int n)
{
	int i = 0;
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

	while (i < counter)
	{
		arr[i] = temp % 16;
		temp /= 16;
		i++;
	}
	i = count - 1;
	while (i >= 0)
	{
		if (arr[i] > 9)
		{
			arr[i] = arr[i] + 39;
		}
		_putchar(arr[i] + '0');
		i--;
	}
	free(arr);
	return (count);
}
