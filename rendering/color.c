/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:08:31 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/19 11:50:30 by skoulen          ###   ########.fr       */
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

int	compute_color(t_vector3 p)
{
	float	percent;

	percent = (float)p.y / (float)100;
	return (rgb(255, (1 - 2 * percent) * 255, (1 - percent) * 255));
}
