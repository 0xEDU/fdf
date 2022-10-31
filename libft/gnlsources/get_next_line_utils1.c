/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:45:27 by coder             #+#    #+#             */
/*   Updated: 2022/10/31 10:05:11 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	nonull;
	size_t	ret;

	nonull = size - 1;
	ret = ft_strlen(src);
	if (size)
	{
		while (nonull-- && *src)
		{
			*dst = (char) *src;
			dst++;
			src++;
		}
		*dst = '\0';
	}
	return (ret);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	size;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = malloc(size * sizeof(char));
	if (new == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(new, s1, ft_strlen(s1) + 1);
	ft_strlcat(new, s2, size);
	free(s1);
	return (new);
}
