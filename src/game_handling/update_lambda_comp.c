/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** update_lambda_comp
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

void update_lambda_comp(frame_component_t *component)
{
    if (!component)
        return ;
    if (component->display_str) {
        free(component->display_str);
        component->display_str = my_int_to_str(component->data);
    }
}