/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:27:51 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/20 13:16:33 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_camera(t_camera *camera)
{
	camera->zoom = 150;
	camera->projection = ORTHOGRAPHIC;
	camera->position = (t_vector3){0, 100, -400};
	camera->alpha = init_matrix();
	camera->beta = init_matrix();
	camera->scale = 1;
	if (!camera->alpha || !camera->beta)
	{
		exit(EXIT_FAILURE);
	}
	compute_alpha_matrix(DEFAULT_ALPHA, camera->alpha);
	compute_beta_matrix(DEFAULT_BETA, camera->beta);
}

void	cleanup_camera(t_camera *camera)
{
	cleanup_matrix(camera->alpha);
	cleanup_matrix(camera->beta);
}

int		in_view(t_vector3 point, t_camera *cam)
{
	t_vector2	r;

	printf("projection: orthographic? %d\n", cam->projection == ORTHOGRAPHIC);
	r = project(point, cam);
	printf("p: {%lld %lld %lld}\n", point.x, point.y, point.z);
	printf("r: {%d %d}\n", r.x, r.y);
	return (r.x >= -WIDTH/2 && r.x <= WIDTH/2 && r.y >= -HEIGHT/2 && r.y <= HEIGHT/2);
}

void	adjust_scale(t_param *param)
{
	t_map	*map;
	int		rows;
	int		cols;
	t_vector3	p0, p1, p2, p3;

	printf("adjust scale\n");
	map = param->map;
	rows = param->map->rows;
	cols = param->map->cols;
	p0 = get_coordinate(map, 0, 0);
	p1 = get_coordinate(map, 0, cols - 1);
	p2 = get_coordinate(map, rows - 1, 0);
	p3 = get_coordinate(map, rows - 1, cols - 1);
	if (!in_view(p0, param->camera) || !in_view(p1, param->camera) || !in_view(p2, param->camera) || !in_view(p3, param->camera))
	{
		param->camera->scale *= 0.8;
		adjust_scale(param);
	}
}
