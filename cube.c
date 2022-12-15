/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:50:59 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/15 10:58:36 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawCube(int x, int y, int z, int l, t_data *data)
{
	(void)z;
	t_point p0, p1, p2, p3;

	p0 = (t_point){x - l / 2, y - l / 2};
	p1 = (t_point){x + l/2, y - l / 2};
	p2 = (t_point){x - l/ 2, y + l/ 2};
	p3 = (t_point){x + l/2, y + l/2};

	pixel_put(data, p0.x, p0.y, RED);
	pixel_put(data, p1.x, p1.y, RED);
	pixel_put(data, p2.x, p2.y, RED);
	pixel_put(data, p3.x, p3.y, RED);
	bresenhamLine(p0, p1, data);
	bresenhamLine(p1, p3, data);
	bresenhamLine(p2, p3, data);
	bresenhamLine(p0, p2, data);
}