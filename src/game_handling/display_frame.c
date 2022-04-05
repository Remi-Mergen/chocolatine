/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display_frame
*/

#include "my.h"
#include "tetris.h"

static void display_frame_component(frame_component_t component, pos_t pos)
{
    init_pair(component.name_color, component.name_color,
                                        COLOR_BLACK);
    attron(COLOR_PAIR(component.name_color));
    mvprintw(pos.y + component.pos.y, pos.x + component.pos.x, component.name);
    attroff(COLOR_PAIR(component.name_color));
    if (component.display_str) {
        init_pair(component.display_str_color, component.display_str_color,
                    COLOR_BLACK);
        attron(COLOR_PAIR(component.display_str_color));
        mvprintw(pos.y + component.pos.y,
                pos.x + component.pos.x + my_strlen(component.name),
                component.display_str);
        attroff(COLOR_PAIR(component.display_str_color));
    }
}

static pos_t compute_frame_pos(frame_t frame, pos_t middle_pos,
                                dimensions_t midde_size)
{
    pos_t pos = middle_pos;

    pos.x += frame.offset.x;
    pos.y += frame.offset.y;
    if (frame.anchor.x == 1)
        pos.x += midde_size.width + 2;
    else if (frame.anchor.x == -1)
        pos.x -= frame.size.width + 2;
    if (frame.anchor.y == 1)
        pos.y += midde_size.height + 2;
    else if (frame.anchor.y == -1)
        pos.y -= frame.size.height + 2;
    return (pos);
}

void display_frame(frame_t frame, pos_t middle_pos, dimensions_t midde_size)
{
    register size_t index = 0;
    pos_t pos = compute_frame_pos(frame, middle_pos, midde_size);

    if (pos.x < 0 || pos.y < 0)
        return ;
    display_board(frame.board, frame.size, pos);
    while (index < frame.component_nb) {
        display_frame_component(frame.components[index], pos);
        index += 1;
    }
}

void display_next_tetrimino(tetrimino_t *queue, frame_t frame,
                            pos_t middle_pos, dimensions_t midde_size)
{
    pos_t pos = compute_frame_pos(frame, middle_pos, midde_size);
    tetrimino_t *next = NULL;

    if (!queue || !(queue->next))
        return ;
    next = queue->next;
    display_tetrimino(next, (pos_t){1, 1}, pos);
}
