/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:58:03 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/19 13:45:36 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector3	midpoint(t_vector3 p0, t_vector3 p1)
{
	t_vector3	mid;

	mid = (t_vector3){(p0.x + p1.x) / 2, (p0.y + p1.y) / 2, (p0.z + p1.z) / 2};
	return (mid);
}

void	draw_line(t_vector3 p0, t_vector3 p1, t_param *param, t_img_data *img)
{
	t_vector3	mid;
	t_vector2	r0;
	t_vector2	r1;
	t_vector2	rm;

	//printf("drawing line: p0{%d %d %d} - p1{%d %d %d}\n", p0.x, p0.y, p0.z, p1.x, p1.y, p1.z);

	mid = midpoint(p0, p1);
	r0 = project(p0, param->camera);
	r1 = project(p1, param->camera);
	rm = project(mid, param->camera);

	//printf("r0: {%d %d} rm: {%d %d} r1: {%d %d}\n", r0.x, r0.y, rm.x, rm.y, r1.x, r1.y);


	plot_point(p0, param, img);
	plot_point(p1, param, img);

	if (is_drawn(mid, param, img))
		return ;

	plot_point(mid, param, img);

	if (abs(p0.x - p1.x) > 0 || abs(p0.y - p1.y) > 0 || abs(p0.z - p1.z) > 0)
	{
		draw_line(p0, mid, param, img);
		draw_line(p1, mid, param, img);
	}

}
