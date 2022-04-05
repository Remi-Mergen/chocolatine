/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_init_frame
*/

#include <criterion/criterion.h>
#include "tetris_frame_template.h"
#include "tetris.h"
#include "my.h"

Test(init_frame, wrong_address_1)
{
    cr_assert(!init_frame_component(NULL, level_template, 0));
}

Test(init_frame, success_1)
{
    frame_component_t frame;

    if (!init_frame_component(&frame, level_template, 0))
        cr_assert(1);
    cr_assert(!frame.data && !my_strcmp(frame.name, level_template.name) &&
                frame.display_str_color == level_template.display_str_color &&
                frame.pos.x == level_template.pos.x &&
                frame.pos.y == level_template.pos.y);
}

Test(init_frame, special_frame_1_fail)
{
    option_t options;

    my_memset((char *)&options, 0, sizeof(option_t));
    cr_assert(!init_left_pannel(NULL, options));
}

Test(init_frame, special_frame_1_success)
{
    frame_t frame;
    option_t options;

    my_memset((char *)&options, 0, sizeof(option_t));
    my_memset((char *)&frame, 0, sizeof(frame_t));
    cr_assert(init_left_pannel(&frame, options));
}

Test(init_frame, special_frame_2_fail)
{
    option_t options;

    my_memset((char *)&options, 0, sizeof(option_t));
    cr_assert(!init_right_pannel(NULL, options));
}

Test(init_frame, special_frame_2_success)
{
    frame_t frame;
    option_t options;

    my_memset((char *)&options, 0, sizeof(option_t));
    my_memset((char *)&frame, 0, sizeof(frame_t));
    cr_assert(init_right_pannel(&frame, options));
}