/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:36:09 by etachott          #+#    #+#             */
/*   Updated: 2022/10/20 10:09:41 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	**make_map(int **matrix)
{
	t_map	**map;
	int	x;
	int	y;

	x = 0;
	y = 0;
	map = NULL;
	while (matrix[x])
	{
		x = 0;
		while (matrix[x][y])
		{
			y++;
		}
		x++;
	}
	return (map);
}

void	naive_draw_line(t_data img, int x0, int y0, int x1, int y1)
{
    int dx;
	int	dy;
	int	p;
 
	dx = x1 - x0;
	dy = y1 - y0;
	p = 2 * dy - dx;
	while (x0 < x1)
	{
		if (p >= 0)
		{
			put_pixel(&img, x0, y0, 0x00ffffff);
			y0++;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			put_pixel(&img, x0, y0, 0x00ffffff);
			p = p + 2 * dy;
		}
		x0++;
	}
}
