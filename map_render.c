/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:42:00 by edu               #+#    #+#             */
/*   Updated: 2022/11/04 18:54:26 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_render(t_map_values **map)
{
	int		scale_val;

	scale_val = HEIGHT / sqrt(pow(map[0][0].meta.rows, 2)
			+ pow(map[0][0].meta.cols, 2));
	scale(map, &scale_val);
	transform_map(map, &rotate);
	transform_map(map, &down);
	transform_map(map, &extrude);
}

void	put_map(t_mlx_vars *mlx, t_data *img, char *map_file)
{
	mlx->map = create_matrix_from_file(map_file, mlx->map_size);
	meta_data(mlx->map);
	isometric_render(mlx->map);
	connect_dots(img, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->window, img->img, 0, 0);
	mlx_destroy_image(mlx->mlx, img->img);
}
