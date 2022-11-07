/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_transformations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:41:36 by etachott          #+#    #+#             */
/*   Updated: 2022/11/07 17:41:38 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	extrude(t_map_values *pos)
{
	pos->y = pos->y + pos->z;
}

void	rotate(t_map_values *pos)
{
	int	x;
	int	y;

	x = (pos->x * 1) + (pos->y * 1);
	y = (pos->x * 1) + (pos->y * -1);
	pos->x = x - (WIDTH * 1.4) / 4;
	pos->y = y - (HEIGHT * 1.5) / 4;
}

void	down(t_map_values *pos)
{
	pos->y /= 2;
}

void	scale(t_map_values **map, int *scale_value)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x] + y)
		{
			map[x][y].x *= *scale_value;
			map[x][y].y *= *scale_value;
			map[x][y].z *= *scale_value / 2;
			if ((map[x] + y)->eol)
				break ;
			y++;
		}
		x++;
	}
}
