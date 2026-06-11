##
## EPITECH PROJECT, 2026
## bistromatic
## File description:
## makefile
##

NAME =  calc
SRC =   src/check/check_base.c \
		src/check/check_ops.c \
		src/compute/compute_add.c \
		src/conversion/convert_base.c \
		src/expressions/eval_expr.c \
		src/expressions/translate_expr.c \
		src/infinite/infinite_add.c \
		src/helper.c \
		src/main.c \
		src/infinite/compare_infinites.c \
		src/parser_utils.c \

OBJ =   $(SRC:.c=.o)
CC =    epiclang
CFLAGS = -I./include/

all: $(NAME)

$(NAME) : $(OBJ)
		make -C ./lib/my/
		$(CC) $(CFLAGS) $(OBJ) -Llib/my -lmy -o $(NAME)

tests:
		$(MAKE) -C ./lib/my
		$(MAKE) all
		epiclang -I./include tests/*.c src/operations/addition.c -L./lib/my -lmy $(shell pkg-config --cflags --libs criterion) -o tests/run_tests
		./tests/run_tests

.PHONY: tests

clean_tests:
		rm -f tests/run_tests

clean :
		rm -f $(OBJ)
		rm -f test
		make clean -C ./lib/my/

fclean : clean_tests clean
		rm -f $(NAME)
		make fclean -C ./lib/my/

re: fclean all
		rm -f $(OBJ)