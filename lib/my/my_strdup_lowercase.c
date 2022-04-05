/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** my_conv_str_lowercase.c
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup_lowercase(const char *template)
{
    register size_t index = 0;
    ssize_t size = my_strlen(template);
    char *dup = NULL;

    if (!template || size <= 0)
        return (NULL);
    dup = malloc(sizeof(char) * (size + 1));
    if (!dup)
        return (NULL);
    while (template[index]) {
        if (my_is_uppercase(template[index]))
            dup[index] = template[index] + 32;
        else
            dup[index] = template[index];
        index += 1;
    }
    dup[size] = '\0';
    return (dup);
}