/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 01:18:56 by coder             #+#    #+#             */
/*   Updated: 2022/09/08 19:39:06 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(const char *s);

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_len(s);
	while (len)
	{
		if (s[len] == (char) c)
			return ((char *)s + len);
		else
			len--;
	}
	if (s[len] == (char) c)
		return ((char *)s + len);
	return (0);
}

static int	ft_len(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
