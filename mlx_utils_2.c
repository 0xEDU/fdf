/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:36:09 by etachott          #+#    #+#             */
/*   Updated: 2022/10/20 13:51:45 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_data img, t_map_values **matrix, int rows, int columns)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < columns)
	{
		y = 0;
		while (y < rows)
		{
			put_pixel(&img, matrix[x][y].x * 25, matrix[x][y].y * 25, 0x00FFFFFF);
			y++;
		}
		x++;
	}
}
