/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** free_frame
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

static bool free_frame_component(frame_component_t component)
{
    if (component.display_str)
        free(component.display_str);
    if (component.name)
        free(component.name);
    return (true);
}

bool free_frame(frame_t frame)
{
    register size_t index = 0;

    if (frame.board)
        my_free_arr((void **)frame.board);
    if (frame.components) {
        for (index = 0; index < frame.component_nb; index += 1)
            free_frame_component(frame.components[index]);
        free(frame.components);
    }
    return (true);
}