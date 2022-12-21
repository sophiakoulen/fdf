/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:41:47 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/21 14:34:27 by skoulen          ###   ########.fr       */
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
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>

/* title of the window */
# define TITLE "fdf"

# define START_CLR 0x00845ec2
# define END_CLR 0x00f9f871
# define BACKGROUND  0x00263238 

/* window width and height */
# define WIDTH 1600
# define HEIGHT 1000

/* projection types */
# define ORTHOGRAPHIC 0
# define PERSPECTIVE 1

/* isometric angles in radians */
# define DEFAULT_ALPHA 0.610865238
# define DEFAULT_BETA 0.785398

/* events */
# define EVENT_CLOSE 17
# define EVENT_KEYDOWN 2

/* key_codes */
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 124
# define RIGHT 123

/* boilerplate stuff for images */
typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}	t_img_data;

typedef struct s_vector2
{
	int	x;
	int	y;
}	t_vector2;

typedef struct s_vector3
{
	long long int	x;
	long long int	y;
	long long int	z;
}	t_vector3;

typedef struct s_camera
{
	int			zoom;
	int			projection;
	t_vector3	position;
	float		**alpha;
	float		**beta;
	float		scale;
}	t_camera;

typedef struct s_map
{
	int	**map;
	int	rows;
	int	cols;
}	t_map;

typedef struct s_param
{
	void		*mlx;
	void		*window;
	t_img_data	*img;
	t_camera	*camera;
	t_map		*map;
	int			max;
	int			min;
}	t_param;

typedef struct s_line3d
{
	t_vector3	p0;
	t_vector3	p1;
	int			clr0;
	int			clr1;
}	t_line3d;

typedef struct s_line2d
{
	t_vector2	p0;
	t_vector2	p1;
	int			clr0;
	int			clr1;
}	t_line2d;

void		clean_exit(t_param *param, int status);

/* parsing */
int			parse_map(char *filename, t_map *map);

/* parsing utils */
void		cleanup_map(t_map *map);
void		cleanup_strs(char **strs);
int			get_line_count(int fd);

/* param */
void		set_param(t_param *param, t_map *map);
void		cleanup_param(t_param *param);

/* do rendering */
void		retrieve_limits(t_param *param);
void		do_rendering(t_map *map);

/* draw terrain */
t_vector3	get_coordinate(t_map *map, int i, int j);
void		draw_terrain(t_map *map, t_param *param, t_img_data *img);

/* puting a pixel to an image */
void		pixel_put(t_img_data *data, int x, int y, int color);

/* plot */
void		draw_line3d(t_line3d line3, t_param *param, t_img_data *img);

/* line drawing */
void		bresenham_line(t_line2d line, t_img_data *data);

/* projection */
t_vector2	project(t_vector3 point, t_camera *camera);
void		compute_alpha_matrix(float alpha, float **m);
void		compute_beta_matrix(float beta, float **m);

/* utils */
int			abs(int x);
float		distance(t_vector2 p0, t_vector2 p1);

/* event handlers */
int			handle_close(void *param);
int			handle_keydown(int code, void *param);

/* camera */
t_camera	*new_camera(void);
void		destroy_camera(t_camera *camera);

/* adjust scale */
void		adjust_scale(t_param *param);

/* render.c */
void		render(t_param *param);

/* matrix utils */
void		cleanup_matrix(float **matrix);
float		**init_matrix(void);
t_vector3	mult(float **matrix, t_vector3 a);

/* color */
int			rgb(int r, int g, int b);
int			get_r(int clr);
int			get_g(int clr);
int			get_b(int clr);

int			color_lerp(int str_clr, int end_clr, float ratio);
int			color_lerp_line(t_line2d line, t_vector2 curr);

#endif