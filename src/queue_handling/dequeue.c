/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** dequeue
*/

#include <stdlib.h>
#include "tetris.h"

bool dequeue_tetrimino(tetrimino_t **queue)
{
    tetrimino_t *save = NULL;

    if (!queue || !(*queue))
        return (false);
    save = *queue;
    *queue = (*queue)->next;
    free(save);
    return (true);
}