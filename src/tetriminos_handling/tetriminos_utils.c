/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetrimino_utils
*/

#include "tetris.h"

size_t number_tetrimino(tetrimino_t *tetrimino_list)
{
    tetrimino_t *tmp = NULL;
    register size_t index = 0;

    if (!tetrimino_list || !(tetrimino_list->prev))
        return (index);
    tmp = tetrimino_list;
    do {
        index += 1;
        tmp = tmp->next;
    } while (tmp && tmp != tetrimino_list);
    return (index);
}

tetrimino_t *get_n_tetrimino(tetrimino_t *tetrimino_list, const size_t n)
{
    tetrimino_t *tmp = NULL;
    register size_t index = 0;

    if (!tetrimino_list)
        return (NULL);
    tmp = tetrimino_list;
    while (index < n && tmp && tmp->next) {
        tmp = tmp->next;
        index += 1;
    }
    if (tmp && tmp->error)
        return (NULL);
    return (tmp);
}