/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_init_game_data
*/

#include <criterion/criterion.h>
#include "tetris.h"
#include "my.h"

Test(game_data_init, wrong_address_1)
{
    option_t options;

    my_memset((char *)&options, 0, sizeof(option_t));
    cr_assert(!init_game_data(NULL, options));
}

Test(game_data_init, success_1)
{
    game_data_t game_data;
    option_t options;

    my_memset((char *)&options, 0, sizeof(option_t));
    cr_assert(init_game_data(&game_data, options));
}

Test(game_data_init, success_2)
{
    game_data_t game_data;
    option_t options;

    my_memset((char *)&options, 0, sizeof(option_t));
    if (!init_game_data(&game_data, options))
        cr_assert(1);
    cr_assert(game_data.board);
}

Test(game_data_init, success_3)
{
    game_data_t game_data;
    option_t options;

    my_memset((char *)&options, 0, sizeof(option_t));
    if (!init_game_data(&game_data, options))
        cr_assert(1);
    cr_assert(game_data.left_panel.board);
}

Test(game_data_init, success_4)
{
    game_data_t game_data;
    option_t options;

    my_memset((char *)&options, 0, sizeof(option_t));
    if (!init_game_data(&game_data, options))
        cr_assert(1);
    cr_assert(game_data.right_panel.board);
}