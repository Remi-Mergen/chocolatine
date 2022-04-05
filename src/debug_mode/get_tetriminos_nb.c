/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** Get the nb of tetriminos in the list.
*/

#include "tetris.h"
#include "my.h"

size_t get_tetriminos_nb(tetrimino_t **head)
{
    tetrimino_t *tmp = NULL;
    size_t nb = 0;

    if (!head || !(*head))
        return (0);
    tmp = *head;
    do {
        nb += 1;
        tmp = tmp->next;
    } while (tmp != *head);
    return (nb);
}