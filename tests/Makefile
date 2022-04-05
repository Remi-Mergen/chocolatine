##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make file for test run
##

CC      	=	gcc

SRC     	=	../src/get_map_tool.c				\
				../src/auxiliary_coding_style.c		\
				../src/start_bsq.c					\
				../src/bsq.c						\
				test_bsq.c							\

OBJ			=	$(SRC:.c=.o)

NAME		=	unit_tests

CPPFLAGS	=	-I./../include/

CFLAGS		=	--coverage

LDFLAGS		=	-L./../lib/

LDLIBS		=	-lmy -lcriterion -lg


all:			fclean $(NAME)
				./$(NAME)

$(NAME):		$(OBJ)
				$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS) $(CFLAGS) -lcriterion -lgcov

clean:
				rm -f $(OBJ)
				rm -f *.gc*
				rm -f ../src/*.gc*

fclean: 		clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			$(NAME) all clean fclean re
