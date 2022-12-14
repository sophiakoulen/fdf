/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_terrain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:18:18 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/20 17:56:24 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector3	get_coordinate(t_map *map, int i, int j)
{
	t_vector3	res;

	res.x = (j - map->cols / 2) * 20;
	res.y = map->map[i][j] * 10;
	res.z = (i - map->rows / 2) * 20;
	return (res);
}

float	get_ratio(t_map *map, int i, int j, t_param *param)
{
	float	value;
	float	range;

	value = map->map[i][j] - param->min;
	range = param->max - param->min;
	return (value / range);
}

void	draw_row(t_map *map, int row, t_param *param, t_img_data *img)
{
	int			i;
	float		ratio0;
	float		ratio1;
	t_line3d	line;

	i = 0;
	while (i < map->cols - 1)
	{
		line.p0 = get_coordinate(map, row, i);
		line.p1 = get_coordinate(map, row, i + 1);
		ratio0 = get_ratio(map, row, i, param);
		ratio1 = get_ratio(map, row, i + 1, param);
		line.clr0 = color_lerp(START_CLR, END_CLR, ratio0);
		line.clr1 = color_lerp(START_CLR, END_CLR, ratio1);
		draw_line3d(line, param, img);
		i++;
	}
}

void	draw_col(t_map *map, int col, t_param *param, t_img_data *img)
{
	int			i;
	float		ratio0;
	float		ratio1;
	t_line3d	line;

	i = 0;
	while (i < map->rows - 1)
	{
		line.p0 = get_coordinate(map, i, col);
		line.p1 = get_coordinate(map, i + 1, col);
		ratio0 = get_ratio(map, i, col, param);
		ratio1 = get_ratio(map, i + 1, col, param);
		line.clr0 = color_lerp(START_CLR, END_CLR, ratio0);
		line.clr1 = color_lerp(START_CLR, END_CLR, ratio1);
		draw_line3d(line, param, img);
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
