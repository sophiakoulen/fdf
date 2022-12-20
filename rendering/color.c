/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:08:31 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/20 14:44:06 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rgb(int r, int g, int b)
{
	int	clr;

	clr = r;
	clr <<= 8;
	clr |= g;
	clr <<= 8;
	clr |= b;
	return (clr);
}

int get_r(int clr)
{
	return ((clr >> 16) & 255);
}

int get_g(int clr)
{
	return ((clr >> 8) & 255);
}

int get_b(int clr)
{
	return (clr & 255);
}

int	compute_color(t_vector3 p, int max)
{
	float	percent;
	int		r;
	int		g;
	int		b;

	percent = (float)p.y / (float)max;
	r = 255;
	g = 255;
	b = 255;
	return (rgb(r, (1 - percent) * g, b));
}

float distance(t_vector2 p0, t_vector2 p1)
{
	int	dx;
	int	dy;

	dx = p0.x - p1.x;
	dy = p0.y - p1.y;
	return (sqrt(dx * dx + dy * dy));
}

int	color_lerp(int str_clr, int end_clr, float ratio)
{
	int		r;
	int		g;
	int		b;

	r = get_r(str_clr) * (1 - ratio) + get_r(end_clr) * ratio;
	g = get_g(str_clr) * (1 - ratio) + get_g(end_clr) * ratio;
	b = get_b(str_clr) * (1 - ratio) + get_b(end_clr) * ratio;
	return (rgb(r, g, b));
}

int	color_lerp_line(int str_clr, int end_clr, t_vector2 start, t_vector2 end, t_vector2 curr)
{
	float	ratio;

	ratio = distance(start, curr) / distance(start, end);
	return (color_lerp(str_clr, end_clr, ratio));
}
