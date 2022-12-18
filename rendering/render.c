/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:08:50 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/18 18:02:44 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render(t_param *param)
{
	t_img_data	img;

	img.img = mlx_new_image(param->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ll, &img.endian);
	draw_terrain(param->map, param->camera, &img);
	mlx_put_image_to_window(param->mlx, param->window, img.img, 0, 0);
}
