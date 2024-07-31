#include "main.h"

/**
 * printf_input_per - prints a percentage
 * @par: input
 * @buff: input
 * @f: flags
 * @w: width
 * @p: precision
 * @s: size
 *
 * Return: int
 */

int printf_input_perc(va_list par, char buff[],
		int f, int w, int p, int s)
{
	UNUSED(par);
	UNUSED(buff);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);
	return (write(1, "%%", 1));
}
