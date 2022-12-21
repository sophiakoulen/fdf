/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:59:43 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/20 17:56:06 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line3d(t_line3d line3, t_param *param, t_img_data *img)
{
	t_line2d	line2;

	line2.p0 = project(line3.p0, param->camera);
	line2.p1 = project(line3.p1, param->camera);
	line2.clr0 = line3.clr0;
	line2.clr1 = line3.clr1;
	bresenham_line(line2, img);
}
