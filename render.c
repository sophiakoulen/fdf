/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:08:50 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/16 12:09:07 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render(void	*mlx, void *window, t_cube *cube, t_camera *camera)
{
	t_img_data	img;

	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	drawCube(cube->position, cube->size, *camera, &img);

	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
}
