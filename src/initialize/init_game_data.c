/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** init_game_data
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"
#include "tetris_frame_template.h"

bool init_game_data(game_data_t *game_data, option_t options)
{
    if (!game_data)
        return (false);
    my_memset((char *)game_data, '\0', sizeof(game_data_t));
    game_data->board = create_board(options.map_size, 0);
    if (!(game_data->board))
        return (false);
    if (!init_left_pannel(&(game_data->left_panel), options))
        return (false);
    if (!init_right_pannel(&(game_data->right_panel), options))
        return (false);
    game_data->cursor.x = options.map_size.width / 2;
    game_data->left_panel.components[TIMER].data = clock();
    return (true);
}