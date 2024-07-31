#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

int _printf(const char *format, ...);
int printf_input_char(va_list par, char buff[],
        int f, int w, int p, int s);
int printf_input_str(va_list par, char buff[],
	int f, int w, int p, int s);
int printf_input_int(va_list par, char buff[],
        int f, int w, int p, int s);
int printf_input_perc(va_list par, char buff[],
        int f, int w, int p, int s);
int printf_input_bin(va_list par, char buff[],
        int f, int w, int p, int s);
int printf_input_oct(va_list par, char buff[],
        int f, int w, int p, int s);
int printf_input_unsigned(va_list par, char buff[],
		int f, int w, int p, int s);
int printf_input_hexa(va_list par, char buff[],
        int f, int w, int p, int s);
int printf_input_HEXA(va_list par, char buff[],
        int f, int w, int p, int s);
int printf_non_printable(va_list par, char buff[],
	int f, int w, int p, int s);
int printf_input_pointer(va_list par, char buff[],
	int f, int w, int p, int s);
int print_hexa(va_list par, char map[], char buff[],
        int f, char flag_ch, int w, int p, int s);
int printf_input_rot13(va_list par, char buff[],
	int f, int w, int p, int s);
int printf_input_rev_str(va_list par, char buff[],
	int f, int w, int p, int s);
int is_digit(char c);
int flg(const char *format, int *i);
int precise_print(const char *format, int *i, va_list par);
int size_cast(const char *format, int *i);
int calc_width(const char *format, int *i, va_list par);
int write_unsgn(int is_neg, int ind,
	char buff[],
	int f, int w, int p, int s);
long int convert_unsgn(unsigned long int n, int size);


/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;



#endif
