/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:08:31 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/20 16:31:40 by skoulen          ###   ########.fr       */
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

int	get_r(int clr)
{
	return ((clr >> 16) & 255);
}

int	get_g(int clr)
{
	return ((clr >> 8) & 255);
}

int	get_b(int clr)
{
	return (clr & 255);
}
