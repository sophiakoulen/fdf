/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:54:08 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/21 14:36:33 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_exit(t_param *param, int status)
{
	cleanup_param(param);
	exit(status);
}

int	handle_close(void *param)
{
	clean_exit(param, EXIT_SUCCESS);
	return (0);
}

static void	key_arrow_control(int code, t_param *param)
{
	if (code == UP)
	{
		param->camera->position.y += 5;
		render(param);
	}
	if (code == DOWN)
	{
		param->camera->position.y -= 5;
		render(param);
	}
	if (code == LEFT)
	{
		param->camera->position.x += 5;
		render(param);
	}
	if (code == RIGHT)
	{
		param->camera->position.x -= 5;
		render(param);
	}
}

int	handle_keydown(int code, void *param)
{
	t_param	*args;

	args = param;
	if (code == ESC)
	{
		clean_exit(param, EXIT_SUCCESS);
	}
	if (code == 35)
	{
		args->camera->projection = !args->camera->projection;
		render(param);
	}
	key_arrow_control(code, param);
	return (0);
}
