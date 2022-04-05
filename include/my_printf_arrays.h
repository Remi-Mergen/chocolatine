/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf flags and function pointers.
*/

#ifndef MY_PRINTF_ARRAYS_H_

#define MY_PRINTF_ARRAYS_H_

#include <stdarg.h>

void flag_c(va_list ap);
void flag_d(va_list ap);
void flag_i(va_list ap);
void flag_u(va_list ap);
void flag_b(va_list ap);
void flag_o(va_list ap);
void flag_lower_x(va_list ap);
void flag_upper_x(va_list ap);
void flag_lower_s(va_list ap);
void flag_upper_s(va_list ap);
void flag_p(va_list ap);

void mod_hashtag(va_list ap, const char *shifted_input, int *idx);
void mod_short(va_list ap, const char *shifted_input, int *idx);
void mod_long(va_list ap, const char *shifted_input, int *idx);

void (*list_flags[])(va_list ap) = {
    flag_c,
    flag_d,
    flag_i,
    flag_u,
    flag_b,
    flag_o,
    flag_lower_x,
    flag_upper_x,
    flag_lower_s,
    flag_upper_s,
    flag_p
};

void (*list_mods[])(va_list ap, const char *shifted_input, int *idx) = {
    mod_hashtag,
    mod_short,
    mod_long,
    mod_long
};

#endif /* MY_PRINTF_ARRAYS_H_ */