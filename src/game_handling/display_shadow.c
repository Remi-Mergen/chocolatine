/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display_shadow
*/

#include "tetris.h"

void display_shadow(game_data_t *game_data, tetrimino_t *queue,
                    option_t options, pos_t board_pos)
{
    pos_t pos = game_data->cursor;
    size_t save_color = 0;

    if (!queue)
        return;
    save_color = queue->color;
    queue->color = COLOR_WHITE;
    while (!tetrimino_collide(game_data, options,
                            queue->shapes[queue->rotation],
                            VEC(pos.x, pos.y + 1))) {
        pos.y += 1;
    }
    display_tetrimino(queue, board_pos, pos);
    queue->color = save_color;
}