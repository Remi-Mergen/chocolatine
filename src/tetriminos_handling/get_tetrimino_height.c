/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** get_tetrimino_height
*/

#include "my.h"
#include "tetris.h"

size_t get_tetriminos_height(tetrimino_t *tetrimino)
{
    register ssize_t index = 0;
    size_t line_nb = 0;

    if (!tetrimino)
        return (0);
    for (index = 0; index < tetrimino->alloc_size; index += 1) {
        if (find_char(tetrimino->shapes[0][index], '*') != -1)
            line_nb += 1;
    }
    return (line_nb);
}