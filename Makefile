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
		src/operations/addition.c\

OBJ =   $(SRC:.c=.o)

CFLAGS = -I./include

CERRORS = -Wall -Wextra

all: $(NAME)
$(NAME) : $(OBJ)
		$(MAKE) -C ./lib/my/
		$(CC) $(CFLAGS) $(OBJ) -L ./lib/my -lmy -o $(NAME)

tests:
		$(MAKE) -C ./lib/my
		$(MAKE) all
		epiclang -I./include tests/*.c src/operations/addition.c -L./lib/my -lmy $(shell pkg-config --cflags --libs criterion) -o tests/run_tests
		./tests/run_tests

.PHONY: tests

clean_tests:
		rm -f tests/run_tests

clean :
		$(MAKE) clean -C ./lib/my
		rm -f $(OBJ)

fclean : clean_tests clean
		$(MAKE) fclean -C ./lib/my
		rm -f $(NAME)

re: fclean all
		rm -f $(OBJ)

