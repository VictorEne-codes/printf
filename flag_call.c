#include "main.h"

/**
 * flg - entry point checks for active flags
 * @format: Formatted string in which arguments are to be printed
 * @i: is the given parameter.
 * Return: flag
 */
int flg(const char *format, int *i)
{
	int j, cur_i;
	int flag = 0;
	const char flag_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flag_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cur_i = *i + 1; format[cur_i] != '\0'; cur_i++)
	{
		for (j = 0; flag_CH[j] != '\0'; j++)
			if (format[cur_i] == flag_CH[j])
			{
				flag |= flag_ARR[j];
				break;
			}

		if (flag_CH[j] == 0)
		{
			break;
		}
	}

	*i = cur_i - 1;

	return (flag);
}
