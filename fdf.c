/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:33:35 by etachott          #+#    #+#             */
/*   Updated: 2022/10/20 20:23:11 by etachott         ###   ########.fr       */
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

t_map_values	**create_matrix_from_file(char *file, size_t rows)
{
	t_map_values		**final_matrix;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	final_matrix = (t_map_values **)malloc(sizeof(t_map_values *) * rows);
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

// Print a t_map_values matrix
void	print_matrix(t_map_values **matrix, size_t rows)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < 17)
		{
			ft_printf("%d ", matrix[i][j].z);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}


int	main(int argc, char *argv[])
{
	t_map_values	**map;
	t_mlx_vars	mlx;
	t_data		img;
	size_t		rows;

	if (argc != 2)
		return (ft_printf("Usage: ./fdf [FILE]\n"));
	rows = ft_count_lines(argv[1]);
	ft_printf("\e[1;42mLINES = %d\e[0m\n", rows);
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, 800, 600, "FdF");
	img.img = mlx_new_image(mlx.mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	paint_image(img, 800, 600);
	map = create_matrix_from_file(argv[1], rows);
	print_map(img, map, rows);
//	print_matrix(map, rows);
	mlx_put_image_to_window(mlx.mlx, mlx.window, img.img, 0, 0);
	ft_printf("IMAGE PUT TO WINDOW\n");
	mlx_loop_hook(mlx.mlx, &handle_no_event, (void *) &mlx);
	mlx_hook(mlx.window, 2, 1L << 0, key_press_events, &mlx);
	mlx_loop(mlx.mlx);
	mlx_destroy_image(mlx.mlx, img.img);
	mlx_destroy_display(mlx.mlx);
	free_matrix((void **)map, ft_count_lines(argv[1])); //Free a matrix
	free(mlx.mlx);
	return (0);
}
