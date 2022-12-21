/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:27:51 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/21 14:12:14 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_camera	*new_camera(void)
{
	t_camera	*camera;

	camera = malloc(sizeof(*camera));
	if (!camera)
		return (0);
	camera->zoom = 150;
	camera->projection = ORTHOGRAPHIC;
	camera->position = (t_vector3){0, 0, -150};
	camera->scale = 2;
	camera->alpha = init_matrix();
	camera->beta = init_matrix();
	if (!camera->alpha || !camera->beta)
	{
		exit(EXIT_FAILURE);
	}
	compute_alpha_matrix(DEFAULT_ALPHA, camera->alpha);
	compute_beta_matrix(DEFAULT_BETA, camera->beta);
	return (camera);
}

void	destroy_camera(t_camera *camera)
{
	if (!camera)
		return ;
	cleanup_matrix(camera->alpha);
	cleanup_matrix(camera->beta);
	free(camera);
}
