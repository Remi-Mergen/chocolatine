/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** tetris_usage.h
*/

#ifndef TETRIS_USAGE_H_

#define TETRIS_USAGE_H_

static const char usage[] = {
    "Usage:\t%s [options]\n"
    "Options:\n"
    "\t--help\t\t\t\t\t Display this help\n"
    "\t-L --level={num}\t\t\t Start Tetris at level num (def: 1)\n"
    "\t-l --key-left={K}\t\t\t Move the tetrimino LEFT "
    "using the K key (def: left arrow)\n"
    "\t-r --key-right={K}\t\t\t Move the tetrimino RIGHT "
    "using the K key (def: right arrow)\n"
    "\t-t --key-turn={K}\t\t\t TURN the tetrimino clockwise 90d "
    "using the K key (def: top arrow)\n"
    "\t-d --key-drop={K}\t\t\t DROP the tetrimino "
    "using the K key (def: down arrow)\n"
    "\t-q --key-quit={K}\t\t\t QUIT the game "
    "using the K key (def: 'q' key)\n"
    "\t-p --key-pause={K}\t\t\t PAUSE/RESTART the game "
    "using the K key (def: space bar)\n"
    "\t--map-size={row,col}\t\t\t Set the numbers of "
    "rows and columns of the map (def: 20,10)\n"
    "\t-w --without-next\t\t\t Hide next tetrimino (def: false)\n"
    "\t-D --debug\t\t\t\t Debug mode (def: false)\n"
};

#endif /* TETRIS_USAGE_H_ */