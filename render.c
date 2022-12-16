/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:08:50 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/16 15:31:48 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render(void	*mlx, void *window, t_cube *cube, t_camera *camera)
{
	t_img_data	img;

	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	t_vector2 center;
	t_vector2 back;
	t_vector2 front;
	t_vector2 right;
	t_vector2 left;
	if (camera->projection == PERSPECTIVE)
	{
		center = project_perspective((t_vector3){0, 0, 0}, *camera);
		back = project_perspective((t_vector3){0, 0, 20}, *camera);
		front = project_perspective((t_vector3){0, 0, -20}, *camera);
		right = project_perspective((t_vector3){20, 0, 0}, *camera);
		left = project_perspective((t_vector3){-20, 0, 0}, *camera);
	}
	else
	{
		center = project_orthographic((t_vector3){0, 0, 0}, *camera);
		back = project_orthographic((t_vector3){0, 0, 20}, *camera);
		front = project_orthographic((t_vector3){0, 0, -20}, *camera);
		right = project_orthographic((t_vector3){20, 0, 0}, *camera);
		left = project_orthographic((t_vector3){-20, 0, 0}, *camera);
	}
	pixel_put(&img, center.x, center.y, RED);
	pixel_put(&img, back.x, back.y, RED);
	pixel_put(&img, front.x, front.y, RED);
	pixel_put(&img, right.x, right.y, RED);
	pixel_put(&img, left.x, left.y, RED);

	drawCube(cube->position, cube->size, *camera, &img);

	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
}
