##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=	src/my_get.c \
		src/my_bird.c \
		src/my_window_draw.c \
		src/my_window_event.c \
		src/my_window_gui.c \
		src/my_window.c \
		src/my_put.c \
		src/my_utils.c \
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

all:	$(NAME)

$(NAME):
	gcc $(SRC) -Wall -Wextra -lc_graph_prog -I include -o $(NAME) -g

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
