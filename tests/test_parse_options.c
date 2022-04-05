/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_parse_options
*/

#include <criterion/criterion.h>
#include "tetris_options.h"
#include "tetris.h"
#include "my.h"

Test(parse_option, wrong_address_1)
{
    char *av = "a";

    cr_assert(!parse_option(1, &av, NULL));
}

Test(parse_option, wrong_address_2)
{
    option_t options;

    cr_assert(!parse_option(1, NULL, &options));
}

Test(parse_option, bad_argument)
{
    option_t options;
    char *av[] = {"./a", "-s", "a,a"};

    cr_assert(!parse_option(3, av, &options));
}

Test(parse_option, good_argument)
{
    option_t options;
    char *av[] = {"./a", "-D"};

    cr_assert(parse_option(2, av, &options));
}