/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:36:05 by etachott          #+#    #+#             */
/*   Updated: 2022/10/31 11:51:15 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line2(t_data *img, t_map_values start, t_map_values end)
{
	int	delta_x;
	int	sx;
	int	delta_y;
	int	sy;
	int	error;

	delta_x = abs(end.x - start.x);
	sx = start.x < end.x ? 1 : -1;
	delta_y = -abs(end.y - start.y);
	sy = start.y < end.y ? 1 : -1;
	error = delta_x + delta_y;
	while (1)
	{
		put_pixel(img, start.x, start.y, 0x0000FFFF);
		if (start.x == end.x && start.y == end.y)
			break ;
		if ((2 * error) >= delta_y)
		{
			if (start.x == end.x)
				break ;
			error += delta_y;
			start.x += sx;
		}
		if ((2 * error) <= delta_x)
		{
			if (start.y == end.y)
				break ;
			error += delta_x;
			start.y += sy;
		}
	}
}
