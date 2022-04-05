/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Main function of the tetris program.
*/

#include "my.h"
#include "tetris_usage.h"
#include "tetris.h"

static void print_usage(char *binary_name)
{
    my_printf(usage, binary_name);
}

static bool should_print_usage(const int ac, char * const av[])
{
    register int index = 0;

    for (index = 0; index < ac; index += 1) {
        if (my_mass_strcmp(av[index], "-h", "--help", NULL))
            return (true);
    }
    return (false);
}

int main(const int ac, char * const av[])
{
    int tetris_end = 0;

    if (ac < 1 || !av || !av[0])
        return (84);
    if (should_print_usage(ac, av)) {
        print_usage(av[0]);
        return (0);
    }
    tetris_end = tetris(ac, av);
    if (tetris_end == 84)
        print_usage(av[0]);
    return (tetris_end);
}