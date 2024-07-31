#ifndef MAIN_H
#define MAIN_H

int printf_input_char(va_list par, char buff[],
        int f, int w, int p, int s);
int printf_input_int(va_list par, char buff[],
        int f, int w, int p, int s);
int printf_input_perc(va_list par, char buff[],
        int f, int w, int p, int s);
int printf_input_bin(va_list par, char buff[],
        int f, int w, int p, int s);

#endif
