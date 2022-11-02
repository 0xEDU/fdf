/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:42:00 by edu               #+#    #+#             */
/*   Updated: 2022/11/02 17:25:12 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_values	**create_matrix_from_file(char *file, size_t rows)
{
	t_map_values		**final_matrix;
	char				*line;
	int					fd;
	int					i;

	i = 0;
	fd = open(file, O_RDONLY);
	final_matrix = ft_calloc(sizeof(t_map_values *), rows + 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		final_matrix[i] = ft_stoia(line, i);
		i++;
		free(line);
	}
	close(fd);
	return (final_matrix);
}

void	put_map(t_mlx_vars *mlx, t_data *img, char *map_file)
{
	mlx->map = create_matrix_from_file(map_file, mlx->map_size);
	transform_to_isometric(mlx->map);
	connect_dots(img, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->window, img->img, 0, 0);
	mlx_destroy_image(mlx->mlx, img->img);
}
