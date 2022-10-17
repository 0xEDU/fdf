/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:33:35 by etachott          #+#    #+#             */
/*   Updated: 2022/10/17 14:22:59 by etachott         ###   ########.fr       */
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

void	fileio(t_data img, char *file)
{
	t_coordinates	coord;
	char			*line;
	int				index;
	int				fd;

	index = 0;
	coord.x = 200;
	coord.y = 150;
	fd = open(file, O_RDONLY);
	paint_image(img, 800, 600);
	put_square(img, coord, 400, 0x00865C0F);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		index = 0;
		while (line[index])
		{
			if (coord.x >= 800)
				coord.x = 25;
			if (line[index] == ' ')
				coord.x = coord.x + 15;
			if (line[index] == '1' && line[index + 1] == '0')
			{
				put_pixel(&img, coord.x, coord.y, 0x008eFF00);
				index++;
			}
			else
				put_pixel(&img, coord.x, coord.y, 0x000000FF);
			coord.x++;
			index++;
		}
		coord.y = coord.y + 25;
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
	fileio(img, argv[1]);
	mlx_put_image_to_window(mlx.mlx, mlx.window, img.img, 0, 0);
	mlx_loop_hook(mlx.mlx, &handle_no_event, (void *) &mlx);
	mlx_hook(mlx.window, 2, 1L << 0, key_press_events, &mlx);
	mlx_loop(mlx.mlx);
	mlx_destroy_image(mlx.mlx, img.img);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
	return (0);
}
