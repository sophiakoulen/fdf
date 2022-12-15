/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:41:47 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/15 10:55:30 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/* some colors */
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define BLUE 0x000000FF
# define GREEN 0x0000FF00

/* boilerplate stuff for images */
typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/* basic point structure */
typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

/* puting a pixel to an image */
void	pixel_put(t_data *data, int x, int y, int color);

/* line drawing */
void	bresenhamLine(t_point p0, t_point p1, t_data *data);

/* cube drawing */
void	drawCube(int x, int y, int z, int l, t_data *data);

/* utils */
int 	abs(int x);

#endif