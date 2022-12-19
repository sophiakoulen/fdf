/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:43:43 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/19 11:46:43 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	plot_line_low(t_vector2 p0, t_vector2 p1, int color, t_img_data *data)
{
	t_vector2	delta;
	int			yi;
	int			error;
	t_vector2	iter;

	yi = 1;
	if (p1.y - p0.y < 0)
		yi = -1;
	delta = (t_vector2){p1.x - p0.x, abs(p1.y - p0.y)};
	error = 2 * delta.y - delta.x;
	iter = p0;
	while (iter.x < p1.x)
	{
		pixel_put(data, iter.x, iter.y, color);
		if (error > 0)
		{
			iter.y += yi;
			error += (2 * (delta.y - delta.x));
		}
		else
			error += (2 * delta.y);
		iter.x++;
	}
}

static void	plot_line_high(t_vector2 p0, t_vector2 p1, int color, t_img_data *data)
{
	t_vector2	delta;
	int			xi;
	int			error;
	t_vector2	iter;

	xi = 1;
	if (p1.x - p0.x < 0)
		xi = -1;
	delta = (t_vector2){abs(p1.x - p0.x), p1.y - p0.y};
	error = 2 * delta.x - delta.y;
	iter = p0;
	while (iter.y < p1.y)
	{
		pixel_put(data, iter.x, iter.y, color);
		if (error > 0)
		{
			iter.x += xi;
			error += 2 * (delta.x - delta.y);
		}
		else
			error += 2 * delta.x;
		iter.y++;
	}	
}

void	bresenham_line(t_vector2 p0, t_vector2 p1, int color, t_img_data *data)
{
	if (abs(p1.y - p0.y) < abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			plot_line_low(p1, p0, color, data);
		else
			plot_line_low(p0, p1, color, data);
	}
	else
	{
		if (p0.y > p1.y)
			plot_line_high(p1, p0, color, data);
		else
			plot_line_high(p0, p1, color, data);
	}
}
