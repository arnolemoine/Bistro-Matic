##
## EPITECH PROJECT, 2026
## bistromatic
## File description:
## makefile
##

NAME = 	calc
SRC = 	main.c\

OBJ = 	$(SRC:.c=.o)
CC = 	epiclang
CFLAGS = -I./include/

all: $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re: fclean all
	rm -f $(OBJ)