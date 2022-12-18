/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:41:58 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/18 10:48:51 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main()
{
	t_param		param;
	t_camera	camera;

	param.mlx = mlx_init();
	param.window = mlx_new_window(param.mlx, WIDTH, HEIGHT, TITLE);

	param.camera = &camera;
	init_camera(param.camera);

	t_cube cube = {.position = (t_vector3){0, 0, 0}, .size =  80};

	param.cube = &cube;

	render(param.mlx, param.window, &cube, &camera);

	mlx_hook(param.window, 17, 0, handle_close, 0);
	mlx_hook(param.window, 2, 0, handle_keydown, &param);
	
	mlx_loop(param.mlx);
	
	return (0);
}