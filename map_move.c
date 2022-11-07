/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:46:57 by etachott          #+#    #+#             */
/*   Updated: 2022/11/07 17:26:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_up(t_map_values *pos)
{
	pos->y -= 10;
}

void	move_down(t_map_values *pos)
{
	pos->y += 10;
}

void	move_left(t_map_values *pos)
{
	pos->x += 10;
}

void	move_right(t_map_values *pos)
{
	pos->x -= 10;
}

int	redraw_map(t_mlx_vars *mlx)
{
	t_data	img;

	img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	set_limits(&img);
	paint_image(img, WIDTH, HEIGHT);
	connect_dots(&img, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->window, img.img, 0, 0);
	mlx_destroy_image(mlx->mlx, img.img);
	return (0);
}
