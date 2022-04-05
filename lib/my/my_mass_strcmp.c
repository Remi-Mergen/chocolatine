/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** my_mass_strcmp.c
*/

#include <stdbool.h>
#include <stdarg.h>
#include "my.h"

bool my_mass_strcmp(const char *template, ...)
{
    char *argument = NULL;
    bool found_match = false;
    va_list ap;

    va_start(ap, template);
    argument = va_arg(ap, char *);
    while (argument) {
        if (!my_strcmp(template, argument)) {
            found_match = true;
            break;
        }
        argument = va_arg(ap, char *);
    }
    va_end(ap);
    return (found_match);
}