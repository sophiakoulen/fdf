/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:07:19 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/20 14:11:09 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vector3	relative_position(t_vector3 obj, t_vector3 cam)
{
	t_vector3	rel;

	rel.x = obj.x - cam.x;
	rel.y = obj.y - cam.y;
	rel.z = obj.z - cam.z;
	return (rel);
}

static t_vector2	project_perspective(t_vector3 object, t_camera *camera)
{
	t_vector2	res;
	t_vector3	pos;

	pos = relative_position(object, camera->position);
	if (pos.z == 0)
	{
		return ((t_vector2){INT_MAX, INT_MAX});
	}
	res.x = (camera->zoom / (float)pos.z * pos.x);
	res.y = (camera->zoom / (float)pos.z * pos.y);
	return (res);
}

void	compute_alpha_matrix(float alpha, float **m)
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;

	m[1][0] = 0;
	m[1][1] = cos(alpha);
	m[1][2] = sin(alpha);
	
	m[2][0] = 0;
	m[2][1] = -sin(alpha);
	m[2][2] = cos(alpha);
}

void	compute_beta_matrix(float beta, float **m)
{
	m[0][0] = cos(beta);
	m[0][1] = 0;
	m[0][2] = -sin(beta);

	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	
	m[2][0] = sin(beta);
	m[2][1] = 0;
	m[2][2] = cos(beta);
}

static t_vector3	rotate(t_vector3 obj, t_camera *camera)
{
	float	**a;
	float	**b;

	a = camera->alpha;
	b = camera->beta;
	return (mult(a, mult(b, obj))); 
}

static t_vector2	project_orthographic(t_vector3 object, t_camera *camera)
{
	t_vector2	res;
	t_vector3	pos;

	pos = rotate(object, camera);
	res.x = pos.x * camera->scale - camera->position.x;
	res.y = -pos.z * camera->scale - camera->position.y;
	return (res);
}

t_vector2	project(t_vector3 point, t_camera *camera)
{
	if (camera->projection == PERSPECTIVE)
		return (project_perspective(point, camera));
	else
		return (project_orthographic(point, camera));
}
