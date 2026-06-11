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

OBJ =	$(SRC:.c=.o)

CFLAGS = -I./include

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n"
	@echo "$(CYAN)** Compiling lib **:"
	@echo "\n"
	$(MAKE) -C ./lib/my/
	$(CC) $(CFLAGS) $(OBJ) -L ./lib/my -lmy -o $(NAME)
	@echo "$(END)"

clean:
	@echo "$(YELLOW)** Cleaning Objects **:"
	@echo "\n"
	$(MAKE) clean -C ./lib/my
	rm -f $(OBJ)
	@echo "$(END)"

fclean: clean
	@echo "$(GREEN)** Removing Library and binary **:"
	@echo "\n"
	$(MAKE) fclean -C ./lib/my
	rm -f $(NAME)
	@echo "$(END)"

re: fclean all
	rm -f $(OBJ)