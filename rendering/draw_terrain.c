/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_terrain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:18:18 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/19 11:43:28 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_row(t_map *map, int row, t_camera *camera, t_img_data *img)
{
	int			i;
	t_vector3	p0;
	t_vector3	p1;

	i = 0;
	while (i < map->cols - 1)
	{
		p0 = (t_vector3){i * 10, map->map[row][i] * 5, row * 10};
		p1 = (t_vector3){(i + 1) * 10, map->map[row][i + 1] * 5, row * 10};
		plot_line(p0, p1, camera, img);
		i++;
	}
}

void	draw_col(t_map *map, int col, t_camera *camera, t_img_data *img)
{
	int			i;
	t_vector3	p0;
	t_vector3	p1;

	i = 0;
	while (i < map->rows - 1)
	{
		p0 = (t_vector3){col * 10, map->map[i][col] * 5, i * 10};
		p1 = (t_vector3){col * 10, map->map[i + 1][col] * 5, (i + 1) * 10};
		plot_line(p0, p1, camera, img);
		i++;
	}
}

void	draw_terrain(t_map *map, t_camera *camera, t_img_data *img)
{
	int			i;

	i = 0;
	while (i < map->rows)
	{
		draw_row(map, i, camera, img);
		i++;
	}
	i = 0;
	while (i < map->cols)
	{
		draw_col(map, i, camera, img);
		i++;
	}
}
