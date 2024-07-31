#include "main.h"

/**
 * printf_input_str - prints a string
 * @par: input
 * @buff: input
 * @f: flags
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */

int printf_input_str(va_list par, char buff[],
	int f, int w, int p, int s)
{
	int len = 0, i;
	char *str = va_arg(par, char *);

	UNUSED(buff);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);
	if (str == NULL)
	{
		str = "(null)";
		if (p >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (p >= 0 && p < len)
		len = p;

	if (w > len)
	{
		if (f & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = w - len; i > 0; i--)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (i = w - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (w);
		}
	}

	return (write(1, str, len));
}
