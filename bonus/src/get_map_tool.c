/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** find the largest square
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int is_bckslsh(char *map, int k);

long long get_byte_size(char const *filepath)
{
    struct stat *stat_buf = malloc(sizeof(struct stat));
    long long size;

    if (stat(filepath, stat_buf) == 0) {
        size = stat_buf->st_size;
    }
    free(stat_buf);
    return (size);
}

int get_width(char const *map)
{
    int i = 0;
    int j = 1;
    while (map[i] != '\n')
        i++;
    while (map[i + j] != '\n')
    j++;
    return (j - 1);
}

int get_length(char const *map)
{
    int i = 0;
    int j = -1;
    char *tmp;
    int length;

    while (map[i] != '\n')
        i++;
    tmp = malloc(sizeof(char *) * (i + 1));
    if (tmp == NULL)
        return (0);
    while (++j < i)
        tmp[j] = map[j];
    tmp[j] = '\0';
    length = my_getnbr(tmp);
    free(tmp);
    return (length);
}

char *read_map(char const *filepath, long long size)
{
    char *buffer = malloc(size + 1);
    int fd = 0;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (NULL);
    read(fd, buffer, size);
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}

int **make_digit_map(char *map)
{
    int i = -1;
    int j = -1;
    int k = -1;
    int length = get_length(map);
    int width = get_width(map);
    int **digit_map = malloc(sizeof(int *) * (length + 1));

    while (*(++map) != '\n');
    map++;
    while (++i < length) {
        digit_map[i] = malloc(sizeof(int) * (width + 1));
        while (++j < width) {
            k = is_bckslsh(map, k);
            digit_map[i][j] = (map[k] + 1) % 2;
        }
    j = -1;
    }
    return (digit_map);
}