/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** init_left_panel
*/

#include <stdlib.h>
#include "my.h"
#include "tetris_frame_template.h"

bool init_right_pannel(frame_t *frame,
                        __attribute__((unused))option_t options)
{
    if (!frame)
        return (false);
    my_memcpy(frame, &right_panel_template, sizeof(frame_t));
    frame->board = create_board(frame->size, frame->style);
    frame->components = malloc(sizeof(frame_component_t) *
                                        (frame->component_nb));
    if (!(frame->board) || !(frame->components))
        return (false);
    if (!init_frame_component(&(frame->components[NEXT_TETRI]),
                                            next_template, 0))
        return (false);
    if (frame->components[NEXT_TETRI].display_str) {
        free(frame->components[NEXT_TETRI].display_str);
        frame->components[NEXT_TETRI].display_str = NULL;
    }
    return (true);
}