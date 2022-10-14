/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:30:25 by coder             #+#    #+#             */
/*   Updated: 2022/09/11 14:58:59 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*h;

	i = 0;
	h = (char *) haystack;
	if (!ft_strlen(needle))
		return (h);
	if (!len)
		return (0);
	while (i + ft_strlen(needle) <= len && h[i])
	{
		if (!ft_strncmp(&h[i], needle, ft_strlen(needle)))
			return (&h[i]);
		i++;
	}
	return (0);
}
