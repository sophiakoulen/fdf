/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:59:43 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/18 18:05:10 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_point(t_vector3 point, int color, t_camera *camera, t_img_data *img)
{
	t_vector2	point2d;

	point2d = project(point, camera);
	pixel_put(img, point2d.x, point2d.y, color);
}

void	plot_line(t_vector3 p0, t_vector3 p1, t_camera *camera, t_img_data *img)
{
	t_vector2	r0;
	t_vector2	r1;

	r0 = project(p0, camera);
	r1 = project(p1, camera);
	bresenham_line(r0, r1, img);
}
