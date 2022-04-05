/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** init_tetriminos
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

static bool init_oriented_shape(tetrimino_t *tetrimino,
                                unsigned short orientation)
{
    char **new_shape = NULL;
    register size_t alloc_size = 0;
    register size_t x = 0;
    register size_t y = 0;

    if (!tetrimino || tetrimino->alloc_size < 1
        || !(tetrimino->shapes[orientation - 1]))
        return (false);
    alloc_size = tetrimino->alloc_size;
    new_shape = get_blank_tetrimino(alloc_size);
    if (!new_shape)
        return (false);
    for (y = 0; y < alloc_size; y += 1) {
        for (x = 0; x < alloc_size; x += 1) {
            new_shape[y][x] =
                tetrimino->shapes[orientation - 1][alloc_size - 1 - x][y];
        }
    }
    tetrimino->shapes[orientation] = new_shape;
    return (true);
}

bool init_all_oriented_shapes(tetrimino_t *tetrimino)
{
    register unsigned short orientation = 1;

    if (!tetrimino)
        return (false);
    for (orientation = 1; orientation < 4; orientation += 1) {
        if (!init_oriented_shape(tetrimino, orientation))
            return (false);
    }
    return (true);
}