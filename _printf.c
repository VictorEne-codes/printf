#include "main.h"

/**
 * printf_helper - helps printf
 * @ind: input
 * @fmt: input
 * @par: input
 * @buff: input
 * @f: flags
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */

int printf_helper(const char *fmt, int *ind, va_list par, char buff[],
	int f, int w, int p, int s)
{
	int i, u_len = 0, printed_ch = -1;
	fmt_t fmt_types[] = {
		{'c', printf_input_char}, {'s', printf_input_str},
		{'%', printf_input_perc}, {'i', printf_input_int},
		{'d', printf_input_int}, {'b', printf_input_bin},
		{'u', printf_input_unsigned}, {'o', printf_input_oct},
		{'x', printf_input_hexa}, {'X', printf_input_HEXA},
		{'p', printf_input_pointer}, {'S', printf_non_printable},
		{'r', printf_rev_str}, {'R', printf_rot13}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(par, buff, f, w, p, s));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		u_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			u_len += write(1, " ", 1);
		else if (w)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		u_len += write(1, &fmt[*ind], 1);
		return (u_len);
	}
	return (printed_ch);
}

/**
 * printf_buffer - prints a buffer
 * @buff: input
 * @buff_ind: input
 *
 * Return: void
 */

void printf_buffer(char buff[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buff[0], *buff_ind);

	*buff_ind = 0;
}

/**
 * _printf - prints to stdout
 * @format: input
 *
 * Return: int
 */

int _printf(const char *format, ...)
{
	int i, printed = 0, printed_ch = 0;
	int f, w, p, s, buff_ind = 0;
	va_list par;
	char buff[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(par, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buff[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				printf_buffer(buff, &buff_ind);
			printed_ch++;
		}
		else
		{
			printf_buffer(buff, &buff_ind);
			f = flg(format, &i);
			w = calc_width(format, &i, par);
			p = precise_print(format, &i, par);
			s = size_cast(format, &i);
			++i;
			printed = printf_helper(format, &i, par, buff,
				f, w, p, s);
			if (printed == -1)
				return (-1);
			printed_ch += printed;
		}
	}

	printf_buffer(buff, &buff_ind);

	va_end(par);

	return (printed_ch);
}
