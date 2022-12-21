# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 10:42:00 by skoulen           #+#    #+#              #
#    Updated: 2022/12/21 14:44:05 by skoulen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = fdf

LIBFT = libft/libft.a
LIBGNL = libgnl/libgnl.a
LIBMLX = mlx/libmlx.a

INCLUDE_PATHS = -I. -Ilibft -Ilibgnl
LIB_PATHS = -Llibft -Llibgnl
LIBS = -lm -lft -lgnl
MLX_MAC = -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit

CFLAGS += $(INCLUDE_PATHS) $(LIB_PATHS) $(LIBS) $(MLX_MAC)

SRCS = $(addprefix srcs/, main.c \
line.c \
pixel_put.c \
projection.c \
utils.c \
event_handlers.c \
render.c \
matrix.c \
camera.c \
do_rendering.c \
draw_terrain.c \
line3d.c \
color.c \
lerp.c \
rotation_matrices.c \
param.c \
adjust_scale.c \
parsing.c \
parsing_utils.c)


ifdef DEBUG
	CFLAGS += -g3 -fsanitize=address
endif

all: $(NAME)

$(LIBFT):
	make -C libft

$(LIBGNL):
	make -C libgnl

$(LIBMLX):
	make -C mlx

$(NAME): $(SRCS) $(LIBFT) $(LIBGNL) $(LIBMLX)
	$(CC) $(CFLAGS) $(SRCS) -o $@

clean:
	make clean -C libft
	make clean -C libgnl
	make clean -C mlx

fclean:
	rm -f $(NAME)
	rm -f $(LIBMLX)
	make fclean -C libft
	make fclean -C libgnl

re: fclean all