/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_terrain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:18:18 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/20 15:05:33 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector3	get_coordinate(t_map *map, int i, int j)
{
	t_vector3	res;

	res.x = (j - map->cols/2) * 20;
	res.y = map->map[i][j] * 10;
	res.z = (i - map->rows/2) * 20;
	return (res);
}

void	draw_row(t_map *map, int row, t_param *param, t_img_data *img)
{
	int			i;
	t_vector3	p0;
	t_vector3	p1;
	int 		y1;
	int			y2;
	int			clr1;
	int			clr2;

	i = 0;
	while (i < map->cols - 1)
	{
		p0 = get_coordinate(map, row, i);
		p1 = get_coordinate(map, row, i+1);
		y1 = map->map[row][i];
		y2 = map->map[row][i + 1];
		clr1 = color_lerp(START_CLR, END_CLR, (float)y1 / (float)param->max);
		clr2 = color_lerp(START_CLR, END_CLR, (float)y2 / (float)param->max);
		plot_line(p0, p1, clr1, clr2, param, img);
		i++;
	}
}

void	draw_col(t_map *map, int col, t_param *param, t_img_data *img)
{
	int			i;
	t_vector3	p0;
	t_vector3	p1;
	int			y1;
	int			y2;
	int			clr1;
	int			clr2;

	i = 0;
	while (i < map->rows - 1)
	{
		p0 = get_coordinate(map, i, col);
		p1 = get_coordinate(map, i + 1, col);
		y1 = map->map[i][col];
		y2 = map->map[i + 1][col];
		clr1 = color_lerp(START_CLR, END_CLR, (float)y1 / (float)param->max);
		clr2 = color_lerp(START_CLR, END_CLR, (float)y2 / (float)param->max);
		//printf("%X %X %f %f\n", clr1, clr2, (float)y1 / (float)param->max, (float)y2 / (float)param->max);
		plot_line(p0, p1, clr1, clr2, param, img);
		i++;
	}
}

void	draw_terrain(t_map *map, t_param *param, t_img_data *img)
{
	int			i;

	i = 0;
	while (i < map->rows)
	{
		draw_row(map, i, param, img);
		i++;
	}
	i = 0;
	while (i < map->cols)
	{
		draw_col(map, i, param, img);
		i++;
	}
}
