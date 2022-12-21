/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:08:50 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/21 11:31:46 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_black(t_img_data *img)
{
	int	i;
	int	j;

	i = -WIDTH / 2;
	while (i < WIDTH / 2)
	{
		j = -HEIGHT / 2;
		while (j < HEIGHT / 2)
		{
			pixel_put(img, i, j, BACKGROUND);
			j++;
		}
		i++;
	}
}

void	render(t_param *param)
{
	make_black(param->img);
	draw_terrain(param->map, param, param->img);
	mlx_put_image_to_window(param->mlx, param->window, param->img->img, 0, 0);
}
