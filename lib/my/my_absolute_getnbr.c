/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** my_absolute_getnbr.c
*/

#include "my.h"

int my_absolute_getnbr(const char *str)
{
    register size_t index = 0;
    int nb = 0;

    if (!my_str_is_num(str))
        return (-1);
    while (str[index]) {
        if (index > 0)
            nb *= 10;
        nb += str[index] - 48;
        index += 1;
    }
    return (nb);
}