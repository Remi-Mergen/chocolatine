/*
** EPITECH PROJECT, 2019
** library
** File description:
** header for libmy
*/

#ifndef MY_H_

#define MY_H_

#include <stdbool.h>
#include <unistd.h>

//Returns 1 if the char is found else returns 0
int find_char_in_str(const char *str, const char c);
//Returns the index of str where to_find is found
//Returns -1 if to_find is not found
int find_char(const char *str, char to_find);

int my_putchar(const char c);
int my_putstr(const char *str);
int my_absolute_getnbr(const char *str);
int my_getnbr(const char *str);

bool my_is_lowercase(const char c);
bool my_is_uppercase(const char c);
int my_isalpha(const char c);
int my_isnum(const char c);
int my_str_is_num(const char *str);
int my_isalphanum(const char c);
int my_str_is_alphanum(const char *str);

// prints onto the stdout with custom flags to print variables
int my_printf(char const *input, ...);
// gets a line from a file, gets the next one at each function call
char *get_next_line(const int fd);

// -> all differents my_put_nbr's
void my_put_nbr(int nb, const char *base);
void my_put_nbr_u(unsigned int nb, const char *base);
void my_put_nbr_s(short int nb, const char *base);
void my_put_nbr_su(unsigned short int nb, const char *base);
void my_put_nbr_l(long int nb, const char *base);
void my_put_nbr_lu(unsigned long int nb, const char *base);
void my_put_nbr_ll(long long int nb, const char *base);
void my_put_nbr_llu(unsigned long long int nb, const char *base);

void my_memset(char *to_write_on, const char to_fill_with,
                const size_t nb_bytes);
void *my_memcpy(void *dest, const void *src, size_t n);

//computes len of types
int my_int_size(int nb, int i);
ssize_t my_strlen(const char *str);
int my_arrlen(char **array);

int my_pow(int nb, int p);
float my_powf(float nb, float p);

int my_strnlen(const char *str, const int n);
int my_strlen_char(const char *str, const char c);
int my_strlen_cmpstr(const char *str, const char cmp[]);

void my_show_arr(char **array);
int my_arrcmp(char **first, char **second);
char **my_arrdup(const char * const *template);
char **my_append_to_array(char **array, char *str, const int freer);
void my_free_arr(void **array);

char *my_strdup(const char *template);
char *my_strndup(const char *template, int n);
char *my_strdup_lowercase(const char *template);
char *my_strdup_char(const char *template, const char c);
char *my_strdup_cmpstr(const char *template, const char cmp[]);
bool my_mass_strcmp(const char *template, ...);
int my_strcmp(const char *first, const char *second);
int my_strncmp(const char *first, char const *second, const unsigned int n);
char *my_strcpy(char *dest, char const *src);
char *my_strcpychar(char *dest, char const *src, char const to_copy);
char *my_int_to_str(int nb);
int my_get_randomnb(const int min, const int max);

int my_skip_a_file_line(const int fd);

char *my_strcat(const char *core, const char *to_append);
char **my_str_to_word_array(char *sentence, const char splitter[],
                            const unsigned int freer);

#endif /* MY_H_ */
