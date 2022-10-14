/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 20:25:05 by coder             #+#    #+#             */
/*   Updated: 2022/09/08 15:40:42 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l_dst;
	size_t	l_src;

	i = 0;
	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	if (dstsize < l_dst)
		return (l_src + dstsize);
	while (*(src + i) && i + 1 < (dstsize - l_dst))
	{
		*(dst + l_dst + i) = *(src + i);
		i++;
	}
	*(dst + l_dst + i) = '\0';
	return (l_dst + l_src);
}
