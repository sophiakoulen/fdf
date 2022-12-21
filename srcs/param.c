/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:44:00 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/21 14:35:59 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_img_data	*new_image(t_param *param)
{
	t_img_data	*img;

	img = malloc(sizeof(*img));
	if (!img)
		return (0);
	img->img = mlx_new_image(param->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->ll, &img->endian);
	return (img);
}

static void	init_param(t_param *param)
{
	param->map = 0;
	param->mlx = 0;
	param->window = 0;
	param->img = 0;
	param->camera = 0;
}

void	set_param(t_param *param, t_map *map)
{
	init_param(param);
	param->map = map;
	param->mlx = mlx_init();
	if (!param->mlx)
	{
		clean_exit(param, EXIT_FAILURE);
	}
	param->window = mlx_new_window(param->mlx, WIDTH, HEIGHT, TITLE);
	if (!param->window)
	{
		clean_exit(param, EXIT_FAILURE);
	}
	param->img = new_image(param);
	if (!param->img)
	{
		clean_exit(param, EXIT_FAILURE);
	}
	param->camera = new_camera();
	if (!param->camera)
	{
		clean_exit(param, EXIT_FAILURE);
	}
	retrieve_limits(param);
	adjust_scale(param);
}

void	cleanup_param(t_param *param)
{
	if (param->mlx && param->window)
		mlx_destroy_window(param->mlx, param->window);
	if (param->mlx && param->img)
		mlx_destroy_image(param->mlx, param->img->img);
	free(param->img);
	if (param->map)
		cleanup_map(param->map);
	if (param->camera)
		destroy_camera(param->camera);
}
