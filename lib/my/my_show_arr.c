/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_show_arr.c
*/

#include "my.h"

void my_show_arr(char **array)
{
    int index = 0;

    if (!array)
        return;
    while (array[index]) {
        my_putstr(array[index]);
        my_putchar('\n');
        index += 1;
    }
}