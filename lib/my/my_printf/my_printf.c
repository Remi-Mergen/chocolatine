/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** similar to the stdio function
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

static void browse_through_input(const char *input, va_list ap)
{
    int idx = 0;

    while (input[idx]) {
        if (input[idx] == '%') {
            get_flag(ap, &input[idx], &idx);
            idx += 2;
        } else
            my_putchar(input[idx]);
        idx += 1;
    }
}

int my_printf(const char *input, ...)
{
    va_list ap;

    va_start(ap, input);
    browse_through_input(input, ap);
    va_end(ap);
    return (0);
}