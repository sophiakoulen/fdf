/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:41:58 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/16 16:29:28 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define TITLE "fdf"

#define DEFAULT_ALPHA 0.610865238
#define DEFAULT_BETA 0.785398

void	init_camera(t_camera *camera)
{
	camera->zoom = 150;
	camera->projection = ORTHOGRAPHIC;
	camera->position = (t_vector3){0, 0, -25};
	camera->alpha = init_matrix();
	camera->beta = init_matrix();
	if (!camera->alpha || !camera->beta)
		exit(EXIT_FAILURE);
	compute_alpha_matrix(DEFAULT_ALPHA, camera->alpha);
	compute_beta_matrix(DEFAULT_BETA, camera->beta);
}

int main()
{
	t_param		param;
	t_camera	camera;

	param.mlx = mlx_init();
	param.window = mlx_new_window(param.mlx, WIDTH, HEIGHT, TITLE);

	param.camera = &camera;
	init_camera(param.camera);

	t_cube cube = {.position = (t_vector3){0, 0, 0}, .size =  42};

	param.cube = &cube;

	render(param.mlx, param.window, &cube, &camera);

	mlx_hook(param.window, 17, 0, handle_close, 0);
	mlx_hook(param.window, 2, 0, handle_keydown, &param);
	
	mlx_loop(param.mlx);
	
	return (0);
}