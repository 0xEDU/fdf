/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:12:50 by etachott          #+#    #+#             */
/*   Updated: 2022/10/20 09:48:15 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	put_square(t_data img, t_map_values map_values, int square_size, int color)
{
	int	y_original;

	y_original = map_values.y;
	while (map_values.x <= square_size)
	{
		put_pixel(&img, map_values.x, map_values.y, color);
		map_values.y = y_original;
		while (map_values.y <= square_size)
		{
			put_pixel(&img, map_values.x, map_values.y, color);
			map_values.y++;
		}
		map_values.x++;
	}
}

void	put_triangle(t_data img)
{
	t_map_values	map_values;

	map_values.x = 100;
	map_values.y = 100;
	while (map_values.y <= 500)
	{
		put_pixel(&img, map_values.x, map_values.y, 0x0000ffFF);
		map_values.y++;
	}
	map_values.y = 100;
	while (map_values.x <= 500 && map_values.y <= 500)
	{
		put_pixel(&img, map_values.x, map_values.y, 0x000fffFF);
		map_values.x++;
		map_values.y++;
	}
	map_values.x = 100;
	while (map_values.x <= 500)
	{
		put_pixel(&img, map_values.x, map_values.y, 0x0000ffFF);
		map_values.x++;
	}
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
