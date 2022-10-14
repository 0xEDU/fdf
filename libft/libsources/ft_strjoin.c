/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:43:14 by etachott          #+#    #+#             */
/*   Updated: 2022/09/10 13:55:41 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	l1;
	size_t	l2;
	size_t	i;
	size_t	j;

	i = 0;
	j = i;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	new = malloc(((l1 + l2) * sizeof(char)) + 1);
	while (l1--)
	{
		*(new + i) = *(s1 + i);
		i++;
	}
	while (l2--)
	{
		*(new + i) = *(s2 + j++);
		i++;
	}
	*(new + i) = '\0';
	return (new);
}
