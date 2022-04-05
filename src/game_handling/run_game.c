/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** run_game
*/

#include "my.h"
#include "tetris.h"
#include "tetris_frame_template.h"

static pos_t compute_board_position(option_t options)
{
    pos_t win_dim = {getmaxx(stdscr), getmaxy(stdscr)};

    return ((pos_t){(win_dim.x / 2) - (options.map_size.width / 2),
                    (win_dim.y / 2) - (options.map_size.height / 2)});
}

static bool should_update_game(game_data_t *game_data)
{
    static clock_t start = 0;
    clock_t end = clock();
    int level = game_data->left_panel.components[LEVEL].data;

    if (!start)
        start = clock();
    if (end - start > 1000000 / (level)) {
        start = end;
        return (true);
    }
    return (false);
}

static bool run_game(game_data_t *game_data, option_t options,
                        tetrimino_t *tetrimino_list)
{
    pos_t board_pos = compute_board_position(options);
    static tetrimino_t *queue = NULL;

    refresh();
    erase();
    update_queue(&queue, tetrimino_list);
    display_all(game_data, queue, options, board_pos);
    parse_input(game_data, &queue, options);
    if (!should_update_game(game_data))
        return (true);
    should_break_line(game_data, options);
    land_tetrimino(game_data, &queue, options);
    if (game_data->quit) {
        empty_queue(&queue);
        return (false);
    }
    return (true);
}

static bool check_for_available_tetriminos(tetrimino_t **head)
{
    tetrimino_t *tmp = NULL;

    if (!head || !(*head))
        return (false);
    for (tmp = *head; tmp != (*head)->prev;tmp = tmp->next) {
        if (!(tmp->error))
            return (true);
    }
    return (!tmp->error) ? true : false;
}

int game(option_t options, tetrimino_t **tetrimino_list)
{
    game_data_t game_data;

    if (!check_for_available_tetriminos(tetrimino_list)
        || !init_game_data(&game_data, options))
        return (84);
    initscr();
    cbreak();
    keypad(stdscr, true);
    timeout(0);
    start_color();
    do {
        update_timer(game_data.left_panel.components + TIMER);
    } while (run_game(&game_data, options, *tetrimino_list));
    endwin();
    should_save_score(game_data);
    free_game_data(game_data);
    return (0);
}