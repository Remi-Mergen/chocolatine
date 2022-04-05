/*
** EPITECH PROJECT, 2019
** my_find_prime_sup
** File description:
** returns the smallest prime number >= to the number given as parameter
*/

int my_find_prime_sup(int nb)
{
    int i = 2;

    while (i < nb) {
        if ((nb % i == 0)) {
            nb += 1;
            i = 2;
        }
        i += 1;
    }
    if (nb > 2147483647) {
        return (0);
    }
    return (nb);
}