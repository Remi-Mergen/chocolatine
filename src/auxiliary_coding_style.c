/*
** EPITECH PROJECT, 2019
** auxiliary_coding_style
** File description:
** all's in the name
*/

int increment_index(int *i, int *k, int *y, int width)
{
    *i += *k;
        if (*k != width)
            return (84);
        *k = -1;
        *y += 1;
        *i += 1;
    return (0);
}

void check_is_filled( char *map, int k, int i, int *is_filled)
{
    if (map[k + i] == '.')
        *is_filled = 0;
}

int is_bckslsh(char *map, int k)
{
    if (map[++k] == '\n')
                k++;
    return (k);
}