/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:59:43 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/20 12:53:39 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_point(t_vector3 p, t_param *param, t_img_data *img)
{
	t_vector2	point2d;
	int			color;

	color = compute_color(p, param->max);
	point2d = project(p, param->camera);
	pixel_put(img, point2d.x, point2d.y, color);
}

int		is_drawn(t_vector3 p, t_param *param, t_img_data *img)
{
	t_vector2	point2d;
	int			color;

	color = compute_color(p,param->max);
	point2d = project(p, param->camera);
	return (is_put(img, point2d.x, point2d.y, color));
}

void	plot_line(t_vector3 p0, t_vector3 p1, t_param *param, t_img_data *img)
{
	t_vector2	r0;
	t_vector2	r1;
	int			color;

	color = WHITE;

	r0 = project(p0, param->camera);
	r1 = project(p1, param->camera);
	bresenham_line(r0, r1, color, img);
}
