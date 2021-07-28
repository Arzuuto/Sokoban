##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME 		=	my_sokoban

SRC 		=	sources/box.c	\
				sources/check_lose.c	\
				sources/error_handling.c	\
				sources/file_to_tab.c	\
				sources/move.c	\
				sources/my_sokoban.c	\
				sources/obstacle.c	\
				sources/update_game.c	\

OBJ 		=	$(SRC:.c=.o)

RM		=	rm -f

LIB 		=	-L lib/my -l my

MLIB		=	-C lib/my

CC		=	gcc

SAFE		=	-W -Wall -Werror

CPPFLAGS	=	-I include/ -g3 -lncurses

TEST_NAME	=	unit_tests

CRITERION =	-lcriterion --coverage

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) $(MLIB)
	$(CC) -o $(NAME) sources/main.c $(OBJ) $(LIB) $(CPPFLAGS)

tests_run:
	gcc -o $(TEST_NAME) $(SRC) tests/test_sokoban.c $(LIB) $(CPPFLAGS) $(CRITERION)
	-./$(TEST_NAME)

clean:
	$(RM) lib/my/*.o
	$(RM) lib/*.a
	$(RM) lib/my/*.a
	$(RM) $(OBJ)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.html

fclean:	clean
	$(RM) $(NAME)

re:	fclean all tests_run

.PHONY: all tests_run clean fclean
