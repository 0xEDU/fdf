	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:33:35 by etachott          #+#    #+#             */
/*   Updated: 2022/10/18 18:50:18 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_no_event(void)
{
	return (0);
}

int	key_press_events(int keycode, t_mlx_vars *mlx)
{
	if (keycode == 65307)
		mlx_destroy_window(mlx->mlx, mlx->window);
	ft_printf("KEYCODE = %d\n", keycode);
	return (0);
}

int	**create_matrix_from_file(char *file, size_t lines)
{
	char	*line;
	char	**tmp_matrix;
	int		**final_matrix;
	int		fd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	final_matrix = (int **)malloc(sizeof(int *) * lines + 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp_matrix = ft_split(line, ' ');
		while (1)
		{
			ft_printf("oi\n");
			final_matrix[i] = ft_mtoia(tmp_matrix);
			if (!final_matrix[i])
				break ;
		}
		i++;
	}
	close(fd);
	free(line);
	return (final_matrix);
}

int	main(int argc, char *argv[])
{
	t_mlx_vars	mlx;
	t_data		img;
	t_map		map;
	size_t		lines;

	if (argc != 2)
		return (ft_printf("Usage: ./fdf [FILE]\n"));
	ft_printf("FILE = %s\n", argv[1]);
	lines = ft_count_lines(argv[1]);
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, 800, 600, "FdF");
	img.img = mlx_new_image(mlx.mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	paint_image(img, 800, 600);
	put_triangle(img);
	map.matrix = create_matrix_from_file(argv[1], lines);
	print_matrix(map.matrix);
	mlx_put_image_to_window(mlx.mlx, mlx.window, img.img, 0, 0);
	mlx_loop_hook(mlx.mlx, &handle_no_event, (void *) &mlx);
	mlx_hook(mlx.window, 2, 1L << 0, key_press_events, &mlx);
	mlx_loop(mlx.mlx);
	mlx_destroy_image(mlx.mlx, img.img);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
	return (0);
}
