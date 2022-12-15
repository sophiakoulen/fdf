/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:07:19 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/15 16:01:04 by skoulen          ###   ########.fr       */
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
	return (res);
}

/*
t_vector2	project_isometric(t_vector3 object)
{
	
}
*/