# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 10:42:00 by skoulen           #+#    #+#              #
#    Updated: 2022/12/16 12:09:48 by skoulen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = fdf

INCLUDE_PATH = -I. -Imlx
LIB_PATH = -L. -lmlx -framework OpenGL -framework AppKit -lm

SRCS = main.c \
line.c \
cube.c \
pixel_put.c \
projection.c \
utils.c \
event_handlers.c \
render.c

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDE_PATH) $(LIB_PATH) $(SRCS) -o $@

fclean:
	rm -f $(NAME)

re: fclean all