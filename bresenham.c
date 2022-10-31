/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:36:05 by etachott          #+#    #+#             */
/*   Updated: 2022/10/31 16:08:57 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_side(int start, int end)
{
	if (start < end)
		return (1);
	else
		return (-1);
}

static void	increment_values(int *error, int *delta, int *s, int *start)
{
	*error += *delta;
	*start += *s;
}

static void	set_values(t_line_values *delta, t_line_values *s,
		t_map_values *start, t_map_values *end)
{
	delta->x = abs(end->x - start->x);
	delta->y = -abs(end->y - start->y);
	s->x = check_side(start->x, end->x);
	s->y = check_side(start->y, end->y);
}

void	draw_line2(t_data *img, t_map_values start, t_map_values end)
{
	t_line_values	delta;
	t_line_values	s;
	int				error;

	set_values(&delta, &s, &start, &end);
	error = delta.x + delta.y;
	while (1)
	{
		put_pixel(img, start.x, start.y, 0x0000FFFF);
		if (start.x == end.x && start.y == end.y)
			break ;
		if ((2 * error) >= delta.y)
		{
			if (start.x == end.x)
				break ;
			increment_values(&error, &delta.y, &s.x, &start.x);
		}
		if ((2 * error) <= delta.x)
		{
			if (start.y == end.y)
				break ;
			increment_values(&error, &delta.x, &s.y, &start.y);
		}
	}
}
