##
## EPITECH PROJECT, 2022
## chocolatine
## File description:
## Makefile
##

NAME = binary

all:
	gcc -o $(NAME) usefull.c

clean:
	rm *.o
