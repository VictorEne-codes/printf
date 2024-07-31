#ifndef MAIN_H
#define MAIN_H

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

#define MINUS_FLG 1
#define PLUS_FLG 2
#define ZERO_FLG 4
#define HASH_FLG 8
#define SPACE_FLG 16

int printf_input_char(va_list par, char buff[],
        int f, int w, int p, int s);
int printf_input_int(va_list par, char buff[],
        int f, int w, int p, int s);
int printf_input_perc(va_list par, char buff[],
        int f, int w, int p, int s);
int printf_input_bin(va_list par, char buff[],
        int f, int w, int p, int s);
int printf_input_oct(va_list par, char buff[],
        int f, int w, int p, int s);
int printf_input_hexa(va_list par, char buff[],
        int f, int w, int p, int s);
int printf_input_hexa(va_list par, char buff[],
        int f, int w, int p, int s);



#endif
