/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:33:35 by etachott          #+#    #+#             */
/*   Updated: 2022/10/16 13:49:43 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	paint_window(t_mlx_vars mlx, int w_length, int w_height)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x <= w_length)
	{
		mlx_pixel_put(mlx.mlx, mlx.window, x, y, 0x00000000);
		y = 0;
		while (y <= w_height)
		{
			mlx_pixel_put(mlx.mlx, mlx.window, x, y, 0x00000000);
			y++;
		}
		x++;
	}
}

static void	put_triangle(t_mlx_vars mlx)
{
	int x;
	int y;

	x = 100;
	y = 100;
	while (y <= 500)
	{
		mlx_pixel_put(mlx.mlx, mlx.window, x, y, 0x000000FF);
		y++;
	}
}

int	main(void)
{
	t_mlx_vars	mlx;
	t_data		img;

	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, 800, 600, "Hello World!");
	img.img = mlx_new_image(mlx.mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	paint_window(mlx, 800, 600);
	put_triangle(mlx);
	//mlx_put_image_to_window(mlx.mlx, mlx.window, img.img, 0, 0);
	mlx_loop(mlx.mlx);
//	mlx_key_hook(vars.window, close_window, )
	return (0);
}
