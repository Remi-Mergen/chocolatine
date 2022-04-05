/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display_all
*/

#include "tetris.h"

void display_all(game_data_t *game_data, tetrimino_t *queue,
                option_t options, pos_t board_pos)
{
    display_board(game_data->board, options.map_size, board_pos);
    display_frame(game_data->left_panel, board_pos, options.map_size);
    display_shadow(game_data, queue, options, board_pos);
    display_tetrimino(queue, board_pos, game_data->cursor);
    if (!(options.game_option & NO_NEXT)) {
        display_frame(game_data->right_panel, board_pos, options.map_size);
        display_next_tetrimino(queue, game_data->right_panel,
                                board_pos, options.map_size);
    }
}