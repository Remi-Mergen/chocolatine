/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** free_tetriminos_list.c
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

static void free_tetriminos_node(tetrimino_t *node)
{
    register size_t index = 0;

    if (!node)
        return;
    if (node->name)
        free(node->name);
    for (index = 0; index < 4; index += 1)
        my_free_arr((void **)node->shapes[index]);
    free(node);
}

void free_tetriminos_list(tetrimino_t *head)
{
    tetrimino_t *tmp = NULL;
    tetrimino_t *save = NULL;

    if (!head)
        return;
    save = head->prev;
    for (tmp = head; tmp != save; tmp = head) {
        head = head->next;
        if (tmp)
            free_tetriminos_node(tmp);
    }
    if (tmp)
        free_tetriminos_node(tmp);
}