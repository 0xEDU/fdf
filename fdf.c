/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:33:35 by etachott          #+#    #+#             */
/*   Updated: 2022/10/17 18:28:10 by etachott         ###   ########.fr       */
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

int	*ltoi(char *str)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * ft_strlen(str));
	while (str[i])
	{
		if (0 <= str[i + 1] && str[i + 1] <= 9)
			tab[i] = str[i] - '0';
			i++;
		else
			i++;
	}
	return (tab);
}

void	create_matrix_from_file(char *file)
{
	t_map	map;
	char	*line;
	int		fd;
	int		row;
	int		columns;

	row = 0;
	columns = 0;
	fd = open(file, O_RDONLY);
	map.width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_printf("%s", line);
	}
	close(fd);
	free(line);
}

int	main(int argc, char *argv[])
{
	t_mlx_vars	mlx;
	t_data		img;

	if (argc != 2)
		return (ft_printf("Usage: ./fdf [FILE]\n"));
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, 800, 600, "FdF");
	img.img = mlx_new_image(mlx.mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	create_matrix_from_file(argv[1]);
	mlx_put_image_to_window(mlx.mlx, mlx.window, img.img, 0, 0);
	mlx_loop_hook(mlx.mlx, &handle_no_event, (void *) &mlx);
	mlx_hook(mlx.window, 2, 1L << 0, key_press_events, &mlx);
	mlx_loop(mlx.mlx);
	mlx_destroy_image(mlx.mlx, img.img);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
	return (0);
}
