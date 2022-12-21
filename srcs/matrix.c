/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:23:45 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/18 10:24:37 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Frees a 3x3 matrix.
*/
void	cleanup_matrix(float **matrix)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

/*
	Allocates memory for a 3x3 matrix of floats.
*/
float	**init_matrix(void)
{
	float	**m;
	int		i;

	m = ft_calloc(3, sizeof(*m));
	if (!m)
		return (0);
	i = 0;
	while (i < 3)
	{
		m[i] = malloc(3 * sizeof(float));
		if (!m[i])
		{
			cleanup_matrix(m);
			return (0);
		}
		i++;
	}
	return (m);
}

/*
	Multiplies a matrix and a vector3.
	The result is a vector3.
*/
t_vector3	mult(float **matrix, t_vector3 a)
{
	t_vector3	res;

	res.x = matrix[0][0] * a.x + matrix[0][1] * a.y + matrix[0][2] * a.z;
	res.y = matrix[1][0] * a.x + matrix[1][1] * a.y + matrix[1][2] * a.z;
	res.z = matrix[2][0] * a.x + matrix[2][1] * a.y + matrix[2][2] * a.z;
	return (res);
}
