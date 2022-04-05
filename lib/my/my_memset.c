/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** my_memset.c
*/

#include <unistd.h>

void my_memset(char *to_write_on,
                const char to_fill_with,
                const size_t nb_bytes)
{
    size_t index = 0;

    if (!to_write_on)
        return;
    while (index < nb_bytes) {
        to_write_on[index] = to_fill_with;
        index += 1;
    }
}