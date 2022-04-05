/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** update_timer
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

static char *create_time_code(const int seconds, const int minutes)
{
    char *tmp = NULL;
    char *tmp2 = NULL;
    char *s_str = NULL;
    char *m_str = NULL;

    s_str = my_int_to_str(seconds);
    m_str = my_int_to_str(minutes);
    if (!s_str || !m_str)
        return (NULL);
    tmp = my_strcat(m_str, ":");
    tmp2 = my_strcat(tmp, s_str);
    free(s_str);
    free(m_str);
    if (tmp)
        free(tmp);
    return (tmp2);
}

void update_timer(frame_component_t *frame)
{
    int absolute_time = (clock() - frame->data) / CLOCKS_PER_SEC;
    int seconds = absolute_time % 60;
    int minutes = absolute_time / 60;

    if (frame->display_str) {
        free(frame->display_str);
        frame->display_str = NULL;
    }
    frame->display_str = create_time_code(seconds, minutes);
}