/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:33:35 by etachott          #+#    #+#             */
/*   Updated: 2022/10/24 14:46:25 by etachott         ###   ########.fr       */
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

int	mouse_press_events(int button, int x, int y, t_mlx_vars *mlx)
{
	ft_printf("BUTTON = %d\n", button);
	ft_printf("X = %d\n", x);
	ft_printf("Y = %d\n", y);
	ft_printf("MLX = %p\n", mlx);
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
		while (j < 18)
		{
			ft_printf("%d ", matrix[i][j].z);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	main_loop(t_mlx_vars *mlx)
{
	mlx_hook(mlx->window, 2, 1L << 0, key_press_events, mlx);
	mlx_hook(mlx->window, 4, 1L << 2, mouse_press_events, mlx);
	mlx_loop_hook(mlx->mlx, handle_no_event, mlx);
	mlx_loop(mlx->mlx);
}

void	create_window(t_mlx_vars *mlx)
{
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, 800, 600, "fdf");
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
	create_window(&mlx);
	img.img = mlx_new_image(mlx.mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	paint_image(img, 800, 600);
	map = create_matrix_from_file(argv[1], rows);
	print_map(img, map);
	print_matrix(map, rows);
	mlx_put_image_to_window(mlx.mlx, mlx.window, img.img, 0, 0);
	main_loop(&mlx);
	mlx_destroy_image(mlx.mlx, img.img);
	mlx_destroy_display(mlx.mlx);
	free_matrix((void **)map, ft_count_lines(argv[1])); //Free a matrix
	free(mlx.mlx);
	return (0);
}
