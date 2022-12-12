CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = fdf

INCLUDE_PATH = -I. -Imlx
LIB_PATH = -L. -lmlx -framework OpenGL -framework AppKit

SRCS = main.c

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(LIB_PATH) $(SRCS) -o $@

fclean:
	rm -f $(NAME)

re: fclean all