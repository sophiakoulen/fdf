/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:23:39 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/21 17:55:27 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	register_events(t_param *param)
{
	mlx_hook(param->window, EVENT_KEYDOWN, 1L, handle_keydown, param);
	mlx_hook(param->window, EVENT_CLOSE, 1L, handle_close, param);
}

void	do_rendering(t_map *map)
{
	t_param		param;

	set_param(&param, map);
	register_events(&param);
	render(&param);
	mlx_loop(param.mlx);
}
