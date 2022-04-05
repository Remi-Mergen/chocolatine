/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** init_frame
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

bool init_frame_component(frame_component_t *component,
                            frame_component_t template, int data)
{
    if (!(component))
        return (false);
    my_memset((char *)component, '\0', sizeof(sizeof(frame_component_t)));
    component->data = data;
    component->pos = template.pos;
    component->name = my_strdup(template.name);
    component->display_str = my_int_to_str(data);
    component->display_str_color = template.display_str_color;
    component->name_color = template.name_color;
    if (!(component->name) || !(component->display_str))
        return (false);
    return (true);
}