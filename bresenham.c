/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:36:05 by etachott          #+#    #+#             */
/*   Updated: 2022/10/27 14:52:52 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_data img, t_map_values start, t_map_values end)
{
	t_map_values	value;
	int				dx;
	int				dy;
	int				D;

	dx = end.x - start.x;
	dy = end.y - start.y;
	D = ((2 * dy) - dx);
	value.x = start.x;
	value.y = start.y;
	value.z = 0;
	while (value.x <= end.x)
	{
		put_pixel(&img, value.x, value.y, 0x00FFFFFF);
		if (D > 0)
		{
			value.y++;
			D = D - (2 * dx);
		}
		D = D + (2 * dy);
		value.x++;
	}
}

void	draw_line2(t_data img, t_map_values start, t_map_values end)
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	error;

	dx = abs(end.x - start.x);
	sx = start.x < end.x ? 1 : -1;
	dy = -abs(end.y - start.y);
	sy = start.y < end.y ? 1 : -1;
	error = dx + dy;
	while (1)
	{
		put_pixel(&img, start.x, start.y, 0x0000FFFF);
		if (start.x == end.x && start.y == end.y)
			break ;
		if ((2 * error) >= dy)
		{
			if (start.x == end.x)
				break ;
			error += dy;
			start.x += sx;
		}
		if ((2 * error) <= dx)
		{
			if (start.y == end.y)
				break ;
			error += dx;
			start.y += sy;
	 	}
	}
}	
