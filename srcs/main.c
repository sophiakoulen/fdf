/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:41:58 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/21 14:17:43 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		write(2, "usage: ./fdf <filename>\n", 24);
		return (1);
	}
	if (parse_map(argv[1], &map) == -1)
		exit(EXIT_FAILURE);
	do_rendering(&map);
	return (0);
}
