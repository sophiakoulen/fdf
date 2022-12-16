/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:54:08 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/16 14:17:45 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define ESC 53

#define UP 126
#define DOWN 125
#define LEFT 124
#define RIGHT 123


int	handle_close(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
	return (0);
}

int handle_keydown(int code, void *param)
{
	t_param	*args;

	args = param;
	printf("%d\n", code);
	if (code == ESC)
	{
		exit(EXIT_SUCCESS);
	}
	else if (code == 35) //P
	{
		args->camera->projection = !args->camera->projection;
		render(args->mlx, args->window, args->cube, args->camera);		
	}
	else if (code == UP)
	{
		args->camera->position.y += 5;
		render(args->mlx, args->window, args->cube, args->camera);
	}
	else if (code == DOWN)
	{
		args->camera->position.y -= 5;
		render(args->mlx, args->window, args->cube, args->camera);
	}
	else if (code == LEFT)
	{
		args->camera->position.x += 5;
		render(args->mlx, args->window, args->cube, args->camera);
	}
	else if (code == RIGHT)
	{
		args->camera->position.x -= 5;
		render(args->mlx, args->window, args->cube, args->camera);
	}
	return (0);
}


