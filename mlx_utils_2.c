/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:36:09 by etachott          #+#    #+#             */
/*   Updated: 2022/10/25 18:12:02 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define THETA 1

void	print_map(t_data img, t_map_values **matrix)
{
	int		x;
	int		y;

	x = 0;
	while (matrix[x])
	{
		y = 0;
		while (matrix[x] + y)
		{
			if ((matrix[x] + y)->eol)
				break;
			matrix[x][y].x = (x * sin(THETA) - y * cos(THETA)) * 20 + 370;
			matrix[x][y].y = (x * cos(THETA) + y * sin(THETA)) * 20 + 170 - (matrix[x][y].z * 2);
			if (matrix[x][y].z > 0)
				put_pixel(&img, matrix[x][y].x, matrix[x][y].y, 0x00FF0000);
			else
				put_pixel(&img, matrix[x][y].x, matrix[x][y].y, 0x00FFFFFF);
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
				draw_line(img,
					map[line][column],
					map[line][column + 1]);
			if (map[line + 1])
				draw_line(img,
					map[line][column],
					map[line + 1][column]);
			if ((map[line] + column)->eol)
				break ;
			column++;
		}
		line++;
	}
}
