/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:53:52 by edu               #+#    #+#             */
/*   Updated: 2022/10/31 11:15:14 by edu              ###   ########.fr       */
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
		quit(mlx);
	ft_printf("KEYCODE = %d\n", keycode);
	return (0);
}

int	mouse_press_events(int button, int x, int y, t_mlx_vars *mlx)
{
	ft_printf("BUTTON = %d\nX = %d\nY = %d\nMLX = %p\n", button, x, y, mlx);
	return (0);
}

int	click_press_events(t_mlx_vars *mlx)
{
	quit(mlx);
	return (0);
}
