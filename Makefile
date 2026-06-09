##
## EPITECH PROJECT, 2026
## bistromatic
## File description:
## makefile
##

NAME =  calc
SRC =   src/main.c\
		src/check/check_base.c\
		src/check/check_ops.c\
		src/helper.c\

OBJ =   $(SRC:.c=.o)
CC =    epiclang
CFLAGS = -I./include/

TEST_FLAGS = $(shell pkg-config --cflags --libs criterion)

test: test.c
	$(CC) $(CFLAGS) test.c -o test $(TEST_FLAGS)
	./test

all: $(NAME)

$(NAME) : $(OBJ)
		make -C ./lib/my/
		$(CC) $(CFLAGS) $(OBJ) -Llib/my -lmy -o $(NAME)

clean :
		rm -f $(OBJ)
		rm -f test
		make clean -C ./lib/my/

fclean : clean
		rm -f $(NAME)
		make fclean -C ./lib/my/

re: fclean all
		rm -f $(OBJ)