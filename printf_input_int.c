#incude "main.h"

/**
 * write_num - writes out a number
 * @padd: input
 * @extra_c: input
 * @ind: input
 * @buff: input
 * @f: flags
 * @len: input
 * @w: width
 * @p: precision
 *
 * Return: int
 */

int write_num(int ind, char buff[],
	int f, int w, int p,
	int len, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (p == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0' && w == 0)
		return (0);
	if (p == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')
		buff[ind] = padd = ' ';
	if (p > 0 && p < len)
		padd = ' ';
	while (p > len)
		buff[--ind] = '0', len++;
	if (extra_c != 0)
		len++;
	if (w > len)
	{
		for (i = 1; i < w - len + 1; i++)
			buff[i] = padd;
		buff[i] = '\0';
		if (f & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[ind], len) + write(1, &buff[1], i - 1));
		}
		else if (!(f & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[1], i - 1) + write(1, &buff[ind], len));
		}
		else if (!(f & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buff[--padd_start] = extra_c;
			return (write(1, &buff[padd_start], i - padd_start) +
				write(1, &buff[ind], len - (1 - padd_start)));
		}
	}
	if (extra_c)
		buff[--ind] = extra_c;
	return (write(1, &buff[ind], len));
}

/**
 * write_numbers - writes a number
 * @is_neg: input
 * @ind: input
 * @buff: input
 * @f: flags
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */

int write_numbers(int is_neg, int ind, char buff[],
		int f, int w, int p, int s)
{
	int len = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(s);

	if ((f & F_ZERO) && !(f & F_MINUS))
		padd = '0';
	if (is_neg)
		extra_ch = '-';
	else if (f & F_PLUS)
		extra_ch = '+';
	else if (f & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buff, f, w, p,
		len, padd, extra_ch));
}

/**
 * printf_input_int - prints a string
 * @par: input
 * @buff: input
 * @f: flags
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */

int printf_input_int(va_list par, char buff[],
		int f, int w, int p, int s)
{
	int i = BUFF_SIZE - 2;
	int is_neg = 0;
	long int n = va_arg(par, long int);
	unsigned long int num;

	n = convert_number(n, size);

	if (n == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_neg = 1;
	}
	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_numbers(is_neg, i, buff, f, w, p, s));
}

