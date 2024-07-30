#include "main.h"

/**
 * handle_flags - function to handle flags
 * @format: input
 * @n: input
 *
 * Return: int
 */

int handle_flags(const char *format, int *n)
{
	int i, j;
	int flags = 0;
	const char ch[] = {'-', '+', '0', '#', ' ', '\0'};
	const int arr[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (i = *n + 1; format[n] != '\0'; n++)
	{
		for (j = 0; ch[j] != '\0'; j++)
			if (format[n] == ch[j])
			{
				flags |= arr[j];
				break;
			}

		if (ch[j] == 0)
			break;
	}

	*n = i - 1;

	return (flags);
}
