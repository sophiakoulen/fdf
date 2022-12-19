/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:58:03 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/19 11:47:06 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector3	midpoint(t_vector3 p0, t_vector3 p1)
{
	t_vector3	mid;

	mid = (t_vector3){(p0.x + p1.x) / 2, (p0.y + p1.y) / 2, (p0.z + p1.z) / 2};
	return (mid);
}

void	draw_line(t_vector3 p0, t_vector3 p1, t_camera *cam, t_img_data *img)
{
	t_vector3	mid;
	t_vector2	r0;
	t_vector2	r1;
	t_vector2	rm;

	mid = midpoint(p0, p1);
	r0 = project(p0, cam);
	r1 = project(p1, cam);
	rm = project(mid, cam);

	plot_point(mid, cam, img);
	plot_point(p0, cam, img);
	plot_point(p1, cam, img);
	if ((abs(r0.x - rm.x) > 1) || (abs(r0.y - rm.y) > 1))
	{
		printf("drawing line: p0{%d %d %d} - mid{%d %d %d}\n", p0.x, p0.y, p0.z, mid.x,mid.y,mid.z);
		draw_line(p0, mid, cam, img);
	}
	if ((abs(r1.x - rm.x) > 1) || (abs(r1.y - rm.y) > 1))
	{
		draw_line(mid, p1, cam, img);
	}
}
