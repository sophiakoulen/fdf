/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:41:58 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/19 13:40:34 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	t_map	map;

	(void)argc;
	map.map = parse_map(argv[1], &map.rows, &map.cols);
	if (!map.map)
	{
		return (0);
	}
	printf("rows: %d\n cols: %d\n", map.rows, map.cols);
	do_rendering(&map);
	return (0);
}