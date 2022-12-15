/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:41:58 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/15 10:56:40 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define WIDTH 1920
#define HEIGHT 1080

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
	
	/*t_point p0 = (t_point){0, HEIGHT / 2};
	t_point p1 = (t_point){WIDTH - 1, HEIGHT / 2};

	pixel_put(&img, p0.x, p0.y, RED);
	pixel_put(&img, p1.x, p1.y, RED);

	bresenhamLine(p0, p1, &img);
*/
	drawCube(WIDTH / 2, HEIGHT / 2, 5, 42, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
	
	return (0);
}