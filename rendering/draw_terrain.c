/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_terrain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:18:18 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/18 15:28:08 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_terrain(t_map *map, t_camera *camera, t_img_data *img)
{
	t_square	s;
	int			i;
	int			j;

	while (i < map->rows - 1)
	{
		while (j < map->cols - 1)
		{

			s.top_left = (t_vector3){j * 10, map->map[i][j] * 10, i * 10};
			s.top_right = (t_vector3){(j + 1) * 10, map->map[i][j + 1] * 2, i * 10};
			s.bottom_left = (t_vector3){j * 10, map->map[i + 1][j] * 2, (i + 1) * 10};
			s.bottom_right = (t_vector3){(j + 1) * 10, map->map[i + 1][j + 1] * 2, (i + 1) * 10};
			plot_line(s.top_left, s.top_right, WHITE, camera, img);
			plot_line(s.top_left, s.bottom_left, WHITE, camera, img);
			if (i == map->rows - 2)
			{
				plot_line(s.bottom_left, s.bottom_right, WHITE, camera, img);
			}
			if (j == map->cols - 2)
			{
				plot_line(s.top_right, s.bottom_right, WHITE, camera, img);
			}
			j++;
		}
		i++;
	}
}