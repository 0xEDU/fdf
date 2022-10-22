/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:36:09 by etachott          #+#    #+#             */
/*   Updated: 2022/10/21 17:04:26 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define TEST1 0

void	print_map(t_data img, t_map_values **matrix, int cols)
{
	int	x;
	int	y;
	int	rows;

	x = 0;
	y = 0;
	rows = 0;
	ft_printf("%d\n", rows);
	while (x < 11)
	{
		y = 0;
		while (y < cols)
		{
			put_pixel(&img, (matrix[x][y].x * 2 + 300), matrix[x][y].y * 2 + 200 + matrix[x][y].z, 0x00FFFFFF);
			y++;
		}
		x++;
	}
}
