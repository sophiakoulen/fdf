/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:31:42 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/20 16:31:55 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	color_lerp_line(t_line2d line, t_vector2 curr)
{
	float	ratio;

	ratio = distance(line.p0, curr) / distance(line.p0, line.p1);
	return (color_lerp(line.clr0, line.clr1, ratio));
}
