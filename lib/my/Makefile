##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rtfm
##

SRC	=	my_strcat.c	\
		my_strncat.c	\
		my_putchar.c	\
		my_strcmp.c	\
		my_strncmp.c	\
		my_put_nbr.c	\
		my_strcpy.c	\
		my_strncpy.c	\
		my_compute_power_rec.c	\
		my_putstr.c	\
		my_str_isalpha.c	\
		my_strstr.c	\
		my_compute_square_root.c	\
		my_revstr.c	\
		my_str_islower.c	\
		my_str_to_word_array.c	\
		my_find_prime_sup.c	\
		my_showmem.c	\
		my_str_isnum.c			\
		my_strupcase.c	\
		my_get_nbr.c	\
		my_showstr.c	\
		my_str_isprintable.c	\
		my_swap.c	\
		my_show_word_array.c	\
		my_str_isupper.c	\
		my_isneg.c	\
		my_strlen.c	\
		my_is_prime.c	\
		my_strcapitalize.c	\
		my_strlowcase.c	\
		my_intlen.c	\
		my_sort_int_array.c	\
		my_strcpaddress.c	\
		my_memset.c	\
		my_strdup.c	\
		my_put_nbr.c	\
		my_put_char.c	\
		my_put_uchar.c	\
		my_put_short.c	\
		my_put_ushort.c	\
		my_put_int.c	\
		my_put_uint.c	\
		my_put_long.c	\
		my_put_ulong.c	\
		my_put_long_long.c	\
		my_put_ulong_long.c	\
		my_put_address.c


OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

NAME_MY_H =	my.h

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ./../$(NAME)
	chmod 775 ./../$(NAME) $(NAME)
	cp ./my.h ./../../include/$(NAME_MY_H)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../../include/$(NAME_MY_H)
	rm -f ../$(NAME)
	rm -f $(NAME)

re:	fclean all

.PHONY:	$(NAME) all clean fclean
