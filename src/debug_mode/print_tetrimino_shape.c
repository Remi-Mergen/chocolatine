/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_tetrimino_shape.c
*/

#include "my.h"

static void print_shape_char(const char *shape_line, size_t *x)
{
    size_t star_finder = *x;

    if (shape_line[(*x)] == ' ') {
        while (shape_line[star_finder] == ' ')
            star_finder += 1;
        if (!shape_line[star_finder])
            return;
    }
    my_putchar(shape_line[(*x)]);
}

void print_tetrimino_shape(char **shape)
{
    register size_t y = 0;
    size_t x = 0;

    if (!shape)
        return;
    for (; shape[y]; y += 1) {
        if (!find_char_in_str(shape[y], '*'))
            continue;
        for (x = 0; shape[y][x]; x += 1)
            print_shape_char(shape[y], &x);
        my_putchar('\n');
    }
}