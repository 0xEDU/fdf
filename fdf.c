/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:33:35 by etachott          #+#    #+#             */
/*   Updated: 2022/10/16 00:26:50 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	paint_window(t_data img, int w_length, int w_height)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x <= w_length)
	{
		put_pixel(&img, x, y, 0x00000000);
		y = 0;
		while (y <= w_height)
		{
			mlx_pixel_put(&img, x, y, 0x00000000);
			y++;
		}
		x++;
	}
}

static void	put_triangle(t_data img)
{
	int x;
	int y;

	x = 100;
	y = 100;
	while (y <= 500)
	{
		mlx_pixel_put(&img, x, y, 0x000000FF);
		y++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*window;
	t_data	img;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 800, 600, "Hello World!");
	img.img = mlx_new_image(mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	paint_window(img, 800, 600);
	put_triangle(img);
	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	mlx_loop(mlx);
//	mlx_key_hook(window, close_window, )
	return (0);
}
