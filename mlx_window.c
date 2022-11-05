/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 08:55:43 by etachott          #+#    #+#             */
/*   Updated: 2022/11/05 08:55:45 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	main_loop(t_mlx_vars *mlx)
{
	mlx_expose_hook(mlx->window, redraw_map, mlx);
	mlx_key_hook(mlx->window, &key_press_events, mlx);
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