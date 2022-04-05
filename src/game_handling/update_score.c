/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** update_score
*/

#include "tetris.h"
#include "tetris_frame_template.h"

void update_score(game_data_t *game_data)
{
    game_data->left_panel.components[SCORE].data += 10;
    update_lambda_comp(game_data->left_panel.components + SCORE);
    if (game_data->left_panel.components[SCORE].data % 100 == 0) {
        game_data->left_panel.components[LEVEL].data += 1;
        update_lambda_comp(game_data->left_panel.components + LEVEL);
    }
}