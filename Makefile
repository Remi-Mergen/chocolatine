##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rtfm
##

CC			=	gcc

SRC			=	print.c

OBJ			=	$(SRC:.c=.o)

NAME		=	binary

$(NAME):	 $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all:	$(NAME)

tests_run:
	make -C tests/

clean:
	rm -f $(OBJ)

coverage:
	@gcovr

fclean: clean
	rm -f $(NAME)
	make fclean -C ./tests

re:	fclean all

.PHONY:	$(NAME) all clean fclean
