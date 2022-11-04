/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:12:50 by etachott          #+#    #+#             */
/*   Updated: 2022/11/04 13:21:14 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		*pixel;
	int		y_map;
	int		x_map;

	if (x > data->limits.right || x < data->limits.left
		|| y < data->limits.bottom
		|| y > data->limits.top)
		return ;
	y_map = (data->limits.top - y) * data->line_length;
	x_map = (data->limits.right + x) * (data->bits_per_pixel / 8);
	dst = data->addr + y_map + x_map;
	pixel = (int *)dst;
	*pixel = color;
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
