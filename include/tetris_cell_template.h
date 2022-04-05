/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris_cell_template
*/

#ifndef TETRIS_CELL_TEMPLATE_H_
#define TETRIS_CELL_TEMPLATE_H_

#include "tetris.h"

const cell_t empty_cell[] = {
    {.cell = ' ', .color = COLOR_YELLOW},
    {.cell = ' ', .color = COLOR_MAGENTA},
    {.cell = ' ', .color = COLOR_MAGENTA}
};

const cell_t w_cell[] = {
    {.cell = '|', .color = COLOR_YELLOW},
    {.cell = 'M', .color = COLOR_MAGENTA},
    {.cell = '|', .color = COLOR_GREEN}
};

const cell_t e_cell[] = {
    {.cell = '|', .color = COLOR_YELLOW},
    {.cell = 'W', .color = COLOR_MAGENTA},
    {.cell = '|', .color = COLOR_GREEN}
};

const cell_t n_cell[] = {
    {.cell = '-', .color = COLOR_YELLOW},
    {.cell = '=', .color = COLOR_MAGENTA},
    {.cell = '~', .color = COLOR_GREEN}
};

const cell_t s_cell[] = {
    {.cell = '-', .color = COLOR_YELLOW},
    {.cell = '=', .color = COLOR_MAGENTA},
    {.cell = '~', .color = COLOR_GREEN}
};

const cell_t nw_cell[] = {
    {.cell = '+', .color = COLOR_YELLOW},
    {.cell = '^', .color = COLOR_MAGENTA},
    {.cell = '/', .color = COLOR_GREEN}
};

const cell_t ne_cell[] = {
    {.cell = '+', .color = COLOR_YELLOW},
    {.cell = '>', .color = COLOR_MAGENTA},
    {.cell = '\\', .color = COLOR_GREEN}
};

const cell_t sw_cell[] = {
    {.cell = '+', .color = COLOR_YELLOW},
    {.cell = '<', .color = COLOR_MAGENTA},
    {.cell = '\\', .color = COLOR_GREEN}
};

const cell_t se_cell[] = {
    {.cell = '+', .color = COLOR_YELLOW},
    {.cell = 'v', .color = COLOR_MAGENTA},
    {.cell = '/', .color = COLOR_GREEN}
};

const cell_t null_cell = {.cell = '\0', .color = COLOR_BLACK};

#endif /* !TETRIS_CELL_TEMPLATE_H_ */
