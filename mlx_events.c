/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:53:52 by edu               #+#    #+#             */
/*   Updated: 2022/11/04 21:26:20 by edu              ###   ########.fr       */
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
