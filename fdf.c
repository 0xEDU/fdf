/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:33:35 by etachott          #+#    #+#             */
/*   Updated: 2022/10/31 12:01:57 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define WIDTH 800
#define HEIGHT 600

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
	mlx->window = mlx_new_window(mlx->mlx, 800, 600, "fdf");
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
		free_matrix((void **)mlx->map, mlx->map_size);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_mlx_vars		mlx;
	t_data			img;

	if (argc != 2)
		return (ft_printf("Usage: ./fdf [FILE]\n"));
	create_window(&mlx);
	mlx.map_size = ft_count_lines(argv[1]);
	img.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	paint_image(img, WIDTH, HEIGHT);
	put_map(&mlx, &img, argv[1]);
	main_loop(&mlx);
	return (0);
}
