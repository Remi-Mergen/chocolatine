/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** test_file_extension_determ.c
*/

#include <criterion/criterion.h>
#include "tetris.h"

Test(file_extension_determ, basic_valid_test)
{
    cr_assert_eq(file_extension_determ("rectangle.tetrimino",
                                        ".tetrimino"), true);
}

Test(file_extension_determ, basic_invalid_test)
{
    cr_assert_eq(file_extension_determ("rectangle.txt",
                                        ".tetrimino"), false);
}

Test(file_extension_determ, null_file_name)
{
    cr_assert_eq(file_extension_determ(NULL, ".tetrimino"), false);
}

Test(file_extension_determ, null_extension)
{
    cr_assert_eq(file_extension_determ("test.txt", NULL), false);
}