/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:08:31 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/19 13:31:37 by skoulen          ###   ########.fr       */
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
