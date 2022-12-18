/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:20:47 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/18 11:36:07 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cleanup_map(int **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	*get_ints(char *line)
{
	char	**tab;
	int		*ints;
	int		n;
	int		i;

	tab = ft_split(line, ' ');
	if (!tab)
		return (0);
	n = 0;
	while (tab[n])
		n++;
	ints = malloc(n * sizeof(*ints));
	if (!ints)
	{
		cleanup_strs(tab);
		return (0);
	}
	i = 0;
	while (i < n)
	{
		ints[i] = ft_atoi(tab[i]);
		i++;
	}
	cleanup_strs(tab);
	return (ints);
}

int	**parse_map(char *filename)
{
	int		**map;
	int		fd;
	char	*line;
	int		i;

	fd = open(filename);
	if (fd < 0)
	{
		return (0);
	}
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		map[i] = line;
		if (line)
		{
			map[i] = get_ints(line);
			if (!map[i])
			{

			}
		}
		if (!line)
			break ;
		i++;
	}
	return (map);
}