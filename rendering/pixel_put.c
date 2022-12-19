/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:42:49 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/19 13:20:55 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_img_data *img, int x, int y, int color)
{
	char	*dst;

	x = x + WIDTH / 2;
	y = -y + HEIGHT / 2;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
	{
		return ;
	}
	else
	{
		dst = img->addr + (y * img->ll + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int		is_put(t_img_data *img, int x, int y,  int color)
{
	char	*dst;

	x = x + WIDTH / 2;
	y = -y + HEIGHT / 2;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
	{
		return 1;
	}
	else
	{
		dst = img->addr + (y * img->ll + x * (img->bpp / 8));
		return (*(unsigned int *)dst == (unsigned int)color);
	}
}
