/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetrimino_interact
*/

#include "tetris.h"

void drop_tetrimino(game_data_t *game_data, tetrimino_t **queue,
                                                option_t options)
{
    while (land_tetrimino(game_data, queue, options));
}

void rotate_tetrimino(game_data_t *game_data, option_t options,
                                                tetrimino_t *tetrimino)
{
    pos_t pos = game_data->cursor;
    int rotation = 0;

    if (!tetrimino)
        return ;
    rotation = tetrimino->rotation;
    if (!tetrimino_collide(game_data, options,
                            tetrimino->shapes[(rotation + 1) % 4],
                            pos)) {
        tetrimino->rotation += 1;
    }
}

void move_tetrimino(game_data_t *game_data, option_t options,
                                            tetrimino_t *tetrimino,
                                            int key_code)
{
    pos_t pos = game_data->cursor;

    if (!tetrimino)
        return;
    if (key_code == KEY_CODE_LEFT &&
        !tetrimino_collide(game_data, options,
                            tetrimino->shapes[tetrimino->rotation],
                            (pos_t){pos.x - 1, pos.y}))
        game_data->cursor.x -= 1;
    if (key_code == KEY_CODE_RIGHT &&
        !tetrimino_collide(game_data, options,
                            tetrimino->shapes[tetrimino->rotation],
                            (pos_t){pos.x + 1, pos.y}))
        game_data->cursor.x += 1;
}