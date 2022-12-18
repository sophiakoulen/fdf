/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:54:08 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/18 17:09:36 by skoulen          ###   ########.fr       */
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
	//cleanup_map(param->map->map);
	exit(EXIT_SUCCESS);
}

int	handle_close(void *param)
{
	clean_exit(param);
	return (0);
}

int handle_keydown(int code, void *param)
{
	t_param	*args;

	args = param;
	printf("%d\n", code);
	if (code == ESC)
	{
		clean_exit(param);
	}
	else if (code == 35) //P
	{
		args->camera->projection = !args->camera->projection;
		render(param);	
	}
	else if (code == UP)
	{
		args->camera->position.y += 5;
		render(param);
	}
	else if (code == DOWN)
	{
		args->camera->position.y -= 5;
		render(param);
	}
	else if (code == LEFT)
	{
		args->camera->position.x += 5;
		render(param);
	}
	else if (code == RIGHT)
	{
		args->camera->position.x -= 5;
		render(param);
	}
	return (0);
}


