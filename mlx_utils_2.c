/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:36:09 by etachott          #+#    #+#             */
/*   Updated: 2022/10/23 15:00:44 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# define THETA 0.523599

t_map_values	**transform_matrix(t_map_values **map, int cols)
{
	int	x;
	int	y;
	int	teta;
	int	omega;

	x = 0;
	y = 0;
	teta = 5;
	omega = 5;
	while (x < 11)
	{
		y = 0;
		while (y < cols)
		{
			map[x][y].x = teta + map[x][y].x * 10 + 300;
			if (map[x][y].z != 0)
				map[x][y].y = omega + map[x][y].y * 10 + 200 - map[x][y].z * 10;
			else
				map[x][y].y = omega + map[x][y].y * 10 + 200;
			y++;
		}
		//i = i + 2;
		teta = teta - 10;
		omega = omega + 10;
		x++;
	}
	return (map);
}

void	print_map(t_data img, t_map_values **matrix, int cols)
{
	int	x;
	int	y;
	int	rows;

	x = 0;
	y = 0;
	rows = 0;
	ft_printf("rows = %d\n", rows);
	matrix = transform_matrix(matrix, cols);
	while (x < 11)
	{
		y = 0;
		while (y < cols)
		{
			put_pixel(&img, matrix[x][y].x, matrix[x][y].y, 0x00FFFFFF);
			y++;
		}
		x++;
	}
}
