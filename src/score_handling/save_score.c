/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** save_score
*/

#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include "tetris_frame_template.h"

static void save_score(int data)
{
    FILE *fptr = fopen("high_score", "w");
    char *tmp = NULL;

    if (!fptr)
        return ;
    tmp = my_int_to_str(data);
    if (!tmp) {
        fclose(fptr);
        return ;
    }
    fwrite(tmp, sizeof(char), my_strlen(tmp), fptr);
    fclose(fptr);
    free(tmp);
}

ssize_t get_score(void)
{
    int fd = open("high_score", O_RDONLY);
    char *tmp = NULL;
    ssize_t nb = 0;

    if (fd == -1)
        return (0);
    tmp = get_next_line(fd);
    if (!tmp)
        return (0);
    close(fd);
    nb = my_getnbr(tmp);
    free(tmp);
    return (nb);
}

void should_save_score(game_data_t game_data)
{
    int data = game_data.left_panel.components[1].data;

    if (get_score() < data)
        save_score(data);
}