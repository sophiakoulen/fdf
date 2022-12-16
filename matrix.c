#include "fdf.h"

float	**init_matrix()
{
	float	**m;
	int		i;
	int		j;

	m = malloc(3 * sizeof(*m));
	if (!m)
		return (0);
	i = 0;
	while (i < 3)
	{
		m[i] = malloc(3 * sizeof(float));
		if (!m[i])
		{
			j = 0;
			while (j < i)
			{
				free(m[j]);
				j++;
			}
			free(m);
			return (0);
		}
		i++;
	}
	return (m);
}

t_vector3	do_mult(float **matrix, t_vector3 a)
{
	t_vector3	res;

	res.x = matrix[0][0] * a.x + matrix[0][1] * a.y + matrix[0][2] * a.z;
	res.y = matrix[1][0] * a.x + matrix[1][1] * a.y + matrix[1][2] * a.z;
	res.z = matrix[2][0] * a.x + matrix[2][1] * a.y + matrix[2][2] * a.z;
	return (res);
}
