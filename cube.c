/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:50:59 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/16 14:06:23 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawCube(t_vector3 pos, int size, t_camera camera, t_img_data *data)
{
	t_vector3 p0, p1, p2, p3, p4, p5, p6, p7;

	t_vector2 r0, r1, r2, r3, r4, r5, r6, r7;


	p0 = (t_vector3){pos.x - size / 2, pos.y - size / 2, pos.z};
	p1 = (t_vector3){pos.x + size / 2, pos.y - size / 2, pos.z};
	p2 = (t_vector3){pos.x - size / 2, pos.y + size / 2, pos.z};
	p3 = (t_vector3){pos.x + size / 2, pos.y + size / 2, pos.z};

	p4 = (t_vector3){pos.x - size / 2, pos.y - size / 2, pos.z + size};
	p5 = (t_vector3){pos.x + size / 2, pos.y - size / 2, pos.z + size};
	p6 = (t_vector3){pos.x - size / 2, pos.y + size / 2, pos.z + size};
	p7 = (t_vector3){pos.x + size / 2, pos.y + size / 2, pos.z + size};

	if (camera.projection == PERSPECTIVE)
	{
		r0 = project_perspective(p0, camera);
		r1 = project_perspective(p1, camera);
		r2 = project_perspective(p2, camera);
		r3 = project_perspective(p3, camera);

		r4 = project_perspective(p4, camera);
		r5 = project_perspective(p5, camera);
		r6 = project_perspective(p6, camera);
		r7 = project_perspective(p7, camera);
	}
	else
	{
		r0 = project_orthographic(p0, camera);
		r1 = project_orthographic(p1, camera);
		r2 = project_orthographic(p2, camera);
		r3 = project_orthographic(p3, camera);

		r4 = project_orthographic(p4, camera);
		r5 = project_orthographic(p5, camera);
		r6 = project_orthographic(p6, camera);
		r7 = project_orthographic(p7, camera);
	}

	bresenhamLine(r0, r1, data);
	bresenhamLine(r1, r3, data);
	bresenhamLine(r0, r2, data);
	bresenhamLine(r2, r3, data);

	bresenhamLine(r4, r5, data);
	bresenhamLine(r5, r7, data);
	bresenhamLine(r4, r6, data);
	bresenhamLine(r6, r7, data);

	bresenhamLine(r0, r4, data);
	bresenhamLine(r1, r5, data);
	bresenhamLine(r2, r6, data);
	bresenhamLine(r3, r7, data);
}