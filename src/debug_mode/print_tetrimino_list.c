/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_tetrimino_list.c
*/

#include "my.h"
#include "tetris.h"

static void print_tetrimino_values(tetrimino_t *tmp)
{
    if (!tmp)
        return;
    my_printf("Tetriminos : Name %s : ", tmp->name);
    my_printf((tmp->error ? "Error\n" : "Size %lu*%lu : Color %lu :\n"),
                tmp->dims.height, tmp->dims.width, tmp->color);
    if (!tmp->error)
        print_tetrimino_shape(tmp->shapes[0]);
}

void print_tetrimino_list(tetrimino_t **head)
{
    tetrimino_t *tmp = NULL;

    if (!head || !(*head))
        return;
    for (tmp = (*head); tmp && tmp != (*head)->prev; tmp = tmp->next)
        print_tetrimino_values(tmp);
    print_tetrimino_values(tmp);
}