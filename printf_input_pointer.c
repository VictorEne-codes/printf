#include "main.h"

int write_pointer(char buff[], int ind, int l,
		int w, int f, char padd, char extra_c, int padd_start);

/**
 * printf_input_pointer - Entry point Prints the value in a pointer variable
 * @par: inputs
 * @buff: array of input
 * @f: flags
 * @w: flags
 * @p: precision
 * @s: size
 * Return: Number of chars printed.
 */
int printf_input_pointer(va_list par, char buff[],
	int f, int w, int p, int s)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, l = 2, p_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(par, void *);

	UNUSED(w);
	UNUSED(s);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buff[BUFF_SIZE - 1] = '\0';
	UNUSED(p);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buff[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		l++;
	}

	if ((f & F_ZERO) && !(f & F_MINUS))
		padd = '0';
	if (f & F_PLUS)
		extra_c = '+', l++;
	else if (f & F_SPACE)
		extra_c = ' ', l++;

	ind++;

	return (write_pointer(buff, ind, l,
		w, f, padd, extra_c, p_start));
}

/**
 * write_pointer - Entry point writes memory address
 * @buff: array of inputs
 * @ind: Index
 * @l: length
 * @w: Width
 * @f: flags
 * @padd: padding
 * @extra_c: extra char
 * @padd_start: padding start
 *
 * Return: Number of written chars.
 */
int write_pointer(char buff[], int ind, int l,
	int w, int f, char padd, char extra_c, int padd_start)
{
	int i;

	if (w > l)
	{
		for (i = 3; i < w - l + 3; i++)
			buff[i] = padd;
		buff[i] = '\0';
		if (f & F_MINUS && padd == ' ')
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[ind], l) + write(1, &buff[3], i - 3));
		}
		else if (!(f & F_MINUS) && padd == ' ')
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[3], i - 3) + write(1, &buff[ind], l));
		}
		else if (!(f & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buff[--padd_start] = extra_c;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[padd_start], i - padd_start) +
				write(1, &buff[ind], l - (1 - padd_start) - 2));
		}
	}
	buff[--ind] = 'x';
	buff[--ind] = '0';
	if (extra_c)
		buff[--ind] = extra_c;
	return (write(1, &buff[ind], BUFF_SIZE - ind - 1));
}
