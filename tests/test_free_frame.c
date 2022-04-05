/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_free_frame
*/

#include <criterion/criterion.h>
#include "tetris_frame_template.h"
#include "tetris.h"
#include "my.h"

Test(free_frame_test, free_special_frame_1_success)
{
    frame_t frame;
    option_t options;

    my_memset((char *)&options, 0, sizeof(option_t));
    my_memset((char *)&frame, 0, sizeof(frame_t));
    if (init_left_pannel(&frame, options))
        cr_assert(1);
    cr_assert(free_frame(frame));
}

Test(free_frame_test, free_special_frame_2_success)
{
    frame_t frame;
    option_t options;

    my_memset((char *)&options, 0, sizeof(option_t));
    my_memset((char *)&frame, 0, sizeof(frame_t));
    if (init_right_pannel(&frame, options))
        cr_assert(1);
    cr_assert(free_frame(frame));
}