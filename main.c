/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:41:58 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/16 12:08:46 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define TITLE "fdf"

int main()
{
	t_param	param;

	param.mlx = mlx_init();
	param.window = mlx_new_window(param.mlx, WIDTH, HEIGHT, TITLE);
	
	t_camera camera = (t_camera){150, (t_vector3){0, 25, 0}};
	t_cube cube = {.position = (t_vector3){25, 0, 80}, .size =  42};

	param.cube = &cube;
	param.camera = &camera;

	render(param.mlx, param.window, &cube, &camera);

	mlx_hook(param.window, 17, 0, handle_close, 0);
	mlx_hook(param.window, 2, 0, handle_keydown, &param);
	
	mlx_loop(param.mlx);
	
	return (0);
}