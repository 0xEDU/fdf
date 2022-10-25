/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:36:05 by etachott          #+#    #+#             */
/*   Updated: 2022/10/25 17:58:52 by etachott         ###   ########.fr       */
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
