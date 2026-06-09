##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile for bistromatic
##

NAME = libmy.a
SRC = 	my_putchar.c\
        my_strcat.c\
        my_strcmp.c\
        my_strcpy.c\
        my_strlen.c\
        my_strdup.c\
        my_putstr.c\
        my_recover_nbr.c\
        my_str_to_word_array.c\
	get_nb_r.c\
	my_getnbr.c\
	my_strncpy.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h bistromatic.h ../../include/

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all
