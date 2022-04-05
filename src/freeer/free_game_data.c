/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** free_game_data
*/

#include "my.h"
#include "tetris.h"

bool free_game_data(game_data_t game_data)
{
    if (game_data.board)
        my_free_arr((void **)game_data.board);
    free_frame(game_data.left_panel);
    free_frame(game_data.right_panel);
    return (true);
}