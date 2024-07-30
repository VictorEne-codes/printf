#include "main.h"

/**
 * printf_HEX_helper - convert to hex
 * @n: input
 *
 * Return: int
 */

int printf_HEX_helper(unsigned long int n)
{
	long int i;
	long int *arr;
	long int count = 0;
	unsigned long int temp = n;

	while (n / 16 != 0)
	{
		n /= 16;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(long int));

	for (i = 0; i < count; i++)
	{
		arr[i] = temp % 16;
		temp /= 16;
	}
	for (i = count - 1; i >= 0; i--)
	{
		if (arr[i] > 9)
		{
			arr[i] = arr[i] + 7;
		}
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}
