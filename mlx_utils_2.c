/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:36:09 by etachott          #+#    #+#             */
/*   Updated: 2022/10/27 18:50:55 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define THETA 0.7853982

void	print_map(t_map_values **matrix)
{
	int		x;
	int		y;

	x = 0;
	while (matrix[x])
	{
		y = 0;
		while (matrix[x] + y)
		{
			matrix[x][y].x = (cos(THETA) * y - sin(THETA) * x) * 20 + 380;
			matrix[x][y].y = (sin(THETA) * y + cos(THETA) * x) * 17 + 150 - (matrix[x][y].z * 8);
			if (matrix[x][y].y < 0)
				matrix[x][y].y *= -1;
			if ((matrix[x] + y)->eol)
				break;
			y++;
		}
		x++;
	}
}

void	connect_dots(t_data img, t_map_values **map) 
{	
	int	line;
	int	column;

	line = 0;
	while (map[line])
	{
		column = 0;
		while (map[line] + column)
		{
			if (!map[line][column].eol)
			{
				draw_line2(img,
					map[line][column],
					map[line][column + 1]);
			}
			if (map[line + 1])
			{
				draw_line2(img,
					map[line][column],
					map[line + 1][column]);
			}
			if ((map[line] + column)->eol)
				break ;
			column++;
		}
		line++;
	}
}
