/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:41:47 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/19 11:47:12 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

/* title of the window */
#define TITLE "fdf"

/* some colors */
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define BLUE 0x000000FF
# define GREEN 0x0000FF00

/* window width and height */
#define WIDTH 800
#define HEIGHT 450

/* projection types */
#define ORTHOGRAPHIC 0
#define PERSPECTIVE 1

/* isometric angles in radians */
#define DEFAULT_ALPHA 0.610865238
#define DEFAULT_BETA 0.785398

/* boilerplate stuff for images */
typedef struct	s_img_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}	t_img_data;

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

typedef float t_matrix3x1[3];

typedef t_matrix3x1 t_matrix3x3[3];

typedef struct s_camera
{
	int			zoom;
	int			projection;
	t_vector3	position;
	float		**alpha; //alpha rotation matrix
	float		**beta; //beta rotation matrix
}	t_camera;

typedef struct	s_cube
{
	t_vector3	position;
	int			size;
}	t_cube;

typedef struct s_map
{
	int	**map;
	int rows;
	int cols;
}	t_map;

typedef struct s_param
{
	void		*mlx;
	void		*window;
	t_camera	*camera;
	t_cube		*cube;
	t_map		*map;
}	t_param;

/* parsing */
int		**parse_map(char *filename, int *rows, int *cols);

/* parsing utils */
void	cleanup_map(int **map);
void	cleanup_strs(char **strs);
int		get_line_count(int fd);

/* do rendering */
void	do_rendering(t_map *map);

/* draw terrain */
void	draw_terrain(t_map *map, t_camera *camera, t_img_data *img);

/* puting a pixel to an image */
void	pixel_put(t_img_data *data, int x, int y, int color);

/* plot */
void	plot_point(t_vector3 point, t_camera *camera, t_img_data *img);
void	plot_line(t_vector3 p0, t_vector3 p1, t_camera *camera, t_img_data *img);

/* line drawing */
void	bresenham_line(t_vector2 p0, t_vector2 p1, int color, t_img_data *data);

void		draw_line(t_vector3 p0, t_vector3 p1, t_camera *cam, t_img_data *img);
t_vector3	midpoint(t_vector3 p0, t_vector3 p1);

/* projection */
t_vector2	project(t_vector3 point, t_camera *camera);
void		compute_alpha_matrix(float alpha, float **m);
void		compute_beta_matrix(float beta, float **m);

/* cube drawing */
void	draw_cube(t_vector3 pos, int size, t_camera *camera, t_img_data *data);

/* utils */
int 	abs(int x);

/* event handlers */
int		handle_close(void *param);
int		handle_keydown(int code, void *param);

/* camera */
void	init_camera(t_camera *camera);
void	cleanup_camera(t_camera *camera);

/* render.c */
void	render(t_param *param);

/* matrix utils */
void		cleanup_matrix(float **matrix);
float		**init_matrix(void);
t_vector3	mult(float **matrix, t_vector3 a);

/* color */
int	compute_color(t_vector3 p);

#endif