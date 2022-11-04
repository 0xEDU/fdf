/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:36:09 by etachott          #+#    #+#             */
/*   Updated: 2022/11/04 17:07:06 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define THETA 0.7853982

void	transform_map(t_map_values **map, void (*transform)(t_map_values *))
{
	int		x;
	int		y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x] + y)
		{
			transform(&map[x][y]);
			if (map[x][y].eol)
				break ;
			y++;
		}
		x++;
	}
}

void	connect_dots(t_data *img, t_map_values **map)
{	
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x] + y)
		{
			if (!map[x][y].eol)
				draw_line2(img,
					map[x][y],
					map[x][y + 1]);
			if (map[x + 1])
				draw_line2(img,
					map[x][y],
					map[x + 1][y]);
			if ((map[x] + y)->eol)
				break ;
			y++;
		}
		x++;
	}
}
