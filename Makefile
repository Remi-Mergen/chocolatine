##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile compilation-handler for tetris program.
##

MAIN				=	src/main.c										\

SRC					=	src/tetris.c									\
						src/debug_mode/get_tetriminos_nb.c				\
						src/debug_mode/print_prog_stats.c				\
						src/debug_mode/print_tetrimino_shape.c			\
						src/debug_mode/print_tetrimino_list.c			\
						src/debug_mode/is_tetri_list_sorted.c			\
						src/debug_mode/sort_tetrimino_list.c			\
						src/freeer/free_frame.c							\
						src/freeer/free_game_data.c						\
						src/game_handling/break_line.c					\
						src/game_handling/display_all.c					\
						src/game_handling/display_board.c				\
						src/game_handling/display_frame.c				\
						src/game_handling/display_shadow.c				\
						src/game_handling/display_tetrimino.c			\
						src/game_handling/run_game.c					\
						src/game_handling/update_lambda_comp.c			\
						src/game_handling/update_queue.c				\
						src/game_handling/update_score.c				\
						src/game_handling/update_timer.c				\
						src/initialize/init_frame.c						\
						src/initialize/init_game_board.c				\
						src/initialize/init_game_data.c					\
						src/initialize/init_left_panel.c				\
						src/initialize/init_right_panel.c				\
						src/input_handling/parse_input.c				\
						src/option_handling/parse_options.c				\
						src/option_handling/set_options.c				\
						src/queue_handling/dequeue.c					\
						src/queue_handling/empty_queue.c				\
						src/queue_handling/enqueue.c					\
						src/score_handling/save_score.c					\
						src/template/tetris_frame_template.c			\
						src/tetrimino_control/land_tetrimino.c			\
						src/tetrimino_control/tetrimino_collide.c		\
						src/tetrimino_control/tetrimino_interact.c		\
						src/tetriminos_handling/file_extension_determ.c	\
						src/tetriminos_handling/free_tetriminos_list.c	\
						src/tetriminos_handling/get_blank_tetrimino.c	\
						src/tetriminos_handling/get_tetrimino_height.c	\
						src/tetriminos_handling/get_tetriminos.c		\
						src/tetriminos_handling/read_tetriminos_dir.c	\
						src/tetriminos_handling/rotate_tetrimino.c		\
						src/tetriminos_handling/tetriminos_utils.c		\
						src/tetriminos_handling/fill_tetri_shape.c		\

SRC_TESTS			=	tests/test_file_extension_determ.c				\
						tests/test_is_list_sorted.c						\

SRC_LIBTESTS		=	tests/tests_libmy/test_my_strdup_lowercase.c	\

OBJ					=	$(MAIN:.c=.o) $(SRC:.c=.o)

NAME 				=	tetris

override CFLAGS		+=	-W -Wall -Wextra

override CPPFLAGS	+=	-I./include/

override LDFLAGS	+=	-L./lib/

override LDLIBS		+= 	-lmy -lncurses

LIB 				=	lib/libmy.a

all:					$(NAME)

$(NAME):				$(LIB) $(OBJ)
						$(LINK.o) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

$(LIB):
						$(MAKE) -C ./lib/my

debug:					CPPFLAGS += -g
debug:					clean $(LIB) $(OBJ)
						$(CC) -o $@ $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

tests_run:				LDLIBS += -lcriterion --coverage
tests_run:				CFLAGS += --coverage
tests_run:				$(LIB)
						$(CC) -o $@ $(SRC) tests/*.c $(SRC_LIBTESTS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
						./$@
						mv *.gc* tests/
						$(RM) $@

coverage:
						gcovr --exclude tests/
						gcovr --exclude tests/ --branches

clean:
						$(RM) $(OBJ)
						$(MAKE) -C lib/my clean

fclean:
						$(RM) $(NAME)
						$(RM) debug
						$(RM) tests_run
						$(RM) $(OBJ)
						find . -type f -name '*.gcno' -exec rm {} +
						find . -type f -name '*.gcda' -exec rm {} +
						find . -type f -name 'vgcore.*' -exec rm {} +
						$(MAKE) -C lib/my fclean

re:			 			fclean all

.NOTPARALLEL:
.PHONY:					debug all clean fclean re tests_run
