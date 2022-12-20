/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:23:39 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/20 17:49:00 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	register_events(t_param *param)
{
	mlx_hook(param->window, EVENT_CLOSE, 0, handle_close, param);
	mlx_hook(param->window, EVENT_KEYDOWN, 0, handle_keydown, param);
}

void	do_rendering(t_map *map)
{
	t_param		param;

	init_param(&param, map);
	render(&param);
	register_events(&param);
	mlx_loop(param.mlx);
}
