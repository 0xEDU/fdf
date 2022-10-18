/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:35:02 by etachott          #+#    #+#             */
/*   Updated: 2022/10/18 17:22:12 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/ft_printf.h"
# include "libft/includes/libput.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mlx_vars {
	void	*mlx;
	void	*window;
}			t_mlx_vars;

typedef struct s_coordinates {
	int		x;
	int		y;
	int		z;
}				t_coordinates;

typedef struct s_map {
	int		width;
	int		height;
	int		**matrix;
}				t_map;

size_t	ft_count_lines(char *file);
void	paint_image(t_data img, int w_length, int w_height);
void	put_pixel(t_data *data, int x, int y, int color);
void	put_square(t_data img, t_coordinates coord, int square_size, int color);
void	put_triangle(t_data img);

// Temporary functions (COPILOT)

void	print_matrix(int **matrix);
#endif
