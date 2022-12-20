/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:08:50 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/20 15:07:20 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_black(t_img_data *img)
{
	int	i;
	int	j;

	i = -WIDTH/2;
	while (i < WIDTH/2)
	{
		j = -HEIGHT/2;
		while (j < HEIGHT/2)
		{
			pixel_put(img, i, j, BACKGROUND);
			j++;
		}
		i++;
	}
}

void	render(t_param *param)
{
	t_img_data	img;

	img.img = mlx_new_image(param->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ll, &img.endian);
	make_black(&img);
	draw_terrain(param->map, param, &img);
	mlx_put_image_to_window(param->mlx, param->window, img.img, 0, 0);
}
