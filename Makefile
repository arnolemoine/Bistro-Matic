##
## EPITECH PROJECT, 2026
## bistromatic
## File description:
## makefile
##

CC =    epiclang

NAME =  calc

SRC =   src/main.c\
		src/check/check_base.c\
		src/check/check_ops.c\
		src/helper.c\
		src/parser/parser.c\

OBJ =   $(SRC:.c=.o)

CFLAGS = -I./include

CERRORS = -Wall -Wextra

all: $(NAME)

$(NAME) : $(OBJ)
		$(MAKE) -C ./lib/my/
		$(CC) $(CFLAGS) $(OBJ) -L ./lib/my -lmy -o $(NAME)

clean :
		$(MAKE) clean -C ./lib/my
		rm -f $(OBJ)

fclean : clean
		$(MAKE) fclean -C ./lib/my
		rm -f $(NAME)

re: fclean all
		rm -f $(OBJ)
