/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** init_left_panel
*/

#include <stdlib.h>
#include "my.h"
#include "tetris_frame_template.h"

bool init_left_pannel(frame_t *frame, option_t options)
{
    if (!frame)
        return (false);
    my_memcpy(frame, &left_panel_template, sizeof(frame_t));
    frame->board = create_board(frame->size, frame->style);
    frame->components = malloc(sizeof(frame_component_t) *
                                        (frame->component_nb));
    if (!(frame->board) || !(frame->components))
        return (false);
    if (!init_frame_component(&(frame->components[HIGH_SCORE]),
                                high_score_template, get_score())
        || !init_frame_component(&(frame->components[SCORE]),
                                score_template, 0)
        || !init_frame_component(&(frame->components[LEVEL]),
                                level_template, options.level)
        || !init_frame_component(&(frame->components[LINES_DESTROYED]),
                                lines_template, 0)
        || !init_frame_component(&(frame->components[TIMER]),
                                timer_template, 0))
        return (false);
    return (true);
}