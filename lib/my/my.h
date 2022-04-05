/*
** EPITECH PROJECT, 2019
** my
** File description:
** my header file
*/

#ifndef MY_H
#define MY_H

int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb);

int my_find_prime_sup(int nb);

int my_getnbr(char const *str);

int my_isneg(int n);

int my_is_prime(int nb);

void my_putchar(char c);

int my_put_nbr(int nb);

int my_putstr(char const *str);

char *my_revstr(char *str);

int my_showmem(char const *str);

int my_showstr(char const *str);

int my_show_word_array(char * const *tab);

void my_sort_int_array(int *tab, int size);

char *my_strcapitalize(char *str);

char *my_strcat(char *dest, char const *src);

int my_strcmp(char *s1, char *s2);

char *my_strcpy(char *dest, char const *src);

int my_str_isalpha(char const *str);

int my_str_islower(char const *str);

int my_str_isnum(char const *str);

int my_str_isprintable(char const *str);

int my_str_isupper(char const *str);

int my_strlen(char const *str);

char *my_strlowcase(char *str);

char *my_strncat(char *dest, char const *src, int nb);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strncpy(char *dest, char const *src, int n);

char *my_strstr(char *str, char *to_find);

char **my_str_to_word_array(char const *str);

char *my_strupcase(char *str);

void my_swap(int *a, int *b);

int get_char_nbr(int number);

int is_neg(int nbr);

int power_nbr(int nbr, int char_nbr);

int get_char_number(char const *str, int i);

int get_word_nbr(char const *str);

char *my_strdup_word(char const *str, int *i);

int is_negat(int first_digit_nbr, char const *string);

int powering_ten(int len);

int my_arrlen(char **str);

int my_intlen(int *tab);

char *my_strcpaddress(char **dest, char const *src);

void my_memset(char *str, char c, int len);

char *init_op(char *a, char *b);

char *negatisator(char *str);

char *mult(char *a, char *b);

char *division(char *a, char *b);

char *my_strdup(char *src);

void my_put_char(char nb, char *base, int sizebase);

void my_put_uchar(unsigned char nb, char *base, int sizebase);

void my_put_short(short nb, char *base, int sizebase);

void my_put_ushort(unsigned short nb, char *base, int sizebase);

void my_put_int(int nb, char *base, int sizebase);

void my_put_uint(unsigned int nb, char *base, int sizebase);

void my_put_long(long nb, char *base, int sizebase);

void my_put_ulong(unsigned long int nb, char *base, int sizebase);

void my_put_long_long(long long nb, char *base, int sizebase);

void my_put_ulong_long(unsigned long long nb, char *base, int sizebase);

int my_put_address(void *ptr);

#endif
