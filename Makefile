# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 10:42:00 by skoulen           #+#    #+#              #
#    Updated: 2022/12/15 13:39:35 by skoulen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

NAME = fdf

INCLUDE_PATH = -I. -Imlx
LIB_PATH = -L. -lmlx -framework OpenGL -framework AppKit -lm

SRCS = main.c \
line.c \
cube.c \
pixel_put.c \
projection.c \
utils.c

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(LIB_PATH) $(SRCS) -o $@

fclean:
	rm -f $(NAME)

re: fclean all