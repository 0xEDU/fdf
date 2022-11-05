/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:13:03 by etachott          #+#    #+#             */
/*   Updated: 2022/11/04 21:34:09 by edu              ###   ########.fr       */
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
