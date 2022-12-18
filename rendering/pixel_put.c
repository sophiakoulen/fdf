/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:42:49 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/18 11:08:01 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_img_data *data, int x, int y, int color)
{
	char *dst;

	x = x + WIDTH / 2;
	y = -y + HEIGHT / 2;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
	{
		return ;
	}
	else
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	plot_point(t_vector3 point, int color, t_camera *camera, t_img_data *img)
{
	t_vector2	point2d;

	point2d = project(point, camera);
	pixel_put(img, point2d.x, point2d.y, color);
}

void	plot_line(t_vector3 p0, t_vector3 p1, int color, t_camera *camera, t_img_data *img)
{
	t_vector2	r0;
	t_vector2	r1;

	(void)color;
	r0 = project(p0, camera);
	r1 = project(p1, camera);
	bresenhamLine(r0, r1, img);
}
