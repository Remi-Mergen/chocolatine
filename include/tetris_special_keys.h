/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** tetris_special_keys.h
*/

#ifndef TETRIS_SPECIAL_KEYS_H_

#define TETRIS_SPECIAL_KEYS_H_

#include <stddef.h>
#include <ncurses.h>

struct special_key {
    int character;
    char *to_print;
};

static struct special_key const special_keys[6] = {
    {.character = ' ', .to_print = "(space)\n"},
    {.character = KEY_LEFT, .to_print = "^EOD\n"},
    {.character = KEY_RIGHT, .to_print = "^EOC\n"},
    {.character = KEY_UP, .to_print = "^EOA\n"},
    {.character = KEY_DOWN, .to_print = "^EOB\n"},
    {.character = -1, .to_print = NULL},
};

#endif /* TETRIS_SPECIAL_KEYS_H_ */