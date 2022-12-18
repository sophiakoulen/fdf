/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:43:43 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/18 16:00:35 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	plotLineLow(t_vector2 p0, t_vector2 p1, t_img_data *data)
{
	int	dx;
	int	dy;
	int	yi;
	int	D;
	int	y;
	int	x;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	
	D = (2 * dy) - dx;
	y = p0.y;
	x = p0.x;
	while (x < p1.x)
	{
		pixel_put(data, x, y, WHITE);
		if (D > 0)
		{
			y += yi;
			D += (2 * (dy - dx));
		}
		else
			D += (2 * dy);
		x++;
	}
}

static void	plotLineHigh(t_vector2 p0, t_vector2 p1, t_img_data *data)
{
	int	dx = p1.x - p0.x;
	int	dy = p1.y - p0.y;
	int xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	int D = (2 * dx) - dy;
	int x = p0.x;

	for (int y = p0.y; y < p1.y; y++)
	{
		pixel_put(data, x, y, WHITE);
		if (D > 0)
		{
			x += xi;
			D = D + (2 * (dx - dy));
		}
		else
			D = D + 2 * dx;
	}	
}

void	bresenhamLine(t_vector2 p0, t_vector2 p1, t_img_data *data)
{
	if (abs(p1.y - p0.y) < abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			plotLineLow(p1, p0, data);
		else
			plotLineLow(p0, p1, data);
	}
	else
	{
		if (p0.y > p1.y)
			plotLineHigh(p1, p0, data);
		else
			plotLineHigh(p0, p1, data);
	}
}
