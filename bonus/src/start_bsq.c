/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** main func for bsq
*/

#include <stdio.h>
#include <stdlib.h>
#include "bsqh.h"
#include "my.h"

int eval_digit(int **digit_map, int i, int j, bg_square_t *bg_square)
{
    int a, b, c;
    int value_set = 0;
 
    if (digit_map[i][j] == 0 || i == 0 || j == 0)
        return (0);
    a = digit_map[i][j - 1];
    b = digit_map[i - 1][j - 1];
    c = digit_map[i - 1][j];
    if (a <= b && a <= c && value_set == 0) {
        digit_map[i][j] = a + 1;
        value_set = 1;
    }
    if (b <= a && b <= c && value_set == 0) {
        digit_map[i][j] = b + 1;
        value_set = 1;
    }
    if (c <= a && c <= b && value_set == 0)
        digit_map[i][j] = c + 1;
    set_bg_square(digit_map, i, j, bg_square);
    return (0);
}

int eval_digit_map(char *map, long long size)
{
    bg_square_t *bg_square = malloc(sizeof(bg_square_t));
    int **digit_map = make_digit_map(map);
    int width = get_width(map);
    int length = get_length(map);
    int i = -1;
    int j = -1;
    int is_filled = is_correct_map(map, width, length);

    bg_square->size = 0;
    if (is_filled == 84)
        return (84);
    while (++i < length) {
        while (++j < width)
            eval_digit(digit_map, i, j, bg_square);
    j = -1;
    }
    make_sqr(bg_square, map, size, is_filled);
    free_alloc(map, bg_square, digit_map, length);
    return (0);
}

int bsq(char *filepath)
{
    long long size = get_byte_size(filepath);
    char *buffer;

    if (size == 0)
        return (84);
    buffer = read_map(filepath, size);
    if (buffer == NULL)
        return (84);
    return (eval_digit_map(buffer, size));
}