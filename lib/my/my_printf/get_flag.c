/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** gets the called flag and redirects towards the matching function
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"
#include "my_printf_arrays.h"

static int check_behind(va_list ap, const char *shifted_input, int *idx)
{
    int call_redir = 0;

    call_redir = check_for_flag(shifted_input[1]);
    if (call_redir > -1) {
        list_flags[call_redir](ap);
        return (0);
    }
    call_redir = check_for_mod(shifted_input[1]);
    if (call_redir > -1) {
        list_mods[call_redir](ap, shifted_input, idx);
        return (0);
    }
    return (1);
}

static int few_cases(const char *shifted_input, int *idx,
                    const int call_redir)
{
    if (shifted_input[1] && call_redir == 1) {
        my_putchar('%');
        my_putchar(shifted_input[1]);
        return (0);
    }
    if (shifted_input[1]) {
        (*idx) -= 1;
        return (0);
    }
    return (1);
}

int get_flag(va_list ap, const char *shifted_input, int *idx)
{
    int call_redir = 0;

    call_redir = check_behind(ap, shifted_input, idx);
    if (shifted_input[1] == '%') {
        flag_percent(shifted_input, idx);
        (*idx) += 1;
        return (0);
    }
    if (!(few_cases(shifted_input, idx, call_redir)))
        return (0);
    return (-1);
}