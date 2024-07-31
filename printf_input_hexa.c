#include "main.h"
 
/**
* printf_input_hexa - prints hexadecimal of integer
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
