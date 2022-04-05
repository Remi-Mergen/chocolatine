/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_


#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <ncurses.h>


//Defines the boundaries of a component.
typedef struct dimensions_s {
    size_t width;
    size_t height;
} dimensions_t;


//Defines the position of a component.
typedef struct pos_s {
    ssize_t x;
    ssize_t y;
} pos_t;


#define VEC(x, y) (pos_t){x, y}


typedef enum shape_valid_e {
    VOID,
    CORRECT,
    INCORRECT
} shape_valid_t;


typedef enum orientation_e {
    UPSIDE,
    RIGHTSIDE,
    DOWNSIDE,
    LEFTSIDE
} orientation_t;


//A tetrimino's characteristics.
typedef struct tetrimino_s {
    char **shapes[4];
    char *name;
    dimensions_t dims;
    ssize_t alloc_size;
    size_t color;
    bool error;
    unsigned int rotation : 2;
    struct tetrimino_s *next;
    struct tetrimino_s *prev;
} tetrimino_t;


//Enum for the chosen gamemode.
typedef enum option_flag_e {
    DEBUG = 1,
    NO_NEXT = 2
} option_flag_t;


//Enum corresponding to the control_keys index
typedef enum key_code_e {
    KEY_CODE_LEFT = 0,
    KEY_CODE_RIGHT = 1,
    KEY_CODE_TURN = 2,
    KEY_CODE_DROP = 3,
    KEY_CODE_QUIT = 0,
    KEY_CODE_PAUSE = 1,
} key_code_t;


typedef struct option_s {
    unsigned int level;
    unsigned int game_option : 2;
    dimensions_t map_size;
    int control_keys[4];
    int option_keys[2];
} option_t;


typedef struct cell_s {
    char cell;
    char color;
} cell_t;


typedef enum cell_style_s {
    STYLE_0,
    STYLE_1
} cell_style_t;


typedef struct frame_component_s {
    ssize_t data;
    char *display_str;
    char display_str_color;
    char *name;
    char name_color;
    pos_t pos;
} frame_component_t;


typedef struct frame_s {
    cell_t **board;
    cell_style_t style;
    dimensions_t size;
    pos_t anchor;
    pos_t offset;
    size_t component_nb;
    frame_component_t *components;
} frame_t;


typedef struct game_data_s {
    cell_t **board;
    frame_t left_panel;
    frame_t right_panel;
    pos_t cursor;
    bool quit;
} game_data_t;



/*
** ******************
** | Option Parsing |
** ******************
*/

//Parses all of the given options.
//
//If a flag isn't found, returns false (0).
bool parse_option(const int ac, char * const av[], option_t *options);

/*
** ***********************
** | Tetriminos Handling |
** ***********************
*/

//Reads the "./tetriminos/" directory and checks all of the
//tetriminos properties.
//
//Fills the tetrimino_t simple linked list.
//
//Returns 1 if there's no issue.
//Returns 0 otherwise.
bool read_tetriminos_dir(tetrimino_t **head);

//Checks a tetrimino properties.
//
//Fills the tetrimino_t node.
//
//Returns 1 if there's no issue.
//Returns 0 otherwise.
void get_tetrimino(tetrimino_t *node, const char file_name[]);

bool fill_shape(const int fd, tetrimino_t *node);

//Returns a square blank tetrimino full of ' ' with alloc_size
char **get_blank_tetrimino(size_t alloc_size);

//Returns the height of a tetrimino
//Height is computed of alloc size minus all full 'space' line detached to
//tetrimino body
size_t get_tetriminos_height(tetrimino_t *tetrimino);

//Fills all the oriented shapes such as:
//-RIGHTSIDE
//-DOWNSIDE
//-LEFTSIDE
//Returns 1 if there's no issue.
//Returns 0 otherwise.
bool init_all_oriented_shapes(tetrimino_t *tetrimino);

//Free's allocated memory of a tetrimino list with memory checkers before
//freeing.
void free_tetriminos_list(tetrimino_t *head);

//Checks if a file_name as a certain given extension.
//
//Returns 1 if it has.
//Returns 0 otherwise.
bool file_extension_determ(const char file_name[], const char extension[]);

/*
** **************
** | Debug mode |
** **************
*/

//Returns the number of tetriminos in a list of tetriminos.
size_t get_tetriminos_nb(tetrimino_t **head);
//Returns the number of tetriminos in a list of tetriminos.
size_t number_tetrimino(tetrimino_t *tetrimino_list);

//Returns the n tetrimino in a list of tetriminos.
tetrimino_t *get_n_tetrimino(tetrimino_t *tetrimino_list, const size_t n);

//Checks whether a tetrimino list is sorted.
bool is_list_sorted(tetrimino_t **head);

//Sorts a tetrimino list by ASCII, non-case sensitive order.
void sort_tetrimino_list(tetrimino_t **head);

void print_tetrimino_list(tetrimino_t **head);
void print_tetrimino_shape(char **shape);
void print_prog_stats(tetrimino_t **tetrimino_list, const option_t options);

/*
** *************
** | init game |
** *************
*/

//Reads high_score file and return the found number
ssize_t get_score(void);

//Returns a allocated char ** of the options's map_size dimensions
//The allocated map has a specific style, please refer to tetris_cell_template
//Returns NULL in case of error
cell_t **create_board(dimensions_t size, cell_style_t style);

//Calls all essential initializer for game
//Returns 1 if there's no issue.
//Returns 0 otherwise.
bool init_game_data(game_data_t *game_data, option_t options);

bool init_frame_component(frame_component_t *component,
                            frame_component_t template, int data);

bool init_left_pannel(frame_t *frame, option_t options);
bool init_right_pannel(frame_t *frame,
                        __attribute__((unused))option_t options);


/*
** ******************
** | Main game Loop |
** ******************
*/

//Adds a new tetrimino in queue by allocating it
//Pushes it at the end of the queue
//Returns 1 if there's no issue.
//Returns 0 otherwise.
bool enqueue_tetrimino(tetrimino_t **queue, tetrimino_t *tetrimino);

//Remove and free first tetrimino of the queue
//Returns 1 if there's no issue.
//Returns 0 otherwise.
bool dequeue_tetrimino(tetrimino_t **queue);

//Remove and free all tetrimino of the queue
//Returns 1 if there's no issue.
//Returns 0 otherwise.
bool empty_queue(tetrimino_t **queue);

//Refresh the display str of the given structure
void update_lambda_comp(frame_component_t *component);
void update_score(game_data_t *game_data);
void update_timer(frame_component_t *frame);


/*
** ****************
** | Display func |
** ****************
*/

//Displays tetrimino with relative position to board pos
void display_tetrimino(tetrimino_t *tetrimino, pos_t board_pos, pos_t pos);

//Displays the shadow of the actual tetrimino
void display_shadow(game_data_t *game_data, tetrimino_t *queue,
                            option_t options, pos_t board_pos);

//Displays a board componed of char and color
void display_board(cell_t **board, dimensions_t size, pos_t pos);

//Displays a frame with relative position to board pos
void display_frame(frame_t frame, pos_t middle_pos, dimensions_t midde_size);

//Displays next tetrimino in the right panel
void display_next_tetrimino(tetrimino_t *queue, frame_t frame,
                            pos_t middle_pos, dimensions_t midde_size);

//Call every display functions
void display_all(game_data_t *game_data, tetrimino_t *queue,
                                            option_t options,
                                            pos_t board_pos);
//Main game function
int game(option_t options, tetrimino_t **tetrimino_list);

void parse_input(game_data_t *game_data, tetrimino_t **queue,
                                                option_t options);

/*
** **********************
** | Control Tetriminos |
** **********************
*/

void move_tetrimino(game_data_t *game_data, option_t options,
                                            tetrimino_t *tetrimino,
                                            int key_code);
void rotate_tetrimino(game_data_t *game_data, option_t options,
                                        tetrimino_t *tetrimino);
void drop_tetrimino(game_data_t *game_data, tetrimino_t **queue,
                                                option_t options);

bool update_queue(tetrimino_t **queue, tetrimino_t *tetrimino_list);

bool land_tetrimino(game_data_t *game_data, tetrimino_t **queue,
                                                option_t options);

bool tetrimino_collide(game_data_t *game_data, option_t options,
                                                char **shape, pos_t pos);

bool should_break_line(game_data_t *game_data, option_t options);

//Where the game starts looping.
//
//Returns 84 if an error occurs.
//Returns 0 otherwise.
int tetris(const int ac, char * const av[]);

/*
** ******************
** | End game func  |
** ******************
*/

void should_save_score(game_data_t game_data);

/*
** ************
** | Free'ers |
** ************
*/

bool free_frame(frame_t frame);
bool free_game_data(game_data_t game_data);

/*
** ************
** | Maths :) |
** ************
*/

int get_randomnb(int min, int max);

#endif /* !TETRIS_H_ */