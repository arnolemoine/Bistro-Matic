##
## EPITECH PROJECT, 2026
## bistromatic
## File description:
## makefile
##

# -- Couleurs
END     = \033[0m
BOLD    = \033[1m
CYAN    = \033[1;36m
GREEN   = \033[1;32m
PURPLE  = \033[1;35m
YELLOW  = \033[1;33m
GREY    = \033[90m

CC =	epiclang

NAME =	calc

SRC =	src/check/check_base.c \
		src/check/check_ops.c \
		src/compute/compute_add.c \
		src/compute/compute_mul.c \
		src/compute/compute_sub.c \
		src/conversion/convert_base.c \
		src/do_op/do_add.c \
		src/do_op/do_op.c \
		src/do_op/do_sub.c \
		src/expressions/eval_expr.c \
		src/expressions/translate_expr.c \
		src/infinite/compare_infinites.c \
		src/infinite/infinite_add.c \
		src/infinite/infinite_mult.c \
		src/infinite/infinite_sub.c \
		src/infinite/infinite_utils.c \
		src/parser/parser.c \
		src/parser/parser_utils.c \
		src/helper.c \
		src/main.c

OBJ =   $(SRC:.c=.o)
CFLAGS = -I./include/

SRC_NO_MAIN = $(filter-out src/main.c, $(SRC))

CRIT_FLAGS =	-lcriterion --coverage
TESTS_SRC =		tests/test_bistromatic.c
TESTS_BIN =		unit_tests

all: $(NAME)

$(NAME): compile_lib $(OBJ)
	$(CC) $(OBJ) -L./lib/my -lmy -o $(NAME)

compile_lib:
	@make -C ./lib/my/

tests_run:
	gcc $(SRC_NO_MAIN) $(TESTS_SRC) $(CFLAGS) $(CRIT_FLAGS) -L ./lib/my -lmy -o $(TESTS_BIN)
	./$(TESTS_BIN) --quiet || true
	@gcovr -r . --exclude tests/ --exclude include/

clean :
	rm -f $(OBJ)
	rm -f test
	make clean -C ./lib/my/

fclean : fclean_tests clean
	rm -f $(NAME)
	make fclean -C ./lib/my/

fclean_tests: fclean
	rm -f $(TESTS_BIN)
	rm -f *.gcda *.gcno
	rm -f src/**/*.gcda src/**/*.gcno

re: fclean all
	rm -f $(OBJ)
