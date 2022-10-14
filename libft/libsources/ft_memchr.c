/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 00:22:39 by coder             #+#    #+#             */
/*   Updated: 2022/08/30 00:56:01 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int			i;
	unsigned int			cont;
	const unsigned	char	(*p);

	i = 0;
	cont = 0;
	p = (const void *)s;
	c = (unsigned char) c;
	while (i < n)
	{
		if (p[i] == c)
		{
			cont += 1;
			break ;
		}
		else
			i++;
	}
	if (cont)
		return ((void *)s + i);
	else
		return (NULL);
}
