#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

void print_int(int num)
{
	if (num == 0)
	{
		_putchar('0');
		return;
	}
	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}

	int ncount = 0;
	int temp_num = num;

	while (temp_num > 0)
	{
		temp_num /= 10;
		ncount++;
	}
	
	char *buffer = (char *)malloc(ncount * sizeof(char));

	int i = 0;
	while (num > 0)
	{
		buffer[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	int j;

	for (j = i - 1; j >= 0; j--)
	{
		_putchar(buffer[j]);
	}
	free(buffer);
}

int main()
{
	print_int(2024);
	_putchar('\n');
}
