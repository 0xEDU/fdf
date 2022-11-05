/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:33:35 by etachott          #+#    #+#             */
/*   Updated: 2022/11/04 21:35:27 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_data			img;
	t_mlx_vars		mlx;

	if (argc != 2 || !validate_file(argv[1]))
		return (ft_printf("Usage: ./fdf [VALID FILE]\n"));
	create_window(&mlx);
	mlx.map_size = ft_count_rows(argv[1]);
	img.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	set_limits(&img);
	paint_image(img, WIDTH, HEIGHT);
	put_map(&mlx, &img, argv[1]);
	main_loop(&mlx);
	return (0);
}
