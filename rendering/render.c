/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:08:50 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/20 12:54:36 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_black(t_img_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			pixel_put(img, i, j, 0);
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
	pixel_put(&img, 0, 0, RED);
	pixel_put(&img, -150, 0, RED);
	pixel_put(&img, 150, 0, RED);
	mlx_put_image_to_window(param->mlx, param->window, img.img, 0, 0);
}
