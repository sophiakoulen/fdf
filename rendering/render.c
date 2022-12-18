/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:08:50 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/18 11:03:12 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render(void	*mlx, void *window, t_cube *cube, t_camera *camera)
{
	t_img_data	img;

	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	t_vector3 center = (t_vector3){0, 0, 0};
	t_vector3 back = (t_vector3){0, 0, 40};
	t_vector3 front = (t_vector3){0, 0, -40};
	t_vector3 right = (t_vector3){40, 0, 0};
	t_vector3 left = (t_vector3){-40, 0, 0};

	plot_point(center, RED, camera, &img);
	plot_point(back, BLUE, camera, &img);
	plot_point(front, BLUE, camera, &img);
	plot_point(right, BLUE, camera, &img);
	plot_point(left, BLUE, camera, &img);

	drawCube(cube->position, cube->size, camera, &img);

	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
}
