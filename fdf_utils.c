/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:12:03 by edu               #+#    #+#             */
/*   Updated: 2022/10/25 17:40:24 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(void **matrix, int elements)
{
	int	i;

	i = 0;
	while (i < elements)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

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
		free(line);
	}
	close(fd);
	return (i);
}

size_t	ft_count_words(const char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

t_map_values	*ft_stoia(char *str, int iteration)
{
	t_map_values		*final_array;
	char				**word_matrix;
	int					index;
	int					elements;

	index = 0;
	word_matrix = ft_split(str, ' ');
	if (!word_matrix)
		return (NULL);
	elements = ft_count_words((const char **)word_matrix);
	final_array = malloc(sizeof(t_map_values) * elements);
	while (index < elements)
	{
		final_array[index].x = index;
		final_array[index].y = iteration;
		final_array[index].z = ft_atoi(word_matrix[index]);
		final_array[index].eol = 0;
		index++;
	}
	final_array[index - 1].eol = 1;
	free_matrix((void **)word_matrix, elements);
	return (final_array);
}
