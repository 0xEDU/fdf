/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:59:45 by etachott          #+#    #+#             */
/*   Updated: 2022/11/03 15:12:15 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	map_count_cols(t_map_values **map)
{
	t_map_values	*row;
	int				i;

	i = 0;
	row = *map;
	while (!row[i].eol)
		i++;
	return (i);
}

int	map_count_rows(t_map_values **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	meta_data(t_map_values **map)
{
	map[0][0].meta.rows = map_count_rows(map);
	map[0][0].meta.cols = map_count_cols(map);
}
