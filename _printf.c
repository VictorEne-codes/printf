#include "main.h"

/**
 * _printf - function to work just like printf
 * @format: input
 *
 * Return: int
 */

int _printf(const char *format, ...)
{
	format_match m[] = {
		{"%s", printf_input_string}, {"%c", printf_input_character},
		{"%%", printf_input_percentage},
		{"%i", printf_input_int}, {"%d", printf_input_dec},
		{"%r", printf_input_reverse_str}, {"%u", printf_unsigned_int},
		{"%o", printf_unsigned_oct}, {"%x", printf_input_hexa},
		{"%X", printf_input_HEXA},
		{"%S", printf_input_exclusive_string}, {"%p", printf_input_pointer}
	};

	va_list par;
	int i = 0, j, length = 0;
 va_start(par, format);
    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
    {
        return (-1);
    }

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            for (j = 0; (long unsigned int)j < (sizeof(m) / sizeof(m[0])); j++)
            {
                if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
                {
                    length += m[j].f(par);
                    i++;
                    break;
                }
            }
            if (j == (sizeof(m) / sizeof(m[0])))
            {
                _putchar('%');
                _putchar(format[i]);
                length += 2;
            }
        }
        else
        {
            _putchar(format[i]);
            length++;
        }
    }

    va_end(par);
    return (length);
}
