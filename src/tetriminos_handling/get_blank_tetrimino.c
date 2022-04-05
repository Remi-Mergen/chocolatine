/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** get_blank_tetrimino
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

char **get_blank_tetrimino(size_t alloc_size)
{
    char **shape = malloc(sizeof(char *) * (alloc_size + 1));
    register size_t index = 0;

    if (!shape)
        return (NULL);
    while (index < alloc_size) {
        shape[index] = malloc(sizeof(char) * (alloc_size + 1));
        if (!(shape[index]))
            return (NULL);
        my_memset(shape[index], ' ', alloc_size);
        shape[index][alloc_size] = '\0';
        index += 1;
    }
    shape[index] = NULL;
    return (shape);
}