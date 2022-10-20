/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:36:09 by etachott          #+#    #+#             */
/*   Updated: 2022/10/20 20:47:10 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_data img, t_map_values **matrix, int cols)
{
	int	x;
	int	y;
	int	rows;

	x = 0;
	y = 0;
	rows = 0;
	ft_printf("%d\n", rows);
	while (x < rows)
	{
		y = 0;
		while (y < cols)
		{
			put_pixel(&img, matrix[x][y].x * 25, matrix[x][y].y * 25, 0x00FFFFFF);
			y++;
		}
		x++;
	}
}
