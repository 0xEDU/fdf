/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:39:59 by etachott          #+#    #+#             */
/*   Updated: 2022/11/07 17:40:05 by etachott         ###   ########.fr       */
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
# include <math.h>
# define WIDTH 1280
# define HEIGHT 800

typedef struct s_limits {
	int	top;
	int	bottom;
	int	left;
	int	right;
}				t_limits;

typedef struct s_data {
	t_limits	limits;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_line_values {
	int	x;
	int	y;
}				t_line_values;

typedef struct s_meta_map {
	int	rows;
	int	cols;
	int	scale_x;
	int	scale_y;
}				t_meta_map;

typedef struct s_map_values {
	t_meta_map	meta;
	int			x;
	int			y;
	int			z;
	int			color;
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
void			create_window(t_mlx_vars *mlx);
void			draw_line2(t_data *img, t_map_values start, t_map_values end);
void			free_map(void **map, int elements);
size_t			ft_count_rows(char *file);
size_t			ft_count_cols(const char **map);
t_map_values	*ft_stoia(char *str, int iteration);
int				handle_no_event(void);
void			isometric_render(t_map_values **map);
int				key_press_events(int keycode, t_mlx_vars *mlx);
int				key_release_events(int keycode, t_mlx_vars *mlx);
void			main_loop(t_mlx_vars *mlx);
void			meta_data(t_map_values **map);
int				mouse_press_events(int button, int x, int y, t_mlx_vars *mlx);
void			paint_image(t_data img, int w_length, int w_height);
void			put_map(t_mlx_vars *mlx, t_data *img, char *map_file);
void			put_pixel(t_data *data, int x, int y, int color);
void			put_square(t_data img, t_map_values map_values,
					int square_size, int color);
void			put_triangle(t_data img);
int				quit(t_mlx_vars *mlx);
int				redraw_map(t_mlx_vars *mlx);
void			set_limits(t_data *img);
void			transform_map(t_map_values **map, void (*transform)(t_map_values
						*map_values));
int				validate_file(char *file);
void			extrude(t_map_values *pos);
void			rotate(t_map_values *pos);
void			down(t_map_values *pos);
void			scale(t_map_values **map, int *scale_val);
void			move_up(t_map_values *pos);
void			move_down(t_map_values *pos);
void			move_left(t_map_values *pos);
void			move_right(t_map_values *pos);
void			zoom_more(t_map_values *pos);
void			zoom_less(t_map_values *pos);
#endif
