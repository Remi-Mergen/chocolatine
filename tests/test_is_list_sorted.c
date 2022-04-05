/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** test_is_list_sorted.c
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include "tetris.h"
#include "my.h"

static tetrimino_t *create_tetri_node(const char name[])
{
    tetrimino_t *node = NULL;

    node = malloc(sizeof(tetrimino_t));
    if (!node)
        return (NULL);
    *node = (tetrimino_t){.shapes = NULL, .name = my_strdup(name),
            .alloc_size = 0, .color = 1, .error = 0, .rotation = 0,
            .next = node, .prev = node};
    return (node);
}

Test(is_list_sorted, correct_sorting_one_node)
{
    tetrimino_t *head = NULL;

    head = create_tetri_node("test");
    cr_expect_eq(1, (head || head->name) ? is_list_sorted(&head) : 0);
    free_tetriminos_list(head);
}

Test(is_list_sorted, first_case_sensitive_true)
{
    tetrimino_t *head = NULL;

    head = create_tetri_node("abc");
    if (head)
        head->next = create_tetri_node("Acc");
    if (head && head->next) {
        head->next->prev = head;
        head->next->next = head;
        head->prev = head->next;
    }
    cr_expect_eq(1, (head || head->name) ? is_list_sorted(&head) : 0);
    free_tetriminos_list(head);
}

Test(is_list_sorted, first_case_sensitive_false)
{
    tetrimino_t *head = NULL;

    head = create_tetri_node("abc");
    if (head)
        head->next = create_tetri_node("Abc");
    if (head && head->next) {
        head->next->prev = head;
        head->next->next = head;
        head->prev = head->next;
    }
    cr_expect_eq(0, (head || head->name) ? is_list_sorted(&head) : 1);
    free_tetriminos_list(head);
}