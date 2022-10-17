/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:12:50 by etachott          #+#    #+#             */
/*   Updated: 2022/10/17 14:31:01 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	paint_image(t_data img, int w_length, int w_height)
{
	t_coordinates	coord;
	
	coord.x = 0;
	coord.y = 0;
	while (coord.x <= w_length)
	{
		put_pixel(&img, coord.x, coord.y, 0x00000000);
		coord.y = 0;
		while (coord.y <= w_height)
		{
			put_pixel(&img, coord.x, coord.y, 0x00000000);
			coord.y++;
		}
		coord.x++;
	}
}

void	put_square(t_data img, t_coordinates coord, int square_size, int color)
{
	int	x_original;
	int	y_original;

	x_original = coord.x;
	y_original = coord.y;
	while (coord.x <= square_size)
	{
		put_pixel(&img, coord.x, coord.y, color);
		coord.y = y_original;
		while (coord.y <= square_size)
		{
			put_pixel(&img, coord.x, coord.y, color);
			coord.y++;
		}
		coord.x++;
	}
}

void	put_triangle(t_data img)
{
	t_coordinates	coord;

	coord.x = 100;
	coord.y = 100;
	while (coord.y <= 500)
	{
		put_pixel(&img, coord.x, coord.y, 0x000000FF);
		coord.y++;
	}
	coord.y = 100;
	while (coord.x <= 500 && coord.y <= 500)
	{
		put_pixel(&img, coord.x, coord.y, 0x000000FF);
		coord.x++;
		coord.y++;
	}
	coord.x = 100;
	while (coord.x <= 500)
	{
		put_pixel(&img, coord.x, coord.y, 0x000000FF);
		coord.x++;
	}
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
