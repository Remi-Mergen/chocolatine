/*
** EPITECH PROJECT, 2019
** my_strcpychar
** File description:
** copies a specific char from a string into another
*/

#include <unistd.h>

ssize_t my_strlen(const char *string);

char *my_strcpychar(char *dest, char const *src, char const to_copy)
{
    int len = my_strlen(src);
    int i = 0;

    if (!dest || !src)
        return (NULL);
    while (i < len && src[i]) {
        if (src[i] == to_copy) {
            dest[i] = src[i];
        }
        i++;
    }
    return (dest);
}