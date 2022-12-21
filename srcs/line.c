/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:43:43 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/20 16:19:52 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	plot_line_low(t_line2d line, t_img_data *data)
{
	t_vector2	delta;
	int			yi;
	int			error;
	t_vector2	iter;

	yi = 1;
	if (line.p1.y - line.p0.y < 0)
		yi = -1;
	delta = (t_vector2){line.p1.x - line.p0.x, abs(line.p1.y - line.p0.y)};
	error = 2 * delta.y - delta.x;
	iter = line.p0;
	while (iter.x < line.p1.x)
	{
		pixel_put(data, iter.x, iter.y, color_lerp_line(line, iter));
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

static void	plot_line_high(t_line2d line, t_img_data *data)
{
	t_vector2	delta;
	int			xi;
	int			error;
	t_vector2	iter;

	xi = 1;
	if (line.p1.x - line.p0.x < 0)
		xi = -1;
	delta = (t_vector2){abs(line.p1.x - line.p0.x), line.p1.y - line.p0.y};
	error = 2 * delta.x - delta.y;
	iter = line.p0;
	while (iter.y < line.p1.y)
	{
		pixel_put(data, iter.x, iter.y, color_lerp_line(line, iter));
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

t_line2d	reverse_line(t_line2d line)
{
	return ((t_line2d){line.p1, line.p0, line.clr1, line.clr0});
}

void	bresenham_line(t_line2d line, t_img_data *data)
{
	if (abs(line.p1.y - line.p0.y) < abs(line.p1.x - line.p0.x))
	{
		if (line.p0.x > line.p1.x)
			plot_line_low(reverse_line(line), data);
		else
			plot_line_low(line, data);
	}
	else
	{
		if (line.p0.y > line.p1.y)
			plot_line_high(reverse_line(line), data);
		else
			plot_line_high(line, data);
	}
}
