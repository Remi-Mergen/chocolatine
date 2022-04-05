/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris_frame_template
*/

#ifndef TETRIS_FRAME_TEMPLATE_H_
#define TETRIS_FRAME_TEMPLATE_H_

#include "tetris.h"

typedef enum left_panel_component_s {
    NEXT_TETRI = 0,
    HIGH_SCORE = 0,
    SCORE = 1,
    LEVEL = 2,
    LINES_DESTROYED = 3,
    TIMER = 4
} left_panel_component_t;

extern const frame_t left_panel_template;
extern const frame_component_t high_score_template;
extern const frame_component_t score_template;
extern const frame_component_t level_template;
extern const frame_component_t lines_template;
extern const frame_component_t timer_template;

extern const frame_t right_panel_template;
extern const frame_component_t next_template;

#endif /* !TETRIS_FRAME_TEMPLATE_H_ */