# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 10:42:00 by skoulen           #+#    #+#              #
#    Updated: 2022/12/18 10:30:26 by skoulen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = fdf

INCLUDE_PATH = -I. -Imlx -Ilibft
LIB_PATH = -L. -lmlx -framework OpenGL -framework AppKit -lm -Llibft -lft

SRCS = main.c \
line.c \
cube.c \
pixel_put.c \
projection.c \
utils.c \
event_handlers.c \
render.c \
matrix.c \
camera.c

LIBFT = libft/libft.a

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(LIB_PATH) $(SRCS) -o $@

fclean:
	rm -f $(NAME)

re: fclean all