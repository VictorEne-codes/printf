#include "main.h"

/**
 * printf_character - funcyion to print character to stdout
 * @val: input
 *
 * Return: integer 1 if success
 */

int printf_input_character(va_list val)
{
	char string;

	string = va_arg(val, int);
	_putchar(string);
	return (1);
}
