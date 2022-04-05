/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** find_char
*/

int find_char(const char *str, char to_find)
{
    int index = 0;

    if (!str)
        return (-1);
    while (str[index]) {
        if (!(str[index] ^ to_find))
            return (index);
        index += 1;
    }
    return (-1);
}