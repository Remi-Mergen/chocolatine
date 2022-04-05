/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** empty_queue
*/

#include "tetris.h"

bool empty_queue(tetrimino_t **queue)
{
    if (!queue)
        return (false);
    while (*queue)
        dequeue_tetrimino(queue);
    return (true);
}