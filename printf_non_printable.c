#include "main.h"

/**
 * printf_non_printable - Entry point Prints ascii codes of non printable chars
 * @par: inputs
 * @buff: array of input
 * @f: flags
 * @w: flags
 * @p: precision
 * @s: size
 * Return: Number of chars printed
 */
int printf_non_printable(va_list types, char buff[],
	int f, int w, int p, int s)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);

	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
		{
			buff[i + offset] = str[i];
		}
		else
		{
			offset += append_hexa_code(str[i], buff, i + offset);
		}
		i++;
	}

	buff[i + offset] = '\0';

	return (write(1, buff, i + offset));
}

/**
 * is_printable - checks if a char is printable
 * @c: Char
 *
 * Return: 1 if printable, or 0 if not
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
	{
		return (1);
	}
	return (0);
}

/**
 * append_hexa_code - Entry point appends ascci code to buffer
 * @buff: Array of inputs.
 * @i: Index
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buff[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
	{
		ascii_code *= -1;
	}
	buff[i++] = '\\';
	buff[i++] = 'x';

	buff[i++] = map_to[ascii_code / 16];
	buff[i] = map_to[ascii_code % 16];

	return (3);
}

