/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** break_line
*/

#include "my.h"
#include "tetris.h"
#include "tetris_frame_template.h"

static bool is_full_line(cell_t *line, dimensions_t size)
{
    register size_t x = 1;

    while (x < size.width + 1) {
        if (line[x].cell == ' ')
            return (false);
        x += 1;
    }
    return (true);
}

static void break_line(game_data_t *data, dimensions_t size, size_t y)
{
    static const cell_t empty_cell = {.cell = ' ', .color = COLOR_YELLOW};
    register size_t x = 1;
    size_t space = sizeof(cell_t);

    while (y > 0) {
        for (x = 1; x < size.width + 1; x += 1) {
            my_memcpy(data->board[y] + x, data->board[y - 1] + x, space);
        }
        y -= 1;
    }
    for (x = 1; x < size.width + 1; x += 1) {
        my_memcpy(data->board[1] + x, &empty_cell, space);
    }
}

bool should_break_line(game_data_t *game_data, option_t options)
{
    register size_t y = 1;

    while (y < options.map_size.height + 1) {
        if (is_full_line(game_data->board[y], options.map_size)) {
            break_line(game_data, options.map_size, y);
            should_break_line(game_data, options);
            update_score(game_data);
            return (true);
        }
        y += 1;
    }
    return (false);
}