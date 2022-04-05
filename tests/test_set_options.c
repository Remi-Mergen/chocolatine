/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_set_options
*/

#include <criterion/criterion.h>
#include "tetris_options.h"
#include "tetris.h"
#include "my.h"

Test(set_options, control_key_fail_1)
{
    option_t option;

    cr_assert(!set_control_key(NULL, 'a', NULL));
}

Test(set_options, control_key_fail_2)
{
    option_t option;

    cr_assert(!set_control_key(&option, 'a', NULL));
}

Test(set_options, control_key_wrong_option)
{
    option_t option;

    cr_assert(!set_control_key(&option, 'a', "))"));
}

Test(set_options, control_key_success)
{
    option_t option;

    cr_assert(set_control_key(&option, 'l', "a"));
}

Test(set_options, option_key_fail_1)
{
    cr_assert(!set_option_key(NULL, 'l', "a"));
}

Test(set_options, option_key_fail_2)
{
    option_t option;

    cr_assert(!set_option_key(&option, 'l', NULL));
}

Test(set_options, option_key_wrong_option)
{
    option_t option;

    cr_assert(!set_option_key(&option, 'l', "))"));
}

Test(set_options, option_key_success)
{
    option_t option;

    cr_assert(set_option_key(&option, 'q', "))"));
}

Test(set_options, level_option_fail_1)
{
    cr_assert(!set_level(NULL, 'q', "))"));
}

Test(set_options, level_option_fail_2)
{
    option_t option;

    cr_assert(!set_level(&option, 'q', NULL));
}

Test(set_options, level_option_wrong_arg)
{
    option_t option;

    cr_assert(!set_level(&option, 'q', "0"));
}

Test(set_options, level_option_wrong_arg_2)
{
    option_t option;

    cr_assert(!set_level(&option, 'q', "PATATE_IS_NO_NUMBER"));
}

Test(set_options, level_option_success)
{
    option_t option;

    cr_assert(set_level(&option, 'q', "5"));
}

Test(set_options, map_size_option_fail_1)
{
    cr_assert(!set_map_size(NULL, 'a', NULL));
}

Test(set_options, map_size_option_fail_2)
{
    option_t option;

    cr_assert(!set_map_size(&option, 0, "aa"));
}

Test(set_options, map_size_option_fail_3)
{
    option_t option;

    cr_assert(!set_map_size(&option, 'a', "1"));
}

Test(set_options, map_size_option_fail_4)
{
    option_t option;

    cr_assert(!set_map_size(&option, 'a', "1,a"));
}

Test(set_options, map_size_option_fail_5)
{
    option_t option;

    cr_assert(!set_map_size(&option, 'a', "1,1,1"));
}

Test(set_options, map_size_option_success)
{
    option_t option;

    cr_assert(set_map_size(&option, 'a', "2,2"));
}

Test(set_options, game_option_fail_1)
{
    cr_assert(!set_game_option(NULL, 'a', NULL));
}

Test(set_options, game_option_fail_2)
{
    option_t option;

    cr_assert(!set_game_option(&option, 'a', NULL));
}

Test(set_options, game_option_success)
{
    option_t option;

    cr_assert(set_game_option(&option, 'w', NULL));
}