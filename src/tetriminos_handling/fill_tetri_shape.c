/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** fill_tetri_shape.c
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

static ssize_t get_shape_line(const int fd, bool *star_found)
{
    ssize_t line_len = 0;
    size_t index = 0;
    char *line = NULL;

    line = get_next_line(fd);
    if (!line)
        return (-1);
    line_len = my_strlen(line);
    while (line[index]) {
        if (line[index] == '*')
            *star_found = true;
        else if (line[index] != ' ')
            return (-2);
        index += 1;
    }
    while (line_len > 0 && line[line_len] != '*')
        line_len -= 1;
    free(line);
    return (line_len + 1);
}

static ssize_t get_shape_alloc_size(const int fd, const dimensions_t dims)
{
    bool star_found = false;
    ssize_t max_len = -1;
    ssize_t tmp_len = -1;
    size_t nb_lines = 0;

    do {
        tmp_len = get_shape_line(fd, &star_found);
        if (tmp_len > max_len)
            max_len = tmp_len;
        if (tmp_len > 0)
            nb_lines += 1;
    } while (tmp_len > -1);
    if (!star_found || tmp_len == -2 || nb_lines == 0
        || nb_lines != dims.height || (size_t)max_len != dims.width)
        return (-1);
    lseek(fd, 0, SEEK_SET);
    my_skip_a_file_line(fd);
    return ((ssize_t)nb_lines >= max_len) ? (ssize_t)nb_lines : max_len;
}

bool fill_shape(const int fd, tetrimino_t *node)
{
    register size_t index = 0;
    char *line = NULL;

    if (!node || fd == -1)
        return (false);
    node->alloc_size = get_shape_alloc_size(fd, node->dims);
    if (node->alloc_size <= 0)
        return (false);
    node->shapes[UPSIDE] = get_blank_tetrimino(node->alloc_size);
    if (!(node->shapes[UPSIDE]))
        return (false);
    for (index = 0; index < (size_t)node->alloc_size; index += 1) {
        line = get_next_line(fd);
        my_strcpychar(node->shapes[UPSIDE][index], line, '*');
        if (line)
            free(line);
    }
    return (true);
}