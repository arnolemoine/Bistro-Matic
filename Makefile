##
## EPITECH PROJECT, 2026
## hangman
## File description:
## makefile
##

NAME =  calc
SRC =   main.c\

OBJ =   $(SRC:.c=.o)
CC =    epiclang
CFLAGS = -I./include/

all: $(NAME)

$(NAME) : $(OBJ)
		make -C ./lib/my/
		$(CC) $(CFLAGS) $(OBJ) -Llib/my -lmy -o $(NAME)

clean :
		rm -f $(OBJ)
		make clean -C ./lib/my/

fclean : clean
		rm -f $(NAME)
		make fclean -C ./lib/my/

re: fclean all
		rm -f $(OBJ)