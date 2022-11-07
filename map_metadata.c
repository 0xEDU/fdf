/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_metadata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:41:10 by etachott          #+#    #+#             */
/*   Updated: 2022/11/07 17:41:15 by etachott         ###   ########.fr       */
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
