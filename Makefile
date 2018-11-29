##
## EPITECH PROJECT, 2018
## MUL_my_hunter_2018
## File description:
## The Makefile of the my_hunter project
##

NAME = my_hunter

SRC =	my_hunter.c

CFLAGS = -Iinclude

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -lcsfml-audio -lcsfml-graphics -lcsfml-system -lcsfml-window

clean:
	rm -f $(OBJ)

fclean:	clean
	rm $(NAME)

re: fclean all
