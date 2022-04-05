/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display_tetrimino
*/

#include "tetris.h"

static void display_tetriminos_cell(tetrimino_t *tetrimino, pos_t pos,
                                    pos_t board_pos, pos_t index)
{
    if (tetrimino->shapes[tetrimino->rotation][index.y]
        && tetrimino->shapes[tetrimino->rotation][index.y][index.x] == '*'
        && pos.y + index.y > 0)
        mvaddch(board_pos.y + pos.y + index.y,
                board_pos.x + pos.x + index.x,
                '*');
}

void display_tetrimino(tetrimino_t *tetrimino, pos_t board_pos, pos_t pos)
{
    register size_t x = 0;
    register size_t y = 0;

    if (!tetrimino || !(tetrimino->shapes)
        || !(tetrimino->shapes[tetrimino->rotation]))
        return ;
    init_pair(tetrimino->color, tetrimino->color, COLOR_BLACK);
    attron(COLOR_PAIR(tetrimino->color));
    while (y < (size_t)tetrimino->alloc_size) {
        for (x = 0; x < (size_t)tetrimino->alloc_size; x += 1)
            display_tetriminos_cell(tetrimino, pos, board_pos, (pos_t){x, y});
        y += 1;
    }
    attroff(COLOR_PAIR(tetrimino->color));
}