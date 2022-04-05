/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** file_extension_determ.c
*/

#include <stdbool.h>
#include "my.h"

bool file_extension_determ(const char file_name[], const char extension[])
{
    const int len_file_name = my_strlen(file_name);
    const int len_extension = my_strlen(extension);

    if (my_strlen(file_name) <= len_extension
        || len_file_name <= len_extension)
        return (false);
    if (my_strcmp(&file_name[len_file_name - len_extension], extension))
        return (false);
    return (true);
}