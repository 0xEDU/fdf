/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:12:03 by edu               #+#    #+#             */
/*   Updated: 2022/10/18 18:50:33 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_count_lines(char *file)
{
	size_t	i;
	char	*line;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
	}
	close(fd);
	free(line);
	return (i);
}

int	*ft_mtoia(char **matrix, size_t lines)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * lines);
	if (!array)
		return (NULL);
	while (matrix[i])
	{
		array[i] = ft_atoi(matrix[i]);
		i++;
	}
	return (array);
}
