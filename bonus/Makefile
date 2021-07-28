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

CPPFLAGS	=	-I include/ -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) $(MLIB)
	$(CC) -o $(NAME) sources/main.c $(OBJ) $(LIB) $(CPPFLAGS) -lncurses

clean:
	$(RM) lib/my/*.o
	$(RM) lib/*.a
	$(RM) lib/my/*.a
	$(RM) $(OBJ)
	$(RM) *.html
	$(RM) sources/*.o
	$(RM) *.o
	$(RM) *~

fclean:	clean
	$(RM) $(NAME)
	$(RM) *.gcda
	$(RM) *.gcno

re:	fclean all clean
