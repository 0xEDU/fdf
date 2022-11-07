/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:42:05 by etachott          #+#    #+#             */
/*   Updated: 2022/11/07 17:42:07 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_no_event(void)
{
	return (0);
}

int	button_press_events(int keycode, t_mlx_vars *mlx)
{
	ft_printf("BUTTON PRESSE: %d\n MLX: %p", keycode, mlx);
	return (0);
}

int	key_press_events(int keycode, t_mlx_vars *mlx)
{
	if (keycode == 65307)
		quit(mlx);
	if (keycode == 65362)
		transform_map(mlx->map, &move_up);
	if (keycode == 65364)
		transform_map(mlx->map, &move_down);
	if (keycode == 65361)
		transform_map(mlx->map, &move_left);
	if (keycode == 65363)
		transform_map(mlx->map, &move_right);
	if (keycode == 45)
		transform_map(mlx->map, &zoom_less);
	if (keycode == 61)
		transform_map(mlx->map, &zoom_more);
	if (keycode != 65307)
		redraw_map(mlx);
	return (0);
}

int	click_press_events(t_mlx_vars *mlx)
{
	quit(mlx);
	return (0);
}
