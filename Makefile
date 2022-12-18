# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 10:42:00 by skoulen           #+#    #+#              #
#    Updated: 2022/12/18 13:24:47 by skoulen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = fdf

LIBFT = libft/libft.a
LIBGNL = libgnl/libgnl.a

INCLUDE_PATHS = -I. -Ilibft -Ilibgnl
LIB_PATHS = -Llibft -Llibgnl
LIBS = -lm -lft -lgnl
MLX_MAC = -Imlx -L. -lmlx -framework OpenGL -framework AppKit

CFLAGS += $(INCLUDE_PATHS) $(LIB_PATHS) $(LIBS) $(MLX_MAC)

RENDERING = line.c \
cube.c \
pixel_put.c \
projection.c \
utils.c \
event_handlers.c \
render.c \
matrix.c \
camera.c \
do_rendering.c

PARSING = parsing.c

SRCS = main.c $(addprefix rendering/, $(RENDERING)) $(addprefix parsing/, $(PARSING))

all: $(NAME)

$(LIBFT):
	make -C libft

$(LIBGNL):
	make -C libgnl

$(NAME): $(SRCS) $(LIBFT) $(LIBGNL)
	$(CC) $(CFLAGS) $(SRCS) -o $@

fclean:
	rm -f $(NAME)

re: fclean all