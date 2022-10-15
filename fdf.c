/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:33:35 by etachott          #+#    #+#             */
/*   Updated: 2022/10/15 17:13:19 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void	put_square(t_data img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x <= 200 && y <= 200)
	{
		put_pixel(&img, x, y, 0x00FF0000);
		x++;
		y++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*window;
	t_data	img;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1920, 1080, "Hello World!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	put_square(img);
	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
