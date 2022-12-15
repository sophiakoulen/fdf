/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:41:47 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/15 16:01:13 by skoulen          ###   ########.fr       */
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

/* window width and height */
#define WIDTH 300
#define HEIGHT 300

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

typedef struct	s_vector2
{
	int	x;
	int y;
}	t_vector2;

typedef struct	s_vector3
{
	int	x;
	int	y;
	int	z;
}	t_vector3;

typedef struct s_camera
{
	int			zoom;
	t_vector3	position;
}	t_camera;

/* puting a pixel to an image */
void	pixel_put(t_data *data, int x, int y, int color);

/* line drawing */
void	bresenhamLine(t_vector2 p0, t_vector2 p1, t_data *data);

/* projection */
t_vector2	project_perspective(t_vector3 object, t_camera camera);

/* cube drawing */
void	drawCube(t_vector3 pos, int size, t_camera camera, t_data *data);

/* utils */
int 	abs(int x);

#endif