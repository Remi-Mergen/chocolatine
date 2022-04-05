/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** read_tetriminos_dir.c
*/

#include <stdbool.h>
#include <dirent.h>
#include <stdlib.h>
#include "my.h"
#include "tetris.h"

static bool add_tetrimino(tetrimino_t **head, const char file_name[])
{
    tetrimino_t *node = NULL;

    if (!head || !(*head))
        return (false);
    node = malloc(sizeof(tetrimino_t));
    if (!node)
        return (false);
    *node = (tetrimino_t){.shapes = {NULL, NULL, NULL, NULL},
            .name = NULL, .alloc_size = 0, .color = 0,
            .error = false, .rotation = 0, .dims = {0, 0},
            .next = NULL, .prev = NULL};
    get_tetrimino(node, file_name);
    node->next = *head;
    node->prev = (*head)->prev;
    (*head)->prev->next = node;
    (*head)->prev = node;
    return (true);
}

static bool add_first_tetrimino(tetrimino_t **head, const char file_name[])
{
    tetrimino_t *node = NULL;

    if (!head || (*head))
        return (false);
    node = malloc(sizeof(tetrimino_t));
    if (!node)
        return (false);
    *node = (tetrimino_t){.shapes = {NULL, NULL, NULL, NULL},
            .name = NULL, .alloc_size = 0, .color = 0,
            .error = false, .rotation = 0, .dims = {0, 0},
            .next = NULL, .prev = NULL};
    get_tetrimino(node, file_name);
    node->next = node;
    node->prev = node;
    *head = node;
    return (true);
}

static bool add_new_tetri_to_list(tetrimino_t **head, char entire_file_name[])
{
    if (!(*head)) {
        if (!add_first_tetrimino(head, entire_file_name))
            return (false);
    } else {
        if (!add_tetrimino(head, entire_file_name))
            return (false);
    }
    return (true);
}

bool read_tetriminos_dir(tetrimino_t **head)
{
    struct dirent *dir_stat = NULL;
    DIR *dir = NULL;

    if (!head)
        return (false);
    dir = opendir("./tetriminos/");
    if (!dir)
        return (false);
    for (dir_stat = readdir(dir); dir_stat; dir_stat = readdir(dir)) {
        if (!file_extension_determ(dir_stat->d_name, ".tetrimino"))
            continue;
        if (!add_new_tetri_to_list(head, dir_stat->d_name))
            return (false);
    }
    closedir(dir);
    return (true);
}