/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** print_prog_stats.c
*/

#include "my.h"
#include "tetris_special_keys.h"
#include "tetris.h"

static void print_key(const int c)
{
    register size_t i = 0;

    while (special_keys[i].to_print) {
        if (special_keys[i].character == c) {
            my_putstr(special_keys[i].to_print);
            return;
        }
        i += 1;
    }
    my_printf("%c\n", c);
}

static void print_selected_keys(const int control_keys[4],
                                const int options_keys[2])
{
    register size_t i = 0;
    register size_t nb_key_print = 0;
    const char *keys[] = {"Key Left : ", "Key Right : ", "Key Turn : ",
                        "Key Drop : ", "Key Quit : ", "Key Pause : ", NULL};

    while (i < 4) {
        my_putstr(keys[nb_key_print]);
        print_key(control_keys[i]);
        nb_key_print += 1;
        i += 1;
    }
    for (i = 0; keys[nb_key_print]; i += 1) {
        my_putstr(keys[nb_key_print]);
        print_key(options_keys[i]);
        nb_key_print += 1;
    }
}

void print_prog_stats(tetrimino_t **head, const option_t opt)
{
    my_putstr("*** DEBUG MODE ***\n");
    print_selected_keys(opt.control_keys, opt.option_keys);
    my_putstr(opt.game_option & NO_NEXT ? "Next : No\n" : "Next : Yes\n");
    my_printf("Level : %u\n", opt.level);
    my_printf("Size : %lu*%lu\n", opt.map_size.width, opt.map_size.height);
    my_printf("Tetriminos: %lu\n", get_tetriminos_nb(head));
    sort_tetrimino_list(head);
    print_tetrimino_list(head);
}