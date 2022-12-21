/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:41:45 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/20 16:31:23 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

float	distance(t_vector2 p0, t_vector2 p1)
{
	int	dx;
	int	dy;

	dx = p0.x - p1.x;
	dy = p0.y - p1.y;
	return (sqrt(dx * dx + dy * dy));
}
