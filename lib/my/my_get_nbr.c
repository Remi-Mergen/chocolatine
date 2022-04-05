/*
** EPITECH PROJECT, 2019
** my_get_nbr
** File description:
** returns a number sent to the function as a string
*/

int is_negat(char const *string)
{
    int neg = 0;
    int i = 0;

    while (string[i] == 45 || string[i] == 43) {
        if (string[i] == 45) {
            neg += 1;
        }
        i += 1;
    }
    neg %= 2;
    return (neg);
}

long long int powering_ten(int len)
{
    int i = 1;
    long long int ten_power = 1;

    while (i < len) {
        ten_power *= 10;
        i += 1;
    }
    return (ten_power);
}

int get_digit_len(char const *str)
{
    int i = 0;
    int len_nbr = 0;

    while (str[i] == '-' || str[i] == '+')
        i += 1;
    while (str[i] >= 48 && str[i] <= 57) {
        i += 1;
        len_nbr += 1;
    }
    return (len_nbr);
}

int get_first_digit(char const *str)
{
    int i = 0;
    while (str[i] == '-' || str[i] == '+')
        i += 1;
    return (i);
}

int my_getnbr(char const *str)
{
    int neg = is_negat(str);
    int nb_len = get_digit_len(str);
    long long int ten_power = powering_ten(nb_len);
    int i = get_first_digit(str);
    long long int nbl = 0;
    int nb;

    while (str[i] >= 48 && str[i] <= 57) {
        nbl = ((str[i] - 48)  * ten_power) + nbl;
        ten_power /= 10;
        i += 1;
    }
    if (neg == 1)
        nbl *= -1;
    if (nbl > 2147483647 || nbl < -2147483647)
        return (0);
    nb = nbl;
    return (nb);
}
