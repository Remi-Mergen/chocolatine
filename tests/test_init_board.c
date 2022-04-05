/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_init_board
*/

#include <criterion/criterion.h>
#include "tetris.h"
#include "my.h"

Test(init_board, success_1)
{
    dimensions_t size = {1, 1};

    cr_assert(create_board(size, STYLE_0));
}

Test(init_board, correct_top_left_cell)
{
    dimensions_t size = {1, 1};
    cell_t **board = create_board(size, STYLE_0);

    if (!board)
        cr_assert(1);
    cr_assert(board[0][0].cell == '+' &&
                board[0][0].color == COLOR_YELLOW);
}