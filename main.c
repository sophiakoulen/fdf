/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:41:58 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/15 16:03:39 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define TITLE "fdf"

int main()
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, TITLE);

	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	

	t_vector3 cubePos1 = (t_vector3){25, 0, 80};
	t_vector3 cubePos2 = (t_vector3){-30, 0, 80};
	t_vector3 cubePos3 = (t_vector3){100, 0, 80};
	t_vector3 cubePos4 = (t_vector3){-100, 0, 80};

	t_camera camera = (t_camera){150, (t_vector3){0, 0, -25}};

	drawCube(cubePos1, 42, camera, &img);
	drawCube(cubePos2, 42, camera, &img);
	drawCube(cubePos3, 42, camera, &img);
	drawCube(cubePos4, 42, camera, &img);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
	
	return (0);
}