/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:33:35 by etachott          #+#    #+#             */
/*   Updated: 2022/11/03 12:39:20 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	main_loop(t_mlx_vars *mlx)
{
	mlx_key_hook(mlx->window, &key_press_events, mlx);
	mlx_hook(mlx->window, 4, 1L << 2, mouse_press_events, mlx);
	mlx_hook(mlx->window, 17, 0, click_press_events, mlx);
	mlx_loop(mlx->mlx);
}

void	create_window(t_mlx_vars *mlx)
{
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "fdf");
	if (!mlx->window)
		free(mlx->window);
}

int	quit(t_mlx_vars *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_display(mlx->mlx);
	if (mlx->mlx)
		free(mlx->mlx);
	if (mlx->map)
		free_map((void **)mlx->map, mlx->map_size);
	exit(0);
}

void	set_limits(t_data *img)
{
	img->limits.top = HEIGHT / 2;
	img->limits.bottom = -(HEIGHT / 2);
	img->limits.left = -(WIDTH / 2);
	img->limits.right = WIDTH / 2;
}

int	main(int argc, char *argv[])
{
	t_data			img;
	t_mlx_vars		mlx;

	if (argc != 2)
		return (ft_printf("Usage: ./fdf [FILE]\n"));
	create_window(&mlx);
	mlx.map_size = ft_count_rows(argv[1]);
	img.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	set_limits(&img);
	paint_image(img, WIDTH, HEIGHT);
	put_map(&mlx, &img, argv[1]);
	main_loop(&mlx);
	return (0);
}
