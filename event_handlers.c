/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:54:08 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/16 12:11:36 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	if (code == 53)
		exit(EXIT_SUCCESS);
	else if (code == 126)
	{
		args->camera->position.y += 5;
		render(args->mlx, args->window, args->cube, args->camera);
	}
	else if (code == 125)
	{
		args->camera->position.y -= 5;
		render(args->mlx, args->window, args->cube, args->camera);
	}
	else if (code == 124)
	{
		args->camera->position.x += 5;
		render(args->mlx, args->window, args->cube, args->camera);
	}
	else if (code == 123)
	{
		args->camera->position.x -= 5;
		render(args->mlx, args->window, args->cube, args->camera);
	}
	return (0);
}
