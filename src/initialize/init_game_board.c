/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** init_game_board
*/

#include "stdlib.h"
#include "my.h"
#include "tetris.h"
#include "tetris_cell_template.h"

static void fill_board_line(cell_t **board, size_t index,
                                dimensions_t size, cell_style_t style)
{
    register unsigned int tmp_i = 0;

    if (!board || !(board[index]))
        return ;
    for (tmp_i = 0; tmp_i < size.width + 1; tmp_i += 1)
        my_memcpy(board[index] + tmp_i, empty_cell + style, sizeof(cell_t));
    if (index == 0) {
        for (tmp_i = 0; tmp_i < size.width + 1; tmp_i += 1)
            my_memcpy(board[index] + tmp_i, n_cell + style, sizeof(cell_t));
    }
    if (index == size.height + 1) {
        for (tmp_i = 0; tmp_i < size.width + 1; tmp_i += 1)
            my_memcpy(board[index] + tmp_i, s_cell + style, sizeof(cell_t));
    }
    my_memcpy(board[index], &(w_cell[style]), sizeof(cell_t));
    my_memcpy(board[index] + size.width + 1, e_cell + style, sizeof(cell_t));
    my_memcpy(board[index] + size.width + 2, &null_cell, sizeof(cell_t));
}

static void fill_board_edge(cell_t **board, dimensions_t map_size,
                                                cell_style_t style)
{
    my_memcpy(board[0], nw_cell + style, sizeof(cell_t));
    my_memcpy(board[map_size.height + 1] + map_size.width + 1,
                se_cell + style, sizeof(cell_t));
    my_memcpy(board[map_size.height + 1], sw_cell + style, sizeof(cell_t));
    my_memcpy(board[0] + map_size.width + 1, ne_cell + style, sizeof(cell_t));
}

cell_t **create_board(dimensions_t size, cell_style_t style)
{
    register size_t index = 0;
    cell_t **board = NULL;

    board = malloc(sizeof(cell_t *) * (size.height + 3));
    if (!board)
        return (NULL);
    while (index < size.height + 2) {
        board[index] = malloc(sizeof(cell_t) * (size.width + 3));
        if (!(board[index]))
            return (NULL);
        fill_board_line(board, index, size, style);
        index += 1;
    }
    fill_board_edge(board, size, style);
    board[size.height + 2] = NULL;
    return (board);
}