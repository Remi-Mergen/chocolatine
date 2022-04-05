/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** test_my_strdup_lowercase.c
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_strdup_lowercase, basic_conv)
{
    char sentence[] = "I am A FiLFy TesT\n";
    char expected[] = "i am a filfy test\n";
    char *result = NULL;

    result = my_strdup_lowercase(sentence);
    cr_expect_str_eq(result, expected);
    if (result)
        free(result);
}

Test(my_strdup_lowercase, null_sent)
{
    char *sentence = NULL;
    char *expected = NULL;
    char *result = NULL;

    result = my_strdup_lowercase(sentence);
    cr_expect_eq(1, (result) ? 0 : 1);
    if (result)
        free(result);
}

Test(my_strdup_lowercase, nothing_to_change)
{
    char sentence[] = "4323923";
    char expected[] = "4323923";
    char *result = NULL;

    result = my_strdup_lowercase(sentence);
    cr_expect_str_eq(result, expected);
    if (result)
        free(result);
}