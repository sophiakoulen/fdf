# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 10:42:00 by skoulen           #+#    #+#              #
#    Updated: 2022/12/20 16:39:17 by skoulen          ###   ########.fr        #
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
pixel_put.c \
projection.c \
utils.c \
event_handlers.c \
render.c \
matrix.c \
camera.c \
do_rendering.c \
draw_terrain.c \
plot.c \
color.c \
lerp.c \
rotation_matrices.c

PARSING = parsing.c parsing_utils.c

SRCS = main.c $(addprefix rendering/, $(RENDERING)) $(addprefix parsing/, $(PARSING))

ifdef DEBUG
	CFLAGS += -g -fsanitize=address
endif

all: $(NAME)

$(LIBFT):
	make -C libft

$(LIBGNL):
	make -C libgnl

$(NAME): $(SRCS) $(LIBFT) $(LIBGNL)
	$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	make clean -C libft
	make clean -C libgnl

fclean:
	rm -f $(NAME)
	make fclean -C libft
	make fclean -C libgnl

re: fclean all