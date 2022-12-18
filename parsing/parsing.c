/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:20:47 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/18 17:27:48 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	*get_ints(char *line, int n)
{
	char	**tab;
	int		*res;
	int		i;

	tab = ft_split(line, ' ');
	if (!tab)
		return (0);
	res = malloc(n * sizeof(*res));
	if (!res)
	{
		cleanup_strs(tab);
		return (0);
	}
	i = 0;
	while (i < n)
	{
		res[i] = ft_atoi(tab[i]);
		i++;
	}
	cleanup_strs(tab);
	return (res);
}

/*
	Returns -1 in case of error (file can't open)
*/
static int	get_rows(char *filename)
{
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	i = get_line_count(fd);
	close(fd);
	return (i);
}

/*
	Returns -1 in case of error (file can't open or
	malloc failure)
	0 if line is empty
*/
static int	get_cols(char *filename)
{
	int		fd;
	char	*line;
	char	**tab;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	if (!line)
		return (0);
	free(line);
	tab = ft_split(line, ' ');
	if (!tab)
		return (-1);
	i = 0;
	while (tab[i])
		i++;
	cleanup_strs(tab);
	get_line_count(fd);
	close(fd);
	return (i);
}

/*
	Returns 0 in case of success,
	-1 in case of failure (malloc failure)
*/
static int	fill_map(int fd, int **map, int rows, int cols)
{
	int		i;
	char	*line;

	i = 0;
	while (i < rows)
	{
		line = get_next_line(fd);
		map[i] = get_ints(line, cols);
		free(line);
		if (!map[i])
		{
			cleanup_map(map);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	**parse_map(char *filename, int *rows, int *cols)
{
	int		**map;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	*rows = get_rows(filename);
	*cols = get_cols(filename);
	map = ft_calloc(*rows, sizeof(*map));
	if (!map)
		return (0);
	fill_map(fd, map, *rows, *cols);
	close(fd);
	return (map);
}
