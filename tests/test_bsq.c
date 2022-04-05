/*
** EPITECH PROJECT, 2019
** test_init_op
** File description:
** infinadd criterion test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bsqh.h"

Test(bsq, incorrect_file)
{
    cr_assert_eq(bsq("azertyuiop"), 84);
}

Test(bsq, too_long_line)
{
    cr_assert_eq(bsq("map1"), 84);
}

Test(bsq, too_short_line)
{
    cr_assert_eq(bsq("map11"), 84);
}

Test(bsq, too_much_lines)
{
    cr_assert_eq(bsq("map2"), 84);
}

Test(bsq, too_few_lines)
{
    cr_assert_eq(bsq("map21"), 84);
}

Test(bsq, invalid_chars)
{
    cr_assert_eq(bsq("map3"), 84);
}

Test(bsq, correct_map)
{
    cr_redirect_stdout();
    bsq("map");
    cr_assert_stdout_eq_str(".oxx.\no.xxo\n.....\n.oo.o\n..o.o\n");
}

Test(bsq, correct_empty_map)
{
    cr_redirect_stdout();
    bsq("map_empty");
    cr_assert_stdout_eq_str("xxxxx\nxxxxx\nxxxxx\nxxxxx\nxxxxx\n");
}

Test(bsq, correct_empty_column_map)
{
    cr_redirect_stdout();
    bsq("map_empty_column");
    cr_assert_stdout_eq_str("x....\n");
}

Test(bsq, correct_empty_column_line)
{
    cr_redirect_stdout();
    bsq("map_empty_line");
    cr_assert_stdout_eq_str("x\n.\n.\n.\n.\n");
}

Test(bsq, correct_filled_map)
{
    cr_redirect_stdout();
    bsq("map_filled");
    cr_assert_stdout_eq_str("ooooo\nooooo\nooooo\nooooo\nooooo\n");
}
