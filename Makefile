##
## EPITECH PROJECT, 2022
## chocolatine
## File description:
## Makefile
##

SRC = usefull.c

OBJ = $(SRC:.c=.o)

NAME = binary

all:    $(OBJ)  $(NAME)

$(NAME): $(OBJ)
        gcc -o $(NAME) $(OBJ)

clean:
        rm -f $(OBJ)
