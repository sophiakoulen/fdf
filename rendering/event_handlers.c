/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:54:08 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/20 15:49:20 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define ESC 53

#define UP 126
#define DOWN 125
#define LEFT 124
#define RIGHT 123

static void	clean_exit(t_param *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}

int	handle_close(void *param)
{
	clean_exit(param);
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
		clean_exit(param);
	}
	if (code == 35)
	{
		args->camera->projection = !args->camera->projection;
		render(param);
	}
	key_arrow_control(code, param);
	return (0);
}
