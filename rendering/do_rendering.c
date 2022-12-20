/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:23:39 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/20 17:01:37 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	retrieve_limits(t_param *param)
{
	t_map	*map;
	int		max;
	int		min;
	int		i;
	int		j;

	map = param->map;
	max = map->map[0][0];
	min = map->map[0][0];
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->map[i][j] > max)
				max = map->map[i][j];
			if (map->map[i][j] < min)
				min = map->map[i][j];
			j++;
		}
		i++;
	}
	param->max = max;
	param->min = min;
}

void	register_events(t_param *param)
{
	mlx_hook(param->window, EVENT_CLOSE, 0, handle_close, 0);
	mlx_hook(param->window, EVENT_KEYDOWN, 0, handle_keydown, param);
}

void	init_param(t_param *param, t_map *map)
{
	param->mlx = mlx_init();
	param->window = mlx_new_window(param->mlx, WIDTH, HEIGHT, TITLE);
	param->camera = new_camera();
	param->map = map;
	if (!param->camera)
	{
		exit(EXIT_FAILURE);
	}
	retrieve_limits(param);
	printf("min: %d max: %d\n", param->min, param->max);
	adjust_scale(param);
}

void	do_rendering(t_map *map)
{
	t_param		param;

	init_param(&param, map);
	render(&param);
	register_events(&param);
	mlx_loop(param.mlx);
}
