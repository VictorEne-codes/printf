#include "main.h"

/**
 * printf_input_hexa - entry point prints an hexadecimal number.
 * @par: arguments to be printed.
 * Return: the value of variable count.
 */
int printf_input_hexa(va_list par)
{
	int *arr;
	int i;
	int count = 0;
	unsigned int num = va_arg(par, unsigned int);
	unsigned int tmp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));

	i = 0;
	while (i < count)
	{
		arr[i] = tmp % 16;
		tmp /= 16;
		i++;
	}

	i = count - 1;
	while (i >= 0)
	{
		if (arr[i] > 9)
			arr[i] = arr[i] + 39;
		_putchar(arr[i] + '0');
		i--;
	}
	free(arr);
	return (count);
}
