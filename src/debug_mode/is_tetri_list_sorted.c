/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** is_tetri_list_sorted.c
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

static bool free_check_list_resources(char *tmp_first, char *tmp_second,
                                        const bool return_val)
{
    if (tmp_first)
        free(tmp_first);
    if (tmp_second)
        free(tmp_second);
    return (return_val);
}

static void reset_pointers_values(tetrimino_t *tmp, char **tmp_first,
                                char **tmp_second, int *cmp_reason)
{
    *tmp_first = my_strdup_lowercase(tmp->prev->name);
    *tmp_second = my_strdup_lowercase(tmp->name);
    *cmp_reason = my_strcmp(*tmp_first, *tmp_second);
}

static bool treat_ascii_order(tetrimino_t *tmp, char *tmp_first,
                            char *tmp_second, int *cmp_ascii_order)
{
    if ((*cmp_ascii_order) > 0)
        return (free_check_list_resources(tmp_first, tmp_second, 0));
    if ((*cmp_ascii_order) == 0) {
        *cmp_ascii_order = my_strcmp(tmp->prev->name, tmp->name);
        if ((*cmp_ascii_order) > 0)
            return (free_check_list_resources(tmp_first, tmp_second, 0));
    }
    return (1);
}

bool is_list_sorted(tetrimino_t **head)
{
    tetrimino_t *tmp = NULL;
    char *tmp_first = NULL;
    char *tmp_second = NULL;
    int cmp_ascii_order = 0;

    if (!head || !(*head))
        return (true);
    tmp = (*head)->next;
    do {
        reset_pointers_values(tmp, &tmp_first, &tmp_second, &cmp_ascii_order);
        if (!treat_ascii_order(tmp, tmp_first, tmp_second, &cmp_ascii_order))
            return (false);
        tmp = tmp->next;
        free_check_list_resources(tmp_first, tmp_second, 1);
    } while (tmp != (*head));
    return (true);
}