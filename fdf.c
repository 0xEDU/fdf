/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:33:35 by etachott          #+#    #+#             */
/*   Updated: 2022/10/17 09:39:53 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press_events(int keycode, t_mlx_vars *mlx)
{
	if (keycode == 65307)
		mlx_destroy_window(mlx->mlx, mlx->window);
	ft_printf("KEYCODE = %d\n", keycode);
	return (0);
}

int	main(void)
{
	t_mlx_vars	mlx;
	t_data		img;

	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, 800, 600, "FdF");
	img.img = mlx_new_image(mlx.mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	paint_image(img, 800, 600);
	put_triangle(img);
	mlx_put_image_to_window(mlx.mlx, mlx.window, img.img, 0, 0);
	mlx_hook(mlx.window, 2, 1L<<0, key_press_events, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
