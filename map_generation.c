/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:36:09 by etachott          #+#    #+#             */
/*   Updated: 2022/11/05 10:02:45 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	validate_file(char *file)
{
	char	tmp[1];
	int		fd;
	int		read_return;

	fd = open(file, O_RDONLY);
	read_return = read(fd, tmp, 1);
	if (fd < 0 || read_return < 0 || !ft_strnstr(file, ".fdf", ft_strlen(file)))
		return (0);
	else
	{
		close(fd);
		return (1);
	}
}

t_map_values	**create_matrix_from_file(char *file, size_t rows)
{
	t_map_values		**final_matrix;
	char				*line;
	int					fd;
	int					i;

	i = 0;
	fd = open(file, O_RDONLY);
	final_matrix = ft_calloc(sizeof(t_map_values *), rows + 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		final_matrix[i] = ft_stoia(line, i);
		i++;
		free(line);
	}
	close(fd);
	return (final_matrix);
}

void	transform_map(t_map_values **map, void (*transform)(t_map_values *))
{
	int		x;
	int		y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x] + y)
		{
			transform(&map[x][y]);
			if (map[x][y].eol)
				break ;
			y++;
		}
		x++;
	}
}
