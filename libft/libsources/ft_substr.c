/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:22:03 by coder             #+#    #+#             */
/*   Updated: 2022/09/12 20:17:50 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	k = start;
	while (len && s[k++])
	{
		i++;
		len--;
	}
	sub = malloc(sizeof(char) * i + 1);
	while (j < i)
		*(sub + j++) = *(s + start++);
	*(sub + i) = '\0';
	return (sub);
}
