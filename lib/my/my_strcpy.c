/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** copies a string into another
*/

#include <unistd.h>

ssize_t my_strlen(const char *string);

char *my_strcpy(char *dest, char const *src)
{
    int len = my_strlen(src);
    int i = 0;

    while (i < len) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}