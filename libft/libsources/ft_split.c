/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:38:43 by coder             #+#    #+#             */
/*   Updated: 2022/10/14 15:10:48 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_words(char const *s, char c);
static size_t	special_strlen(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	k;
	char	**mrx;

	k = 0;
	i = get_words(s, c);
	mrx = (char **) ft_calloc(i + 1, sizeof(char *));
	while (*s)
	{
		if (*s != c)
		{
			mrx[k] = ft_substr(s, 0, special_strlen(s, c));
			s++;
			k++;
		}
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (mrx);
}

static size_t	get_words(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(s + j))
	{
		if (*(s + j) != c)
			i++;
		while (*(s + j) != c && *(s + j))
			j++;
		while (*(s + j) == c && *(s + j))
			j++;
	}
	return (i);
}

static size_t	special_strlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}
