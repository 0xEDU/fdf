/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:12:50 by etachott          #+#    #+#             */
/*   Updated: 2022/10/31 11:54:46 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	paint_image(t_data img, int w_length, int w_height)
{
	t_map_values	map_values;

	map_values.x = 0;
	map_values.y = 0;
	while (map_values.x <= w_length)
	{
		put_pixel(&img, map_values.x, map_values.y, 0x00000000);
		map_values.y = 0;
		while (map_values.y <= w_height)
		{
			put_pixel(&img, map_values.x, map_values.y, 0x00000000);
			map_values.y++;
		}
		map_values.x++;
	}
}

void	zoom(t_map_values **map, int zoom)
{
	int		x;
	int		y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x] + y)
		{
			map[x][y].x *= zoom;
			map[x][y].y *= zoom;
			if ((map[x] + y)->eol)
				break ;
			y++;
		}
		x++;
	}
}
