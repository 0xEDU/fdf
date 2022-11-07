/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:41:45 by etachott          #+#    #+#             */
/*   Updated: 2022/11/07 17:41:47 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_more(t_map_values *pos)
{
	pos->x *= 2;
	pos->y *= 2;
}

void	zoom_less(t_map_values *pos)
{
	pos->x /= 2;
	pos->y /= 2;
}
