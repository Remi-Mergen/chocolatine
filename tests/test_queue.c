/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_queue
*/

#include <criterion/criterion.h>
#include "tetris.h"
#include "my.h"

Test(queue_tests, dequeue_fail)
{
    tetrimino_t *queue = NULL;

    cr_assert(!dequeue_tetrimino(&queue));
}

Test(queue_tests, dequeue_fail_2)
{
    cr_assert(!dequeue_tetrimino(NULL));
}

Test(queue_tests, dequeue_success)
{
    tetrimino_t *queue = malloc(sizeof(tetrimino_t));

    if (!queue)
        cr_assert(1);
    queue->next = NULL;
    dequeue_tetrimino(&queue);
    cr_assert(!queue);
}

Test(queue_tests, empty_queue_fail)
{
    cr_assert(!empty_queue(NULL));
}

Test(queue_tests, empty_queue_success)
{
    tetrimino_t *queue = malloc(sizeof(tetrimino_t));
    tetrimino_t *tmp = malloc(sizeof(tetrimino_t));

    if (!queue || !tmp)
        cr_assert(1);
    queue->next = tmp;
    tmp->next = NULL;
    empty_queue(&queue);
    cr_assert(!queue);
}

Test(queue_tests, enqueue_fail_1)
{
    cr_assert(!enqueue_tetrimino(NULL, NULL));
}

Test(queue_tests, enqueue_fail_2)
{
    tetrimino_t *queue = NULL;

    cr_assert(!enqueue_tetrimino(&queue, NULL));
}

Test(queue_tests, enqueue_success_one_tetri)
{
    tetrimino_t *queue = NULL;
    tetrimino_t *tetri = malloc(sizeof(tetrimino_t));

    if (!tetri)
        cr_assert(1);
    cr_assert(enqueue_tetrimino(&queue, tetri));
}

Test(queue_tests, enqueue_success_two_tetri)
{
    tetrimino_t *queue = NULL;
    tetrimino_t *tetri = malloc(sizeof(tetrimino_t));

    if (!tetri)
        cr_assert(1);
    my_memset((char *)tetri, 0, sizeof(tetrimino_t));
    enqueue_tetrimino(&queue, tetri);
    enqueue_tetrimino(&queue, tetri);
    if (queue && queue->next && !(queue->next->next))
        cr_assert(1);
    else
        cr_assert(0);
}

Test(queue_tests, update_queue_fail_1)
{
    tetrimino_t *queue = NULL;

    cr_assert(!update_queue(&queue, NULL));
}

Test(queue_tests, update_queue_fail_2)
{
    tetrimino_t *tetri = malloc(sizeof(tetrimino_t));

    cr_assert(!update_queue(NULL, tetri));
}

Test(queue_tests, update_queue_success_1)
{
    tetrimino_t *queue = NULL;
    tetrimino_t *tetri = malloc(sizeof(tetrimino_t));

    if (!tetri)
        cr_assert(1);
    my_memset((char *)tetri, 0, sizeof(tetrimino_t));
    tetri->next = tetri;
    tetri->prev = tetri;
    cr_assert(update_queue(&queue, tetri));
}

Test(queue_tests, update_queue_success_2)
{
    tetrimino_t *queue = NULL;
    tetrimino_t *tetri = malloc(sizeof(tetrimino_t));

    if (!tetri)
        cr_assert(1);
    my_memset((char *)tetri, 0, sizeof(tetrimino_t));
    tetri->next = tetri;
    tetri->prev = tetri;
    update_queue(&queue, tetri);
    cr_assert(update_queue(&queue, tetri));
}