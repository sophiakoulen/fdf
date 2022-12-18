/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:20:47 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/18 13:26:30 by skoulen          ###   ########.fr       */
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

void	cleanup_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
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

int	get_height(int fd)
{
	int	i;

	i = 0;
	while (get_next_line(fd))
		i++;
	return (i);
}

int	get_width(int fd)
{
	char	*line;
	char	**tab;
	int		i;

	line = get_next_line(fd);
	if (!line)
		return (0);
	tab = ft_split(line, ' ');
	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	cleanup_strs(tab);
	while (get_next_line(fd))
		;
	return (i);
}

int	**parse_map(char *filename, int *rows, int *cols)
{
	int		**map;
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		return (0);
	}
	*rows = get_height(fd);
	*cols = get_width(fd);
	map = ft_calloc(*rows, sizeof(*map));
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			map[i] = get_ints(line);
			if (!map[i])
			{
				cleanup_map(map);
				return (0);
			}
		}
		if (!line)
			break ;
		i++;
	}
	return (map);
}