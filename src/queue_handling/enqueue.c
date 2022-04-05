/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** enqueue
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

static void enqueue_first_tetrimino(tetrimino_t **queue,
                                    tetrimino_t *tetrimino)
{
    (*queue) = tetrimino;
}

static void enqueue_new_tetrimino(tetrimino_t *queue,
                                    tetrimino_t *tetrimino)
{
    for (; queue->next; queue = queue->next);
    queue->next = tetrimino;
}

bool enqueue_tetrimino(tetrimino_t **queue, tetrimino_t *tetrimino)
{
    tetrimino_t *new_tetrimino = NULL;

    if (!queue || !tetrimino)
        return (false);
    new_tetrimino = malloc(sizeof(tetrimino_t));
    if (!new_tetrimino)
        return (false);
    my_memcpy(new_tetrimino, tetrimino, sizeof(tetrimino_t));
    new_tetrimino->next = NULL;
    new_tetrimino->prev = NULL;
    if (!(*queue))
        enqueue_first_tetrimino(queue, new_tetrimino);
    else
        enqueue_new_tetrimino(*queue, new_tetrimino);
    return (true);
}