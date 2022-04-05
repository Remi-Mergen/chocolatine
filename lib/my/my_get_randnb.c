/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Gets a random integer in a given range.
*/

#include <stdbool.h>
#include "stdlib.h"

int my_get_randomnb(const int min, const int max)
{
    static bool start_randomizer = false;
    int nb = 0;

    if (!start_randomizer) {
        srand((size_t)&start_randomizer);
        start_randomizer = true;
    }
    if (!max || (max == min))
        return (max);
    nb = rand() % (max - min) + min;
    return (nb);
}