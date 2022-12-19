/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:23:39 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/19 13:44:36 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	do_rendering(t_map *map)
{
	t_param		param;
	t_camera	camera;

	param.mlx = mlx_init();
	param.window = mlx_new_window(param.mlx, WIDTH, HEIGHT, TITLE);
	param.camera = &camera;
	init_camera(param.camera);
	param.map = map;
	param.max = map->map[0][0];
	for(int i = 0; i < map->rows; i++)
	{
		for (int j = 0; j < map->cols; j++)
		{
			if (map->map[i][j] > param.max)
				param.max = map->map[i][j];
		}
	}
	render(&param);
	mlx_hook(param.window, 17, 0, handle_close, 0);
	mlx_hook(param.window, 2, 0, handle_keydown, &param);
	mlx_loop(param.mlx);
}
