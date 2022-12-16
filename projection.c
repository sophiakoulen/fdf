/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:07:19 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/16 16:30:11 by skoulen          ###   ########.fr       */
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

t_vector2	project_perspective(t_vector3 object, t_camera camera)
{
	t_vector2	res;
	t_vector3	pos;

	pos = relative_position(object, camera.position);
	res.x = (float)((float)camera.zoom / (float)pos.z * (float)pos.x);
	res.y = (float)((float)camera.zoom / (float)pos.z * (float)pos.y);

	//BEWARE OF FLOATING POINT EXCEPTION
	
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

#define SQRT_3 1.732050807568877
#define SQRT_2 1.414213562373095
#define SQRT_6 2.449489742783178

static t_vector3	rotate(t_vector3 obj, t_camera camera)
{
	float	**a;
	float	**b;

	a = camera.alpha;
	b = camera.beta;
	return (do_mult(a, do_mult(b, obj))); 
}

t_vector2	project_orthographic(t_vector3 object, t_camera camera)
{
	t_vector2	res;
	t_vector3	pos;

	pos = rotate(object, camera);
	res.x = pos.x - camera.position.x;
	res.y = pos.z - camera.position.y;
	return (res);
}
