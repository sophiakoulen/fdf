/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:58:01 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/20 17:58:30 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	in_view(t_vector3 point, t_camera *cam)
{
	t_vector2	r;

	r = project(point, cam);
	return (r.x >= -WIDTH / 2 && r.x <= WIDTH / 2
		&& r.y >= -HEIGHT / 2 && r.y <= HEIGHT / 2);
}

void	adjust_scale(t_param *param)
{
	t_vector3	p0;
	t_vector3	p1;
	t_vector3	p2;
	t_vector3	p3;

	p0 = get_coordinate(param->map, 0, 0);
	p1 = get_coordinate(param->map, 0, param->map->cols - 1);
	p2 = get_coordinate(param->map, param->map->rows - 1, 0);
	p3 = get_coordinate(param->map, param->map->rows - 1, param->map->cols - 1);
	if (!in_view(p0, param->camera) || !in_view(p1, param->camera)
		|| !in_view(p2, param->camera) || !in_view(p3, param->camera))
	{
		param->camera->scale *= 0.8;
		adjust_scale(param);
	}
}
