/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:27:51 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/18 10:28:36 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_camera(t_camera *camera)
{
	camera->zoom = 150;
	camera->projection = ORTHOGRAPHIC;
	camera->position = (t_vector3){0, 0, -25};
	camera->alpha = init_matrix();
	camera->beta = init_matrix();
	if (!camera->alpha || !camera->beta)
	{
		exit(EXIT_FAILURE);
	}
	compute_alpha_matrix(DEFAULT_ALPHA, camera->alpha);
	compute_beta_matrix(DEFAULT_BETA, camera->beta);
}

void	cleanup_camera(t_camera *camera)
{
	cleanup_matrix(camera->alpha);
	cleanup_matrix(camera->beta);
}
