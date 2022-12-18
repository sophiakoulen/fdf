/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:50:59 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/18 17:32:04 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_cube(t_vector3 pos, int size, t_camera *camera, t_img_data *data)
{
	t_vector3 p0, p1, p2, p3, p4, p5, p6, p7;


	p0 = (t_vector3){pos.x - size / 2, pos.y, pos.z - size / 2};
	p1 = (t_vector3){pos.x + size / 2, pos.y, pos.z - size / 2};
	p2 = (t_vector3){pos.x - size / 2, pos.y + size, pos.z - size / 2};
	p3 = (t_vector3){pos.x + size / 2, pos.y + size, pos.z - size / 2};

	p4 = (t_vector3){pos.x - size / 2, pos.y, pos.z + size / 2};
	p5 = (t_vector3){pos.x + size / 2, pos.y, pos.z + size / 2};
	p6 = (t_vector3){pos.x - size / 2, pos.y + size, pos.z + size / 2};
	p7 = (t_vector3){pos.x + size / 2, pos.y + size, pos.z + size / 2};

	plot_line(p0, p1, 0, camera, data);
	plot_line(p1, p3, 0, camera, data);
	plot_line(p0, p2, 0, camera, data);
	plot_line(p2, p3, 0, camera, data);

	plot_line(p4, p5, 0, camera, data);
	plot_line(p5, p7, 0, camera, data);
	plot_line(p4, p6, 0, camera, data);
	plot_line(p6, p7, 0, camera, data);

	plot_line(p0, p4, 0, camera, data);
	plot_line(p1, p5, 0, camera, data);
	plot_line(p2, p6, 0, camera, data);
	plot_line(p3, p7, 0, camera, data);
}
