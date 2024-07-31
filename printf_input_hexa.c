#include "main.h"

/**
 * printf_input_oct - prints an octal of integer
 * @map: input
 * @flag_ch: input
 * @par: input
 * @buff: input
 * @f: flags
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */

int print_hexa(va_list par, char map[], char buff[],
	int f, char flag_ch, int w, int p, int s)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(par, unsigned long int);
	unsigned long int init_n = num;

	UNUSED(w);

	num = convert_unsgnd(num, size);

	if (num == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = map[num % 16];
		num /= 16;
	}

	if (f & F_HASH && init_n != 0)
	{
		buff[i--] = flag_ch;
		buff[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buff, f, w, p, s));
}

/**
 * printf_input_oct - prints an octal of integer
 * @par: input
 * @buff: input
 * @f: flags
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */

int printf_input_hexa(va_list par, char buff[],
	int f, int w, int p, int s)
{
	return (print_hexa(par, "0123456789abcdef", buff,
		f, 'x', w, p, s));
}
