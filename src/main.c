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

int bsq(char *filepath);

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    return (bsq(av[1]));
}