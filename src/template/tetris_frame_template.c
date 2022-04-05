/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris_frame_template
*/

#include "tetris.h"

const frame_t left_panel_template = {
    .board = NULL,
    .style = 1,
    .size = (dimensions_t) {30, 9},
    .anchor = (pos_t) {-1, 0},
    .offset = (pos_t) {-1, 0},
    .component_nb = 5,
    .components = NULL
};

const frame_component_t high_score_template = {
    .data = 0,
    .display_str = NULL,
    .display_str_color = COLOR_CYAN,
    .name = "High Score :",
    .name_color = COLOR_MAGENTA,
    .pos = (pos_t) {2, 2}
};

const frame_component_t score_template = {
    .data = 0,
    .display_str = NULL,
    .display_str_color = COLOR_CYAN,
    .name = "Score :",
    .name_color = COLOR_MAGENTA,
    .pos = (pos_t) {2, 3}
};

const frame_component_t level_template = {
    .data = 0,
    .display_str = NULL,
    .display_str_color = COLOR_CYAN,
    .name = "Level :",
    .name_color = COLOR_MAGENTA,
    .pos = (pos_t) {2, 5}
};

const frame_component_t lines_template = {
    .data = 0,
    .display_str = NULL,
    .display_str_color = COLOR_CYAN,
    .name = "Lines :",
    .name_color = COLOR_MAGENTA,
    .pos = (pos_t) {2, 6}
};

const frame_component_t timer_template = {
    .data = 0,
    .display_str = NULL,
    .display_str_color = COLOR_CYAN,
    .name = "Timer :",
    .name_color = COLOR_MAGENTA,
    .pos = (pos_t) {2, 8}
};

const frame_t right_panel_template = {
    .board = NULL,
    .style = 2,
    .size = (dimensions_t) {20, 6},
    .anchor = (pos_t) {1, 0},
    .offset = (pos_t) {1, 0},
    .component_nb = 1,
    .components = NULL
};

const frame_component_t next_template = {
    .data = 0,
    .display_str = NULL,
    .display_str_color = COLOR_RED,
    .name = "Next :",
    .name_color = COLOR_RED,
    .pos = (pos_t) {1, 0}
};