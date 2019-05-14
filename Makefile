##
## EPITECH PROJECT, 2018
## MUL_my_hunter_2018
## File description:
## The Makefile of the my_hunter project
##

NAME = my_hunter

SRC =	src/main.c \
		src/my_hunter.c \
		src/assets.c

CFLAGS = -Iinclude -Wall -Wextra -Iinclude

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -lcsfml-audio -lcsfml-graphics -lcsfml-system -lcsfml-window -Llib/my -lmy

clean:
	rm -f $(OBJ)

fclean:	clean
	rm $(NAME)
	make -C lib/my fclean

re: fclean all
