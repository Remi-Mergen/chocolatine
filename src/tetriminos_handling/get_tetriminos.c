/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** get_tetriminos.c
*/

#include <stdbool.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include "tetris.h"

static bool free_node_first_line_and_quit(char **first_line,
                                        const bool return_val)
{
    my_free_arr((void **)first_line);
    return (return_val);
}

static bool fill_first_tetrimino_line(const int fd, tetrimino_t *node)
{
    char **first_line = NULL;
    int color_tmp = 0;

    if (!node || fd == -1)
        return (free_node_first_line_and_quit(first_line, false));
    first_line = my_str_to_word_array(get_next_line(fd), " ", 1);
    if (my_arrlen(first_line) != 3)
        return (free_node_first_line_and_quit(first_line, false));
    node->dims.width = my_absolute_getnbr(first_line[0]);
    if (node->dims.width <= 0)
        return (free_node_first_line_and_quit(first_line, false));
    node->dims.height = my_absolute_getnbr(first_line[1]);
    if (node->dims.height <= 0)
        return (free_node_first_line_and_quit(first_line, false));
    color_tmp = my_absolute_getnbr(first_line[2]);
    if (color_tmp < 0)
        return (free_node_first_line_and_quit(first_line, false));
    node->color = (size_t)color_tmp;
    return (free_node_first_line_and_quit(first_line, true));
}

void get_tetrimino(tetrimino_t *node, const char file_name[])
{
    char *absolute_path = NULL;
    int fd = -1;

    if (!node || !file_extension_determ(file_name, ".tetrimino"))
        return;
    node->name = my_strndup(file_name, my_strlen(file_name) - 10);
    if (!node->name) {
        node->error = true;
        return;
    }
    absolute_path = my_strcat("./tetriminos/", file_name);
    if (!absolute_path) {
        node->error = true;
        return;
    }
    fd = open(absolute_path, O_RDONLY);
    free(absolute_path);
    if (fd == -1 || !fill_first_tetrimino_line(fd, node)
        || !fill_shape(fd, node) || !init_all_oriented_shapes(node))
        node->error = true;
}