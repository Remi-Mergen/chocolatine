/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** update_queue
*/

#include "my.h"
#include "tetris.h"

bool update_queue(tetrimino_t **queue, tetrimino_t *tetrimino_list)
{
    tetrimino_t *tmp = NULL;
    size_t index = 0;

    if (!queue)
        return (false);
    index = number_tetrimino(tetrimino_list);
    if (!(*queue) || !((*queue)->next)) {
        tmp = get_n_tetrimino(tetrimino_list, my_get_randomnb(0, index));
        return (enqueue_tetrimino(queue, tmp));
    }
    return (false);
}