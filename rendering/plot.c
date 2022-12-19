/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:59:43 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/19 11:45:40 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_point(t_vector3 p, t_camera *cam, t_img_data *img)
{
	t_vector2	point2d;
	int			color;

	color = compute_color(p);
	point2d = project(p, cam);
	pixel_put(img, point2d.x, point2d.y, color);
}

void	plot_line(t_vector3 p0, t_vector3 p1, t_camera *camera, t_img_data *img)
{
	t_vector2	r0;
	t_vector2	r1;
	t_vector3	mid;
	int			color;

	mid = midpoint(p0, p1);
	color = compute_color(mid);

	r0 = project(p0, camera);
	r1 = project(p1, camera);
	bresenham_line(r0, r1, color, img);
}
