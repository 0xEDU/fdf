/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:35:02 by etachott          #+#    #+#             */
/*   Updated: 2022/10/31 15:57:59 by edu              ###   ########.fr       */
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
# include <math.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_line_values {
	int	x;
	int	y;
}				t_line_values;

typedef struct s_map_values {
	int			x;
	int			y;
	int			z;
	short int	eol;
}				t_map_values;

typedef struct s_mlx_vars {
	t_map_values	**map;
	int				map_size;
	void			*mlx;
	void			*window;
}			t_mlx_vars;

typedef struct s_bsh {
	int		x0;
	int		y0;
	int		x1;
	int		y1;
}				t_bsh;

int				click_press_events(t_mlx_vars *mlx);
void			connect_dots(t_data *img, t_map_values **map);
t_map_values	**create_matrix_from_file(char *file, size_t rows);
void			draw_line2(t_data *img, t_map_values start, t_map_values end);
void			free_matrix(void **matrix, int elements);
size_t			ft_count_lines(char *file);
size_t			ft_count_words(const char **matrix);
t_map_values	*ft_stoia(char *str, int iteration);
int				handle_no_event(void);
int				key_press_events(int keycode, t_mlx_vars *mlx);
int				mouse_press_events(int button, int x, int y, t_mlx_vars *mlx);
void			paint_image(t_data img, int w_length, int w_height);
void			put_map(t_mlx_vars *mlx, t_data *img, char *map_file);
void			put_pixel(t_data *data, int x, int y, int color);
void			put_square(t_data img, t_map_values map_values,
					int square_size, int color);
void			put_triangle(t_data img);
int				quit(t_mlx_vars *mlx);
void			transform_to_isometric(t_map_values **matrix);

// Temporary functions (COPILOT)

#endif
