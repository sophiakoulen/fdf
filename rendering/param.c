/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:44:00 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/20 17:45:00 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_param(t_param *param, t_map *map)
{
	param->mlx = mlx_init();
	param->window = mlx_new_window(param->mlx, WIDTH, HEIGHT, TITLE);
	param->camera = new_camera();
	param->map = map;
	if (!param->camera)
	{
		cleanup_param(param);
		exit(EXIT_FAILURE);
	}
	retrieve_limits(param);
	adjust_scale(param);
}

void	cleanup_param(t_param *param)
{
	cleanup_map(param->map->map);
	cleanup_camera(param->camera);
	free(param->camera);
}
