/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** sort_tetrimino_list.c
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

static void swap_tetrimino_nodes(tetrimino_t **head, tetrimino_t *first,
                                    tetrimino_t *second)
{
    tetrimino_t *fir_prev = NULL;
    tetrimino_t *sec_next = NULL;
    bool move_head = false;

    if (!first || !second)
        return;
    if (*head == first)
        move_head = true;
    fir_prev = first->prev;
    sec_next = second->next;
    first->next = sec_next;
    sec_next->prev = first;
    first->prev = second;
    second->prev = fir_prev;
    fir_prev->next = second;
    second->next = first;
    if (move_head)
        *head = second;
}

static void reset_pointers_values(tetrimino_t *tmp, char **tmp_first,
                                char **tmp_second, int *cmp_reason)
{
    *tmp_first = my_strdup_lowercase(tmp->prev->name);
    *tmp_second = my_strdup_lowercase(tmp->name);
    *cmp_reason = my_strcmp(*tmp_first, *tmp_second);
}

static void free_tmps(char *tmp_first, char *tmp_second)
{
    if (tmp_first)
        free(tmp_first);
    if (tmp_second)
        free(tmp_second);
}

static void rearrange_ascii_order(tetrimino_t **head, tetrimino_t *tmp,
                                    char **tmp_first, char **tmp_second)
{
    int cmp_ascii_order = 0;

    reset_pointers_values(tmp, tmp_first, tmp_second, &cmp_ascii_order);
    if (cmp_ascii_order > 0)
        swap_tetrimino_nodes(head, tmp->prev, tmp);
    else if (cmp_ascii_order == 0) {
        cmp_ascii_order = my_strcmp(tmp->prev->name, tmp->name);
        if (cmp_ascii_order > 0)
            swap_tetrimino_nodes(head, tmp->prev, tmp);
    }
}

void sort_tetrimino_list(tetrimino_t **head)
{
    tetrimino_t *tmp = NULL;
    char *tmp_first = NULL;
    char *tmp_second = NULL;

    if (!head || !(*head) || (*head) == (*head)->next)
        return;
    for (tmp = (*head)->next; !is_list_sorted(head); tmp = tmp->next) {
        if (tmp == (*head))
            tmp = tmp->next;
        rearrange_ascii_order(head, tmp, &tmp_first, &tmp_second);
        free_tmps(tmp_first, tmp_second);
    }
}