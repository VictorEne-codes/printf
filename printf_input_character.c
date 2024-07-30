#include "main.h"

/**
 * printf_input_character - funcyion to print character to stdout
 * @par: input
 *
 * Return: integer 1 if success
 */

int printf_input_character(va_list par)
{
	char string;

	string = va_arg(par, int);
	_putchar(string);
	return (1);
}
