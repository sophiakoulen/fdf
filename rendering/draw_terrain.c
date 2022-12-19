/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_terrain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:18:18 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/19 13:37:41 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_row(t_map *map, int row, t_param *param, t_img_data *img)
{
	int			i;
	t_vector3	p0;
	t_vector3	p1;

	i = 0;
	while (i < map->cols - 1)
	{
		p0 = (t_vector3){i * 20, map->map[row][i] * 10, row * 20};
		p1 = (t_vector3){(i + 1) * 20, map->map[row][i + 1] * 10, row * 20};
		draw_line(p0, p1, param, img);
		i++;
	}
}

void	draw_col(t_map *map, int col, t_param *param, t_img_data *img)
{
	int			i;
	t_vector3	p0;
	t_vector3	p1;

	i = 0;
	while (i < map->rows - 1)
	{
		p0 = (t_vector3){col * 20, map->map[i][col] * 10, i * 20};
		p1 = (t_vector3){col * 20, map->map[i + 1][col] * 10, (i + 1) * 20};
		draw_line(p0, p1, param, img);
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
