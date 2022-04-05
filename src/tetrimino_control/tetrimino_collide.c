/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetrimino_collide
*/

#include "tetris.h"

static bool tetrimino_collide_cell(game_data_t *game_data, char **shape,
                                    pos_t pos, pos_t offset)
{
    if (pos.y + offset.y < 0 || pos.x + offset.x < 0)
        return (false);
    if (shape[offset.y][offset.x] == '*' &&
        game_data->board[pos.y + offset.y][pos.x + offset.x].cell == '*')
        return (true);
    return (false);
}

static bool tetrimino_outside_board(option_t options, char **shape,
                                        pos_t pos, pos_t offset)
{
    if (shape[offset.y][offset.x] != '*')
        return (false);
    if (pos.y + offset.y > (ssize_t)options.map_size.height)
        return (true);
    if (pos.x + offset.x < 1)
        return (true);
    if (pos.x + offset.x > (ssize_t)options.map_size.width)
        return (true);
    return (false);
}

bool tetrimino_collide(game_data_t *game_data, option_t options,
                        char **shape, pos_t pos)
{
    register size_t x = 0;
    register size_t y = 0;
    register bool collide = false;

    for (y = 0; shape[y] && !collide; y += 1) {
        for (x = 0; shape[y][x] && !collide; x += 1) {
            collide = tetrimino_outside_board(options, shape, pos, VEC(x, y))
                    ? true :
                    tetrimino_collide_cell(game_data, shape, pos, VEC(x, y));
        }
    }
    return (collide);
}