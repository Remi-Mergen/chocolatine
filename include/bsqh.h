/*
** EPITECH PROJECT, 2019
** bsqh
** File description:
** bsq header
*/

#ifndef BSQH_H_
#define BSQH_H_

typedef struct bg_square{
    int x;
    int y;
    int size;
} bg_square_t;

int get_length(char const *map);
int get_width(char const *map);
long long get_byte_size(char const *filepath);

int is_correct_map(char *map, int width, int length);
char *read_map(char const *filepath, long long size);


int **make_digit_map(char *map);
int eval_digit(int **digit_map, int i, int j, bg_square_t *bg_square);
void set_bg_square(int **digit_map, int i, int j, bg_square_t *bg_square);
void make_sqr(bg_square_t *square, char *map,
    long long size_fd, int is_filled);
void print_square(int i);

void is_bckslsh(char *map, int k);
void free_alloc(char *map, bg_square_t *bg_square, int **digit_map, int length);

int bsq(char *filepath);

#endif
