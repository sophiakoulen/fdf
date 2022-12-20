/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:39:21 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/20 16:40:03 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	compute_alpha_matrix(float alpha, float **m)
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = cos(alpha);
	m[1][2] = sin(alpha);
	m[2][0] = 0;
	m[2][1] = -sin(alpha);
	m[2][2] = cos(alpha);
}

void	compute_beta_matrix(float beta, float **m)
{
	m[0][0] = cos(beta);
	m[0][1] = 0;
	m[0][2] = -sin(beta);
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[2][0] = sin(beta);
	m[2][1] = 0;
	m[2][2] = cos(beta);
}
