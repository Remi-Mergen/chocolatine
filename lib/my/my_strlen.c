/*
** EPITECH PROJECT, 2019
** library
** File description:
** gets a string length
*/

#include <unistd.h>

ssize_t my_strlen(const char *str)
{
    ssize_t index = -1;

    while (str && str[++index]);
    return (index);
}