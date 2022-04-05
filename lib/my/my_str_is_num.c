/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** checks if a string only contains alphanumerical characters
*/

#include "my.h"

int my_str_is_num(const char *str)
{
    int index = 0;

    if (!str || !str[0])
        return (0);
    while (str[index]) {
        if (!my_isnum(str[index]))
            return (0);
        index += 1;
    }
    return (1);
}